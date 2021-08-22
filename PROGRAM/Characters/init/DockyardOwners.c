/* Estharos Modification March, 2009
- Towns with no codes after there name, means no shipyard for this town
- All Shipyard Owner models as been reassign
- Organise the characters per town in alphabetic order from Antigua to Willemstad for easier search
*/

void CreateDockYardOwnersCharacters(ref n)
{
	object chobj;
	ref ch;
	makeref(ch, chobj);

	//===============================| Alice Town |===============================//

	ch.old.name = "Patrick";
	ch.old.lastname = "Webster";
	ch.name 	= TranslateString("", "Patrick");
	ch.lastname 	= TranslateString("", "Webster");
	ch.id		= "Patrick Webster";
	ch.model = "bocman8";
	ch.sex = "man";
	ch.location	= "Alice_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";//1
	ch.Dialog.Filename = "Patrick Webster_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	//ch.greeting = "Gr_esteban castillo";
	AddGameCharacter(n, ch);
	
	//===============================| Antigua Town |===============================//
	
	ch.old.name = "Dockyard";
	ch.old.lastname = "Comissioner";
	ch.name 	= TranslateString("", "Dockyard");
	ch.lastname 	= TranslateString("", "Comissioner");
	ch.id		= "Antigua_Dockyard";
	ch.model	= "brtcpt1_18"; // Thomas the Terror
	ch.sex = "man";
	ch.location	= "Antigua_yard";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Antigua_Dockyard.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
	ch.rank 	= 1;
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
	LAi_SetCitizenType(ch);
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	LAi_SetHP(ch, 200.0, 200.0);
	AddGameCharacter(n, ch);
	
	//===========================| Buccaneers Camp Town |===========================//
	//=============================| Charlestown Town |=============================//
	
	ch.old.name = "Hugh";
	ch.old.lastname = "Chadman";
	ch.name = TranslateString("", "Hugh");
	ch.lastname = TranslateString("", "Chadman");
	ch.id		= "Hugh Chadman";
	ch.model	= "sailor10"; // Estharos Change from Chelovek1 to this model
	ch.sex = "man";
	ch.location	= "Charlestown_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Hugh_Chadman_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
	ch.greeting = "Gr_David Fairweather";
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
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
	
	//==============================| Conceicao Town |==============================//
	
	ch.old.name = "Humberto";
	ch.old.lastname = "de Paiva";
	ch.name = TranslateString("", "Humberto");
	ch.lastname = TranslateString("", "de Paiva");
	ch.id		= "Humberto de Paiva";
	ch.model = "bocman10"; // Estharos Change from man6_1 to this model
	ch.sex = "man";
	ch.location	= "Conceicao_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Humberto de Paiva_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
	ch.nation = PORTUGAL;
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
	ch.skill.Commerce = "5";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 6.0, 21.98333);
	LAi_group_MoveCharacter(ch, "CONCEICAO_CITIZENS");
	ch.greeting = "Gr_Humberto de Paiva";
	AddGameCharacter(n, ch);
	
	//===============================| Douwesen Town |==============================//
	
	ch.old.name = "Lambrecht";
	ch.old.lastname = "Fobes";
	ch.name = TranslateString("", "Lambrecht");
	ch.lastname = TranslateString("", "Fobes");
	ch.id		= "Lambrecht Fobes";
	ch.model	= "33_Ronald"; // Estharos Change from Old_man1 to this model
	ch.model.animation = "33_Ronald";
	ch.sex = "man";
	ch.location	= "Douwesen_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Lambrecht Fobes_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Lambrecht Fobes";
	AddGameCharacter(n, ch);
	
	//==============================| Eleuthera Town |==============================//

	ch.old.name = "Philippe";
	ch.old.lastname = "";
	ch.name 	= TranslateString("", "Philippe");
	ch.lastname 	= "";
	ch.id		= "Philippe";
	ch.model = "33_Ronald";
	ch.model.animation = "33_Ronald";
	ch.sex = "man";
	ch.location	= "Eleuthera_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Philippe_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_esteban castillo";
	AddGameCharacter(n, ch);

	//==========================| Falaise De Fleur Town |===========================//
	
	ch.old.name = "Jean";
	ch.old.lastname = "Filaut";
	ch.name = TranslateString("", "Jean");
	ch.lastname = TranslateString("", "Filaut");
	ch.id		= "Jean Filaut";
	ch.model	= "bocman16"; // Estharos Change from man6 to this model
	ch.sex = "man";
	ch.location	= "Falaise_de_Fleur_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Jean Filaut_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "53";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "4";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_jean filaut";
	AddGameCharacter(n, ch);
	
	//=============================| Grand Cayman Town |============================//
	
	ch.old.name = "Fletcher";
	ch.old.lastname = "Rosewood";
	ch.name 	= TranslateString("", "Fletcher");
	ch.lastname 	= TranslateString("", "Rosewood");
	ch.id		= "Fletcher Rosewood";
	ch.model	= "33_Ronal2"; // Estharos Change from Bocman3 to this model
	ch.headmodel = "h_33_Ronal2"; // Estharos Change from h_Bocman3 to this model
	ch.model.animation = "33_Ronald";
	ch.sex = "man";
	ch.location	= "Grand_Cayman_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Fletcher Rosewood_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Roger Murray";
	AddGameCharacter(n, ch);
	
	//==============================| Greenford Town |==============================//
	
	ch.old.name = "David";
	ch.old.lastname = "Fairweather";
	ch.name 	= TranslateString("", "David");
	ch.lastname = TranslateString("", "Fairweather");
	ch.id		= "David Fairweather";
	ch.model	= "bocman18"; // Estharos Change from man1 to this model
	ch.sex = "man";
	ch.location	= "Greenford_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "David Fairweather_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
	ch.greeting = "Gr_David Fairweather";
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
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	AddGameCharacter(n, ch);
	
	//=============================| Isla Muelle Town |=============================//

	ch.old.name = "Esteban";
	ch.old.lastname = "Castillo";
	ch.name = TranslateString("", "Esteban");
	ch.lastname = TranslateString("", "Castillo");
	ch.id		= "Esteban Castillo";
	ch.model	= "sailor7"; // Estharos Change from old_man1 to this model
	ch.sex = "man";
	ch.location	= "Muelle_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Esteban Castillo_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	ch.quest.escort = "0";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_esteban castillo";
	AddGameCharacter(n, ch);

	//==============================| La Havana Town |==============================//

	ch.old.name = "Jorge";
	ch.old.lastname = "Suarez";
	ch.name = TranslateString("", "Jorge");
	ch.lastname = TranslateString("", "Suarez");
	ch.id		= "Jorge Suarez";
	ch.model	= "capstan3"; // Estharos Change from man6 to this model
	ch.sex = "man";
	ch.location	= "Havana_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Jorge Suarez_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_esteban castillo";
	AddGameCharacter(n, ch);

	//===============================| Marigot Town |===============================//
	
	ch.old.name = "Maurice";
	ch.old.lastname = "Dupont";
	ch.name = TranslateString("", "Maurice");
	ch.lastname = TranslateString("", "Dupont");
	ch.id		= "Maurice Dupont";
	ch.model	= "Pirat8"; // Estharos Change from man2 to this model
	ch.sex = "man";
	ch.location	= "Marigot_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Maurice Dupont_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
	ch.nation = FRANCE;
	ch.rank 	= 1;
	ch.reputation = "53";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "1";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "4";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "3";
	ch.skill.Sneak = "1";
	ch.money = "10";
	ch.quest.meeting = "0";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_jean filaut";
	AddGameCharacter(n, ch);
	
	//==============================| Oranjestad Town |=============================//
/*
	ch.old.name = "Abraham";
	ch.old.lastname = "Hollander";
	ch.name = TranslateString("","Abraham");
	ch.lastname = TranslateString("","Hollander");
	ch.id		= "Abraham Hollander";
	ch.model	= "bocman17"; // Estharos Change from Old_man1 to this model
	ch.sex = "man";
	ch.location	= "Oranjestad_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Abraham Hollander_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Lambrecht Fobes";
	AddGameCharacter(n, ch);
*/
	//================================| Oxbay Town |================================//
	
	ch.old.name = "Oweyn";
	ch.old.lastname = "McDorey";
	ch.name 	= TranslateString("", "Oweyn");
	ch.lastname 	= TranslateString("", "McDorey");
	ch.id		= "Oweyn McDorey";
	ch.model	= "bocman"; // Estharos Change from Sailor6 to this model
	ch.sex = "man";
	ch.location	= "Oxbay_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Oweyn McDorey_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Oweyn McDorey";
	AddGameCharacter(n, ch);
	
	//=============================| Philipsburg Town |=============================//
	
	ch.old.name = "Arendt";
	ch.old.lastname = "Verheugen";
	ch.name = TranslateString("", "Arendt");
	ch.lastname = TranslateString("", "Verheugen");
	ch.id		= "Arendt Verheugen";
	ch.model	= "Old_man2"; // Estharos Change from man1 to this model
	ch.sex = "man";
	ch.location	= "Philipsburg_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Arendt Verheugen_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Lambrecht Fobes";
	AddGameCharacter(n, ch);
	
	//============================| Point a Pitre Town |============================//
	
	ch.old.name = "Prosper";
	ch.old.lastname = "Fraigneau";
	ch.name 	= TranslateString("", "Prosper");
	ch.lastname 	= TranslateString("", "Fraigneau");
	ch.id		= "Prosper Fraigneau";
	ch.model	= "man1"; // Estharos Change from Corsair4 to this model
	ch.headmodel = "h_man1"; // Estharos Change from h_Corsair4 to this model
	ch.sex = "man";
	ch.location	= "Pointe_a_pitre_shipyard";
	ch.location.group = "goto"; //"sit";
	ch.location.locator = "goto10"; //;
	ch.Dialog.Filename = "Prosper Fraigneau_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetCitizenType(ch);	//LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_Prosper Fraigneau";
	AddGameCharacter(n, ch);
	
	//============================| Port o Prince Town |============================//

	ch.old.name = "Benoit";
	ch.old.lastname = "Bertignac";
	ch.name 	= TranslateString("", "Benoit");
	ch.lastname 	= TranslateString("", "Bertignac");
	ch.id		= "Benoit Bertignac";
	ch.model	= "capstan"; // Estharos Change from Searcher to this model
	ch.headmodel = "h_capstan";
	ch.sex = "man";
	ch.location	= "PoPrince_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Benoit Bertignac_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "FRANCE_CITIZENS");
	ch.greeting = "Gr_Benoit Bertignac";
	AddGameCharacter(n, ch);
	
	//=========================| Quebradas Costillas Town |=========================//
	
	ch.old.name = "Jakob";
	ch.old.lastname = "Nickerson";
	ch.name = TranslateString("", "Jakob");
	ch.lastname = TranslateString("", "Nickerson");
	ch.id		= "Jakob Nickerson";
	ch.model	= "pirat15"; // Estharos Change from pirat4 to this model
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "QC_shipyard";
	ch.location.group = "sit";//for oxbay style shipyard use "goto";
	ch.location.locator = "sit3";//for oxbay style chipyard use "sit_1";
	ch.Dialog.Filename = "Jakob Nickerson_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);
	
	//===============================| Redmond Town |===============================//
	
	ch.old.name = "Roger";
	ch.old.lastname = "Murray";
	ch.name = TranslateString("", "Roger");
	ch.lastname = TranslateString("", "Murray");
	ch.id		= "Roger Murray";
	ch.model	= "9R_Carp"; // Estharos Change from man1 to this model
	ch.sex = "man";
	ch.location	= "Redmond_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Roger Murray_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "ENGLAND_CITIZENS");
	ch.greeting = "Gr_Roger Murray";
	AddGameCharacter(n, ch);
	
	//===============================| Santiago Town |==============================//

	ch.old.name = "Pablo";
	ch.old.lastname = "Duarte";
	ch.name = TranslateString("", "Pablo");
	ch.lastname = TranslateString("", "Duarte");
	ch.id		= "Pablo Duarte";
	ch.model	= "Sailor16"; // Estharos Change from man6 to this model
	ch.sex = "man";
	ch.location	= "Santiago_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit_1";
	ch.Dialog.Filename = "Pablo Duarte_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_esteban castillo";
	AddGameCharacter(n, ch);

	//============================| Santo Domingo Town |============================//

	ch.old.name = "Teodinus";
	ch.old.lastname = "Serrano";
	ch.name 	= TranslateString("", "Teodinus");
	ch.lastname 	= TranslateString("", "Serrano");
	ch.id		= "Teodinus Serrano";
	ch.model = "man6"; // Estharos Change from Storeman2 to this model
	ch.sex = "man";
	ch.location	= "Santo_Domingo_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Teodinus Serrano_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_esteban castillo";
	AddGameCharacter(n, ch);
	
	//==============================| Smugglers Town |==============================//
	//===============================| Tortuga Town |===============================//

	ch.old.name = "Adhemar";
	ch.old.lastname = "Bertillon";
	ch.name 	= TranslateString("", "Adhemar");
	ch.lastname 	= TranslateString("", "Bertillon");
	ch.id		= "Adhemar Bertillon";
	ch.model	= "capitan";
	ch.sex = "man";
	GiveItem2Character(ch, "blade2");
	ch.equip.blade = "blade2";
	GiveItem2Character(ch, "pistol2");
	ch.equip.gun = "pistol2";
	ch.location	= "Tortuga_shipyard";
	ch.location.group = "goto";
	ch.location.locator = "goto1";
	ch.Dialog.Filename = "Jakob Nickerson_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	//LAi_SetHuberType(ch);
	LAi_SetWarriorType(ch);
	LAi_warrior_DialogEnable(ch, true);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "TORTUGA_SOLDIERS");
	ch.greeting = "Gr_Valentin Massoni";
	AddGameCharacter(n, ch);
	
	//================================| Turks Town |================================//
	
	ch.old.name = "Maarten";
	ch.old.lastname = "Verlinden";
	ch.name 	= TranslateString("", "Maarten");
	ch.lastname = TranslateString("", "Verlinden");
	ch.id		= "Maarten Verlinden";
	ch.model	= "bocman3"; // Estharos Change from bocman1 to this model
	ch.sex = "man";
	ch.sound_type = "pirate";
	ch.location	= "Grand_Turk_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Jakob Nickerson_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
	ch.nation = PIRATE;
	GiveItem2Character(ch, "blade4");
	ch.equip.blade = "blade4";
	ch.rank 	= 1;
	ch.reputation = "None";
	ch.experience = "0";
	ch.skill.Leadership = "1";
	ch.skill.Fencing = "6";
	ch.skill.Sailing = "1";
	ch.skill.Accuracy = "1";
	ch.skill.Cannons = "1";
	ch.skill.Grappling = "1";
	ch.skill.Repair = "1";
	ch.skill.Defence = "1";
	ch.skill.Commerce = "1";
	ch.skill.Sneak = "1";
	ch.money = "1";
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "QC_SOLDIERS");
	ch.greeting = "Gr_QC Citizen";
	AddGameCharacter(n, ch);
	
	//==============================| Willemstad Town |=============================//
	
	ch.old.name = "Gheret";
	ch.old.lastname = "Bogardus";
	ch.name = TranslateString("", "Gheret");
	ch.lastname = TranslateString("", "Bogardus");
	ch.id		= "Gheret Bogardus";
	ch.model	= "Pirtt7"; // Estharos Change from Sailor19 to this model
	ch.sex = "man";
	ch.location	= "Willemstad_Shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Gheret Bogardus_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	LAi_SetHuberType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_group_MoveCharacter(ch, "DOUWESEN_CITIZENS");
	ch.greeting = "Gr_Lambrecht Fobes";
	AddGameCharacter(n, ch);

	ch.old.name = "Hendrick";
	ch.old.lastname = "Vanderdecken";
	ch.name 	= TranslateString("", "Hendrick");
	ch.lastname 	= TranslateString("", "Vanderdecken");
	ch.id		= "Hendrick Vanderdecken";
	ch.model = "Vanderdecken";
	ch.sex = "man";
	ch.nation = PIRATE;
	ch.location	= "IslaDeMuerte_Cabin";
	ch.location.group = "sit";
	ch.location.locator = "sit1";
	ch.Dialog.Filename = "Hendrick Vanderdecken_dialog.c";
	ch.rank 	= 100;
	ch.reputation = "None";
	ch.experience = "1000";
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
	GiveItem2Character(ch, "cursedcoin"); // PB: Cursed Coins
	ch.money = "10";
    ch.questchar = true;
	ch.greeting = "Gr_Lambrecht Fobes";
	LAi_SetSitType(ch);
	LAi_SetLoginTime(ch, 0.0, 24.0);
	LAi_SetImmortal(ch, true);
	AddGameCharacter(n, ch);
	
	//=============================| Cartagena Town |=============================//

	ch.old.name = "Ricardo";
	ch.old.lastname = "Ordiales";
	ch.name = TranslateString("", "Ricardo");
	ch.lastname = TranslateString("", "Ordiales");
	ch.id		= "Ricardo Ordiales";
	ch.model	= "sailor13";
	ch.sex = "man";
	ch.location	= "Cartagena_shipyard";
	ch.location.group = "sit";
	ch.location.locator = "sit3";
	ch.Dialog.Filename = "Esteban Castillo_dialog.c";
	ch.Dialog.Filename.GroupDialog = "shipyard.c"; //Levis
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
	ch.quest.escort = "0";
	LAi_SetHuberType(ch);
	LAi_group_MoveCharacter(ch, "SPAIN_CITIZENS");
	ch.greeting = "Gr_esteban castillo";
	AddGameCharacter(n, ch);	
}