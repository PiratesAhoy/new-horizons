//#include "DIALOGS\Divers_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.snd = "Voice\CLLA\CLLA001";
			PlaySound("AMBIENT\CRYPT\daemon3.wav");
			PlaySound("AMBIENT\CRYPT\daemon3.wav");
			PlaySound("AMBIENT\CRYPT\daemon3.wav");
			PlaySound("AMBIENT\CRYPT\daemon3.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "where_to";
		break;

		case "where_to":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l0 = DLG_TEXT[3];
			link.l0.go = "exit";
		
			link.l1 = DLG_TEXT[4];	//LEGRANDS HOUSE after shores
			link.l1.go = "1";
			link.l2 = DLG_TEXT[5];	//LEGRANDS HOUSE day2
			link.l2.go = "2";
			link.l3 = DLG_TEXT[6];	//JUPITERS PAPER MISSION
			link.l3.go = "3";
			link.l4 = DLG_TEXT[7];	//FORT
			link.l4.go = "4";
			link.l5 = DLG_TEXT[8];	//CHARLESTON
			link.l5.go = "5";
			link.l6 = DLG_TEXT[9];	//CHINATOWN
			link.l6.go = "6";
			link.l7 = DLG_TEXT[10];	//CHINAROOM
			link.l7.go = "7";
			link.l8 = DLG_TEXT[11];	//PLANTATION
			link.l8.go = "8";
			link.l9 = DLG_TEXT[12];	//MAROONS ETC
			link.l9.go = "9";
			link.l10 = DLG_TEXT[13];//BISHOP'S HOSTEL, FIRST TIME  	
			link.l10.go = "10";
			link.l11 = DLG_TEXT[14];//SPYGLASS TOUR + PYM TOUR
			link.l11.go = "11";
			link.l12 = DLG_TEXT[15];//BISHOP'S HOSTEL, SECOND TIME
			link.l12.go = "12";
			link.l13 = DLG_TEXT[16];//POE'S + JUP BOAT, HUT
			link.l13.go = "13";
			link.l14 = DLG_TEXT[17];//FORT REVOLVER
			link.l14.go = "14";
			link.l15 = DLG_TEXT[18];//POE CHURCH
			link.l15.go = "15";
			link.l16 = DLG_TEXT[19];//BISHOP'S HOSTEL, LAST TIME
			link.l16.go = "16";						
		break;

		case "where_to_again":
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			PlaySound("AMBIENT\CRYPT\daemon1.wav");	
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l0 = DLG_TEXT[3];
			link.l0.go = "exit";
		
			link.l1 = DLG_TEXT[4];	//LEGRANDS HOUSE after shores
			link.l1.go = "1";
			link.l2 = DLG_TEXT[5];	//LEGRANDS HOUSE day2
			link.l2.go = "2";
			link.l3 = DLG_TEXT[6];	//JUPITERS PAPER MISSION
			link.l3.go = "3";
			link.l4 = DLG_TEXT[7];	//FORT
			link.l4.go = "4";
			link.l5 = DLG_TEXT[8];	//CHARLESTON
			link.l5.go = "5";
			link.l6 = DLG_TEXT[9];	//CHINATOWN
			link.l6.go = "6";
			link.l7 = DLG_TEXT[10];	//CHINAROOM
			link.l7.go = "7";
			link.l8 = DLG_TEXT[11];	//PLANTATION
			link.l8.go = "8";
			link.l9 = DLG_TEXT[12];	//MAROONS ETC
			link.l9.go = "9";
			link.l10 = DLG_TEXT[13];//BISHOP'S HOSTEL, FIRST TIME  	
			link.l10.go = "10";
			link.l11 = DLG_TEXT[14];//SPYGLASS TOUR + PYM TOUR
			link.l11.go = "11";
			link.l12 = DLG_TEXT[15];//BISHOP'S HOSTEL, SECOND TIME
			link.l12.go = "12";
			link.l13 = DLG_TEXT[16];//POE'S + JUP BOAT, HUT
			link.l13.go = "13";
			link.l14 = DLG_TEXT[17];//FORT REVOLVER
			link.l14.go = "14";
			link.l15 = DLG_TEXT[18];//POE CHURCH
			link.l15.go = "15";
			link.l16 = DLG_TEXT[19];//BISHOP'S HOSTEL, LAST TIME
			link.l16.go = "16";						
		break;
	
		case "start_teleport":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Teach_head_teleport");
		break;

		case "1":
			//LEGRANDS HOUSE after shores
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
				


			SetCurrentTime(12.00, 0);
			SetNextWeather("Clear");

			Pchar.quest.FM_exit_stones = "phase1";
			Pchar.quest.Legrands_fireplace = "fire1";
			Pchar.quest.Legrands_damper = "half_open";
			Pchar.quest.Legrands_logs = 0;
			Pchar.quest.backyard = "closed";		
			Pchar.quest.Fort_password = "no";
			Pchar.quest.house_box1 = "locked";
			Pchar.quest.boathouse = "return";
			Pchar.quest.crypto_full_text = "first_time";
			Pchar.quest.Fort_visit = "neutral";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "yes";		//opened later
			Pchar.quest.Chinatown_malaria = "yes";		//opened later	

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Sullivan_jungle1", "officers", "reload2_1");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));

			GiveItem2Character(characterFromID("Jupiter"), "bladebirdsack");
			EquipCharacterbyItem(characterFromID("Jupiter"), "bladebirdsack");
			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			
			Locations[FindLocation("Sullivan_shore3")].locators_radius.box.box2 = 1.0;
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box4 = 1.0;
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box5 = 1.0;
		   	
		LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
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

			//starter
			pchar.quest.visitor.win_condition.l1 = "location";
			pchar.quest.visitor.win_condition.l1.location = "Legrands_house";
			pchar.quest.visitor.win_condition = "visitor";





			Pchar.quest.Teach_head = "1";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
		
		case "2":
			//LEGRANDS HOUSE day2
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			


			SetCurrentTime(7.00, 0);
			SetNextWeather("Clear");

			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);

			Pchar.quest.FM_exit_stones = "phase1";
			Pchar.quest.Legrands_fireplace = "no_wood";
			Pchar.quest.Legrands_damper = "open";
			Pchar.quest.backyard = "closed";		
			Pchar.quest.Fort_password = "no";
			Pchar.quest.house_box1 = "open";
			Pchar.quest.boathouse = "return";
			Pchar.quest.Legrands_cauldron_w = "in_fireplace";
			Pchar.quest.Legrands_cauldron_water = "cold";	
			Pchar.quest.crypto_full_text = "first_time";
			Pchar.quest.Fort_visit = "neutral";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "yes";		//opened later
			Pchar.quest.Chinatown_malaria = "yes";		//opened later

			ChangeCharacterAddressGroup(characterFromID("Lieutenant G"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "none", "", "");
			
			Locations[FindLocation("Sullivan_shore3")].locators_radius.box.box2 = 1.0;
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box4 = 1.0;
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box5 = 1.0;

			locations[FindLocation("Legrands_kitchen")].models.always.l4 = "damper_open";	
			locations[FindLocation("Legrands_kitchen")].models.always.l2 = "";		//no wood
			locations[FindLocation("Legrands_kitchen")].models.always.l9 = "cauldron3_w";
			locations[FindLocation("Legrands_kitchen")].models.always.locators = "mediumhouse01_locators_GB0";
		   	
		LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
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
			
			//starter
			LAi_QuestDelay("Legrand_sleepy_done", 0.1);












			Pchar.quest.Teach_head = "2";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";	
		break;

		case "3":
			//JUPITERS PAPER MISSION
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	

			SetCurrentTime(08.30, 0);
			SetNextWeather("Clear");

			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			Pchar.quest.Jupiter_coin7 = "yes";
		
			Pchar.quest.FM_exit_stones = "phase1";
			Pchar.quest.Legrands_fireplace = "no_wood";
			Pchar.quest.Legrands_damper = "open";
			Pchar.quest.backyard = "closed";		
			Pchar.quest.Fort_password = "no";
			Pchar.quest.house_box1 = "open";
			Pchar.quest.boathouse = "return";
			Pchar.quest.Legrands_cauldron_w = "in_fireplace";
			Pchar.quest.Legrands_cauldron_water = "cold";
			Pchar.quest.Fort_visit = "neutral";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "yes";		//opened later	
			Pchar.quest.Chinatown_malaria = "yes";		//opened later

			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "none", "", "");
			LAi_SetStayType(characterFromID("Jupiter"));

			Locations[FindLocation("Sullivan_shore3")].locators_radius.box.box2 = 1.0;
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box4 = 1.0;
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box5 = 1.0;

			Locations[FindLocation("Sullivan_shore3")].locators_radius.box.box2 = 1.0;
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box4 = 1.0;
			Locations[FindLocation("Sullivan_shore2")].locators_radius.box.box5 = 1.0;

			Locations[FindLocation("Legrands_house")].reload.l3.disable = 0;		//grot	

			locations[FindLocation("Legrands_kitchen")].models.always.l4 = "damper_open";	
			locations[FindLocation("Legrands_kitchen")].models.always.l2 = "";		//no wood
			locations[FindLocation("Legrands_kitchen")].models.always.l9 = "cauldron3_w";
			locations[FindLocation("Legrands_kitchen")].models.always.locators = "mediumhouse01_locators_GB0";

		LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
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
		
		//	LAi_QuestDelay("Jup_paper_mission", 0.1);
			




			
			Pchar.quest.Teach_head = "3";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 4
		case "4":
			//FORT
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			
			SetCurrentTime(12.00, 0);
			SetNextWeather("Clear");	

			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "none", "", "");

			//Fort Moultrie visit 2
			Pchar.quest.Fort_M_box16 = "phase2";
			Pchar.quest.Fort_M_south_wall = "right";
			Pchar.quest.Fort_M_flag_pos = "none";

			Pchar.quest.Fort_visit = "1";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "yes";		//opened later
			Pchar.quest.Chinatown_malaria = "yes";		//opened later
			Pchar.Lut_G_cipher = "done";

			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
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
			LAi_QuestDelay("step_back_store", 0.1);






			Pchar.quest.Teach_head = "4";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 5	
		case "5":
			//CHARLESTON
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");

			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");

			Pchar.quest.Fort_visit = "1";
			Pchar.quest.Jupiter_equip = "case1";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "yes";		//opened later
			Pchar.quest.Chinatown_malaria = "yes";		//opened later
			Pchar.Lut_G_cipher = "done";

			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2_indians";
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.l4 = "fireplace_wood";
			Locations[FindLocation("Fort_Moultrie_exit")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle1")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle2")].type = "indian_jungle";

		LAi_QuestDelay("Jupiter_equip_check", 1.0);
			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
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
			
			LAi_QuestDelay("THE_ok", 1.0);		
			LAi_QuestDelay("tipi1_backloop", 0.1);
			LAi_QuestDelay("tipi2_backloop", 0.1);
			LAi_QuestDelay("open_village_full", 1.0);

			LAi_QuestDelay("step_back_church2", 0.1);
			LAi_QuestDelay("step_back_church3", 0.1);
			LAi_QuestDelay("remove_lieutenant", 0.1);	//fills some boxes Charleston 
			LAi_QuestDelay("check_medicine_bag_equipped", 0.1);


			Pchar.quest.Teach_head = "5";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 6
		case "6":
			//CHINATOWN
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			
			SetCurrentTime(12.00, 0);
			SetNextWeather("Blue Sky");

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "officers", "reload1_1");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));	

			GiveItem2Character(Pchar, "bladeX4");
			EquipCharacterbyItem(Pchar, "bladeX4");
			GiveItem2Character(Pchar, "pistoltinderbox");
			GiveItem2Character(Pchar, "clock1");
			EquipCharacterbyItem(Pchar, "clock1");
			GiveItem2Character(Pchar, "inkpen");
			GiveItem2Character(Pchar, "bird_sketch");
			GiveItem2Character(Pchar, "crypto2");
			GiveItem2Character(Pchar, "med_bag1_out");
			EquipCharacterbyItem(Pchar, "med_bag1_out");
			GiveItem2Character(Pchar, "goldbug");
	
			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");

			Pchar.quest.Fort_visit = "1";
			Pchar.quest.Jupiter_equip = "case1";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "no";		//opened later
			Pchar.Lut_G_cipher = "done";

			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2_indians";
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.l4 = "fireplace_wood";
			Locations[FindLocation("Fort_Moultrie_exit")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle1")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle2")].type = "indian_jungle";
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;

			LAi_QuestDelay("Jupiter_equip_check", 1.0);
			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
			LAi_QuestDelay("FM_exit_stones_turn_around", 0.1);
			LAi_QuestDelay("fort_closed", 0.1);
			LAi_QuestDelay("fort_shore_pier_boat", 0.1);
			LAi_QuestDelay("fort_shore_pier", 0.1);
			LAi_QuestDelay("Charleston_steam_frigate", 0.1);
			LAi_QuestDelay("church_sounds_first", 0.1);
			LAi_QuestDelay("Charleston_priest", 0.1);
			LAi_QuestDelay("bridge_broken_A", 0.1);	
			Locations[FindLocation("GB_Charleston_town")].reload.l5.disable = 0;
				
			LAi_QuestDelay("tipi1_backloop", 0.1);
			LAi_QuestDelay("tipi2_backloop", 0.1);
			LAi_QuestDelay("open_village_full", 1.0);

			LAi_QuestDelay("step_back_church2", 0.1);
			LAi_QuestDelay("step_back_church3", 0.1);
			LAi_QuestDelay("check_medicine_bag_equipped", 0.1);
			



			Pchar.quest.Teach_head = "6";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";	
		break;
//kidd 7
		case "7":
			//CHINAROOM
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			
			
			TakeNItems(characterFromID("Jupiter"),"gunpowder", 6);	
			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");

			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;
			Pchar.Lut_G_cipher = "done";




			Pchar.quest.Teach_head = "7";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";	
		break;
//kidd 8
		case "8":
			//PLANTATION
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			
			SetCurrentTime(22.00, 0);
			SetNextWeather("Clear");

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "officers", "reload1_1");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			GiveItem2Character(characterFromID("Jupiter"), "bladeX4");
			EquipCharacterbyItem(characterFromID("Jupiter"), "bladeX4");
			TakeNItems(characterFromID("Jupiter"),"gunpowder", 6);	

			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");

			Pchar.quest.Fort_visit = "1";
			Pchar.quest.Jupiter_equip = "case1";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "no";		//opened later	
			Pchar.Lut_G_cipher = "done";

			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2_indians";
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.l4 = "fireplace_wood";
			Locations[FindLocation("Fort_Moultrie_exit")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle1")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle2")].type = "indian_jungle";
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;

			LAi_QuestDelay("Jupiter_equip_check", 1.0);
			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
			LAi_QuestDelay("FM_exit_stones_turn_around", 0.1);
			LAi_QuestDelay("fort_closed", 0.1);
			LAi_QuestDelay("fort_shore_pier_boat", 0.1);
			LAi_QuestDelay("fort_shore_pier", 0.1);
			LAi_QuestDelay("Charleston_steam_frigate", 0.1);
			LAi_QuestDelay("church_sounds_first", 0.1);
			LAi_QuestDelay("Charleston_priest", 0.1);

			Locations[FindLocation("GB_Charleston_town")].reload.l5.disable = 0;
				
			LAi_QuestDelay("tipi1_backloop", 0.1);
			LAi_QuestDelay("tipi2_backloop", 0.1);
			LAi_QuestDelay("open_village_full", 1.0);

			LAi_QuestDelay("step_back_church2", 0.1);
			LAi_QuestDelay("step_back_church3", 0.1);
			LAi_QuestDelay("check_medicine_bag_equipped", 0.1);
			LAi_QuestDelay("how_to_enter_plantation_done", 0.1);	//here are all start values for Chinatown
		//LAi_QuestDelay("no_rain_cavernmedium", 0.1);	//testing to guarantee no rain in cavernmedium

			pchar.quest.Bessop_start_dialog.win_condition.l1 = "locator";
			pchar.quest.Bessop_start_dialog.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.Bessop_start_dialog.win_condition.l1.locator_group = "goto";
			pchar.quest.Bessop_start_dialog.win_condition.l1.locator = "goto26";
			pchar.quest.Bessop_start_dialog.win_condition = "Bessop_start_dialog";
	

			Pchar.quest.Teach_head = "8";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 9
		case "9":
			//MAROONS ETC
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");		
		
			SetCurrentTime(12.00, 0);
			SetNextWeather("Clear");	

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "officers", "reload1_1");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			TakeNItems(characterFromID("Jupiter"),"gunpowder", 6);	
			GiveItem2Character(characterFromID("Jupiter"), "pistoltinderbox");
			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
			
			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
			
			Pchar.quest.Fort_visit = "1";
			Pchar.quest.Jupiter_equip = "case1";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "no";		//opened later	
			Pchar.Lut_G_cipher = "done";

			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2_indians";
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.l4 = "fireplace_wood";
			Locations[FindLocation("Fort_Moultrie_exit")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle1")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle2")].type = "indian_jungle";
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;

			LAi_QuestDelay("Jupiter_equip_check", 1.0);
			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
			LAi_QuestDelay("FM_exit_stones_turn_around", 0.1);
			LAi_QuestDelay("fort_closed", 0.1);
			LAi_QuestDelay("fort_shore_pier_boat", 0.1);
			LAi_QuestDelay("fort_shore_pier", 0.1);
			LAi_QuestDelay("Charleston_steam_frigate", 0.1);
			LAi_QuestDelay("church_sounds_first", 0.1);
			LAi_QuestDelay("Charleston_priest", 0.1);
		
			Locations[FindLocation("GB_Charleston_town")].reload.l5.disable = 0;
				
			LAi_QuestDelay("tipi1_backloop", 0.1);
			LAi_QuestDelay("tipi2_backloop", 0.1);
			LAi_QuestDelay("open_village_full", 1.0);

			LAi_QuestDelay("step_back_church2", 0.1);
			LAi_QuestDelay("step_back_church3", 0.1);
			LAi_QuestDelay("check_medicine_bag_equipped", 0.1);
			LAi_QuestDelay("how_to_enter_plantation_done", 0.1);	//here are all start values for Chinatown

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box15", 2.0);
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box15 = 2.0;
			SetLocatorRadius(locations[FindLocation(Pchar.location)], "goto", "gate", 16.0);
			Locations[FindLocation("Bessop_plantation")].locators_radius.goto.gate = 16.0;

			pchar.quest.Bessop_gate_alarm.win_condition.l1 = "locator";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.location = "Bessop_plantation";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator_group = "goto";
			pchar.quest.Bessop_gate_alarm.win_condition.l1.locator = "gate";
			pchar.quest.Bessop_gate_alarm.win_condition = "Bessop_gate_alarm";



			
			Pchar.quest.Teach_head = "9";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 10
		case "10":
			//BISHOP'S HOSTEL, FIRST TIME  	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");		
		
			SetNextWeather("Clear");		
			SetCurrentTime(12.00, 0);	

			

			Pchar.quest.mar_cav_to_bridge = "open";
			Pchar.Lut_G_cipher = "done";
			Pchar.quest.town_exit_closed = "no";
			Pchar.quest.gate_other_side  = "yes";

	
			Locations[FindLocation("Maroon_cavern")].environment.weather = "true";
	locations[n].lockWeather = "Inside";
			Locations[FindLocation("Maroon_cavern")].environment.sea = "false";
			Locations[FindLocation("Maroon_cavern")].models.always.locators = "CavernMedium_locators_GB_dry";
			Locations[FindLocation("Maroon_cavern")].models.always.l4 = "";		
			Locations[FindLocation("Maroon_cavern")].models.always.l5 = "barrelC";		
			Locations[FindLocation("Maroon_cavern")].models.always.l6 = "";			
			Locations[FindLocation("Maroon_cavern")].models.always.l7 = "bottleC_cork";
			Locations[FindLocation("Charleston_shore")].models.always.locators = "pass1_l_GB9";
			Locations[FindLocation("Charleston_shore")].models.always.l5 = "rope_gibbet";	
			Locations[FindLocation("Charleston_shore")].models.always.l6 = "plank2A";
			Locations[FindLocation("Charleston_shore")].models.always.l9 = "ladder_rope";
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box29 = 0.0001;
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box40 = 1.5;
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;	
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;


			LAi_QuestDelay("maroon_hideout_boxback", 0.1);
			LAi_QuestDelay("maroon_cavern_steplock", 0.1);
			LAi_QuestDelay("bridge_broken_A", 0.1);
			LAi_QuestDelay("bridge_broken_B", 0.1);
			LAi_QuestDelay("ch_shore_bars", 0.1);



			Pchar.quest.Teach_head = "10";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 11
		case "11":
			//SPYGLASS TOUR + PYM TOUR
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
				
			SetNextWeather("Clear");		
			SetCurrentTime(7.00, 0);

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "officers", "reload1_1");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			TakeNItems(characterFromID("Jupiter"),"gunpowder", 6);	
			GiveItem2Character(characterFromID("Jupiter"), "pistoltinderbox");
			AddMoneyToCharacter(characterFromID("Jupiter"),-1000);
			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
			GiveItem2Character(characterFromID("Jupiter"), "bladelever");
			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);

			Pchar.quest.devils_seat_found = "yes";
			Pchar.quest.Fort_visit = "1";
			Pchar.quest.Jupiter_equip = "case1";
			Pchar.quest.Ch_town_box3 = "locked";		//gatehouse
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.quest.town_exit_closed = "no";		//opened later	
			Pchar.Lut_G_cipher = "done";

			Locations[FindLocation("Fort_Moultrie_exit")].models.always.locators = "smlexit_l_GB_smoke2_indians";
			Locations[FindLocation("Fort_Moultrie_exit")].models.always.l4 = "fireplace_wood";
			Locations[FindLocation("Fort_Moultrie_exit")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle1")].type = "indian_jungle";
			Locations[FindLocation("Sullivan_jungle2")].type = "indian_jungle";
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;
			Locations[FindLocation("Charleston_shore")].models.always.locators = "pass1_l_GB9";

			LAi_QuestDelay("Jupiter_equip_check", 1.0);
			LAi_QuestDelay("Legrands_kitchen_fire_level_down", 0.1);
			LAi_QuestDelay("FM_exit_stones_turn_around", 0.1);
			LAi_QuestDelay("fort_closed", 0.1);
			LAi_QuestDelay("fort_shore_pier_boat", 0.1);
			LAi_QuestDelay("fort_shore_pier", 0.1);
			LAi_QuestDelay("Charleston_steam_frigate", 0.1);
			LAi_QuestDelay("church_sounds_first", 0.1);
			LAi_QuestDelay("Charleston_priest", 0.1);
				
			Locations[FindLocation("GB_Charleston_town")].reload.l5.disable = 0;
				
			LAi_QuestDelay("tipi1_backloop", 0.1);
			LAi_QuestDelay("tipi2_backloop", 0.1);
			LAi_QuestDelay("open_village_full", 1.0);

			LAi_QuestDelay("step_back_church2", 0.1);
			LAi_QuestDelay("step_back_church3", 0.1);
			LAi_QuestDelay("check_medicine_bag_equipped", 0.1);
			LAi_QuestDelay("start_maroon_part", 0.1);

	


			Pchar.quest.Teach_head = "11";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 12
		case "12":
			//BISHOP'S HOSTEL, SECOND TIME
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			
			SetCurrentTime(7.00, 0);//yes
			SetNextWeather("Clear");	

			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "officers", "reload1_1");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));
			
			ChangeCharacterAddressGroup(characterFromID("Edgar Allan Poe"), "Poe_bedroom", "goto", "stay1");

			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
			TakeNItems(characterFromID("Jupiter"),"gunpowder", 6);	
			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);
	
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;
			Pchar.quest.mar_cav_to_bridge = "open";
			Pchar.Lut_G_cipher = "done";
			Pchar.quest.town_exit_closed = "no";

			Locations[FindLocation("Maroon_cavern")].environment.weather = "true";
	locations[n].lockWeather = "Inside";
			Locations[FindLocation("Maroon_cavern")].environment.sea = "false";
			Locations[FindLocation("Maroon_cavern")].models.always.locators = "CavernMedium_locators_GB_dry";
			Locations[FindLocation("Maroon_cavern")].models.always.l4 = "";		
			Locations[FindLocation("Maroon_cavern")].models.always.l5 = "barrelC";		
			Locations[FindLocation("Maroon_cavern")].models.always.l6 = "";			
			Locations[FindLocation("Maroon_cavern")].models.always.l7 = "bottleC_cork";
			Locations[FindLocation("Charleston_shore")].models.always.locators = "pass1_l_GB9";
			Locations[FindLocation("Charleston_shore")].models.always.l5 = "rope_gibbet";	
			Locations[FindLocation("Charleston_shore")].models.always.l6 = "plank2A";
			Locations[FindLocation("Charleston_shore")].models.always.l9 = "ladder_rope";
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box29 = 0.0001;
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box40 = 1.5;

			LAi_QuestDelay("maroon_hideout_boxback", 0.1);
			LAi_QuestDelay("maroon_cavern_steplock", 0.1);
			LAi_QuestDelay("bridge_broken_A", 0.1);
			LAi_QuestDelay("bridge_broken_B", 0.1);
			LAi_QuestDelay("ch_shore_bars", 0.1);


	
			Pchar.quest.Teach_head = "12";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 13
		case "13":
			//POE'S + JUP BOAT, HUT
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");		
				
			SetCurrentTime(12.00, 0);
			SetNextWeather("Clear");		
			
			ChangeCharacterAddressGroup(characterFromID("Jupiter"), "Bessop_plantation", "officers", "reload1_1");
			AddPassenger(Pchar, characterFromID("Jupiter"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Jupiter"));

			TakeItemFromCharacter(characterFromID("Jupiter"), "pistolmtoon");
			TakeNItems(characterFromID("Jupiter"),"gunpowder", 6);
			RemoveCharacterEquip(characterFromID("Jupiter"), GUN_ITEM_TYPE);	

			Pchar.quest.Jupiter_tobacco = "2";
			Pchar.quest.Jupiter_jewelry12 = "yes";
			Pchar.quest.Jupiter_coin7 = "yes";
			Pchar.quest.Jupiter_gunpowder = "6";
			Pchar.Lut_G_cipher = "done";
			Pchar.quest.town_exit_closed = "no";

			Pchar.quest.Fort_M_flag_pos = "up";
			Locations[FindLocation("Fort_Moultrie")].models.always.locators = "fort2_locators_GB3";			
			Locations[FindLocation("Maroon_cavern")].environment.weather = "true";
	locations[n].lockWeather = "Inside";
			Locations[FindLocation("Maroon_cavern")].environment.sea = "false";
			Locations[FindLocation("Maroon_cavern")].models.always.locators = "CavernMedium_locators_GB_dry";
			Locations[FindLocation("Maroon_cavern")].models.always.l4 = "";		
			Locations[FindLocation("Maroon_cavern")].models.always.l5 = "barrelC";		
			Locations[FindLocation("Maroon_cavern")].models.always.l6 = "";			
			Locations[FindLocation("Maroon_cavern")].models.always.l7 = "bottleC_cork";
			Locations[FindLocation("Charleston_shore")].models.always.locators = "pass1_l_GB9";
			Locations[FindLocation("Charleston_shore")].models.always.l5 = "rope_gibbet";	
			Locations[FindLocation("Charleston_shore")].models.always.l6 = "plank2A";
			Locations[FindLocation("Charleston_shore")].models.always.l9 = "ladder_rope";
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box29 = 0.0001;
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box40 = 1.5;
			Locations[FindLocation("Bishops_Hostel")].models.always.locators = "locator_BH2";	//tree + boat + raft
			
			LAi_QuestDelay("maroon_cavern_steplock", 0.1);
			LAi_QuestDelay("maroon_hideout_steplock", 0.1);
			LAi_QuestDelay("bridge_broken_A", 0.1);
			LAi_QuestDelay("bridge_broken_B", 0.1);
			LAi_QuestDelay("ch_shore_bars", 0.1);
			LAi_QuestDelay("step_back_store", 0.1);
			
			LAi_QuestDelay("fort_shore_pier_boat", 0.1);
			LAi_QuestDelay("fort_shore_pier", 0.1);
			LAi_QuestDelay("Charleston_steam_frigate", 0.1);
			LAi_QuestDelay("church_sounds_first", 0.1);
			LAi_QuestDelay("Charleston_priest", 0.1);

			Pchar.quest.Teach_head = "13";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 14
		case "14":
			//FORT REVOLVER
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			
			//logit("dialog 14");
					
			SetCurrentTime(12.00, 0);
			SetNextWeather("Clear");

			

			Pchar.quest.Teach_head = "14";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 15		
		case "15":
			//POE CHURCH
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
				
			SetCurrentTime(12.00, 0);
			SetNextWeather("Clear");

			SetModel(characterFromID("landlady"), "landlady_private", "woman", "woman", 1.8, true);
			GiveItem2Character(characterFromID("landlady"), "bladeX4");
			EquipCharacterbyItem(characterFromID("landlady"), "bladeX4");
			GiveItem2Character(characterFromID("landlady"), "pistolwhip");
			EquipCharacterbyItem(characterFromID("landlady"), "pistolwhip");
			LAi_SetStayType(characterFromID("landlady"));
			Pchar.quest.Poe_home = "private";
			Pchar.quest.Ch_town_box6 = "locked";		//brothel
			Pchar.Lut_G_cipher = "done";

			locations[FindLocation("Poe_bedroom")].models.always.locators = "largehouse02_locators_GB_open";
			Locations[FindLocation("GB_Chinatown")].locators_radius.reload.reload9 = 1.5;
			Locations[FindLocation("GB_Chinatown")].locators_radius.box.box4 = 0.001;
			Locations[FindLocation("GB_Chinatown")].reload.l9.disable = 1;
			Locations[FindLocation("GB_Charleston_town")].reload.l13.disable = 1;//lock to tailor, easiest
			Locations[FindLocation("GB_Charleston_town")].reload.l2.disable = 0;
			Locations[FindLocation("GB_Charleston_town")].reload.l5.disable = 0;
			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;
			
			LAi_QuestDelay("Charleston_steam_frigate", 0.1);
			LAi_QuestDelay("church_sounds_first", 0.1);
			


			Pchar.quest.Teach_head = "15";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
//kidd 16		
		case "16":
			//BISHOP'S HOSTEL, LAST TIME
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			PlaySound("AMBIENT\CRYPT\daemon3.wav");	
			
			SetCurrentTime(12.00, 0);
			SetNextWeather("Clear");
			Pchar.quest.JRH_rain = "Clear";

			ChangeCharacterAddressGroup(characterFromID("maroon1"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon2"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("maroon3"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("indian_bandit"), "none", "", "");		

			Locations[FindLocation("Charleston_shore")].models.always.locators = "pass1_l_GB9";
			Locations[FindLocation("Charleston_shore")].models.always.l5 = "rope_gibbet";	
			Locations[FindLocation("Charleston_shore")].models.always.l6 = "plank2A";
			Locations[FindLocation("Charleston_shore")].models.always.l9 = "ladder_lever";
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box29 = 0.0001;
			Locations[FindLocation("Charleston_shore")].locators_radius.box.box40 = 1.5;

			Locations[FindLocation("Bessop_plantation")].locators_radius.box.box3 = 1.0;
			Locations[FindLocation("Bessop_plantation")].locators_radius.goto.gate = 16.0;
			
			Pchar.Lut_G_cipher = "done";
			Pchar.quest.mar_cav_from_plant = "open";
			Characters[GetCharacterIndex("Charleston_guard1")].Ship.Type = "obj_raft3";	//in hideout

			LAi_QuestDelay("maroon_cavern_steplock", 0.1);
			LAi_QuestDelay("maroon_hideout_steplock", 0.1);

			Pchar.quest.Teach_head = "16";

			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "start_teleport";
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;

               case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		
               break;
	}
}
