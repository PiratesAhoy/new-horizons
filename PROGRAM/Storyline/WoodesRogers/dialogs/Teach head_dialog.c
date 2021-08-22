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

			if(GetAttribute(pchar, "TH_first_time") == "done")
			{
				PlaySound("VOICE\ENGLISH\gr_Teach7.wav");
				dialog.text = DLG_TEXT[52];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[53];
				link.l2.go = "where_to_part";
			}
			else
			{
				PlaySound("VOICE\ENGLISH\gr_Teach5.wav");
				dialog.text = DLG_TEXT[50];
				link.l1 = DLG_TEXT[51];
				link.l1.go = "no_bonus_chapter";
				Pchar.TH_first_time = "done";
			}
		break;

		case "no_bonus_chapter":
			PlaySound("VOICE\ENGLISH\gr_Teach7.wav");
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[53];
			link.l2.go = "where_to_part";
		break;

		case "where_to_part":
			dialog.snd = "Voice\CLLA\CLLA001";
			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "where_to_part1";
			link.l2 = DLG_TEXT[31];
			link.l2.go = "where_to_part2";
		break;

		case "where_to_part1":
			PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l0 = DLG_TEXT[3];
			link.l0.go = "exit";
		
			link.l1 = DLG_TEXT[4];	//Port Royal: mission given
			link.l1.go = "1";
			link.l2 = DLG_TEXT[5];	//brothel
			link.l2.go = "2";
			link.l3 = DLG_TEXT[6];	//Port Royal after QC
			link.l3.go = "3";
			link.l4 = DLG_TEXT[7];	//Port Royal: armory
			link.l4.go = "4";
			link.l5 = DLG_TEXT[8];	//Port Royal: kitchen
			link.l5.go = "5";
			link.l6 = DLG_TEXT[9];	//Port Royal: terrace to library
			link.l6.go = "6";
			link.l7 = DLG_TEXT[10];	//Port Royal: shop
			link.l7.go = "7";
			link.l8 = DLG_TEXT[11];	//Port Royal: tavern storeroom
			link.l8.go = "8";
			link.l9 = DLG_TEXT[12];	//Port Royal: outside shipyard, ready for medicine collect part
			link.l9.go = "9";
			link.l10 = DLG_TEXT[13];//cave shore: medicines collected  	
			link.l10.go = "10";
			link.l11 = DLG_TEXT[14];//Port Royal: shipyard to farm
			link.l11.go = "11";
			link.l12 = DLG_TEXT[15];//ships: long run to Vane's
			link.l12.go = "12";
			link.l14 = DLG_TEXT[16];//choir: long run to Vane's
			link.l14.go = "14";
			link.l15 = DLG_TEXT[17];//pirate church: before coins
			link.l15.go = "15";
			link.l16 = DLG_TEXT[18];//cave shore: before wood tower
			link.l16.go = "16";
			link.l17 = DLG_TEXT[19];//cavern: revenge
			link.l17.go = "17";
			link.l18 = DLG_TEXT[20];//corvette yellow deck: revenge
			link.l18.go = "18";
			link.l20 = DLG_TEXT[21];//study to secret
			link.l20.go = "20";							
		break;
	
		case "where_to_part2":

		    //common for all part2 -->
			AddMoneyToCharacter(Pchar,-10000);	//first take all then add start money in q_r	

			Pchar.mapBB1 = "info";

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

			LAi_LocationFightDisable(&Locations[FindLocation("Redmond_Town_01")], true);		//so officers don't get lost
			LAi_LocationFightDisable(&Locations[FindLocation("Redmond_Town_04")], true);
			Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH7";	//was 6
			Locations[FindLocation("Redmond_Town_01")].reload.l18.disable = 1;		//window
			Locations[FindLocation("Redmond_Town_01")].reload.l23.disable = 1;		//gate terrace
			Locations[FindLocation("Redmond_Town_01")].reload.l26.disable = 1;		//tavern storeroom
			Locations[FindLocation("Redmond_Town_01")].reload.l27.disable = 1;		//Rogers shop
			Locations[FindLocation("Redmond_Town_01")].reload.l20.disable = 1;		//LS back door
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
			Locations[FindLocation("Redmond_Port")].models.always.locators = "RedPort_l";	//reset to normal
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

			LAi_QuestDelay("Vane_Richards_from game", 0.1);			//NO SHIPS, NO PIR CAPS at cave_shore, Vane's hideout

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
		    //<-- common for all part2


			PlaySound("VOICE\ENGLISH\gr_Teach2.wav");
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			
			link.l21 = DLG_TEXT[28];//Port Royal: start part 2
			link.l21.go = "21";
			link.l22 = DLG_TEXT[29];//farm: after alchemy 1
			link.l22.go = "22";

			link.l23 = DLG_TEXT[34];//cave shore: after Vane
			link.l23.go = "23";
			link.l24 = DLG_TEXT[35];//Curacao: after Hands
			link.l24.go = "24";
			link.l25 = DLG_TEXT[36];//La Grenade: after Odel
			link.l25.go = "25";

			link.l26 = DLG_TEXT[37];//Tortuga: after surgeons
			link.l26.go = "26";
			link.l27 = DLG_TEXT[38];//Charlestown: after Maltains
			link.l27.go = "27";
			link.l28 = DLG_TEXT[39];//Cayman Estate: after maze + rooms
			link.l28.go = "28";
			link.l29 = DLG_TEXT[40];//Eleuthera: after Maynard Citadel
			link.l29.go = "29";

			link.l30 = DLG_TEXT[41];//Cartagena: after monastary
			link.l30.go = "30";
			link.l31 = DLG_TEXT[42];//Antigua: after prison
			link.l31.go = "31";
			link.l32 = DLG_TEXT[43];//Cayman: after estate wine cellar
			link.l32.go = "32";
			link.l33 = DLG_TEXT[44];//Turks: after Caesar's map
			link.l33.go = "33";

			link.l34 = DLG_TEXT[45];//Cartagena: after all 4 missions
			link.l34.go = "34";
			link.l35 = DLG_TEXT[46];//Kristiania: after all 6 items found
			link.l35.go = "35";

			link.l36 = DLG_TEXT[47];//Careen shore: after Blackbeard's tower
			link.l36.go = "36";
			link.l37 = DLG_TEXT[48];//Corvette: after Careen shore
			link.l37.go = "37";
			link.l38 = DLG_TEXT[49];//Isla Mona: after Corvette
			link.l38.go = "38";											
		break;
	
		case "how_to_return":
			PlaySound("VOICE\ENGLISH\gr_Teach1.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];	
			link.l1.go = "start_teleport";
		break;

		case "start_teleport":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Teach_head_teleport");
		break;

		case "1":
			//PORT ROYAL: QUEST START	after marooned
			
			Pchar.quest.Redmond_pause_sounds = "yes";
	
			ChangeCharacterAddressGroup(characterFromID("Woodes Rogers"), "Redmond_Town_01", "goto", "goto56");
			Locations[FindLocation("Redmond_town_01")].locators_radius.goto.goto17 = 2.0;
		
			pchar.quest.WR_on_balcony.win_condition.l1 = "locator";
			pchar.quest.WR_on_balcony.win_condition.l1.location = "Redmond_town_01";
			pchar.quest.WR_on_balcony.win_condition.l1.locator_group = "goto";
			pchar.quest.WR_on_balcony.win_condition.l1.locator = "goto17";
			pchar.quest.WR_on_balcony.win_condition = "WR_on_balcony";

			Pchar.quest.Teach_head = "1";

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "how_to_return";
		break;
		
		case "2":
			//QC: BROTHEL
					
			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "QC_Port");

			Pchar.quest.wr_quest1 = "on";
			Pchar.quest.wr_quest2 = "start";
			Pchar.quest.wr_questinfo = "no";
			ChangeCharacterAddressGroup(characterFromID("Mistress"), "none", "", "");
			ChangeCharacterAddressGroup(characterFromID("Wench3"), "QC_Brothel", "goto", "goto3");

			ChangeCharacterAddressGroup(characterFromID("Woodes Rogers"), "Redmond_Town_01", "goto", "goto56");
		
			Pchar.quest.Teach_head = "2";

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "how_to_return";
		break;

		case "3":
			//PORT ROYAL: AFTER QC		before mission 1
		
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");
			Pchar.quest.JRH_rain = "Clear";
		
			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Redmond_Port");	

			ChangeCharacterAddressGroup(characterFromID("Woodes Rogers"), "Redmond_Town_01", "goto", "goto56");
			Pchar.quest.wr_quest1 = "off";
			Pchar.quest.wr_quest2 = "QC_finished";

			AddPassenger(Pchar, characterFromID("Wench3"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Wench3"));
			LAi_SetOfficerType(characterFromID("Wench3"));

			Locations[FindLocation("Redmond_Town_01")].locators_radius.goto.goto17 = 4.0;
		
			locations[FindLocation("Redmond_Town_01")].type = "blues_town";
			locations[FindLocation("Redmond_Town_03")].type = "blues_town";
			locations[FindLocation("Redmond_Town_04")].type = "blues_town";
			locations[FindLocation("Redmond_Port")].type = "blues_port";
			locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";
		
			LAi_QuestDelay("QC_sound_check_done", 0.1);

			Pchar.quest.Teach_head = "3";

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "how_to_return";
		break;

		case "4":
			//ARMORY			before mission 3
			
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");
		
			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Redmond_Port");
		
			Pchar.quest.Rdm_officiant = "Claire";
			Pchar.quest.wr_quest1 = "pistol2";
			Pchar.quest.wr_quest2 = "QC_finished";

			ChangeCharacterAddressGroup(CharacterFromID("wr_bucc1"), "Redmond_tavern", "goto", "guard1");
			ChangeCharacterAddressGroup(CharacterFromID("wr_boc16"), "Redmond_tavern", "goto", "guard2");

			ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "none", "", "");
			Locations[FindLocation("wr_residence")].reload.l7.disable = 0;//open to armory
			Locations[FindLocation("wr_residence")].reload.l2.disable = 1;//closed to lib
			Locations[FindLocation("wr_library")].reload.l2.disable = 1;//closed to residence
			ChangeCharacterAddressGroup(CharacterFromID("wr_voy"), "none", "", "");//doc
			Locations[FindLocation("wr_library")].locators_radius.reload.reload2 = 1.0;
			locations[FindLocation("wr_armory")].id.label = "Woodes Rogers' armory";

			Locations[FindLocation("Redmond_tavern")].models.always.locators = "LT_l_JRH2";
			Locations[FindLocation("JRH_tavern_upstairs")].models.always.locators = "LH_F2_l_JRH_open";

			Locations[FindLocation("wr_kitchen")].reload.l1.disable = 0;
			Locations[FindLocation("wr_kitchen")].models.always.locators = "FlamHouse_locators_JRH1";//lever down, means open
			locations[FindLocation("wr_kitchen")].id.label = "Woodes Rogers' kitchen";

			Locations[FindLocation("Redmond_Town_01")].reload.l16.go = "WR_kitchen";
			Locations[FindLocation("Redmond_Town_01")].reload.l16.emerge = "reload1";
			Locations[FindLocation("Redmond_Town_01")].reload.l16.label = "Woodes Rogers' kitchen.";
			Locations[FindLocation("Redmond_Town_01")].reload.l16.disable = 0;
			Locations[FindLocation("JRH_tavern_upstairs")].reload.l2.disable = 1;//to wr bed

			Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH2";//window F3 visible
			Locations[FindLocation("Redmond_Town_01")].reload.l18.disable = 0;//window F3 open
			Locations[FindLocation("wr_residence")].reload.l3.disable = 0;//window now open
			Locations[FindLocation("wr_library")].reload.l1.disable = 1;//library to storeroom closed
			Locations[FindLocation("Tavern_storeroom")].reload.l3.disable = 1;//storeroom to library closed
			locations[FindLocation("wr_library")].type = "Rogers_repair_residence";
			locations[FindLocation("Tavern_storeroom")].type = "repair_house";
			Locations[FindLocation("Tavern_storeroom")].models.always.locators = "store04_locators_JRH3";//with planks

			locations[FindLocation("Redmond_Town_01")].type = "blues_town";
			locations[FindLocation("Redmond_Town_03")].type = "blues_town";
			locations[FindLocation("Redmond_Town_04")].type = "blues_town";
			locations[FindLocation("Redmond_Port")].type = "blues_port";
			locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

			Pchar.quest.Teach_head = "4";

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "how_to_return";
		break;
	
		case "5":
			//PORT ROYAL: KITCHEN		before mission 4
		
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");

			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Redmond_Port");	
		
			Pchar.quest.Rdm_officiant = "Claire";
			Pchar.quest.wr_quest1 = "pistol3";
			Pchar.quest.wr_quest2 = "QC_finished";
		
			Pchar.quest.wr_shop = "box8_tour_open";
			Pchar.quest.wr_shoppistol = "yes";
			Pchar.quest.wr_elevator = "up";//start position

			ChangeCharacterAddressGroup(CharacterFromID("wr_bucc1"), "Redmond_tavern", "goto", "guard1");
			ChangeCharacterAddressGroup(CharacterFromID("wr_boc16"), "Redmond_tavern", "goto", "guard2");

			ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "none", "", "");
			Locations[FindLocation("wr_residence")].reload.l7.disable = 0;//open to armory
			Locations[FindLocation("wr_residence")].reload.l2.disable = 1;//closed to lib
			Locations[FindLocation("wr_library")].reload.l2.disable = 1;//closed to residence
			ChangeCharacterAddressGroup(CharacterFromID("wr_voy"), "none", "", "");//doc
			Locations[FindLocation("wr_library")].locators_radius.reload.reload2 = 1.0;
			locations[FindLocation("wr_armory")].id.label = "Woodes Rogers' armory";
			Locations[FindLocation("wr_armory")].reload.l1.disable = 0;//gps

			Locations[FindLocation("Redmond_tavern")].models.always.locators = "LT_l_JRH2";
			Locations[FindLocation("JRH_tavern_upstairs")].models.always.locators = "LH_F2_l_JRH_open";

			Locations[FindLocation("wr_kitchen")].reload.l1.disable = 0;
			Locations[FindLocation("wr_kitchen")].models.always.locators = "FlamHouse_locators_JRH1";//lever down, means open
			locations[FindLocation("wr_kitchen")].id.label = "Woodes Rogers' kitchen";
			Locations[FindLocation("Redmond_Town_01")].reload.l16.go = "WR_kitchen";
			Locations[FindLocation("Redmond_Town_01")].reload.l16.emerge = "reload1";
			Locations[FindLocation("Redmond_Town_01")].reload.l16.label = "Woodes Rogers' kitchen.";
			Locations[FindLocation("Redmond_Town_01")].reload.l16.disable = 0;//to kitchen
			Locations[FindLocation("Redmond_Town_01")].reload.l18.disable = 1;//window to residence
			Locations[FindLocation("Redmond_Town_01")].reload.l23.disable = 1;//gate to terrace
			Locations[FindLocation("Redmond_tavern")].reload.l2.disable = 0;//to tavern_upstairs
			Locations[FindLocation("JRH_tavern_upstairs")].reload.l2.disable = 1;//to wr bed
			Locations[FindLocation("Redmond_town_01")].reload.l11.disable = 1;//to tavern
			Locations[FindLocation("Redmond_town_01")].reload.l31.disable = 1;//to tavern from balcony
			locations[FindLocation("Redmond_tavern")].id.label = "CLOSED BECAUSE OF ILLNESS - Charles Windem innkeeper";
			Locations[FindLocation("Redmond_tavern")].reload.l1.disable = 1;//to town
			Locations[FindLocation("Redmond_tavern")].reload.l3.disable = 1;//to balcony
			Locations[FindLocation("JRH_tavern_upstairs")].reload.l2.disable = 0;//to wr bed
			Locations[FindLocation("Redmond_town_01")].models.always.locators = "Red01_l_JRH3";//with locator outside the gate
	
			Locations[FindLocation("wr_residence")].reload.l3.disable = 1;//window now closed
			Locations[FindLocation("wr_residence")].reload.l1.disable = 0;//terrace
			Locations[FindLocation("wr_library")].reload.l1.disable = 1;//library to storeroom closed
			Locations[FindLocation("Tavern_storeroom")].reload.l3.disable = 1;//storeroom to library closed
			locations[FindLocation("wr_library")].type = "Rogers_repair_residence";
			locations[FindLocation("Tavern_storeroom")].type = "repair_house";
			Locations[FindLocation("Tavern_storeroom")].models.always.locators = "store04_locators_JRH3";//with planks
			Locations[FindLocation("wr_armory")].models.always.locators = "LS_l_JRH5";//no smoke
			Locations[FindLocation("wr_shop")].models.always.locators = "residence05_locators_JRH_Lup";
			locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
			locations[FindLocation("Charles_Windem_room")].id.label = "Charles Windem's room";

			Locations[FindLocation("Redmond_UsurerHouse")].reload.l2.disable = 0;//to shop
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l6.disable = 0;//to cellar
			locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";

			ChangeCharacterAddressGroup(CharacterFromID("Wench3"), "ck_bedroom", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Woodes Rogers"), "wr_bedroom", "goto", "goto5");
			LAi_SetStayType(CharacterFromID("Woodes Rogers"));
			ChangeCharacterAddressGroup(CharacterFromID("Selkirk"), "wr_booty", "sit", "sit1");
			LAi_SetSitType(characterFromID("Selkirk"));
			ChangeCharacterAddressGroup(CharacterFromID("Dave Edna"), "wr_shop", "sit", "sit1");
			ChangeCharacterAddressGroup(CharacterFromID("wr_oman1X"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("powdermonkey"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Charles Windem"), "Charles_Windem_room", "sit", "sit2");
			LAi_SetActorType(CharacterFromID("Charles Windem"));
			LAi_ActorSetLayMode(CharacterFromID("Charles Windem"));
			locations[FindLocation("ck_bedroom")].id.label = "Caroline K's bedroom";

			locations[FindLocation("Redmond_Town_01")].type = "blues_town";
			locations[FindLocation("Redmond_Town_03")].type = "blues_town";
			locations[FindLocation("Redmond_Town_04")].type = "blues_town";
			locations[FindLocation("Redmond_Port")].type = "blues_port";
			locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";
			
			LAi_QuestDelay("fill_shop_boxes", 0.1);
			LAi_QuestDelay("selkirk_dialog", 0.1);
			LAi_QuestDelay("dave_arrives", 1.5);

			//RESTARTS WAY IN
			Pchar.quest.wr_terrace = "second_time";

			pchar.quest.terrace_in1.win_condition.l1 = "locator";
			pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
			pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
			pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
			pchar.quest.terrace_in1.win_condition = "terrace_in1";

			Pchar.quest.Teach_head = "5";

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "how_to_return";
		break;

		case "6":
			//PORT ROYAL: TERRACE		before mission 5
		
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");

			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Redmond_Port");

			Pchar.quest.wr_quest2 = "shut_up_Caroline";
		
			Pchar.quest.Rdm_officiant = "Claire";
			Pchar.quest.wr_quest1 = "pistol4";
			Pchar.quest.wr_quest2 = "shut_up_Caroline";
			Pchar.quest.wr_libstep = "libstep_open";
			Pchar.quest.wr_shop = "box8_tour_open";
			Pchar.quest.wr_shoppistol = "yes";
			Pchar.quest.wr_elevator = "up";//start position
			Pchar.quest.wr_kitchendoor = "stuck";

			//import from [5]
			Locations[FindLocation("wr_library")].locators_radius.reload.reload2 = 1.0;
			locations[FindLocation("wr_armory")].id.label = "Woodes Rogers' armory";
			Locations[FindLocation("wr_armory")].reload.l1.disable = 0;//gps

			locations[FindLocation("Redmond_tavern")].type = "house";
			Locations[FindLocation("Redmond_tavern")].models.always.locators = "LT_l_JRH3";//without characters
			Locations[FindLocation("JRH_tavern_upstairs")].models.always.locators = "LH_F2_l_JRH_open";

			locations[FindLocation("wr_kitchen")].id.label = "Woodes Rogers' kitchen";
		
			Locations[FindLocation("Redmond_Town_01")].reload.l18.disable = 1;//window to residence
			Locations[FindLocation("Redmond_Town_01")].reload.l23.disable = 0;//gate to terrace
			Locations[FindLocation("Redmond_tavern")].reload.l2.disable = 0;//to tavern_upstairs
			Locations[FindLocation("JRH_tavern_upstairs")].reload.l2.disable = 1;//to wr bed
			Locations[FindLocation("Redmond_town_01")].reload.l11.disable = 1;//to tavern
			Locations[FindLocation("Redmond_town_01")].reload.l31.disable = 1;//to tavern from balcony
			locations[FindLocation("Redmond_tavern")].id.label = "CLOSED BECAUSE OF ILLNESS - Charles Windem innkeeper";
			Locations[FindLocation("Redmond_tavern")].reload.l1.disable = 1;//to town
			Locations[FindLocation("Redmond_tavern")].reload.l3.disable = 1;//to balcony
			Locations[FindLocation("JRH_tavern_upstairs")].reload.l2.disable = 0;//to wr bed
			Locations[FindLocation("Redmond_town_01")].models.always.locators = "Red01_l_JRH3";//with locator outside the gate
	
			Locations[FindLocation("wr_residence")].reload.l3.disable = 1;//window now closed
			Locations[FindLocation("wr_residence")].reload.l1.disable = 0;//terrace
			Locations[FindLocation("wr_library")].reload.l1.disable = 1;//library to storeroom closed
			locations[FindLocation("wr_library")].id.label = "Woodes Rogers' library";
			Locations[FindLocation("Tavern_storeroom")].reload.l3.disable = 1;//storeroom to library closed
			locations[FindLocation("wr_library")].type = "Rogers_repair_residence";

			locations[FindLocation("Tavern_storeroom")].type = "repair_house";
			Locations[FindLocation("Tavern_storeroom")].models.always.locators = "store04_locators_JRH3";//with planks
			Locations[FindLocation("wr_armory")].models.always.locators = "LS_l_JRH5";//no smoke
			Locations[FindLocation("wr_shop")].models.always.locators = "residence05_locators_JRH_Lup";
			locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
		
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l6.disable = 0;//to cellar
			locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";

			ChangeCharacterAddressGroup(CharacterFromID("wr_bucc1"), "Redmond_tavern", "goto", "guard1");
			ChangeCharacterAddressGroup(CharacterFromID("wr_boc16"), "Redmond_tavern", "goto", "guard2");

			ChangeCharacterAddressGroup(CharacterFromID("Wench3"), "ck_bedroom", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Woodes Rogers"), "wr_bedroom", "goto", "goto5");
			LAi_SetStayType(CharacterFromID("Woodes Rogers"));
			ChangeCharacterAddressGroup(CharacterFromID("Dave Edna"), "wr_shop", "sit", "sit1");
			ChangeCharacterAddressGroup(CharacterFromID("wr_oman1X"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("powdermonkey"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Charles Windem"), "Charles_Windem_room", "sit", "sit2");
			LAi_SetActorType(CharacterFromID("Charles Windem"));
			LAi_ActorSetLayMode(CharacterFromID("Charles Windem"));
			ChangeCharacterAddressGroup(CharacterFromID("wr_boc1"), "none", "", "");//bald with whiskers in library

			Locations[FindLocation("wr_library")].models.always.locators = "Res02_l_JRH2";//right one here
	
			//changes during phase 4:
			
			Locations[FindLocation("wr_kitchen")].models.always.locators = "FlamHouse_locators_JRH2";
			Locations[FindLocation("wr_kitchen")].reload.l1.disable = 1;//to town
			Locations[FindLocation("Redmond_Town_01")].reload.l16.disable = 1;//to kitchen

			Locations[FindLocation("Redmond_UsurerHouse")].reload.l2.disable = 1;//to shop
			Locations[FindLocation("wr_shop")].reload.l6.disable = 1;//to loanshark
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l1.disable = 1;//to town
			Locations[FindLocation("Redmond_Town_01")].reload.l10.disable = 1;//to LS
			bDisableFastReload = 1;			
			locations[FindLocation("Redmond_UsurerHouse")].id.label = "TEMPORARY OUT OF GOLD. OPEN SOON AGAIN. Robyn Corrick - bank manager";
			ChangeCharacterAddressGroup(CharacterFromID("Redmond Usurer"), "none", "", "");

			Locations[FindLocation("wr_shop")].reload.l3.disable = 0;//to shop entrй
			Locations[FindLocation("Redmond_Town_01")].reload.l27.disable = 0;//to shop

			Locations[FindLocation("wr_residence")].reload.l7.disable = 1;//locked to arm

			Locations[FindLocation("wr_residence")].reload.l2.disable = 0;//open to lib
			Locations[FindLocation("wr_library")].reload.l2.disable = 0;//open to residence
		
			locations[FindLocation("storeroom_attic")].id.label = "Storeroom attic";
			locations[FindLocation("Charles_Windem_room")].id.label = "Charles Windem's room";

			Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
			Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
			Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
			Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
			Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

			ChangeCharacterAddressGroup(CharacterFromID("wr_boc4"), "none", "", "");//library guards disturbing textlog
			ChangeCharacterAddressGroup(CharacterFromID("wr_cor1_1"), "none", "", "");

			ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "wr_residence", "sit", "sit2");
			ChangeCharacterAddressGroup(CharacterFromID("wr_voy"), "wr_library", "goto", "goto18");
			
			SetModel(characterFromID("Powdermonkey"), "monkey", "monkey", "monkey", 1.8, false);
			ChangeCharacterAddressGroup(CharacterFromID("PowderMonkey"), "Redmond_Town_01", "goto", "goto60");
			locations[FindLocation("ck_bedroom")].id.label = "Caroline K's bedroom";

			//reusing 6 walkers from shop to crew quarters
			ChangeCharacterAddressGroup(CharacterFromID("wr_fsh"), "wr_crew", "sit", "sit2");
			LAi_SetSitType(CharacterFromID("wr_fsh"));
			RemoveCharacterEquip(characterFromID("wr_fsh"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_fsh"), "bladearmchair");
			EquipCharacterbyItem(characterFromID("wr_fsh"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_fsh"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_fatj"), "wr_crew", "sit", "sit3");
			LAi_SetSitType(CharacterFromID("wr_fatj"));
			RemoveCharacterEquip(characterFromID("wr_fatj"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_fatj"), "bladebasket");
			EquipCharacterbyItem(characterFromID("wr_fatj"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_fatj"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_cor3"), "wr_crew", "sit", "sit4");
			LAi_SetSitType(CharacterFromID("wr_cor3"));
			RemoveCharacterEquip(characterFromID("wr_cor3"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_cor3"), "pistol_armchair");
			EquipCharacterbyItem(characterFromID("wr_cor3"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_cor3"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_fralut"), "wr_crew", "goto", "stay1");
			LAi_SetCitizenType(CharacterFromID("wr_fralut"));
			RemoveCharacterEquip(characterFromID("wr_fralut"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_fralut"), "bladebasket");
			EquipCharacterbyItem(characterFromID("wr_fralut"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_fralut"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_mong"), "wr_crew", "sit", "sit5");
			LAi_SetSitType(CharacterFromID("wr_mong"));
			RemoveCharacterEquip(characterFromID("wr_mong"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_mong"), "bladebarrel");
			RemoveCharacterEquip(characterFromID("wr_mong"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_mong"), "pistolbarrel");
			EquipCharacterbyItem(characterFromID("wr_mong"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_mong"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_pir4"), "wr_crew", "sit", "sit6");
			LAi_SetSitType(CharacterFromID("wr_pir4"));
			RemoveCharacterEquip(characterFromID("wr_pir4"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_pir4"), "bladeglobe");
			EquipCharacterbyItem(characterFromID("wr_pir4"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_pir4"), "pistol1");

			Pchar.quest.wr_defoe = "start";
			Pchar.quest.rum_water = "empty";	//start = empty
			Pchar.quest.rum_molasses = "empty";	//start = empty
			Pchar.quest.rum_wheel = "off";		//start = off
			Pchar.quest.rum_damper = "closed";	//start = closed
			Pchar.quest.rum_fire = "unlit";		//start = unlit
			Pchar.quest.rum_fuel = "no";		//start = no
			Pchar.quest.rum_phase = "0";		//start = 0
			Pchar.quest.rum_sack = "no";		//start = no

			Pchar.quest.water_check = 0;		//start = 0
			Pchar.quest.molasses_check = 0;		//start = 0
			Pchar.quest.wheel_check = 0;		//start = 0
			Pchar.quest.damper_check = 0;		//start = 0
			Pchar.quest.4checks = 0;		//start = 0

			locations[FindLocation("Redmond_Town_01")].type = "blues_town";
			locations[FindLocation("Redmond_Town_03")].type = "blues_town";
			locations[FindLocation("Redmond_Town_04")].type = "blues_town";
			locations[FindLocation("Redmond_Port")].type = "blues_port";
			locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

			LAi_QuestDelay("steplock_mother", 0.1);//starts the steplock loop in wr_mother room
			LAi_QuestDelay("subject_sound_architecture", 0.1);
			LAi_QuestDelay("bladetalk_finished", 0.1);

			//RESTARTS WAY IN
			Pchar.quest.wr_terrace = "second_time";

			pchar.quest.terrace_in1.win_condition.l1 = "locator";
			pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
			pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
			pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
			pchar.quest.terrace_in1.win_condition = "terrace_in1";

			Pchar.quest.Teach_head = "6";

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "how_to_return";
		break;

		case "7":
			//PORT ROYAL: SHOP	after distillery before bridge

			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Redmond_Port");

			SetCurrentTime(21, 0);
			SetNextWeather("Red Sky");
			Pchar.quest.JRH_rain = "Cloudy";

			SetCharacterShipLocation(Pchar, "Redmond_port");
		
			Pchar.quest.Rdm_officiant = "Claire";
			Pchar.quest.wr_quest1 = "pistol4";
			Pchar.quest.wr_quest2 = "shut_up_Caroline";
			Pchar.quest.wr_libstep = "libstep_open";
			Pchar.quest.wr_shop = "box8_tour_open";
			Pchar.quest.wr_shoppistol = "yes";
			Pchar.quest.wr_elevator = "up";//start position
			Pchar.quest.wr_kitchendoor = "stuck";

			//import from [6]
			Locations[FindLocation("wr_library")].locators_radius.reload.reload2 = 1.0;
			locations[FindLocation("wr_armory")].id.label = "Woodes Rogers' armory";
			Locations[FindLocation("wr_armory")].reload.l1.disable = 0;//gps

			locations[FindLocation("Redmond_tavern")].type = "house";
			Locations[FindLocation("Redmond_tavern")].models.always.locators = "LT_l_JRH3";//without characters
			Locations[FindLocation("JRH_tavern_upstairs")].models.always.locators = "LH_F2_l_JRH_open";

			locations[FindLocation("wr_kitchen")].id.label = "Woodes Rogers' kitchen";
		
			Locations[FindLocation("Redmond_Town_01")].reload.l18.disable = 1;//window to residence
			Locations[FindLocation("Redmond_Town_01")].reload.l23.disable = 0;//gate to terrace
			Locations[FindLocation("Redmond_tavern")].reload.l2.disable = 0;//to tavern_upstairs
			Locations[FindLocation("JRH_tavern_upstairs")].reload.l2.disable = 1;//to wr bed
			Locations[FindLocation("Redmond_town_01")].reload.l11.disable = 1;//to tavern
			Locations[FindLocation("Redmond_town_01")].reload.l31.disable = 1;//to tavern from balcony
			locations[FindLocation("Redmond_tavern")].id.label = "CLOSED BECAUSE OF ILLNESS - Charles Windem innkeeper";
			Locations[FindLocation("Redmond_tavern")].reload.l1.disable = 1;//to town
			Locations[FindLocation("Redmond_tavern")].reload.l3.disable = 1;//to balcony
			Locations[FindLocation("JRH_tavern_upstairs")].reload.l2.disable = 0;//to wr bed
			Locations[FindLocation("Redmond_town_01")].models.always.locators = "Red01_l_JRH3";//with locator outside the gate, needed here?
	
			Locations[FindLocation("wr_residence")].reload.l3.disable = 1;//window now closed
			Locations[FindLocation("wr_residence")].reload.l1.disable = 0;//terrace
			Locations[FindLocation("wr_library")].reload.l1.disable = 1;//library to storeroom closed
			locations[FindLocation("wr_library")].id.label = "Woodes Rogers' library";
			Locations[FindLocation("Tavern_storeroom")].reload.l3.disable = 1;//storeroom to library closed
			locations[FindLocation("wr_library")].type = "Rogers_repair_residence";

			locations[FindLocation("Tavern_storeroom")].type = "Rogers_neutral";
			Locations[FindLocation("Charles_windem_room")].reload.l3.disable = 1;//locked to storeroom
			Locations[FindLocation("Tavern_storeroom")].reload.l1.disable = 0;//to town
			Locations[FindLocation("Tavern_storeroom")].reload.l2.disable = 1;//to tavern
			Locations[FindLocation("Tavern_storeroom")].reload.l4.disable = 1;//to windem room

			Locations[FindLocation("Tavern_storeroom")].models.always.locators = "store04_locators_JRH4";//with planks and fall down locator
			Locations[FindLocation("wr_armory")].models.always.locators = "LS_l_JRH5";//no smoke
			Locations[FindLocation("wr_shop")].models.always.locators = "residence05_locators_JRH_Lup";
			locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
			locations[FindLocation("shop_stairs")].id.label = "Rogers' Paintings Furniture & Weapons";			
			locations[FindLocation("wr_mother_stairs")].id.label = "Grandma's stairs";
			
			Locations[FindLocation("wr_mother")].reload.l1.disable = 0;//to stairs
			Locations[FindLocation("wr_mother")].locators_radius.goto.goto7 = 2.5;		

			Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
			Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
			Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
			Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
			Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

			Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
			Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
			Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
			Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
			Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

			Locations[FindLocation("Redmond_UsurerHouse")].reload.l6.disable = 0;//to cellar
			locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";

			ChangeCharacterAddressGroup(CharacterFromID("wr_bucc1"), "Redmond_tavern", "goto", "guard1");
			ChangeCharacterAddressGroup(CharacterFromID("wr_boc16"), "Redmond_tavern", "goto", "guard2");

			ChangeCharacterAddressGroup(CharacterFromID("grandma"), "wr_mother", "goto", "goto2");
			LAi_SetStayType(CharacterFromID("grandma"));
			ChangeCharacterAddressGroup(CharacterFromID("Wench3"), "ck_bedroom", "goto", "goto3");
			ChangeCharacterAddressGroup(CharacterFromID("Woodes Rogers"), "wr_bedroom", "goto", "goto5");
			LAi_SetStayType(CharacterFromID("Woodes Rogers"));
			ChangeCharacterAddressGroup(CharacterFromID("Dave Edna"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("wr_pir13"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("wr_oman1X"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("powdermonkey"), "none", "", "");
			ChangeCharacterAddressGroup(CharacterFromID("Charles Windem"), "Charles_Windem_room", "sit", "sit2");
			LAi_SetActorType(CharacterFromID("Charles Windem"));
			LAi_ActorSetLayMode(CharacterFromID("Charles Windem"));
			ChangeCharacterAddressGroup(CharacterFromID("wr_boc1"), "none", "", "");//bald with whiskers in library

			Locations[FindLocation("wr_library")].models.always.locators = "Res02_l_JRH2";//right one here
			
			Locations[FindLocation("wr_kitchen")].models.always.locators = "FlamHouse_locators_JRH2";
			Locations[FindLocation("wr_kitchen")].reload.l1.disable = 1;//to town
			Locations[FindLocation("Redmond_Town_01")].reload.l16.disable = 1;//to kitchen

			Locations[FindLocation("Redmond_UsurerHouse")].reload.l2.disable = 1;//to shop
			Locations[FindLocation("wr_shop")].reload.l6.disable = 1;//to loanshark
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l1.disable = 1;//to town

			Locations[FindLocation("Redmond_Town_01")].reload.l10.disable = 1;//to LS
			Locations[FindLocation("Redmond_Town_01")].reload.l23.disable = 1;//to terrace
			bDisableFastReload = 1;			
			locations[FindLocation("Redmond_UsurerHouse")].id.label = "TEMPORARY OUT OF GOLD. OPEN SOON AGAIN. Robyn Corrick - bank manager";
			ChangeCharacterAddressGroup(CharacterFromID("Redmond Usurer"), "none", "", "");

			Locations[FindLocation("wr_shop")].reload.l3.disable = 0;//to shop entrй
			Locations[FindLocation("Redmond_Town_01")].reload.l27.disable = 0;//to shop

			Locations[FindLocation("wr_residence")].reload.l7.disable = 1;//locked to arm

			Locations[FindLocation("wr_residence")].reload.l2.disable = 0;//open to lib
			Locations[FindLocation("wr_library")].reload.l2.disable = 0;//open to residence
			
			locations[FindLocation("storeroom_attic")].id.label = "Storeroom attic";
			locations[FindLocation("Charles_Windem_room")].id.label = "Charles Windem's room";

			ChangeCharacterAddressGroup(CharacterFromID("wr_boc4"), "none", "", "");//library guards disturbing textlog
			ChangeCharacterAddressGroup(CharacterFromID("wr_cor1_1"), "none", "", "");

			ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "wr_residence", "sit", "sit2");
			ChangeCharacterAddressGroup(CharacterFromID("wr_voy"), "wr_library", "goto", "goto18");
			
			Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH3";//needed here?
			locations[FindLocation("ck_bedroom")].id.label = "Caroline K's bedroom";

			//reusing 6 walkers from shop to crew quarters
			ChangeCharacterAddressGroup(CharacterFromID("wr_fsh"), "wr_crew", "sit", "sit2");
			LAi_SetSitType(CharacterFromID("wr_fsh"));
			RemoveCharacterEquip(characterFromID("wr_fsh"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_fsh"), "bladearmchair");
			EquipCharacterbyItem(characterFromID("wr_fsh"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_fsh"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_fatj"), "wr_crew", "sit", "sit3");
			LAi_SetSitType(CharacterFromID("wr_fatj"));
			RemoveCharacterEquip(characterFromID("wr_fatj"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_fatj"), "bladebasket");
			EquipCharacterbyItem(characterFromID("wr_fatj"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_fatj"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_cor3"), "wr_crew", "sit", "sit4");
			LAi_SetSitType(CharacterFromID("wr_cor3"));
			RemoveCharacterEquip(characterFromID("wr_cor3"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_cor3"), "pistol_armchair");
			EquipCharacterbyItem(characterFromID("wr_cor3"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_cor3"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_fralut"), "wr_crew", "goto", "stay1");
			LAi_SetCitizenType(CharacterFromID("wr_fralut"));
			RemoveCharacterEquip(characterFromID("wr_fralut"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_fralut"), "bladebasket");
			EquipCharacterbyItem(characterFromID("wr_fralut"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_fralut"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_mong"), "wr_crew", "sit", "sit5");
			LAi_SetSitType(CharacterFromID("wr_mong"));
			RemoveCharacterEquip(characterFromID("wr_mong"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_mong"), "bladebarrel");
			RemoveCharacterEquip(characterFromID("wr_mong"), GUN_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_mong"), "pistolbarrel");
			EquipCharacterbyItem(characterFromID("wr_mong"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_mong"), "pistol1");

			ChangeCharacterAddressGroup(CharacterFromID("wr_pir4"), "wr_crew", "sit", "sit6");
			LAi_SetSitType(CharacterFromID("wr_pir4"));
			RemoveCharacterEquip(characterFromID("wr_pir4"), BLADE_ITEM_TYPE);
			TakeItemFromCharacter(characterFromID("wr_pir4"), "bladeglobe");
			EquipCharacterbyItem(characterFromID("wr_pir4"), "blade4");
			EquipCharacterbyItem(characterFromID("wr_pir4"), "pistol1");

			Pchar.quest.wr_defoe = "incognito";
			Pchar.quest.rum_water = "filled";
			Pchar.quest.rum_molasses = "empty";	//after process
			Pchar.quest.rum_wheel = "off";		//autostops after process
			Pchar.quest.rum_damper = "open";	//probably open after process
			Pchar.quest.rum_fire = "lit";		//probably lit after process
			Pchar.quest.rum_fuel = "sack";		//book sack still there
			Pchar.quest.rum_phase = "4";		//after process
			Pchar.quest.rum_sack = "soon";		//latest case, never 'yes'

			locations[FindLocation("Redmond_Town_01")].type = "blues_town";
			locations[FindLocation("Redmond_Town_03")].type = "blues_town";
			locations[FindLocation("Redmond_Town_04")].type = "blues_town";
			locations[FindLocation("Redmond_Port")].type = "blues_port";
			locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

			//new
			Locations[FindLocation("wr_mother")].models.always.locators = "brothel_room_locators_JRH3";//invisible pistol for this shortcut	
			LAi_QuestDelay("steplock_mother", 0.1);//starts the steplock loop in wr_mother room
			LAi_QuestDelay("after_unlock_storeroom", 0.1);

			LAi_QuestDelay("subject_sound_architecture", 0.1);
			LAi_QuestDelay("office_ladder", 0.1);

			//RESTARTS WAY IN
			Pchar.quest.wr_terrace = "second_time";

			pchar.quest.terrace_in1.win_condition.l1 = "locator";
			pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
			pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
			pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
			pchar.quest.terrace_in1.win_condition = "terrace_in1";

			Pchar.quest.Teach_head = "7";

			PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];	
			link.l1.go = "how_to_return";
		break;

			case "8":
				//PORT ROYAL: TAVERN STOREROOM	before mission 6
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(23.00, 0);				
				SetNextWeather("Clear");	
			
				Pchar.quest.Rdm_officiant = "Claire";
				Pchar.quest.wr_quest1 = "pistol5";
				Pchar.quest.wr_quest2 = "shut_up_Caroline";
				Pchar.quest.wr_libstep = "libstep_open";
				Pchar.quest.wr_shop = "box8_tour_open";
				Pchar.quest.wr_shoppistol = "yes";
				Pchar.quest.wr_elevator = "up";//start position
				Pchar.quest.wr_kitchendoor = "stuck";

				//import from [7]
				Locations[FindLocation("wr_library")].locators_radius.reload.reload2 = 1.0;
				locations[FindLocation("wr_armory")].id.label = "Woodes Rogers' armory";
				Locations[FindLocation("wr_armory")].reload.l1.disable = 0;//gps

				locations[FindLocation("Redmond_tavern")].type = "house";
				Locations[FindLocation("Redmond_tavern")].models.always.locators = "LT_l_JRH3";//without characters
				Locations[FindLocation("JRH_tavern_upstairs")].models.always.locators = "LH_F2_l_JRH_open";

				locations[FindLocation("wr_kitchen")].id.label = "Woodes Rogers' kitchen";
		
				Locations[FindLocation("Redmond_Town_01")].reload.l18.disable = 1;//window to residence
				Locations[FindLocation("Redmond_tavern")].reload.l2.disable = 0;//to tavern_upstairs
				Locations[FindLocation("Redmond_town_01")].reload.l11.disable = 1;//to tavern
				Locations[FindLocation("Redmond_town_01")].reload.l31.disable = 1;//to tavern from balcony
	
				Locations[FindLocation("Redmond_tavern")].reload.l1.disable = 1;//to town
				Locations[FindLocation("Redmond_tavern")].reload.l3.disable = 1;//to balcony
				Locations[FindLocation("JRH_tavern_upstairs")].reload.l2.disable = 0;//to wr bed
				Locations[FindLocation("Redmond_town_01")].models.always.locators = "Red01_l_JRH4";//bridge THIS IS ONLY TEMP TURNED OFF FOR TEST PURPOSE

				Locations[FindLocation("wr_residence")].reload.l3.disable = 1;//window now closed
				Locations[FindLocation("wr_residence")].reload.l1.disable = 0;//terrace
				Locations[FindLocation("wr_library")].reload.l1.disable = 1;//library to storeroom closed
				locations[FindLocation("wr_library")].id.label = "Woodes Rogers' library";
				Locations[FindLocation("Tavern_storeroom")].reload.l3.disable = 1;//storeroom to library closed
				locations[FindLocation("wr_library")].type = "Rogers_repair_residence";

				locations[FindLocation("Tavern_storeroom")].type = "Rogers_neutral";
				Locations[FindLocation("Charles_windem_room")].reload.l3.disable = 1;//locked to storeroom
				Locations[FindLocation("Tavern_storeroom")].reload.l4.disable = 1;//to windem room
				Locations[FindLocation("Tavern_storeroom")].models.always.locators = "store04_locators_JRH4";//with planks and fall down locator
				Locations[FindLocation("wr_armory")].models.always.locators = "LS_l_JRH5";//no smoke
				Locations[FindLocation("wr_shop")].models.always.locators = "residence05_locators_JRH_Lup";
				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
		
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l6.disable = 0;//to cellar
				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";

				ChangeCharacterAddressGroup(CharacterFromID("Wench3"), "ck_bedroom", "goto", "goto3");
				ChangeCharacterAddressGroup(CharacterFromID("Dave Edna"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("wr_pir13"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("wr_oman1X"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("powdermonkey"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("wr_boc1"), "none", "", "");//bald with whiskers in library

				Locations[FindLocation("wr_library")].models.always.locators = "Res02_l_JRH2";//right one here
			
				Locations[FindLocation("wr_kitchen")].models.always.locators = "FlamHouse_locators_JRH2";
				Locations[FindLocation("wr_kitchen")].reload.l1.disable = 1;//to town
				Locations[FindLocation("Redmond_Town_01")].reload.l16.disable = 1;//to kitchen

				Locations[FindLocation("Redmond_UsurerHouse")].reload.l2.disable = 1;//to shop
				Locations[FindLocation("wr_shop")].reload.l6.disable = 1;//to loanshark
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l1.disable = 1;//to town
				Locations[FindLocation("Redmond_Town_01")].reload.l10.disable = 1;//to LS			
				locations[FindLocation("Redmond_UsurerHouse")].id.label = "TEMPORARY OUT OF GOLD. OPEN SOON AGAIN. Robyn Corrick - bank manager";
				ChangeCharacterAddressGroup(CharacterFromID("Redmond Usurer"), "none", "", "");

				Locations[FindLocation("wr_shop")].reload.l3.disable = 0;//to shop entrй
				Locations[FindLocation("Redmond_Town_01")].reload.l27.disable = 0;//to shop

				Locations[FindLocation("wr_residence")].reload.l7.disable = 1;//locked to arm

				Locations[FindLocation("wr_residence")].reload.l2.disable = 0;//open to lib
				Locations[FindLocation("wr_library")].reload.l2.disable = 0;//open to residence
			
				locations[FindLocation("storeroom_attic")].id.label = "Storeroom attic";
				locations[FindLocation("Charles_Windem_room")].id.label = "Charles Windem's room";

				ChangeCharacterAddressGroup(CharacterFromID("wr_boc4"), "none", "", "");//library guards disturbing textlog
				ChangeCharacterAddressGroup(CharacterFromID("wr_cor1_1"), "none", "", "");

				ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "wr_residence", "sit", "sit2");
				ChangeCharacterAddressGroup(CharacterFromID("wr_voy"), "wr_library", "goto", "goto18");
			
				Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH3";//needed here?

				Locations[FindLocation("wr_mother")].models.always.locators = "brothel_room_locators_JRH3";//invisible pistol for this shortcut	
				Locations[FindLocation("wr_mother")].locators_radius.goto.goto7 = 2.5;			

				Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
				Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
				Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
				Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
				Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

				ChangeCharacterAddressGroup(CharacterFromID("wr_bucc1"), "Redmond_tavern", "goto", "guard1");
				ChangeCharacterAddressGroup(CharacterFromID("wr_boc16"), "Redmond_tavern", "goto", "guard2");

				//reusing 6 walkers from shop to crew quarters
				ChangeCharacterAddressGroup(CharacterFromID("wr_fsh"), "wr_crew", "sit", "sit2");
				LAi_SetSitType(CharacterFromID("wr_fsh"));
				RemoveCharacterEquip(characterFromID("wr_fsh"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fsh"), "bladearmchair");
				GiveItem2Character(CharacterFromID("wr_fsh"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fsh"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fsh"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fsh"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_fatj"), "wr_crew", "sit", "sit3");
				LAi_SetSitType(CharacterFromID("wr_fatj"));
				RemoveCharacterEquip(characterFromID("wr_fatj"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fatj"), "bladebasket");
				GiveItem2Character(CharacterFromID("wr_fatj"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fatj"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fatj"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fatj"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_cor3"), "wr_crew", "sit", "sit4");
				LAi_SetSitType(CharacterFromID("wr_cor3"));
				RemoveCharacterEquip(characterFromID("wr_cor3"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_cor3"), "pistol_armchair");
				GiveItem2Character(CharacterFromID("wr_cor3"), "blade4");
				GiveItem2Character(CharacterFromID("wr_cor3"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_cor3"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_cor3"), "pistol1");

				//ChangeCharacterAddressGroup(CharacterFromID("wr_fralut"), "wr_crew", "goto", "stay1");
				ChangeCharacterAddressGroup(CharacterFromID("wr_fralut"), "wr_crew", "waitress", "stay2");
				LAi_SetCitizenType(CharacterFromID("wr_fralut"));
				RemoveCharacterEquip(characterFromID("wr_fralut"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fralut"), "bladebasket");
				GiveItem2Character(CharacterFromID("wr_fralut"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fralut"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fralut"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fralut"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_mong"), "wr_crew", "sit", "sit5");
				LAi_SetSitType(CharacterFromID("wr_mong"));
				RemoveCharacterEquip(characterFromID("wr_mong"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_mong"), "bladebarrel");
				RemoveCharacterEquip(characterFromID("wr_mong"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_mong"), "pistolbarrel");
				GiveItem2Character(CharacterFromID("wr_mong"), "blade4");
				GiveItem2Character(CharacterFromID("wr_mong"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_mong"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_mong"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_pir4"), "wr_crew", "sit", "sit6");
				LAi_SetSitType(CharacterFromID("wr_pir4"));
				RemoveCharacterEquip(characterFromID("wr_pir4"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_pir4"), "bladeglobe");
				GiveItem2Character(CharacterFromID("wr_pir4"), "blade4");
				GiveItem2Character(CharacterFromID("wr_pir4"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_pir4"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_pir4"), "pistol1");

				Pchar.quest.wr_defoe = "incognito";
				Pchar.quest.rum_water = "filled";
				Pchar.quest.rum_molasses = "empty";	//after process
				Pchar.quest.rum_wheel = "off";		//autostops after process
				Pchar.quest.rum_damper = "open";	//probably open after process
				Pchar.quest.rum_fire = "lit";		//probably lit after process
				Pchar.quest.rum_fuel = "sack";		//book sack still there
				Pchar.quest.rum_phase = "4";		//after process
				Pchar.quest.rum_sack = "soon";		//latest case, never 'yes'

				locations[FindLocation("Tavern_storeroom")].id.label = "Tavern storeroom";
				Locations[FindLocation("Tavern_storeroom")].reload.l1.disable = 0;//to town
				Locations[FindLocation("Redmond_Town_01")].reload.l26.disable = 0;//to storeroom
				Locations[FindLocation("Redmond_Town_01")].reload.l23.disable = 1;//reload6 to terrace
				locations[FindLocation("Redmond_UsurerHouse")].id.label = "TEMPORARY OUT OF GOLD. OPEN SOON AGAIN. Robyn Corrick - bank manager";
				locations[FindLocation("ck_bedroom")].id.label = "Caroline K's bedroom";			

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";
			
				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("pistol5_end3", 0.1);
				LAi_QuestDelay("torch_unable", 0.1);//for direct jump to guard room
				LAi_QuestDelay("steplock_A_prison", 0.1);
			
				Pchar.quest.torch_enable = "no";//start value
				Pchar.quest.gas_level = "0";//start value
		
				//RESTARTS WAY IN
				Pchar.quest.wr_terrace = "second_time";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				Pchar.quest.Teach_head = "8";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "9":
				//PORT ROYAL: OUTSIDE SHIPYARD	ready for medicine collect part
				
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				Pchar.quest.outfit = "blue_uniform_hat";
			
				Pchar.quest.Rdm_officiant = "Claire";
			
				ChangeCharacterAddressGroup(CharacterFromID("wr_bucc1"), "Redmond_tavern", "goto", "guard1");
				ChangeCharacterAddressGroup(CharacterFromID("wr_boc16"), "Redmond_tavern", "goto", "guard2");

				//............................................................................................
				LAi_SetCitizenType(CharacterFromID("wr_bri"));
				ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "wr_chapel", "goto", "goto10");
				RemoveCharacterEquip(CharacterFromID("wr_bri"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("wr_bri"), "blade4");

				LAi_SetSitType(CharacterFromID("Defoe_incognito"));
				ChangeCharacterAddressGroup(CharacterFromID("Defoe_incognito"), "wr_chapel", "sit", "sit18");
				RemoveCharacterEquip(CharacterFromID("Defoe_incognito"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("Defoe_incognito"), "pistol201");
		
				ChangeCharacterAddressGroup(CharacterFromID("Sarah Fitter"), "none", "", "");//real Sarah removed
				ChangeCharacterAddressGroup(CharacterFromID("Laurence Wellman"), "none", "", "");//real Wellman removed
				ChangeCharacterAddressGroup(CharacterFromID("Father Bernard"), "none", "", "");//real Bernard removed

				LAi_SetHuberStayType(CharacterFromID("fake_Silehard"));
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap12"), "wr_church_outside", "goto", "goto2");
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap25"), "Redmond_shore_02", "goto", "goto10");
				locations[FindLocation("wr_cavern")].reload.l2.disable = 0;//open to shore

				Locations[FindLocation("Redmond_town_exit_2")].reload.l1.disable = 1;	//to town
				Locations[FindLocation("Redmond_shore_02")].models.always.locators = "shore03_l_JRH";
			
				Locations[FindLocation("wr_dungeon4_main")].environment.weather = "false";
				Locations[FindLocation("wr_dungeon4_main")].environment.sea = "false";
				Locations[FindLocation("wr_dungeon4_loop")].environment.weather = "false";
				Locations[FindLocation("wr_dungeon4_loop")].environment.sea = "false";

				ChangeCharacterAddressGroup(CharacterFromID("Red_guard_1"), "Redmond_town_exit_2", "goto", "goto11");
				ChangeCharacterAddressGroup(CharacterFromID("Red_guard_2"), "Redmond_town_exit_2", "goto", "goto12");

				Locations[FindLocation("wr_mine")].locators_radius.officers.reload2_1 = 2.0;
				Locations[FindLocation("wr_mine")].locators_radius.goto.goto2 = 0.5;
				Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L1";
				Locations[FindLocation("wr_dungeon3_right")].models.always.locators = "d03_l_JRH_R1";
				Locations[FindLocation("wr_mine")].models.always.locators = "Mine_l_JRH1";
				Locations[FindLocation("wr_mine_control")].models.always.locators = "d02_l_JRH1_F";
				Locations[FindLocation("wr_mine")].reload.l7.disable = 1;		//to mine control room
				Locations[FindLocation("wr_mine")].reload.l5.disable = 1;		//to tunnelA

				Locations[FindLocation("wr_mine")].reload.l2.disable = 0;
				Locations[FindLocation("Loanshark_cellar")].reload.l1.disable = 0;
				Locations[FindLocation("Redmond_UsurerHouse")].models.always.locators = "ss_l_JRH3";
				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";

				locations[FindLocation("storeroom_attic")].id.label = "Storeroom attic";
				locations[FindLocation("Charles_Windem_room")].id.label = "Charles Windem's room";

				Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
				Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
				Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
				Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
				Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l16.go = "WR_kitchen";
				Locations[FindLocation("Redmond_Town_01")].reload.l16.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l16.label = "Woodes Rogers' kitchen.";
				Locations[FindLocation("Redmond_Town_01")].reload.l16.disable = 0;

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";

				SetCurrentTime(12, 0);
				SetNextWeather("Blue Sky");

				Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH5";	//bridge visible + exit backdoor loanshark
		
				ChangeCharacterAddressGroup(CharacterFromID("Woodes Rogers"), "Redmond_Town_01", "goto", "goto29");
				LAi_SetStayType(CharacterFromID("Woodes Rogers"));

				//SetCharacterShipLocation(characterFromID("Woodes Rogers"), "wr_port");
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

				ChangeCharacterAddressGroup(CharacterFromID("wr_boc1"), "Redmond_Town_04", "goto", "goto_48");
				ChangeCharacterAddressGroup(CharacterFromID("wr_kor"), "Redmond_Town_04", "goto", "goto_49");
		
				//reusing 6 walkers from shop to crew quarters
				ChangeCharacterAddressGroup(CharacterFromID("wr_fsh"), "wr_crew", "sit", "sit2");
				LAi_SetSitType(CharacterFromID("wr_fsh"));
				RemoveCharacterEquip(characterFromID("wr_fsh"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fsh"), "bladearmchair");
				GiveItem2Character(CharacterFromID("wr_fsh"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fsh"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fsh"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fsh"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_fatj"), "wr_crew", "sit", "sit3");
				LAi_SetSitType(CharacterFromID("wr_fatj"));
				RemoveCharacterEquip(characterFromID("wr_fatj"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fatj"), "bladebasket");
				GiveItem2Character(CharacterFromID("wr_fatj"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fatj"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fatj"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fatj"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_cor3"), "wr_crew", "sit", "sit4");
				LAi_SetSitType(CharacterFromID("wr_cor3"));
				RemoveCharacterEquip(characterFromID("wr_cor3"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_cor3"), "pistol_armchair");
				GiveItem2Character(CharacterFromID("wr_cor3"), "blade4");
				GiveItem2Character(CharacterFromID("wr_cor3"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_cor3"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_cor3"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_fralut"), "wr_crew", "waitress", "stay2");
				LAi_SetCitizenType(CharacterFromID("wr_fralut"));
				RemoveCharacterEquip(characterFromID("wr_fralut"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fralut"), "bladebasket");
				GiveItem2Character(CharacterFromID("wr_fralut"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fralut"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fralut"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fralut"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_mong"), "wr_crew", "sit", "sit5");
				LAi_SetSitType(CharacterFromID("wr_mong"));
				RemoveCharacterEquip(characterFromID("wr_mong"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_mong"), "bladebarrel");
				RemoveCharacterEquip(characterFromID("wr_mong"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_mong"), "pistolbarrel");
				GiveItem2Character(CharacterFromID("wr_mong"), "blade4");
				GiveItem2Character(CharacterFromID("wr_mong"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_mong"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_mong"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_pir4"), "wr_crew", "sit", "sit6");
				LAi_SetSitType(CharacterFromID("wr_pir4"));
				RemoveCharacterEquip(characterFromID("wr_pir4"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_pir4"), "bladeglobe");
				GiveItem2Character(CharacterFromID("wr_pir4"), "blade4");
				GiveItem2Character(CharacterFromID("wr_pir4"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_pir4"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_pir4"), "pistol1");
		
				ChangeCharacterAddressGroup(CharacterFromID("PowderMonkey"), "none", "", "");

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";
	
				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("cavern_chest_stop", 0.1);//started also during first visit to cavern (fall from mine)
				LAi_QuestDelay("rogers_talks_medicine", 0.1);

				//RESTARTS WAY IN
				Pchar.quest.wr_terrace = "second_time";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";
			
				Pchar.quest.Teach_head = "9";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "10":
				//CAVE SHORE: MEDICINES COLLECTED
				//use shortcut cave shore
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(23.00, 0);				
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";	
			
				Pchar.quest.Rdm_officiant = "Claire";
			
				ChangeCharacterAddressGroup(CharacterFromID("wr_bucc1"), "Redmond_tavern", "goto", "guard1");
				ChangeCharacterAddressGroup(CharacterFromID("wr_boc16"), "Redmond_tavern", "goto", "guard2");

				//............................................................................................
				LAi_SetCitizenType(CharacterFromID("wr_bri"));
				ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "wr_chapel", "goto", "goto10");
				RemoveCharacterEquip(CharacterFromID("wr_bri"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("wr_bri"), "blade4");

				LAi_SetSitType(CharacterFromID("Defoe_incognito"));
				ChangeCharacterAddressGroup(CharacterFromID("Defoe_incognito"), "wr_chapel", "sit", "sit18");
				RemoveCharacterEquip(CharacterFromID("Defoe_incognito"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("Defoe_incognito"), "pistol201");
		
				ChangeCharacterAddressGroup(CharacterFromID("Sarah Fitter"), "none", "", "");//real Sarah removed
				ChangeCharacterAddressGroup(CharacterFromID("Laurence Wellman"), "none", "", "");//real Wellman removed
				ChangeCharacterAddressGroup(CharacterFromID("Father Bernard"), "none", "", "");//real Bernard removed

				LAi_SetHuberStayType(CharacterFromID("fake_Silehard"));
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap12"), "wr_church_outside", "goto", "goto2");
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap25"), "Redmond_shore_02", "goto", "goto10");
				locations[FindLocation("wr_cavern")].reload.l2.disable = 0;//open to shore

				Locations[FindLocation("Redmond_town_exit_2")].reload.l1.disable = 1;	//to town
				Locations[FindLocation("Redmond_shore_02")].models.always.locators = "shore03_l_JRH";
			
				Locations[FindLocation("wr_dungeon4_main")].environment.weather = "false";
				Locations[FindLocation("wr_dungeon4_main")].environment.sea = "false";
				Locations[FindLocation("wr_dungeon4_loop")].environment.weather = "false";
				Locations[FindLocation("wr_dungeon4_loop")].environment.sea = "false";

				ChangeCharacterAddressGroup(CharacterFromID("Red_guard_1"), "Redmond_town_exit_2", "goto", "goto11");
				ChangeCharacterAddressGroup(CharacterFromID("Red_guard_2"), "Redmond_town_exit_2", "goto", "goto12");

				Locations[FindLocation("wr_mine")].locators_radius.officers.reload2_1 = 2.0;
				Locations[FindLocation("wr_mine")].locators_radius.goto.goto2 = 0.5;
				Locations[FindLocation("wr_dungeon3_left")].models.always.locators = "d03_l_JRH_L1";
				Locations[FindLocation("wr_dungeon3_right")].models.always.locators = "d03_l_JRH_R1";
				Locations[FindLocation("wr_mine")].models.always.locators = "Mine_l_JRH1";
				Locations[FindLocation("wr_mine_control")].models.always.locators = "d02_l_JRH1_F";
				Locations[FindLocation("wr_mine")].reload.l7.disable = 1;		//to mine control room
				Locations[FindLocation("wr_mine")].reload.l5.disable = 1;		//to tunnelA

				Locations[FindLocation("wr_mine")].reload.l2.disable = 0;
				Locations[FindLocation("Loanshark_cellar")].reload.l1.disable = 0;
				Locations[FindLocation("Redmond_UsurerHouse")].models.always.locators = "ss_l_JRH3";	
				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";

				Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH5";	//bridge visible + exit backdoor loanshark
			
				locations[FindLocation("storeroom_attic")].id.label = "Storeroom attic";
				locations[FindLocation("Charles_Windem_room")].id.label = "Charles Windem's room";
	
				Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
				Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
				Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
				Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
				Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
			
				ChangeCharacterAddressGroup(CharacterFromID("Woodes Rogers"), "Redmond_Town_01", "goto", "goto29");
				LAi_SetStayType(CharacterFromID("Woodes Rogers"));
			
				//SetCharacterShipLocation(characterFromID("Woodes Rogers"), "wr_port");
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

				ChangeCharacterAddressGroup(CharacterFromID("wr_boc1"), "Redmond_Town_04", "goto", "goto_48");
				ChangeCharacterAddressGroup(CharacterFromID("wr_kor"), "Redmond_Town_04", "goto", "goto_49");

				//reusing 6 walkers from shop to crew quarters
				ChangeCharacterAddressGroup(CharacterFromID("wr_fsh"), "wr_crew", "sit", "sit2");
				LAi_SetSitType(CharacterFromID("wr_fsh"));
				RemoveCharacterEquip(characterFromID("wr_fsh"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fsh"), "bladearmchair");
				GiveItem2Character(CharacterFromID("wr_fsh"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fsh"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fsh"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fsh"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_fatj"), "wr_crew", "sit", "sit3");
				LAi_SetSitType(CharacterFromID("wr_fatj"));
				RemoveCharacterEquip(characterFromID("wr_fatj"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fatj"), "bladebasket");
				GiveItem2Character(CharacterFromID("wr_fatj"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fatj"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fatj"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fatj"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_cor3"), "wr_crew", "sit", "sit4");
				LAi_SetSitType(CharacterFromID("wr_cor3"));
				RemoveCharacterEquip(characterFromID("wr_cor3"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_cor3"), "pistol_armchair");
				GiveItem2Character(CharacterFromID("wr_cor3"), "blade4");
				GiveItem2Character(CharacterFromID("wr_cor3"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_cor3"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_cor3"), "pistol1");

				//ChangeCharacterAddressGroup(CharacterFromID("wr_fralut"), "wr_crew", "goto", "stay1");
				ChangeCharacterAddressGroup(CharacterFromID("wr_fralut"), "wr_crew", "waitress", "stay2");
				LAi_SetCitizenType(CharacterFromID("wr_fralut"));
				RemoveCharacterEquip(characterFromID("wr_fralut"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fralut"), "bladebasket");
				GiveItem2Character(CharacterFromID("wr_fralut"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fralut"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fralut"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fralut"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_mong"), "wr_crew", "sit", "sit5");
				LAi_SetSitType(CharacterFromID("wr_mong"));
				RemoveCharacterEquip(characterFromID("wr_mong"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_mong"), "bladebarrel");
				RemoveCharacterEquip(characterFromID("wr_mong"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_mong"), "pistolbarrel");
				GiveItem2Character(CharacterFromID("wr_mong"), "blade4");
				GiveItem2Character(CharacterFromID("wr_mong"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_mong"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_mong"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_pir4"), "wr_crew", "sit", "sit6");
				LAi_SetSitType(CharacterFromID("wr_pir4"));
				RemoveCharacterEquip(characterFromID("wr_pir4"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_pir4"), "bladeglobe");
				GiveItem2Character(CharacterFromID("wr_pir4"), "blade4");
				GiveItem2Character(CharacterFromID("wr_pir4"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_pir4"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_pir4"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("PowderMonkey"), "none", "", "");

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";
		
				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("cavern_chest_stop", 0.1);//started also during first visit to cavern (fall from mine)
				LAi_QuestDelay("cannon_tower", 0.1);

				//RESTARTS WAY IN
				Pchar.quest.wr_terrace = "second_time";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				Pchar.quest.Teach_head = "10";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "11":
				//PORT ROYAL: SHIPYARD BEFORE FARM

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");
			
				Pchar.quest.Rdm_officiant = "Claire";
				
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

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
				SetCharacterShipLocation(characterFromID("CoastBrother33"), "Redmond_shore_03");//tartane2
				SetCharacterShipLocation(characterFromID("CoastBrother25"), "wr_port");		//prize ship galleon
				SetCharacterShipLocation(characterFromID("CoastBrother26"), "wr_port");		//prize ship corvette
				SetCharacterShipLocation(characterFromID("wr_aub"), "wr_ships");		//boat2
				//----------------------------------------------------------------------------------------------------------------------
				ChangeCharacterAddressGroup(CharacterFromID("wr_boc1"), "Redmond_Town_04", "goto", "goto_48");
				ChangeCharacterAddressGroup(CharacterFromID("wr_kor"), "Redmond_Town_04", "goto", "goto_49");

				ChangeCharacterAddressGroup(CharacterFromID("wr_bucc1"), "Redmond_tavern", "goto", "guard1");
				ChangeCharacterAddressGroup(CharacterFromID("wr_boc16"), "Redmond_tavern", "goto", "guard2");
		
				//reusing 6 walkers from shop to crew quarters
				ChangeCharacterAddressGroup(CharacterFromID("wr_fsh"), "wr_crew", "sit", "sit2");
				LAi_SetSitType(CharacterFromID("wr_fsh"));
				RemoveCharacterEquip(characterFromID("wr_fsh"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fsh"), "bladearmchair");
				GiveItem2Character(CharacterFromID("wr_fsh"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fsh"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fsh"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fsh"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_fatj"), "wr_crew", "sit", "sit3");
				LAi_SetSitType(CharacterFromID("wr_fatj"));
				RemoveCharacterEquip(characterFromID("wr_fatj"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fatj"), "bladebasket");
				GiveItem2Character(CharacterFromID("wr_fatj"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fatj"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fatj"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fatj"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_cor3"), "wr_crew", "sit", "sit4");
				LAi_SetSitType(CharacterFromID("wr_cor3"));
				RemoveCharacterEquip(characterFromID("wr_cor3"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_cor3"), "pistol_armchair");
				GiveItem2Character(CharacterFromID("wr_cor3"), "blade4");
				GiveItem2Character(CharacterFromID("wr_cor3"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_cor3"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_cor3"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_fralut"), "wr_crew", "waitress", "stay2");
				LAi_SetCitizenType(CharacterFromID("wr_fralut"));
				RemoveCharacterEquip(characterFromID("wr_fralut"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_fralut"), "bladebasket");
				GiveItem2Character(CharacterFromID("wr_fralut"), "blade4");
				GiveItem2Character(CharacterFromID("wr_fralut"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_fralut"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_fralut"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_mong"), "wr_crew", "sit", "sit5");
				LAi_SetSitType(CharacterFromID("wr_mong"));
				RemoveCharacterEquip(characterFromID("wr_mong"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_mong"), "bladebarrel");
				RemoveCharacterEquip(characterFromID("wr_mong"), GUN_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_mong"), "pistolbarrel");
				GiveItem2Character(CharacterFromID("wr_mong"), "blade4");
				GiveItem2Character(CharacterFromID("wr_mong"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_mong"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_mong"), "pistol1");

				ChangeCharacterAddressGroup(CharacterFromID("wr_pir4"), "wr_crew", "sit", "sit6");
				LAi_SetSitType(CharacterFromID("wr_pir4"));
				RemoveCharacterEquip(characterFromID("wr_pir4"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(characterFromID("wr_pir4"), "bladeglobe");
				GiveItem2Character(CharacterFromID("wr_pir4"), "blade4");
				GiveItem2Character(CharacterFromID("wr_pir4"), "pistol1");
				EquipCharacterbyItem(characterFromID("wr_pir4"), "blade4");
				EquipCharacterbyItem(characterFromID("wr_pir4"), "pistol1");

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("cavern_chest_stop", 0.1);//started also during first visit to cavern (fall from mine)
				LAi_QuestDelay("ready_for_ships0", 0.1);	//start from redmond, this way no problems

				//RESTARTS WAY IN
				bDisableFastReload = 1;
				Pchar.quest.wr_terrace = "second_time";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				Pchar.quest.Teach_head = "11";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "12":
				//SHIPS: LONG RUN TO VANE'S
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");
			
				Pchar.quest.Rdm_officiant = "Claire";
			
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";	

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
			SetCharacterShipLocation(characterFromID("pir_cap23"), "wr_cave_shore");		//ok?
			
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
				SetCharacterShipLocation(characterFromID("CoastBrother33"), "Redmond_shore_03");//tartane2
				SetCharacterShipLocation(characterFromID("CoastBrother25"), "wr_port");		//prize ship galleon
				SetCharacterShipLocation(characterFromID("CoastBrother26"), "wr_port");		//prize ship corvette
				SetCharacterShipLocation(characterFromID("CoastBrother27"), "wr_port");		//boat2
				SetCharacterShipLocation(characterFromID("wr_aub"), "wr_ships");		//boat2
				//----------------------------------------------------------------------------------------------------------------------
				ChangeCharacterAddressGroup(CharacterFromID("wr_boc1"), "Redmond_Town_04", "goto", "goto_48");
				ChangeCharacterAddressGroup(CharacterFromID("wr_kor"), "Redmond_Town_04", "goto", "goto_49");
			
				Locations[FindLocation("wr_ships")].models.always.l2 = "";
				Locations[FindLocation("wr_ships")].models.always.l3 = "";
				Locations[FindLocation("wr_ships")].models.always.l6 = "elevator&ropes_C1";
				Locations[FindLocation("wr_ships")].models.always.l7 = "elevator&ropes_G1";
				Locations[FindLocation("wr_ships")].models.always.l8 = "";
				Locations[FindLocation("wr_ships")].models.always.l9 = "plank1";
				Locations[FindLocation("wr_ships")].models.always.l10 = "pinion_small_L";	
				Locations[FindLocation("wr_ships")].models.always.l11 = "pinion_large_R";	
				Locations[FindLocation("wr_ships")].models.always.l12 = "hubs";
				Locations[FindLocation("wr_ships")].models.always.l13 = "wheel_R";
				Locations[FindLocation("wr_ships")].models.always.l15 = "";
				Locations[FindLocation("wr_ships")].models.always.l18 = "door_broken";
				Locations[FindLocation("wr_ships")].reload.l5.disable = 0;
				Locations[FindLocation("wr_ships")].reload.l8.disable = 0;
				Locations[FindLocation("wr_ships")].reload.l9.disable = 0;
				Locations[FindLocation("wr_ships")].reload.l10.disable = 0;
				Locations[FindLocation("wr_ships")].reload.l11.disable = 0;
				Locations[FindLocation("wr_ships")].locators_radius.reload.reload12 = 0.0001;
				Locations[FindLocation("wr_ships")].locators_radius.reload.reload6 = 1.0;
				Locations[FindLocation("wr_ships")].locators_radius.box.box4 = 0.0001;
				Locations[FindLocation("wr_ships")].locators_radius.box.box6 = 0.0001;
				Locations[FindLocation("wr_ships")].locators_radius.box.box7 = 0.0001;
				Locations[FindLocation("wr_ships")].locators_radius.box.box9 = 0.0001;

				Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.box.box5 = 0.0001;
				Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.box.box6 = 0.0001;
				Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.reload.reload2 = 1.0;
				Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.reload.reload3 = 1.0;
				Locations[FindLocation("wr_gall_deck2_stern")].reload.l5.disable = 0;

				Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.box.box1 = 0.0001;
				Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.box.box2 = 0.0001;
				Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.reload.reload2 = 1.0;
				Locations[FindLocation("wr_gall_deck2_prow")].locators_radius.reload.reload3 = 1.0;
				Locations[FindLocation("wr_gall_deck2_prow")].reload.l1.disable = 0;

				Locations[FindLocation("wr_corv_capsm")].reload.l1.disable = 0;
				Locations[FindLocation("wr_corv_capsm")].models.always.l2 = "stopboom_R";

				Locations[FindLocation("wr_corv_crew")].models.always.locators = "camp_deck_l_JRH1B";//dummy without belt

				Locations[FindLocation("wr_gall_hold_first")].reload.l1.disable = 0;
				Locations[FindLocation("wr_gall_hold_first")].models.always.l2 = "plank1";
				Locations[FindLocation("wr_gall_hold_first")].models.always.l3 = "elevatornoropes_G1";

				Locations[FindLocation("wr_gall_hold_second")].reload.l2.disable = 0;
				Locations[FindLocation("wr_gall_hold_second")].reload.l3.disable = 0;
				Locations[FindLocation("wr_gall_hold_second")].locators_radius.reload.reload3 = 1.0;
				Locations[FindLocation("wr_gall_hold_second")].locators_radius.box.box2 = 0.0001;
				Locations[FindLocation("wr_gall_hold_second")].id.label = "Cargo Hold";

				Locations[FindLocation("wr_gall_cap_outer")].id.label = "Captain's deck";

				//............................................................................................
				Locations[FindLocation("wr_ships")].models.always.locators = "udeck_l_JRH_S1";

				Locations[FindLocation("Redmond_Town_01")].models.always.locators = "Red01_l_JRH5";	//bridge visible + exit backdoor loanshark
				Locations[FindLocation("Redmond_town_exit_2")].models.always.locators = "Redexit2_l_JRH";//well
				Locations[FindLocation("Redmond_tavern")].models.always.locators = "LT_l_JRH3";
				Locations[FindLocation("Redmond_UsurerHouse")].models.always.locators = "ss_l_JRH3";
				Locations[FindLocation("Redmond_shore_02")].models.always.locators = "shore03_l";	//no tartane	

				Locations[FindLocation("wr_animists_stairs")].reload.l2.disable = 1;	//to chapel, already locked earlier by game
				Locations[FindLocation("wr_animists")].reload.l1.disable = 0;		//to crypt
				locations[FindLocation("Redmond_church")].reload.l3.disable = 0;	//to crypt
				Locations[FindLocation("Redmond_Town_01")].reload.l13.disable = 0;	//to governor's residence
				Locations[FindLocation("Redmond_Town_01")].reload.l18.disable = 1;	//to window
				Locations[FindLocation("Redmond_Town_01")].reload.l23.disable = 1;	//to gate
				Locations[FindLocation("Redmond_Town_01")].reload.l20.disable = 1;	//to backdoor LS
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l4.disable = 1;	//to counter
				locations[FindLocation("Redmond_tavern")].reload.l3.disable = 1;	//to balcony
				locations[FindLocation("Redmond_tavern")].reload.l6.disable = 1;	//to storeroom
				Locations[FindLocation("Redmond_Port")].reload.l6.disable = 0;		//to harbour office
				Locations[FindLocation("Redmond_Town_exit_2")].reload.l1.disable = 0;	//to town
				Locations[FindLocation("Redmond_Town_exit_2")].reload.l5.disable = 1;	//to well
			
				locations[FindLocation("wr_crypt")].id.label = "Port Royal catacombs";
				locations[FindLocation("WR_kitchen")].id.label = "Woodes Rogers' kitchen";
				locations[FindLocation("Tavern_storeroom")].id.label = "Tavern storeroom";
				locations[FindLocation("Shop_stairs")].id.label = "Rogers' Paintings Furniture & Weapons";
				locations[FindLocation("wr_crew")].id.label = "Crew's quarter";
				locations[FindLocation("wr_library")].id.label = "Woodes Rogers' library";
				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";

				Locations[FindLocation("Redmond_shipyard")].locators_radius.officers.reload2_1 = 2.0;

				ChangeCharacterAddressGroup(CharacterFromID("Red_guard_1"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("Red_guard_2"), "none", "", "");

				ChangeCharacterAddressGroup(CharacterFromID("Claire Voyant"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("Sarah Fitter"), "Redmond_town_04", "merchant", "merchant1"); 
				ChangeCharacterAddressGroup(CharacterFromID("Laurence Wellman"), "Redmond_Head_port_house", "goto", "locator1");
				ChangeCharacterAddressGroup(CharacterFromID("Father Bernard"), "Redmond_church", "goto", "goto11");

				ChangeCharacterAddressGroup(characterFromID("fake_Red_Docker_1"), "Shipyard_Shore", "sit", "sit1");
				ChangeCharacterAddressGroup(characterFromID("fake_Red_Docker_2"), "Shipyard_Shore", "goto", "goto4");
				ChangeCharacterAddressGroup(characterFromID("fake_Gillian_Atterbury"), "Shipyard_Shore", "goto", "goto2");
				ChangeCharacterAddressGroup(characterFromID("fake_Griffith_Peabody"), "Shipyard_Shore", "goto", "citizen01");
				ChangeCharacterAddressGroup(characterFromID("fake_Elias_Belt"), "Shipyard_Shore", "goto", "goto23");
				LAi_SetSitType(characterFromID("fake_Red_Docker_1"));
				LAi_SetCitizenType(characterFromID("fake_Red_Docker_2"));
				LAi_SetStayType(characterFromID("fake_Gillian_Atterbury"));
				LAi_SetCitizenType(characterFromID("fake_Griffith_Peabody"));
				LAi_SetCitizenType(characterFromID("fake_Elias_Belt"));

				ChangeCharacterAddressGroup(CharacterFromID("prisoner_Silehard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("prisoner_wr_bri"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("prisoner_Sarah_Fitter"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("prisoner_Laurence_Wellman"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("prisoner_Defoe_incognito"), "none", "", "");

				ChangeCharacterAddressGroup(CharacterFromID("fake_Silehard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Sarah_Fitter"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Laurence_Wellman"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				//...........................................................................................
				RemoveCharacterEquip(characterFromID("wr_fsh"), BLADE_ITEM_TYPE); 
				TakeItemFromCharacter(characterFromID("wr_fsh"), "bladearmchair");			
			
				RemoveCharacterEquip(characterFromID("wr_cor3"), BLADE_ITEM_TYPE); 
				TakeItemFromCharacter(characterFromID("wr_cor3"), "pistol_armchair");

				Pchar.quest.disable_rebirth = true;
				Pchar.quest.anchor = "up";
				Pchar.quest.anchor_mechanism = "complete";
				Pchar.quest.ship_wc = "start";
				Pchar.quest.deck_bell = "broken";
				Pchar.quest.cannon_goodspile = "gone";
				Pchar.quest.elevatorG_status = "elevator_ready";
				Pchar.quest.plank_position = "deck";
				Pchar.quest.captains_door = "open";
				Pchar.quest.cap_inner_gp_box = "locked";
		
				Pchar.quest.mandala_position = "5";
				Locations[FindLocation("wr_animists")].filespath.textures = "locations\inside\ANIMISTS_Cave\mandala5";
				Locations[FindLocation("wr_animists")].reload.l1.disable = 0;		//crypt
				Locations[FindLocation("wr_animists")].reload.l2.disable = 1;		//animists_stairs
			
				Locations[FindLocation("wr_animists")].models.always.locators = "scave_l_JRH_ON5";
				Pchar.quest.med_Claire = "acetum";	//makes her silent or what?		

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("cavern_chest_stop", 0.1);//started also during first visit to cavern (fall from mine)
				LAi_QuestDelay("fall_to_hold", 0.1);	
				LAi_QuestDelay("prepare_leave_with_belt", 0.1);

				LAi_QuestDelay("defoes_cabin", 0.1);
				LAi_QuestDelay("shipyard_docks", 0.1);
				LAi_QuestDelay("subject_defoe_pirates", 0.1);
				LAi_QuestDelay("subject_defoe_travels", 0.1);
				LAi_QuestDelay("subject_defoe_alchemy", 0.1);
				LAi_QuestDelay("subject_defoe_selkirk", 0.1);

				//RESTARTS WAY IN
				bDisableFastReload = 1;
				Pchar.quest.wr_terrace = "second_time";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				Pchar.quest.Teach_head = "12";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "14":
				//CHOIR: LONG RUN TO VANE'S
				
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");		
			
				Pchar.quest.Rdm_officiant = "Claire";
				//............................................
			
				Locations[FindLocation("wr_corv_capsm")].reload.l1.disable = 0;
				Locations[FindLocation("wr_corv_capsm")].models.always.l2 = "stopboom_R";
			
				locations[FindLocation("Redmond_church")].reload.l2.disable = 0;
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";	

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
				locations[FindLocation("shipyard_stairs")].reload.l1.disable = 0;//back to shya

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

				Locations[FindLocation("wr_church_attic")].type = "Vane_jungle";

				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("fall_to_hold", 0.1);
				LAi_QuestDelay("cavern_chest_stop", 0.1);//started also during first visit to cavern (fall from mine)

				Pchar.quest.wet_gp = "yes";
				Pchar.quest.bsw_dead = "yes";
				Pchar.quest.choir_lockpick = "not_found";
				Pchar.quest.choir_clock = "neutral";
				Pchar.quest.choir_ladder = "not_found";

				ChangeCharacterAddressGroup(CharacterFromID("Father Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "Redmond_church", "goto", "goto11");
				LAi_SetPriestType(CharacterFromID("fake_father_Bernard"));

				locations[FindLocation("church_wine_cellar")].id.label = "Church wine cellar";
				locations[FindLocation("church_choir")].id.label = "Port Royal Church Choir";
				Locations[FindLocation("church_choir")].reload.l4.disable = 1;			//to wine cellar

				Locations[FindLocation("Redmond_church")].reload.l1.disable = 1;		//to town
				Locations[FindLocation("Redmond_church")].reload.l3.disable = 1;		//to crypt
				Locations[FindLocation("Redmond_church")].models.always.locators = "Church_l_JRH";
				locations[FindLocation("wr_crypt")].id.label = "Port Royal catacombs";
				Locations[FindLocation("wr_crypt")].models.always.locators = "d01_l_JRH2";	//mummies
		
				Locations[FindLocation("wr_animists")].models.always.locators = "scave_l_JRH_ON5";
				Pchar.quest.mandala_position = "5";
				Locations[FindLocation("wr_animists")].filespath.textures = "locations\inside\ANIMISTS_Cave\mandala5";

				Locations[FindLocation("wr_animists")].reload.l1.disable = 0;		//to crypt open????
				locations[FindLocation("wr_crypt")].id.label = "Port Royal catacombs";
				Locations[FindLocation("wr_animists")].reload.l2.disable = 1;		//to animists_stairs

				locations[FindLocation("wr_animists_stairs")].id.label = "Temple stairs";
				locations[FindLocation("wr_chapel_stairs")].id.label = "Chapel stairs";
				locations[FindLocation("wr_sacristy")].id.label = "Sacristy";

				ChangeCharacterAddressGroup(CharacterFromID("prisoner_Silehard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("prisoner_Laurence_Wellman"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("prisoner_Sarah_Fitter"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("prisoner_Defoe_incognito"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("prisoner_wr_bri"), "none", "", "");

				ChangeCharacterAddressGroup(CharacterFromID("fake_Silehard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Laurence_Wellman"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Sarah_Fitter"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "none", "", "");

				Locations[FindLocation("wr_animists_stairs")].reload.l2.disable = 0;		//to chapel
				Locations[FindLocation("wr_chapel")].reload.l2.disable = 0;			//to animists_stairs
			
				pchar.quest.bernard_music.win_condition.l1 = "locator";
				pchar.quest.bernard_music.win_condition.l1.location = "Redmond_church";
				pchar.quest.bernard_music.win_condition.l1.locator_group = "goto";
				pchar.quest.bernard_music.win_condition.l1.locator = "goto13";
				pchar.quest.bernard_music.win_condition = "bernard_music";

				Pchar.quest.remove_bsw.win_condition.l1 = "ExitFromLocation";
				Pchar.quest.remove_bsw.win_condition.l1.location = "church_wine_cellar";
				Pchar.quest.remove_bsw.win_condition = "remove_bsw";

				//RESTARTS WAY IN
				bDisableFastReload = 1;
				Pchar.quest.disable_rebirth = true;
				Pchar.quest.wr_terrace = "second_time";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				Pchar.quest.Teach_head = "14";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "15":
				//PIRATE CHURCH: BEFORE COINS
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(8, 0);
				SetNextWeather("Morning");
			
				Pchar.quest.Rdm_officiant = "Claire";
				//............................................
			
				Pchar.quest.wet_gp = "yes";

				Locations[FindLocation("wr_corv_capsm")].reload.l1.disable = 0;
				Locations[FindLocation("wr_corv_capsm")].models.always.l2 = "stopboom_R";

				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";
				Locations[FindLocation("wr_chapel")].reload.l2.disable = 0;			//to animists_stairs
				locations[FindLocation("wr_church_inside")].type = "Vane_church";			//not tavern if no pirates
				Locations[FindLocation("wr_church_inside")].reload.l8.disable = 0;		//to chapel_stairs

				Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
				Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
				Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
				Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
				Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
				locations[FindLocation("shipyard_stairs")].reload.l1.disable = 0;//back to shya
		
				ChangeCharacterAddressGroup(CharacterFromID("fake_Silehard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Laurence_Wellman"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Sarah_Fitter"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "none", "", "");

				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("Father Bernard"), "Redmond_church", "goto", "goto11");
				LAi_SetPriestType(CharacterFromID("Father Bernard"));
				LAi_group_MoveCharacter(CharacterFromID("Father Bernard"), "ENGLAND_CITIZENS");

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("fall_to_hold", 0.1);
				LAi_QuestDelay("cavern_chest_stop", 0.1);//started also during first visit to cavern (fall from mine)
				LAi_QuestDelay("ready_for_last_Vane1", 0.1);

				//RESTARTS WAY IN
				bDisableFastReload = 1;
				Pchar.quest.disable_rebirth = true;
				Pchar.quest.wr_terrace = "second_time";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				Pchar.quest.Teach_head = "15";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;
		
			case "16":
				//CAVE SHORE: BEFORE WOOD TOWER
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(12.00, 0);
				SetNextWeather("Heavy Storm");
				Pchar.quest.JRH_rain = "Heavy Storm";
			
				Pchar.quest.Rdm_officiant = "Claire";
				//............................................
			
				Pchar.quest.cavern_chestkey = "yes";
				Pchar.quest.wet_gp = "yes";

				Locations[FindLocation("wr_corv_capsm")].reload.l1.disable = 0;
				Locations[FindLocation("wr_corv_capsm")].models.always.l2 = "stopboom_R";

				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";
				Locations[FindLocation("wr_chapel")].reload.l2.disable = 0;			//to animists_stairs
				locations[FindLocation("wr_church_inside")].type = "Vane_church";			//not tavern if no pirates
				Locations[FindLocation("wr_church_inside")].reload.l8.disable = 0;		//to chapel_stairs
		
				Locations[FindLocation("wr_cave_shore")].models.always.locators = "shore04_l_JRH1";	//with fallen tree
			
				Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
				Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
				Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
				Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
				Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
				locations[FindLocation("shipyard_stairs")].reload.l1.disable = 0;//back to shya

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
				SetCharacterShipLocation(characterFromID("pir_cap23"), "wr_cave_shore");		//ladder

				SetCharacterShipLocation(characterFromID("pir_cap24"), "wr_cave_shore");	
				SetCharacterShipLocation(characterFromID("pir_cap25"), "wr_cave_shore");	
				SetCharacterShipLocation(characterFromID("pir_cap29"), "wr_cave_shore");
			
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
				SetCharacterShipLocation(characterFromID("CoastBrother33"), "Redmond_shore_03");//tartane2
				SetCharacterShipLocation(characterFromID("CoastBrother25"), "wr_port");		//prize ship galleon
				SetCharacterShipLocation(characterFromID("CoastBrother26"), "wr_port");		//prize ship corvette
				SetCharacterShipLocation(characterFromID("CoastBrother27"), "wr_port");		//boat2
			
				ChangeCharacterAddressGroup(CharacterFromID("fake_Silehard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Laurence_Wellman"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Sarah_Fitter"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "none", "", "");

				ChangeCharacterAddressGroup(CharacterFromID("pir_cap13"), "none", "", "");//in water

				RemoveCharacterEquip(CharacterFromID("pir_cap8"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap8"), "blade4" );
				GiveItem2Character(CharacterFromID("pir_cap8"), "bladereliquary");
				EquipCharacterbyItem(CharacterFromID("pir_cap8"), "bladereliquary");

				RemoveCharacterEquip(CharacterFromID("pir_cap16"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap16"), "blade24" );
				GiveItem2Character(CharacterFromID("pir_cap16"), "bladecenser");
				EquipCharacterbyItem(CharacterFromID("pir_cap16"), "bladecenser");

				RemoveCharacterEquip(CharacterFromID("pir_cap18"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap18"), "blade16" );
				GiveItem2Character(CharacterFromID("pir_cap18"), "bladecandelabre");
				EquipCharacterbyItem(CharacterFromID("pir_cap18"), "bladecandelabre");

				RemoveCharacterEquip(CharacterFromID("pir_cap23"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap23"), "blade11" );
				GiveItem2Character(CharacterFromID("pir_cap23"), "bladechalice");
				EquipCharacterbyItem(CharacterFromID("pir_cap23"), "bladechalice");

				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("Father Bernard"), "Redmond_church", "goto", "goto11");
				LAi_SetPriestType(CharacterFromID("Father Bernard"));
				LAi_group_MoveCharacter(CharacterFromID("Father Bernard"), "ENGLAND_CITIZENS");
		
				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("fall_to_hold", 0.1);
				LAi_QuestDelay("cavern_chest_stop", 0.1);	//already here?, but this loop is already running!
				LAi_QuestDelay("wood_tower", 0.1);

				//RESTARTS WAY IN
				bDisableFastReload = 1;
				Pchar.quest.disable_rebirth = true;
				Pchar.quest.wr_terrace = "second_time";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				Pchar.quest.Teach_head = "16";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;
		
			case "17":
				//BLUE CAVERN: REVENGE
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(11, 0);
				SetNextWeather("Clear");
			
				Pchar.quest.Rdm_officiant = "Claire";
				//............................................
			
				Pchar.quest.cavern_chestkey = "yes";

				Locations[FindLocation("wr_corv_capsm")].reload.l1.disable = 0;
				Locations[FindLocation("wr_corv_capsm")].models.always.l2 = "stopboom_R";
				Locations[FindLocation("wr_gall_hold_first")].locators_radius.reload.reload1 = 1.0;
				Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box7 = 0.0001;
				Locations[FindLocation("wr_gall_hold_second")].locators_radius.reload.reload2 = 1.0;
				Locations[FindLocation("wr_gall_hold_second")].locators_radius.box.box1 = 0.0001;

				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";
				locations[FindLocation("wr_church_inside")].type = "Vane_church";			//not tavern if no pirates
			
				Locations[FindLocation("wr_cave_shore")].models.always.locators = "shore04_l_JRH4F";
				Locations[FindLocation("wr_cavern")].models.always.locators = "cavern_l_JRH_air_closed";
				locations[FindLocation("wr_cavern")].reload.l1.disable = 0;			//church_outside	
				locations[FindLocation("wr_cavern")].reload.l2.disable = 0;			//cave_shore
	
				Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
				Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
				Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
				Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
				Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
				locations[FindLocation("shipyard_stairs")].reload.l1.disable = 0;//back to shya

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
				SetCharacterShipLocation(characterFromID("pir_cap23"), "wr_cave_shore");		//ladder

				SetCharacterShipLocation(characterFromID("pir_cap24"), "wr_cave_shore");	
				SetCharacterShipLocation(characterFromID("pir_cap25"), "wr_cave_shore");	
				SetCharacterShipLocation(characterFromID("pir_cap29"), "wr_cave_shore");
			
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
				SetCharacterShipLocation(characterFromID("CoastBrother33"), "Redmond_shore_03");//tartane2
				SetCharacterShipLocation(characterFromID("CoastBrother25"), "wr_port");		//prize ship galleon
				SetCharacterShipLocation(characterFromID("CoastBrother26"), "wr_port");		//prize ship corvette
				SetCharacterShipLocation(characterFromID("CoastBrother27"), "wr_port");		//boat2
		
				ChangeCharacterAddressGroup(CharacterFromID("fake_Silehard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Laurence_Wellman"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Sarah_Fitter"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "none", "", "");

				ChangeCharacterAddressGroup(CharacterFromID("pir_cap13"), "none", "", "");//in water
		
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap6"), "wr_cave_shore", "goto", "boat1");//testing locators
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap10"), "wr_cave_shore", "goto", "boat2");//testing locators
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap11"), "wr_cave_shore", "goto", "boat3D");//testing locators
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap17"), "wr_cave_shore", "goto", "boat4D");//testing locators
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap21"), "wr_cave_shore", "goto", "boat5D");//testing locators
				ChangeCharacterAddressGroup(CharacterFromID("pir_cap24"), "wr_cave_shore", "goto", "boat6D");//testing locators

				LAi_SetCitizenType(CharacterFromID("pir_cap6"));
				LAi_SetCitizenType(CharacterFromID("pir_cap10"));
				LAi_SetCitizenType(CharacterFromID("pir_cap11"));
				LAi_SetCitizenType(CharacterFromID("pir_cap17"));
				LAi_SetCitizenType(CharacterFromID("pir_cap21"));
				LAi_SetCitizenType(CharacterFromID("pir_cap24"));
		
				RemoveCharacterEquip(CharacterFromID("pir_cap8"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap8"), "blade4" );
				GiveItem2Character(CharacterFromID("pir_cap8"), "bladereliquary");
				EquipCharacterbyItem(CharacterFromID("pir_cap8"), "bladereliquary");

				RemoveCharacterEquip(CharacterFromID("pir_cap16"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap16"), "blade24" );
				GiveItem2Character(CharacterFromID("pir_cap16"), "bladecenser");
				EquipCharacterbyItem(CharacterFromID("pir_cap16"), "bladecenser");

				RemoveCharacterEquip(CharacterFromID("pir_cap18"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap18"), "blade16" );
				GiveItem2Character(CharacterFromID("pir_cap18"), "bladecandelabre");
				EquipCharacterbyItem(CharacterFromID("pir_cap18"), "bladecandelabre");

				RemoveCharacterEquip(CharacterFromID("pir_cap23"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap23"), "blade11" );
				GiveItem2Character(CharacterFromID("pir_cap23"), "bladechalice");
				EquipCharacterbyItem(CharacterFromID("pir_cap23"), "bladechalice");

				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("Father Bernard"), "Redmond_church", "goto", "goto11");
				LAi_SetPriestType(CharacterFromID("Father Bernard"));
				LAi_group_MoveCharacter(CharacterFromID("Father Bernard"), "ENGLAND_CITIZENS");
			
				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

				LAi_QuestDelay("subject_sound_architecture", 0.1);
				LAi_QuestDelay("fall_to_hold", 0.1);
				LAi_QuestDelay("cavern_chest_stop", 0.1);	
				LAi_QuestDelay("Vane_ladder", 0.1);

				//RESTARTS WAY IN
				bDisableFastReload = 1;
				Pchar.quest.disable_rebirth = true;
				Pchar.quest.wr_terrace = "second_time";
				Pchar.quest.mine_enabled = "yes";
				Pchar.quest.Friday_room = "open";

				pchar.quest.tunnel1back_loop1.win_condition.l1 = "locator";
				pchar.quest.tunnel1back_loop1.win_condition.l1.location = "wr_dungeon3_right";
				pchar.quest.tunnel1back_loop1.win_condition.l1.locator_group = "reload";
				pchar.quest.tunnel1back_loop1.win_condition.l1.locator = "reload7";
				pchar.quest.tunnel1back_loop1.win_condition = "tunnel1back_loop1";

				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				Pchar.quest.Teach_head = "17";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "18":
				//CORVETTE YELLOW DECK: REVENGE
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(23.00, 0);				
				SetNextWeather("Clear");
				
				Pchar.quest.Rdm_officiant = "Claire";
				//............................................
			
				Pchar.quest.cavern_chestkey = "yes";
		
				Locations[FindLocation("wr_corv_capsm")].reload.l1.disable = 0;
				Locations[FindLocation("wr_corv_capsm")].models.always.l2 = "stopboom_R";
				Locations[FindLocation("wr_gall_hold_first")].locators_radius.reload.reload1 = 1.0;
				Locations[FindLocation("wr_gall_hold_first")].locators_radius.box.box7 = 0.0001;
				Locations[FindLocation("wr_gall_hold_second")].locators_radius.reload.reload2 = 1.0;
				Locations[FindLocation("wr_gall_hold_second")].locators_radius.box.box1 = 0.0001;

				locations[FindLocation("Loanshark_cellar")].id.label = "Loanshark cellar";
				locations[FindLocation("wr_church_inside")].type = "Vane_church";			//not tavern if no pirates
			
				Locations[FindLocation("wr_cave_shore")].models.always.locators = "shore04_l_JRH4F";
				Locations[FindLocation("wr_cavern")].models.always.locators = "cavern_l_JRH_air_closed";
				locations[FindLocation("wr_cavern")].reload.l1.disable = 0;			//church_outside	
				locations[FindLocation("wr_cavern")].reload.l2.disable = 0;			//cave_shore
	
				Locations[FindLocation("wr_library")].reload.l6.name = "reload6";	
				Locations[FindLocation("wr_library")].reload.l6.go = "Redmond_UsurerHouse";
				Locations[FindLocation("wr_library")].reload.l6.emerge = "reload5";
				Locations[FindLocation("wr_library")].reload.l6.autoreload = "0";
				Locations[FindLocation("wr_library")].reload.l6.label = "Loanshark's Office.";

				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.name = "reload5";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.go = "wr_library";			
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.emerge = "reload6";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.autoreload = "0";
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
				locations[FindLocation("shipyard_stairs")].reload.l1.disable = 0;//back to shya

				Locations[FindLocation("wr_church_attic")].type = "Vane_jungle";

				Locations[FindLocation("wr_gall_hold_second")].locators_radius.reload.reload2 = 1.0;		
				Locations[FindLocation("wr_gall_hold_second")].locators_radius.box.box1 = 0.0001;	

				Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.reload.reload4 = 1.0;		
				Locations[FindLocation("wr_gall_deck2_stern")].locators_radius.box.box12 = 0.0001;

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
				SetCharacterShipLocation(characterFromID("pir_cap23"), "wr_cave_shore");		//ladder

				SetCharacterShipLocation(characterFromID("pir_cap24"), "wr_cave_shore");	
				SetCharacterShipLocation(characterFromID("pir_cap25"), "wr_cave_shore");	
				SetCharacterShipLocation(characterFromID("pir_cap29"), "wr_cave_shore");
			
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
				SetCharacterShipLocation(characterFromID("CoastBrother33"), "Redmond_shore_03");//tartane2
				SetCharacterShipLocation(characterFromID("CoastBrother25"), "wr_port");		//prize ship galleon
				SetCharacterShipLocation(characterFromID("CoastBrother26"), "wr_port");		//prize ship corvette
				SetCharacterShipLocation(characterFromID("CoastBrother27"), "wr_port");		//boat2
				SetCharacterShipLocation(characterFromID("wr_aub"), "wr_ships");		//boat2
		
				ChangeCharacterAddressGroup(CharacterFromID("fake_Silehard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Laurence_Wellman"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_Sarah_Fitter"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("wr_bri"), "none", "", "");

				SetModel(characterFromID("pir_cap1"), "pir_cap1_redC_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap8"), "pir_cap8_red_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap16"), "pir_cap16_red_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap18"), "pir_cap18_red_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap23"), "pir_cap23_red_M", "man", "man", 1.8, false);

				SetModel(characterFromID("pir_cap3"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap4"), "Animists1_M_black", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap5"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap7"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap9"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap14"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap15"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap22"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap26"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap27"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap29"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap30"), "Animists1_M", "man", "man", 1.8, false);
				SetModel(characterFromID("pir_cap31"), "Animists1_M", "man", "man", 1.8, false);
		
				SetModel(characterFromID("Selkirk"), "rabwhite1Priest", "man", "man", 1.8, false);
				SetModel(characterFromID("Friday"), "Animists1_black", "man", "man", 1.8, false);

				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRH1";

				RemoveCharacterEquip(CharacterFromID("pir_cap8"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap8"), "blade4" );
				GiveItem2Character(CharacterFromID("pir_cap8"), "bladereliquary");
				EquipCharacterbyItem(CharacterFromID("pir_cap8"), "bladereliquary");

				RemoveCharacterEquip(CharacterFromID("pir_cap16"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap16"), "blade24" );
				GiveItem2Character(CharacterFromID("pir_cap16"), "bladecenser");
				EquipCharacterbyItem(CharacterFromID("pir_cap16"), "bladecenser");

				RemoveCharacterEquip(CharacterFromID("pir_cap18"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap18"), "blade16" );
				GiveItem2Character(CharacterFromID("pir_cap18"), "bladecandelabre");
				EquipCharacterbyItem(CharacterFromID("pir_cap18"), "bladecandelabre");

				RemoveCharacterEquip(CharacterFromID("pir_cap23"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("pir_cap23"), "blade11" );
				GiveItem2Character(CharacterFromID("pir_cap23"), "bladechalice");
				EquipCharacterbyItem(CharacterFromID("pir_cap23"), "bladechalice");

				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("Father Bernard"), "Redmond_church", "goto", "goto11");
				LAi_SetPriestType(CharacterFromID("Father Bernard"));
				LAi_group_MoveCharacter(CharacterFromID("Father Bernard"), "ENGLAND_CITIZENS");

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

				//RESTARTS WAY IN
				bDisableFastReload = 1;
				Pchar.quest.disable_rebirth = true;
				Pchar.quest.wr_terrace = "second_time";
				Pchar.quest.crew_to_ships = "closed";
				Pchar.quest.cap_inner_gp_box = "locked";

				Pchar.quest.Teach_head = "18";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;
			
			case "20":
				//LIBRARY: STUDY TO SECRET
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(7, 0);
				SetNextWeather("Morning");
			
				ChangeCharacterAddressGroup(characterFromID("Woodes Rogers"), "wr_study", "goto", "wr_dead");
				LAi_SetActorType(CharacterFromID("Woodes Rogers"));
				LAi_ActorSetLayMode(CharacterFromID("Woodes Rogers"));
				RemoveCharacterEquip(CharacterFromID("Woodes Rogers"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("Woodes Rogers"), "bladeA5");
				Locations[FindLocation("wr_study")].locators_radius.box.box16 = 1.0;
				Locations[FindLocation("wr_study")].locators_radius.randitem.randitem2 = 0.001;				

				TakeNItems(CharacterFromID("Woodes Rogers"), "compass1", 1);
				TakeNItems(CharacterFromID("Woodes Rogers"), "sewing_kit", 1);
				TakeNItems(CharacterFromID("Woodes Rogers"), "tobacco", 1);
				TakeNItems(CharacterFromID("Woodes Rogers"), "key17", 1);

				Pchar.quest.Rdm_officiant = "Claire";
				Pchar.quest.study_lever1 = "missing";
				Pchar.quest.study_lever2 = "missing";
				Pchar.quest.study_lever3 = "missing";
				Pchar.quest.study_lever4 = "missing";

				Locations[FindLocation("wr_study")].locators_radius.box.box1 = 0.0001;
				Locations[FindLocation("wr_study")].locators_radius.box.box2 = 0.0001;
				Locations[FindLocation("wr_study")].locators_radius.box.box3 = 0.0001;
				Locations[FindLocation("wr_study")].locators_radius.box.box4 = 0.0001;
				Locations[FindLocation("wr_study")].locators_radius.box.box5 = 0.0001;
				Locations[FindLocation("wr_study")].locators_radius.box.box6 = 0.0001;

				Locations[FindLocation("wr_study")].locators_radius.box.box8 = 0.5;
				Locations[FindLocation("wr_study")].locators_radius.box.box9 = 0.5;
				Locations[FindLocation("wr_study")].locators_radius.box.box10 = 0.5;
				Locations[FindLocation("wr_study")].locators_radius.box.box11 = 0.5;
				Locations[FindLocation("wr_study")].locators_radius.goto.wr_dead = 2.0;

				Pchar.quest.distillery_items = "something_else";
				Pchar.quest.Minerva_copper = "no";
				Pchar.quest.Minerva_silver = "no";
				Pchar.quest.Minerva_gold = "no";
				Pchar.quest.wr_library = "medicine";
				Pchar.quest.medicine_quest = "started";

				Locations[FindLocation("wr_library")].models.always.locators = "Res02_l_JRH12";
				Locations[FindLocation("wr_library")].locators_radius.reload.reload2 = 0.5;
				Locations[FindLocation("wr_library")].reload.l1.disable = 1;
				Locations[FindLocation("wr_library")].reload.l2.disable = 1;
				Locations[FindLocation("wr_library")].reload.l3.disable = 1;
				Locations[FindLocation("wr_library")].reload.l4.disable = 1;
				Locations[FindLocation("wr_library")].reload.l5.disable = 0;
				Locations[FindLocation("wr_library")].reload.l6.disable = 1;
				Locations[FindLocation("wr_library")].reload.l7.disable = 1;
				LAi_LocationFightDisable(&Locations[FindLocation("wr_library")], false);

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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogersґ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.disable = 0;

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
				locations[FindLocation("shipyard_stairs")].reload.l1.disable = 0;//back to shya
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";

				Locations[FindLocation("wr_church_attic")].type = "Vane_jungle";

				SetCharacterShipLocation(characterFromID("CoastBrother29"), "Redmond_shore_ship");//PrisonShip
				SetCharacterShipLocation(characterFromID("CoastBrother30"), "Redmond_shore_ship");//PrisonShip
				SetCharacterShipLocation(characterFromID("CoastBrother32"), "Redmond_shore_ship");//tartane2
				SetCharacterShipLocation(characterFromID("CoastBrother33"), "Redmond_shore_03");//tartane2

				ChangeCharacterAddressGroup(characterFromID("wr_boc4"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("wr_cor1_1"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("wr_voy"), "none", "", "");
	
				LAi_SetStayType(CharacterFromID("guncrew_1"));
				LAi_SetStayType(CharacterFromID("guncrew_2"));
				LAi_SetStayType(CharacterFromID("guncrew_3"));
				LAi_SetStayType(CharacterFromID("guncrew_4"));
				LAi_SetOfficerType(CharacterFromID("Minerva"));
				LAi_SetStayType(CharacterFromID("Wench3"));
		
				Pchar.quest.guncrew = "";
				Characters[GetCharacterIndex("guncrew_1")].quest.meeting = "8";
				Characters[GetCharacterIndex("guncrew_2")].quest.meeting = "8";
				Characters[GetCharacterIndex("guncrew_3")].quest.meeting = "8";
				Characters[GetCharacterIndex("guncrew_4")].quest.meeting = "8";
			
				ChangeCharacterAddressGroup(characterFromID("guncrew_4"), "wr_library", "goto", "goto4");
				ChangeCharacterAddressGroup(characterFromID("guncrew_2"), "wr_library", "goto", "goto5");
				ChangeCharacterAddressGroup(characterFromID("guncrew_3"), "wr_library", "goto", "goto20");
				ChangeCharacterAddressGroup(characterFromID("guncrew_1"), "wr_library", "reload", "reload1");

				ChangeCharacterAddressGroup(characterFromID("Minerva"), "wr_library", "reload", "reload6");
				ChangeCharacterAddressGroup(characterFromID("Wench3"), "wr_study", "goto", "caroline");
		

				RemoveCharacterEquip(characterFromID("guncrew_1"), BLADE_ITEM_TYPE );
				GiveItem2Character(characterFromID("guncrew_1"), "bladeX4");
				EquipCharacterbyItem(characterFromID("guncrew_1"), "bladeX4");
				RemoveCharacterEquip(characterFromID("guncrew_1"), GUN_ITEM_TYPE );
				GiveItem2Character(characterFromID("guncrew_1"), "pistolmket");
				EquipCharacterbyItem(characterFromID("guncrew_1"), "pistolmket");

				RemoveCharacterEquip(characterFromID("guncrew_2"), GUN_ITEM_TYPE );
				GiveItem2Character(characterFromID("guncrew_2"), "pistolmket");
				EquipCharacterbyItem(characterFromID("guncrew_2"), "pistolmket");

				RemoveCharacterEquip(characterFromID("guncrew_3"), GUN_ITEM_TYPE );
				GiveItem2Character(characterFromID("guncrew_3"), "pistolmket");
				EquipCharacterbyItem(characterFromID("guncrew_3"), "pistolmket");

				RemoveCharacterEquip(characterFromID("guncrew_4"), GUN_ITEM_TYPE );
				GiveItem2Character(characterFromID("guncrew_4"), "pistolmket");
				EquipCharacterbyItem(characterFromID("guncrew_4"), "pistolmket");

				locations[FindLocation("Tavern_storeroom")].id.label = "Tavern storeroom";
				locations[FindLocation("wr_study")].id.label = "Woodes Rogers' study";
				locations[FindLocation("wr_gunroom")].id.label = "Gunroom";
				locations[FindLocation("storeroom_attic")].id.label = "Storeroom attic";

				ChangeCharacterAddressGroup(CharacterFromID("fake_father_Bernard"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("Father Bernard"), "Redmond_church", "goto", "goto11");
				LAi_SetPriestType(CharacterFromID("Father Bernard"));
				LAi_group_MoveCharacter(CharacterFromID("Father Bernard"), "ENGLAND_CITIZENS");

				ChangeCharacterAddressGroup(CharacterFromID("wr_fwn"), "none", "", "");
				ChangeCharacterAddressGroup(CharacterFromID("wr_sol6f77"), "none", "", "");

				locations[FindLocation("Redmond_Town_01")].type = "blues_town";
				locations[FindLocation("Redmond_Town_03")].type = "blues_town";
				locations[FindLocation("Redmond_Town_04")].type = "blues_town";
				locations[FindLocation("Redmond_Port")].type = "blues_port";
				locations[FindLocation("Redmond_UsurerHouse")].type = "Rogers_neutral";

				LAi_QuestDelay("study_puzzle2", 0.1);

				//RESTARTS WAY IN
				bDisableFastReload = 1;
				Pchar.quest.disable_rebirth = true;
				Pchar.quest.wr_terrace = "second_time";

				//starts all step-backs in shipyard_shore, wr_port m fl
				pchar.quest.3mainchar_gone.win_condition.l1 = "location";
				pchar.quest.3mainchar_gone.win_condition.l1.location = "Shipyard_shore";
				pchar.quest.3mainchar_gone.win_condition = "3mainchar_gone";
			
				pchar.quest.terrace_in1.win_condition.l1 = "locator";
				pchar.quest.terrace_in1.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.terrace_in1.win_condition.l1.locator_group = "goto";
				pchar.quest.terrace_in1.win_condition.l1.locator = "terr_in1";	
				pchar.quest.terrace_in1.win_condition = "terrace_in1";

				Pchar.quest.Teach_head = "20";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;
//===================================================================================================================
//part 2
			case "21":
				//PORT ROYAL: START PART 2

				Pchar.quest.disable_rebirth = true;

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

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
			
				pchar.quest.Shipyard_shore_ambush.win_condition.l1 = "location";
				pchar.quest.Shipyard_shore_ambush.win_condition.l1.location = "Redmond_town_04";
				pchar.quest.Shipyard_shore_ambush.win_condition = "to_the_farm";

		//----------------------------------------------------------------------------------------
			pchar.quest.shyashore_backloop7_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop7_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop7_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop7_A.win_condition.l1.locator = "reload7";
			pchar.quest.shyashore_backloop7_A.win_condition = "shyashore_backloop7_A";

			pchar.quest.shyashore_backloop8_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop8_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop8_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop8_A.win_condition.l1.locator = "reload8";
			pchar.quest.shyashore_backloop8_A.win_condition = "shyashore_backloop8_A";
		//----------------------------------------------------------------------------------------
			pchar.quest.shyashore_backloop15_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop15_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop15_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop15_A.win_condition.l1.locator = "reload15";
			pchar.quest.shyashore_backloop15_A.win_condition = "shyashore_backloop15_A";

			pchar.quest.shyashore_backloop12_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop12_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop12_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop12_A.win_condition.l1.locator = "reload12";
			pchar.quest.shyashore_backloop12_A.win_condition = "shyashore_backloop12_A";

			pchar.quest.shyashore_backloop16_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop16_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop16_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop16_A.win_condition.l1.locator = "reload16";
			pchar.quest.shyashore_backloop16_A.win_condition = "shyashore_backloop16_A";

			pchar.quest.shyashore_backloop14_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop14_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop14_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop14_A.win_condition.l1.locator = "reload14";
			pchar.quest.shyashore_backloop14_A.win_condition = "shyashore_backloop14_A";

			pchar.quest.shyashore_backloop17_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop17_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop17_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop17_A.win_condition.l1.locator = "reload17";
			pchar.quest.shyashore_backloop17_A.win_condition = "shyashore_backloop17_A";

			pchar.quest.shyashore_backloop28_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop28_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop28_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop28_A.win_condition.l1.locator = "reload28";
			pchar.quest.shyashore_backloop28_A.win_condition = "shyashore_backloop28_A";
		//----------------------------------------------------------------------------------------
			pchar.quest.shyashore_backloop22_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop22_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop22_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop22_A.win_condition.l1.locator = "reload22";
			pchar.quest.shyashore_backloop22_A.win_condition = "shyashore_backloop22_A";

			pchar.quest.shyashore_backloop23_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop23_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop23_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop23_A.win_condition.l1.locator = "reload23";
			pchar.quest.shyashore_backloop23_A.win_condition = "shyashore_backloop23_A";

			pchar.quest.shyashore_backloop24_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop24_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop24_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop24_A.win_condition.l1.locator = "reload24";
			pchar.quest.shyashore_backloop24_A.win_condition = "shyashore_backloop24_A";

			pchar.quest.shyashore_backloop25_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop25_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop25_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop25_A.win_condition.l1.locator = "reload25";
			pchar.quest.shyashore_backloop25_A.win_condition = "shyashore_backloop25_A";
		//----------------------------------------------------------------------------------------
			pchar.quest.shyashore_backloop26_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop26_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop26_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop26_A.win_condition.l1.locator = "reload26";
			pchar.quest.shyashore_backloop26_A.win_condition = "shyashore_backloop26_A";

			pchar.quest.shyashore_backloop27_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop27_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop27_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop27_A.win_condition.l1.locator = "reload27";
			pchar.quest.shyashore_backloop27_A.win_condition = "shyashore_backloop27_A";

			pchar.quest.shyashore_backloop21_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop21_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop21_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop21_A.win_condition.l1.locator = "reload21";
			pchar.quest.shyashore_backloop21_A.win_condition = "shyashore_backloop21_A";
		//----------------------------------------------------------------------------------------
			pchar.quest.shyashore_backloop18_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop18_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop18_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop18_A.win_condition.l1.locator = "reload18";
			pchar.quest.shyashore_backloop18_A.win_condition = "shyashore_backloop18_A";

			pchar.quest.shyashore_backloop10_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop10_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop10_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop10_A.win_condition.l1.locator = "reload10";
			pchar.quest.shyashore_backloop10_A.win_condition = "shyashore_backloop10_A";

			pchar.quest.shyashore_backloop11_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop11_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop11_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop11_A.win_condition.l1.locator = "reload11";
			pchar.quest.shyashore_backloop11_A.win_condition = "shyashore_backloop11_A";

			pchar.quest.shyashore_backloop19_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop19_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop19_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop19_A.win_condition.l1.locator = "reload19";
			pchar.quest.shyashore_backloop19_A.win_condition = "shyashore_backloop19_A";

			pchar.quest.shyashore_backloop20_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop20_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop20_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop20_A.win_condition.l1.locator = "reload20";
			pchar.quest.shyashore_backloop20_A.win_condition = "shyashore_backloop20_A";

			pchar.quest.shyashore_backloop6_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop6_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop6_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop6_A.win_condition.l1.locator = "reload6";
			pchar.quest.shyashore_backloop6_A.win_condition = "shyashore_backloop6_A";
		
			pchar.quest.shyashore_backloop13_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop13_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop13_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop13_A.win_condition.l1.locator = "reload13";
			pchar.quest.shyashore_backloop13_A.win_condition = "shyashore_backloop13_A";

			pchar.quest.shyashore_backloop9_A.win_condition.l1 = "locator";
			pchar.quest.shyashore_backloop9_A.win_condition.l1.location = "shipyard_shore";
			pchar.quest.shyashore_backloop9_A.win_condition.l1.locator_group = "reload";
			pchar.quest.shyashore_backloop9_A.win_condition.l1.locator = "reload9";
			pchar.quest.shyashore_backloop9_A.win_condition = "shyashore_backloop9_A";
		//----------------------------------------------------------------------------------------
				pchar.quest.shoreship_backloop6_A.win_condition.l1 = "locator";
				pchar.quest.shoreship_backloop6_A.win_condition.l1.location = "Redmond_shore_ship";
				pchar.quest.shoreship_backloop6_A.win_condition.l1.locator_group = "reload";
				pchar.quest.shoreship_backloop6_A.win_condition.l1.locator = "reload6";
				pchar.quest.shoreship_backloop6_A.win_condition = "shoreship_backloop6_A";

				Pchar.quest.Teach_head = "21";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "22":
				//FARM: AFTER ALCHEMY 1

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "wr_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//additional "22" conditions		

				Locations[FindLocation("Tutorial_Deck")].WeaponsLocker.items.blade10 = 1;
				Locations[FindLocation("Tutorial_Deck")].WeaponsLocker.items.PiratesPistol = 1;

				Locations[FindLocation("Tutorial_Deck")].box1.items.shirt_shoes = 1;
				Locations[FindLocation("Tutorial_Deck")].box1.items.spyglass3 = 1;
				Locations[FindLocation("Tutorial_Deck")].box1.items.compass2 = 1;
				Locations[FindLocation("Tutorial_Deck")].box1.items.map = 1;
				Locations[FindLocation("Tutorial_Deck")].box1.items.medical2 = 1;
				Locations[FindLocation("Tutorial_Deck")].box1.items.potionrum = 2;
				Locations[FindLocation("Tutorial_Deck")].box1.money = 2000;

				Locations[FindLocation("Tutorial_Deck")].box2.items.ammopouch = 1;
				Locations[FindLocation("Tutorial_Deck")].box2.items.powderflask = 1;
				Locations[FindLocation("Tutorial_Deck")].box2.items.gunpowder = 12;
				Locations[FindLocation("Tutorial_Deck")].box2.items.pistolbullets = 12;

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
				
				LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);		//starts Vane info

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao conditions
		/*		
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
				Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
				LAi_SetPoorType(CharacterFromID("Hands"));
				ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");
		*/
				LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//done in here instead

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				Pchar.estate_direction = "Cayman_town";

				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade conditions

				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "22";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "23":
				//CAVE SHORE: AFTER VANE

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "wr_cave_shore");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart", 0.1);		//Vane info done

			//------------------------------------------------------------------------------------------------------------------
			//Surgeons Tortuga conditions

				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao conditions
			/*	
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
				Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
				LAi_SetPoorType(CharacterFromID("Hands"));
				ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");
			*/
				LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//done in here instead

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				Pchar.estate_direction = "Cayman_town";

				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade conditions

				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "23";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "24":
				//CURACAO: AFTER HANDS

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Willemstad_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Hands"));

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);		//starts Vane info

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao + Maltains conditions
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//	LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//not after Hands
				LAi_QuestDelay("start_Maltains", 1.0);
			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				Pchar.estate_direction = "Cayman_town";

				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade conditions

				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "24";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "25":
				//LA GRENADE: AFTER ODEL

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Conceicao_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			
			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);		//starts Vane info

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao conditions
			/*	
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
				Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
				LAi_SetPoorType(CharacterFromID("Hands"));
				ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");
			*/
				LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//done in here instead

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				Pchar.estate_direction = "Cayman_town";

				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade + Citadel conditions
			
				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");
				Characters[GetCharacterIndex("Odel")].dialog.CurrentNode  = "neutral";

				LAi_QuestDelay("Citadel_rock_start", 0.1);

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "25";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "26":
				//TORTUGA: AFTER SURGEONS

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Tortuga_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart", 0.1);		//Vane info done

			//------------------------------------------------------------------------------------------------------------------
			//Surgeons Tortuga + Cartagena conditions

				SetServedNation(FRANCE);
				HoistFlag(FRANCE);
			
				Pchar.qbook.richards4 = "done";
				Pchar.qbook.richards5 = "done";
				Pchar.qbook.richards6 = "done";
				Pchar.qbook.richards7 = "done";
				Pchar.qbook.richards8 = "done";
				Pchar.qbook.richards9 = "done";
				Pchar.qbook.richards10 = "done";
				Pchar.qbook.richards11 = "done";
				Pchar.qbook.richards12 = "done";

				Pchar.Tgunsmith = "yes";
				Pchar.Tsailmaker = "yes";
				Pchar.Tassistent = "yes";
				Pchar.Tgovernor = "yes";
				Pchar.Ttower = "yes";
				Pchar.Cook_dead = "yes";

				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);

				ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "none", "", "");
				Locations[FindLocation("Tortuga_townhall")].reload.l3.disable = 0;
				locations[FindLocation("Tortuga_tower_passage")].id.label = "Tower passage";
	
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ4 = 1.5;	
				Locations[FindLocation("Tortuga_port")].locators_radius.box.box8 = 1.0;
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ1 = 0.9;	
			Locations[FindLocation("Tortuga_gunsmith_kitchen")].locators_radius.box.box1 = 0.001;


				Locations[FindLocation("cloister_exit")].locators_radius.box.box1 = 2.0;	//opens WoodesRogers part
				Pchar.monastary = "Sister_Richards";

				Pchar.quest.tape_found.win_condition.l1 = "item";
				Pchar.quest.tape_found.win_condition.l1.character = Pchar.id;
				Pchar.quest.tape_found.win_condition.l1.item = "tape";
				Pchar.quest.tape_found.win_condition = "tape_found";

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao conditions
			/*	
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
				Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
				LAi_SetPoorType(CharacterFromID("Hands"));
				ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");
			*/
				LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//done in here instead

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				Pchar.estate_direction = "Cayman_town";

				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade conditions

				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "26";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "27":
				//CHARLESTOWN: AFTER MALTAINS

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Charlestown_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Hands"));

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore
		
			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);		//starts Vane info

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao + Maltains + Antigua prison conditions
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//	LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//not after Hands

				AddPassenger(Pchar, characterFromID("Hands"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Hands"));
				
				//check how these should be modified
				locations[FindLocation("Charlestown_port")].reload.l17.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l17.close_for_day = 0;	//always closed from now
				locations[FindLocation("Charlestown_port")].reload.l18.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l3.close_for_night = 0;	//townhall always open in WR, enough with Maltains close_for_day

				ChangeCharacterAddressGroup(characterFromID("Thomas Modiford"), "none", "", "");	//governor gone
				ChangeCharacterAddressGroup(characterFromID("Anne_Russel"), "Charlestown_Residence", "goto", "goto6");
				Characters[GetCharacterIndex("Anne_Russel")].dialog.CurrentNode  = "neutral";
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier3"), "Charlestown_port", "quest", "quest2");
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier4"), "Charlestown_port", "quest", "quest3");

				Pchar.unlocked_cells = "9";
				Pchar.cell9 = "unlocked"; Pchar.cell7 = "unlocked"; Pchar.cell3 = "unlocked"; 
				Pchar.cell1 = "unlocked"; Pchar.cell17 = "unlocked"; Pchar.cell15 = "unlocked";
				Pchar.cell5 = "unlocked"; Pchar.cell19 = "unlocked"; Pchar.cell2 = "unlocked";

				//this enables the prison tour
				locations[FindLocation("Antigua_port")].models.always.locators = "StJohns_locators_JRH";
				//LAi_QuestDelay("prison_info_done5", 0.1);

				//this enables the prison tour, instead of "prison_info_done5"
				Locations[FindLocation("Antigua_fakefort1")].reload.l4.name = "reloadc1";
				Locations[FindLocation("Antigua_fakefort1")].reload.l4.go = "bb_prison_port";
				Locations[FindLocation("Antigua_fakefort1")].reload.l4.emerge = "reload2";
				locations[FindLocation("Antigua_port")].reload.l23.disable = 1;	//Antigua port to fort
			
				Pchar.quest.prison_pier = "phase0";
				Pchar.quest.prison_elevator = "down";
				Pchar.quest.prison_opening = "stairs";
				Pchar.quest.prison_opening2 = "prison";
				Pchar.prison2.water = "fast";
				Pchar.P2_ambush = "not_yet";
				SetLocatorRadius(locations[FindLocation("Antigua_port")], "reload", "reload7_back", 0.001);	//box6 instead first time
				Locations[FindLocation("Antigua_port")].locators_radius.reload.reload7_back = 0.001;

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

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				Pchar.estate_direction = "Cayman_town";

				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade conditions

				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "27";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "28":
				//CAYMAN ESTATE: AFTER MAZE + ROOMS

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Cayman_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);		//starts Vane info

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao conditions
			/*	
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
				Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
				LAi_SetPoorType(CharacterFromID("Hands"));
				ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");
			*/
				LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//done in here instead

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;
				Pchar.estate_direction = "Cayman_town";

			//.....................................................................
			//more here

				ChangeCharacterAddressGroup(characterFromID("Margaret_Pough"), "BB_Eden_estate", "goto", "goto6");
				LAi_SetStayType(characterFromID("Margaret_Pough"));
			
				pchar.quest.Margaret_Pough3.win_condition.l1 = "locator";
				pchar.quest.Margaret_Pough3.win_condition.l1.location = "BB_Eden_estate";
				pchar.quest.Margaret_Pough3.win_condition.l1.locator_group = "goto";
				pchar.quest.Margaret_Pough3.win_condition.l1.locator = "goto6";
				pchar.quest.Margaret_Pough3.win_condition = "Margaret_Pough3";

				Locations[FindLocation("BB_Eden_estate")].reload.l6.disable = 0;		//chapel
				Locations[FindLocation("BB_Eden_estate")].reload.l4.disable = 0;		//bedroom
				ChangeCharacterAddressGroup(characterFromID("Caesar"), "BB_Eden_estate", "goto", "servant2");
				SetModel(characterFromID("Caesar"), "black_servant2", "man", "man", 1.8, false);
				RemoveCharacterEquip(characterFromID("Caesar"), GUN_ITEM_TYPE);
				RemoveCharacterEquip(characterFromID("Caesar"), BLADE_ITEM_TYPE);
				DeleteAttribute(characterFromID("Caesar"), "items");
				LAi_SetStayType(characterFromID("Caesar"));
				characters[GetCharacterIndex("Caesar")].name = "Servant";
				GiveItem2Character(characterFromID("Caesar"), "machete");
				EquipCharacterByItem(characterFromID("Caesar"), "machete");
				
				Locations[FindLocation("BB_Eden_chapel")].models.always.l1 = "girder_free";
				Locations[FindLocation("BB_Eden_chapel")].locators_radius.box.box1 = 0.0001;
				Locations[FindLocation("BB_Eden_chapel")].locators_radius.reload.reload1 = 1.0;

				Locations[FindLocation("BB_Eden_estate")].locators_radius.reload.reload7 = 0.7;
				Locations[FindLocation("BB_Eden_estate")].locators_radius.reload.reload8 = 0.7;

				//these open to Estate
				Pchar.Cayman_box1 = "unlocked";
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				LAi_QuestDelay("maze_gate1_down_check", 0.5);
				LAi_QuestDelay("maze_gate2_down_check", 0.5);
				LAi_QuestDelay("maze_F1_check", 0.5);
				LAi_QuestDelay("maze_F2_check", 0.5);
				LAi_QuestDelay("maze_F3_check", 0.5);
				LAi_QuestDelay("maze_F4_check", 0.5);

				Pchar.servants_info = "4";
				Characters[GetCharacterIndex("Caesar")].Dialog.Filename = "Eden servants_dialog.c";
				characters[GetCharacterIndex("Caesar")].dialog.CurrentNode = "repeat_look_around";
				characters[GetCharacterIndex("black_servant1")].dialog.CurrentNode = "repeat_look_around";

				ChangeCharacterAddressGroup(characterFromID("maze_monkey1"), "BB_Eden_maze", "goto", "monkey1");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey2"), "BB_Eden_maze", "goto", "monkey2");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey3"), "BB_Eden_maze", "goto", "monkey3");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey4"), "BB_Eden_maze", "goto", "monkey4");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey5"), "BB_Eden_maze", "goto", "monkey5");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey6"), "BB_Eden_maze", "goto", "monkey6");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey7"), "BB_Eden_maze", "goto", "monkey7");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey8"), "BB_Eden_maze", "goto", "monkey8");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey6"), "BB_Eden_maze", "goto", "monkey9");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey7"), "BB_Eden_maze", "goto", "monkey10");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey8"), "BB_Eden_maze", "goto", "monkey11");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey8"), "BB_Eden_maze", "goto", "monkey12");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey8"), "BB_Eden_maze", "goto", "monkey13");
				ChangeCharacterAddressGroup(characterFromID("maze_monkey8"), "BB_Eden_maze", "goto", "monkey14");

				Locations[FindLocation("bb_Eden_garden_house")].locators_radius.box.box1 = 0.001;
				Locations[FindLocation("bb_Eden_garden_house")].locators_radius.box.box2 = 0.001;
				Locations[FindLocation("bb_Eden_garden_house")].locators_radius.box.box3 = 0.001;
				Locations[FindLocation("bb_Eden_garden_house")].locators_radius.box.box4 = 0.8;
				Locations[FindLocation("bb_Eden_garden_house")].locators_radius.box.box5 = 0.8;
				Locations[FindLocation("bb_Eden_garden_house")].locators_radius.box.box6 = 0.7;

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade conditions

				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "28";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "29":
				//ELEUTHERA: AFTER CITADEL

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Eleuthera_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);		//starts Vane info

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao conditions
			/*	
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
				Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
				LAi_SetPoorType(CharacterFromID("Hands"));
				ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");
			*/
				LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//done in here instead

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				Pchar.estate_direction = "Cayman_town";

				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade + Citadel + Turks conditions
			
				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");
				Characters[GetCharacterIndex("Odel")].dialog.CurrentNode  = "neutral";


				Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB1";
				Locations[FindLocation("Eleuthera_shore")].models.always.l1 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l2 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l3 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l5 = "leverC_up";
				Locations[FindLocation("Eleuthera_shore")].models.always.l6 = "anchor_big3";

				SetCharacterShipLocation(characterFromID("wr_mummy5"), "Eleuthera_shore");	//test for Citadel Rock
				Locations[FindLocation("Eleuthera_tavern_upstairs")].vcskip = true;	//enough with bad guys on Eleuthera_shore
				Locations[FindLocation("Eleuthera_shore")].vcskip = true;		//these are replaced with quest bad guys
				ChangeCharacterAddressGroup(characterFromID("Maynard"), "Eleuthera_shore", "quest", "quest6");
				Pchar.citadel_lever = "up";
				Locations[FindLocation("Eleuthera_shore")].locators_radius.box.box36 = 0.001;
				Locations[FindLocation("Eleuthera_shore")].locators_radius.reload.reload4 = 1.0;
				Locations[FindLocation("Citadel_cave")].locators_radius.box.box1 = 0.001;
			
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug1"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug2"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug3"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug4"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug5"), "none", "", "");

				LAi_QuestDelay("maynard_tower_done1", 0.1);


				ChangeCharacterAddressGroup(characterFromID("shipwreck_trader"), "Turks_Fort_Office", "sit", "sit1");
				Locations[FindLocation("Turks_Fort_Office")].locators_radius.sit.sit1 = 2.5;

				LAi_QuestDelay("Turks_armory", 0.1);

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "29";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "30":
				//CARTAGENA: AFTER MONASTARY

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Cartagena_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart", 0.1);		//Vane info done

			//------------------------------------------------------------------------------------------------------------------
			//Surgeons Tortuga + Cartagena conditions

				SetServedNation(FRANCE);
				HoistFlag(FRANCE);
			
				Pchar.qbook.richards4 = "done";
				Pchar.qbook.richards5 = "done";
				Pchar.qbook.richards6 = "done";
				Pchar.qbook.richards7 = "done";
				Pchar.qbook.richards8 = "done";
				Pchar.qbook.richards9 = "done";
				Pchar.qbook.richards10 = "done";
				Pchar.qbook.richards11 = "done";
				Pchar.qbook.richards12 = "done";

				Pchar.Tgunsmith = "yes";
				Pchar.Tsailmaker = "yes";
				Pchar.Tassistent = "yes";
				Pchar.Tgovernor = "yes";
				Pchar.Ttower = "yes";
				Pchar.Cook_dead = "yes";

				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);

				ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "none", "", "");
				Locations[FindLocation("Tortuga_townhall")].reload.l3.disable = 0;
				locations[FindLocation("Tortuga_tower_passage")].id.label = "Tower passage";
	
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ4 = 1.5;	
				Locations[FindLocation("Tortuga_port")].locators_radius.box.box8 = 1.0;
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ1 = 0.9;	
			Locations[FindLocation("Tortuga_gunsmith_kitchen")].locators_radius.box.box1 = 0.001;

				Locations[FindLocation("cloister_exit")].locators_radius.box.box1 = 2.0
				Locations[FindLocation("cloister_exit")].reload.l5.disable = 1;			//cloister_exit to BB_graveyard not available
			Locations[FindLocation("cloister_exit")].locators_radius.box.box2 = 0.001;

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao conditions
			/*	
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
				Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
				LAi_SetPoorType(CharacterFromID("Hands"));
				ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");
			*/
				LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//done in here instead

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				Pchar.estate_direction = "Cayman_town";

				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade conditions

				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "30";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "31":
				//ANTIGUA: AFTER PRISON

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Antigua_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

				SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Hands"));

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);		//starts Vane info

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao + Maltains + Antigua prison conditions
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//	LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//not after Hands

				AddPassenger(Pchar, characterFromID("Hands"), 0);
				SetOfficersIndex(Pchar, 1, getCharacterIndex("Hands"));
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Hands"));

				AddPassenger(Pchar, characterFromID("Pell"), 0);
				SetOfficersIndex(Pchar, 2, getCharacterIndex("Pell"));
				characters[GetCharacterIndex("Pell")].dialog.CurrentNode = "neutral";
				LAi_SetOfficerType(characterFromID("Pell"));
				

				//check how these should be modified
				locations[FindLocation("Charlestown_port")].reload.l17.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l17.close_for_day = 0;	//always closed from now
				locations[FindLocation("Charlestown_port")].reload.l18.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l3.close_for_night = 0;	//townhall always open in WR, enough with Maltains close_for_day

				ChangeCharacterAddressGroup(characterFromID("Thomas Modiford"), "none", "", "");	//governor gone
				ChangeCharacterAddressGroup(characterFromID("Anne_Russel"), "Charlestown_Residence", "goto", "goto6");
				Characters[GetCharacterIndex("Anne_Russel")].dialog.CurrentNode  = "neutral";
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier3"), "Charlestown_port", "quest", "quest2");
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier4"), "Charlestown_port", "quest", "quest3");

				Pchar.unlocked_cells = "9";
				Pchar.cell9 = "unlocked"; Pchar.cell7 = "unlocked"; Pchar.cell3 = "unlocked"; 
				Pchar.cell1 = "unlocked"; Pchar.cell17 = "unlocked"; Pchar.cell15 = "unlocked";
				Pchar.cell5 = "unlocked"; Pchar.cell19 = "unlocked"; Pchar.cell2 = "unlocked";


				locations[FindLocation("Antigua_port")].models.always.locators = "StJohns_locators_JRH2";
				locations[FindLocation("Antigua_fakefort1")].reload.l4.disable = 1;	//fort to "bb_prison_port"

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				
				//these open to Estate
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.box.box1 = 0.8;
				Locations[FindLocation("Grand_Cayman_townhall")].locators_radius.goto.box1 = 0.8;

				Pchar.estate_direction = "Cayman_town";

				Pchar.eden_info = "start";	//must be on for gove Shaw to open to estate
				ChangeCharacterAddressGroup(characterFromID("Edmund Christobel Shaw"), "Grand_Cayman_townhall", "goto", "goto12");
				LAi_SetStayType(characterFromID("Edmund Christobel Shaw"));

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade conditions

				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "31";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "32":
				//CAYMAN PORT: AFTER ESTATE WINE CELLAR

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Cayman_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			
			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);	//starts Vane info

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao conditions
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);

				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//	LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//not after Hands


			/*	Characters[GetCharacterIndex("Hands")].name = TranslateString("","Beggar");
				Characters[GetCharacterIndex("Hands")].lastname = TranslateString("","");
				characters[GetCharacterIndex("Hands")].dialog.CurrentNode = "beggar";
				LAi_SetPoorType(CharacterFromID("Hands"));
				ChangeCharacterAddressGroup(CharacterFromID("Hands"), "Willemstad_town_3", "officers", "reload7_1");

				LAi_QuestDelay("start_Hands_Willemstad", 0.1);
			*/
			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions

				Locations[FindLocation("Grand_Cayman_town")].reload.l9.disable = 1;	//to townhall
				Pchar.Cayman_box1 = "locked";	//from townhall to Estate

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

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade conditions

				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");

				pchar.quest.Odel_dialog.win_condition.l1 = "locator";
				pchar.quest.Odel_dialog.win_condition.l1.location = "Smugglers_Tavern";
				pchar.quest.Odel_dialog.win_condition.l1.locator_group = "goto";
				pchar.quest.Odel_dialog.win_condition.l1.locator = "goto17";
				pchar.quest.Odel_dialog.win_condition = "Odel_dialog";

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "32";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "33":
				//TURKS: AFTER MAP FOUND

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Turks_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart_and_game", 0.1);		//starts Vane info

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao conditions
	
				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				Locations[FindLocation("Grand_Cayman_town")].reload.l9.disable = 1;	//to townhall
				Pchar.Cayman_box1 = "locked";	//from townhall to Estate

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

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade + Citadel + Turks conditions
			
				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");
				Characters[GetCharacterIndex("Odel")].dialog.CurrentNode  = "neutral";


				Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB1";
				Locations[FindLocation("Eleuthera_shore")].models.always.l1 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l2 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l3 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l5 = "leverC_up";
				Locations[FindLocation("Eleuthera_shore")].models.always.l6 = "anchor_big3";

				SetCharacterShipLocation(characterFromID("wr_mummy5"), "Eleuthera_shore");	//test for Citadel Rock
				Locations[FindLocation("Eleuthera_tavern_upstairs")].vcskip = true;	//enough with bad guys on Eleuthera_shore
				Locations[FindLocation("Eleuthera_shore")].vcskip = true;		//these are replaced with quest bad guys
				ChangeCharacterAddressGroup(characterFromID("Maynard"), "Eleuthera_shore", "quest", "quest6");
				Pchar.citadel_lever = "up";
				Locations[FindLocation("Eleuthera_shore")].locators_radius.box.box36 = 0.001;
				Locations[FindLocation("Eleuthera_shore")].locators_radius.reload.reload4 = 1.0;
				Locations[FindLocation("Citadel_cave")].locators_radius.box.box1 = 0.001;
			
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug1"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug2"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug3"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug4"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug5"), "none", "", "");

				
				Locations[FindLocation("Turks_port")].models.always.l9 = "Margarita_gatebroken";
				Locations[FindLocation("Turks_port")].locators_radius.box.box10 = 0.7;		//boat back to cave
				Locations[FindLocation("Turks_tavern_kitchen")].reload.l5.disable = 1;		//roof tour only once
				Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_KR_closed";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gate = "";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gatebroken = "Margarita_gatebroken";
				ChangeCharacterAddressGroup(characterFromID("shipwreck_trader"), "Turks_old_Fort", "goto", "goto13");
				LAi_SetCitizenType(characterFromID("shipwreck_trader"));

			//------------------------------------------------------------------------------------------------------------------
			
				Pchar.quest.Teach_head = "33";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "34":
				//CARTAGENA: AFTER ALL 4 MISSIONS

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Cartagena_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart", 0.1);		//Vane info done

			//------------------------------------------------------------------------------------------------------------------
			//Surgeons Tortuga + Cartagena conditions

			//	SetServedNation(FRANCE);
			//	HoistFlag(FRANCE);
			
				Pchar.qbook.richards4 = "done";
				Pchar.qbook.richards5 = "done";
				Pchar.qbook.richards6 = "done";
				Pchar.qbook.richards7 = "done";
				Pchar.qbook.richards8 = "done";
				Pchar.qbook.richards9 = "done";
				Pchar.qbook.richards10 = "done";
				Pchar.qbook.richards11 = "done";
				Pchar.qbook.richards12 = "done";

				Pchar.Tgunsmith = "yes";
				Pchar.Tsailmaker = "yes";
				Pchar.Tassistent = "yes";
				Pchar.Tgovernor = "yes";
				Pchar.Ttower = "yes";
				Pchar.Cook_dead = "yes";

				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);

				ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "none", "", "");
				Locations[FindLocation("Tortuga_townhall")].reload.l3.disable = 0;
				locations[FindLocation("Tortuga_tower_passage")].id.label = "Tower passage";
	
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ4 = 1.5;	
				Locations[FindLocation("Tortuga_port")].locators_radius.box.box8 = 1.0;
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ1 = 0.9;
			Locations[FindLocation("Tortuga_gunsmith_kitchen")].locators_radius.box.box1 = 0.001;	

				Locations[FindLocation("cloister_exit")].locators_radius.box.box1 = 2.0
				Locations[FindLocation("cloister_exit")].reload.l5.disable = 1;			//cloister_exit to BB_graveyard not available
			Locations[FindLocation("cloister_exit")].locators_radius.box.box2 = 0.001;

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao + Maltains + Antigua prison conditions
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//	LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//not after Hands

				//check how these should be modified
				locations[FindLocation("Charlestown_port")].reload.l17.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l17.close_for_day = 0;	//always closed from now
				locations[FindLocation("Charlestown_port")].reload.l18.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l3.close_for_night = 0;	//townhall always open in WR, enough with Maltains close_for_day

				ChangeCharacterAddressGroup(characterFromID("Thomas Modiford"), "none", "", "");	//governor gone
				ChangeCharacterAddressGroup(characterFromID("Anne_Russel"), "Charlestown_Residence", "goto", "goto6");
				Characters[GetCharacterIndex("Anne_Russel")].dialog.CurrentNode  = "neutral";
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier3"), "Charlestown_port", "quest", "quest2");
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier4"), "Charlestown_port", "quest", "quest3");

				Pchar.unlocked_cells = "9";
				Pchar.cell9 = "unlocked"; Pchar.cell7 = "unlocked"; Pchar.cell3 = "unlocked"; 
				Pchar.cell1 = "unlocked"; Pchar.cell17 = "unlocked"; Pchar.cell15 = "unlocked";
				Pchar.cell5 = "unlocked"; Pchar.cell19 = "unlocked"; Pchar.cell2 = "unlocked";


				locations[FindLocation("Antigua_port")].models.always.locators = "StJohns_locators_JRH2";
				locations[FindLocation("Antigua_fakefort1")].reload.l4.disable = 1;	//fort to "bb_prison_port"
			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				Locations[FindLocation("Grand_Cayman_town")].reload.l9.disable = 1;	//to townhall
				Pchar.Cayman_box1 = "locked";	//from townhall to Estate

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade + Citadel + Turks conditions
			
				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");
				Characters[GetCharacterIndex("Odel")].dialog.CurrentNode  = "neutral";


				Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB1";
				Locations[FindLocation("Eleuthera_shore")].models.always.l1 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l2 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l3 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l5 = "leverC_up";
				Locations[FindLocation("Eleuthera_shore")].models.always.l6 = "anchor_big3";

				SetCharacterShipLocation(characterFromID("wr_mummy5"), "Eleuthera_shore");	//test for Citadel Rock
				Locations[FindLocation("Eleuthera_tavern_upstairs")].vcskip = true;	//enough with bad guys on Eleuthera_shore
				Locations[FindLocation("Eleuthera_shore")].vcskip = true;		//these are replaced with quest bad guys
				ChangeCharacterAddressGroup(characterFromID("Maynard"), "Eleuthera_shore", "quest", "quest6");
				Pchar.citadel_lever = "up";
				Locations[FindLocation("Eleuthera_shore")].locators_radius.box.box36 = 0.001;
				Locations[FindLocation("Eleuthera_shore")].locators_radius.reload.reload4 = 1.0;
				Locations[FindLocation("Citadel_cave")].locators_radius.box.box1 = 0.001;
			
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug1"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug2"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug3"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug4"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug5"), "none", "", "");

				
				Locations[FindLocation("Turks_port")].models.always.l9 = "Margarita_gatebroken";
				Locations[FindLocation("Turks_port")].locators_radius.box.box10 = 0.7;		//boat back to cave
				Locations[FindLocation("Turks_tavern_kitchen")].reload.l5.disable = 1;		//roof tour only once
				Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_KR_closed";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gate = "";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gatebroken = "Margarita_gatebroken";
				ChangeCharacterAddressGroup(characterFromID("shipwreck_trader"), "Turks_old_Fort", "goto", "goto13");
				LAi_SetCitizenType(characterFromID("shipwreck_trader"));

			//------------------------------------------------------------------------------------------------------------------
			//after all 4 missions

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

				ChangeCharacterAddressGroup(CharacterFromID("Defoe"), "new_cloister_garden", "quest", "defoe");
				LAi_SetSitType(CharacterFromID("Defoe"));
				Characters[GetCharacterIndex("Defoe")].dialog.CurrentNode  = "neutral";//if spoken to before the auto dialog starts
		
				ChangeCharacterAddressGroup(CharacterFromID("gm_crew8"), "Cartagena_town_02", "officers", "falaise_de_fleur_location_02_perechod_3");
				Locations[FindLocation("Cartagena_town_02")].locators_radius.officers.falaise_de_fleur_location_02_perechod_3 = 3.0;
				SetLocatorRadius(locations[FindLocation(Pchar.location)], "officers", "falaise_de_fleur_location_02_perechod_3", 3.0);

				pchar.quest.defoe_letter.win_condition.l1 = "locator";
				pchar.quest.defoe_letter.win_condition.l1.location = "Cartagena_town_02";
				pchar.quest.defoe_letter.win_condition.l1.locator_group = "officers";
				pchar.quest.defoe_letter.win_condition.l1.locator = "falaise_de_fleur_location_02_perechod_3";
				pchar.quest.defoe_letter.win_condition = "defoe_letter";

				pchar.quest.defoe_sit_down.win_condition.l1 = "locator";
				pchar.quest.defoe_sit_down.win_condition.l1.location = "new_cloister_garden";
				pchar.quest.defoe_sit_down.win_condition.l1.locator_group = "quest";
				pchar.quest.defoe_sit_down.win_condition.l1.locator = "defoe";
				pchar.quest.defoe_sit_down.win_condition = "defoe_sit_down";

			//------------------------------------------------------------------------------------------------------------------
				Pchar.quest.Teach_head = "34";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "35":
				//KRISTIANIA: AFTER ALL 6 ITEMS FOUND

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore
				Island_SetReloadEnableLocal("IslaMona", "reload_1", true);	
				Islands[FindIsland("IslaMona")].reload.l1.goto_enable = true;

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart", 0.1);		//Vane info done

			//------------------------------------------------------------------------------------------------------------------
			//Surgeons Tortuga + Cartagena conditions

			//	SetServedNation(FRANCE);
			//	HoistFlag(FRANCE);
			
				Pchar.qbook.richards4 = "done";
				Pchar.qbook.richards5 = "done";
				Pchar.qbook.richards6 = "done";
				Pchar.qbook.richards7 = "done";
				Pchar.qbook.richards8 = "done";
				Pchar.qbook.richards9 = "done";
				Pchar.qbook.richards10 = "done";
				Pchar.qbook.richards11 = "done";
				Pchar.qbook.richards12 = "done";

				Pchar.Tgunsmith = "yes";
				Pchar.Tsailmaker = "yes";
				Pchar.Tassistent = "yes";
				Pchar.Tgovernor = "yes";
				Pchar.Ttower = "yes";
				Pchar.Cook_dead = "yes";

				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);

				ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "none", "", "");
				Locations[FindLocation("Tortuga_townhall")].reload.l3.disable = 0;
				locations[FindLocation("Tortuga_tower_passage")].id.label = "Tower passage";
	
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ4 = 1.5;	
				Locations[FindLocation("Tortuga_port")].locators_radius.box.box8 = 1.0;
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ1 = 0.9;
			Locations[FindLocation("Tortuga_gunsmith_kitchen")].locators_radius.box.box1 = 0.001;

				Locations[FindLocation("cloister_exit")].locators_radius.box.box1 = 2.0
				Locations[FindLocation("cloister_exit")].reload.l5.disable = 1;			//cloister_exit to BB_graveyard not available
			Locations[FindLocation("cloister_exit")].locators_radius.box.box2 = 0.001;

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao + Maltains + Antigua prison conditions
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//	LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//not after Hands

				//check how these should be modified
				locations[FindLocation("Charlestown_port")].reload.l17.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l17.close_for_day = 0;	//always closed from now
				locations[FindLocation("Charlestown_port")].reload.l18.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l3.close_for_night = 0;	//townhall always open in WR, enough with Maltains close_for_day

				ChangeCharacterAddressGroup(characterFromID("Thomas Modiford"), "none", "", "");	//governor gone
				ChangeCharacterAddressGroup(characterFromID("Anne_Russel"), "Charlestown_Residence", "goto", "goto6");
				Characters[GetCharacterIndex("Anne_Russel")].dialog.CurrentNode  = "neutral";
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier3"), "Charlestown_port", "quest", "quest2");
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier4"), "Charlestown_port", "quest", "quest3");

				Pchar.unlocked_cells = "9";
				Pchar.cell9 = "unlocked"; Pchar.cell7 = "unlocked"; Pchar.cell3 = "unlocked"; 
				Pchar.cell1 = "unlocked"; Pchar.cell17 = "unlocked"; Pchar.cell15 = "unlocked";
				Pchar.cell5 = "unlocked"; Pchar.cell19 = "unlocked"; Pchar.cell2 = "unlocked";


				locations[FindLocation("Antigua_port")].models.always.locators = "StJohns_locators_JRH2";
				locations[FindLocation("Antigua_fakefort1")].reload.l4.disable = 1;	//fort to "bb_prison_port"
			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				Locations[FindLocation("Grand_Cayman_town")].reload.l9.disable = 1;	//to townhall
				Pchar.Cayman_box1 = "locked";	//from townhall to Estate

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade + Citadel + Turks conditions
			
				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");
				Characters[GetCharacterIndex("Odel")].dialog.CurrentNode  = "neutral";


				Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB1";
				Locations[FindLocation("Eleuthera_shore")].models.always.l1 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l2 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l3 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l5 = "leverC_up";
				Locations[FindLocation("Eleuthera_shore")].models.always.l6 = "anchor_big3";

				SetCharacterShipLocation(characterFromID("wr_mummy5"), "Eleuthera_shore");	//test for Citadel Rock
				Locations[FindLocation("Eleuthera_tavern_upstairs")].vcskip = true;	//enough with bad guys on Eleuthera_shore
				Locations[FindLocation("Eleuthera_shore")].vcskip = true;		//these are replaced with quest bad guys
				ChangeCharacterAddressGroup(characterFromID("Maynard"), "Eleuthera_shore", "quest", "quest6");
				Pchar.citadel_lever = "up";
				Locations[FindLocation("Eleuthera_shore")].locators_radius.box.box36 = 0.001;
				Locations[FindLocation("Eleuthera_shore")].locators_radius.reload.reload4 = 1.0;
				Locations[FindLocation("Citadel_cave")].locators_radius.box.box1 = 0.001;
			
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug1"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug2"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug3"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug4"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug5"), "none", "", "");

				
				Locations[FindLocation("Turks_port")].models.always.l9 = "Margarita_gatebroken";
				Locations[FindLocation("Turks_port")].locators_radius.box.box10 = 0.7;		//boat back to cave
				Locations[FindLocation("Turks_tavern_kitchen")].reload.l5.disable = 1;		//roof tour only once
				Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_KR_closed";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gate = "";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gatebroken = "Margarita_gatebroken";
				ChangeCharacterAddressGroup(characterFromID("shipwreck_trader"), "Turks_old_Fort", "goto", "goto13");
				LAi_SetCitizenType(characterFromID("shipwreck_trader"));

			//------------------------------------------------------------------------------------------------------------------
			//after all 4 missions

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
	
			//------------------------------------------------------------------------------------------------------------------
			//after Kristiania

				Locations[FindLocation("Kristiania_entre")].models.always.locators = "ff01_l_JRH_stop2";
				Locations[FindLocation("Kristiania_center")].models.always.locators = "GrTown_l_JRH_stop2";
				Locations[FindLocation("Nueva_Suecia_lower_town")].models.always.locators = "mu01_l_JRH_open";
				Locations[FindLocation("Nueva_Suecia_hidden_town")].models.always.locators = "mu01_l_JRH2";
				Locations[FindLocation("Nueva_Suecia_upper_town")].models.always.locators = "mu03_l_JRH_open";
				Locations[FindLocation("Kristiania_port")].models.always.locators = "GrPort_l_JRH";
				Locations[FindLocation("Kristiania_cathedral")].models.always.locators = "church3_l_ON_open";


				Locations[FindLocation("Kristiania_entre")].reload.l2.disable = 0;	//NS upper
				Locations[FindLocation("Kristiania_entre")].reload.l3.disable = 1;	//center
				locations[FindLocation("Kristiania_entre")].type = "silent_repair_town";

				Locations[FindLocation("Kristiania_center")].reload.l3.disable = 1;	//entre
				Locations[FindLocation("Kristiania_center")].reload.l9.disable = 0;	//TH office
				Locations[FindLocation("Kristiania_center")].locators_radius.reload.reload19 = 1.0;	//fort
				locations[FindLocation("Kristiania_center")].type = "silent_repair_town";

				Locations[FindLocation("Kristiania_townhall_entre")].reload.l2.disable = 1;	//TH
		
				Locations[FindLocation("Kristiania_fort_stairs")].reload.l4.disable = 1;	//commander

				Locations[FindLocation("Nueva_Suecia_upper_town")].models.always.l3 = "lever_down";
				locations[FindLocation("Nueva_Suecia_upper_town")].type = "town";
				Locations[FindLocation("Nueva_Suecia_lower_town")].locators_radius.box.box2 = 0.0001;	//ladder to bell

				Locations[FindLocation("Kristiania_cathedral")].locators_radius.box.box6 = 0.0001;	//collection box
				Locations[FindLocation("Kristiania_cathedral")].reload.l2.disable = 0;		//inner town
				Locations[FindLocation("Kristiania_cathedral")].models.always.l1 = "door_button";
				Locations[FindLocation("Kristiania_cathedral")].models.always.l2 = "";		//no wire

				Locations[FindLocation("Nueva_Suecia_upper_town")].reload.l1.disable = 0;	//entre
				Locations[FindLocation("Nueva_Suecia_upper_town")].reload.l1.go = "Kristiania_entre";
				locations[FindLocation("Nueva_Suecia_upper_town")].type = "town";

				Locations[FindLocation("NS_hidden_town_Tavern")].reload.l2.disable = 1;		//priest
				Locations[FindLocation("Nueva_Suecia_TailorsShop")].reload.l2.disable = 1;	//textiles
				
				Locations[FindLocation("Kristiania_jungle_house")].locators_radius.box.box1 = 0.0001;	//to RedHouse

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit1"), "Kristiania_entre", "goto", "citizen010");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit8"), "Kristiania_entre", "reload", "locator22");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit9"), "Kristiania_entre", "goto", "citizen06");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit10"), "Kristiania_entre", "goto", "locator11");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit2"), "Kristiania_center", "reload", "reload28");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit11"), "Kristiania_center", "goto", "goto37");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit12"), "Kristiania_center", "goto", "goto52");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit13"), "Kristiania_center", "reload", "reload13");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit3"), "Kristiania_downhill", "goto", "locator13");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit14"), "Kristiania_downhill", "goto", "citizen04");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit15"), "Kristiania_downhill", "reload", "home");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit4"), "Kristiania_suburb", "goto", "citizen01");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit16"), "Kristiania_suburb", "reload", "locator21");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit17"), "Kristiania_suburb", "goto", "locator9");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit5"), "Nueva_Suecia_lower_town", "reload", "reload27");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit18"), "Nueva_Suecia_lower_town", "reload", "reload25");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit19"), "Nueva_Suecia_lower_town", "goto", "goto90");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit20"), "Nueva_Suecia_hidden_town", "goto", "goto2");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit21"), "Nueva_Suecia_hidden_town", "goto", "goto61");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit6"), "Nueva_Suecia_upper_town", "goto", "goto5");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit23"), "Nueva_Suecia_upper_town", "reload", "reload8");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit24"), "Nueva_Suecia_upper_town", "goto", "character4");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit7"), "Kristiania_port", "goto", "goto1");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit25"), "Kristiania_port", "goto", "goto4");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit27"), "Kristiania_port", "goto", "goto3");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit28"), "Kristiania_swamp_exit", "goto", "citizen02");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit29"), "Kristiania_swamp_exit", "goto", "citizen04");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit30"), "Kristiania_jungle_exit", "goto", "citizen011");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit31"), "Kristiania_jungle_exit", "goto", "citizen013");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit32"), "Kristiania_jungle_exit", "goto", "citizen03");

				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit22"), "Kristiania_townhall_entre", "sit", "sit2");
				ChangeCharacterAddressGroup(CharacterFromID("Kr_cit26"), "Kristiania_townhall_entre", "sit", "sit3");


				LAi_SetCitizenType(characterFromID("Kr_cit1")); LAi_SetCitizenType(characterFromID("Kr_cit4"));
				LAi_SetCitizenType(characterFromID("Kr_cit6")); LAi_SetCitizenType(characterFromID("Kr_cit7"));
				LAi_SetCitizenType(characterFromID("Kr_cit12")); LAi_SetCitizenType(characterFromID("Kr_cit17"));
				LAi_SetCitizenType(characterFromID("Kr_cit18")); LAi_SetCitizenType(characterFromID("Kr_cit20"));
				LAi_SetCitizenType(characterFromID("Kr_cit21")); LAi_SetCitizenType(characterFromID("Kr_cit23"));
				LAi_SetCitizenType(characterFromID("Kr_cit24")); LAi_SetCitizenType(characterFromID("Kr_cit25"));

				LAi_SetCitizenType(characterFromID("Kr_cit2")); LAi_SetCitizenType(characterFromID("Kr_cit8"));
				LAi_SetCitizenType(characterFromID("Kr_cit10")); LAi_SetCitizenType(characterFromID("Kr_cit11"));
				LAi_SetCitizenType(characterFromID("Kr_cit14")); LAi_SetCitizenType(characterFromID("Kr_cit15"));
				LAi_SetCitizenType(characterFromID("Kr_cit16"));

				LAi_SetCitizenType(characterFromID("Kr_cit3")); LAi_SetCitizenType(characterFromID("Kr_cit5"));
				LAi_SetCitizenType(characterFromID("Kr_cit9")); LAi_SetCitizenType(characterFromID("Kr_cit13"));
				LAi_SetCitizenType(characterFromID("Kr_cit19")); LAi_SetCitizenType(characterFromID("Kr_cit27"));
				LAi_SetCitizenType(characterFromID("Kr_cit29"));

				LAi_SetCitizenType(characterFromID("Kr_cit28")); LAi_SetCitizenType(characterFromID("Kr_cit30"));
				LAi_SetCitizenType(characterFromID("Kr_cit31")); LAi_SetCitizenType(characterFromID("Kr_cit32"));
		
				LAi_SetSitType(characterFromID("Kr_cit22")); LAi_SetSitType(characterFromID("Kr_cit26"));

				Pchar.Kr_quest = "6_locations";//changes Kr citizens dialog
				Pchar.Kr_password = "known";
				Pchar.BB_shya = "knowledge";
				Pchar.BB_churches = "knowledge";
				Pchar.BB_tailor = "knowledge";
				Pchar.BB_RH_exit = "knowledge";

				Characters[GetCharacterIndex("Kr_cit22")].dialog.CurrentNode  = "townhall_neutral";
				Characters[GetCharacterIndex("Kr_cit26")].dialog.CurrentNode  = "townhall_neutral";


			//------------------------------------------------------------------------------------------------------------------
			//BB tower conditions

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

			//------------------------------------------------------------------------------------------------------------------
				Pchar.quest.Teach_head = "35";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "36":
				//CAREEN SHORE: AFTER BLACKBEARD'S TOWER

				Pchar.quest.disable_rebirth = true;
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore
				Island_SetReloadEnableLocal("IslaMona", "reload_1", true);	
				Islands[FindIsland("IslaMona")].reload.l1.goto_enable = true;

				SetCurrentTime(12, 0);
				SetNextWeather("Clear");

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart", 0.1);		//Vane info done

			//------------------------------------------------------------------------------------------------------------------
			//Surgeons Tortuga + Cartagena conditions

			//	SetServedNation(FRANCE);
			//	HoistFlag(FRANCE);
			
				Pchar.qbook.richards4 = "done";
				Pchar.qbook.richards5 = "done";
				Pchar.qbook.richards6 = "done";
				Pchar.qbook.richards7 = "done";
				Pchar.qbook.richards8 = "done";
				Pchar.qbook.richards9 = "done";
				Pchar.qbook.richards10 = "done";
				Pchar.qbook.richards11 = "done";
				Pchar.qbook.richards12 = "done";

				Pchar.Tgunsmith = "yes";
				Pchar.Tsailmaker = "yes";
				Pchar.Tassistent = "yes";
				Pchar.Tgovernor = "yes";
				Pchar.Ttower = "yes";
				Pchar.Cook_dead = "yes";

				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);

				ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "none", "", "");
				Locations[FindLocation("Tortuga_townhall")].reload.l3.disable = 0;
				locations[FindLocation("Tortuga_tower_passage")].id.label = "Tower passage";
	
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ4 = 1.5;	
				Locations[FindLocation("Tortuga_port")].locators_radius.box.box8 = 1.0;
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ1 = 0.9;
			Locations[FindLocation("Tortuga_gunsmith_kitchen")].locators_radius.box.box1 = 0.001;

				Locations[FindLocation("cloister_exit")].locators_radius.box.box1 = 2.0
				Locations[FindLocation("cloister_exit")].reload.l5.disable = 1;			//cloister_exit to BB_graveyard not available
			Locations[FindLocation("cloister_exit")].locators_radius.box.box2 = 0.001;

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao + Maltains + Antigua prison conditions
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//	LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//not after Hands

				//check how these should be modified
				locations[FindLocation("Charlestown_port")].reload.l17.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l17.close_for_day = 0;	//always closed from now
				locations[FindLocation("Charlestown_port")].reload.l18.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l3.close_for_night = 0;	//townhall always open in WR, enough with Maltains close_for_day

				ChangeCharacterAddressGroup(characterFromID("Thomas Modiford"), "none", "", "");	//governor gone
				ChangeCharacterAddressGroup(characterFromID("Anne_Russel"), "Charlestown_Residence", "goto", "goto6");
				Characters[GetCharacterIndex("Anne_Russel")].dialog.CurrentNode  = "neutral";
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier3"), "Charlestown_port", "quest", "quest2");
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier4"), "Charlestown_port", "quest", "quest3");

				Pchar.unlocked_cells = "9";
				Pchar.cell9 = "unlocked"; Pchar.cell7 = "unlocked"; Pchar.cell3 = "unlocked"; 
				Pchar.cell1 = "unlocked"; Pchar.cell17 = "unlocked"; Pchar.cell15 = "unlocked";
				Pchar.cell5 = "unlocked"; Pchar.cell19 = "unlocked"; Pchar.cell2 = "unlocked";


				locations[FindLocation("Antigua_port")].models.always.locators = "StJohns_locators_JRH2";
				locations[FindLocation("Antigua_fakefort1")].reload.l4.disable = 1;	//fort to "bb_prison_port"
			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				Locations[FindLocation("Grand_Cayman_town")].reload.l9.disable = 1;	//to townhall
				Pchar.Cayman_box1 = "locked";	//from townhall to Estate

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade + Citadel + Turks conditions
			
				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");
				Characters[GetCharacterIndex("Odel")].dialog.CurrentNode  = "neutral";


				Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB1";
				Locations[FindLocation("Eleuthera_shore")].models.always.l1 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l2 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l3 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l5 = "leverC_up";
				Locations[FindLocation("Eleuthera_shore")].models.always.l6 = "anchor_big3";

				SetCharacterShipLocation(characterFromID("wr_mummy5"), "Eleuthera_shore");	//test for Citadel Rock
				Locations[FindLocation("Eleuthera_tavern_upstairs")].vcskip = true;	//enough with bad guys on Eleuthera_shore
				Locations[FindLocation("Eleuthera_shore")].vcskip = true;		//these are replaced with quest bad guys
				ChangeCharacterAddressGroup(characterFromID("Maynard"), "Eleuthera_shore", "quest", "quest6");
				Pchar.citadel_lever = "up";
				Locations[FindLocation("Eleuthera_shore")].locators_radius.box.box36 = 0.001;
				Locations[FindLocation("Eleuthera_shore")].locators_radius.reload.reload4 = 1.0;
				Locations[FindLocation("Citadel_cave")].locators_radius.box.box1 = 0.001;
			
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug1"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug2"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug3"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug4"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug5"), "none", "", "");

				
				Locations[FindLocation("Turks_port")].models.always.l9 = "Margarita_gatebroken";
				Locations[FindLocation("Turks_port")].locators_radius.box.box10 = 0.7;		//boat back to cave
				Locations[FindLocation("Turks_tavern_kitchen")].reload.l5.disable = 1;		//roof tour only once
				Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_KR_closed";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gate = "";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gatebroken = "Margarita_gatebroken";
				ChangeCharacterAddressGroup(characterFromID("shipwreck_trader"), "Turks_old_Fort", "goto", "goto13");
				LAi_SetCitizenType(characterFromID("shipwreck_trader"));

			//------------------------------------------------------------------------------------------------------------------
			//after all 4 missions

			//------------------------------------------------------------------------------------------------------------------
			//after Kristiania
		
			//------------------------------------------------------------------------------------------------------------------
			//careen shore conditions

				SetModel(characterFromID("Hands"), "bb_hands2", "man", "man", 1.8, true);
				SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, true);
				Characters[GetCharacterIndex("Caesar")].dialog.CurrentNode  = "neutral";

				Pchar.special_flag = "on";
				CaptureTownForNation("Grand_Turk", PIRATE);
				ref cmdr = CharacterFromID("Dante Siciliano");//ok here
				cmdr.nation = PIRATE;
				cmdr.Flags.Pirate = 4; cmdr.Flags.Pirate.texture = 2;

				RemoveCharacterEquip(Pchar, GUN_ITEM_TYPE);
				RemoveCharacterEquip(Pchar, BLADE_ITEM_TYPE);
				RemoveCharacterEquip(Pchar, COMPASS_ITEM_TYPE);
				RemoveCharacterEquip(Pchar, CLOCK_ITEM_TYPE);
				RemoveCharacterEquip(Pchar, SPYGLASS_ITEM_TYPE);			
				DeleteAttribute(Pchar, "items");		

				AddMoneyToCharacter(Pchar, -100000);
				GiveItem2Character(Pchar, "bladeX4");
		    		EquipCharacterbyItem(Pchar, "bladeX4");

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

			//------------------------------------------------------------------------------------------------------------------
				Pchar.quest.Teach_head = "36";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "37":
				//CORVETTE: AFTER CAREEN SHORE

				Pchar.quest.disable_rebirth = true;
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore
				Island_SetReloadEnableLocal("IslaMona", "reload_1", true);	
				Islands[FindIsland("IslaMona")].reload.l1.goto_enable = true;

				SetCurrentTime(0.00, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart", 0.1);		//Vane info done

			//------------------------------------------------------------------------------------------------------------------
			//Surgeons Tortuga + Cartagena conditions

			//	SetServedNation(FRANCE);
			//	HoistFlag(FRANCE);
			
				Pchar.qbook.richards4 = "done";
				Pchar.qbook.richards5 = "done";
				Pchar.qbook.richards6 = "done";
				Pchar.qbook.richards7 = "done";
				Pchar.qbook.richards8 = "done";
				Pchar.qbook.richards9 = "done";
				Pchar.qbook.richards10 = "done";
				Pchar.qbook.richards11 = "done";
				Pchar.qbook.richards12 = "done";

				Pchar.Tgunsmith = "yes";
				Pchar.Tsailmaker = "yes";
				Pchar.Tassistent = "yes";
				Pchar.Tgovernor = "yes";
				Pchar.Ttower = "yes";
				Pchar.Cook_dead = "yes";

				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);

				ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "none", "", "");
				Locations[FindLocation("Tortuga_townhall")].reload.l3.disable = 0;
				locations[FindLocation("Tortuga_tower_passage")].id.label = "Tower passage";
	
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ4 = 1.5;	
				Locations[FindLocation("Tortuga_port")].locators_radius.box.box8 = 1.0;
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ1 = 0.9;
			Locations[FindLocation("Tortuga_gunsmith_kitchen")].locators_radius.box.box1 = 0.001;	

				Locations[FindLocation("cloister_exit")].locators_radius.box.box1 = 2.0
				Locations[FindLocation("cloister_exit")].reload.l5.disable = 1;			//cloister_exit to BB_graveyard not available
			Locations[FindLocation("cloister_exit")].locators_radius.box.box2 = 0.001;

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao + Maltains + Antigua prison conditions
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";
		
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//	LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//not after Hands

				//check how these should be modified
				locations[FindLocation("Charlestown_port")].reload.l17.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l17.close_for_day = 0;	//always closed from now
				locations[FindLocation("Charlestown_port")].reload.l18.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l3.close_for_night = 0;	//townhall always open in WR, enough with Maltains close_for_day

				ChangeCharacterAddressGroup(characterFromID("Thomas Modiford"), "none", "", "");	//governor gone
				ChangeCharacterAddressGroup(characterFromID("Anne_Russel"), "Charlestown_Residence", "goto", "goto6");
				Characters[GetCharacterIndex("Anne_Russel")].dialog.CurrentNode  = "neutral";
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier3"), "Charlestown_port", "quest", "quest2");
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier4"), "Charlestown_port", "quest", "quest3");

				Pchar.unlocked_cells = "9";
				Pchar.cell9 = "unlocked"; Pchar.cell7 = "unlocked"; Pchar.cell3 = "unlocked"; 
				Pchar.cell1 = "unlocked"; Pchar.cell17 = "unlocked"; Pchar.cell15 = "unlocked";
				Pchar.cell5 = "unlocked"; Pchar.cell19 = "unlocked"; Pchar.cell2 = "unlocked";


				locations[FindLocation("Antigua_port")].models.always.locators = "StJohns_locators_JRH2";
				locations[FindLocation("Antigua_fakefort1")].reload.l4.disable = 1;	//fort to "bb_prison_port"
			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				Locations[FindLocation("Grand_Cayman_town")].reload.l9.disable = 1;	//to townhall
				Pchar.Cayman_box1 = "locked";	//from townhall to Estate

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade + Citadel + Turks conditions
			
				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");
				Characters[GetCharacterIndex("Odel")].dialog.CurrentNode  = "neutral";


				Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB1";
				Locations[FindLocation("Eleuthera_shore")].models.always.l1 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l2 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l3 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l5 = "leverC_up";
				Locations[FindLocation("Eleuthera_shore")].models.always.l6 = "anchor_big3";

				SetCharacterShipLocation(characterFromID("wr_mummy5"), "Eleuthera_shore");	//test for Citadel Rock
				Locations[FindLocation("Eleuthera_tavern_upstairs")].vcskip = true;	//enough with bad guys on Eleuthera_shore
				Locations[FindLocation("Eleuthera_shore")].vcskip = true;		//these are replaced with quest bad guys
				ChangeCharacterAddressGroup(characterFromID("Maynard"), "Eleuthera_shore", "quest", "quest6");
				Pchar.citadel_lever = "up";
				Locations[FindLocation("Eleuthera_shore")].locators_radius.box.box36 = 0.001;
				Locations[FindLocation("Eleuthera_shore")].locators_radius.reload.reload4 = 1.0;
				Locations[FindLocation("Citadel_cave")].locators_radius.box.box1 = 0.001;
			
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug1"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug2"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug3"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug4"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug5"), "none", "", "");

				
				Locations[FindLocation("Turks_port")].models.always.l9 = "Margarita_gatebroken";
				Locations[FindLocation("Turks_port")].locators_radius.box.box10 = 0.7;		//boat back to cave
				Locations[FindLocation("Turks_tavern_kitchen")].reload.l5.disable = 1;		//roof tour only once
				Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_KR_closed";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gate = "";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gatebroken = "Margarita_gatebroken";
				ChangeCharacterAddressGroup(characterFromID("shipwreck_trader"), "Turks_old_Fort", "goto", "goto13");
				LAi_SetCitizenType(characterFromID("shipwreck_trader"));

			//------------------------------------------------------------------------------------------------------------------
			//after all 4 missions

			//------------------------------------------------------------------------------------------------------------------
			//after Kristiania
		
			//------------------------------------------------------------------------------------------------------------------
			//careen shore conditions

			//------------------------------------------------------------------------------------------------------------------
			//corvette conditions
			
				SetModel(characterFromID("Hands"), "bb_hands2", "man", "man", 1.8, true);
				SetModel(characterFromID("Pell"), "bb_Pell", "man", "man", 1.8, true);
				Characters[GetCharacterIndex("Caesar")].dialog.CurrentNode  = "neutral";
			
				DeleteAttribute(Pchar, "items");		

				AddMoneyToCharacter(Pchar, -100000);
				GiveItem2Character(Pchar, "bladeX4");
		    		EquipCharacterbyItem(Pchar, "bladeX4");
				GiveItem2Character(Pchar, "book71_9_start");
				GiveItem2Character(Pchar, "picture8_A");

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

				DeleteAttribute(characterFromID("Caesar"), "items");
				DeleteAttribute(characterFromID("mutineer_23"), "items");
				DeleteAttribute(characterFromID("mutineer_19"), "items");

				GiveItem2Character(characterFromID("Caesar"),"bladeX4");
				EquipCharacterByItem(characterFromID("Caesar"), "bladeX4");
				GiveItem2Character(characterFromID("mutineer_23"),"bladeX4");
				EquipCharacterByItem(characterFromID("mutineer_23"), "bladeX4");
				GiveItem2Character(characterFromID("mutineer_19"),"bladeX4");
				EquipCharacterByItem(characterFromID("mutineer_19"), "bladeX4");

				Characters[GetCharacterIndex("Mutineer_32")].name = TranslateString("", "Quartermaster");

				LAi_QuestDelay("start_careen_corvette", 0.1);

		
			//------------------------------------------------------------------------------------------------------------------
				Pchar.quest.Teach_head = "37";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;

			case "38":
				//ISLA MONA: AFTER CORVETTE

				Pchar.quest.disable_rebirth = true;
				GiveShip2Character(pchar,"Corvette2","Den svenske islandsfararen",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "IslaMona_port");
				Locations[FindLocation("wr_port")].models.always.locators = "QCport_l_JRHsea";
				Locations[FindLocation("wr_port")].reload.l2.disable = 1;	//farm locked
				Island_SetReloadEnableLocal("Redmond", "reload_1", true);	//back to wr_port
				Island_SetReloadEnableLocal("Redmond", "reload_3", true);	//to cave_shore
				Island_SetReloadEnableLocal("IslaMona", "reload_1", true);	
				Islands[FindIsland("IslaMona")].reload.l1.goto_enable = true;

				SetCurrentTime(12.00, 0);
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";
				SetNextWind("E",30);

			//------------------------------------------------------------------------------------------------------------------
			//start conditions all >= "22"
				Locations[FindLocation("Redmond_shore_03")].models.always.locators = "shore10_l_JRH1";
				Locations[FindLocation("Redmond_shore_03")].locators_radius.reload.reload1 = 0.001;
				Characters[GetCharacterIndex("CoastBrother33")].Ship.Type = "obj_invisible";		//was tartane at boat shore

			//------------------------------------------------------------------------------------------------------------------
			//Vane cave_shore conditions
			
				LAi_QuestDelay("Vane_Richards_from_jumpstart", 0.1);		//Vane info done

			//------------------------------------------------------------------------------------------------------------------
			//Surgeons Tortuga + Cartagena conditions

			//	SetServedNation(FRANCE);
			//	HoistFlag(FRANCE);
			
				Pchar.qbook.richards4 = "done";
				Pchar.qbook.richards5 = "done";
				Pchar.qbook.richards6 = "done";
				Pchar.qbook.richards7 = "done";
				Pchar.qbook.richards8 = "done";
				Pchar.qbook.richards9 = "done";
				Pchar.qbook.richards10 = "done";
				Pchar.qbook.richards11 = "done";
				Pchar.qbook.richards12 = "done";

				Pchar.Tgunsmith = "yes";
				Pchar.Tsailmaker = "yes";
				Pchar.Tassistent = "yes";
				Pchar.Tgovernor = "yes";
				Pchar.Ttower = "yes";
				Pchar.Cook_dead = "yes";

				LAi_QuestDelay("Tortuga_surgeons_start", 0.1);

				ChangeCharacterAddressGroup(characterFromID("Bertrand Ogeron"), "none", "", "");
				Locations[FindLocation("Tortuga_townhall")].reload.l3.disable = 0;
				locations[FindLocation("Tortuga_tower_passage")].id.label = "Tower passage";
	
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ4 = 1.5;	
				Locations[FindLocation("Tortuga_port")].locators_radius.box.box8 = 1.0;
				Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ1 = 0.9;
			Locations[FindLocation("Tortuga_gunsmith_kitchen")].locators_radius.box.box1 = 0.001;

				Locations[FindLocation("cloister_exit")].locators_radius.box.box1 = 2.0
				Locations[FindLocation("cloister_exit")].reload.l5.disable = 1;			//cloister_exit to BB_graveyard not available
			Locations[FindLocation("cloister_exit")].locators_radius.box.box2 = 0.001;

			//------------------------------------------------------------------------------------------------------------------
			//Hands Curacao + Maltains + Antigua prison conditions
				
				SetModel(characterFromID("Hands"), "bb_Hands2", "man", "man", 1.8, false);
				Pchar.beggar1 = "done"; Pchar.beggar2 = "done"; Pchar.beggar3 = "done"; Pchar.beggar4 = "done";
				Pchar.beggar5 = "done"; Pchar.beggar6 = "done"; Pchar.beggar7 = "done"; Pchar.beggar8 = "done";

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar1"), "Willemstad_port", "goto", "goto10");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar2"), "Willemstad_port", "goto", "goto15");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar3"), "Willemstad_port", "goto", "goto19");
			
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar4"), "Willemstad_town", "goto", "goto9");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar5"), "Willemstad_town", "goto", "goto27");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar6"), "Willemstad_town", "goto", "goto37");

				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar7"), "Willemstad_town_3", "officers", "reload18_1");
				ChangeCharacterAddressGroup(CharacterFromID("WR_beggar8"), "Willemstad_town_3", "goto", "goto18");

			//	LAi_QuestDelay("start_Hands_Willemstad", 0.1);		//not after Hands

				//check how these should be modified
				locations[FindLocation("Charlestown_port")].reload.l17.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l17.close_for_day = 0;	//always closed from now
				locations[FindLocation("Charlestown_port")].reload.l18.disable = 1;		//always closed from now
				Locations[FindLocation("Charlestown_port")].reload.l3.close_for_night = 0;	//townhall always open in WR, enough with Maltains close_for_day

				ChangeCharacterAddressGroup(characterFromID("Thomas Modiford"), "none", "", "");	//governor gone
				ChangeCharacterAddressGroup(characterFromID("Anne_Russel"), "Charlestown_Residence", "goto", "goto6");
				Characters[GetCharacterIndex("Anne_Russel")].dialog.CurrentNode  = "neutral";
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier3"), "Charlestown_port", "quest", "quest2");
				ChangeCharacterAddressGroup(characterFromID("Maltese_soldier4"), "Charlestown_port", "quest", "quest3");

				Pchar.unlocked_cells = "9";
				Pchar.cell9 = "unlocked"; Pchar.cell7 = "unlocked"; Pchar.cell3 = "unlocked"; 
				Pchar.cell1 = "unlocked"; Pchar.cell17 = "unlocked"; Pchar.cell15 = "unlocked";
				Pchar.cell5 = "unlocked"; Pchar.cell19 = "unlocked"; Pchar.cell2 = "unlocked";


				locations[FindLocation("Antigua_port")].models.always.locators = "StJohns_locators_JRH2";
				locations[FindLocation("Antigua_fakefort1")].reload.l4.disable = 1;	//fort to "bb_prison_port"
			//------------------------------------------------------------------------------------------------------------------
			//Eden Cayman conditions
				Locations[FindLocation("Grand_Cayman_town")].reload.l9.disable = 1;	//to townhall
				Pchar.Cayman_box1 = "locked";	//from townhall to Estate

			//------------------------------------------------------------------------------------------------------------------
			//Odell La Grenade + Citadel + Turks conditions
			
				ChangeCharacterAddressGroup(CharacterFromID("Odel"), "Smugglers_Tavern", "goto", "goto17");
				Characters[GetCharacterIndex("Odel")].dialog.CurrentNode  = "neutral";


				Locations[FindLocation("Eleuthera_shore")].models.always.locators = "Pass1_l_Eleuthera_FB1";
				Locations[FindLocation("Eleuthera_shore")].models.always.l1 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l2 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l3 = "";
				Locations[FindLocation("Eleuthera_shore")].models.always.l5 = "leverC_up";
				Locations[FindLocation("Eleuthera_shore")].models.always.l6 = "anchor_big3";

				SetCharacterShipLocation(characterFromID("wr_mummy5"), "Eleuthera_shore");	//test for Citadel Rock
				Locations[FindLocation("Eleuthera_tavern_upstairs")].vcskip = true;	//enough with bad guys on Eleuthera_shore
				Locations[FindLocation("Eleuthera_shore")].vcskip = true;		//these are replaced with quest bad guys
				ChangeCharacterAddressGroup(characterFromID("Maynard"), "Eleuthera_shore", "quest", "quest6");
				Pchar.citadel_lever = "up";
				Locations[FindLocation("Eleuthera_shore")].locators_radius.box.box36 = 0.001;
				Locations[FindLocation("Eleuthera_shore")].locators_radius.reload.reload4 = 1.0;
				Locations[FindLocation("Citadel_cave")].locators_radius.box.box1 = 0.001;
			
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug1"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug2"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug3"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug4"), "none", "", "");
				ChangeCharacterAddressGroup(characterFromID("Citadel_thug5"), "none", "", "");

				
				Locations[FindLocation("Turks_port")].models.always.l9 = "Margarita_gatebroken";
				Locations[FindLocation("Turks_port")].locators_radius.box.box10 = 0.7;		//boat back to cave
				Locations[FindLocation("Turks_tavern_kitchen")].reload.l5.disable = 1;		//roof tour only once
				Locations[FindLocation("Turks_port")].models.always.locators = "Margarita_locators_KR_closed";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gate = "";
				Locations[FindLocation("Turks_Jungle_03")].models.always.gatebroken = "Margarita_gatebroken";
				ChangeCharacterAddressGroup(characterFromID("shipwreck_trader"), "Turks_old_Fort", "goto", "goto13");
				LAi_SetCitizenType(characterFromID("shipwreck_trader"));

			//------------------------------------------------------------------------------------------------------------------
			//after all 4 missions

			//------------------------------------------------------------------------------------------------------------------
			//after Kristiania
		
			//------------------------------------------------------------------------------------------------------------------
			//careen shore conditions

			//------------------------------------------------------------------------------------------------------------------
			//IslaMona conditions

				Pchar.nation = PERSONAL_NATION;
				Pchar.Flags.Personal = 3;
				Pchar.Flags.Personal.texture = 4;

				Locations[FindLocation("IslaMona_port")].models.always.locators = "mayak_ls_JRH";
			
				Locations[FindLocation("IslaMona_port_exit")].reload.l1.disable = 1;
				Locations[FindLocation("IslaMona_port")].locators_radius.reload.boat = 0.001;
				
			//------------------------------------------------------------------------------------------------------------------
				Pchar.quest.Teach_head = "38";

				PlaySound("VOICE\ENGLISH\gr_Teach4.wav");
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];	
				link.l1.go = "how_to_return";
			break;



               case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		
               break;
	}
}
