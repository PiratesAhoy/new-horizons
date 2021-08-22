/* Estharos Modification March, 2009
- Quebradas Costillas Store Owner Sex Change
- Tortuga Store Owner Sex Change
- All StoreOwner models as been reassign
- Organise the characters per town in alphabetic order from Antigua to Willemstad for easier search
*/


void CreateStoreOwnersCharacters(ref n)
{
	object chobj;
	ref ch;

	makeref(ch, chobj);

	//===============================| Antigua Town |===============================//
	
	ch.old.name = "Agent-Victualler";
	ch.old.lastname = "";
	ch.name 	= TranslateString("","Agent-Victualler");
	ch.lastname 	= "";
	ch.id		= "Antigua_Victualler";
	ch.model	= "BrtOffic18"; // "rn_comdr18_1";
	ch.sex = "man";
	ch.location	= "Antigua_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Antigua_Victualler.c";
	ch.rank 	= 1;
	ch.nation = ENGLAND;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "8";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1000";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	//LAi_group_MoveCharacter(ch, "LAI_DEFAULT_GROUP"); Estharos Remove because it was causing the character to get stuck on the wall
	LAi_SetMerchantType(ch); // Estharos to cancel movement
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 200.0, 200.0);
	AddGameCharacter(n, ch);

	//===========================| Buccaneers Camp Town |===========================//

	ch.old.name = "Eugene";
	ch.old.lastname = "Martin";
	ch.name = TranslateString("","Eugene");
	ch.lastname = TranslateString("","Martin");
	ch.id		= "Eugene Martin";
	ch.model = "Eugene_Martin"; // Thomas the Terror
	ch.sex = "man";
	ch.location	= "BC_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Eugene Martin_dialog.c";
	ch.nation = PIRATE;
	ch.rank 	= 8;
	ch.reputation = "43";
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
	ch.money.quest = "0";
	ch.quest.meeting = "0";
	ch.quest_begin = "0";
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.greeting = "Gr_Francois Moulin";
	AddGameCharacter(n, ch);

	//=============================| Charlestown Town |=============================//

	ch.old.name = "James";
	ch.old.lastname = "Griffith";
	ch.name = TranslateString("","James");
	ch.lastname = TranslateString("","Griffith");
	ch.id		= "James Griffith";
	ch.model	= "korsar";
	ch.sex = "man";
	ch.location	= "Charlestown_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "James Griffith_dialog.c";
	ch.greeting = "Gr_Redmond Citizen";
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	//==============================| Conceicao Town |==============================//

	ch.old.name = "Martinho";
	ch.old.lastname = "Guterres";
	ch.name = TranslateString("","Martinho");
	ch.lastname = TranslateString("","Guterres");
	ch.id		= "Martinho Guterres";
	ch.model	= "huber_por"; // Estharos Change from storeman to this model
	ch.sex = "man";
	ch.location	= "Conceicao_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Martinho Guterres_dialog.c";
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
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "CONCEICAO_CITIZENS");
	ch.greeting = "Gr_Martinho Guterres";
	AddGameCharacter(n, ch);

	//===============================| Douwesen Town |==============================//

	ch.old.name = "Gheerlof";
	ch.old.lastname = "Darlang";
	ch.name = TranslateString("","Gheerlof");
	ch.lastname = TranslateString("","Darlang");
	ch.id		= "Gheerlof Darlang";
	ch.model	= "man3"; // Estharos Change from Storeman2 to this model
	ch.sex = "man";
	ch.location	= "Douwesen_Store";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Gheerlof Darlang_dialog.c";
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
	ch.money = "20";
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Gheerlof Darlang";
	AddGameCharacter(n, ch);

	//==========================| Pirate Fort |===========================//

	ch.old.name = "Cornelius";
	ch.old.lastname = "Vanslyperken";
	ch.name = TranslateString("","Cornelius");
	ch.lastname = TranslateString("","Vanslyperken");
	ch.id		= "Cornelius Vanslyperken";
	ch.model	= "Pirat2";
	ch.sex = "man";
	ch.location	= "Pirate_Store";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Leonardo Violate_dialog.c";
	ch.greeting = "Gr_QC Citizen";
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_PIRATE");
	AddGameCharacter(n, ch);

	//==========================| Falaise De Fleur Town |===========================//

	ch.old.name = "Arnaud";
	ch.old.lastname = "Matton";
	ch.name = TranslateString("","Arnaud");
	ch.lastname = TranslateString("","Matton");
	ch.id		= "Arnaud Matton";
	ch.model = "Fatman2"; // Estharos Change from storeman2 to this model
	ch.sex = "man";
	ch.location	= "Falaise_de_Fleur_store";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Arnaud Matton_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "43";
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
	ch.money.quest = "0";
	ch.quest.meeting = "0";
	ch.quest_begin = "0";
	ch.quest.to_redmond_1 = "0";
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_arnaud matton";
	AddGameCharacter(n, ch);

	//=============================| Grand Cayman Town |============================//

	ch.old.name = "Laurence";
	ch.old.lastname = "Bannerman";
	ch.name 	= TranslateString("","Laurence");
	ch.lastname 	= TranslateString("","Bannerman");
	ch.id		= "Laurence Bannerman";
	ch.model = "9S_Nat"; // Estharos Change from Albermal to this model
	ch.headmodel = "h_9S_Nat"; // Estharos Change from h_Albermal to this model
	ch.sex = "man";
	ch.nation = ENGLAND;
	ch.location	= "Grand_Cayman_store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Laurence Bannerman_dialog.c";
	ch.greeting = "Gr_Laurence Bannerman";
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
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	ch.quest.meeting = "0";
	ch.quest_begin = "0";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);

	//==============================| Greenford Town |==============================//

	ch.old.name = "John";
	ch.old.lastname = "Filbert";
	ch.name 	= TranslateString("","John");
	ch.lastname = TranslateString("","Filbert");
	ch.id		= "John Filbert";
	ch.model	= "Sailor2"; // Estharos Change from Storeman to this model
	ch.sex = "man";
	ch.location	= "Greenford_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "John Filbert_dialog.c";
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
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_John Filbert";
	AddGameCharacter(n, ch);

	//=============================| Isla Muelle Town |=============================//

	ch.old.name = "Emiliano";
	ch.old.lastname = "Rionda";
	ch.name = TranslateString("","Emiliano");
	ch.lastname = TranslateString("","Rionda");
	ch.id		= "Emiliano Rionda";
	ch.model = "Fatman2_1"; // Estharos Change from Storeman to this model
	ch.sex = "man";
	ch.location	= "Muelle_store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Emiliano Rionda_dialog.c";
	ch.greeting = "Gr_Emiliano Rionda";
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
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	ch.quest.meeting = "0";
	ch.quest_begin = "0";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	AddGameCharacter(n, ch);

	//==============================| La Havana Town |==============================//

	ch.old.name = "Juan";
	ch.old.lastname = "Mendoza";
	ch.name 	= TranslateString("","Juan");
	ch.lastname = TranslateString("","Mendoza");
	ch.id		= "Juan Mendoza";
	ch.model	= "hub_spa2"; // Estharos Change from Huber_Por2 to this model
	ch.headmodel = "h_hub_spa2"; // Estharos Change from h_Huber_Por2 to this model
	ch.sex = "man";
	ch.location	= "Havana_store"; // Estharos
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Juan Mendoza_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 2;
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_Juan Mendoza";
	AddGameCharacter(n, ch);

	//===============================| Marigot Town |===============================//

	ch.old.name = "Jean";
	ch.old.lastname = "Maginot";
	ch.name 	= TranslateString("","Jean");
	ch.lastname 	= TranslateString("","Maginot");
	ch.id		= "Jean Maginot";
	ch.model	= "korsar1"; // Estharos Change from storeman1 to this model
	ch.sex = "man";
	ch.location	= "Marigot_store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Jean Maginot_dialog.c";
	ch.rank 	= 1;
	ch.nation = FRANCE;
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
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch); // PB: was LAi_SetStayType
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_arnaud matton";
	AddGameCharacter(n, ch);

	//==============================| Oranjestad Town |=============================//

	ch.old.name = "Cornelis";
	ch.old.lastname = "Huijser";
	ch.name = TranslateString("","Cornelis");
	ch.lastname = TranslateString("","Huijser");
	ch.id		= "Cornelis Huijser";
	ch.model = "Man6_1"; // Estharos Change from storeman to this model
	ch.sex = "man";
	ch.location	= "Oranjestad_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Cornelis Huijser_dialog.c";
	ch.nation = HOLLAND;
	ch.rank 	= 8;
	ch.reputation = "43";
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
	ch.money.quest = "0";
	ch.quest.meeting = "0";
	ch.quest_begin = "0";
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Gheerlof Darlang";
	AddGameCharacter(n, ch);

	//==============================| Oranjestad Port |=============================//
//JRH
	ch.old.name = "Jimmy";
	ch.old.lastname = "Carl Black";
	ch.name = TranslateString("","Jimmy");
	ch.lastname = TranslateString("","Carl Black");
	ch.id		= "indian_storekeeper";
	ch.model = "indian_trader";
	ch.sex = "man";
	ch.location	= "Oranjestad_Store_02";
	ch.location.group = "merchant";
	ch.location.locator = "merchant1";
	ch.Dialog.Filename = "Cornelis Huijser_dialog.c";
	ch.Dialog.Filename.Ayahuasca = "ayahuasca_trading.c";
	ch.nation = HOLLAND;
	ch.rank 	= 8;
	ch.reputation = "43";
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
	ch.money.quest = "0";
	ch.quest.meeting = "0";
	ch.quest_begin = "0";
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Gheerlof Darlang";
	AddGameCharacter(n, ch);

	//================================| Oxbay Town |================================//

	ch.old.name = "Alan";
	ch.old.lastname = "Milds";
	ch.name 	= TranslateString("","Alan");
	ch.lastname 	= TranslateString("","Milds");
	ch.id		= "Alan Milds";
	ch.model	= "Sailor13"; // Estharos Change from storeman2 to this model
	ch.sex = "man";
	ch.location	= "Oxbay_store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Alan Milds_dialog.c";
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
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Alan Milds";
	AddGameCharacter(n, ch);

	//=============================| Philipsburg Town |=============================//

	ch.old.name = "Pieter";
	ch.old.lastname = "Van Vecker";
	ch.name = TranslateString("","Pieter");
	ch.lastname = TranslateString("","Van Vecker");
	ch.id		= "Pieter Van Vecker";
	ch.model	= "man2"; // Estharos Change from man4 to this model
	ch.sex = "man";
	ch.location	= "Philipsburg_store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Pieter Van Vecker_dialog.c";
	ch.nation = HOLLAND; // TIH was missing - causes trade quests to fail? Nov7'05
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
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.money.quest = "0";
	ch.quest.first_job = "0";
	ch.quest.contraband = "0";
	ch.quest_begin = "0";
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Gheerlof Darlang";
	AddGameCharacter(n, ch);

	//============================| Point a Pitre Town |============================//

	ch.old.name = "Dieudonne";
	ch.old.lastname = "Toussaint";
	ch.name 	= TranslateString("","Dieudonne");
	ch.lastname 	= TranslateString("","Toussaint");
	ch.id		= "Dieudonne Toussaint";
	ch.model = "50M5";
	ch.headmodel = "h_50M5";
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_store";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Dieudonne Toussaint_dialog.c";
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "43";
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
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_arnaud matton";
	AddGameCharacter(n, ch);

	//============================| Port o Prince Town |============================//

	ch.old.name = "Violette";
	ch.old.lastname = "De Colville";
	ch.name 	= TranslateString("","Violette");
	ch.lastname = TranslateString("","De Colville");
	ch.id		= "Violette De Colville";
	ch.model	= "Towngirl4";
	ch.headmodel = "h_Towngirl4";
	ch.sex = "woman";
	ch.sound_type = "female_citizen";
	ch.location	= "PoPrince_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Violette De Colville_dialog.c";
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_Sabine Matton";
	AddGameCharacter(n, ch);

	//=========================| Quebradas Costillas Town |=========================//

	// <-- Estharos Sex Change	
	ch.old.name = "Kate";
	ch.old.lastname = "Blowhorn";
	ch.name = TranslateString("","Kate");
	ch.lastname = TranslateString("","Blowhorn");
	ch.id		= "Kate Blowhorn";
	ch.model	= "33_Blazie";
	ch.model.animation = "33_Blazie"; // PB
	ch.sex = "woman";
	ch.location	= "QC_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Kate Blowhorn_dialog.c";
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.greeting = "Gr_Desiree' Muerte";
	AddGameCharacter(n, ch);
	// <-- Estharos Sex Change

	//===============================| Redmond Town |===============================//
	
	ch.old.name = "Thomas";
	ch.old.lastname = "O'Reily";
	ch.name = TranslateString("","Thomas");
	ch.lastname = TranslateString("","O'Reily");
	ch.id		= "Thomas O'Reily";
	ch.model	= "9S_Nav"; // Grey Roger / Bathtub Pirate, change from "9R_Purs"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Redmond_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Thomas O'Reily_dialog.c";
	ch.nation = ENGLAND; // TIH was missing - causes trade quest to fail? Nov7'06
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
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.money.quest = "0";
	ch.quest.first_job = "0";
	ch.quest.contraband = "0";
	ch.quest_begin = "0";
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Thomas O'Reily";
	AddGameCharacter(n, ch);

	//===============================| Santiago Town |==============================//

	ch.old.name = "Jose";
	ch.old.lastname = "Zugarro";
	ch.name = TranslateString("","Jose");
	ch.lastname = TranslateString("","Zugarro");
	ch.id		= "Jose Zugarro";
	ch.model	= "hub_spa3"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Santiago_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Jose Zugarro_dialog.c";
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
	ch.skill.Commerce = "4";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.money.quest = "0";
	ch.quest.first_job = "0";
	ch.quest.contraband = "0";
	ch.quest_begin = "0";
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_Emiliano Rionda";
	AddGameCharacter(n, ch);

	//============================| Santo Domingo Town |============================//

	ch.old.name = "Pedro";
	ch.old.lastname = "Ortega";
	ch.name 	= TranslateString("","Pedro");
	ch.lastname = TranslateString("","Ortega");
	ch.id		= "Pedro Ortega";
	ch.model	= "Old_man1"; // Estharos Change from BadV to this model
	ch.sex = "man";
	ch.location	= "Santo_Domingo_store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Pedro Ortega_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 2;
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_Peter Blowhorn";
	AddGameCharacter(n, ch);

	//==============================| Smugglers Town |==============================//

	ch.old.name = "Leonardo";
	ch.old.lastname = "Violate";
	ch.name = TranslateString("","Leonardo");
	ch.lastname = TranslateString("","Violate");
	ch.id		= "Leonardo Violate";
	ch.model	= "Pirat2"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Smugglers_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Leonardo Violate_dialog.c";
	ch.greeting = "Gr_QC Citizen";
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SMUGGLERS_CITIZENS");
	AddGameCharacter(n, ch);

	//===============================| Tortuga Town |===============================//

	// <-- Estharos Sex Change
	ch.old.name = "Jasmine"; 
	ch.old.lastname = "Cotton";
	ch.name 	= TranslateString("","Jasmine"); 
	ch.lastname = TranslateString("","Cotton");
	ch.id		= "Jasmine Cotton"; 
	ch.model	= "33_TG5D";
	ch.sex = "woman"; 
	ch.location	= "Tortuga_Store";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Jasmine Cotton_dialog.c";
	ch.nation = FRANCE;
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
	LAi_SetMerchantType(ch); // PB
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "TORTUGA_CITIZENS");
	ch.greeting = "Gr_Desiree' Muerte";
	AddGameCharacter(n, ch);
	// <-- Estharos Sex Change

	//================================| Turks Town |================================//

	ch.old.name = "Ricardo";
	ch.old.lastname = "Sanchez";
	ch.name 	= TranslateString("","Ricardo");
	ch.lastname = TranslateString("","Sanchez");
	ch.id		= "Ricardo Sanchez";
	ch.model	= "9S_Pir"; // Estharos Change from Searcher_navy to this model
	ch.sex = "man";
	ch.location	= "Turks_Store";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Ricardo Sanchez_dialog.c";
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_CITIZENS");
	ch.greeting = "Gr_Peter Blowhorn";
	AddGameCharacter(n, ch);

	//==============================| Willemstad Town |=============================//

	ch.old.name = "Jacobus";
	ch.old.lastname = "Colijn";
	ch.name = TranslateString("","Jacobus");
	ch.lastname = TranslateString("","Colijn");
	ch.id		= "Jacobus Colijn";
	ch.model = "Man3_1"; // Estharos Change from man4 to this model
	ch.sex = "man";
	ch.location	= "Willemstad_Store";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Jacobus Colijn_dialog.c";
	ch.nation = HOLLAND;
	ch.rank 	= 8;
	ch.reputation = "43";
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
	ch.money.quest = "0";
	ch.quest.meeting = "0";
	ch.quest_begin = "0";
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetHP(ch, 80.0, 80.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Gheerlof Darlang";
	AddGameCharacter(n, ch);

//==================================| Eleuthera store |==================================//
	// Fox Ratter
	ch.old.name = "Fox";
	ch.old.lastname = "Ratter";
	ch.name 	= TranslateString("","Fox");
	ch.lastname 	= TranslateString("","Ratter");
	ch.id		= "Fox Ratter";
	ch.model	= "apothecary";
	ch.sex = "man";
	ch.location	= "Eleuthera_Store";
	ch.location.group = "barmen";
	ch.location.locator = "stay";
	ch.Dialog.Filename = "Fox Ratter_dialog.c";
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
	ch.quest.trade_date = "";
	ch.quest.item_date = "";
	LAi_SetBarmanType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Alan Milds";
	AddGameCharacter(n, ch);
// <-- KK

//==================================| Alice town_store |==================================//
	// Dawg Bennett -- Searcher_navy
	ch.old.name = "Dawg";
	ch.old.lastname = "Bennett";
	ch.name 	= TranslateString("","Dawg");
	ch.lastname = TranslateString("","Bennett");
	ch.id		= "Dawg Bennett";
	ch.model	= "Searcher_navy";
	ch.sex = "man";
	ch.location	= "Alice_store";
	ch.location.group = "merchant";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Dawg Bennett_dialog.c";
	ch.nation = ENGLAND;
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Peter Blowhorn";
	AddGameCharacter(n, ch);
	
	//==============================| Cartagena Town |==============================//

	ch.old.name = "Augustin";
	ch.old.lastname = "Frechilla";
	ch.name 	= TranslateString("","Augustin");
	ch.lastname = TranslateString("","Frechilla");
	ch.id		= "Augustin Frechilla";
	ch.model	= "hub_spa2"; 
	ch.headmodel = "h_hub_spa2"; 
	ch.sex = "man";
	ch.location	= "Cartagena_store";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Juan Mendoza_dialog.c";
	ch.nation = SPAIN;
	ch.rank 	= 2;
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
	LAi_SetMerchantType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_Juan Mendoza";
	AddGameCharacter(n, ch);	
}
