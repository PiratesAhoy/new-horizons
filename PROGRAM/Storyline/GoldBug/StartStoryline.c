void StartStoryLine()
{
	string loadPort = "";
	string rldGroup;
	string rldLocator;
	//loadPort = "Redmond_Port";
	loadPort = "Charleston_Port";

	ref PChar = GetMainCharacter();	
	Pchar.perks.list.BasicCommerce = true;				
	Pchar.perks.list.BasicLandOwner = true;
	Pchar.perks.list.IronWill = true;		
	Pchar.perks.freepoints = 0;
	Pchar.rank = 5;				
	
	Pchar.skill.Leadership = "5";
	Pchar.skill.Fencing = "2";		
	Pchar.skill.Sailing = "1";
	Pchar.skill.Accuracy = "1";
	Pchar.skill.Cannons = "1";
	Pchar.skill.Grappling = "1";
	Pchar.skill.Repair = "1";
	Pchar.skill.Defence = "1";
	Pchar.skill.Commerce = "3";
	Pchar.skill.Sneak = "5";

	LAi_SetHP(Pchar, 80.0, 80.0);

	Pchar.wealth = "0";
	Pchar.quest.Jupiter_gold = "0";

	AddLandToCharacter(&Pchar, "Redmond", AMERICA, 4)

	Pchar.perks.list.Gunman = true;
	Pchar.perks.list.BasicDefence = true;
	Pchar.perks.list.GunProfessional = true;
	Pchar.perks.list.GunFighter = true;
		
	AddMoneyToCharacter(Pchar,-10000);
	DeleteAttribute(Pchar, "items");		//to get rid of cutlass + small pistol
	DeleteAttribute(Pchar,"ship.type");
	DeleteAttribute(Pchar,"ship.name");
	EmptyShip(Pchar);

	GiveItem2Character(characterFromID("Axel von Fersen"), "bladeA2");
	EquipCharacterbyItem(characterFromID("Axel von Fersen"), "bladeA2");
	GiveItem2Character(characterFromID("client4"), "bladeA2");
	EquipCharacterbyItem(characterFromID("client4"), "bladeA2");
	GiveItem2Character(characterFromID("maroon5"), "bladeirontool");
	EquipCharacterbyItem(characterFromID("maroon5"), "bladeirontool");
	GiveItem2Character(characterFromID("deserter_us1"), "bladerammer");
	EquipCharacterbyItem(characterFromID("deserter_us1"), "bladerammer");
	GiveItem2Character(characterFromID("white_trash2"), "bladeanchor");
	EquipCharacterbyItem(characterFromID("white_trash2"), "bladeanchor");

	SetCharacterShipLocation(characterFromID("Moultrie_guard1"), "Fort_Moultrie_shore");
	SetCharacterShipLocation(characterFromID("Claude Frollo"), "Fort_Moultrie_shore");
	SetCharacterShipLocation(characterFromID("Claude Frollo2"), "Fort_Moultrie_shore");
	SetCharacterShipLocation(characterFromID("Landlady"), "Fort_Moultrie_shore");

	SetCharacterShipLocation(characterFromID("Edgar Allan Poe"), "Fort_Moultrie");
	SetCharacterShipLocation(characterFromID("Medicine Woman"), "Fort_Moultrie");
	SetCharacterShipLocation(characterFromID("KP"), "Fort_Moultrie");

	SetCharacterShipLocation(characterFromID("Moultrie_guard2"), "GB_Charleston_port");
	SetCharacterShipLocation(characterFromID("Lieutenant G"), "GB_Charleston_port");
	SetCharacterShipLocation(characterFromID("Moultrie_guard3"), "Legrands_boathouse");
	SetCharacterShipLocation(characterFromID("Moultrie_guard4"), "GB_Charleston_port");
	SetCharacterShipLocation(characterFromID("Moultrie_guard5"), "GB_Charleston_port");
	SetCharacterShipLocation(characterFromID("Moultrie_guard6"), "GB_Charleston_port");
	SetCharacterShipLocation(characterFromID("Moultrie_guard7"), "GB_Charleston_port");
	SetCharacterShipLocation(characterFromID("Moultrie_guard8"), "GB_Charleston_port");
	SetCharacterShipLocation(characterFromID("Moultrie_guard9"), "GB_Charleston_port");
	SetCharacterShipLocation(characterFromID("Moultrie_guard10"), "Charleston_shore");		//raft
	SetCharacterShipLocation(characterFromID("Charleston_guard1"), "Maroon_hideout");		//raft
	SetCharacterShipLocation(characterFromID("Charleston_guard2"), "Bishops_Hostel");		//raft
	SetCharacterShipLocation(characterFromID("Maroon5"), "Charleston_passage");			//raft, way home
	SetCharacterShipLocation(characterFromID("maroon_girl"), "Bishops_hostel");			//treasurechest later
	SetCharacterShipLocation(characterFromID("deserter_us1"), "Bishops_hostel");			//sacks1 later
	SetCharacterShipLocation(characterFromID("white_trash1"), "Bishops_hostel");			//sacks2 later
	SetCharacterShipLocation(characterFromID("indian_bandit"), "Bishops_hostel");			//sacks3 later

	SetCharacterShipLocation(characterFromID("mystery_monk"), "Legrands_boathouse");		//sacks1 later
	SetCharacterShipLocation(characterFromID("box_ghost"), "Legrands_boathouse");			//sacks2 later
	SetCharacterShipLocation(characterFromID("gate_ghost"), "Legrands_boathouse");			//sacks3 later
	SetCharacterShipLocation(characterFromID("zombie1"), "Legrands_boathouse");			//raft3 later
	SetCharacterShipLocation(characterFromID("zombie2"), "Legrands_boathouse");			//treasurechest

	CaptureTownForNation("Greenford", AMERICA);
	Pchar.quest.exchange_items_officer = "no";	//for the rest of this quest, code in Landinterface.c
	Pchar.quest.disable_rebirth = true;
//	bSuppressResurrection = true;
	
	LAi_QuestDelay("Fort_label_2", 0.1);
	LAi_QuestDelay("Fort_label_3", 0.1);
	LAi_QuestDelay("Tower_label_2", 0.1);
	LAi_QuestDelay("Tower_label_3", 0.1);

	pchar.quest.look_rock.win_condition.l1 = "locator";
	pchar.quest.look_rock.win_condition.l1.location = "Bishops_hostel";
	pchar.quest.look_rock.win_condition.l1.locator_group = "goto";
	pchar.quest.look_rock.win_condition.l1.locator = "look_rock";
	pchar.quest.look_rock.win_condition = "look_rock";

	pchar.quest.look_rockB.win_condition.l1 = "locator";
	pchar.quest.look_rockB.win_condition.l1.location = "Bishops_hostel";
	pchar.quest.look_rockB.win_condition.l1.locator_group = "goto";
	pchar.quest.look_rockB.win_condition.l1.locator = "look_rockB";
	pchar.quest.look_rockB.win_condition = "look_rockB";

	pchar.quest.look_rockC.win_condition.l1 = "locator";
	pchar.quest.look_rockC.win_condition.l1.location = "Bishops_hostel";
	pchar.quest.look_rockC.win_condition.l1.locator_group = "goto";
	pchar.quest.look_rockC.win_condition.l1.locator = "look_rockC";
	pchar.quest.look_rockC.win_condition = "look_rockC";

	pchar.quest.prison_stop.win_condition.l1 = "locator";
	pchar.quest.prison_stop.win_condition.l1.location = "Fort_Moultrie_prison";
	pchar.quest.prison_stop.win_condition.l1.locator_group = "goto";
	pchar.quest.prison_stop.win_condition.l1.locator = "stop";
	pchar.quest.prison_stop.win_condition = "prison_stop";

	
		//GAME START
			SetCurrentTime(12.00, 0);
			SetNextWeather("Clear");
		
			sTeleportLocName = "Sullivan_shore3";
			rldGroup = "reload";
			rldLocator = "reload1";	

			GiveItem2Character(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "bladeemptysack_B");
			EquipCharacterbyItem(Pchar, "bladeemptysack_B");
			GiveItem2Character(Pchar, "pistolmtoon");
			EquipCharacterbyItem(Pchar, "pistolmtoon");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");

			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			
			Pchar. = "no";
			Pchar.quest.FM_exit_stones = "phase1";
			Pchar.quest.Legrands_fireplace = "fire1";
			Pchar.quest.Legrands_damper = "half_open";
			Pchar.quest.Legrands_logs = 0;
			Pchar.quest.Legrands_hens = 0;
			Pchar.quest.Legrands_shells = 0;
			Pchar.quest.detected_goldbug = "nothing";
			Pchar.quest.backyard = "closed";
			Pchar.quest.Fort_password = "no";
			//Pchar.quest.Fort_password = "yes";			//testing yes
			Pchar.quest.house_box1 = "locked";
			Pchar.quest.boathouse = "return";
			Pchar.quest.crypto_full_text = "first_time";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "yes";		//opened later
			Pchar.quest.Chinatown_malaria = "yes";		//opened later

			LAi_SetStayType(Pchar);


		    LAi_QuestDelay("hunting_birds", 0.001);	//starter
		
			LAi_QuestDelay("FM_exit_stones_turn_around", 0.1);
			LAi_QuestDelay("fort_closed", 0.1);
			LAi_QuestDelay("fort_shore_pier_boat", 0.1);
			LAi_QuestDelay("fort_shore_pier", 0.1);
			LAi_QuestDelay("Charleston_steam_frigate", 0.1);
			LAi_QuestDelay("church_sounds_first", 0.1);
			LAi_QuestDelay("Charleston_priest", 0.1);
			LAi_QuestDelay("bridge_broken_A", 0.1);
			LAi_QuestDelay("town_exit_closed", 0.1);
			LAi_QuestDelay("Chinatown_malaria", 0.1);

			pchar.quest.Kidd_storyteller.win_condition.l1 = "locator";
			pchar.quest.Kidd_storyteller.win_condition.l1.location = "Kidds_cabin";
			pchar.quest.Kidd_storyteller.win_condition.l1.locator_group = "goto";
			pchar.quest.Kidd_storyteller.win_condition.l1.locator = "Kidd";
			pchar.quest.Kidd_storyteller.win_condition = "Kidd_storyteller";
		

	

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
	SetRelationsAsNation(AMERICA);	// Set nations as per America
}
