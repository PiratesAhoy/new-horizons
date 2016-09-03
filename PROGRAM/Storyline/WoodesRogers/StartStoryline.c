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
	ch.Flags.Personal = 3;
	ch.Flags.Personal.texture = 4;
	Towns[GetTownIndex("Khael Roa")].gov = "Swedish Guy";

	Locations[FindLocation("IslaMona_port_exit")].models.always.locators = "QCexit_l_wr2";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.name = "Reload1";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.go = "Kristiania_canyon";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.emerge = "reload2";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.autoreload = "0";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.label = "";
	Locations[FindLocation("IslaMona_port_exit")].reload.l1.disable = 0;

	DeleteAttribute(PChar, "quest.Install_Voysey_And_Blythe");										//disables sidequest in Nevis
	DeleteAttribute(&Locations[FindLocation("QC_town")],"vcskip");									//disables sidequest in Nevis
	ChangeCharacterAddress(characterFromID("Marc Blacque"), "none", ""); 							//disables Blaque sidequest in Port Royal 
	Characters[GetCharacterIndex("Thomas O'Reily")].Dialog.Filename = "Cornelis Huijser_dialog.c";	//disables O'Reilly sidequest in Port Royal

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
	GiveItem2Character(characterFromID("wr_cor3"), "pistol_armchair"); EquipCharacterbyItem(characterFromID("wr_cor3"), "pistol_armchair");
	GiveItem2Character(characterFromID("wr_fralut"), "blade3carpets"); EquipCharacterbyItem(characterFromID("wr_fralut"), "blade3carpets");
	GiveItem2Character(characterFromID("wr_fsh"), "bladearmchair"); EquipCharacterbyItem(characterFromID("wr_fsh"), "bladearmchair");
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
	GiveItem2Character(characterFromID("Hands"), "pistol206"); EquipCharacterbyItem(characterFromID("Hands"), "pistol206");
	GiveItem2Character(characterFromID("Caesar"), "pistol202"); EquipCharacterbyItem(characterFromID("Caesar"), "pistol202");
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

	InitQCBrothel();	//even if it's off it's now on
	InitBrothelRoom("QC_brothel_upstairs");

	InitTortugaBrothel();

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
	GiveItem2Character(characterFromID("wr_cor3"), "pistol_armchair");		
	EquipCharacterbyItem(characterFromID("wr_cor3"), "pistol_armchair");
	GiveItem2Character(characterFromID("wr_fralut"), "blade3carpets");		
	EquipCharacterbyItem(characterFromID("wr_fralut"), "blade3carpets");
	GiveItem2Character(characterFromID("wr_fsh"), "bladearmchair");		
	EquipCharacterbyItem(characterFromID("wr_fsh"), "bladearmchair");
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
	GiveItem2Character(CharacterFromID("Hands"),"pistol206");
	EquipCharacterByItem(CharacterFromID("Hands"), "pistol206");
	GiveItem2Character(CharacterFromID("Caesar"),"pistol202");
	EquipCharacterByItem(CharacterFromID("Caesar"), "pistol202");
	GiveItem2Character(characterFromID("gm_crew1"), "bladeboathook_1");		
	EquipCharacterbyItem(characterFromID("gm_crew1"), "bladeboathook_1");
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

	SetCharacterShipLocation(characterFromID("gm_crew1"), "swamp_island1");		//fallen_tree, diff pos
	SetCharacterShipLocation(characterFromID("gm_crew2"), "swamp_island2");		//raft2
	SetCharacterShipLocation(characterFromID("gm_crew3"), "mutiny_deck");		//boat beside ship
	SetCharacterShipLocation(characterFromID("gm_crew4"), "swamp_island1");		//boat close to shore
	SetCharacterShipLocation(characterFromID("gm_crew5"), "swamp_island1");		//sloop
	SetCharacterShipLocation(characterFromID("gm_crew7"), "at_sea_in_fog");		//raft2 far out at sea
	SetCharacterShipLocation(characterFromID("gm_crew8"), "at_sea_in_fog");		//HMS_Endeavour far out at sea
//Q2
	SetCharacterShipLocation(characterFromID("gm_crew11"), "bb_Eden_passage");
	SetCharacterShipLocation(characterFromID("gm_crew12"), "BB_upper_cave");	//tartane50
	SetCharacterShipLocation(characterFromID("gm_crew14"), "BB_isle");		//tartane50

	SetCharacterShipLocation(characterFromID("gm_crew15"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew16"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew17"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew18"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew19"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew20"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew21"), "Kristiania_port");
	SetCharacterShipLocation(characterFromID("gm_crew22"), "BB_prison_port");	//Gunboat at port
	SetCharacterShipLocation(characterFromID("gm_crew23"), "BB_prison_port");	//Gunboat at prison

	SetCharacterShipLocation(characterFromID("wr_mummy1"), "Kristiania_shipwreck");	//obj_raft3
	SetCharacterShipLocation(characterFromID("wr_mummy2"), "Kristiania_port");	//obj_invisible	
	SetCharacterShipLocation(characterFromID("wr_mummy3"), "Turks_wreck_shore");	//obj_cutter_wreck
	SetCharacterShipLocation(characterFromID("wr_mummy4"), "Turks_wreck_shore");	//obj_PrisonShip1

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
	

	if(ENABLE_CHEATMODE) ChangeCharacterAddressGroup(characterFromID("Teach_head"), "mutiny_cabin", "goto", "head");

	Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = 1;		//governors residence

//Q2:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	
//Quest 2
	Pchar.quest.BB_isl1_ladder = "way_up";



		Pchar.quest.WR_start = "1";	//normal quest start
	//	Pchar.quest.WR_start = "30";	//Eden passage
	//	Pchar.quest.WR_start = "35";	//Eden estate

	//	Pchar.quest.WR_start = "47";	//french surgeons Tortuga
	//	Pchar.quest.WR_start = "48";	//Richards monastary

	//	Pchar.quest.WR_start = "50";	//Caesar 
	//	Pchar.quest.WR_start = "57";	//Caesar Maynard Citadel Rock
	//	Pchar.quest.WR_start = "58";	//Caesar Turks
	//	Pchar.quest.WR_start = "59";	//Caesar Sloop

	//	Pchar.quest.WR_start = "62";	//Hands Charleston
	//	Pchar.quest.WR_start = "64";	//Hands outsk - port - alcove - (POTC dungeons)
	//	Pchar.quest.WR_start = "66";	//Hands alcove
	//	Pchar.quest.WR_start = "68";	//Hands prison2

	//	Pchar.quest.WR_start = "90";	//Kristiania canyon
	//	Pchar.quest.WR_start = "91";	//BB island1	
				
	//	Pchar.quest.WR_start = "100";	//alchemy


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
				//Eden passage

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "bb_Eden_passage";
			
				rldGroup = "reload";
				rldLocator = "reload1_back";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
			break;

			case "35":
				//Eden estate
		LAi_SetImmortal(pchar, true);		//temp
		GiveItem2Character(Pchar, "map");	//temp
				Pchar.quest.disable_rebirth = true;

				rldGroup = "reload";
			//	sTeleportLocName = "bb_Eden_estate";
			//	rldLocator = "reload1";

				sTeleportLocName = "bb_Eden_tunnel";
				rldLocator = "reload2_back";
				
				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";

				Pchar.estate_direction = "Teach_house";
			
			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterByItem(Pchar, "bladeX4");



			ChangeCharacterAddressGroup(CharacterFromID("Teach"), "BB_Eden_tunnel", "reload", "reload2_back");

				pchar.quest.Eden_elevator1.win_condition.l1 = "locator";
				pchar.quest.Eden_elevator1.win_condition.l1.location = "BB_Eden_tunnel";
				pchar.quest.Eden_elevator1.win_condition.l1.locator_group = "goto";
				pchar.quest.Eden_elevator1.win_condition.l1.locator = "elevator1";
				pchar.quest.Eden_elevator1.win_condition = "Eden_elevator_steplock1";

				pchar.quest.Eden_elevator2.win_condition.l1 = "locator";
				pchar.quest.Eden_elevator2.win_condition.l1.location = "BB_Eden_tunnel";
				pchar.quest.Eden_elevator2.win_condition.l1.locator_group = "goto";
				pchar.quest.Eden_elevator2.win_condition.l1.locator = "elevator2";
				pchar.quest.Eden_elevator2.win_condition = "Eden_elevator_steplock2";

				pchar.quest.Eden_gate_stop1.win_condition.l1 = "locator";
				pchar.quest.Eden_gate_stop1.win_condition.l1.location = "BB_Eden_tunnel";
				pchar.quest.Eden_gate_stop1.win_condition.l1.locator_group = "goto";
				pchar.quest.Eden_gate_stop1.win_condition.l1.locator = "gate_stop1";
				pchar.quest.Eden_gate_stop1.win_condition = "Eden_gate_stop1";

				pchar.quest.Eden_gate_stop2.win_condition.l1 = "locator";
				pchar.quest.Eden_gate_stop2.win_condition.l1.location = "BB_Eden_tunnel";
				pchar.quest.Eden_gate_stop2.win_condition.l1.locator_group = "goto";
				pchar.quest.Eden_gate_stop2.win_condition.l1.locator = "gate_stop2";
				pchar.quest.Eden_gate_stop2.win_condition = "Eden_gate_stop2";
			
				pchar.quest.Eden_gate2_stop.win_condition.l1 = "locator";
				pchar.quest.Eden_gate2_stop.win_condition.l1.location = "BB_Eden_tunnel";
				pchar.quest.Eden_gate2_stop.win_condition.l1.locator_group = "goto";
				pchar.quest.Eden_gate2_stop.win_condition.l1.locator = "gate2_stop";
				pchar.quest.Eden_gate2_stop.win_condition = "Eden_gate2_stop";
			break;
		
			case "47":
				//french surgeons Tortuga
				
				sTeleportLocName = "Tortuga_townhall";	//to get JRH loc files from start
			//	sTeleportLocName = "Tortuga_tower";
			//	sTeleportLocName = "Tortuga_tower_stairs_B";
				rldGroup = "reload";
			//	rldLocator = "reload1";
				rldLocator = "locator2";
			//	rldLocator = "reloadQ4";
			//	rldLocator = "reload4";
				SetCurrentTime(12, 0);
			//	SetCurrentTime(2, 0);

				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";
				//SetNextWeather("Heavy Storm");

				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);
			break;

			case "48":
				//Richards graveyard
		//LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "BB_graveyard";

				rldGroup = "reload";
				rldLocator = "reload6";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");	
			break;

			case "57":
				//Caesar Mayanard Citadel Rock				

				sTeleportLocName = "Eleuthera_tavern_upstairs";
				rldGroup = "reload";
				rldLocator = "reload3_back";

				LAi_SetImmortal(pchar, true);
				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade27");
				EquipCharacterByItem(Pchar, "blade27");
				GiveItem2Character(Pchar, "pistolmtoon");
				EquipCharacterByItem(Pchar, "pistolmtoon");
				TakeNItems(Pchar,"gunpowder", 6);
				TakeNItems(Pchar,"pistolgrapes", 6);

			//	GiveItem2Character(Pchar, "bladelever");	//temp
			//	GiveItem2Character(Pchar, "map");		//temp
			//	GiveItem2Character(Pchar, "bladeanchor_big");
			//	EquipCharacterByItem(Pchar, "bladeanchor_big");	

				LAi_QuestDelay("Citadel_rock_start", 0.1);
			break;
		
			case "58":
				//Caesar Turks
		//LAi_SetImmortal(pchar, true);	//temp

		//		Pchar.quest.disable_rebirth = true;
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

				Locations[FindLocation("Turks_tavern_kitchen")].reload.l5.disable = 0;
				Locations[FindLocation("Turks_port")].models.day.charactersPatch = "Margarita_patch_roof";
				Locations[FindLocation("Turks_port")].models.night.charactersPatch = "Margarita_patch_roof";

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
				//Caesar Sloop
		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				rldGroup = "reload";
			

				rldLocator = "reload1";
			//	sTeleportLocName = "Turks_sewer";

				sTeleportLocName = "Turks_wreck_shore";

			//	rldLocator = "reload2";
			//	sTeleportLocName = "BB_sloop_cabin";

			//	rldLocator = "reload1";
			//	sTeleportLocName = "BB_sloop_hold";	
			

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");	
			break;

			case "62":
				//Charleston
		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Charlestown_port";
			
				rldGroup = "reload";
				rldLocator = "reload8_back";

				//SetCurrentTime(12, 0);
			SetCurrentTime(2, 0);
				//SetNextWeather("Clear");
			SetNextWeather("Heavy Rain");

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
				
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
				
				LAi_QuestDelay("start_Maltains", 0.1);
			break;

			case "64":
				//Hands prison outsk - port - alcove - (POTC dungeons)
		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "bb_prison_outskirt";
			
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(18, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";

				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				
				ChangeCharacterAddressGroup(CharacterFromID("Teach"), "BB_prison_outskirt", "officers", "reload2_2");

				Pchar.quest.prison_pier = "phase0";
				Pchar.quest.prison_elevator = "down";
				Pchar.quest.prison_opening = "stairs";
				Pchar.quest.prison_opening2 = "prison";

				LAi_QuestDelay("prison_alcove", 0.1);

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
			break;

			case "66":
				//Hands alcove etc
		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "bb_prison_alcove";
			
				rldGroup = "reload";
				rldLocator = "reload2";

				SetCurrentTime(18, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";

				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				
				ChangeCharacterAddressGroup(CharacterFromID("Teach"), "BB_prison_outskirt", "officers", "reload2_2");

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
		LAi_SetImmortal(pchar, true);	//temp

				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "bb_prison2";
			
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(18, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";

				GiveItem2Character(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");
				
				ChangeCharacterAddressGroup(CharacterFromID("Teach"), "BB_prison_outskirt", "officers", "reload2_2");

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
			break;

			case "90":
				//Kristiania Canyon

		//LAi_SetImmortal(pchar, true);	//temp
				SetNextWind("W",30);			//good for visible ship flags
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "Kristiania_canyon";
			//	sTeleportLocName = "Kristiania_center2";
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(12, 0);
			//SetCurrentTime(19, 0);			//testing bad randitems
			//SetCurrentTime(7, 0);			//testing bad randitems
				SetNextWeather("Clear");

				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			//	ChangeCharacterAddressGroup(CharacterFromID("Teach"), "BB_island1", "goto", "citizen03");			
				GiveItem2Character(Pchar, "blade1");
				EquipCharacterByItem(Pchar, "blade1");

				AddCharacterGoods(Pchar, GOOD_COTTON, 1);
				AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 145);
				AddCharacterGoods(Pchar, GOOD_SUGAR, 250);
				
				LAi_QuestDelay("KR_center_backloop1", 0.1);
				LAi_QuestDelay("KR_center_backloop2", 0.1);
				LAi_QuestDelay("KR_lower_backloop", 0.1);

				LAi_QuestDelay("BB_tower_top_backloop", 0.1);
				//LAi_QuestDelay("BB_tower_backloop", 0.1);	//only if door to upper cave is locked
				
				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				LAi_QuestDelay("BB_lower_cave_backloop", 0.1);
			break;

			case "91":
				//Q2: BB_island1
		
				Pchar.quest.disable_rebirth = true;

				sTeleportLocName = "BB_island1";
				rldGroup = "reload";
				rldLocator = "reload1";

				SetCurrentTime(12, 0);
			//	SetCurrentTime(19, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";
				
				SetModel(PChar, "Howard_Pyle", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);

				GiveItem2Character(Pchar, "bladelever3");		
				EquipCharacterbyItem(Pchar, "bladelever3");
				GiveItem2Character(Pchar, "bladeflag_pir"); 
				GiveItem2Character(Pchar, "bladeflag_pir1");
			//	GiveItem2Character(Pchar, "bladeflag_pir2"); 
			//	GiveItem2Character(Pchar, "bladeflag_pir3");
			//	GiveItem2Character(Pchar, "bladeflag_pir4"); 
			//	GiveItem2Character(Pchar, "bladeflag_pir5");
				GiveItem2Character(Pchar, "bladeflag_pir6");

				ChangeCharacterAddressGroup(CharacterFromID("Teach"), "BB_island1", "goto", "citizen03");

				AddMoneyToCharacter(Pchar,-10000);

				AddCharacterGoods(Pchar, GOOD_GOLD, 1);
				AddCharacterGoods(Pchar, GOOD_SILVER, 1);

				AddCharacterGoods(Pchar, GOOD_COTTON, 1);
				AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 145);
				AddCharacterGoods(Pchar, GOOD_SUGAR, 250);
				
				
				LAi_QuestDelay("KR_center_backloop1", 0.1);
				LAi_QuestDelay("KR_center_backloop2", 0.1);
				LAi_QuestDelay("KR_church", 0.1);
				LAi_QuestDelay("BB_tower_top_backloop", 0.1);
				//LAi_QuestDelay("BB_tower_backloop", 0.1);	//only if door to upper cave is locked
				
				LAi_QuestDelay("BB_upper_cave_backloop", 0.1);
				LAi_QuestDelay("BB_lower_cave_backloop", 0.1);
				LAi_QuestDelay("pick_up_grotto_boom", 0.1);
				LAi_QuestDelay("BB_lower_cave_steplock", 0.1);
				LAi_QuestDelay("BB_lower_cave_fill_chests", 0.1);
				LAi_QuestDelay("BB_lower_cave_deathtrap", 0.1);
			break;

			
			case "100":
				//Q2: alchemy
		//LAi_SetImmortal(pchar, true);	//temp
	Pchar.quest.disable_rebirth = true;
	//DeleteAttribute(PChar, "quest.disable_rebirth");
	ChangeCharacterAddressGroup(CharacterFromID("Minerva"), "wr_port", "goto", "goto20");	//temp

				sTeleportLocName = "wr_port";
				rldGroup = "reload";
				rldLocator = "reload2";

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";

				GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
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
				SetCharacterShipLocation(Pchar, "wr_port");

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
			
				Pchar.quest.Rdm_officiant = "Claire";
				
			Locations[FindLocation("wr_farm_alchemy")].reload.l2.disable = 0;			//to alchemy2
			Locations[FindLocation("wr_farm_servant")].reload.l2.disable = 0;			//to alchemy2

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
			locations[FindLocation("wr_farm_alchemy2")].id.label = "Rogers' alchemy laboratory";

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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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
	}






	Reinit_KhaelRoa();

//================================| BEGINNING QUESTS |================================//
	//Tortuga Atmosphere
	PChar.quest.Tortuga_atmosphere.win_condition.l1 = "location";
	PChar.quest.Tortuga_atmosphere.win_condition.l1.character = PChar.id;
	PChar.quest.Tortuga_atmosphere.win_condition.l1.location = "Tortuga_port";
	PChar.quest.Tortuga_atmosphere.win_condition = "Tortuga_atmosphere";
	//Tortuga Atmosphere
//===============================| QUESTS SECTION END |===============================//

	ReloadProgressUpdate();

	AllDaysCount = 1;//MAXIMUS: calculates days amount (updating in calendar.c)
	PChar.newGameStart = true;//MAXIMUS: for adding new locators

	LoadMainCharacterInFirstLocation(sTeleportLocName, rldGroup, rldLocator, loadPort); // KK

	// PB: Modify Default Relations
	SetRelationsAsNation(ENGLAND);					// Set nations as per England for story start
	SetRMRelation(PChar, PIRATE, REP_LEAVEMIN);		// You ARE a pirate
}
