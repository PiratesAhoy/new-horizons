void StartStoryLine()
{
	string loadPort = "";
	string rldGroup;
	string rldLocator;

	ref PChar = GetMainCharacter();

	DeleteAttribute(PChar, "items"); // PB: Override Character Type
		
	Pchar.perks.list.Gunman = true;				
	Pchar.perks.list.CriticalHit = true;
	Pchar.perks.freepoints = 0;
	Pchar.rank = 1;				
	
	Pchar.skill.Leadership = "3";
	Pchar.skill.Fencing = "3";		
	Pchar.skill.Sailing = "1";
	Pchar.skill.Accuracy = "1";
	Pchar.skill.Cannons = "1";
	Pchar.skill.Grappling = "1";
	Pchar.skill.Repair = "1";
	Pchar.skill.Defence = "1";
	Pchar.skill.Commerce = "1";
	Pchar.skill.Sneak = "1";		
	
	ref ch = CharacterFromID("Swedish Guy");
	ch.nation = PERSONAL_NATION;
	ch.Flags.Personal = 3;				//was 3
	ch.Flags.Personal.texture = 4;			//was 4
	Towns[GetTownIndex("Khael Roa")].gov = "Swedish Guy";

	Locations[FindLocation("IslaMona_port_exit")].models.always.locators = "QCexit_l_wr2";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.name = "Reload1";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.go = "Kristiania_canyon";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.emerge = "reload2";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.autoreload = "0";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.label = "";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.disable = 0;

	iForceDetectionFalseFlag = -1;	//which will make everyone ALWAYS believe your false flag
	DisableFastTravel(true);

	DeleteAttribute(PChar, "quest.Install_Voysey_And_Blythe");								//disables sidequest in Nevis
	DeleteAttribute(&Locations[FindLocation("QC_town")],"vcskip");								//disables sidequest in Nevis
	ChangeCharacterAddress(characterFromID("Marc Blacque"), "none", ""); 							//disables Blaque sidequest in Port Royal
	ChangeCharacterAddress(characterFromID("Milon Blacque"), "none", "");							//disables sidequest
	ChangeCharacterAddress(characterFromID("Willem Voigt"), "none", "");							//disables sidequest
	ChangeCharacterAddress(characterFromID("Rian Dekkers"), "none", "");							//disables sidequest
	ChangeCharacterAddress(characterFromID("Janneke Blinkerhof"), "none", "");						//disables sidequest
	ChangeCharacterAddress(characterFromID("Lisebet Schefold"), "none", "");						//disables sidequest

	Characters[GetCharacterIndex("Thomas O'Reily")].Dialog.Filename = "Cornelis Huijser_dialog.c";	//disables O'Reilly sidequest in Port Royal

	Stores[PIRATES_STORE].owner = "Peter Blowhorn";	//to enable trade with QC

	GiveItem2Character(characterFromID("Brthug5"), "bladep2"); EquipCharacterbyItem(characterFromID("Brthug5"), "bladep2");
	GiveItem2Character(characterFromID("Brthug5"), "pistolb1"); EquipCharacterbyItem(characterFromID("Brthug5"), "pistolb1");
	GiveItem2Character(characterFromID("wr_voy"), "bladep6"); EquipCharacterbyItem(characterFromID("wr_voy"), "bladep6");
	GiveItem2Character(characterFromID("wr_aub"), "bladep6"); EquipCharacterbyItem(characterFromID("wr_aub"), "bladep6");
	GiveItem2Character(characterFromID("wr_pir13"), "bladeA17"); EquipCharacterbyItem(characterFromID("wr_pir13"), "bladeA17");
	GiveItem2Character(characterFromID("gm_crew18"), "bladeA17"); EquipCharacterbyItem(characterFromID("gm_crew18"), "bladeA17");
	GiveItem2Character(characterFromID("wr_cor4"), "bladeA2"); EquipCharacterbyItem(characterFromID("wr_cor4"), "bladpA2");
	GiveItem2Character(characterFromID("gm_crew11"), "bladeA2"); EquipCharacterbyItem(characterFromID("gm_crew11"), "bladeA2");
	GiveItem2Character(characterFromID("wr_bri"), "bladeA5"); EquipCharacterbyItem(characterFromID("wr_bri"), "bladeA5");
	GiveItem2Character(characterFromID("Woodes Rogers"), "bladeA5"); EquipCharacterbyItem(characterFromID("Woodes Rogers"), "bladeA5");
	GiveItem2Character(characterFromID("wr_fralut"), "blade3carpets"); EquipCharacterbyItem(characterFromID("wr_fralut"), "blade3carpets");
	GiveItem2Character(characterFromID("wr_mong"), "bladebarrel"); EquipCharacterbyItem(characterFromID("wr_mong"), "bladebarrel");
	GiveItem2Character(characterFromID("gm_crew14"), "bladebarrel"); EquipCharacterbyItem(characterFromID("gm_crew14"), "bladebarrel");
	GiveItem2Character(characterFromID("wr_mong"), "pistolbarrel"); EquipCharacterbyItem(characterFromID("wr_mong"), "pistolbarrel");
	GiveItem2Character(characterFromID("wr_pir4"), "bladeglobe"); EquipCharacterbyItem(characterFromID("wr_pir4"), "bladeglobe");
	GiveItem2Character(characterFromID("wr_fatj"), "bladebasket"); EquipCharacterbyItem(characterFromID("wr_fatj"), "bladebasket");
	GiveItem2Character(characterFromID("pir_cap3"), "pistoldart"); EquipCharacterbyItem(characterFromID("pir_cap3"), "pistoldart");
	GiveItem2Character(characterFromID("pir_cap27"), "pistoldart"); EquipCharacterbyItem(characterFromID("pir_cap27"), "pistoldart");
	GiveItem2Character(characterFromID("pir_cap29"), "pistoldart"); EquipCharacterbyItem(characterFromID("pir_cap29"), "pistoldart");
	GiveItem2Character(characterFromID("pir_cap30"), "pistoldart"); EquipCharacterbyItem(characterFromID("pir_cap30"), "pistoldart");
	GiveItem2Character(characterFromID("gm_crew6"), "pistoldart"); EquipCharacterbyItem(characterFromID("gm_crew6"), "pistoldart");
	GiveItem2Character(characterFromID("pir_cap4"), "pistolthrowaxe"); EquipCharacterbyItem(characterFromID("pir_cap4"), "pistolthrowaxe");
	GiveItem2Character(characterFromID("pir_cap9"), "pistolthrowaxe"); EquipCharacterbyItem(characterFromID("pir_cap9"), "pistolthrowaxe");
	GiveItem2Character(characterFromID("pir_cap18"), "pistolthrowaxe"); EquipCharacterbyItem(characterFromID("pir_cap18"), "pistolthrowaxe");
	GiveItem2Character(characterFromID("pir_cap26"), "pistolthrowaxe"); EquipCharacterbyItem(characterFromID("pir_cap26"), "pistolthrowaxe");
	GiveItem2Character(characterFromID("Selkirk"), "bladespyglass6"); EquipCharacterbyItem(characterFromID("Selkirk"), "bladespyglass6");
	GiveItem2Character(characterFromID("Defoe"), "pistol201"); EquipCharacterbyItem(characterFromID("Defoe"), "pistol201");
	GiveItem2Character(characterFromID("Defoe_incognito"), "pistol201"); EquipCharacterbyItem(characterFromID("Defoe_incognito"), "pistol201");
	GiveItem2Character(characterFromID("guncrew_1"), "bladeladle"); EquipCharacterbyItem(characterFromID("guncrew_1"), "bladeladle");
	GiveItem2Character(characterFromID("guncrew_2"), "pistolrammer"); EquipCharacterbyItem(characterFromID("guncrew_2"), "pistolrammer");
	GiveItem2Character(characterFromID("gm_crew23"), "pistolrammer"); EquipCharacterbyItem(characterFromID("gm_crew23"), "pistolrammer");
	GiveItem2Character(characterFromID("guncrew_3"), "pistolboom"); EquipCharacterbyItem(characterFromID("guncrew_3"), "pistolboom");
	GiveItem2Character(characterFromID("guncrew_4"), "pistolsponge"); EquipCharacterbyItem(characterFromID("guncrew_4"), "pistolsponge");
	GiveItem2Character(characterFromID("gm_crew13"), "pistolsponge"); EquipCharacterbyItem(characterFromID("gm_crew13"), "pistolsponge");
	GiveItem2Character(characterFromID("Richards"), "pistol205"); EquipCharacterbyItem(characterFromID("Richards"), "pistol205");
	GiveItem2Character(characterFromID("black_servant1"), "bladep0"); EquipCharacterbyItem(characterFromID("black_servant1"), "bladep0");
	GiveItem2Character(characterFromID("JRH"), "bladecompasses"); EquipCharacterbyItem(characterFromID("JRH"), "bladecompasses");
	GiveItem2Character(characterFromID("gm_crew1"), "bladeboathook_1"); EquipCharacterbyItem(characterFromID("gm_crew1"), "bladeboathook_1");
	GiveItem2Character(characterFromID("gm_crew2"), " bladeflag_pir"); EquipCharacterbyItem(characterFromID("gm_crew2"), " bladeflag_pir");
	GiveItem2Character(characterFromID("gm_crew5"), " bladeanchor"); EquipCharacterbyItem(characterFromID("gm_crew5"), " bladeanchor");
	GiveItem2Character(characterFromID("gm_crew7"), " bladeaxe5"); EquipCharacterbyItem(characterFromID("gm_crew7"), " bladeaxe5");
	GiveItem2Character(characterFromID("gm_crew15"), " bladeaxe4"); EquipCharacterbyItem(characterFromID("gm_crew15"), " bladeaxe4");
//Q2
	GiveItem2Character(characterFromID("french_surgeon3"), "tool5"); EquipCharacterbyItem(characterFromID("french_surgeon3"), "tool5");
	GiveItem2Character(characterFromID("french_surgeon4"), "bladeX4"); EquipCharacterbyItem(characterFromID("french_surgeon4"), "bladeX4");
	GiveItem2Character(characterFromID("french_surgeon4"), "pistolmdchest_F1_C"); EquipCharacterbyItem(characterFromID("french_surgeon4"), "pistolmdchest_F1_C");

	GiveItem2Character(characterFromID("Kri_gunner_1"), "pistolsponge"); EquipCharacterbyItem(characterFromID("Kri_gunner_1"), "pistolsponge");
	GiveItem2Character(characterFromID("Kri_gunner_2"), "pistolrammer"); EquipCharacterbyItem(characterFromID("Kri_gunner_2"), "pistolrammer");
	GiveItem2Character(characterFromID("Kri_gunner_3"), "pistolboom"); EquipCharacterbyItem(characterFromID("Kri_gunner_3"), "pistolboom");
	GiveItem2Character(characterFromID("Kri_gunner_5"), "pistolbarrel4"); EquipCharacterbyItem(characterFromID("Kri_gunner_5"), "pistolbarrel4");
	GiveItem2Character(characterFromID("Kri_gunner_6"), "bladecannon_ball"); EquipCharacterbyItem(characterFromID("Kri_gunner_6"), "bladecannon_ball");
	GiveItem2Character(characterFromID("Kri_dragoon_1"), "pistol203"); EquipCharacterbyItem(characterFromID("Kri_dragoon_1"), "pistol203");
	GiveItem2Character(characterFromID("Kri_dragoon_2"), "pistol203"); EquipCharacterbyItem(characterFromID("Kri_dragoon_2"), "pistol203");
	GiveItem2Character(characterFromID("Kri_dragoon_3"), "pistol203"); EquipCharacterbyItem(characterFromID("Kri_dragoon_3"), "pistol203");
	GiveItem2Character(characterFromID("Kri_dragoon_4"), "pistol203"); EquipCharacterbyItem(characterFromID("Kri_dragoon_4"), "pistol203");
	GiveItem2Character(characterFromID("Kri_dragoon_5"), "pistol203"); EquipCharacterbyItem(characterFromID("Kri_dragoon_5"), "pistol203");
	GiveItem2Character(characterFromID("Kri_dragoon_6"), "pistol203"); EquipCharacterbyItem(characterFromID("Kri_dragoon_6"), "pistol203");
	GiveItem2Character(characterFromID("devil"), "bladethunder"); EquipCharacterbyItem(characterFromID("devil"), "bladethunder");
	GiveItem2Character(characterFromID("devil"), "pistollightning"); EquipCharacterbyItem(characterFromID("devil"), "pistollightning");

	Locations[FindLocation("Redmond_Port")].models.always.locators = "RedPort_l_JRH0";
	Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH";
	Locations[FindLocation("Redmond_Town_01")].reload.l16.go = "";
	Locations[FindLocation("Redmond_Town_01")].reload.l16.emerge = "";
	Locations[FindLocation("Redmond_Town_01")].reload.l16.label = "";			//'kitchen' when opened
	Locations[FindLocation("Redmond_Town_01")].reload.l16.disable = 1;
	Locations[FindLocation("Redmond_Town_04")].models.always.locators = "Red04_l_JRH";
	Locations[FindLocation("Redmond_tavern")].models.always.locators = "LT_l_JRH";
	Locations[FindLocation("Redmond_tavern")].reload.l2.go = "JRH_tavern_upstairs";
	Locations[FindLocation("Redmond_tavern")].reload.l2.disable = 1;
	Locations[FindLocation("Redmond_UsurerHouse")].models.always.locators = "SS_l_JRH1";
	Locations[FindLocation("Redmond_shipyard")].models.always.locators = "sh01_l_JRH";

	//switch back town exits
	Locations[FindLocation("Redmond_Town_03")].reload.l3.go = "Redmond_town_exit_1";
	Locations[FindLocation("Redmond_Town_03")].reload.l6.go = "Redmond_town_exit_1";
	Locations[FindLocation("Redmond_Town_04")].reload.l3.go = "Redmond_Town_exit_2";
	Locations[FindLocation("Redmond_town_exit_1")].reload.l1.go = "Redmond_Town_03";
	Locations[FindLocation("Redmond_town_exit_1")].reload.l1.emerge = "reload_3_3";
	Locations[FindLocation("Redmond_town_exit_2")].reload.l1.go = "Redmond_town_04";
	Locations[FindLocation("Redmond_town_exit_2")].reload.l1.emerge = "reload_2_jungle";
	Locations[FindLocation("Redmond_town_exit_2")].reload.l3.go = "Redmond_town_04";
	Locations[FindLocation("Redmond_town_exit_2")].reload.l3.emerge = "reload_2_jungle";

	ChangeCharacterAddressGroup(characterFromID("Greg Dawson"), "none", "", "");//B14 replacement for Sarah Fitter
	ChangeCharacterAddressGroup(characterFromID("John Clifford Brin"), "none", "", "");//default governor
	ChangeCharacterAddressGroup(characterFromID("Red_soldier_3"), "none", "", "");//Naval HQ guard
	ChangeCharacterAddressGroup(characterFromID("Red_soldier_4"), "none", "", "");//Naval HQ guard

	ChangeCharacterAddressGroup(characterFromID("cloister_monk1"), "none", "", "");		//these 4 in all other storylines
	ChangeCharacterAddressGroup(characterFromID("cloister_monk2"), "none", "", "");
	ChangeCharacterAddressGroup(characterFromID("cloister_monk3"), "none", "", "");
	ChangeCharacterAddressGroup(characterFromID("cloister_monk4"), "none", "", "");

	Locations[FindLocation("QC_brothel")].models.always.locators = "LT_l_JRHbr";
	locations[FindLocation("QC_brothel")].type = "brothel_QC";
	
	//JRH window exit to roof
	Locations[FindLocation("QC_brothel")].reload.l2.name = "reload3";
	Locations[FindLocation("QC_brothel")].reload.l2.go = "QC_town";
	Locations[FindLocation("QC_brothel")].reload.l2.emerge = "roof1";
	Locations[FindLocation("QC_brothel")].reload.l2.autoreload = "0";
	Locations[FindLocation("QC_brothel")].reload.l2.label = "Quebradas Costillas.";
	Locations[FindLocation("QC_brothel")].reload.l2.disable = 1;

	locations[FindLocation("QC_brothel_upstairs")].type = "brothel_room_QC";
	Locations[FindLocation("QC_brothel_upstairs")].models.always.locators = "brothel_room_locators_JRH";
	Locations[FindLocation("QC_brothel_upstairs")].models.back = "back\qcbrothel_room_";

	//Reload map
	Locations[FindLocation("QC_brothel_upstairs")].reload.l1.name = "reload1";
	Locations[FindLocation("QC_brothel_upstairs")].reload.l1.go = "QC_brothel";
	Locations[FindLocation("QC_brothel_upstairs")].reload.l1.emerge = "reload2";
	Locations[FindLocation("QC_brothel_upstairs")].reload.l1.autoreload = "0";
	Locations[FindLocation("QC_brothel_upstairs")].reload.l1.label = "Quebradas Costillas Brothel.";
	Locations[FindLocation("QC_brothel_upstairs")].locators_radius.reload.reload1 = 0.8;

	Locations[FindLocation("Muelle_port")].models.always.l3.foam = "1";	

	ChangeCharacterAddressGroup(characterFromID("Kate Blowhorn"), "none", "", "");
	SetModel(characterFromID("Jakob Nickerson"), "pirat4", "man", "man", 1.8, false);

	GiveItem2Character(characterFromID("wr_aub"), "bladep6");		
	EquipCharacterbyItem(characterFromID("wr_aub"), "bladep6");
	GiveItem2Character(characterFromID("wr_pir13"), "bladeA17");		
	EquipCharacterbyItem(characterFromID("wr_pir13"), "bladeA17");
	GiveItem2Character(characterFromID("gm_crew18"), "bladeA17");		
	EquipCharacterbyItem(characterFromID("gm_crew18"), "bladeA17");
	GiveItem2Character(characterFromID("wr_cor4"), "bladeA2");		
	EquipCharacterbyItem(characterFromID("wr_cor4"), "bladeA2");
	GiveItem2Character(characterFromID("gm_crew11"), "bladeA2");		
	EquipCharacterbyItem(characterFromID("gm_crew11"), "bladeA2");
	GiveItem2Character(CharacterFromID("wr_bri"), "bladeA5");
	EquipCharacterbyItem(CharacterFromID("wr_bri"), "bladeA5");
	GiveItem2Character(CharacterFromID("Woodes Rogers"), "bladeA5");
	EquipCharacterbyItem(CharacterFromID("Woodes Rogers"), "bladeA5");
	GiveItem2Character(characterFromID("wr_fralut"), "blade3carpets");		
	EquipCharacterbyItem(characterFromID("wr_fralut"), "blade3carpets");
	GiveItem2Character(characterFromID("wr_mong"), "bladebarrel");		
	EquipCharacterbyItem(characterFromID("wr_mong"), "bladebarrel");
	GiveItem2Character(characterFromID("gm_crew14"), "bladebarrel");		
	EquipCharacterbyItem(characterFromID("gm_crew14"), "bladebarrel");
	GiveItem2Character(characterFromID("wr_mong"), "pistolbarrel");		
	EquipCharacterbyItem(characterFromID("wr_mong"), "pistolbarrel");
	GiveItem2Character(CharacterFromID("wr_pir4"), "bladeglobe");
	EquipCharacterbyItem(CharacterFromID("wr_pir4"), "bladeglobe");
	GiveItem2Character(CharacterFromID("wr_fatj"), "bladebasket");
	EquipCharacterbyItem(CharacterFromID("wr_fatj"), "bladebasket");
	GiveItem2Character(characterFromID("pir_cap3"), "pistoldart");		
	EquipCharacterbyItem(characterFromID("pir_cap3"), "pistoldart");
	GiveItem2Character(characterFromID("pir_cap30"), "pistoldart");		
	EquipCharacterbyItem(characterFromID("pir_cap30"), "pistoldart");
	GiveItem2Character(characterFromID("pir_cap27"), "pistoldart");		
	EquipCharacterbyItem(characterFromID("pir_cap27"), "pistoldart");
	GiveItem2Character(characterFromID("pir_cap29"), "pistoldart");		
	EquipCharacterbyItem(characterFromID("pir_cap29"), "pistoldart");
	GiveItem2Character(characterFromID("gm_crew6"), "pistoldart");		
	EquipCharacterbyItem(characterFromID("gm_crew6"), "pistoldart");
	GiveItem2Character(CharacterFromID("pir_cap9"), "pistolthrowaxe");
	EquipCharacterbyItem(CharacterFromID("pir_cap9"), "pistolthrowaxe");
	GiveItem2Character(CharacterFromID("pir_cap4"), "pistolthrowaxe");
	EquipCharacterbyItem(CharacterFromID("pir_cap4"), "pistolthrowaxe");
	GiveItem2Character(CharacterFromID("pir_cap26"), "pistolthrowaxe");
	EquipCharacterbyItem(CharacterFromID("pir_cap26"), "pistolthrowaxe");
	GiveItem2Character(CharacterFromID("pir_cap18"), "pistolthrowaxe");
	EquipCharacterbyItem(CharacterFromID("pir_cap18"), "pistolthrowaxe");
	GiveItem2Character(CharacterFromID("Selkirk"), "bladespyglass6");
	EquipCharacterbyItem(CharacterFromID("Selkirk"), "bladespyglass6");
	GiveItem2Character(CharacterFromID("Defoe"), "pistol201");
	EquipCharacterbyItem(CharacterFromID("Defoe"), "pistol201");
	GiveItem2Character(CharacterFromID("Defoe_incognito"), "pistol201");
	EquipCharacterbyItem(CharacterFromID("Defoe_incognito"), "pistol201");
	GiveItem2Character(CharacterFromID("guncrew_1"), "bladeladle");
	EquipCharacterbyItem(CharacterFromID("guncrew_1"), "bladeladle");
	GiveItem2Character(CharacterFromID("guncrew_2"),"pistolrammer");
	EquipCharacterByItem(CharacterFromID("guncrew_2"), "pistolrammer");
	GiveItem2Character(CharacterFromID("gm_crew23"),"pistolrammer");
	EquipCharacterByItem(CharacterFromID("gm_crew23"), "pistolrammer");
	GiveItem2Character(CharacterFromID("guncrew_3"),"pistolboom");
	EquipCharacterByItem(CharacterFromID("guncrew_3"), "pistolboom");
	GiveItem2Character(CharacterFromID("guncrew_4"),"pistolsponge");
	EquipCharacterByItem(CharacterFromID("guncrew_4"), "pistolsponge");
	GiveItem2Character(CharacterFromID("gm_crew13"),"pistolsponge");
	EquipCharacterByItem(CharacterFromID("gm_crew13"), "pistolsponge");
	GiveItem2Character(CharacterFromID("Richards"),"pistol205");
	EquipCharacterByItem(CharacterFromID("Richards"), "pistol205");
	//GiveItem2Character(characterFromID("gm_crew1"), "bladeboathook_1");		
	//EquipCharacterbyItem(characterFromID("gm_crew1"), "bladeboathook_1");
	GiveItem2Character(characterFromID("gm_crew2"), "bladeflag_pir");		
	EquipCharacterbyItem(characterFromID("gm_crew2"), "bladeflag_pir");
	GiveItem2Character(characterFromID("gm_crew5"), "bladeanchor");		
	EquipCharacterbyItem(characterFromID("gm_crew5"), "bladeanchor");
	GiveItem2Character(characterFromID("gm_crew7"), "bladeaxe5");		
	EquipCharacterbyItem(characterFromID("gm_crew7"), "bladeaxe5");
	GiveItem2Character(characterFromID("gm_crew15"), "bladeaxe4");		
	EquipCharacterbyItem(characterFromID("gm_crew15"), "bladeaxe4");
	GiveItem2Character(characterFromID("jrh"), "bladecompasses");		
	EquipCharacterbyItem(characterFromID("jrh"), "bladecompasses");
	GiveItem2Character(characterFromID("BB_monk5"), "bladestool");		
	EquipCharacterbyItem(characterFromID("BB_monk5"), "bladestool");

	SetCharacterShipLocation(characterFromID("gm_crew1"), "swamp_island1");		//fallen_tree, diff pos
	SetCharacterShipLocation(characterFromID("gm_crew2"), "swamp_island2");		//raft2
	SetCharacterShipLocation(characterFromID("gm_crew3"), "mutiny_deckWR");		//boat beside ship
	SetCharacterShipLocation(characterFromID("gm_crew4"), "swamp_island1");		//boat close to shore
	SetCharacterShipLocation(characterFromID("gm_crew5"), "swamp_island1");		//sloop
	SetCharacterShipLocation(characterFromID("gm_crew7"), "at_sea_in_fog");		//raft2 far out at sea
	SetCharacterShipLocation(characterFromID("gm_crew8"), "at_sea_in_fog");		//HMS_Endeavour far out at sea
//Q2
	SetCharacterShipLocation(characterFromID("gm_crew12"), "BB_upper_cave");	//tartane50
	SetCharacterShipLocation(characterFromID("gm_crew14"), "BB_isle");		//tartane50
/*
//replaced
	SetCharacterShipLocation(characterFromID("gm_crew15"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew16"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew17"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew18"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew19"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew20"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew21"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew22"), "BB_prison_port");	//Gunboat at port
	SetCharacterShipLocation(characterFromID("gm_crew23"), "BB_prison_port");	//Gunboat at prison
*/
	SetCharacterShipLocation(characterFromID("wr_mummy1"), "Kristiania_shipwreck");	//obj_raft3
//replaced
//	SetCharacterShipLocation(characterFromID("wr_mummy2"), "Kristiania_port");	//obj_invisible	
	SetCharacterShipLocation(characterFromID("wr_mummy3"), "Turks_wreck_shore");	//obj_cutter_wreck
	SetCharacterShipLocation(characterFromID("wr_mummy4"), "Turks_wreck_shore");	//obj_PrisonShip1
	SetCharacterShipLocation(characterFromID("wr_mummy8"), "BB_sloop");		//cutter2 (Maynard's)
	SetCharacterShipLocation(characterFromID("wr_mummy9"), "BB_sloop");		//cutter1 (Maynard's)
	SetCharacterShipLocation(characterFromID("Teach_head"), "BB_QAR_deck");			//sloop4 Charleston blockade
	SetCharacterShipLocation(characterFromID("Kristiania_shipyard_owner"), "BB_QAR_deck");	//cutter2 Charleston blockade
	SetCharacterShipLocation(characterFromID("BB_nun1"), "BB_QAR_deck");			//boat sailors Charleston blockade
	SetCharacterShipLocation(characterFromID("crypt_skeleton5"), "BB_QAR_deck");		//boat Fort Charleston blockade
	SetCharacterShipLocation(characterFromID("crypt_skeleton6"), "BB_QAR_deck");		//boat Fort Charleston blockade
	SetCharacterShipLocation(characterFromID("crypt_skeleton7"), "BB_QAR_deck");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("crypt_skeleton8"), "BB_QAR_deck");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("crypt_zombie1"), "BB_QAR_deck");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("french_surgeon1"), "BB_QAR_deck");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("french_surgeon2"), "BB_QAR_deck");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("french_surgeon3"), "BB_QAR_deck");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("french_surgeon4"), "BB_QAR_deck");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("carriage_girl"), "BB_QAR_cabin");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("fake_Ogeron"), "BB_QAR_cabin");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("Maynard"), "BB_QAR_cabin");			//Charleston blockade
	SetCharacterShipLocation(characterFromID("citadel_thug1"), "BB_QAR_cabin");		//Charleston blockade
	SetCharacterShipLocation(characterFromID("citadel_thug2"), "BB_Eden_estate");		//Estate river
	SetCharacterShipLocation(characterFromID("citadel_thug3"), "BB_QAR_cabinH");		//QAR cabinH Hands
	SetCharacterShipLocation(characterFromID("citadel_thug4"), "BB_QAR_cabinH");		//QAR cabinH Bonnet
	SetCharacterShipLocation(characterFromID("citadel_thug5"), "BB_QAR_cabinH");		//QAR cabinH 4:th sloop

	GiveShip2Character(characterFromID("Tor_soldier_4"),"MerchantPinnace","Victory",-1,FRANCE,true,true);
	GiveShip2Character(characterFromID("Tor_soldier_5"),"SchoonerXebec","Victory",-1,FRANCE,true,true);
	GiveShip2Character(characterFromID("Tor_soldier_6"),"FR_Sloop","Victory",-1,FRANCE,true,true);
	GiveShip2Character(characterFromID("Tor_soldier_7"),"Sloop2","Victory",-1,FRANCE,true,true);
	GiveShip2Character(characterFromID("Tor_soldier_8"),"PiratBrig50","Victory",-1,FRANCE,true,true);
					
	setCharacterShipLocation(characterFromID("Tor_soldier_4"), "Tortuga_tower");
	setCharacterShipLocation(characterFromID("Tor_soldier_5"), "Tortuga_tower");
	setCharacterShipLocation(characterFromID("Tor_soldier_6"), "Tortuga_tower");
	setCharacterShipLocation(characterFromID("Tor_soldier_7"), "Tortuga_tower"); 	
	setCharacterShipLocation(characterFromID("Tor_soldier_8"), "Tortuga_tower");
//replaced
//	setCharacterShipLocation(characterFromID("Maltese_soldier1"), "bb_prison_port");
	setCharacterShipLocation(characterFromID("Maltese_soldier2"), "Antigua_port");
	setCharacterShipLocation(characterFromID("Maltese_soldier3"), "BB_careen_shore");
	setCharacterShipLocation(characterFromID("Maltese_soldier4"), "BB_careen_shore");	//boat1
	setCharacterShipLocation(characterFromID("Maltese_soldier5"), "BB_careen_shore");	//boat2
	setCharacterShipLocation(characterFromID("Maltese_soldier6"), "BB_careen_shore");	//boat3
	setCharacterShipLocation(characterFromID("Maltese_soldier7"), "BB_careen_shore");	//boat4
	setCharacterShipLocation(characterFromID("Maltese_governor"), "BB_careen_shore");	//boat5
	setCharacterShipLocation(characterFromID("Maltese_red1"), "BB_careen_shore");
	setCharacterShipLocation(characterFromID("Maltese_red2"), "BB_careen_shore");		//hit boat1
	setCharacterShipLocation(characterFromID("Maltese_green"), "BB_careen_shore");		//hit boat2
	setCharacterShipLocation(characterFromID("Maltese_black"), "BB_careen_shore");		//hit boat2
	setCharacterShipLocation(characterFromID("Maltese_knight"), "BB_careen_shore");		//hit boat2
	setCharacterShipLocation(characterFromID("Margaret_Pough"), "BB_careen_shore");	//boat3 empty stopped
	setCharacterShipLocation(characterFromID("KR_indian_L"), "BB_careen_shore");	//boat4 empty stopped
	setCharacterShipLocation(characterFromID("KR_indian_1"), "BB_careen_shore");	//boat5 empty stopped

	setCharacterShipLocation(characterFromID("KR_indian_2"), "Kristiania_fort");	//Brig pos 1
	setCharacterShipLocation(characterFromID("KR_indian_3"), "Kristiania_fort");	//Brig pos 2

	setCharacterShipLocation(characterFromID("KR_cit3"), "Turks_sewer");		//skeleton
	setCharacterShipLocation(characterFromID("KR_cit4"), "Turks_sewer");		//fur
	setCharacterShipLocation(characterFromID("KR_cit5"), "Turks_sewer");		//wolfs_head

	setCharacterShipLocation(characterFromID("KR_cit6"), "Kristiania_port");
	setCharacterShipLocation(characterFromID("KR_cit7"), "Kristiania_port");
	setCharacterShipLocation(characterFromID("KR_cit8"), "Kristiania_port");
	setCharacterShipLocation(characterFromID("KR_cit9"), "Kristiania_port");
	setCharacterShipLocation(characterFromID("KR_cit10"), "Kristiania_port");
	setCharacterShipLocation(characterFromID("KR_cit11"), "Kristiania_port");
	setCharacterShipLocation(characterFromID("KR_cit12"), "Kristiania_port");

	setCharacterShipLocation(characterFromID("KR_cit13"), "BB_prison_port");
	setCharacterShipLocation(characterFromID("KR_cit14"), "BB_prison_port");
	setCharacterShipLocation(characterFromID("KR_cit15"), "BB_prison_port");
	setCharacterShipLocation(characterFromID("KR_cit16"), "Kristiania_port");
	
	if(ENABLE_CHEATMODE) ChangeCharacterAddressGroup(characterFromID("Teach_head"), "mutiny_cabin", "goto", "head");

	Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = 1;		//governors residence
	locations[FindLocation("Smugglers_Tavern")].type = "party";
	Locations[FindLocation("Smugglers_Tavern")].locators_radius.goto.goto17 = 3.0;	//was 2.0
	Locations[FindLocation("Smugglers_Tavern")].models.always.locators = "MT_l_JRH";
	Locations[FindLocation("Turks_Fort_Office")].models.always.locators = "armory_locators_JRH";
	Locations[FindLocation("Grand_Cayman_town")].models.always.locators = "DouTown_l_JRH";

	Pchar.killed_wr_officers = 0;
	Pchar.Caesar_info = "no";

//Q2:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	
//Quest 2
	Pchar.quest.BB_isl1_ladder = "way_up";

		Pchar.quest.WR_start = "1";	//normal quest start

	//  Pchar.quest.WR_start = "30";	//Cayman town
	//  Pchar.quest.WR_start = "31";	//shortcut start chapel
 	//	Pchar.quest.WR_start = "32";	//shortcut to Eden bribing scene		     only bribing + burning is ok, delete it
	//	Pchar.quest.WR_start = "33";	//shortcut to Eden bribing scene, burning ship       NO, doesn't work at all,      delete it
	//	Pchar.quest.WR_start = "35";	//Eden estate, to maze
	
	// 	Pchar.quest.WR_start = "43";	//cave shore to Vane
	//  Pchar.quest.WR_start = "45";	//french surgeons Tortuga
	//	Pchar.quest.WR_start = "46";	//tower open Tortuga
	//    Pchar.quest.WR_start = "47";	//Richards Cartagena
	//	Pchar.quest.WR_start = "49";	//Cloister fight					//didn't work ok at all

	//	Pchar.quest.WR_start = "50";	//Odel Smugglers_Tavern 
	//  Pchar.quest.WR_start = "55";	//Caesar Maynard Citadel Rock
	//  Pchar.quest.WR_start = "56";	//Caesar Turks start, to Fort
	//  Pchar.quest.WR_start = "57";	//Caesar Turks roof tour
	//	Pchar.quest.WR_start = "58";	//Caesar Turks cave					//starts strange if officers with you, else ok!
	//	Pchar.quest.WR_start = "59";	//Turks wreck shore

	//	Pchar.quest.WR_start = "60";	//Hands Willemstad port Curacao
	//  Pchar.quest.WR_start = "62";	//Hands Charleston Maltains
	//  Pchar.quest.WR_start = "63";	//Hands Antigua port
	//	Pchar.quest.WR_start = "64";	//Hands port - alcove - prison
	//	Pchar.quest.WR_start = "66";	//Hands alcove
	//	Pchar.quest.WR_start = "68";	//Hands prison2

	//	Pchar.quest.WR_start = "80";	//Kristiania canyon
	//	Pchar.quest.WR_start = "82";	//NS_upper_town
	//	Pchar.quest.WR_start = "83";	//NS_lower_town
	//	Pchar.quest.WR_start = "84";	//Kristiania_jungle_exit
	//	Pchar.quest.WR_start = "85";	//indian village
	//	Pchar.quest.WR_start = "86";	//Red House
		
	//	Pchar.quest.WR_start = "90";	//BB island1
	//	Pchar.quest.WR_start = "92";	//BB tower top
	//	Pchar.quest.WR_start = "97";	//BB Isle
	
	//	Pchar.quest.WR_start = "99";	//final boss				officers do not show up ok
	//      Pchar.quest.WR_start = "100";	//after treasure
	
	//	Pchar.quest.WR_start = "105";	//careen shore
	//	Pchar.quest.WR_start = "106";	//careen corvette
		
	//	Pchar.quest.WR_start = "109";	//start Q2
	//	Pchar.quest.WR_start = "110";	//alchemy part 1
	//	Pchar.quest.WR_start = "111";	//alchemy part 2

	//	Pchar.quest.WR_start = "150";	//defoe tavern scene, Cartagena new cloister
	//	Pchar.quest.WR_start = "151";	//defoe tavern scene, Turks fort


	switch(Pchar.quest.WR_start)
	{
			case "1":
				//normal quest start

				sTeleportLocName = "mutiny_cabin";
				rldGroup = "reload";
				rldLocator = "reload2";	

				SetCurrentTime(11.00, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";			

				AddMoneyToCharacter(Pchar, 23);
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "bladeX4");			//this was missing
		
				GiveItem2Character(Pchar, "pistolbbuss");
				EquipCharacterByItem(Pchar, "pistolbbuss");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolgrapes", 6);

				TakeNItems(PChar, "medical2", 1);
				TakeNItems(PChar, "spyglass2", 1);
				TakeNItems(PChar, "clock1",1);
				TakeNItems(PChar, "compass1",1);
				EquipCharacterbyItem(Pchar, "Spyglass2");
				EquipCharacterbyItem(PChar, "clock1");
				EquipCharacterbyItem(PChar, "compass1");
		
				Pchar.quest.fallen_tree = "pos_1";
				Pchar.quest.mast_climb = "way_up";
				Pchar.quest.raft_ropes = "not_yet";
		
				LAi_SetStayType(Pchar);

				LAi_QuestDelay("mutiny_cabin", 3.0);
			break;

			case "30":
		//	LAi_SetImmortal(pchar, true);		//temp
				rldGroup = "reload";
				sTeleportLocName = "Grand_Cayman_town";
				rldLocator = "reload15";

				Pchar.estate_direction = "Cayman_town";
			//	Pchar.estate_direction = "Teach_house";		//tour very direct to Teach house
			//	Pchar.estate_direction = "Knight_house";	//tour not finished

				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(Pchar, "Howard_Pyle_3", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);
				TakeNItems(PChar, "clock1",1);
				EquipCharacterbyItem(PChar, "clock1");	
				TakeNItems(Pchar,"medical1", 1);

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Cayman_port");
			
			//these 2 officers can be skipped here
			AddPassenger(Pchar, characterFromID("Hands"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
			SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);

			AddPassenger(Pchar, characterFromID("Pell"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Pell"));
			SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
			
			GiveItem2Character(characterFromID("Pell"), "blade4");
			EquipCharacterByItem(characterFromID("Pell"), "blade4");
			GiveItem2Character(characterFromID("Pell"), "piratespistol");
			EquipCharacterByItem(characterFromID("Pell"), "piratespistol");
			TakeNItems(characterFromID("Pell"),"gunpowder", 6);
			TakeNItems(characterFromID("Pell"),"pistolbullets", 6);
			
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
			
				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); AddQuestRecord("Israel_Hands","3");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2");
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");
			/*
			//started from after governor Shaw Cayman dialog
				LAi_QuestDelay("maze_gate1_down_check", 0.5);
				LAi_QuestDelay("maze_gate2_down_check", 0.5);
				LAi_QuestDelay("maze_F1_check", 0.5);
				LAi_QuestDelay("maze_F2_check", 0.5);
			*/


			break;

			case "31":
				//chapel - bribing scene - wine cellar

			LAi_SetImmortal(pchar, true);		//temp
				rldGroup = "reload";
				sTeleportLocName = "BB_Eden_chapel";
				rldLocator = "reload1";

				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(Pchar, "Howard_Pyle_3", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);
				TakeNItems(PChar, "clock1",1);
				EquipCharacterbyItem(PChar, "clock1");

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Cayman_port");

				AddPassenger(Pchar, characterFromID("Hands"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);

				AddPassenger(Pchar, characterFromID("Pell"), 0);
				SetOfficersIndex(Pchar, 2, getCharacterIndex("Pell"));
				SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
			
				GiveItem2Character(characterFromID("Pell"), "blade4");
				EquipCharacterByItem(characterFromID("Pell"), "blade4");
				GiveItem2Character(characterFromID("Pell"), "piratespistol");
				EquipCharacterByItem(characterFromID("Pell"), "piratespistol");
				TakeNItems(characterFromID("Pell"),"gunpowder", 6);
				TakeNItems(characterFromID("Pell"),"pistolbullets", 6);

				ChangeCharacterAddressGroup(characterFromID("Caesar"), "BB_Eden_estate", "goto", "servant2");
				SetModel(characterFromID("Caesar"), "black_servant2", "man", "man", 1.8, false);
				RemoveCharacterEquip(characterFromID("Caesar"), GUN_ITEM_TYPE);
				RemoveCharacterEquip(characterFromID("Caesar"), BLADE_ITEM_TYPE);
				DeleteAttribute(characterFromID("Caesar"), "items");
				LAi_SetStayType(characterFromID("Caesar"));
				characters[GetCharacterIndex("Caesar")].name = "Servant";
				GiveItem2Character(characterFromID("Caesar"), "machete");
				EquipCharacterByItem(characterFromID("Caesar"), "machete");

				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";

				Pchar.eden_info = "start";
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); AddQuestRecord("Israel_Hands","3");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2"); AddQuestRecord("Charles_Eden","3"); 
				AddQuestRecord("Charles_Eden","4"); AddQuestRecord("Charles_Eden","6"); AddQuestRecord("Charles_Eden","7"); 
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");

			LAi_QuestDelay("Margaret_Pough3_A", 0.5);		//places Pough and starts dialogs

				LAi_QuestDelay("maze_gate1_down_check", 0.5);
				LAi_QuestDelay("maze_gate2_down_check", 0.5);
				LAi_QuestDelay("maze_F1_check", 0.5);
				LAi_QuestDelay("maze_F2_check", 0.5);
			break;

			case "32":
				//bribing scene
			LAi_SetImmortal(pchar, true);		//temp
				rldGroup = "reload";
				sTeleportLocName = "Grand_Cayman_town";
				rldLocator = "reload15";

				Pchar.estate_direction = "Cayman_town";
			//	Pchar.estate_direction = "Teach_house";		//tour very direct to Teach house
			//	Pchar.estate_direction = "Knight_house";	//tour not finished

				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);
				TakeNItems(PChar, "clock1",1);
				EquipCharacterbyItem(PChar, "clock1");	

				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";

				Pchar.eden_info = "start";
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); AddQuestRecord("Israel_Hands","3");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2"); AddQuestRecord("Charles_Eden","3"); 
				AddQuestRecord("Charles_Eden","4"); AddQuestRecord("Charles_Eden","6"); AddQuestRecord("Charles_Eden","7"); 
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");

				LAi_QuestDelay("maze_gate1_down_check", 0.5);
				LAi_QuestDelay("maze_gate2_down_check", 0.5);
				LAi_QuestDelay("maze_F1_check", 0.5);
				LAi_QuestDelay("maze_F2_check", 0.5);

				LAi_QuestDelay("Eden_bribing_scene", 1.0);
			break;

			case "33":
				//bribing scene, burning ship
			LAi_SetImmortal(pchar, true);		//temp
				rldGroup = "reload";
				sTeleportLocName = "BB_Eden_office";
				rldLocator = "reload2";

				Pchar.estate_direction = "Cayman_town";
			//	Pchar.estate_direction = "Teach_house";		//tour very direct to Teach house
			//	Pchar.estate_direction = "Knight_house";	//tour not finished

				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);
				TakeNItems(PChar, "clock1",1);
				EquipCharacterbyItem(PChar, "clock1");	

				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";

				Pchar.eden_info = "start";
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); AddQuestRecord("Israel_Hands","3");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2"); AddQuestRecord("Charles_Eden","3"); 
				AddQuestRecord("Charles_Eden","4"); AddQuestRecord("Charles_Eden","6"); AddQuestRecord("Charles_Eden","7"); 
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");

				LAi_QuestDelay("maze_gate1_down_check", 0.5);
				LAi_QuestDelay("maze_gate2_down_check", 0.5);
				LAi_QuestDelay("maze_F1_check", 0.5);
				LAi_QuestDelay("maze_F2_check", 0.5);
			
			ChangeCharacterAddressGroup(characterFromID("bb_crew5"), "BB_Eden_estate_wreck", "goto", "B_crew1");	
			ChangeCharacterAddressGroup(characterFromID("Richards"), "BB_Eden_estate_wreck", "goto", "B_crew2");
			ChangeCharacterAddressGroup(characterFromID("Teach"), "BB_Eden_estate_wreck", "goto", "B_teach");
			LAi_SetActorType(characterFromID("Richards"));
			LAi_SetActorType(characterFromID("Teach"));

				LAi_QuestDelay("Eden_bribing_scene62", 1.0);		//from office direct to burning ship
			break;

			case "35":
				//Eden estate to maze
		//LAi_SetImmortal(pchar, true);		//temp
		GiveItem2Character(Pchar, "map");	//temp
				Pchar.quest.disable_rebirth = true;

				rldGroup = "reload";
				sTeleportLocName = "bb_Eden_estate";
				rldLocator = "reload1";

				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				Pchar.estate_direction = "Cayman_town";
			//	Pchar.estate_direction = "Teach_house";		//tour very direct to Teach house
			//	Pchar.estate_direction = "Knight_house";	//tour not finished
			
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);

				Pchar.eden_info = "done";

				LAi_QuestDelay("maze_gate1_down_check", 0.5);
				LAi_QuestDelay("maze_gate2_down_check", 0.5);
				LAi_QuestDelay("maze_F1_check", 0.5);
				LAi_QuestDelay("maze_F2_check", 0.5);
		
				LAi_QuestDelay("Eden_steplocks", 0.1);
			break;
		
			case "43":
				//cave shore to Vane
				
				Pchar.quest.disable_rebirth = true;
				Locations[FindLocation("wr_cave_shore")].models.always.locators = "Shore04_l_JRHsea";	

				sTeleportLocName = "wr_cave_shore";
				rldGroup = "reload";
				rldLocator = "reload2";
				SetCurrentTime(12, 0);
			
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	
		
				Locations[FindLocation("wr_cave_shore")].locators_radius.reload.reload1 = 0.0001;
				locations[FindLocation("wr_cave_shore")].reload.l2.disable = 1;
				locations[FindLocation("wr_cave_shore")].reload.l33.disable = 1;
				locations[FindLocation("wr_cave_shore")].reload.l11.disable = 0;
				locations[FindLocation("wr_cave_shore")].reload.l111.disable = 0;

					GiveItem2Character(Pchar, "map");
					SetModel(PChar, "Howard_Pyle_3", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

					GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
					SetCharacterShipLocation(Pchar, "wr_cave_shore");

				GiveShip2Character(characterFromID("pir_cap2"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap3"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap4"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap5"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap6"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap7"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap8"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap9"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap10"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap12"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap13"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap14"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap15"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap17"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap18"),"obj_invisible","",-1,PIRATE,true,true);
				GiveShip2Character(characterFromID("pir_cap21"),"obj_invisible","",-1,PIRATE,true,true);

				SetCharacterShipLocation(characterFromID("pir_cap1"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap2"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap3"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap4"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap5"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap6"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap7"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap8"), "wr_cave_shore");
			
				SetCharacterShipLocation(characterFromID("pir_cap9"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap10"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap11"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap12"), "wr_cave_shore");
		
				SetCharacterShipLocation(characterFromID("pir_cap13"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap14"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap15"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap16"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap17"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap18"), "wr_cave_shore");
		
				SetCharacterShipLocation(characterFromID("pir_cap19"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap20"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap21"), "wr_cave_shore");
			
				ChangeCharacterAddressGroup(characterFromID("pir_cap2"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap3"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap4"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap5"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap6"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap7"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap8"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap9"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap10"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap11"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap14"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap15"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap16"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap17"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap20"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap21"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap22"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap23"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap24"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap27"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap28"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap29"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap30"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap31"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("pir_cap32"), "none", "", "");
			
					LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);
			break;

			case "45":
				//french surgeons Tortuga
			LAi_SetImmortal(pchar, true);	//temp
				
				sTeleportLocName = "Tortuga_townhall";	//to get JRH loc files from start
				rldGroup = "reload";
				rldLocator = "locator2";
			/*
				sTeleportLocName = "Tortuga_port";
				rldGroup = "reload";
				rldLocator = "reload2_back";
			*/	
				SetCurrentTime(12, 0);
			
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	
				//SetNextWeather("Heavy Storm");

				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade10");
				EquipCharacterByItem(Pchar, "blade10");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);

				SetModel(PChar, "Howard_Pyle_3", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Tortuga_port");

				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); AddQuestRecord("Israel_Hands","3");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2");
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");
				
				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);
			break;

			case "46":
				//tower open Tortuga
			LAi_SetImmortal(pchar, true);	//temp
				
				sTeleportLocName = "Tortuga_townhall";	//to get JRH loc files from start
			//	sTeleportLocName = "Tortuga_tower";
			//	sTeleportLocName = "Tortuga_tower_stairs_B";
				rldGroup = "reload";
			//	rldLocator = "reload1";
				rldLocator = "locator2";
			//	rldLocator = "reloadQ4";
			//	rldLocator = "reload4";
				SetCurrentTime(12, 0);

				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	
				//SetNextWeather("Heavy Storm");

				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade10");
				EquipCharacterByItem(Pchar, "blade10");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);	
				
			Locations[FindLocation("Tortuga_port")].models.day.locators = "Tortuga_l_day_JRH";
			Locations[FindLocation("Tortuga_port")].models.night.locators = "Tortuga_l_night_JRH";
				ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "none", "", "");
				Locations[FindLocation("Tortuga_townhall")].reload.l3.disable = 0;	//tower passage	
				locations[FindLocation("Tortuga_tower_passage")].id.label = "Tower passage";

				LAi_QuestDelay("carriage_girl_end", 0.1);
			break;

			case "47":
				//Richards Cartagena
		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Cartagena_town_02";

				rldGroup = "reload";
				rldLocator = "Falaise_de_fleur_location_02_perechod";

				SetCurrentTime(12, 0);
			//SetCurrentTime(21, 0);
			//SetCurrentTime(9, 0);
			//SetCurrentTime(2, 0);
				SetNextWeather("Clear");
			//	//Pchar.quest.JRH_rain = "Clear";	

				Locations[FindLocation("cloister_exit")].locators_radius.box.box1 = 2.0;	//opens WoodesRogers part
				Pchar.monastary = "Sister_Richards";

				Pchar.quest.tape_found.win_condition.l1 = "item";
				Pchar.quest.tape_found.win_condition.l1.character = Pchar.id;
				Pchar.quest.tape_found.win_condition.l1.item = "tape";
				Pchar.quest.tape_found.win_condition = "tape_found";
	
				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");	
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);

				SetModel(PChar, "Howard_Pyle_4", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Cartagena_port");

				AddPassenger(Pchar, characterFromID("Hands"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Hands"));

				AddPassenger(Pchar, characterFromID("Caesar"), 0);
				SetOfficersIndex(Pchar, 2, getCharacterIndex("Caesar"));
				SetModel(characterFromID("Caesar"), "bb_Caesar", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Caesar"));

				AddPassenger(Pchar, characterFromID("Pell"), 0);
				SetOfficersIndex(Pchar, 3, getCharacterIndex("Pell"));
				SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Pell"));

				int i;
				for(i=1; i<14; i++) AddQuestRecord("Richards", i); 

				pchar.quest.monastary_no_officers.win_condition.l1 = "location";
				pchar.quest.monastary_no_officers.win_condition.l1.location = "cloister_exit";
				pchar.quest.monastary_no_officers.win_condition = "monastary_no_officers";

			break;

			case "49":
				//Cloister fight

		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "BB_graveyard";

				rldGroup = "reload";
				rldLocator = "reload6";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				Locations[FindLocation("cloister_exit")].locators_radius.box.box1 = 2.0;	//opens WoodesRogers part

				SetModel(Pchar, "Howard_Pyle_3", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");	
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);	
				GiveItem2Character(Pchar, "mapBB4C");
				TakeNItems(Pchar,"potionwine2", 2);

				LAi_QuestDelay("abbess_map_given1", 0.1);
			break;

			case "50":
				//Odel Smugglers_Tavern

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Smugglers_Lair";
				rldGroup = "reload";
				rldLocator = "reload6";
				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//these are for testing reasons
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "pistol6");
				EquipCharacterByItem(Pchar, "pistol6");

				AddQuestRecord("Richards","2");
				AddQuestRecord("Israel_Hands","2");
				AddQuestRecord("Blackbeards_crew","2");
			
				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Conceicao_port");

			AddPassenger(Pchar, characterFromID("Hands"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
			SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);

			AddPassenger(Pchar, characterFromID("Caesar"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Caesar"));

			AddPassenger(Pchar, characterFromID("Pell"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Pell"));
			SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
				
				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";
			
			break;

			case "55":
				//Caesar Mayanard Citadel Rock			

			/*	sTeleportLocName = "Eleuthera_tavern_upstairs";
				rldGroup = "reload";
				rldLocator = "reload3_back";		*/

				sTeleportLocName = "Eleuthera_port";
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				LAi_SetImmortal(pchar, true);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade10");
				EquipCharacterByItem(Pchar, "blade10");
				GiveItem2Character(Pchar, "PiratesPistol");
				EquipCharacterByItem(Pchar, "PiratesPistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);

				//GiveItem2Character(Pchar, "bladespade");
				//GiveItem2Character(Pchar, "bladeanchor_big");
				//GiveItem2Character(Pchar, "bladelever");
				


				SetModel(PChar, "Howard_Pyle_3", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Eleuthera_port");

			//	GiveItem2Character(Pchar, "bladelever");	//temp
			//	GiveItem2Character(Pchar, "bladeanchor_big");
			//	EquipCharacterByItem(Pchar, "bladeanchor_big");	

			AddPassenger(Pchar, characterFromID("Hands"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
			SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Hands"));

			AddPassenger(Pchar, characterFromID("Caesar"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Caesar"));
			characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Caesar"));

			AddPassenger(Pchar, characterFromID("Pell"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Pell"));
			SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Pell"));

				GiveItem2Character(characterFromID("Pell"), "blade4");
				EquipCharacterByItem(characterFromID("Pell"), "blade4");
				GiveItem2Character(characterFromID("Pell"), "piratespistol");
				EquipCharacterByItem(characterFromID("Pell"), "piratespistol");
				TakeNItems(characterFromID("Pell"),"gunpowder", 6);
				TakeNItems(characterFromID("Pell"),"pistolbullets", 6);

				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); AddQuestRecord("Israel_Hands","3");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3"); AddQuestRecord("Caesar","4");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2");
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");

				LAi_QuestDelay("Citadel_rock_start", 0.1);
			break;
		
			case "56":
				//Caesar Turks start, to Fort
		LAi_SetImmortal(pchar, true);	//temp
				Pchar.quest.disable_rebirth = true;

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				sTeleportLocName = "Turks_port";
				rldGroup = "reload";
				rldLocator = "reload1";

				SetModel(PChar, "Howard_Pyle_3", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "blade10");
				EquipCharacterByItem(Pchar, "blade10");	
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);	

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Turks_port");

				ChangeCharacterAddressGroup(characterFromID("shipwreck_trader"), "Turks_Fort_Office", "sit", "sit1");
				Locations[FindLocation("Turks_Fort_Office")].locators_radius.sit.sit1 = 2.5;

			AddPassenger(Pchar, characterFromID("Hands"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
			SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Hands"));
		/*
			AddPassenger(Pchar, characterFromID("Caesar"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Caesar"));
			characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Caesar"));

			Pchar.quest.hammer_gp = 0;
			Pchar.killed_wr_officers = 1;
			Pchar.Caesar_info = "yes";

			AddPassenger(Pchar, characterFromID("Pell"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Pell"));
			SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Pell"));

				GiveItem2Character(characterFromID("Pell"), "blade4");
				EquipCharacterByItem(characterFromID("Pell"), "blade4");
				GiveItem2Character(characterFromID("Pell"), "piratespistol");
				EquipCharacterByItem(characterFromID("Pell"), "piratespistol");
				TakeNItems(characterFromID("Pell"),"gunpowder", 6);
				TakeNItems(characterFromID("Pell"),"pistolbullets", 6);
		*/

				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); AddQuestRecord("Israel_Hands","3");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3"); AddQuestRecord("Caesar","4");
				AddQuestRecord("Caesar","5");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2");
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");

				LAi_QuestDelay("Turks_armory", 0.1);

			/*
				//this is done in q_r after gate explosion
				pchar.quest.Turks_steplockM.win_condition.l1 = "locator";
				pchar.quest.Turks_steplockM.win_condition.l1.location = "Turks_port";
				pchar.quest.Turks_steplockM.win_condition.l1.locator_group = "goto";
				pchar.quest.Turks_steplockM.win_condition.l1.locator = "steplockM";
				pchar.quest.Turks_steplockM.win_condition = "Turks_steplockM_1";

				pchar.quest.Turks_steplockR.win_condition.l1 = "locator";
				pchar.quest.Turks_steplockR.win_condition.l1.location = "Turks_port";
				pchar.quest.Turks_steplockR.win_condition.l1.locator_group = "goto";
				pchar.quest.Turks_steplockR.win_condition.l1.locator = "steplockR";
				pchar.quest.Turks_steplockR.win_condition = "Turks_steplockR_1";

				pchar.quest.Turks_steplockL.win_condition.l1 = "locator";
				pchar.quest.Turks_steplockL.win_condition.l1.location = "Turks_port";
				pchar.quest.Turks_steplockL.win_condition.l1.locator_group = "goto";
				pchar.quest.Turks_steplockL.win_condition.l1.locator = "steplockL";
				pchar.quest.Turks_steplockL.win_condition = "Turks_steplockL_1";

				pchar.quest.Turks_watergate.win_condition.l1 = "locator";
				pchar.quest.Turks_watergate.win_condition.l1.location = "Turks_port";
				pchar.quest.Turks_watergate.win_condition.l1.locator_group = "goto";
				pchar.quest.Turks_watergate.win_condition.l1.locator = "waterstop";
				pchar.quest.Turks_watergate.win_condition = "Turks_watergate";

				pchar.quest.fall_to_sewer.win_condition.l1 = "location";
				pchar.quest.fall_to_sewer.win_condition.l1.location = "Turks_sewer";
				pchar.quest.fall_to_sewer.win_condition = "fall_to_sewer";
			*/
			break;

			case "57":
				//Caesar Turks roof tour
		//	LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;
				locations[FindLocation("Turks_port")].type = "silent_seashore";
				Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_KR_closed";

				sTeleportLocName = "Turks_tavern_bedroom";
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				SetModel(PChar, "Howard_Pyle_3", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			//	SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);	//testing as the last mission

				GiveItem2Character(Pchar, "blade10");
				EquipCharacterByItem(Pchar, "blade10");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "map");

				Locations[FindLocation("Turks_tavern_kitchen")].reload.l5.disable = 0;

			AddPassenger(Pchar, characterFromID("Hands"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
			SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Hands"));

			AddPassenger(Pchar, characterFromID("Caesar"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Caesar"));
			characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Caesar"));

			AddPassenger(Pchar, characterFromID("Pell"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Pell"));
			SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Pell"));

				Pchar.quest.hammer_gp = 0;
				Pchar.killed_wr_officers = 1;
			//	Pchar.killed_wr_officers = 3;		//testing as the last mission
				Pchar.Caesar_info = "yes";
	
				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); AddQuestRecord("Israel_Hands","3");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3"); AddQuestRecord("Caesar","4");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2");
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");


				pchar.quest.Turks_enemy0.win_condition.l1 = "locator";
				pchar.quest.Turks_enemy0.win_condition.l1.location = "Turks_port";
				pchar.quest.Turks_enemy0.win_condition.l1.locator_group = "quest";
				pchar.quest.Turks_enemy0.win_condition.l1.locator = "shot1";
				pchar.quest.Turks_enemy0.win_condition = "Turks_enemy0";

				LAi_QuestDelay("Turks_roofs", 0.1);
			break;

			case "58":
				//Caesar Turks cave
		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;
		locations[FindLocation("Turks_port")].type = "silent_seashore";
		Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_KR_closed";
	
				sTeleportLocName = "Turks_port";
				rldGroup = "reload";
				rldLocator = "reload_sewer";
			//	rldLocator = "reload1";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "map");	

				Locations[FindLocation("Turks_tavern_kitchen")].reload.l5.disable = 0;
				Locations[FindLocation("Turks_port")].models.day.charactersPatch = "Margarita_patch_roof";
				Locations[FindLocation("Turks_port")].models.night.charactersPatch = "Margarita_patch_roof";

				AddPassenger(Pchar, characterFromID("Hands"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Hands"));

				AddPassenger(Pchar, characterFromID("Caesar"), 0);
				SetOfficersIndex(Pchar, 2, getCharacterIndex("Caesar"));
				characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Caesar"));

				AddPassenger(Pchar, characterFromID("Pell"), 0);
				SetOfficersIndex(Pchar, 3, getCharacterIndex("Pell"));
				SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Pell"));

				Pchar.quest.hammer_gp = 0;
				Pchar.killed_wr_officers = 1;
				Pchar.Caesar_info = "yes";

				pchar.quest.Turks_steplockM.win_condition.l1 = "locator";
				pchar.quest.Turks_steplockM.win_condition.l1.location = "Turks_port";
				pchar.quest.Turks_steplockM.win_condition.l1.locator_group = "goto";
				pchar.quest.Turks_steplockM.win_condition.l1.locator = "steplockM";
				pchar.quest.Turks_steplockM.win_condition = "Turks_steplockM_1";

				pchar.quest.Turks_steplockR.win_condition.l1 = "locator";
				pchar.quest.Turks_steplockR.win_condition.l1.location = "Turks_port";
				pchar.quest.Turks_steplockR.win_condition.l1.locator_group = "goto";
				pchar.quest.Turks_steplockR.win_condition.l1.locator = "steplockR";
				pchar.quest.Turks_steplockR.win_condition = "Turks_steplockR_1";

				pchar.quest.Turks_steplockL.win_condition.l1 = "locator";
				pchar.quest.Turks_steplockL.win_condition.l1.location = "Turks_port";
				pchar.quest.Turks_steplockL.win_condition.l1.locator_group = "goto";
				pchar.quest.Turks_steplockL.win_condition.l1.locator = "steplockL";
				pchar.quest.Turks_steplockL.win_condition = "Turks_steplockL_1";

				pchar.quest.Turks_watergate.win_condition.l1 = "locator";
				pchar.quest.Turks_watergate.win_condition.l1.location = "Turks_port";
				pchar.quest.Turks_watergate.win_condition.l1.locator_group = "goto";
				pchar.quest.Turks_watergate.win_condition.l1.locator = "waterstop";
				pchar.quest.Turks_watergate.win_condition = "Turks_watergate";

				pchar.quest.fall_to_sewer.win_condition.l1 = "location";
				pchar.quest.fall_to_sewer.win_condition.l1.location = "Turks_sewer";
				pchar.quest.fall_to_sewer.win_condition = "fall_to_sewer";
			break;

			case "59":
				//Turks wreck shore
		//LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				rldGroup = "reload";
				rldLocator = "reload1";
			//	sTeleportLocName = "Turks_wreck_shore";
				sTeleportLocName = "Turks_sewer";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");	
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "map");

				ChangeCharacterAddressGroup(characterFromID("shipwreck_trader"), "Turks_wreck_shore", "goto", "goto3");//temp for the icons
				LAi_SetStayType(characterFromID("shipwreck_trader"));
				Pchar.quest.hammer_gp = 0;
				Pchar.killed_wr_officers = 1;
				Pchar.Caesar_info = "yes";

				LAi_QuestDelay("fall_to_sewer3", 0.1);
			break;

			case "60":
				//Hands Willemstad port Curacao
		//LAi_SetImmortal(pchar, true);	//Pchar as Hands will be shot so not immortal for this

				Pchar.quest.disable_rebirth = true;

				rldGroup = "reload";
			//	rldLocator = "sea";
				rldLocator = "reload7";
			//	sTeleportLocName = "Willemstad_port";
				sTeleportLocName = "Willemstad_town_3";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				SetModel(PChar, "Howard_Pyle_4", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");	
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "map");

				Pchar.killed_wr_officers = 1;
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
				Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
				LAi_SetPoorType(CharacterFromID("Hands"));
				ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");

				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); 
				//from reading HOP (items.c)
				Pchar.book72_handsL = "read";
				AddQuestRecord("Israel_Hands", "3");

				LAi_QuestDelay("start_Hands_Willemstad", 0.1);
			break;

			case "62":
				//Charleston Maltains
		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Charlestown_port";
			
				rldGroup = "reload";
				rldLocator = "reload8_back";

				//SetCurrentTime(12, 0);		//closed to Maltains
			SetCurrentTime(2, 0);				//open to Maltains if info from Hands (given in "start_Maltains" below)
				//SetNextWeather("Clear");
			SetNextWeather("Heavy Rain");

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				EquipCharacterByItem(Pchar, "bladeX4");
			//	GiveItem2Character(Pchar, "key34");
			//	GiveItem2Character(Pchar, "bladekeyring");
			//	EquipCharacterByItem(Pchar, "bladekeyring");

			//GiveItem2Character(Pchar, "blade1");
			//GiveItem2Character(Pchar, "clock1");
			//EquipCharacterByItem(Pchar, "clock1");

			//Locations[FindLocation("bb_Maltains")].locators_radius.reload.reload2 = 0.0001;	//testing
			//Locations[FindLocation("bb_Maltains")].locators_radius.box.box21 = 1.0; //testing

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Charlestown_port");
					
				AddCharacterGoods(Pchar, GOOD_WHEAT, 1);
				AddCharacterGoods(Pchar, GOOD_RUM, 1);
				AddCharacterGoods(Pchar, GOOD_BALLS, 1);
				AddCharacterGoods(Pchar, GOOD_KNIPPELS, 1);
				AddCharacterGoods(Pchar, GOOD_BOMBS, 1);
				AddCharacterGoods(Pchar, GOOD_GUNPOWDER, 1);
				AddCharacterGoods(Pchar, GOOD_SAILCLOTH, 1);
				AddCharacterGoods(Pchar, GOOD_PLANKS, 1);
				AddCharacterGoods(Pchar, GOOD_GOLD, 1);
				AddCharacterGoods(Pchar, GOOD_SILVER, 1);
				AddCharacterGoods(Pchar, GOOD_CINNAMON, 1);
				AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 1);
				AddCharacterGoods(Pchar, GOOD_COFFEE, 1);
				AddCharacterGoods(Pchar, GOOD_FOOD, 1);
				AddCharacterGoods(Pchar, GOOD_TREATMENT, 1);
				AddCharacterGoods(Pchar, GOOD_PAPRIKA, 1);
				AddCharacterGoods(Pchar, GOOD_WINE, 1);
				AddCharacterGoods(Pchar, GOOD_SANDAL, 1);
				AddCharacterGoods(Pchar, GOOD_EBONY, 1);
				AddCharacterGoods(Pchar, GOOD_MAHOGANY, 1);
				AddCharacterGoods(Pchar, GOOD_SUGAR, 1);
				AddCharacterGoods(Pchar, GOOD_TOBACCO, 1);
				AddCharacterGoods(Pchar, GOOD_ALE, 1);
				AddCharacterGoods(Pchar, GOOD_SILK, 1);
				AddCharacterGoods(Pchar, GOOD_LINEN, 1);
				AddCharacterGoods(Pchar, GOOD_FRUITS, 1);
				AddCharacterGoods(Pchar, GOOD_CLOTHES, 1);
				AddCharacterGoods(Pchar, GOOD_BRICKS, 1);
				AddCharacterGoods(Pchar, GOOD_OIL, 1);
				AddCharacterGoods(Pchar, GOOD_COTTON, 1);
				AddCharacterGoods(Pchar, GOOD_COPRA, 1);
				AddCharacterGoods(Pchar, GOOD_LEATHER, 1);
				
				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); 
				AddQuestRecord("Israel_Hands","3"); AddQuestRecord("Israel_Hands","4");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2");
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");

				LAi_QuestDelay("start_Maltains", 0.1);
			break;

			case "63":
				//Hands Antigua port - fort - prison
		//LAi_SetImmortal(pchar, true);	//temp
		//AddMoneyToCharacter(Pchar, 100000); //temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Antigua_port";
				rldGroup = "reload";
				rldLocator = "reload5_back";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
			
				AddMoneyToCharacter(Pchar,-10000);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade10");
				EquipCharacterByItem(Pchar, "blade10");
			/*	GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);		*/
				GiveItem2Character(Pchar, "doc61");
				TakeNItems(Pchar,"medical1", 1);

				SetModel(PChar, "Howard_Pyle_4", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Antigua_port");

				AddPassenger(Pchar, characterFromID("Hands"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Hands"));

			//could be here or not yet found
			AddPassenger(Pchar, characterFromID("Caesar"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Caesar"));
			SetModel(characterFromID("Caesar"), "bb_Caesar", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Caesar"));

				AddQuestRecord("Israel_Hands","1"); AddQuestRecord("Israel_Hands","2"); AddQuestRecord("Israel_Hands","3");
				AddQuestRecord("Israel_Hands","4"); AddQuestRecord("Israel_Hands","5");
				AddQuestRecord("Blackbeards_crew","1"); AddQuestRecord("Blackbeards_crew","2"); AddQuestRecord("Blackbeards_crew","3");
				AddQuestRecord("Benjamin_Hornigold","1"); AddQuestRecord("Benjamin_Hornigold","2"); CloseQuestHeader("Benjamin_Hornigold");
				AddQuestRecord("Caesar","1"); AddQuestRecord("Caesar","2"); AddQuestRecord("Caesar","3");
				AddQuestRecord("Charles_Eden","1"); AddQuestRecord("Charles_Eden","2");
				AddQuestRecord("Johnson","1"); AddQuestRecord("Johnson","2");
				AddQuestRecord("Richards","1"); AddQuestRecord("Richards","2");

				//this enables the prison tour
				locations[FindLocation("Antigua_port")].models.always.locators = "StJohns_locators_JRH";

				//this is only for testing prison escape route
			//	locations[FindLocation("Antigua_port")].models.always.locators = "StJohns_locators_JRH2";

				LAi_QuestDelay("prison_info_done5", 0.1);
			break;

			case "64":
				//Hands prison port - alcove - (POTC dungeons)
		//LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "bb_prison_port";
				rldGroup = "reload";
				rldLocator = "reload2";

				//SetCurrentTime(18, 0);
			SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(PChar, "Howard_Pyle_3", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "doc61");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);
				TakeNItems(Pchar,"mecical1", 1);

				LAi_QuestDelay("prison_info_done5", 0.1);
			break;

			case "66":
				//Hands alcove etc
		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "bb_prison_alcove";
			
				rldGroup = "reload";
				rldLocator = "reload2";

				//SetCurrentTime(18, 0);
			SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

			//GiveItem2Character(Pchar, "bladesaw");
			//GiveItem2Character(Pchar, "tool5");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "blade10");
				EquipCharacterByItem(Pchar, "blade10");
				GiveItem2Character(Pchar, "doc61");
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);
				TakeNItems(Pchar,"medical1", 1);

				SetModel(PChar, "Howard_Pyle_3", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				Pchar.quest.prison_pier = "phase0";
				Pchar.quest.prison_elevator = "down";
				Pchar.quest.prison_opening = "stairs";
				Pchar.quest.prison_opening2 = "prison";

				pchar.quest.bb_prison_opening.win_condition.l1 = "locator";
				pchar.quest.bb_prison_opening.win_condition.l1.location = "bb_prison2";
				pchar.quest.bb_prison_opening.win_condition.l1.locator_group = "goto";
				pchar.quest.bb_prison_opening.win_condition.l1.locator = "opening";
				pchar.quest.bb_prison_opening.win_condition = "bb_prison_opening";

				pchar.quest.bb_prison_opening2.win_condition.l1 = "locator";
				pchar.quest.bb_prison_opening2.win_condition.l1.location = "bb_prison2";
				pchar.quest.bb_prison_opening2.win_condition.l1.locator_group = "goto";
				pchar.quest.bb_prison_opening2.win_condition.l1.locator = "opening2";
				pchar.quest.bb_prison_opening2.win_condition = "bb_prison_opening2";

				pchar.quest.alcove_box5.win_condition.l1 = "locator";
				pchar.quest.alcove_box5.win_condition.l1.location = "bb_prison_alcove";
				pchar.quest.alcove_box5.win_condition.l1.locator_group = "box";
				pchar.quest.alcove_box5.win_condition.l1.locator = "box5";
				pchar.quest.alcove_box5.win_condition = "alcove_box5";

				pchar.quest.alcove_stop1.win_condition.l1 = "locator";
				pchar.quest.alcove_stop1.win_condition.l1.location = "bb_prison_alcove";
				pchar.quest.alcove_stop1.win_condition.l1.locator_group = "goto";
				pchar.quest.alcove_stop1.win_condition.l1.locator = "stop1";
				pchar.quest.alcove_stop1.win_condition = "alcove_stop1";

				pchar.quest.alcove_stop2.win_condition.l1 = "locator";
				pchar.quest.alcove_stop2.win_condition.l1.location = "bb_prison_alcove";
				pchar.quest.alcove_stop2.win_condition.l1.locator_group = "goto";
				pchar.quest.alcove_stop2.win_condition.l1.locator = "stop2";
				pchar.quest.alcove_stop2.win_condition = "alcove_stop2";

				pchar.quest.alcove_stop3.win_condition.l1 = "locator";
				pchar.quest.alcove_stop3.win_condition.l1.location = "bb_prison_alcove";
				pchar.quest.alcove_stop3.win_condition.l1.locator_group = "goto";
				pchar.quest.alcove_stop3.win_condition.l1.locator = "stop3";
				pchar.quest.alcove_stop3.win_condition = "alcove_stop3";

				pchar.quest.alcove_stop4.win_condition.l1 = "locator";
				pchar.quest.alcove_stop4.win_condition.l1.location = "bb_prison_alcove";
				pchar.quest.alcove_stop4.win_condition.l1.locator_group = "goto";
				pchar.quest.alcove_stop4.win_condition.l1.locator = "stop4";
				pchar.quest.alcove_stop4.win_condition = "alcove_stop4";

				pchar.quest.alcove_stop5.win_condition.l1 = "locator";
				pchar.quest.alcove_stop5.win_condition.l1.location = "bb_prison_alcove";
				pchar.quest.alcove_stop5.win_condition.l1.locator_group = "goto";
				pchar.quest.alcove_stop5.win_condition.l1.locator = "stop5";
				pchar.quest.alcove_stop5.win_condition = "alcove_stop5";

				pchar.quest.alcove_stop6.win_condition.l1 = "locator";
				pchar.quest.alcove_stop6.win_condition.l1.location = "bb_prison_alcove";
				pchar.quest.alcove_stop6.win_condition.l1.locator_group = "goto";
				pchar.quest.alcove_stop6.win_condition.l1.locator = "stop6";
				pchar.quest.alcove_stop6.win_condition = "alcove_stop6";
			break;

			case "68":
				//Hands prison2
		//LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "bb_prison2";
			
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(20, 0);
			//	SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	
			//SetNextWeather("Heavy Storm");//temp test

				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				GiveItem2Character(Pchar, "piratespistol");
				
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);
				TakeNItems(Pchar,"cognac", 2);
				GiveItem2Character(Pchar, "pistol203");
				GiveItem2Character(Pchar, "ammobag1");
				GiveItem2Character(Pchar, "bladeA4");
				GiveItem2Character(Pchar, "doctortoolkit");
				TakeNItems(Pchar,"medical1", 1);
			//GiveItem2Character(Pchar, "key38");
			//GiveItem2Character(Pchar, "bladehammer");
			//GiveItem2Character(Pchar, "bladesaw");
			//GiveItem2Character(Pchar, "bladeaxe4");
			//GiveItem2Character(Pchar, "map");			//temp

				EquipCharacterByItem(Pchar, "bladeA4");
				EquipCharacterByItem(Pchar, "pistol203");

				SetModel(PChar, "Howard_Pyle_3", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				Pchar.quest.prison_pier = "phase0";
				Pchar.quest.prison_elevator = "down";
				Pchar.quest.prison_opening = "stairs";
				Pchar.quest.prison_opening2 = "prison";

				pchar.quest.bb_prison_opening.win_condition.l1 = "locator";
				pchar.quest.bb_prison_opening.win_condition.l1.location = "bb_prison2";
				pchar.quest.bb_prison_opening.win_condition.l1.locator_group = "goto";
				pchar.quest.bb_prison_opening.win_condition.l1.locator = "opening";
				pchar.quest.bb_prison_opening.win_condition = "bb_prison_opening";

				pchar.quest.bb_prison_opening2.win_condition.l1 = "locator";
				pchar.quest.bb_prison_opening2.win_condition.l1.location = "bb_prison2";
				pchar.quest.bb_prison_opening2.win_condition.l1.locator_group = "goto";
				pchar.quest.bb_prison_opening2.win_condition.l1.locator = "opening2";
				pchar.quest.bb_prison_opening2.win_condition = "bb_prison_opening2";
			
				LAi_QuestDelay("prison_info_done5", 0.1);
				LAi_QuestDelay("prison2_tools3_check", 0.5);			
			break;

			case "80":
				//Kristiania Canyon

		//LAi_SetImmortal(pchar, true);	//temp
				SetNextWind("W",30);			//good for visible ship flags
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Kristiania_canyon";
			//	sTeleportLocName = "Kristiania_center2";
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(12, 0);
			//SetCurrentTime(2, 0);
			//SetCurrentTime(19, 0);			//testing bad randitems
			//SetCurrentTime(7, 0);			//testing bad randitems
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	
		//SetNextWeather("Heavy Rain");
		//Pchar.quest.JRH_rain = "Heavy Rain";

				SetModel(PChar, "Howard_Pyle_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			//	ChangeCharacterAddressGroup(CharacterFromID("Teach"), "BB_island1", "goto", "citizen03");			
				
				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;

				AddMoneyToCharacter(Pchar, 1000);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
			//	GiveItem2Character(Pchar, "bladelever3");
			//	EquipCharacterByItem(Pchar, "bladelever3");
			//	GiveItem2Character(Pchar, "pistolbelt");
			//	EquipCharacterByItem(Pchar, "pistolbelt");
				GiveItem2Character(Pchar, "pistol20");
				EquipCharacterByItem(Pchar, "pistol20");
				GiveItem2Character(Pchar, "ammobag2");
				EquipCharacterByItem(Pchar, "ammobag2");
				TakeNItems(Pchar,"gunpowder", 18);
				TakeNItems(Pchar,"pistolbullets", 18);

				TakeNItems(Pchar,"incense", 6);		//total 12
				TakeNItems(Pchar,"myrrh", 3);		//total 4
			//	LAi_SetHP(Pchar, 80.0, 80.0);
				
				AddCharacterGoods(Pchar, GOOD_COTTON, 1);
				AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 145);
				AddCharacterGoods(Pchar, GOOD_SUGAR, 250);
	
			AddPassenger(Pchar, characterFromID("Hands"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
			SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Hands"));
			TakeNItems(characterFromID("Hands"),"pistol206", -1);				//double pistols for some reason

			AddPassenger(Pchar, characterFromID("Caesar"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Caesar"));
			characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Caesar"));
			TakeNItems(characterFromID("Caesar"),"pistol202", -1);				//double pistols for some reason

			AddPassenger(Pchar, characterFromID("Pell"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Pell"));
			SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Pell"));

			GiveItem2Character(characterFromID("Pell"), "blade4");
			EquipCharacterByItem(characterFromID("Pell"), "blade4");
			GiveItem2Character(characterFromID("Pell"), "piratespistol");
			EquipCharacterByItem(characterFromID("Pell"), "piratespistol");
			TakeNItems(characterFromID("Pell"),"gunpowder", 6);
			TakeNItems(characterFromID("Pell"),"pistolbullets", 6);
	
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");

				//these 4 to start_Kristiania
				//LAi_QuestDelay("KR_center_backloop1", 0.1);
				//LAi_QuestDelay("KR_center_backloop2", 0.1);
				//LAi_QuestDelay("KR_lower_backloop", 0.1);
				//LAi_QuestDelay("NS_locked_shipyard_start", 0.1);

				LAi_QuestDelay("start_Kristiania", 0.1);

				//these 8 to fort_unlock2
				//LAi_QuestDelay("BB_tower_top_backloop", 0.1);
				//LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				//LAi_QuestDelay("BB_lower_cave_backloop", 0.1);
				//LAi_QuestDelay("start_BB_flag", 0.1);
				//LAi_QuestDelay("pick_up_grotto_boom", 0.1);
				//LAi_QuestDelay("BB_lower_cave_steplock", 0.1);
				//LAi_QuestDelay("BB_lower_cave_deathtrap", 0.1);
				//LAi_QuestDelay("BB_tower_backloop", 0.1);	//no, always "on", only locator changes in size

			break;

			case "82":
				//Nueva_Suecia_upper_town
		
	//	Pchar.cardinal = "start";
		LAi_SetImmortal(pchar, true);	//temp
				SetNextWind("W",30);			//good for visible ship flags
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Nueva_Suecia_upper_town";
				rldGroup = "reload";
				rldLocator = "reload11";

				SetCurrentTime(12, 0);
			//	SetCurrentTime(2, 0);
			//	SetCurrentTime(8, 0);
			//	SetCurrentTime(20, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "map");			
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
			GiveItem2Character(pchar, "switch_button");
			//GiveItem2Character(pchar, "auction_list_roll");

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");

				AddCharacterGoods(Pchar, GOOD_COTTON, 1);
				AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 145);
				AddCharacterGoods(Pchar, GOOD_SUGAR, 250);
	
				LAi_QuestDelay("KR_center_backloop1", 0.1);
				LAi_QuestDelay("KR_center_backloop2", 0.1);
				LAi_QuestDelay("KR_lower_backloop", 0.1);

				LAi_QuestDelay("BB_tower_top_backloop", 0.1);
			LAi_QuestDelay("BB_tower_backloop", 0.1);	//no, always "on", only locator changes in size
				
				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				LAi_QuestDelay("BB_lower_cave_backloop", 0.1);

				LAi_QuestDelay("NS_locked_shipyard_start", 0.1);
			LAi_QuestDelay("start_BB_flag", 0.1);
			
				pchar.quest.see_oriel.win_condition.l1 = "locator";
				pchar.quest.see_oriel.win_condition.l1.location = "Nueva_Suecia_upper_town";
				pchar.quest.see_oriel.win_condition.l1.locator_group = "quest";
				pchar.quest.see_oriel.win_condition.l1.locator = "see_oriel";
				pchar.quest.see_oriel.win_condition = "see_oriel";
			break;

			case "83":
				//Nueva_Suecia_lower_town
		
				Pchar.cardinal = "start";
		//LAi_SetImmortal(pchar, true);	//temp
				SetNextWind("W",30);			//good for visible ship flags
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Nueva_Suecia_lower_town";
				rldGroup = "reload";
				rldLocator = "reload32";

				SetCurrentTime(12, 0);
			//	SetCurrentTime(2, 0);
			//	SetCurrentTime(8, 0);
			//	SetCurrentTime(20, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "map");			
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
			//GiveItem2Character(pchar, "switch_button");

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");

				AddCharacterGoods(Pchar, GOOD_COTTON, 1);
				AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 145);
				AddCharacterGoods(Pchar, GOOD_SUGAR, 250);
	
				LAi_QuestDelay("KR_center_backloop1", 0.1);
				LAi_QuestDelay("KR_center_backloop2", 0.1);
				LAi_QuestDelay("KR_lower_backloop", 0.1);

				LAi_QuestDelay("BB_tower_top_backloop", 0.1);
			LAi_QuestDelay("BB_tower_backloop", 0.1);	//no, always "on", only locator changes in size
				
				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				LAi_QuestDelay("BB_lower_cave_backloop", 0.1);

				LAi_QuestDelay("NS_locked_shipyard_start", 0.1);
		LAi_QuestDelay("start_BB_flag", 0.1);
			break;

			case "84":
				//Kristiania_jungle_exit
			
			LAi_SetImmortal(pchar, true);	//temp

				sTeleportLocName = "Kristiania_jungle_exit";
				rldGroup = "reload";
				rldLocator = "reload3";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";

			GiveItem2Character(Pchar, "tailors_note");

			Pchar.jungle_path = "know_how";
			AddQuestRecord("KR_logbook","5");

			//now the way to the red house is enabled
			Locations[FindLocation("KR_jungle_8")].reload.l3.go = "KR_jungle_13";
			Locations[FindLocation("KR_jungle_8")].reload.l3.emerge = "reload3";
			Locations[FindLocation("KR_jungle_8")].reload.l5.go = "KR_jungle_13";
			Locations[FindLocation("KR_jungle_8")].reload.l5.emerge = "reload3";

			Locations[FindLocation("KR_jungle_10")].reload.l1.go = "KR_jungle_13";
			Locations[FindLocation("KR_jungle_10")].reload.l1.emerge = "reload1";
			Locations[FindLocation("KR_jungle_10")].reload.l6.go = "KR_jungle_13";
			Locations[FindLocation("KR_jungle_10")].reload.l6.emerge = "reload1";

			pchar.quest.check_logbook.win_condition.l1 = "location";
			pchar.quest.check_logbook.win_condition.l1.location = "Redhouse_room";
			pchar.quest.check_logbook.win_condition = "check_logbook";

			pchar.quest.KR_indian_ambush.win_condition.l1 = "locator";
			pchar.quest.KR_indian_ambush.win_condition.l1.location = "KR_jungle_9";
			pchar.quest.KR_indian_ambush.win_condition.l1.locator_group = "goto";
			pchar.quest.KR_indian_ambush.win_condition.l1.locator = "box9";
			pchar.quest.KR_indian_ambush.win_condition = "KR_indian_ambush";

				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				
				GiveItem2Character(Pchar, "map");
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");
			break;

			case "85":
				//indian village
		//	LAi_SetImmortal(pchar, true);	//temp
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "KR_jungle_4";
				rldGroup = "reload";
				rldLocator = "reload2";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "map");

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");

				LAi_QuestDelay("KR_indian_ambush_start", 0.1);
			break;			

			case "86":
				//Red House

		//LAi_SetImmortal(pchar, true);	//temp
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Kristiania_jungle_house";
				rldGroup = "reload";
				rldLocator = "reload1";

			//	SetCurrentTime(2, 0);
				SetCurrentTime(12, 0);
			//	SetCurrentTime(20, 0);
			//	SetCurrentTime(8, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "map");			
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
		GiveItem2Character(Pchar, "tailors_book");

				AddCharacterGoods(Pchar, GOOD_COTTON, 1);
				AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 145);
				AddCharacterGoods(Pchar, GOOD_SUGAR, 250);

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");
				
				LAi_QuestDelay("KR_center_backloop1", 0.1);
				LAi_QuestDelay("KR_center_backloop2", 0.1);
				LAi_QuestDelay("KR_lower_backloop", 0.1);

				LAi_QuestDelay("BB_tower_top_backloop", 0.1);
			LAi_QuestDelay("BB_tower_backloop", 0.1);	//no, always "on", only locator changes in size
				
				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				LAi_QuestDelay("BB_lower_cave_backloop", 0.1);
			break;

			case "90":
				//Q2: BB_island1
		
			//LAi_SetImmortal(pchar, true);		//temp
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "BB_island1";
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	
				
				SetModel(PChar, "Howard_Pyle_hat_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1"); 
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "ammobag2");
				EquipCharacterByItem(Pchar, "ammobag2");
				GiveItem2Character(Pchar, "BB_hatA2");
				EquipCharacterByItem(Pchar, "BB_hatA2");
				GiveItem2Character(Pchar, "pistol20");
				EquipCharacterByItem(Pchar, "pistol20");
				GiveItem2Character(Pchar, "bladeBB"); 
				EquipCharacterbyItem(Pchar, "bladeBB");
				GiveItem2Character(Pchar, "pistolbladeBB"); 
				EquipCharacterbyItem(Pchar, "pistolbladeBB");
				GiveItem2Character(Pchar, "flagchest_closed"); 
				GiveItem2Character(Pchar, "BB_coin");
				GiveItem2Character(Pchar, "book69A");
				GiveItem2Character(Pchar, "BB_key");
				GiveItem2Character(Pchar, "doc60A");
				TakeNItems(Pchar,"pistolbullets", 18);
				TakeNItems(Pchar,"gunpowder", 18);

				TakeNItems(Pchar,"incense", 12);
				TakeNItems(Pchar,"myrrh", 4);
			
				Pchar.skill.Defence = "5";

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
				
				//ChangeCharacterAddressGroup(CharacterFromID("Teach"), "BB_island1", "goto", "citizen03");

			AddPassenger(Pchar, characterFromID("Hands"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
			SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Hands"));

			AddPassenger(Pchar, characterFromID("Caesar"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Caesar"));
			characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Caesar"));

			AddPassenger(Pchar, characterFromID("Pell"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Pell"));
			SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Pell"));

			GiveItem2Character(characterFromID("Pell"), "blade4");
			EquipCharacterByItem(characterFromID("Pell"), "blade4");
			GiveItem2Character(characterFromID("Pell"), "piratespistol");
			EquipCharacterByItem(characterFromID("Pell"), "piratespistol");
			TakeNItems(characterFromID("Pell"),"gunpowder", 6);
			TakeNItems(characterFromID("Pell"),"pistolbullets", 6);
				
				AddMoneyToCharacter(Pchar,-10000);

				AddCharacterGoods(Pchar, GOOD_GOLD, 1);
				AddCharacterGoods(Pchar, GOOD_SILVER, 1);

				AddCharacterGoods(Pchar, GOOD_COTTON, 1);
				AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 145);
				AddCharacterGoods(Pchar, GOOD_SUGAR, 250);

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");
			
		//	Pchar.quest.grotto_lever = "up";			//testing off now	
				
				LAi_QuestDelay("KR_center_backloop1", 0.1);
				LAi_QuestDelay("KR_center_backloop2", 0.1);
				LAi_QuestDelay("BB_tower_top_backloop", 0.1);
				LAi_QuestDelay("BB_tower_backloop", 0.1);	//always "on", only locator changes in size
				
				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				LAi_QuestDelay("BB_lower_cave_backloop", 0.1);
				LAi_QuestDelay("pick_up_grotto_boom", 0.1);
				LAi_QuestDelay("BB_lower_cave_steplock", 0.1);
				LAi_QuestDelay("BB_lower_cave_deathtrap", 0.1);
				LAi_QuestDelay("start_BB_flag", 0.1);
			break;

			case "92":
				//Q2: BB tower top
		
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "BB_tower";
				rldGroup = "reload";
				rldLocator = "reload6";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	
				
				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				ChangeCharacterAddressGroup(CharacterFromID("Teach"), "BB_tower", "goto", "goto4");

			Pchar.boat.islet = "ready";				//testing
			
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladelever3");		
				EquipCharacterbyItem(Pchar, "bladelever3");
				GiveItem2Character(Pchar, "bladeflag_pir"); 
				GiveItem2Character(Pchar, "bladeflag_pir2");
				GiveItem2Character(Pchar, "bladeflag_HOL"); 
				GiveItem2Character(Pchar, "bladeflag_ENG");
				GiveItem2Character(Pchar, "bladeflag_FRA"); 
				GiveItem2Character(Pchar, "bladeflag_POR");
				GiveItem2Character(Pchar, "bladeflag_SPA"); 
				GiveItem2Character(Pchar, "bladeflag_PRE");
				GiveItem2Character(Pchar, "bladeflag_IRE"); 
				GiveItem2Character(Pchar, "bladeflag_SWE");
				GiveItem2Character(Pchar, "bladeflag_HOL2"); 
				GiveItem2Character(Pchar, "bladeflag_AME");
				GiveItem2Character(Pchar, "bladeflag_SPA2"); 
				GiveItem2Character(Pchar, "BB_coin"); 
				
				AddMoneyToCharacter(Pchar,-10000);

				AddCharacterGoods(Pchar, GOOD_GOLD, 1);
				AddCharacterGoods(Pchar, GOOD_SILVER, 1);

				AddCharacterGoods(Pchar, GOOD_COTTON, 1);
				AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 145);
				AddCharacterGoods(Pchar, GOOD_SUGAR, 250);
				
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");
				
				LAi_QuestDelay("KR_center_backloop1", 0.1);
				LAi_QuestDelay("KR_center_backloop2", 0.1);
				LAi_QuestDelay("BB_tower_top_backloop", 0.1);
				LAi_QuestDelay("BB_tower_backloop", 0.1);	//always "on", only locator changes in size
				
				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				LAi_QuestDelay("BB_lower_cave_backloop", 0.1);
				LAi_QuestDelay("pick_up_grotto_boom", 0.1);
				LAi_QuestDelay("BB_lower_cave_steplock", 0.1);
				LAi_QuestDelay("BB_lower_cave_deathtrap", 0.1);

				LAi_QuestDelay("start_BB_flag", 0.1);
			break;

			case "97":
				//Q2: BB Isle
		
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "BB_isle";
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(PChar, "Howard_Pyle_hat_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "map");
			//	GiveItem2Character(Pchar, "pistolbelt");
			//	EquipCharacterByItem(Pchar, "pistolbelt");
				GiveItem2Character(Pchar, "pistol20");
				EquipCharacterByItem(Pchar, "pistol20");
				GiveItem2Character(Pchar, "ammobag2");
				EquipCharacterByItem(Pchar, "ammobag2");
				GiveItem2Character(Pchar, "BB_hatA2");
				EquipCharacterByItem(Pchar, "BB_hatA2");
				GiveItem2Character(Pchar, "BB_coin"); 
				EquipCharacterByItem(Pchar, "BB_coin");

				GiveItem2Character(Pchar, "book69A");
				GiveItem2Character(Pchar, "BB_key");

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");

				LAi_QuestDelay("KR_center_backloop1", 0.1);
				LAi_QuestDelay("KR_center_backloop2", 0.1);
				LAi_QuestDelay("BB_tower_top_backloop", 0.1);
			LAi_QuestDelay("BB_tower_backloop", 0.1);	//no, always "on", only locator changes in size
				
				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				LAi_QuestDelay("BB_lower_cave_backloop", 0.1);
				LAi_QuestDelay("pick_up_grotto_boom", 0.1);
				LAi_QuestDelay("BB_lower_cave_steplock", 0.1);
				LAi_QuestDelay("BB_lower_cave_deathtrap", 0.1);
			break;
		
			case "99":
				//Q2: final boss

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "BB_lower_cave";	//use console to get to burning_cave
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				LAi_SetHP(Pchar, 80.0, 80.0);
				SetModel(PChar, "Howard_Pyle_hat_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");		
				GiveItem2Character(Pchar, "blade1");		
				EquipCharacterByItem(Pchar, "blade1");
				GiveItem2Character(Pchar, "pistol20");
				EquipCharacterByItem(Pchar, "pistol20");
				GiveItem2Character(Pchar, "ammobag2");
				EquipCharacterByItem(Pchar, "ammobag2");
				GiveItem2Character(Pchar, "BB_hatA2");
				EquipCharacterByItem(Pchar, "BB_hatA2");
				GiveItem2Character(Pchar, "BB_coin"); 
				EquipCharacterByItem(Pchar, "BB_coin");
				TakeNItems(Pchar,"pistolbullets", 18);
				TakeNItems(Pchar,"gunpowder", 18);
			
				TakeNItems(Pchar,"incense", 10);		//new max
				TakeNItems(Pchar,"myrrh", 4);			//new max
				TakeNItems(Pchar,"potion1", 2);
				TakeNItems(Pchar,"potion3", 1);
			
				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");
			
				Pchar.protection = "off";
				locations[FindLocation("BB_lower_cave")].models.always.locators = "grotto2_l_dry";
				Locations[FindLocation("BB_lower_cave")].environment.sea = "false";

				Locations[FindLocation("BB_tower")].locators_radius.reload.reload5 = 0.001;
				Locations[FindLocation("BB_tower")].locators_radius.goto.goto2 = 0.7;

				Locations[FindLocation("BB_island1")].models.always.l1 = "blade1";
				Locations[FindLocation("BB_island1")].models.always.locators = "jungle07_l_JRH_open";	

				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				//LAi_QuestDelay("pick_up_grotto_boom", 0.1);
				LAi_QuestDelay("BB_lower_cave_deathtrap", 0.1);

				pchar.quest.BB_lower_cave_backloop_A.win_condition.l1 = "locator";
				pchar.quest.BB_lower_cave_backloop_A.win_condition.l1.location = "BB_lower_cave";
				pchar.quest.BB_lower_cave_backloop_A.win_condition.l1.locator_group = "reload";
				pchar.quest.BB_lower_cave_backloop_A.win_condition.l1.locator = "reload3";
				pchar.quest.BB_lower_cave_backloop_A.win_condition = "BB_lower_cave_backloop_A";

				pchar.quest.BB_lower_cave_steplock1.win_condition.l1 = "locator";
				pchar.quest.BB_lower_cave_steplock1.win_condition.l1.location = "BB_lower_cave";
				pchar.quest.BB_lower_cave_steplock1.win_condition.l1.locator_group = "goto";
				pchar.quest.BB_lower_cave_steplock1.win_condition.l1.locator = "steplock";
				pchar.quest.BB_lower_cave_steplock1.win_condition = "BB_lower_cave_steplock1";
			break;

			case "100":
				//Q2: after treasure

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "BB_lower_cave";	//use console to get to burning_cave
				rldGroup = "reload";
				rldLocator = "reload1";
			
				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				LAi_SetHP(Pchar, 80.0, 80.0);
				SetModel(PChar, "Skel4", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");		
				GiveItem2Character(Pchar, "blade1");		
				GiveItem2Character(Pchar, "pistol20");
				GiveItem2Character(Pchar, "ammobag1");
				GiveItem2Character(Pchar, "BB_hatA2");
				GiveItem2Character(Pchar, "BB_coin"); 
				EquipCharacterByItem(Pchar, "BB_coin");
				TakeNItems(Pchar,"pistolbullets", 18);
				TakeNItems(Pchar,"gunpowder", 18);

				GiveItem2Character(Pchar, "book73_closed");
				GiveItem2Character(Pchar, "snakewand");
				GiveItem2Character(Pchar, "pistolcenserD");

				GiveItem2Character(Pchar, "BBDagger");
				GiveItem2Character(Pchar, "toolbox_filled");
				GiveItem2Character(Pchar, "bladepainting");
				EquipCharacterByItem(Pchar, "bladepainting");
				GiveItem2Character(Pchar, "pistolbook71");
				EquipCharacterByItem(Pchar, "pistolbook71");

				TakeNItems(Pchar,"incense", 3);
				TakeNItems(Pchar,"myrrh", 2);

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;

			AddPassenger(Pchar, characterFromID("Hands"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
			SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Hands"));

			AddPassenger(Pchar, characterFromID("Caesar"), 0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Caesar"));
			characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Caesar"));

			AddPassenger(Pchar, characterFromID("Pell"), 0);
			SetOfficersIndex(Pchar, 3, getCharacterIndex("Pell"));
			SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, false);
			characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
			LAi_SetOfficerType(characterFromID("Pell"));

			GiveItem2Character(characterFromID("Pell"), "blade4");
			EquipCharacterByItem(characterFromID("Pell"), "blade4");
			GiveItem2Character(characterFromID("Pell"), "piratespistol");
			EquipCharacterByItem(characterFromID("Pell"), "piratespistol");
			TakeNItems(characterFromID("Pell"),"gunpowder", 6);
			TakeNItems(characterFromID("Pell"),"pistolbullets", 6);

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");
		
				Pchar.protection = "off";
				locations[FindLocation("BB_lower_cave")].models.always.locators = "grotto2_l_dry_H";
				Locations[FindLocation("BB_lower_cave")].environment.sea = "false";

				Locations[FindLocation("BB_tower")].locators_radius.reload.reload5 = 0.001;
				Locations[FindLocation("BB_tower")].locators_radius.goto.goto2 = 0.7;
				Locations[FindLocation("BB_island1")].models.always.locators = "Jungle07_l_JRH_open";
				Locations[FindLocation("BB_island1")].models.always.l1 = "blade1";
				Locations[FindLocation("BB_island1")].locators_radius.box.box1 = 0.0001;	

				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				//LAi_QuestDelay("pick_up_grotto_boom", 0.1);
				LAi_QuestDelay("BB_lower_cave_deathtrap", 0.1);

				pchar.quest.BB_lower_cave_backloop_A.win_condition.l1 = "locator";
				pchar.quest.BB_lower_cave_backloop_A.win_condition.l1.location = "BB_lower_cave";
				pchar.quest.BB_lower_cave_backloop_A.win_condition.l1.locator_group = "reload";
				pchar.quest.BB_lower_cave_backloop_A.win_condition.l1.locator = "reload3";
				pchar.quest.BB_lower_cave_backloop_A.win_condition = "BB_lower_cave_backloop_A";

				pchar.quest.BB_lower_cave_steplock1.win_condition.l1 = "locator";
				pchar.quest.BB_lower_cave_steplock1.win_condition.l1.location = "BB_lower_cave";
				pchar.quest.BB_lower_cave_steplock1.win_condition.l1.locator_group = "goto";
				pchar.quest.BB_lower_cave_steplock1.win_condition.l1.locator = "steplock";
				pchar.quest.BB_lower_cave_steplock1.win_condition = "BB_lower_cave_steplock1";
			break;

			case "105":
				//Q2: careen shore
		
			//LAi_SetImmortal(pchar, true);		//temp
				Pchar.quest.disable_rebirth = true;
		
				sTeleportLocName = "BB_careen_shore";
			//	sTeleportLocName = "BB_isle";
				rldGroup = "reload";
				rldLocator = "reload1";
			
				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	
				WhrDeleteRainEnvironment();
				SetNextWind("N",30);

			//	SetModel(PChar, "Howard_Pyle_b", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				SetModel(characterFromID("Hands"), "bb_hands2", "man", "man", 1.8, true);
				SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, true);
				Characters[GetCharacterIndex("Caesar")].dialog.CurrentNode  = "neutral";

				Pchar.special_flag = "on";
				CaptureTownForNation("Grand_Turk", PIRATE);
				ref cmdr = CharacterFromID("Dante Siciliano");//ok here
				cmdr.nation = PIRATE;
				cmdr.Flags.Pirate = 4; cmdr.Flags.Pirate.texture = 2;
		
			//no map: to be found in corvette cabin
				GiveItem2Character(Pchar, "bladeX4");
				EquipCharacterbyItem(Pchar, "bladeX4");
				LAi_SetActorType(Pchar);
				LAi_ActorSetLayMode(Pchar);

				LAi_QuestDelay("storm_careen", 1.0);

				//GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);		//only test
		
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_1"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_2"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_3"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_4"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_5"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_6"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_7"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_8"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_9"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_10"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_11"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_12"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_13"), "BB_careen_shore", "quest", "mut");
			ChangeCharacterAddressGroup(CharacterFromID("Mutineer_14"), "BB_careen_shore", "quest", "mut");//temp off

				LAi_SetPoorType(CharacterFromID("Mutineer_1"));
				LAi_SetPoorType(CharacterFromID("Mutineer_2"));
				LAi_SetPoorType(CharacterFromID("Mutineer_3"));
				LAi_SetPoorType(CharacterFromID("Mutineer_4"));
				LAi_SetPoorType(CharacterFromID("Mutineer_5"));
				LAi_SetPoorType(CharacterFromID("Mutineer_6"));
				LAi_SetPoorType(CharacterFromID("Mutineer_7"));
				LAi_SetPoorType(CharacterFromID("Mutineer_8"));
				LAi_SetPoorType(CharacterFromID("Mutineer_9"));
				LAi_SetPoorType(CharacterFromID("Mutineer_10"));
				LAi_SetPoorType(CharacterFromID("Mutineer_11"));
				LAi_SetPoorType(CharacterFromID("Mutineer_12"));
				LAi_SetPoorType(CharacterFromID("Mutineer_13"));
				LAi_SetPoorType(CharacterFromID("Mutineer_14"));

				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_15"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_16"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_17"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_18"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_19"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_20"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_21"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_22"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_32"), "BB_careen_shore", "quest", "mut");//obs 32 instead of 23
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_24"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_25"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_26"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_27"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Mutineer_31"), "BB_careen_shore", "quest", "mut");

		
				ChangeCharacterAddressGroup(CharacterFromID("Fletcher Christian"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Constable Mills"), "BB_careen_shore", "quest", "mut");
				ChangeCharacterAddressGroup(CharacterFromID("Midshipman Young"), "BB_careen_shore", "quest", "mut");
		//characters[GetCharacterIndex("Maltese_soldier3")].Ship.Type = "Corvette2";	//temp start with corvette
		
				pchar.quest.careen_back1_A.win_condition.l1 = "locator";
				pchar.quest.careen_back1_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back1_A.win_condition.l1.locator_group = "quest";
				pchar.quest.careen_back1_A.win_condition.l1.locator = "1";
				pchar.quest.careen_back1_A.win_condition = "careen_back1_A";

				pchar.quest.careen_back2_A.win_condition.l1 = "locator";
				pchar.quest.careen_back2_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back2_A.win_condition.l1.locator_group = "quest";
				pchar.quest.careen_back2_A.win_condition.l1.locator = "2";
				pchar.quest.careen_back2_A.win_condition = "careen_back2_A";

				pchar.quest.careen_back3_A.win_condition.l1 = "locator";
				pchar.quest.careen_back3_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back3_A.win_condition.l1.locator_group = "quest";
				pchar.quest.careen_back3_A.win_condition.l1.locator = "3";
				pchar.quest.careen_back3_A.win_condition = "careen_back3_A";
		
				pchar.quest.careen_back4_A.win_condition.l1 = "locator";
				pchar.quest.careen_back4_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back4_A.win_condition.l1.locator_group = "quest";
				pchar.quest.careen_back4_A.win_condition.l1.locator = "4";
				pchar.quest.careen_back4_A.win_condition = "careen_back4_A";

				pchar.quest.careen_back5_A.win_condition.l1 = "locator";
				pchar.quest.careen_back5_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back5_A.win_condition.l1.locator_group = "quest";
				pchar.quest.careen_back5_A.win_condition.l1.locator = "5";
				pchar.quest.careen_back5_A.win_condition = "careen_back5_A";

				pchar.quest.careen_back6_A.win_condition.l1 = "locator";
				pchar.quest.careen_back6_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back6_A.win_condition.l1.locator_group = "quest";
				pchar.quest.careen_back6_A.win_condition.l1.locator = "6";
				pchar.quest.careen_back6_A.win_condition = "careen_back6_A";

				pchar.quest.careen_back7_A.win_condition.l1 = "locator";
				pchar.quest.careen_back7_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back7_A.win_condition.l1.locator_group = "barmen";
				pchar.quest.careen_back7_A.win_condition.l1.locator = "7";
				pchar.quest.careen_back7_A.win_condition = "careen_back7_A";

				pchar.quest.careen_back8_A.win_condition.l1 = "locator";
				pchar.quest.careen_back8_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back8_A.win_condition.l1.locator_group = "barmen";
				pchar.quest.careen_back8_A.win_condition.l1.locator = "8";
				pchar.quest.careen_back8_A.win_condition = "careen_back8_A";

				pchar.quest.careen_back9_A.win_condition.l1 = "locator";
				pchar.quest.careen_back9_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back9_A.win_condition.l1.locator_group = "barmen";
				pchar.quest.careen_back9_A.win_condition.l1.locator = "9";
				pchar.quest.careen_back9_A.win_condition = "careen_back9_A";

				pchar.quest.careen_back10_A.win_condition.l1 = "locator";
				pchar.quest.careen_back10_A.win_condition.l1.location = "BB_careen_shore";
				pchar.quest.careen_back10_A.win_condition.l1.locator_group = "quest";
				pchar.quest.careen_back10_A.win_condition.l1.locator = "10";
				pchar.quest.careen_back10_A.win_condition = "careen_back10_A";
			break;

			case "106":
				//Q2: careen corvette
		
			//LAi_SetImmortal(pchar, true);		//temp
				Pchar.quest.disable_rebirth = true;
		
				sTeleportLocName = "BB_careen_corvette";
				rldGroup = "reload";
				rldLocator = "reload1";
				
				SetCurrentTime(2, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	
				WhrDeleteRainEnvironment();
				SetNextWind("N",30);

				DeleteAttribute(Pchar, "items");
				GiveItem2Character(Pchar, "book71_9_start");
				GiveItem2Character(Pchar, "picture8_A");
			//no map: to be found in corvette cabin

				DeleteAttribute(characterFromID("Caesar"), "items");
				DeleteAttribute(characterFromID("mutineer_23"), "items");
				DeleteAttribute(characterFromID("mutineer_19"), "items");

				GiveItem2Character(pchar,"bladeX4");
				EquipCharacterByItem(pchar, "bladeX4");
				GiveItem2Character(characterFromID("Caesar"),"bladeX4");
				EquipCharacterByItem(characterFromID("Caesar"), "bladeX4");
				GiveItem2Character(characterFromID("mutineer_23"),"bladeX4");
				EquipCharacterByItem(characterFromID("mutineer_23"), "bladeX4");
				GiveItem2Character(characterFromID("mutineer_19"),"bladeX4");
				EquipCharacterByItem(characterFromID("mutineer_19"), "bladeX4");

				AddPassenger(Pchar, characterFromID("Caesar"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Caesar"));
				characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Caesar"));

				AddPassenger(Pchar, characterFromID("mutineer_23"), 0);
				SetOfficersIndex(Pchar, 2, getCharacterIndex("mutineer_23"));
				characters[GetCharacterIndex("mutineer_23")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("mutineer_23"));

				AddPassenger(Pchar, characterFromID("mutineer_19"), 0);
				SetOfficersIndex(Pchar, 3, getCharacterIndex("mutineer_19"));
				characters[GetCharacterIndex("mutineer_19")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("mutineer_19"));

				LAi_QuestDelay("prepare_start_careen_corvette", 1.0);
			break;

			case "109":
				//start Q2

				sTeleportLocName = "Redmond_town_04";
				rldGroup = "reload";
				rldLocator = "reload2";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				SetModel(PChar, "ShkiperM_UH_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				AddMoneyToCharacter(Pchar, 2743);
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "bladeA5");
				EquipCharacterbyItem(Pchar, "bladeA5");
				GiveItem2Character(Pchar, "pistol20");
				EquipCharacterbyItem(Pchar, "pistol20");
				GiveItem2Character(Pchar, "ammobag2");
				EquipCharacterbyItem(Pchar, "ammobag2");
				GiveItem2Character(Pchar, "bladepclub203");
				TakeNItems(Pchar,"pistolbullets", 18);
				TakeNItems(Pchar,"gunpowder", 18);
				GiveItem2Character(Pchar, "sewing_kit");
				TakeNItems(Pchar,"tobacco", 4);
				GiveItem2Character(Pchar, "spyglass2");
				EquipCharacterbyItem(Pchar, "spyglass2");
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "mapBB1");
				GiveItem2Character(Pchar, "chinatiger");
				GiveItem2Character(Pchar, "key17");

				Pchar.mapBB1 = "info";
				AddQuestRecord("Benjamin_Hornigold", "3");
				CloseQuestHeader("Benjamin_Hornigold");

				SetQuestHeader("Caesar");
				AddQuestRecord("Caesar", "1");

				SetQuestHeader("Israel_Hands");
				AddQuestRecord("Israel_Hands", "1");

				SetQuestHeader("Charles_Eden");
				AddQuestRecord("Charles_Eden", "1");

				SetQuestHeader("Richards");
				AddQuestRecord("Richards", "1");

				SetQuestHeader("Johnson");
				AddQuestRecord("Johnson", "1");	

				AddPassenger(Pchar, characterFromID("gm_crew1"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("gm_crew1"));
				characters[GetCharacterIndex("gm_crew1")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("gm_crew1"));

				AddPassenger(Pchar, characterFromID("gm_crew20"), 0);
				SetOfficersIndex(Pchar, 2, getCharacterIndex("gm_crew20"));
				characters[GetCharacterIndex("gm_crew20")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("gm_crew20"));

				int iNation;
				iNation = sti(PChar.nation);
				PChar.templand = GetCharacterLand(PChar);
				AddLandToCharacter(&Pchar, "Redmond", iNation, 50);
				DeleteAttribute(PChar,"templand");

				int curExp = sti(Pchar.Experience);
				int nextExp = CalculateExperienceFromRank(sti(Pchar.rank)+7);
				int addExp = nextExp-curExp;
				AddCharacterExpNS(Pchar, addExp);
				Pchar.perks.freepoints = 0;//this takes away the added perk

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.IronWill = true;
				Pchar.perks.list.GunFighter = true;

				ChangeCharacterAddressGroup(characterFromID("wr_man3"), "none", "", "");	//terrace guard
				ChangeCharacterAddressGroup(characterFromID("wr_pir7"), "none", "", "");	//terrace guard
				ChangeCharacterAddressGroup(characterFromID("wr_sol6f77"), "none", "", "");	//shore 03 guard
				ChangeCharacterAddressGroup(characterFromID("wr_fwn"), "none", "", "");		//shore 03 guard

				locations[FindLocation("wr_crew")].id.label = "Crew's quarter";

				Locations[FindLocation("Redmond_UsurerHouse")].models.always.locators = "SS_l_JRH3";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l1.disable = 0;		//to town
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.disable = 1;		//to library
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l4.disable = 1;		//to behind counter
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l6.disable = 1;		//to cellar
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l7.disable = 1;		//to town behind counter
				locations[FindLocation("Redmond_UsurerHouse")].type = "house";			//reset

				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";
				locations[FindLocation("wr_library")].id.label = "Woodes Rogers' library";

				locations[FindLocation("Shop_stairs")].id.label = "Rogers' Paintings Furniture & Weapons";

				Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH7";	//was 6
				Locations[FindLocation("Redmond_Town_01")].reload.l18.disable = 1;		//window
				Locations[FindLocation("Redmond_Town_01")].reload.l23.disable = 1;		//gate terrace
				Locations[FindLocation("Redmond_Town_01")].reload.l26.disable = 1;		//tavern storeroom
				Locations[FindLocation("Redmond_Town_01")].reload.l27.disable = 1;		//Rogers shop
				Locations[FindLocation("Redmond_Town_01")].reload.l20.disable = 1;		//LS back door
			//	Locations[FindLocation("Redmond_Town_01")].reload.l9.close_for_night = 1;	//shipyard
				Locations[FindLocation("Redmond_shipyard")].reload.l2.disable = 0;		//shipyard stairs
				locations[FindLocation("shipyard_stairs")].id.label = "Shipyard stairs";
				Locations[FindLocation("Shipyard_shore")].reload.l1.disable = 1;		//to docks
				Locations[FindLocation("Shipyard_shore")].reload.l2.disable = 1;		//to docks
		
				Locations[FindLocation("Redmond_tavern")].models.always.locators = "LT_l_JRH3";
				Locations[FindLocation("Redmond_tavern")].reload.l3.disable = 1;		//balcony: officer problems
				Locations[FindLocation("Redmond_tavern")].reload.l4.disable = 1;		//counter: officer problems
				Locations[FindLocation("Redmond_tavern")].reload.l6.disable = 1;		//tavern storeroom

				locations[FindLocation("Tavern_storeroom")].id.label = "Tavern storeroom";
				locations[FindLocation("wr_kitchen")].id.label = "Woodes Rogers' kitchen";

				Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = 0;	//to governor's residence
				Locations[FindLocation("Redmond_Port")].reload.l6.disable = 0;		//to harbour office
				Locations[FindLocation("Redmond_Port")].reload.l4.disable = 1;		//to my ship

				locations[FindLocation("Redmond_church")].reload.l1.disable = 0;
				locations[FindLocation("Redmond_church")].reload.l2.disable = 1;
				locations[FindLocation("Redmond_church")].reload.l3.disable = 1;
				locations[FindLocation("church_choir")].id.label = "Port Royal Church Choir";
				locations[FindLocation("wr_crypt")].id.label = "Port Royal catacombs";

				Locations[FindLocation("Redmond_town_exit_2")].models.always.locators = "Redexit2_l_JRH";
				locations[FindLocation("Redmond_town_exit_2")].reload.l5.disable = 1;		//to well
				Locations[FindLocation("Redmond_Town_exit_2")].reload.l1.disable = 0;		//to town

				Locations[FindLocation("Shipyard_shore")].models.always.locators = "FFport02_l_JRH_out";
				locations[FindLocation("Shipyard_shore")].type = "silent_town";
				Locations[FindLocation("Redmond_shore_02")].models.always.locators = "shore03_l";

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";	

				Pchar.quest.Rdm_officiant = "Claire";

				pchar.quest.Shipyard_shore_ambush.win_condition.l1 = "location";
				pchar.quest.Shipyard_shore_ambush.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.Shipyard_shore_ambush.win_condition = "to_the_farm";

				pchar.quest.wrport_backloop7_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop7_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop7_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop7_A.win_condition.l1.locator = "reload7";
				pchar.quest.wrport_backloop7_A.win_condition = "wrport_backloop7_A";

				pchar.quest.wrport_backloop8_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop8_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop8_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop8_A.win_condition.l1.locator = "reload8";
				pchar.quest.wrport_backloop8_A.win_condition = "wrport_backloop8_A";

				pchar.quest.alchemy_fire_level_down1.win_condition.l1 = "location";
				pchar.quest.alchemy_fire_level_down1.win_condition.l1.location = "wr_farm_alchemy";
				pchar.quest.alchemy_fire_level_down1.win_condition = "alchemy_fire_level_down1";
			break;

			case "110":
				//Q2: alchemy part 1
		//LAi_SetImmortal(pchar, true);	//temp
	Pchar.quest.disable_rebirth = true;
	//DeleteAttribute(PChar, "quest.disable_rebirth");
	//ChangeCharacterAddressGroup(CharacterFromID("Minerva"), "wr_port", "goto", "goto20");	//temp
	ChangeCharacterAddressGroup(CharacterFromID("JRH"), "wr_port", "goto", "goto20");	//temp

				sTeleportLocName = "wr_port";
				rldGroup = "reload";
				rldLocator = "reload2";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(PChar, "Howard_Pyle_1", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "bladeX4");
				EquipCharacterbyItem(Pchar, "bladeX4");
		//		GiveItem2Character(Pchar, "key17");		//kept from WR1
		//		GiveItem2Character(Pchar, "mapBB1");		//kept from WR1
				GiveItem2Character(PChar, "long_johns");
				GiveItem2Character(PChar, "bandana");
			//no map yet: to be found in small sloop's cabin

				Pchar.mapBB1 = "info";
				AddQuestRecord("Benjamin_Hornigold", "3");
				CloseQuestHeader("Benjamin_Hornigold");

				SetQuestHeader("Caesar");
				AddQuestRecord("Caesar", "1");

				SetQuestHeader("Israel_Hands");
				AddQuestRecord("Israel_Hands", "1");

				SetQuestHeader("Charles_Eden");
				AddQuestRecord("Charles_Eden", "1");

				SetQuestHeader("Richards");
				AddQuestRecord("Richards", "1");

				SetQuestHeader("Johnson");
				AddQuestRecord("Johnson", "1");	


			//GiveItem2Character(Pchar, "bladebottle_BNc");
			//GiveItem2Character(Pchar, "bladebottle_CA2_1");
			//GiveItem2Character(Pchar, "bladebottle_CT1_sulf");
			//GiveItem2Character(Pchar, "bladebottle_CT1_sulf");		
			//EquipCharacterbyItem(Pchar, "bladebottle_CT1_sulf");
			//GiveItem2Character(Pchar, "bladebottle_BTc_hydr");
			//EquipCharacterbyItem(Pchar, "bladebottle_BTc_hydr");
			//GiveItem2Character(Pchar, "bladebottle_BN1");
			//GiveItem2Character(Pchar, "bladebottle_CE0");
			//EquipCharacterbyItem(Pchar, "bladebottle_CE0");
			//GiveItem2Character(Pchar, "bladebottle_BE0");
			//EquipCharacterbyItem(Pchar, "bladebottle_BE0");
			//GiveItem2Character(Pchar, "bladebottle_CT2_sulf_w");
			//EquipCharacterbyItem(Pchar, "bladebottle_CT2_sulf_w");
			//GiveItem2Character(Pchar, "bladebottle_CP2");
			//EquipCharacterbyItem(Pchar, "bladebottle_CP2");
			//GiveItem2Character(Pchar, "bladecauldron");
			//EquipCharacterbyItem(Pchar, "bladecauldron");

			//GiveItem2Character(Pchar, "pistolfunnel");
			//EquipCharacterbyItem(Pchar, "pistolfunnel");
		//GiveItem2Character(Pchar, "pistolcalciumsack");
		//GiveItem2Character(Pchar, "pistolstonebasket_G");
		//GiveItem2Character(Pchar, "pistolstonebasket_R");
		//GiveItem2Character(Pchar, "pistolstonebasket_M");
		//GiveItem2Character(Pchar, "pistolstonebasket_B");
		//GiveItem2Character(Pchar, "pistolbucket_dung");
		//GiveItem2Character(Pchar, "pistolretort3");
			//GiveItem2Character(Pchar, "pistolretort3");
			//GiveItem2Character(Pchar, "pistolcharcoal_WR");
		//GiveItem2Character(Pchar, "pistolnitre");
			//GiveItem2Character(Pchar, "pistolsalt");
		//GiveItem2Character(Pchar, "pistolsalt");
			//EquipCharacterbyItem(Pchar, "pistolsalt");
		//GiveItem2Character(Pchar, "pistolcopperas");
		//GiveItem2Character(Pchar, "pistolcloth");
			//EquipCharacterbyItem(Pchar, "pistolcloth");
		//GiveItem2Character(Pchar, "pistolfunnel");
		//GiveItem2Character(Pchar, "pistolcharcoal_WR");
			//GiveItem2Character(Pchar, "pistolcharcoal_WR");
			//GiveItem2Character(Pchar, "pistolnitre");

			//#7
			//GiveItem2Character(Pchar, "bladebottle_CV1_cao");
			//GiveItem2Character(Pchar, "bladebottle_CV1_NH4Cl");
			//GiveItem2Character(Pchar, "bladebottle_CW1");
			//GiveItem2Character(Pchar, "pistolsulphur_WR");

			//#9
			//GiveItem2Character(Pchar, "bladebottle_CV1_cao");
			//GiveItem2Character(Pchar, "bladebottle_CV1_sc");
			//GiveItem2Character(Pchar, "pistolsulphur_WR");
			//GiveItem2Character(Pchar, "pistolstonebasket_M");
			//GiveItem2Character(Pchar, "bladebottle_CT1_nitr");
			
			//#10
			//GiveItem2Character(Pchar, "bladebottle_CB2_mix9");
			//EquipCharacterbyItem(Pchar, "bladebottle_CB2_mix9");
			//GiveItem2Character(Pchar, "bladebottle_CT1_sulf");
			//EquipCharacterbyItem(Pchar, "bladebottle_CT1_sulf");
			//GiveItem2Character(Pchar, "bladebottle_CT1_nitr");

			//#11
		//GiveItem2Character(Pchar, "bladebottle_CT2_mix11");
			//GiveItem2Character(Pchar, "bladebottle_CT1_nitr");
			//GiveItem2Character(Pchar, "pistolstonebasket_R");
			//GiveItem2Character(Pchar, "bladebottle_CE0");
			//GiveItem2Character(Pchar, "bladebottle_CE0");
			//EquipCharacterbyItem(Pchar, "bladebottle_CE0");

			//#12
			//GiveItem2Character(Pchar, "bladebottle_CB1_mix9");
			//EquipCharacterbyItem(Pchar, "bladebottle_CB1_mix9");
			//GiveItem2Character(Pchar, "bladebottle_CT1_sulf");
			//GiveItem2Character(Pchar, "bladebottle_CE0");
			//GiveItem2Character(Pchar, "bladebottle_CR1");
			
			//#13 start final mixes
		//	GiveItem2Character(Pchar, "bladebottle_BS2_LH");
		//	GiveItem2Character(Pchar, "bladebottle_CC2_bps");
		//	GiveItem2Character(Pchar, "bladebottle_CR2_rps");


				//PORT ROYAL: SHIPYARD BEFORE FARM

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			//	SetCharacterShipLocation(Pchar, "Redmond_Port");
			//	SetCharacterShipLocation(Pchar, "wr_port");

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
			
				Pchar.quest.Rdm_officiant = "Claire";
			
			ChangeCharacterAddressGroup(characterFromID("wr_sol6f77"), "none", "", "");		//boatshore
			ChangeCharacterAddressGroup(characterFromID("wr_fwn"), "none", "", "");			//boatshore
			Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
			Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
			Locations[FindLocation("wr_farm_booty")].models.always.locators = "sklad_locators_JRH2";
			Locations[FindLocation("wr_farm_bedroom")].reload.l2.disable = 0;
			Locations[FindLocation("wr_farm_corridor")].filespath.textures = "locations\inside\Corridor\normal";
			Locations[FindLocation("wr_farm_corridor")].locators_radius.box.box1 = 0.001;
			Locations[FindLocation("wr_farm_corridor")].models.always.locators = "storeSmall_locators_JRH_normal";
			Locations[FindLocation("wr_farm_corridor")].reload.l5.disable = 0;
			Locations[FindLocation("wr_farm_servant")].models.always.locators = "sh_l_JRH2_open";
			Locations[FindLocation("wr_farm_alchemy")].reload.l3.disable = 0;
			Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box6 = 0.0001;
			Locations[FindLocation("wr_farm_alchemy")].locators_radius.reload.reload1 = 0.6;
			locations[FindLocation("wr_farm_alchemy")].models.always.l9 = "cauldron3_w";
			locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_E0";
			locations[FindLocation("wr_farm_alchemy")].models.always.l11 = "top3";
			locations[FindLocation("wr_farm_alchemy")].models.always.l12 = "glass_tube3";
			locations[FindLocation("wr_farm_servant")].id.label = "Minervas room";
			locations[FindLocation("wr_farm_corridor")].id.label = "Rogers' passage";

			Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box7 = 0.5;	//mixtable big bottle
			locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LE0";	//should be on here
			locations[FindLocation("wr_farm_alchemy")].models.always.l15 = "hatch7";

			Locations[FindLocation("wr_farm_kitchen")].items.randitem1 = "key8";		//invisible model
			Locations[FindLocation("wr_farm_bedroom")].items.randitem7 = "key8";
			Locations[FindLocation("wr_farm_corridor")].models.always.l1 = "";
			Locations[FindLocation("wr_farm_servant")].items.randitem6 = "key8";
			Locations[FindLocation("wr_farm_servant")].items.randitem7 = "key8";
			Locations[FindLocation("wr_farm_alchemy")].items.randitem6 = "key8";

			Locations[FindLocation("wr_farm_kitchen")].locators_radius.randitem.randitem1 = 0.0001;
			Locations[FindLocation("wr_farm_bedroom")].locators_radius.randitem.randitem7 = 0.0001;
			Locations[FindLocation("wr_farm_servant")].locators_radius.randitem.randitem6 = 0.0001;
			Locations[FindLocation("wr_farm_servant")].locators_radius.randitem.randitem7 = 0.0001;
			Locations[FindLocation("wr_farm_alchemy")].locators_radius.randitem.randitem6 = 0.0001;

			Pchar.quest.distillery_items = "open";
			//Pchar.quest.farm_water = "off";
			Pchar.quest.alchemy_lever = "down";
			Pchar.quest.alchemy_plank = "up";
			Pchar.quest.apparatus_level = "glass_tube";		
			Pchar.quest.farmbooty_fillbottle = "off";
			Pchar.quest.apparatus_liquid = "none";
			Pchar.quest.apparatus_cooling = "2";
			Pchar.quest.mixtable_bottle = "ME0";
			pchar.quest.Minerva = "arrived";
			Pchar.quest.cauldron = "water";
			Pchar.quest.retort = "yes";
		Pchar.quest.block_water = "yes";
		

			//new attributes Q2
			Pchar.alchemy2_grinder = "empty";
			Pchar.use_only_big_bottle = "yes";
			Pchar.Q2_mix = "1";			//start = "1"
		//	Pchar.Q2_mix = "5";			//after HNO3
		//	Pchar.Q2_mix = "7";			//ready for 4 ingredients mix L.H.
			Pchar.quest.qbook_receiver = "done";
			Pchar.quest.distillery_items_Q2 = "open";

		//	Pchar.Q2_mix = "4";
		//	Pchar.use_only_big_bottle = "no";
		//	Pchar.use_only_small_bottle = "yes";

		//	Pchar.Q2_mix = "9";				//start BPS

		//	Pchar.Q2_mix = "10";				//mix sulf aur med bottle
		//	Pchar.use_only_big_bottle = "no";
		//	Pchar.use_only_small_bottle = "yes";	

		//	Pchar.Q2_mix = "11";				//red stones into crucible
		//	Pchar.use_only_big_bottle = "no";
		//	Pchar.use_only_small_bottle = "yes";
		//	Pchar.quest.mixtable_bottle = "none";		//if start without any bottle here

		//	Pchar.Q2_mix = "12";				//start with red powder picked up
		//	Pchar.use_only_big_bottle = "no";
		//	Pchar.use_only_small_bottle = "yes";
		//	Pchar.quest.mixtable_bottle = "none";		//if start without any bottle here

		//	Pchar.Q2_mix = "13";				//start final mixes
		//	Pchar.use_only_big_bottle = "no";
		//	Pchar.use_only_small_bottle = "no";		//both yes


				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";

				Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
				Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
				Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
				Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
				Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes RogersÂ´ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";

				Locations[FindLocation("wr_church_attic")].type = "Vane_jungle";

				SetCharacterShipLocation(characterFromID("pir_cap1"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap2"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap3"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap4"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap5"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap6"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap7"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap8"), "wr_cave_shore");
			
				SetCharacterShipLocation(characterFromID("pir_cap9"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap10"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap11"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap12"), "wr_cave_shore");
		
				SetCharacterShipLocation(characterFromID("pir_cap13"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap14"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap15"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap16"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap17"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap18"), "wr_cave_shore");
		
				SetCharacterShipLocation(characterFromID("pir_cap19"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap20"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap21"), "wr_cave_shore");
				SetCharacterShipLocation(characterFromID("pir_cap22"), "Redmond_shore_02");
			
				SetCharacterShipLocation(characterFromID("CoastBrother1"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother2"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother3"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother4"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother5"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother6"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother7"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother8"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother9"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother10"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother11"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother12"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother13"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother14"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother15"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother16"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother17"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother19"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother22"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother23"), "wr_cannon_tower");
				SetCharacterShipLocation(characterFromID("CoastBrother24"), "wr_cannon_tower");	

				SetCharacterShipLocation(characterFromID("CoastBrother29"), "Redmond_shore_ship");//PrisonShip
				SetCharacterShipLocation(characterFromID("CoastBrother30"), "Redmond_shore_ship");//PrisonShip
				SetCharacterShipLocation(characterFromID("CoastBrother32"), "Redmond_shore_ship");//tartane2
			//	SetCharacterShipLocation(characterFromID("CoastBrother33"), "Redmond_shore_03");//tartane2
			//	SetCharacterShipLocation(characterFromID("CoastBrother25"), "wr_port");		//prize ship galleon
			//	SetCharacterShipLocation(characterFromID("CoastBrother26"), "wr_port");		//prize ship corvette
				SetCharacterShipLocation(characterFromID("wr_aub"), "wr_ships");		//boat2
				//----------------------------------------------------------------------------------------------------------------------

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("cavern_chest_stop", 0.1);//started also during first visit to cavern (fall from mine)
		//		LAi_QuestDelay("ready_for_ships0", 0.1);	//start from redmond, this way no problems
			LAi_QuestDelay("alchemy_fire_level_down", 0.1);

				//RESTARTS WAY IN
				bDisableFastReload = 1;
				Pchar.quest.wr_terrace = "second_time";

				pchar.quest.place_distillery_itemsA1.win_condition.l1 = "location";
				pchar.quest.place_distillery_itemsA1.win_condition.l1.location = "wr_farm_booty";
				pchar.quest.place_distillery_itemsA1.win_condition = "place_distillery_itemsA1";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				//----------------------------------------------------------------

				pchar.quest.wrport_backloop7_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop7_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop7_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop7_A.win_condition.l1.locator = "reload7";
				pchar.quest.wrport_backloop7_A.win_condition = "wrport_backloop7_A";

				pchar.quest.wrport_backloop8_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop8_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop8_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop8_A.win_condition.l1.locator = "reload8";
				pchar.quest.wrport_backloop8_A.win_condition = "wrport_backloop8_A";
			/*
				pchar.quest.wrport_backloop4_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop4_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop4_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop4_A.win_condition.l1.locator = "reload4";
				pchar.quest.wrport_backloop4_A.win_condition = "wrport_backloop4_A";

				pchar.quest.wrport_backloop5_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop5_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop5_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop5_A.win_condition.l1.locator = "reload5";
				pchar.quest.wrport_backloop5_A.win_condition = "wrport_backloop5_A";

				pchar.quest.wrport_backloop6_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop6_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop6_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop6_A.win_condition.l1.locator = "reload6";
				pchar.quest.wrport_backloop6_A.win_condition = "wrport_backloop6_A";

				pchar.quest.wrport_backloop9_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop9_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop9_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop9_A.win_condition.l1.locator = "reload9";
				pchar.quest.wrport_backloop9_A.win_condition = "wrport_backloop9_A";

				pchar.quest.wrport_backloop10_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop10_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop10_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop10_A.win_condition.l1.locator = "reload10";
				pchar.quest.wrport_backloop10_A.win_condition = "wrport_backloop10_A";
			*/
				//----------------------------------------------------------------

				pchar.quest.alchemy2_fire_level_down1.win_condition.l1 = "location";
				pchar.quest.alchemy2_fire_level_down1.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.alchemy2_fire_level_down1.win_condition = "alchemy2_fire_level_down1";
			
				pchar.quest.ovenstop1.win_condition.l1 = "locator";
				pchar.quest.ovenstop1.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.ovenstop1.win_condition.l1.locator_group = "goto";
				pchar.quest.ovenstop1.win_condition.l1.locator = "ovenstop1";
				pchar.quest.ovenstop1.win_condition = "ovenback1";

				pchar.quest.ovenstop2.win_condition.l1 = "locator";
				pchar.quest.ovenstop2.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.ovenstop2.win_condition.l1.locator_group = "goto";
				pchar.quest.ovenstop2.win_condition.l1.locator = "ovenstop2";
				pchar.quest.ovenstop2.win_condition = "ovenback2";

				pchar.quest.ovenstop3.win_condition.l1 = "locator";
				pchar.quest.ovenstop3.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.ovenstop3.win_condition.l1.locator_group = "goto";
				pchar.quest.ovenstop3.win_condition.l1.locator = "ovenstop3";
				pchar.quest.ovenstop3.win_condition = "ovenback2";

				pchar.quest.woodstop.win_condition.l1 = "locator";
				pchar.quest.woodstop.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.woodstop.win_condition.l1.locator_group = "goto";
				pchar.quest.woodstop.win_condition.l1.locator = "woodstop";
				pchar.quest.woodstop.win_condition = "woodback";
			break;

			case "111":
				//Q2: alchemy part 2
			
				sTeleportLocName = "wr_port";
				rldGroup = "reload";
				rldLocator = "sea";
			
				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(PChar, "Howard_Pyle_hat_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

			//no map: replaced by mapWR5
				GiveItem2Character(Pchar, "mapWR5");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade11");
				EquipCharacterbyItem(Pchar, "blade11");
				GiveItem2Character(Pchar, "pistol6");
				EquipCharacterbyItem(Pchar, "pistol6");
				TakeNItems(pchar, "gunpowder", 4);
				TakeNItems(pchar, "pistolbullets", 4);
				GiveItem2Character(Pchar, "pistolbelt");
				EquipCharacterByItem(Pchar, "pistolbelt");
				GiveItem2Character(Pchar, "ammobag2");
				EquipCharacterByItem(Pchar, "ammobag2");
				GiveItem2Character(Pchar, "BB_hatA2");
				EquipCharacterByItem(Pchar, "BB_hatA2");

				AddMoneyToCharacter(Pchar,-10000);
				GiveItem2Character(Pchar, "potionrum");

				GiveItem2Character(Pchar, "spyglass3");			//from Bolitho corvette
				EquipCharacterbyItem(Pchar, "spyglass3");
				GiveItem2Character(Pchar, "sextant");
				EquipCharacterbyItem(Pchar, "sextant");
				GiveItem2Character(Pchar, "compass2");
				EquipCharacterbyItem(Pchar, "compass2");
				GiveItem2Character(Pchar, "map");
				
				GiveItem2Character(Pchar, "book71_9_start");
				GiveItem2Character(Pchar, "picture8_A");

				DeleteAttribute(Pchar,"ship");
				GiveShip2Character(pchar,"Corvette2","Den svenske islandsfararen",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "wr_port");
				
				DeleteAttribute(Pchar,"nation");
				Pchar.nation = ENGLAND;

				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//to wr_port
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";

				ChangeCharacterAddressGroup(characterFromID("wr_sol6f77"), "none", "", "");		//boatshore
				ChangeCharacterAddressGroup(characterFromID("wr_fwn"), "none", "", "");			//boatshore
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Locations[FindLocation("wr_farm_booty")].models.always.locators = "sklad_locators_JRH2";
				Locations[FindLocation("wr_farm_bedroom")].reload.l2.disable = 0;
				Locations[FindLocation("wr_farm_corridor")].filespath.textures = "locations\inside\Corridor\normal";
				Locations[FindLocation("wr_farm_corridor")].locators_radius.box.box1 = 0.001;
				Locations[FindLocation("wr_farm_corridor")].models.always.locators = "storeSmall_locators_JRH_normal";
				Locations[FindLocation("wr_farm_corridor")].reload.l5.disable = 0;
				Locations[FindLocation("wr_farm_servant")].models.always.locators = "sh_l_JRH2_open";
				Locations[FindLocation("wr_farm_servant")].reload.l2.disable = 0;
				Locations[FindLocation("wr_farm_alchemy")].reload.l2.disable = 0;
				Locations[FindLocation("wr_farm_alchemy")].reload.l3.disable = 0;
				Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box6 = 0.0001;
				Locations[FindLocation("wr_farm_alchemy")].locators_radius.reload.reload1 = 0.6;
				locations[FindLocation("wr_farm_alchemy")].models.always.l9 = "cauldron3_w";
				locations[FindLocation("wr_farm_alchemy")].models.always.l10 = "retort_E0";
				locations[FindLocation("wr_farm_alchemy")].models.always.l11 = "top3";
				locations[FindLocation("wr_farm_alchemy")].models.always.l12 = "glass_tube3";

				Locations[FindLocation("wr_farm_alchemy2")].reload.l1.disable = 0;
				Locations[FindLocation("wr_farm_alchemy2")].reload.l2.disable = 0;
				Locations[FindLocation("wr_farm_alchemy2")].reload.l3.disable = 0;
				locations[FindLocation("wr_farm_booty2")].id.label = "Rogers' secret storeroom";

				locations[FindLocation("wr_farm_servant")].id.label = "Minervas room";
				locations[FindLocation("wr_farm_corridor")].id.label = "Rogers' passage";

				Locations[FindLocation("wr_farm_alchemy")].locators_radius.box.box7 = 0.5;	//mixtable big bottle
				locations[FindLocation("wr_farm_alchemy")].models.always.l16 = "bottle_LE0";	//should be on here
				locations[FindLocation("wr_farm_alchemy")].models.always.l15 = "hatch7";

				Locations[FindLocation("wr_farm_kitchen")].items.randitem1 = "key8";		//invisible model
				Locations[FindLocation("wr_farm_bedroom")].items.randitem7 = "key8";
				Locations[FindLocation("wr_farm_corridor")].models.always.l1 = "";
				Locations[FindLocation("wr_farm_servant")].items.randitem6 = "key8";
				Locations[FindLocation("wr_farm_servant")].items.randitem7 = "key8";
				Locations[FindLocation("wr_farm_alchemy")].items.randitem6 = "key8";

				Locations[FindLocation("wr_farm_kitchen")].locators_radius.randitem.randitem1 = 0.0001;
				Locations[FindLocation("wr_farm_bedroom")].locators_radius.randitem.randitem7 = 0.0001;
				Locations[FindLocation("wr_farm_servant")].locators_radius.randitem.randitem6 = 0.0001;
				Locations[FindLocation("wr_farm_servant")].locators_radius.randitem.randitem7 = 0.0001;
				Locations[FindLocation("wr_farm_alchemy")].locators_radius.randitem.randitem6 = 0.0001;
				Locations[FindLocation("wr_farm_alchemy2")].locators_radius.box.box17 = 0.0001;
				Locations[FindLocation("wr_farm_alchemy2")].locators_radius.box.box18 = 0.0001;
	
				Pchar.quest.distillery_items = "open";
				//Pchar.quest.farm_water = "off";
				Pchar.quest.alchemy_lever = "down";
				Pchar.quest.alchemy_plank = "up";
				Pchar.quest.apparatus_level = "glass_tube";		
				Pchar.quest.farmbooty_fillbottle = "off";
				Pchar.quest.apparatus_liquid = "none";
				Pchar.quest.apparatus_cooling = "2";
				Pchar.quest.mixtable_bottle = "ME0";
				pchar.quest.Minerva = "arrived";
				Pchar.quest.cauldron = "water";
				Pchar.quest.retort = "yes";
				Pchar.quest.block_water = "yes";
		
				//new attributes Q2
				Pchar.alchemy2_grinder = "empty";
				Pchar.use_only_big_bottle = "yes";
				Pchar.quest.qbook_receiver = "done";
				Pchar.quest.distillery_items_Q2 = "open";

				pchar.quest.wrport_backloop7_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop7_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop7_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop7_A.win_condition.l1.locator = "reload7";
				pchar.quest.wrport_backloop7_A.win_condition = "wrport_backloop7_A";

				pchar.quest.wrport_backloop8_A.win_condition.l1 = "locator";
				pchar.quest.wrport_backloop8_A.win_condition.l1.location = "wr_port";
				pchar.quest.wrport_backloop8_A.win_condition.l1.locator_group = "reload";
				pchar.quest.wrport_backloop8_A.win_condition.l1.locator = "reload8";
				pchar.quest.wrport_backloop8_A.win_condition = "wrport_backloop8_A";

				pchar.quest.alchemy2_fire_level_down1.win_condition.l1 = "location";
				pchar.quest.alchemy2_fire_level_down1.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.alchemy2_fire_level_down1.win_condition = "alchemy2_fire_level_down1";
			
				pchar.quest.ovenstop1.win_condition.l1 = "locator";
				pchar.quest.ovenstop1.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.ovenstop1.win_condition.l1.locator_group = "goto";
				pchar.quest.ovenstop1.win_condition.l1.locator = "ovenstop1";
				pchar.quest.ovenstop1.win_condition = "ovenback1";

				pchar.quest.ovenstop2.win_condition.l1 = "locator";
				pchar.quest.ovenstop2.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.ovenstop2.win_condition.l1.locator_group = "goto";
				pchar.quest.ovenstop2.win_condition.l1.locator = "ovenstop2";
				pchar.quest.ovenstop2.win_condition = "ovenback2";

				pchar.quest.ovenstop3.win_condition.l1 = "locator";
				pchar.quest.ovenstop3.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.ovenstop3.win_condition.l1.locator_group = "goto";
				pchar.quest.ovenstop3.win_condition.l1.locator = "ovenstop3";
				pchar.quest.ovenstop3.win_condition = "ovenback2";

				pchar.quest.woodstop.win_condition.l1 = "locator";
				pchar.quest.woodstop.win_condition.l1.location = "wr_farm_alchemy2";
				pchar.quest.woodstop.win_condition.l1.locator_group = "goto";
				pchar.quest.woodstop.win_condition.l1.locator = "woodstop";
				pchar.quest.woodstop.win_condition = "woodback";
			
				LAi_QuestDelay("return_farm_items_new_game", 0.1);
			break;

			case "150":
				//defoe tavern scene
				//Cartagena new cloister

				LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "new_cloister_garden";

				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(11, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(Pchar, "Howard_Pyle", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");	
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);	
				
				TakeNItems(Pchar,"potionwine2", 2);

			//	Pchar.mapBB4C = "info";		//Nevis	(Richards)
			//	Pchar.mapBB2B = "info";		//Barbados (Caesar)
			//	Pchar.mapBB5B = "info";		//Cayman (Hands)

				GiveItem2Character(Pchar, "mapBB1");
					GiveItem2Character(Pchar, "mapBB2A");		//alternative Barbados
				//GiveItem2Character(Pchar, "mapBB2B");
				GiveItem2Character(Pchar, "mapBB3T");
				GiveItem2Character(Pchar, "mapBB4C");
					GiveItem2Character(Pchar, "mapBB5A");		//alternative Cayman
				//GiveItem2Character(Pchar, "mapBB5B");

				ChangeCharacterAddressGroup(CharacterFromID("Defoe"), "new_cloister_garden", "quest", "defoe");
				LAi_SetSitType(CharacterFromID("Defoe"));
				Characters[GetCharacterIndex("Defoe")].dialog.CurrentNode  = "neutral";//if spoken to before the auto dialog starts
		
				pchar.quest.defoe_sit_down.win_condition.l1 = "locator";
				pchar.quest.defoe_sit_down.win_condition.l1.location = "new_cloister_garden";
				pchar.quest.defoe_sit_down.win_condition.l1.locator_group = "quest";
				pchar.quest.defoe_sit_down.win_condition.l1.locator = "defoe";
				pchar.quest.defoe_sit_down.win_condition = "defoe_sit_down";
			break;

			case "151":
				//defoe tavern scene
				//Turks fort

				LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Turks_old_Fort";

				rldGroup = "reload";
				rldLocator = "reload2";

				SetCurrentTime(11, 0);
				SetNextWeather("Clear");
				//Pchar.quest.JRH_rain = "Clear";	

				SetModel(Pchar, "Howard_Pyle", Pchar.model.animation, Pchar.sex, stf(Pchar.model.height), true);
				GiveItem2Character(Pchar, "map");
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");	
				GiveItem2Character(Pchar, "piratespistol");
				EquipCharacterByItem(Pchar, "piratespistol");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolbullets", 6);	
				
				TakeNItems(Pchar,"potionwine2", 2);

				Pchar.mapBB4C = "info";		//Nevis	(Richards)
				Pchar.mapBB2B = "info";		//Barbados (Caesar)
				Pchar.mapBB5B = "info";		//Cayman (Hands)

				GiveItem2Character(Pchar, "mapBB1");
					//GiveItem2Character(Pchar, "mapBB2A");		//alternative Barbados
				GiveItem2Character(Pchar, "mapBB2B");
				GiveItem2Character(Pchar, "mapBB3T");
				GiveItem2Character(Pchar, "mapBB4C");
					//GiveItem2Character(Pchar, "mapBB5A");		//alternative Cayman
				GiveItem2Character(Pchar, "mapBB5B");

				ChangeCharacterAddressGroup(CharacterFromID("Defoe"), "Turks_old_Fort", "quest", "defoe");
				LAi_SetSitType(CharacterFromID("Defoe"));
				Characters[GetCharacterIndex("Defoe")].dialog.CurrentNode  = "neutral";//if spoken to before the auto dialog starts
				locations[FindLocation("Turks_old_fort")].type = "silent_seashore";
			
				pchar.quest.defoe_sit_down.win_condition.l1 = "locator";
				pchar.quest.defoe_sit_down.win_condition.l1.location = "Turks_old_Fort";
				pchar.quest.defoe_sit_down.win_condition.l1.locator_group = "quest";
				pchar.quest.defoe_sit_down.win_condition.l1.locator = "defoe";
				pchar.quest.defoe_sit_down.win_condition = "defoe_sit_down";
			break;
	}






	Reinit_KhaelRoa();

//================================| BEGINNING QUESTS |================================//
	//Tortuga Atmosphere
	PChar.quest.Tortuga_atmosphere.win_condition.l1 = "location";
	PChar.quest.Tortuga_atmosphere.win_condition.l1.character = PChar.id;
	PChar.quest.Tortuga_atmosphere.win_condition.l1.location = "Tortuga_port";
	PChar.quest.Tortuga_atmosphere.win_condition = "Tortuga_atmosphere";
	//Tortuga Atmosphere

	//JRH: Cartagena New_cloister
	pchar.quest.cloister_start.win_condition.l1 = "location";
	pchar.quest.cloister_start.win_condition.l1.location = "new_cloister_garden";
	pchar.quest.cloister_start.win_condition = "cloister_start";

	pchar.quest.maze_fountain.win_condition.l1 = "location";
	pchar.quest.maze_fountain.win_condition.l1.location = "BB_Eden_maze";
	pchar.quest.maze_fountain.win_condition = "maze_fountain";

//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// PB: Modify Default Relations
	SetRelationsAsNation(ENGLAND);					// Set nations as per England for story start
	SetRMRelation(PChar, PIRATE, REP_LEAVEMIN);		// You ARE a pirate
}
