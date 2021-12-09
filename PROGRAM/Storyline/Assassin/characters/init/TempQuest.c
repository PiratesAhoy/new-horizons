void CreateTempQuestCharacters(ref n)
{

	object chobj;
	ref ch;
	makeref(ch, chobj);

// Enrique Padilla
	ch.old.name = "Enrique";
	ch.old.lastname = "Padilla";
	ch.name = TranslateString("", "Enrique");
	ch.lastname = TranslateString("", "Padilla");
	ch.id		= "Enrique Padilla";
	ch.model	= "Offic_spa2_16";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade28");
	ch.equip.blade = "blade28";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Enrique Padilla_dialog.c";
	ch.greeting = "Gr_isla muelle soldier";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "80";
	ch.Ship.Name = "Gloriosa";
	ch.Ship.Type = "SP_Galeon50";
	ch.Ship.Stopped = true; 	
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "3";
	ch.money = "0";
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	AddGameCharacter(n, ch);
	
// Baltasar Salgada
	ch.old.name = "Baltasar";
	ch.old.lastname = "Salgada";
	ch.name = TranslateString("", "Baltasar");
	ch.lastname = TranslateString("", "Salgada");
	ch.id		= "Baltasar Salgada";
	ch.model	= "Storeman2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade13");
	ch.equip.blade = "blade13";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Baltasar Salgada_dialog.c";
	ch.greeting = "Gr_Francisco Cruz";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

//Captain Damski	
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
	ch.Dialog.Filename = "Damski_dialog.c";
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
	LAi_SetCitizenType(ch);	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.questchar = true;
	AddGameCharacter(n, ch);

//   Chico Cois
	ch.old.name = "Chico";
	ch.old.lastname = "Cois";
	ch.name = TranslateString("", "Chico");
	ch.lastname = TranslateString("", "Cois");
	ch.id		= "Chico Cois";
	ch.model	= "Buccaneer1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.nodisarm	= 1;
	GiveItem2Character(ch, "pistol8");
	ch.equip.gun = "pistol8";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Chico Cois_dialog.c";
	ch.greeting = "Gr_Txiki Pijuan";
	ch.rank 	= 6;
	ch.reputation = "None";
	TakeNItems(ch,"potion1", Rand(4)+1);
	ch.experience = CalculateExperienceFromRank(6)+ (CalculateExperienceFromRank(6)/10 + rand(6000));
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "2";
	ch.money = "0";
    ch.questchar = true;	
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.ProfessionalGunman = true;	
	ch.HPBonus = 100;
	ch.quest.officertype = OFFIC_TYPE_BOATSWAIN;
	ch.quest.officerprice = "500";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 120.0, 120.0);
	LAi_SetImmortal(ch, true);
	AddGameCharacter(n, ch);

//Dominico Cuellar	
	ch.old.name = "Dominico";
	ch.old.lastname = "Cuellar";
	ch.name = TranslateString("", "Dominico");
	ch.lastname = TranslateString("", "Cuellar");
	ch.id		= "Dominico Cuellar";
	ch.model	= "Spy1"; 
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Dominico Cuellar_dialog.c";
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
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_isla muelle Soldier";
	AddGameCharacter(n, ch);
	
// Harold Flesher
	ch.old.name = "Harold";
	ch.old.lastname = "Flesher";
	ch.name = TranslateString("", "Harold");
	ch.lastname = TranslateString("", "Flesher");
	ch.id		= "Harold Flesher";
	ch.model	= "Offic_eng_16";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade11");
	ch.equip.blade = "blade11";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.rank 	= 8;
	ch.reputation = "None";
	ch.experience = "80";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "3";
	ch.money = "100";
    ch.questchar = true;	
	LAi_SetCitizenType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	LAi_NoRebirthEnable(ch);	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 30.0, 30.0);
	AddGameCharacter(n, ch);	

//Pelagius Lizarraga	
	ch.old.name = "Pelagius";
	ch.old.lastname = "Lizarraga";
	ch.name = TranslateString("", "Pelagius");
	ch.lastname = TranslateString("", "Lizarraga");
	ch.id		= "Pelagius Lizarraga";
	ch.model	= "Spy2"; 
	ch.sound_type = "soldier";
	ch.sex = "man";
	ch.nation = SPAIN;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Pelagius Lizarraga_dialog.c";
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
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);	
	ch.greeting = "Gr_isla muelle Soldier";
	AddGameCharacter(n, ch);

//Gabriel Brugera
	ch.old.name = "Gabriel";
	ch.old.lastname = "Brugera";
	ch.name = TranslateString("", "Gabriel");
	ch.lastname = TranslateString("", "Brugera");
	ch.id		= "Gabriel Brugera";
	ch.model = "Offic_fra2_16";
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "patrol_dialog.c";
	ch.nation = FRANCE;
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
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);	
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

//Tello Basadre	
	ch.old.name = "Tello";
	ch.old.lastname = "Basadre";
	ch.name = TranslateString("", "Tello");
	ch.lastname = TranslateString("", "Basadre");
	ch.id		= "Tello Basadre";
	ch.model	= "sailor19"; 
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.nation = SPAIN;
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Tello Basadre_dialog.c";
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
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 20.0, 8.0); //works during the day
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);	
	ch.greeting = "Gr_zaid murro";
	AddGameCharacter(n, ch);

//Aurelien Bergerat
	ch.old.name = "Aurelien";
	ch.old.lastname = "Bergerat";
	ch.name = TranslateString("", "Aurelien");
	ch.lastname = TranslateString("", "Bergerat");
	ch.id		= "Aurelien Bergerat";
	ch.model = "Gener_fra_16";
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "blade25");
	ch.equip.blade = "blade25";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Aurelien Bergerat_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 18;
	ch.reputation = "None";
	ch.experience = "0";
	ch.Ship.Name = "La Fougueuse";
	ch.Ship.Type = 	"FR_SoleilRoyal";	
	ch.Ship.Stopped = true;
	ch.Flags.Personal = 5; // PB: Malta Flag
	ch.Flags.Personal.texture = 1;
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "2";
	ch.money = "10";
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 180.0, 180.0);
	LAi_NoRebirthEnable(ch);	
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);
	
			// SoldatF1
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "SoldatF1";
	ch.model = "soldier_fra2_16"; 
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.nation = FRANCE;
	ch.rank 	= 1;
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	AddGameCharacter(n, ch);
	
			// SoldatF2
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "SoldatF2";
	ch.model = "soldier_fra3_16"; 
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.nation = FRANCE;
	ch.rank 	= 1;
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	AddGameCharacter(n, ch);

	//Modified Hitman
	
				// Ambroz Bricenos
	ch.old.name = "Ambroz";
	ch.old.lastname = "Bricenos";
	ch.name = TranslateString("", "Ambroz");
	ch.lastname = TranslateString("", "Bricenos");
	ch.id		= "Ambroz Bricenos";
	ch.model = "Storeman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade25+3"); //SCM
	ch.equip.blade = "blade25+3"; //SCM
	GiveItem2Character(ch, "pistol1a+3"); //SCM
	ch.equip.gun = "pistol1a+3"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Ambroz Bricenos_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "10";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "0";
	ch.money = "100";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 50.0, 50.0);
	ch.greeting = "Gr_Ambroz Bricenos";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Mateus Santos
	ch.old.name = "Mateus";
	ch.old.lastname = "Santos";
	ch.name = TranslateString("", "Mateus");
	ch.lastname = TranslateString("", "Santos");
	ch.id		= "Mateus Santos";
	ch.model = "Assassin"; //SCM
	ch.sex = "man";
	ch.sound_type = "Mateus Santos"; //SCM
	GiveItem2Character(ch, "bladeX1"); //SCM
	ch.equip.blade = "bladeX1"; //SCM
	ch.nodisarm	= 1;				// PB: Disable disarming
	GiveItem2Character(ch, "pistol2+3"); //SCM
	ch.equip.gun = "pistol2+3"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "Hit_houseB";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Mateus Santos_dialog.c";
	ch.greeting = "Gr_Mateus Santos";
	ch.rank 	= 5;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "7";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "0";
	ch.money = "5000";
	ch.quest.meeting = "0";
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 140.0, 140.0);
	LAi_SetImmortal(ch, true);	
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 1
	ch.old.name = "Desiree'"; //SCM
	ch.old.lastname = "Muerte"; //SCM
	ch.name = TranslateString("", "Desiree'"); //SCM
	ch.lastname = TranslateString("", "Muerte"); //SCM
	ch.id		= "Desiree' Muerte"; //SCM
	ch.model = "mowngirl7"; //SCM
	ch.sex = "woman"; //SCM
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade5"); //SCM
	ch.equip.blade = "blade5"; //SCM
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "Hit_houseB";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Desiree' Muerte_dialog.c";
	ch.greeting = "Gr_Desiree' Muerte";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);	
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 2
	ch.old.name = "Thug";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Thug");
	ch.lastname = " ";
	ch.id		= "Thug2";
	ch.model = "pirat6"; //SCM
	ch.sex = "man";
	ch.sound_type = "Thug"; //SCM
	GiveItem2Character(ch, "blade36"); //SCM
	ch.equip.blade = "blade36"; //SCM
	GiveItem2Character(ch, "pistol1a"); //SCM
	ch.equip.gun = "pistol1a"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "Hit_houseB";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "Gr_Thug";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);	
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 3
	ch.old.name = "Vassal";
	ch.old.lastname = "Bethune";
	ch.name = TranslateString("", "Vassal"); //SCM
	ch.lastname = TranslateString("", "Bethune"); //SCM
	ch.id		= "Thug3";
	ch.model = "killer"; //SCM
	ch.sex = "man";
	ch.sound_type = "Vassal Bethune"; //SCM
	GiveItem2Character(ch, "bladeX1"); //SCM
	ch.equip.blade = "bladeX1"; //SCM
	ch.nodisarm	= 1;				// PB: Disable disarming
	GiveItem2Character(ch, "pistol1a+3"); //SCM
	ch.equip.gun = "pistol1a+3"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Vassal Bethune_dialog.c"; //SCM
	ch.greeting = "Gr_Vassal Bethune"; //SCM
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);	
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 4 //SCM
	ch.old.name = "Daryl"; //SCM
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Daryl"); //SCM
	ch.lastname = " ";
	ch.id		= "Thug4"; //SCM
	ch.model = "pirat2"; //SCM
	ch.sex = "man";
	ch.sound_type = "Daryl"; //SCM
	GiveItem2Character(ch, "bladeC26"); //SCM
	ch.equip.blade = "bladeC26"; //SCM
	GiveItem2Character(ch, "pistol2"); //SCM
	ch.equip.gun = "pistol2"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "Hit_houseB";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Daryl_dialog.c";
	ch.greeting = "Gr_Daryl";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 5 //SCM
	ch.old.name = "Larry"; //SCM
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Larry"); //SCM
	ch.lastname = " ";
	ch.id		= "Thug5"; //SCM
	ch.model = "bugmanpirat14"; //SCM
	ch.sex = "man";
	ch.sound_type = "Larry"; //SCM
	GiveItem2Character(ch, "blade20"); //SCM
	ch.equip.blade = "blade20"; //SCM
	GiveItem2Character(ch, "pistol1a"); //SCM
	ch.equip.gun = "pistol1a"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "Hit_houseB";
	ch.location.group = "goto";
	ch.location.locator = "goto9";
	ch.Dialog.Filename = "Larry_dialog.c"; //SCM
	ch.greeting = "Gr_Larry"; //SCM
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 6 //SCM
	ch.old.name = "Daryl"; //SCM
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Daryl"); //SCM
	ch.lastname = " ";
	ch.id		= "Thug6"; //SCM
	ch.model = "korsar1"; //SCM
	ch.sex = "man";
	ch.sound_type = "Daryl"; //SCM
	GiveItem2Character(ch, "blade28"); //SCM
	ch.equip.blade = "blade28"; //SCM
	GiveItem2Character(ch, "pistol1a"); //SCM
	ch.equip.gun = "pistol1a"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "Hit_houseB";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "Daryl_dialog.c";
	ch.greeting = "Gr_Daryl";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 7 //SCM
	ch.old.name = "Thug";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Thug");
	ch.lastname = " ";
	ch.id		= "Thug7"; //SCM
	ch.model = "pirat8"; //SCM
	ch.sex = "man";
	ch.sound_type = "Thug"; //SCM
	GiveItem2Character(ch, "blade31"); //SCM
	ch.equip.blade = "blade31"; //SCM
	GiveItem2Character(ch, "pistol1a"); //SCM
	ch.equip.gun = "pistol1a"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "Hit_houseB";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "Gr_Thug";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Thug 8 //SCM
	ch.old.name = "Thug";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Thug");
	ch.lastname = " ";
	ch.id		= "Thug8"; //SCM
	ch.model = "pirat9"; //SCM
	ch.sex = "man";
	ch.sound_type = "Thug"; //SCM
	GiveItem2Character(ch, "blade19"); //SCM
	ch.equip.blade = "blade19"; //SCM
	GiveItem2Character(ch, "pistol2"); //SCM
	ch.equip.gun = "pistol2"; //SCM
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "Hit_houseB";
	ch.location.group = "goto";
	ch.location.locator = "goto8";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "Gr_Thug";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

	ch.old.name = "Thomas the";
	ch.old.lastname = "Terror";
	ch.name = TranslateString("","Thomas the");
	ch.lastname = TranslateString("","Terror");
	ch.id		= "Thug9";
	ch.model = "Thomas_the_Terror"; // Thomas the Terror
	ch.sex = "man";
	ch.loyality = 15;
	ch.sound_type = "pirate";
	ch.location	= "Hit_passage";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Thomas_dialog.c";
	ch.greeting = "Gr_Oxbay Citizen";
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
	ch.money = "10";
    LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Leone's Daughter Camille //SCM
	ch.old.name = "Camille"; //SCM
	ch.old.lastname = "Leone"; //SCM
	ch.name = TranslateString("", "Camille"); //SCM
	ch.lastname = TranslateString("", "Leone"); //SCM
	ch.id		= "Camille Leone"; //SCM
	ch.model = "mowngirl5"; //SCM
	ch.sex = "woman"; //SCM
	ch.sound_type = "Desiree' Muerte";  //SCM
	ch.location	= "Hit_passage";
	ch.location.group = "goto";
	ch.location.locator = "goto9";
	ch.Dialog.Filename = "Camille Leone_dialog.c"; //SCM
	ch.greeting = "Gr_Camille Leone"; //SCM
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_SetImmortal(ch, true);	
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pris 1 //SCM
	ch.old.name = "Prisoner";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Prisoner");
	ch.lastname = " ";
	ch.id		= "Pris1"; //SCM
	ch.model = "rabblack"; //SCM
	ch.sex = "man";
	ch.location	= "Hit_passage";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pris 2 //SCM
	ch.old.name = "Prisoner";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Prisoner");
	ch.lastname = " ";
	ch.id		= "Pris2"; //SCM
	ch.model = "rabblack_1"; //SCM
	ch.sex = "man";
	ch.location	= "Hit_passage";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pris 3 //SCM
	ch.old.name = "Prisoner";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Prisoner");
	ch.lastname = "";
	ch.id		= "Pris3"; //SCM
	ch.model = "rabWhite"; //SCM
	ch.sex = "man";
	ch.location	= "Hit_passage";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pris 4 //SCM
	ch.old.name = "Prisoner";
	ch.old.lastname = " ";
	ch.name = TranslateString("", "Prisoner");
	ch.lastname = "";
	ch.id		= "Pris4"; //SCM
	ch.model = "rabWhite1"; //SCM
	ch.sex = "man";
	ch.location	= "Hit_passage";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
	ch.rank 	= 3;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "0";
	ch.money = "200";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Geffrey Bampfylde
	ch.old.name = "Geffrey";
	ch.old.lastname = "Bampfylde";
	ch.name = TranslateString("", "Geffrey");
	ch.lastname = TranslateString("", "Bampfylde");
	ch.id		= "Geffrey Bampfylde";
	ch.model = "Nobleman";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "Hit_house1";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.Dialog.Filename = "Geffrey Bampfylde_dialog.c";
	ch.rank 	= 1;
	ch.reputation = "50";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "0";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "0";
	ch.money = "1000";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 30.0, 30.0);
	LAi_SetImmortal(ch, true);	
	ch.greeting = "Gr_Geffrey Bampfylde";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Bucho
	ch.old.name = "Bucho";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Bucho");
	ch.lastname = " ";
	ch.id		= "Bucho";
	ch.model = "man4";
	ch.sex = "man";
	ch.sound_type = "Thug";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";
	ch.location	= "Hit_house1";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Bucho_dialog.c";
	ch.greeting = "Gr_Thug";
	ch.rank 	= 2;
	ch.reputation = "20";
	ch.experience = "0";
	ch.skill.Leadership = "0";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "0";
	ch.money = "300";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetImmortal(ch, true);	
	LAi_SetHP(ch, 60.0, 60.0);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Pepin Bertillon
	ch.old.name = "Pepin";
	ch.old.lastname = "Bertillon";
	ch.name = TranslateString("", "Pepin");
	ch.lastname = TranslateString("", "Bertillon");
	ch.id		= "Pepin Bertillon";
	ch.model = "Pirat4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "bladec12");
	ch.equip.blade = "bladec12";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Pepin Bertillon_dialog.c";
	ch.rank 	= 4;
	ch.reputation = "30";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "0";
	ch.money = "1500";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 90.0, 90.0);
	LAi_SetImmortal(ch, true);	
	ch.greeting = "Gr_Pepin Bertillon";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Bertillon's guard 1
	ch.old.name = "Bertillon's guard";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Bertillon's guard");
	ch.lastname = " ";
	ch.id		= "Bertillon's guard1";
	ch.model = "pirat7";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bertillon's Guard_dialog.c";
	ch.greeting = "Gr_Bertillon's Guard";
	ch.rank 	= 2;
	ch.reputation = "30";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "0";
	ch.money = "500";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 70.0, 70.0);
	LAi_SetImmortal(ch, true);	
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Bertillon's guard 2
	ch.old.name = "Bertillon's guard";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Bertillon's guard");
	ch.lastname = " ";
	ch.id		= "Bertillon's guard2";
	ch.model = "pirat5";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bertillon's Guard_dialog.c";
	ch.greeting = "Gr_Bertillon's Guard";
	ch.rank 	= 2;
	ch.reputation = "30";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "0";
	ch.skill.Sneak = "0";
	ch.money = "500";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 70.0, 70.0);
	LAi_SetImmortal(ch, true);	
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

				// Vito Leone
	ch.old.name = "Vito";
	ch.old.lastname = "Leone";
	ch.name = TranslateString("", "Vito");
	ch.lastname = TranslateString("", "Leone");
	ch.id		= "Vito Leone";
	ch.model = "Vito";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Vito Leone_dialog.c";
	ch.rank 	= 7;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "0";
	ch.skill.Accuracy = "0";
	ch.skill.Cannons = "0";
	ch.skill.Grappling = "0";
	ch.skill.Repair = "0";
	ch.skill.Defence = "0";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "0";
	ch.money = "7000";
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 90.0, 90.0);
	LAi_SetImmortal(ch, true);	
	ch.greeting = "Gr_Vito Leone";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
	
	// Amerigo Vieira //SCM Changes
	ch.old.name = "Amerigo";
	ch.old.lastname = "Vieira";
	ch.name = TranslateString("", "Amerigo");		// KevAtl - should give him back a first name
	ch.lastname = TranslateString("", "Vieira");
	ch.id		= "Amerigo Vieira";
	ch.model = "ancient"; //SCM
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.loyality = 7;
	ch.alignment = "bad";
	GiveItem2Character(ch, "bladeSC"); // KevAtl 09-09-2007
	ch.equip.blade = "bladeSC"; // KevAtl
	ch.nation	= PORTUGAL; //SC
	ch.location	= "Hit_house2";
	ch.location.group = "goto";
	ch.location.locator = "goto4";
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
	LAi_SetImmortal(ch, true);	
	ch.quest.officertype = OFFIC_TYPE_ABORDAGE;	// KevAtl to make him a Deck Fighter AKA Tough
	ch.HPBonus = 100;		// KevAtl to correct for game giving much less than 150hp when hired
	ch.skill.freeskill = 2;		// KevAtl added as points to increase ability later in game
	ch.perks.freepoints = 1;	// KevAtl ditto
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;		// GR: attempt to make his skills stick, otherwise leveling system resets them and he isn't Fencing 10 any more
	AddGameCharacter(n, ch);	

//Modified Hitman

//Nicholas Butcher
	ch.old.name = "Nicholas";
	ch.old.lastname = "Butcher";
	ch.name = TranslateString("", "Nicholas");
	ch.lastname = TranslateString("", "Butcher");
	ch.id		= "Nicholas Butcher";
	ch.model = "Pirat15";
	ch.sound_type = "pirate";
	ch.sex = "man";
	GiveItem2Character(ch, "blade31");
	ch.equip.blade = "blade31";
	GiveItem2Character(ch, "pistol2+3");
	ch.equip.gun = "pistol2+3";
	GiveItem2Character(ch, "commonarmor");
	ch.equip.armor = "commonarmor";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Nicholas Butcher_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 15;
	ch.reputation = "None";
	ch.experience = "0";
	ch.Ship.Name = "The Insatiable";
	ch.Ship.Type = 	"Xebec1";	
	ch.Ship.Stopped = true;	
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "2";
	ch.money = "10";
    ch.questchar = true;	
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.ProfessionalGunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.ShipSpeedUp = true;
	ch.perks.list.LightRepair = true;
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 180.0, 180.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Laurence Wellman";
	AddGameCharacter(n, ch);

	// Roche Brasiliano
	ch.old.name = "Roche";
	ch.old.lastname = "Brasiliano";
	ch.name 	= TranslateString("", "Roche"); 
	ch.lastname 	= TranslateString("", "Brasiliano");
	ch.id		= "Roche Brasiliano";
	ch.model = "Roche";
	ch.sex = "man"; 
	ch.loyality = 9;
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.nation	= PIRATE;
	ch.sound_type = "pirate"; 
	GiveItem2Character(ch, "blade34");
	ch.equip.blade = "blade34";
	GiveItem2Character(ch, "PiratesPistol");
	ch.equip.gun = "PiratesPistol";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Roche Brasiliano_dialog.c";
	ch.rank 	= 25;
	ch.reputation = "42";
	TakeNItems(ch,"potion1", Rand(4)+1);
	ch.experience = 20000;
	ch.skill.Leadership = "7";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "5";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.Ship.Name = "Quick Death";
	ch.Ship.Type = "PiratFastGal";
// KK -->
	ch.Ship.EmblemedSails.normalTex = "sail_whole_black_plain.tga";
	ch.Ship.EmblemedSails.nationFileName = "sail_whole_black_plain.tga";
// <-- KK
	ch.Ship.Stopped = true;
	ch.nosurrender = 2;
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
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.ShipSpeedUp = true;
	ch.perks.list.LightRepair = true;
	ch.perks.list.SharedExperience = true;
	ch.perks.list.BasicCommerce = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 300.0, 300.0);
	LAi_NoRebirthEnable(ch);	
	ch.greeting = "Gr_Douwesen_soldiers_01";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
	
	// Rock Braziliano
	ch.old.name = "Roche";
	ch.old.lastname = "Brasiliano";
	ch.name 	= TranslateString("", "Roche"); 
	ch.lastname 	= TranslateString("", "Brasiliano");
	ch.id		= "Rock Braziliano";
	ch.model = "Roche";
	ch.sex = "man"; 
	ch.loyality = 9;
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.nation	= PIRATE;
	ch.sound_type = "pirate"; 
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Roche Brasiliano_dialog.c";
	ch.rank 	= 25;
	ch.reputation = "42";
	TakeNItems(ch,"potion1", Rand(4)+1);
	ch.experience = 20000;
	ch.skill.Leadership = "7";
	ch.skill.Fencing = "9";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "5";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.money = "0";
	ch.quest.meeting = "0";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 300.0, 300.0);
	LAi_NoRebirthEnable(ch);	
	ch.greeting = "Gr_Douwesen_soldiers_01";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);	

// Spanish Soldier.
	ch.nation = SPAIN;
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "spanish_soldier_01";
	ch.model = "Soldier_Spa_16";
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Isla Muelle soldier_dialog.c";
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
	ch.quest.meeting = "0";
    LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

// Spanish Soldier 2
	ch.nation = SPAIN;
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "spanish_soldier_02";
	ch.model = "Soldier_Spa2_16";
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Isla Muelle soldier_dialog.c";
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
	ch.quest.meeting = "0";
    LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

// Spanish Soldier 3
	ch.nation = SPAIN;
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "spanish_soldier_03";
	ch.model = "Soldier_Spa3_16";
	ch.sex = "man";
	ch.sound_type = "soldier";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "survivor_dialog.c";
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
	ch.quest.meeting = "0";
    LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_SetImmortal(ch, true);
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);

//Renouart Baumont	
	ch.old.name = "Renouart";
	ch.old.lastname = "Baumont";
	ch.name = TranslateString("", "Renouart");
	ch.lastname = TranslateString("", "Baumont");
	ch.id		= "Renouart Baumont";
	ch.model	= "Corsair4";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Renouart Baumont_dialog.c";
	ch.greeting = "Gr_turpin cabanel";
	ch.rank 	= 6;
	ch.reputation = "40";
	ch.experience = "240";
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
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 8.0, 20.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Lady Gaga
	ch.old.name = "Lady";
	ch.old.lastname = "Gaga";
	ch.name = TranslateString("", "Lady");
	ch.lastname = TranslateString("", "Gaga");
	ch.id		= "Lady Gaga";
	ch.model = "Towngirl1";
	ch.sex = "woman";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Lady Gaga_dialog.c";
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

// Roche Guard 01
	ch.old.name = "Blaas";
	ch.old.lastname = "Davids";
	ch.name = TranslateString("", "Blaas");
	ch.lastname = TranslateString("", "Davids");
	ch.id		= "Roche_guard_01";
	ch.model	= "pirat2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_dialog.c";
	ch.nation = PIRATE;
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
	ch.greeting = "Gr_Oxbay Citizen";	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_SetImmortal(ch, true);
	LAi_NoRebirthEnable(ch);	
	LAi_group_MoveCharacter(ch, "ROCHE_HOUSE");	
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Roche Guard 02
	ch.old.name = "Paul";
	ch.old.lastname = "Brink";
	ch.name = TranslateString("", "Paul");
	ch.lastname = TranslateString("", "Brink");
	ch.id		= "Roche_guard_02";
	ch.model	= "pirat3";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade11");
	ch.equip.blade = "blade11";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_dialog.c";
	ch.nation = PIRATE;
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
	ch.greeting = "Gr_Oxbay Citizen";	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_SetImmortal(ch, true);
	LAi_NoRebirthEnable(ch);	
	LAi_group_MoveCharacter(ch, "ROCHE_HOUSE");		
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);
	
// Roche Guard 03
	ch.old.name = "Sampson";
	ch.old.lastname = "Burrell";
	ch.name = TranslateString("", "Sampson");
	ch.lastname = TranslateString("", "Burrell");
	ch.id		= "Roche_guard_03";
	ch.model	= "pirat4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
     //JRH ammo mod -->
	if (ENABLE_AMMOMOD) {	// LDH change
		TakenItems(ch, "gunpowder", 1 + rand(2));
		TakenItems(ch, "pistolbullets", 1 + rand(2));
	}
     //JRH ammo mod <--
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "French_dialog.c";
	ch.nation = PIRATE;
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
	ch.greeting = "Gr_Oxbay Citizen";	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);	
	LAi_group_MoveCharacter(ch, "ROCHE_GARDAS");		
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);	

// Cesario de Rosas
	ch.old.name = "Cesario";
	ch.old.lastname = "de Rosas";
	ch.name = TranslateString("", "Cesario");
	ch.lastname = TranslateString("", "de Rosas");
	ch.id		= "Cesario de Rosas";
	ch.model = "Huber_Por2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Cesario de Rosas_dialog.c";
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
	ch.greeting = "Gr_christofor manuel de alencar";		
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 120.0, 120.0);
	LAi_SetImmortal(ch, true);	
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Hans Delorme
	ch.old.name = "Hans";
	ch.old.lastname = "Delorme";
	ch.name = TranslateString("", "Hans");
	ch.lastname = TranslateString("", "Delorme");
	ch.id		= "Hans Delorme";
	ch.model	= "man4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Hans Delorme_dialog.c";
	ch.greeting = "Gr_Douwesen Citizen";
	ch.rank 	= 2;
	ch.reputation = "None";
	ch.experience = "80";
	ch.skill.Leadership = "2";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "0";
    ch.questchar = true;	
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

	// Rabel Chardon
	ch.old.name = "Rabel";
	ch.old.lastname = "Chardon";
	ch.name 	= TranslateString("", "Rabel"); 
	ch.lastname 	= TranslateString("", "Chardon");
	ch.id		= "Rabel Chardon";
	ch.model = "Rabel_Chardon";
	ch.sex = "man"; 
	ch.loyality = 9;
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.nation	= FRANCE;
	ch.sound_type = "pirate"; 
	GiveItem2Character(ch, "blade9");
	ch.equip.blade = "blade9";
	GiveItem2Character(ch, "pistol8");
	ch.equip.gun = "pistol8";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "";
	ch.rank 	= 15;
	ch.reputation = "42";
	ch.experience = 2000;
	ch.skill.Leadership = "7";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "5";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.Ship.Name = "Belleville";
	ch.Ship.Type = "FR_Derfflinger";
	ch.Ship.Stopped = true;
	ch.nosurrender = 2;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 200.0, 200.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

	// Jeremy Tripper
	ch.old.name = "Jeremy";
	ch.old.lastname = "Tripper";
	ch.name 	= TranslateString("", "Jeremy"); 
	ch.lastname 	= TranslateString("", "Tripper");
	ch.id		= "Jeremy Tripper";
	ch.model = "Jeremy_Tripper";
	ch.sex = "man"; 
	ch.loyality = 9;
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.nation	= ENGLAND;
	ch.sound_type = "pirate"; 
	GiveItem2Character(ch, "bladeC30");
	ch.equip.blade = "bladeC30";
	GiveItem2Character(ch, "pistol7a");
	ch.equip.gun = "pistol7a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Jeremy Tripper_dialog.c";
	ch.rank 	= 15;
	ch.reputation = "42";
	ch.experience = 2000;
	ch.skill.Leadership = "7";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "5";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.Ship.Name = "Magnificent";
	ch.Ship.Type = "RN_RevengeW";
	ch.Ship.Stopped = true;
	ch.Flags.Personal = 4; // PB: Not Johan Elting's Flag
	ch.Flags.Personal.texture = 1;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 200.0, 200.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Redmond Soldier";
	AddGameCharacter(n, ch);

	// Clement Bossicar
	ch.old.name = "Clement";
	ch.old.lastname = "Bossicar";
	ch.name 	= TranslateString("", "Clement"); 
	ch.lastname 	= TranslateString("", "Bossicar");
	ch.id		= "Clement Bossicar";
	ch.model = "Huber_Fra4_17";
	ch.sex = "man"; 
	ch.loyality = 9;
	ch.nodisarm	= 1;				// PB: Disable disarming
	ch.nation	= FRANCE;
	ch.sound_type = "pirate"; 
	GiveItem2Character(ch, "blade9");
	ch.equip.blade = "blade9";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--	
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "";
	ch.rank 	= 15;
	ch.reputation = "42";
	ch.experience = 2000;
	ch.skill.Leadership = "7";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "6";
	ch.skill.Grappling = "4";
	ch.skill.Repair = "5";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "5";
	ch.money = "0";
	ch.quest.meeting = "0";
	ch.Ship.Name = "La Precieuse";
	ch.Ship.Type = "Lineship47";
	ch.Ship.Stopped = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 200.0, 200.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_falaise de fleur soldier";
	AddGameCharacter(n, ch);

// Wilfred Larner
	ch.old.name = "Wilfred";
	ch.old.lastname = "Larner";
	ch.name = TranslateString("", "Wilfred");
	ch.lastname = TranslateString("", "Larner");
	ch.id		= "Wilfred Larner";
	ch.model = "bocman8";
	ch.sex = "man";
	ch.sound_type = "seaman";
	LAi_NoRebirthEnable(ch);
	GiveItem2Character(ch, "blade11");
	ch.equip.blade = "blade11";
	ch.location	= "none"
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Wilfred Larner_dialog.c";
	ch.nation = ENGLAND;
	ch.Ship.Name = "The Bulldog";
	ch.Ship.Type = 	"PO_Caravel50";			
	ch.Ship.Stopped = true;
	ch.rank 	= 1;
	ch.reputation = "52";
	ch.experience = "0";
	ch.skill.Leadership = "4";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "2";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "1";
	ch.money = "10";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_SetStayType(ch);	
	ch.greeting = "Gr_Oxbay Citizen";
	ch.questchar = true;//MAXIMUS: identifier for captives
	AddGameCharacter(n, ch);

// Bartolomeu o Portugues
	ch.old.name = "Bartolomeu";
	ch.old.lastname = "o Portugues";
	ch.name = TranslateString("", "Bartolomeu");
	ch.lastname = TranslateString("", "o Portugues");
	ch.id		= "Bartolomeu";
	ch.model = "GypsyCaptn_5";
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "bladeBP");
	ch.equip.blade = "bladeBP";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";		
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Bartolomeu o Portugues_dialog.c";
	ch.nation = PORTUGAL;
	ch.rank 	= 20;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "6";
	ch.money = "10";
    ch.questchar = true;	
	ch.Ship.Name = "Santiago";
	ch.Ship.Type = 	"FastCaravel";
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 4;
	ch.Flags.Pirate.texture = 0;
	ch.Flags.Personal = 1;	
	ch.Flags.Personal.texture = 1;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.ProfessionalGunman = true;
	ch.perks.list.Rush = true;
	ch.perks.list.FastReload = true;
	ch.perks.list.HullDamageUp = true;
	ch.perks.list.CrewDamageUp = true;
	ch.perks.list.BasicDamageControl = true;
	ch.perks.list.Rigging = true;
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.ShipSpeedUp = true;
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Bartolomeu o Portugues";
	AddGameCharacter(n, ch);
	
//   Emilio Soares
	ch.old.name = "Emilio";
	ch.old.lastname = "Soares";
	ch.name = TranslateString("", "Emilio");
	ch.lastname = TranslateString("", "Soares");
	ch.id		= "Emilio Soares";
	ch.model	= "Emilio1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.nodisarm	= 1;
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Emilio Soares_dialog.c";
	ch.greeting = "Gr_Emilio Soares";
	ch.rank 	= 5;
	ch.reputation = "None";
	ch.experience = "0";	
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "1";
	ch.money = "0";
    ch.questchar = true;	
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.HPBonus = 100;
	ch.quest.officertype = OFFIC_TYPE_BOATSWAIN;
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);	

	// Henry Morgan
	ch.old.name = "Henry";
	ch.old.lastname = "Morgan";
	ch.name = TranslateString("", "Henry");
	ch.lastname = TranslateString("", "Morgan");
	ch.id		= "Henry Morgan";
	ch.model	= "Henry_Morgan";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade34");
	ch.equip.blade = "blade34";
	ch.nation	= PIRATE;
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Henry Morgan_dialog.c";
	ch.Ship.Name = "Jamaica Merchant";
	ch.Ship.Type = 	"RN_WarGalleon";
	ch.Ship.Stopped = true;
	ch.rank 	= 25;
	ch.reputation = "None";
	ch.experience = "0";
	ch.greeting = "Gr_Ralph Fawn";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "6";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "3";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "6";
	ch.skill.Sneak = "5";
	ch.money = "10";
    ch.questchar = true;	
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 250.0, 250.0);
	AddGameCharacter(n, ch);

// Berend de Voor
	ch.old.name = "Berend";
	ch.old.lastname = "de Voor";
	ch.name = TranslateString("", "Berend");
	ch.lastname = TranslateString("", "de Voor");
	ch.id		= "Berend de Voor";
	ch.model = "Berend_de_Voor";
	ch.sound_type = "soldier";
	ch.sex = "man";
	GiveItem2Character(ch, "bladec26");
	ch.equip.blade = "bladec26";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Berend de Voor_dialog.c";
	ch.nation = HOLLAND;
	ch.rank 	= 18;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "5";
	ch.skill.Cannons = "4";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "3";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "2";
	ch.money = "10";
    ch.questchar = true;	
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.ProfessionalGunman = true;
	ch.perks.list.Rush = true;
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 180.0, 180.0);
	LAi_SetImmortal(ch, true);	
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Douwesen Soldier";
	AddGameCharacter(n, ch);

// Spanish Soldier.
	ch.nation = SPAIN;
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "spanish_soldat_09";
	ch.model = "Soldier_Spa2_16";
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Divers_dialog.c";
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
	ch.quest.meeting = "0";
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_SOLDIERS");
	ch.greeting = "Gr_isla muelle soldier";
	AddGameCharacter(n, ch);
	
// Leonardo Corrales	
	ch.old.name = "Leonardo";
	ch.old.lastname = "Corrales";
	ch.name = TranslateString("", "Leonardo");
	ch.lastname = TranslateString("", "Corrales");
	ch.id		= "Leonardo Corrales";
	ch.model	= "Leonardo_Corrales"; 
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = SPAIN;
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Leonardo Corrales_dialog.c";
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
    ch.questchar = true;	
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_isla muelle citizen";
	AddGameCharacter(n, ch);	

// Andrew Parson
	ch.old.name = "Andrew";
	ch.old.lastname = "Parson";
	ch.name = TranslateString("", "Andrew");
	ch.lastname = TranslateString("", "Parson");
	ch.id		= "Andrew Parson";
	ch.model	= "Andrew_Parson";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Andrew Parson_dialog.c";
	ch.greeting = "Gr_QC Citizen";
	ch.rank 	= 3;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "2";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_NoRebirthEnable(ch);
	AddGameCharacter(n, ch);

// William Cotter
	ch.old.name = "William";
	ch.old.lastname = "Cotter";
	ch.name = TranslateString("", "William");
	ch.lastname = TranslateString("", "Cotter");
	ch.id		= "William Cotter";
	ch.model	= "Offic_eng_16";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade11");
	ch.equip.blade = "blade11";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "William Cotter_dialog.c";	
	ch.rank 	= 8;
	ch.reputation = "None";
	ch.experience = "80";
	ch.skill.Leadership = "5";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "3";
	ch.money = "100";
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_SOLDIERS");
	LAi_NoRebirthEnable(ch);	
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	AddGameCharacter(n, ch);

// Roxanne Lalliere	
	ch.old.name = "Roxanne"; 
	ch.old.lastname = "Lalliere";
	ch.name = TranslateString("", "Roxanne"); 
	ch.lastname = TranslateString("", "Lalliere");
	ch.id		= "Roxanne Lalliere";
	ch.model	= "Roxanne";
	ch.sex = "woman";
	ch.sound_type = "pirate";
	ch.nation = FRANCE;
	GiveItem2Character(ch, "blthag02");
	ch.equip.blade = "blthag02";
	GiveItem2Character(ch, "pistol1a");
	ch.equip.gun = "pistol1a";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Roxanne Lalliere_dialog.c";
	ch.rank 	= 12;
	ch.reputation = "None";
	ch.Ship.Name = "La Diablesse";
	ch.Ship.Type = 	"FR_LightPinnace";	
	ch.Ship.Stopped = true;
	ch.Flags.Pirate = 6; // GR
	ch.Flags.Pirate.texture = 3; // GR
	ch.Flags.Personal = 5; // GR
	ch.Flags.Personal.texture = 5; // GR
	ch.experience = "0";
	ch.greeting = "Gr_Woman_French citizen";
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "2";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "3";
	ch.money = "0";
    ch.questchar = true;	
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;	
	ch.perks.list.ShipSpeedUp = true;
	ch.perks.list.ShipTurnRateUp = true;
	ch.perks.list.StormProfessional = true;
	ch.perks.list.SandbankManeuver = true;
	ch.perks.list.SailingProfessional = true;
	LAi_SetCitizenType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 120.0, 120.0);
	AddGameCharacter(n, ch);

//  Guibert Daudet
	ch.old.name = "Guibert";
	ch.old.lastname = "Daudet";
	ch.name = TranslateString("", "Guibert");
	ch.lastname = TranslateString("", "Daudet");
	ch.id		= "Guibert Daudet";
	ch.model	= "Guibert_Daudet";
	ch.sex = "man";
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Guibert Daudet_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 5;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "3";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "2";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "0";
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	ch.greeting = "Gr_turpin cabanel";
	AddGameCharacter(n, ch);

			// Dutch soldier
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "SoldatD1";
	ch.model = "soldier_hol2_16"; 
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "bladeC26");
	ch.equip.blade = "bladeC26";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.nation = HOLLAND;
	ch.rank 	= 1;
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "DUTCH_SOLDIERS");
	AddGameCharacter(n, ch);
	
			// Dutch soldier
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "SoldatD2";
	ch.model = "soldier_hol3_16"; 
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "bladeC26");
	ch.equip.blade = "bladeC26";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.nation = HOLLAND;
	ch.Dialog.Filename = "Divers_dialog.c";	
	ch.rank 	= 1;
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "DUTCH_SOLDIERS");
	AddGameCharacter(n, ch);

	ch.old.name = "Diablo";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Diablo");
	ch.lastname = "";
	ch.id		= "Diablo";
	ch.nation	= PERSONAL_NATION;
	ch.model	= "Hugnt18";
	ch.sex = "man";	
	ch.Ship.Name = "El Diablo";
	ch.Ship.Type = "XebecAS";
	ch.Ship.Stopped = true; 
	LAi_SetLoginTime(ch, 0.0, 24.0);
	AddGameCharacter(n, ch);

// Captain Villalobos
	ch.old.name = "Captain";
	ch.old.lastname = "Villalobos";
	ch.name = TranslateString("", "Captain");
	ch.lastname = TranslateString("", "Villalobos");
	ch.id		= "Captain Villalobos";
	ch.model	= "hub_spa4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade28");
	ch.equip.blade = "blade28";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Spaniards_dialog.c";
	ch.greeting = "Gr_isla muelle soldier";
	ch.rank 	= 10;
	ch.reputation = "None";
	ch.experience = "80";	
	ch.skill.Leadership = "6";
	ch.skill.Fencing = "5";
	ch.skill.Sailing = "3";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "2";
	ch.skill.Repair = "1";
	ch.skill.Defence = "4";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "3";
	ch.money = "0";
    ch.questchar = true;	
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 100.0, 100.0);
	LAi_group_MoveCharacter(ch, "VILLA_SOLDIERS");	
	AddGameCharacter(n, ch);

			// Villalobos' soldier 1
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "VillaSoldat1";
	ch.model = "soldier_spa2_16"; 
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.nation = SPAIN;
	ch.rank 	= 1;
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "VILLA_SOLDIERS");
	AddGameCharacter(n, ch);
	
			// Villalobos' soldier 2
	ch.old.name = "Soldier";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Soldier");
	ch.lastname = "";
	ch.id		= "VillaSoldat2";
	ch.model = "soldier_spa3_16"; 
	ch.sex = "man";
	ch.sound_type = "soldier";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	ch.location	= "";
	ch.location.group = "";
	ch.location.locator = "";
	ch.nation = SPAIN;
	ch.Dialog.Filename = "Divers_dialog.c";	
	ch.rank 	= 1;
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "VILLA_SOLDIERS");
	AddGameCharacter(n, ch);

//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "elting_pirate_02";
	ch.model	= "pirat2";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";	
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "elting_pirate_03";
	ch.model	= "pirat3";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "bladeC12");
	ch.equip.blade = "bladeC12";	
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "elting_pirate_04";
	ch.model	= "pirat4";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade10");
	ch.equip.blade = "blade10";	
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "elting_pirate_05";
	ch.model	= "pirat5";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade11");
	ch.equip.blade = "blade11";	
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "elting_pirate_06";
	ch.model	= "pirat6";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.Dialog.Filename = "Divers_dialog.c";
	ch.greeting = "Gr_Francisco Cruz";	
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";	
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "elting_pirate_01";
	ch.model	= "pirat1";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade6");
	ch.equip.blade = "blade6";	
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

//  crew
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "elting_pirate_07";
	ch.model	= "pirat3";
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade20");
	ch.equip.blade = "blade20";	
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

//  crew (climbing)
	ch.old.name = "Pirate";
	ch.old.lastname = "";
	ch.name = TranslateString("", "Pirate");
	ch.lastname = "";
	ch.id		= "elting_pirate_01c";
	ch.model	= "pirat1";
    ch.model.animation = "climb";	
	ch.sex = "man";
	ch.sound_type = "pirate";
	GiveItem2Character(ch, "blade36");
	ch.equip.blade = "blade36";	
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
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
	LAi_SetStayType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	AddGameCharacter(n, ch);

	ch.old.name = "Capitan";
	ch.old.lastname = "Caceres";
	ch.name = TranslateString("", "Capitan");
	ch.lastname = TranslateString("", "Caceres");
	ch.id		= "Capitan Caceres";
	ch.model	= "Espinosa";
	ch.model.animation = "man"; // PB
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "none";
	ch.location.group = "";
	ch.location.locator = "";
	ch.Dialog.Filename = "Divers_dialog.c";
	GiveItem2Character(ch, "bladeC30");
	ch.equip.blade = "bladeC30";
	GiveItem2Character(ch, "pistol8");
	ch.equip.gun = "pistol8";
	//JRH ammo mod -->
	TakenItems(ch, "gunpowder", 6);
	TakenItems(ch, "pistolbullets", 6);
	//JRH ammo mod <--
	ch.rank 	= 40;
	ch.reputation = "60";
	ch.experience = "2000000";
	ch.greeting = "Gr_isla muelle soldier";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.AdvancedDefence = true;
	ch.perks.list.SwordplayProfessional = true;
	ch.perks.list.CriticalHit = true;
	ch.perks.list.Gunman = true;
	ch.perks.list.ProfessionalGunman = true;	
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
	ch.money = "1000";
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 280.0, 280.0);
	ch.questchar = true;
	AddGameCharacter(n, ch);	
}
	
