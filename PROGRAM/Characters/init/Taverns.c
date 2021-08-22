/* Estharos Modification March, 2009
- Put all Travern Characters into this file
- All character models have been reassigned
- Organise the characters per town in alphabetic order from Antigua to Willemstad for easier search
*/

void CreateTavernsCharacters(ref n)
{
	object chobj;
	ref ch;
	makeref(ch, chobj);

	//===============================| Alice Town |===============================//

	ch.old.name = "Robert";
	ch.old.lastname = "Wicker";
	ch.name 	= TranslateString("", "Robert");
	ch.lastname = TranslateString("", "Wicker");
	ch.id		= "Robert Wicker";
	ch.model	= "50M5";
	ch.sex = "man";
	ch.location	= "Alice_tavern";
	ch.location.group = "barmen";
	ch.location.locator = "bar2";
	ch.Dialog.Filename = "Robert Wicker_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Robert Wicker";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.repqtation = "None";
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
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	//===============================| Antigua Town |===============================//

//	Tavern Keeper
	ch.old.name = "Brian";
	ch.old.lastname = "Moods";
	ch.name = TranslateString("", "Brian");
	ch.lastname = TranslateString("", "Moods");
	ch.id		= "Brian Moods";
	ch.model	= "Pirtt7"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Antigua_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Brian Moods_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Simon Hanpool";
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
	ch.work = "";
	ch.money = "1";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
	
// KK --> Officiant
	ch.old.name = "Anne";
	ch.old.lastname = "Andress";
	ch.name = TranslateString("", "Anne");
	ch.lastname = TranslateString("", "Andress");
	ch.id		= "Antigua_officiant";
	ch.model	= "OldWoman1"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Antigua_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Antigua_Tavern_upstairs";
	ch.resurrection.shore = "Antigua_shore";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//===========================| Buccaneers Camp Town |===========================//

//	Tavern Keeper
	ch.old.name = "Florentin";
	ch.old.lastname = "Destot";
	ch.name = TranslateString("", "Florentin");
	ch.lastname = TranslateString("", "Destot");
	ch.id		= "Florentin Destot";
	ch.model = "Corsair2"; // Estharos Change from 33_Ronald to this model
	ch.sex = "man";
	ch.location	= "BC_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Florentin Destot_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_antoine lebretton";
	ch.nation = PIRATE;
	ch.rank 	= 1;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.work = "";
	ch.quest.meeting = "0";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Joanne";
	ch.old.lastname = "Ellene";
	ch.name = TranslateString("", "Joanne");
	ch.lastname = TranslateString("", "Ellene");
	ch.id		= "BuccaneersCamp_officiant";
	ch.model	= "Downgir52"; // Estharos Change from towngirl6 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "BC_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "BC_Tavern_upstairs";
	ch.resurrection.shore = "Hispaniola_shore_02";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//=============================| Charlestown Town |=============================//

//	Tavern Keeper	
	ch.old.name = "Pete";
	ch.old.lastname = "Manchester";
	ch.name = TranslateString("", "Pete");
	ch.lastname = TranslateString("", "Manchester");
	ch.id		= "Pete Manchester";
	ch.model	= "Corsair1"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Charlestown_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Pete Manchester_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Simon Hanpool";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.repqtation = "None";
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
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Agnes";
	ch.old.lastname = "Marley";
	ch.name = TranslateString("", "Agnes");
	ch.lastname = TranslateString("", "Marley");
	ch.id		= "Charlestown_officiant";
	ch.model	= "Downgir51"; // Estharos Change from towngirl3 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Charlestown_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Charlestown_Tavern_upstairs";
	ch.resurrection.shore = "QC_Shore1";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//==============================| Conceicao Town |==============================//
	
//	Tavern Keeper
	ch.old.name = "Duarte";
	ch.old.lastname = "Correja";
	ch.name = TranslateString("", "Duarte");
	ch.lastname = TranslateString("", "Correja");
	ch.id		= "Duarte Correja";
	ch.model	= "sailor15"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Conceicao_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Duarte Correja_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Duarte Correja";
	ch.nation = PORTUGAL;
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
	ch.work = "";
	ch.money = "1";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "CONCEICAO_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Laurenco";
	ch.old.lastname = "Costa";
	ch.name = TranslateString("", "Laurenco");
	ch.lastname = TranslateString("", "Costa");
	ch.id		= "Laurenco Costa";
	ch.model	= "shkiper";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "Conceicao_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Conceicao Citizen";
	ch.nation = PORTUGAL;
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "CONCEICAO_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Carlos";
	ch.old.lastname = "Resende";
	ch.name = TranslateString("", "Carlos");
	ch.lastname = TranslateString("", "Resende");
	ch.id		= "Carlos Resende";
	ch.model	= "fatman";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "Conceicao_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit7";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Conceicao Citizen";
	ch.nation = PORTUGAL;
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_group_MoveCharacter(ch, "CONCEICAO_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Helena";
	ch.old.lastname = "Azocar";
	ch.name = TranslateString("", "Helena");
	ch.lastname = TranslateString("", "Azocar");
	ch.id		= "Conceicao_officiant";
	ch.model	= "Downgirl2"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Conceicao_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Conceicao_Tavern_upstairs";
	ch.resurrection.shore = "Conceicao_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = PORTUGAL;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "CONCEICAO_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//===============================| Douwesen Town |==============================//

//	Tavern Keeper	
	ch.old.name = "Friedrich";
	ch.old.lastname = "Corleis";
	ch.name = TranslateString("", "Friedrich");
	ch.lastname = TranslateString("", "Corleis");
	ch.id		= "Friedrich Corleis";
	ch.model	= "bocman1"; // Estharos Change from man5 to this model
	ch.sex = "man";
	ch.location	= "Douwesen_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Friedrich Corleis_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.nation = HOLLAND;
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
	ch.money = "2";
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Friedrich Corleis";
	AddGameCharacter(n, ch);

	ch.old.name = "Baernt";
	ch.old.lastname = "Jans";
	ch.name = TranslateString("", "Baernt");
	ch.lastname = TranslateString("", "Jans");
	ch.id		= "Baernt Jans";
	ch.model	= "fatman2";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "Douwesen_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit7";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Douwesen Citizen";
	ch.nation = HOLLAND;
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Olivier";
	ch.old.lastname = "Fessler";
	ch.name = TranslateString("", "Olivier");
	ch.lastname = TranslateString("", "Fessler");
	ch.id		= "Olivier Fessler";
	ch.model	= "korsar";
	ch.sex = "man";
	ch.sound_type = "seaman";
	ch.location	= "Douwesen_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Douwesen Citizen";
	ch.nation = HOLLAND;
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 5.0, 21.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Tanneken";
	ch.old.lastname = "Clemens";
	ch.name = TranslateString("", "Tanneken");
	ch.lastname = TranslateString("", "Clemens");
	ch.id		= "Douwesen_officiant";
	ch.model	= "Downgir53"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Douwesen_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Douwesen_Tavern_upstairs";
	ch.resurrection.shore = "Douwesen_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = HOLLAND;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//==============================| Eleuthera Town |==============================//

	ch.old.name = "Brian";
	ch.old.lastname = "Armstrong";
	ch.name 	= TranslateString("", "Brian");
	ch.lastname = TranslateString("", "Armstrong");
	ch.id		= "Brian Armstrong";
	ch.model	= "50M5";
	ch.sex = "man";
	ch.location	= "Eleuthera_tavern";
	ch.location.group = "barmen";
	ch.location.locator = "bar2";
	ch.Dialog.Filename = "Brian Armstrong_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Brian Armstrong";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.repqtation = "None";
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
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

// Sulan --> Officiant
	ch.old.name = "Sulana";
	ch.old.lastname = "Armstrong";
	ch.name = TranslateString("", "Sulana");
	ch.lastname = TranslateString("", "Armstrong");
	ch.id		= "Eleuthera_officiant";
	ch.model	= "Downgir51"; 
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Eleuthera_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Eleuthera_tavern_upstairs";
	ch.resurrection.shore = "Eleuthera_shore_Ship";
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
// <-- Sulan

	//==========================| Falaise De Fleur Town |===========================//

//	Tavern Keeper	
	ch.old.name = "Antoine";
	ch.old.lastname = "Lebretton";
	ch.name = TranslateString("", "Antoine");
	ch.lastname = TranslateString("", "Lebretton");
	ch.id		= "Antoine Lebretton";
	ch.model = "Sailor6"; // Estharos Change from Old_man1 to this model
	ch.sex = "man";
	ch.location	= "Falaise_de_fleur_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Antoine Lebretton_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_antoine lebretton";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.work = "";
	ch.quest.meeting = "0";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	AddGameCharacter(n, ch);
	
	ch.old.name = "Thierry";
	ch.old.lastname = "Bosquet";
	ch.name = TranslateString("", "Thierry");
	ch.lastname = TranslateString("", "Bosquet");
	ch.id		= "Thierry Bosquet";
	ch.model = "Black_Corsair";
	ch.sound_type = "seaman";
	ch.sex = "man";
	GiveItem2Character(ch, "blade7");
	ch.equip.blade = "blade7";
	ch.location	= "Falaise_de_fleur_tavern";
	ch.location.group = "candles"; // GR: was "sit"
	ch.location.locator = "sit2";
	ch.Dialog.Filename = "Thierry Bosquet_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 3;
	ch.reputation = "35";
	ch.experience = "40";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "3";
	ch.skill.Cannons = "3";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "600";
	ch.quest.meeting = "0";
	ch.quest.gambling = "0";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_thierry bosquet";
	LAi_NoRebirthEnable(ch); //NK fix so he doesn't reappear and attack again after killing him.
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Pauline";
	ch.old.lastname = "Beteille";
	ch.name = TranslateString("", "Pauline");
	ch.lastname = TranslateString("", "Beteille");
	ch.id		= "Falaise_de_fleur_officiant";
	ch.model	= "Downgirl3"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "FALAISE_DE_FLEUR_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Falaise_de_fleur_Tavern_upstairs";
	ch.resurrection.shore = "Falaise_de_fleur_shore";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//=============================| Grand Cayman Town |============================//
	
//	Tavern Keeper
	ch.old.name = "Olyver";
	ch.old.lastname = "Littlejohn";
	ch.name 	= TranslateString("", "Olyver");
	ch.lastname = TranslateString("", "Littlejohn");
	ch.id		= "Olyver Littlejohn";
	ch.model	= "Old_mat1"; // Estharos no change
	ch.headmodel = "h_Old_mat1";
	ch.sex = "man";
	ch.location	= "Grand_Cayman_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Olyver Littlejohn_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Olyver Littlejohn";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.repqtation = "None";
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
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Julia";
	ch.old.lastname = "Stirling";
	ch.name = TranslateString("", "Julia");
	ch.lastname = TranslateString("", "Stirling");
	ch.id		= "Grand_Cayman_officiant";
	ch.model	= "towngirl1"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Grand_Cayman_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Grand_Cayman_Tavern_upstairs";
	ch.resurrection.shore = "Cayman_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//==============================| Greenford Town |==============================//

//	Tavern Keeper	
	ch.old.name = "Simon";
	ch.old.lastname = "Hanpool";
	ch.name 	= TranslateString("", "Simon");
	ch.lastname = TranslateString("", "Hanpool");
	ch.id		= "Simon Hanpool";
	ch.model	= "Corsair1_4"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Greenford_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Simon Hanpool_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Simon Hanpool";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.repqtation = "None";
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
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Ralph";
	ch.old.lastname = "Damerell";
	ch.name 	= TranslateString("", "Ralph");
	ch.lastname = TranslateString("", "Damerell");
	ch.id		= "Ralph Damerell";
	ch.model	= "Corsair3";
	ch.sound_type = "pirate";
	ch.sex = "man";
	ch.location	= "Greenford_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit5";
	ch.Dialog.Filename = "Greenford Citizen_Dialog.c"; //"Ralph Damerell_dialog.c"; //NK reenable Ralph's dialog, coming when fixed.
	ch.greeting = "Gr_Ralph Damerell";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 4.0, 19.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Frederyk";
	ch.old.lastname = "Kember";
	ch.name 	= TranslateString("", "Frederyk");
	ch.lastname = TranslateString("", "Kember");
	ch.id		= "Frederyk Kember";
	ch.model	= "man4";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.location	= "Greenford_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Greenford Citizen";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
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
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Nadine";
	ch.old.lastname = "Jansen";
	ch.name 	= TranslateString("", "Nadine");
	ch.lastname = TranslateString("", "Jansen");
	ch.id		= "Greenford_officiant";
	ch.model	= "towngirl3_1"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Greenford_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Greenford_Tavern_upstairs";
	ch.resurrection.shore = "Oxbay_Lighthouse";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
    ch.questchar = true;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//=============================| Isla Muelle Town |=============================//

//	Tavern Keeper	
	ch.old.name = "Claudio";
	ch.old.lastname = "Burrieza";
	ch.name = TranslateString("", "Claudio");
	ch.lastname = TranslateString("", "Burrieza");
	ch.id		= "Claudio Burrieza";
	ch.model = "50FatJack"; // Estharos Change from Fatman2 to this model
	ch.sex = "man";
	ch.location	= "Muelle_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Claudio Burrieza_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.nation = SPAIN;
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
	
	ch.old.name = "Tiago";
	ch.old.lastname = "Marquina";
	ch.name = TranslateString("", "Tiago");
	ch.lastname = TranslateString("", "Marquina");
	ch.id		= "Tiago Marquina";
	ch.model = "man4";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Muelle_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit7";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_isla muelle citizen";
	ch.nation = SPAIN;
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
	ch.quest.goldmine = "0";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Marinella";
	ch.old.lastname = "Castrilli";
	ch.name = TranslateString("", "Marinella");
	ch.lastname = TranslateString("", "Castrilli");
	ch.id		= "Muelle_officiant";
	ch.model	= "mowngirl7"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Muelle_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Muelle_Tavern_upstairs";
	ch.resurrection.shore = "Muelle_shore";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = SPAIN;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK

	//==============================| La Havana Town |==============================//

//	Tavern Keeper	
	ch.old.name = "Fadrique";
	ch.old.lastname = "Castillo";
	ch.name = TranslateString("", "Fadrique");
	ch.lastname = TranslateString("", "Castillo");
	ch.id		= "Fadrique Castillo";
	ch.model	= "blackman"; // Estharos no change
	ch.sex = "man";
	ch.location	= "Havana_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Fadrique Castillo_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.nation = SPAIN;
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
	ch.money = "2";
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_claudio burrieza";
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Leonor";
	ch.old.lastname = "Esperanza";
	ch.name = TranslateString("", "Leonor");
	ch.lastname = TranslateString("", "Esperanza");
	ch.id		= "Havana_officiant";
	ch.model	= "towngirl1_1"; // Estharos Change from towngirl5 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Havana_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Havana_Tavern_upstairs";
	ch.resurrection.shore = "Cuba_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = SPAIN;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//===============================| Marigot Town |===============================//

//	Tavern Keeper	
	ch.old.name = "Andre";
	ch.old.lastname = "Figaux";
	ch.name = TranslateString("", "Andre");
	ch.lastname = TranslateString("", "Figaux");
	ch.id		= "Andree Figaux";
	ch.model = "Corsair1_1"; // Estharos Change from mongol to this model
	ch.sex = "man";
	ch.location	= "Marigot_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Andre Figaux_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_antoine lebretton";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.work = "";
	ch.quest.meeting = "0";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Sophie";
	ch.old.lastname = "Neveu";
	ch.name = TranslateString("", "Sophie");
	ch.lastname = TranslateString("", "Neveu");
	ch.id		= "Marigot_officiant";
	ch.model	= "towngirl2";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Marigot_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Marigot_Tavern_upstairs";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//==============================| Oranjestad Town |=============================//

//	Tavern Keeper	
	ch.old.name = "Johannes";
	ch.old.lastname = "Harlekeyn";
	ch.name = TranslateString("", "Johannes");
	ch.lastname = TranslateString("", "Harlekeyn");
	ch.id		= "Johannes Harlekeyn";
	ch.model	= "bocman8"; // Estharos Change from corsair2 to this model
	ch.sex = "man";
	ch.location	= "Oranjestad_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Johannes Harlekeyn_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Gheerlof Darlang";
	ch.nation = HOLLAND;
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
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant	
	ch.old.name = "Alcke";
	ch.old.lastname = "Smitshoek";
	ch.name = TranslateString("", "Alcke");
	ch.lastname = TranslateString("", "Smitshoek");
	ch.id		= "Oranjestad_officiant";
	ch.model	= "towngirl6"; // Estharos Change from towngirl4 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Oranjestad_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Oranjestad_tavern_upstairs";
	ch.resurrection.shore = "Oranjestad_port";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = HOLLAND;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);
	
	//================================| Oxbay Town |================================//

//	Tavern Keeper	
	ch.old.name = "Everard";
	ch.old.lastname = "Gordon";
	ch.name 	= TranslateString("", "Everard");
	ch.lastname 	= TranslateString("", "Gordon");
	ch.id		= "Everard Gordon";
	ch.model	= "Pirat3"; // Estharos Change from old_man1 to this model
	ch.sex = "man";
	ch.location	= "Oxbay_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Everard Gordon_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Everard Gordon";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
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
	ch.work = "";
	ch.money = "10";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
	
	ch.old.name = "Raulf";
	ch.old.lastname = "Mather";
	ch.name 	= TranslateString("", "Raulf");
	ch.lastname 	= TranslateString("", "Mather");
	ch.id		= "Raulf Mather";
	ch.model	= "bocman";
	ch.sound_type = "seaman";
	ch.sex = "man";
	ch.location	= "Oxbay_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Oxbay Citizen";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Triston";
	ch.old.lastname = "Bonger";
	ch.name 	= TranslateString("", "Triston");
	ch.lastname 	= TranslateString("", "Bonger");
	ch.id		= "Triston Bonger";
	ch.model	= "man6_1";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.location	= "Oxbay_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Oxbay Citizen";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Peter";
	ch.old.lastname = "Blaxter";
	ch.name 	= TranslateString("", "Peter");
	ch.lastname 	= TranslateString("", "Blaxter");
	ch.id		= "Peter Blaxter";
	ch.model	= "man3";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.location	= "Oxbay_tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Oxbay Citizen";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Mary";
	ch.old.lastname = "Bekker";
	ch.name 	= TranslateString("", "Mary");
	ch.lastname = TranslateString("", "Bekker");
	ch.id		= "Oxbay_officiant";
	ch.model	= "towngirl7"; // Estharos Change from towngirl5 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Oxbay_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Oxbay_Tavern_upstairs";
	ch.resurrection.shore = "Oxbay_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//=============================| Philipsburg Town |=============================//

//	Tavern Keeper	
	ch.old.name = "Marcus";
	ch.old.lastname = "Maas";
	ch.name = TranslateString("", "Marcus");
	ch.lastname = TranslateString("", "Maas");
	ch.id		= "Marcus Maas";
	ch.model	= "Pirat13"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Philipsburg_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Marcus Maas_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.nation = HOLLAND;
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
	ch.money = "2";
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Friedrich Corleis";
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Cornelisje";
	ch.old.lastname = "Vandecken";
	ch.name = TranslateString("", "Cornelisje");
	ch.lastname = TranslateString("", "Vandecken");
	ch.id		= "Philipsburg_officiant";
	ch.model	= "towngirl3"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Philipsburg_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Philipsburg_Tavern_upstairs";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = HOLLAND;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOWESEN_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//==============================| Pirate Fort Town |============================//

//	Tavern Keeper	
	ch.old.name = "Mario";
	ch.old.lastname = "Figuiera";
	ch.name = TranslateString("", "Mario");
	ch.lastname = TranslateString("", "Figuiera");
	ch.id		= "Mario Figuiera";
	ch.model	= "Pirat9"; // Estharos Change from man4 to this model
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Pirate_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Mario Figuiera_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Mario Figuiera";
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
	ch.money = "0";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_PIRATE_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Elkzander";
	ch.old.lastname = "Dumarteene";
	ch.name = TranslateString("", "Elkzander");
	ch.lastname = TranslateString("", "Dumarteene");
	ch.id		= "Elkzander Dumarteene";
	ch.model	= "man4";
	ch.sex = "man";
	ch.sound_type = "seaman";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Pirate_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_douwesen pirate";
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
	ch.money = "0";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_group_MoveCharacter(ch, "DOUWESEN_PIRATE_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Leandro";
	ch.old.lastname = "Sousa";
	ch.name = TranslateString("", "Leandro");
	ch.lastname = TranslateString("", "Sousa");
	ch.id		= "Leandro Sousa";
	ch.model	= "man4";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Pirate_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit4";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_douwesen pirate";
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
	ch.money = "0";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_group_MoveCharacter(ch, "DOUWESEN_PIRATE_CITIZENS");
	AddGameCharacter(n, ch);
	
// KK --> Officiant
	ch.old.name = "Rosalie";
	ch.old.lastname = "Bezace";
	ch.name = TranslateString("", "Rosalie");
	ch.lastname = TranslateString("", "Bezace");
	ch.id		= "Pirate_officiant";
	ch.model	= "Indian_girl1"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Pirate_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto7";
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_PIRATE_CITIZENS");
	AddGameCharacter(n, ch);
	
	//============================| Point a Pitre Town |============================//

//	Tavern Keeper	
	ch.old.name = "Albin";
	ch.old.lastname = "Bonaventure";
	ch.name 	= TranslateString("", "Albin");
	ch.lastname = TranslateString("", "Bonaventure");
	ch.id		= "Albin Bonaventure";
	ch.model	= "Sailor"; // Estharos Change from Fatman2_1 to this model
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Albin Bonaventure_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Albin Bonaventure";
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
	ch.money = "1";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);

/* TALISMAN - removed drunk soldiers since no character models for them & they do not appear in tavern anyway & won't work with Period soldier models
	ch.name 	= "";
	ch.lastname = TranslateString("","");
	ch.id		= "Soldier_drunk1";
	ch.model = 3; // PB
	// PB ch.headmodel = "h_Soldier_Fra3";
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit9";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "VOICE\"+LanguageGetLanguage()+"\Fre_m_a_029.wav";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 12.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	AddGameCharacter(n, ch);

	ch.name 	= "";
	ch.lastname = TranslateString("","");
	ch.id		= "Soldier_drunk2";
	ch.model = 4; // PB
	// PB ch.headmodel = "h_Soldier_Fra4";
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit10";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "VOICE\"+LanguageGetLanguage()+"\Fre_m_a_073.wav";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 12.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	AddGameCharacter(n, ch);

	ch.name 	= "";
	ch.lastname = TranslateString("","");
	ch.id		= "Soldier_drunk3";
	ch.model = 5; // PB
	// PB ch.headmodel = "h_Soldier_Fra5";
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit8";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "VOICE\"+LanguageGetLanguage()+"\Fre_m_a_038.wav";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 12.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	AddGameCharacter(n, ch);

	ch.name 	= "";
	ch.lastname = TranslateString("","");
	ch.id		= "Soldier_drunk4";
	ch.model = 6; // PB
	// PB ch.headmodel = "h_Soldier_Fra6";
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Thug_dialog.c";
	ch.greeting = "VOICE\"+LanguageGetLanguage()+"\Fre_m_a_074.wav";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 12.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_SOLDIERS");
	AddGameCharacter(n, ch);
	
//<-- TALISMAN soldiers removed here
*/

	ch.name 	= TranslateString("", "Sailor");
	ch.lastname = "";
	ch.id		= "Drunk1";
	ch.model	= "Pirat3";
	ch.headmodel = "h_Pirat3";
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit11";
	ch.Dialog.Filename = "Drunk_dialog.c";
	ch.greeting = "VOICE\"+LanguageGetLanguage()+"\Por_m_a_032.wav";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 12.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);

	ch.name 	= TranslateString("", "Sailor");
	ch.lastname = "";
	ch.id		= "Drunk2";
	ch.model	= "Pirat4";
	ch.headmodel = "h_Pirat4";
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit5";
	ch.Dialog.Filename = "Drunk_dialog.c";
	ch.greeting = "VOICE\"+LanguageGetLanguage()+"\Por_m_b_062.wav";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 12.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);

	ch.name 	= TranslateString("", "Sailor");
	ch.lastname = "";
	ch.id		= "Drunk2";
	ch.model	= "Pirtt7";
	ch.headmodel = "h_Pirtt7";
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Drunk_dialog.c";
	ch.greeting = "VOICE\"+LanguageGetLanguage()+"\Spa_m_a_028.wav";
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
	ch.money = "1";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);
	
// Gambler
	ch.name 	= TranslateString("", "Louis");
	ch.lastname = TranslateString("", "Guillaut");
	ch.id		= "Louis Guillaut";
	ch.model	= "Hugnt18";
	ch.headmodel = "h_Hugnt18";
	ch.sound_type = "seaman";
	ch.sex = "man";
	GiveItem2Character(ch, "blade27");
	ch.equip.blade = "blade27";
	GiveItem2Character(ch, "pistol3");
	ch.equip.gun = "pistol3";
	ch.location	= "Pointe_a_pitre_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit6";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 60;
	ch.reputation = "none";
	ch.experience = "300000";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "9";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "4";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "7";
	ch.money = "1000";
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_thierry bosquet";
	AddGameCharacter(n, ch);
	
// KK --> Officiant
	ch.old.name = "Brigitte";
	ch.old.lastname = "Yberville";
	ch.name = TranslateString("", "Brigitte");
	ch.lastname = TranslateString("", "Yberville");
	ch.id		= "Pointe_a_pitre_officiant";
	ch.model	= "towngirl2_1"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Pointe_a_Pitre_tavern";
	ch.location.group = "waitress";
	ch.location.locator = "barmen";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Pointe_a_pitre_tavern_upstairs";
	ch.resurrection.shore = "Guadeloupe_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//============================| Port o Prince Town |============================//

//	Tavern Keeper	
	ch.old.name = "Francois";
	ch.old.lastname = "Chabert";
	ch.name 	= TranslateString("", "Francois");
	ch.lastname 	= TranslateString("", "Chabert");
	ch.id		= "Francois Chabert";
	ch.model = "Sailor14"; // Estharos Change from Man1 to this model
	ch.headmodel = "h_Sailor14"; // Estharos Change from h_Man1 to this model
	ch.sex = "man";
	ch.location	= "PoPrince_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Francois Chabert_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Francois Chabert";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "70";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS"); // KK
	AddGameCharacter(n, ch);

	ch.old.name = "Marcel";
	ch.old.lastname = "Fasquel";
	ch.name 	= TranslateString("", "Marcel");
	ch.lastname = TranslateString("", "Fasquel");
	ch.id		= "Marcel Fasquel";
	ch.model	= "Sailor6";
	ch.headmodel = "h_Sailor6";
	ch.sound_type = "seaman";
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	GiveItem2Character(ch, "pistol3");
	ch.equip.gun = "pistol3";
	ch.location	= "PoPrince_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit8";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 10;
	ch.reputation = "none";
	ch.experience = "3000";
	ch.skill.Leadership = "8";
	ch.skill.Fencing = "4";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "5";
	ch.skill.Grappling = "3";
	ch.skill.Repair = "4";
	ch.skill.Defence = "2";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "7";
	ch.money = "1000";
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_frcrew member";
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Eliza";
	ch.old.lastname = "Girard";
	ch.name = TranslateString("", "Eliza");
	ch.lastname = TranslateString("", "Girard");
	ch.id		= "PoPrince_officiant";
	ch.model	= "towngirl5"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "PoPrince_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "PoPrince_Tavern_upstairs";
	ch.resurrection.shore = "Hispaniola_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	AddGameCharacter(n, ch);

	//=========================| Quebradas Costillas Town |=========================//

//	Tavern Keeper	
	ch.old.name = "Ines";
	ch.old.lastname = "Diaz";
	ch.name = TranslateString("","Ines");
	ch.lastname = TranslateString("","Diaz");
	ch.id		= "Ines Diaz";
	ch.model	= "Oldwoman"; // Estharos no change
	ch.sex = "woman";
	ch.location	= "QC_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Ines Diaz_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Ines Diaz";
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
	ch.quest.about = "0";
	ch.quest.rheims = "0";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "William";
	ch.old.lastname = "Blaker";
	ch.name = TranslateString("", "William");
	ch.lastname = TranslateString("", "Blaker");
	ch.id		= "William Blaker";
	ch.model	= "chameleon";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "William Blaker_dialog.c";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Marc";
	ch.old.lastname = "Fremont";
	ch.name = TranslateString("", "Marc");
	ch.lastname = TranslateString("", "Fremont");
	ch.id		= "Marc Fremont";
	ch.model	= "man5";
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit7";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_QC Citizen";
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Tientje";
	ch.old.lastname = "Durfee";
	ch.name = TranslateString("", "Tientje");
	ch.lastname = TranslateString("", "Durfee");
	ch.id		= "QC_officiant";
	ch.model	= "Indian_girl1"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "QC_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "QC_Tavern_upstairs";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//===============================| Redmond Town |===============================//

//	Tavern Keeper	
	ch.old.name = "Morys";
	ch.old.lastname = "Biddulph";
	ch.name = TranslateString("", "Morys");
	ch.lastname = TranslateString("", "Biddulph");
	ch.id		= "Morys Biddulph";
	ch.model	= "Capitan1"; // Grey Roger / Bathtub Pirate change back from "9S_Nav"; // Estharos Change from capitan1 to this model
	ch.sound_type = "seaman";
	ch.sex = "man";
	ch.nation = ENGLAND;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Redmond_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Redmond Citizen";
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 5.0, 21.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Roger";
	ch.old.lastname = "Hayes";
	ch.name = TranslateString("", "Roger");
	ch.lastname = TranslateString("", "Hayes");
	ch.id		= "Roger Hayes";
	ch.model	= "bocman3";
	ch.sound_type = "seaman";
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "Redmond_Tavern";
	ch.location.group = "Sit";
	ch.location.locator = "Sit3";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Redmond Citizen";
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
	ch.quest.last_theme = "";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 5.0, 21.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Flann";
	ch.old.lastname = "Marrow";
	ch.name = TranslateString("", "Flann");
	ch.lastname = TranslateString("", "Marrow");
	ch.id		= "Flann Marrow";
	ch.model	= "man1_1";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "Redmond_Tavern";
	ch.location.group = "Sit";
	ch.location.locator = "Sit3";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Redmond Citizen";
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 21.1, 4.9);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Evan";
	ch.old.lastname = "Newson";
	ch.name = TranslateString("", "Evan");
	ch.lastname = TranslateString("", "Newson");
	ch.id		= "Evan Newson";
	ch.model	= "man2";
	ch.sound_type = "male_citizen";
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "Redmond_Tavern";
	ch.location.group = "Sit";
	ch.location.locator = "Sit1";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_Redmond Citizen";
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
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 21.1, 4.8);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Charles";
	ch.old.lastname = "Windem";
	ch.name = TranslateString("", "Charles");
	ch.lastname = TranslateString("", "Windem");
	ch.id		= "Charles Windem";
	ch.model	= "old_man1";
	ch.sex = "man";
	ch.location	= "Redmond_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Charles Windem_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Charles Windem";
	ch.nation = ENGLAND; // TIH was missing Nov7'06
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
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant	
	ch.old.name = "Simona";
	ch.old.lastname = "Tolman";
	ch.name = TranslateString("", "Simona");
	ch.lastname = TranslateString("", "Tolman");
	ch.id		= "Redmond_officiant";
	ch.model	= "Downgirl1"; // Estharos Change from towngirl2 to this model
	ch.sound_type = "female_citizen";
	ch.sex = "woman";
	ch.location	= "Redmond_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Redmond_Tavern_upstairs";
	ch.resurrection.shore = "Redmond_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK

// --> JRH Quest Officiant				//fake Claire as exchanged officiant Redmond
	ch.old.name = "Claire";
	ch.old.lastname = "Voyant";
	ch.name = TranslateString("", "Claire");
	ch.lastname = TranslateString("", "Voyant");
	ch.id		= "Redmond_officiant_jrh";
	ch.model	= "OldwomanPriest"; 
	ch.sound_type = "female_citizen";
	ch.sex = "man";
	//ch.location	= "Redmond_tavern";
	//ch.location.group = "goto";
	//ch.location.locator = "goto3";
// KK -->
	//ch.tavern.location = ch.location;
	//ch.tavern.location.group = ch.location.group;
	//ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "wr_claire";
	ch.resurrection.shore = "Redmond_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
// <-- JRH

	//===============================| Santiago Town |==============================//

//	Tavern Keeper
	ch.old.name = "Pedro";
	ch.old.lastname = "Fructoso";
	ch.name = TranslateString("", "Pedro");
	ch.lastname = TranslateString("", "Fructoso");
	ch.id		= "Pedro Fructoso";
	ch.model	= "Black_Corsair"; // Estharos Change from man5 to this model
	ch.sex = "man";
	ch.location	= "Santiago_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Pedro Fructoso_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.nation = SPAIN;
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
	ch.money = "2";
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_claudio burrieza";
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Juana";
	ch.old.lastname = "Martinez";
	ch.name = TranslateString("", "Juana");
	ch.lastname = TranslateString("", "Martinez");
	ch.id		= "Santiago_officiant";
	ch.model	= "OldWoman2"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Santiago_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Santiago_Tavern_upstairs";
	ch.resurrection.shore = "Cuba_shore_02";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = SPAIN;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//============================| Santo Domingo Town |============================//

//	Tavern Keeper
	ch.old.name = "Rodrigo";
	ch.old.lastname = "Ramos";
	ch.name 	= TranslateString("", "Rodrigo");
	ch.lastname 	= TranslateString("", "Ramos");
	ch.id		= "Rodrigo Ramos";
	ch.model	= "Napitan"; // Estharos no change
	ch.headmodel = "h_Napitan";
	ch.sex = "man";
	ch.location	= "Santo_Domingo_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Rodrigo Ramos_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Rodrigo Ramos";
	ch.nation = SPAIN;
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
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant	
	ch.old.name = "Maria";
	ch.old.lastname = "Delgado";
	ch.name = TranslateString("", "Maria");
	ch.lastname = TranslateString("", "Delgado");
	ch.id		= "Santo_Domingo_officiant";
	ch.model	= "Downgir52"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Santo_Domingo_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Santo_Domingo_Tavern_upstairs";
	ch.resurrection.shore = "Hispaniola_shore_04";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = SPAIN;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//==============================| Smugglers Town |==============================//

//	Tavern Keeper	
	ch.old.name = "Fabiao";
	ch.old.lastname = "Dunga";
	ch.name = TranslateString("", "Fabiao");
	ch.lastname = TranslateString("", "Dunga");
	ch.id		= "Fabiao Dunga";
	ch.model	= "bugmanpirat14"; // Estharos Change from fatman2 to this model
	ch.sex = "man";
	ch.location	= "Smugglers_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Fabiao Dunga_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Fabiao Dunga";
	ch.nation = PORTUGAL;
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
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SMUGGLERS_CITIZENS");
	AddGameCharacter(n, ch);
	
	ch.old.name = "Christiano";
	ch.old.lastname = "Bessa";
	ch.name = TranslateString("", "Christiano");
	ch.lastname = TranslateString("", "Bessa");
	ch.id		= "Christiano Bessa";
	ch.model	= "Corsair3";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "Smugglers_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit5";
	ch.Dialog.Filename = "habitue_dialog.c";
	ch.greeting = "Gr_QC Citizen";
	ch.nation = PORTUGAL;
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
	LAi_group_MoveCharacter(ch, "SMUGGLERS_CITIZENS");
	AddGameCharacter(n, ch);
	
	ch.old.name = "Adao";
	ch.old.lastname = "Henriques";
	ch.name = TranslateString("", "Adao");
	ch.lastname = TranslateString("", "Henriques");
	ch.id		= "Adao Henriques";
	ch.model	= "korsar";
	ch.sex = "man";
	ch.sound_type = "male_citizen";
	ch.location	= "Smugglers_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit4";
	ch.Dialog.Filename = "habitue_dialog.c";
	ch.greeting = "Gr_QC Citizen";
	ch.nation = PORTUGAL;
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
	LAi_SetLoginTime(ch, 22.0, 5.98333);
	LAi_group_MoveCharacter(ch, "SMUGGLERS_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant		
	ch.old.name = "Sofia";
	ch.old.lastname = "Guterres";
	ch.name = TranslateString("", "Sofia");
	ch.lastname = TranslateString("", "Guterres");
	ch.id		= "Smugglers_officiant";
	ch.model	= "mowngirl5"; // Estharos no change
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Smugglers_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto6";
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Smugglers_tavern_upstairs";
	ch.resurrection.shore = "Conceicao_shore_02";
	ch.Dialog.Filename = "eng_officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = PORTUGAL;
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
	ch.quest.sex = "0";
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SMUGGLERS_CITIZENS");
	AddGameCharacter(n, ch);
	
	//===============================| Tortuga Town |===============================//

//	Tavern Keeper	
	ch.old.name = "John";
	ch.old.lastname = "Adams";
	ch.name 	= TranslateString("", "John");
	ch.lastname = TranslateString("", "Adams");
	ch.id		= "John Adams";
	ch.model	= "Corsair3"; // Estharos no Change
	ch.sex = "man";
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.location	= "Tortuga_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "John Adams_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Charles Windem";
	ch.nation = FRANCE;
	ch.rank 	= 62;
	ch.reputation = "None";
	ch.experience = "150000";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "5";
	ch.skill.Accuracy = "7";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "8";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "7";
	ch.money = "1";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "TORTUGA_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Manuel";
	ch.old.lastname = "Salazar";
	ch.name 	= TranslateString("", "Manuel");
	ch.lastname = TranslateString("", "Salazar");
	ch.id		= "Manuel Salazar";
	ch.model	= "Shkiper";
	ch.headmodel = "h_Shkiper";
	ch.sound_type = "seaman";
	ch.sex = "man";
	GiveItem2Character(ch, "blade27");
	ch.equip.blade = "blade27";
	GiveItem2Character(ch, "pistol3");
	ch.equip.gun = "pistol3";
	ch.location	= "Tortuga_Tavern";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Habitue_dialog.c";
	ch.greeting = "Gr_QC Citizen";
	ch.nation = FRANCE;
	ch.rank 	= 60;
	ch.reputation = "none";
	ch.experience = "300000";
	ch.skill.Leadership = "10";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "10";
	ch.skill.Cannons = "9";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "4";
	ch.skill.Defence = "9";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "7";
	ch.money = "100";
	LAi_SetSitType(ch);
	LAi_group_MoveCharacter(ch, "TORTUGA_CITIZENS");
	AddGameCharacter(n, ch);

	ch.old.name = "Mary";
	ch.old.lastname = "Wood";
	ch.name 	= TranslateString("", "Mary");
	ch.lastname = TranslateString("", "Wood");
	ch.id		= "Mary Wood";
	ch.model	= "Ladyinred";
	ch.headmodel = "h_Ladyinred";
	ch.model.animation = "man_woman_sit";
	ch.sex = "woman";
	GiveItem2Character(ch, "blade24");
	ch.equip.blade = "blade24";
	GiveItem2Character(ch, "pistol5");
	ch.equip.gun = "pistol5";
	ch.location	= "Tortuga_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto2";
	ch.Dialog.Filename = "Mary Wood_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 331;//MAXIMUS: real rank for her HP
	ch.reputation = "30";
	ch.experience = "20000"		//chr.experience;
	ch.skill.Leadership = "7";
	ch.skill.Fencing = "10";
	ch.skill.Sailing = "7";
	ch.skill.Accuracy = "8";
	ch.skill.Cannons = "9";
	ch.skill.Grappling = "5";
	ch.skill.Repair = "4";
	ch.skill.Defence = "10";
	ch.skill.Commerce = "2";
	ch.skill.Sneak = "8";
	ch.money = "500";
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
	ch.Ship.Name = "Morning Star";
	ch.Ship.Type = "Brigantina1";
	ch.Ship.Cannons.Type = CANNON_TYPE_CULVERINE_LBS24;
	ch.ship.cargo.goods.BALLS = 1000;
	ch.ship.cargo.goods.GRAPES = 500;
	ch.ship.cargo.goods.KNIPPELS = 500;
	ch.Ship.Stopped = true;
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetHP(ch, 1500.0, 1500.0);
	LAi_NoRebirthEnable(ch);
	ch.greeting = "Gr_Ines Diaz";
	LAi_group_MoveCharacter(ch, "TORTUGA_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Esther";
	ch.old.lastname = "Littlewood";
	ch.name = TranslateString("", "Esther");
	ch.lastname = TranslateString("", "Littlewood");
	ch.id		= "Tortuga_officiant";
	ch.model	= "Indian_girl1"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Tortuga_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Tortuga_Tavern_upstairs";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "TORTUGA_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK
	
	//================================| Turks Town |================================//

//	Tavern Keeper	
	ch.old.name = "Josephine";
	ch.old.lastname = "Bonassieu";
	ch.name 	= TranslateString("", "Josephine");
	ch.lastname = TranslateString("", "Bonassieu");
	ch.id		= "Josephine Bonassieu";
	ch.model	= "girlpatch"; // Estharos no change
	ch.sex = "woman";
	ch.location	= "Turks_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Josephine Bonassieu_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Ines Diaz";
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
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Cathrine";
	ch.old.lastname = "Scarlett";
	ch.name = TranslateString("", "Cathrine");
	ch.lastname = TranslateString("", "Scarlett");
	ch.id		= "Turks_officiant";
	ch.model	= "Indian_girl1"; // Estharos Change from towngirl2 to this model
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Turks_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Turks_tavern_upstairs";
	ch.resurrection.shore = "Turks_shore_05";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK

	//================================| Village Curacao |================================//

//	Tavern Keeper	
	ch.old.name = "Bella";
	ch.old.lastname = "Froelich";
	ch.name 	= TranslateString("", "Bella");
	ch.lastname = TranslateString("", "Froelich");
	ch.id		= "Bella Froelich";
	ch.model	= "downgir53";
	ch.sex = "woman";
	ch.location	= "Village_Tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto3";
	ch.Dialog.Filename = "Bella Froelich_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.greeting = "Gr_Ines Diaz";
	ch.nation = HOLLAND;
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
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Jantina";
	ch.old.lastname = "Dedrick";
	ch.name = TranslateString("", "Jantina");
	ch.lastname = TranslateString("", "Dedrick");
	ch.id		= "Village_officiant";
	ch.model	= "towngirl2_1";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Village_Tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = HOLLAND;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK

	//==============================| Willemstad Town |=============================//

//	Tavern Keeper	
	ch.old.name = "Pierart";
	ch.old.lastname = "Kamerling";
	ch.name = TranslateString("", "Pierart");
	ch.lastname = TranslateString("", "Kamerling");
	ch.id		= "Pierart Kamerling";
	ch.model	= "Corsair5"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Willemstad_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Pierart Kamerling_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.nation = HOLLAND;
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
	ch.money = "2";
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Friedrich Corleis";
	AddGameCharacter(n, ch);
	
// KK --> Officiant	
	ch.old.name = "Brechtje";
	ch.old.lastname = "Palings";
	ch.name = TranslateString("", "Brechtje");
	ch.lastname = TranslateString("", "Palings");
	ch.id		= "Willemstad_officiant";
	ch.model	= "towngirl6";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Willemstad_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto3";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Willemstad_tavern_upstairs";
	ch.resurrection.shore = "Curacao_shore_01";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_f_officer";
	ch.nation = HOLLAND;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	AddGameCharacter(n, ch);
	
	//==============================| Cartagena Town |==============================//

//	Tavern Keeper 1	
	ch.old.name = "Valerio";
	ch.old.lastname = "Xalmiento";
	ch.name = TranslateString("", "Valerio");
	ch.lastname = TranslateString("", "Xalmiento");
	ch.id		= "Valerio Xalmiento";
	ch.model	= "fatman";
	ch.sex = "man";
	ch.location	= "Cartagena_tavern";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Fadrique Castillo_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.nation = SPAIN;
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
	ch.money = "2";
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_claudio burrieza";
	AddGameCharacter(n, ch);

// KK --> Officiant
	ch.old.name = "Inocencia";
	ch.old.lastname = "Ussica";
	ch.name = TranslateString("", "Inocencia");
	ch.lastname = TranslateString("", "Ussica");
	ch.id		= "Cartagena_officiant";
	ch.model	= "mowngirl7";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Cartagena_tavern";
	ch.location.group = "goto";
	ch.location.locator = "goto5";
// KK -->
	ch.tavern.location = ch.location;
	ch.tavern.location.group = ch.location.group;
	ch.tavern.location.locator = ch.location.locator;
	ch.resurrection.location = "Cartagena_Tavern_upstairs";
	ch.resurrection.shore = "Cartagena_port";
// <-- KK
	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = SPAIN;
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
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);
// <-- KK

//	Tavern Keeper 2	
	ch.old.name = "Salvadore";
	ch.old.lastname = "Xalmiento";
	ch.name = TranslateString("", "Salvadore");
	ch.lastname = TranslateString("", "Xalmiento");
	ch.id		= "Salvadore Xalmiento";
	ch.model	= "fatman2";
	ch.sex = "man";
	ch.location	= "Cartagena_tavern2";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Salvadore Xalmiento_dialog.c";
	ch.Dialog.Filename.GroupDialog = "tavern.c";
	ch.nation = SPAIN;
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
	ch.money = "2";
	ch.work = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_claudio burrieza";
	AddGameCharacter(n, ch);

// GR --> Officiant 2
	ch.old.name = "Jimena";
	ch.old.lastname = "López";
	ch.name = TranslateString("", "Jimena");
	ch.lastname = TranslateString("", "López");
	ch.id		= "Cartagena_officiant2";
	ch.model	= "Jimena";	// Special model for officiant in special tavern - GR
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "Cartagena_tavern2";
	ch.location.group = "goto";
	ch.location.locator = "goto3";

	ch.Dialog.Filename = "Eng_Officiant_dialog.c";
	ch.greeting = "Gr_eng_officiant";
	ch.nation = SPAIN;
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "3";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "2";
	ch.skill.Defence = "3";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "3";
	ch.perks.list.BasicDefence = true;
	ch.perks.list.ImprovePotions = true;
	ch.perks.list.BasicFirstAid = true;
	ch.perks.list.Cooking = true;
	ch.perks.list.BasicCommerce = true;
	ch.money = "1";
	ch.quest.sex = 0;
	ch.sex.time = 0;
	LAi_SetWaitressType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	ch.questchar = true;
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);
}
