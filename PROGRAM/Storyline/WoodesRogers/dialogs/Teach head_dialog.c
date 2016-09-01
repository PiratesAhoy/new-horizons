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
		// -----------------------------------Äèàëîã ïåðâûé - ïåðâàÿ âñòðå÷à
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
			PlaySound("VOICE\ENGLISH\gr_Teach5.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "where_to";
		break;

		case "where_to":
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

		case "where_to_again":
			PlaySound("VOICE\ENGLISH\gr_Teach1.wav");
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
			//PORT ROYAL: QUEST START
			
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
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
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
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";	
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
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;

		case "4":
			//ARMORY			before mission 3
			
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");
		
			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Redmond_Port");
		
			Pchar.perks.list.BasicDefence = true;
		
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
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;
	
		case "5":
			//PORT ROYAL: KITCHEN		before mission 4
		
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");

			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Redmond_Port");

			Pchar.perks.list.BasicDefence = true;	
		
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
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";
		break;

		case "6":
			//PORT ROYAL: TERRACE		before mission 5
		
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");

			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Redmond_Port");

			Pchar.quest.wr_quest2 = "shut_up_Caroline";

			Pchar.perks.list.BasicDefence = true;	
		
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

			Locations[FindLocation("wr_shop")].reload.l3.disable = 0;//to shop entré
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
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";	
		break;

		case "7":
			//PORT ROYAL: SHOP	after distillery before bridge

			GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
			SetCharacterShipLocation(Pchar, "Redmond_Port");

			SetCurrentTime(21, 0);
			SetNextWeather("Red Sky");
			Pchar.quest.JRH_rain = "Cloudy";

			SetCharacterShipLocation(Pchar, "Redmond_port");

			Pchar.perks.list.BasicDefence = true;	
		
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
			Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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

			Locations[FindLocation("wr_shop")].reload.l3.disable = 0;//to shop entré
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
			link.l2 = DLG_TEXT[25];		//no thank you
			link.l2.go = "exit";
			link.l3 = DLG_TEXT[24];		//where_to_again
			link.l3.go = "where_to_again";	
		break;

			case "8":
				//PORT ROYAL: TAVERN STOREROOM	before mission 6
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(23.00, 0);				
				SetNextWeather("Clear");	
			
				Pchar.perks.list.BasicDefence = true;
			
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

				Locations[FindLocation("wr_shop")].reload.l3.disable = 0;//to shop entré
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;

			case "9":
				//PORT ROYAL: OUTSIDE SHIPYARD	ready for medicine collect part
				
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				Pchar.quest.outfit = "blue_uniform_hat";
			
				Pchar.perks.list.BasicDefence = true;	
			
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;

			case "10":
				//CAVE SHORE: MEDICINES COLLECTED
				//use shortcut cave shore
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(23.00, 0);				
				SetNextWeather("Clear");
				Pchar.quest.JRH_rain = "Clear";	

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
			
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;

			case "11":
				//PORT ROYAL: SHIPYARD BEFORE FARM

				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
			
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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;

			case "12":
				//SHIPS: LONG RUN TO VANE'S
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				Pchar.perks.list.BasicDefence = true;
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
			
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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;

			case "14":
				//CHOIR: LONG RUN TO VANE'S
				
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");		

				Pchar.perks.list.BasicDefence = true;
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;

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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";	

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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;

			case "15":
				//PIRATE CHURCH: BEFORE COINS
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(8, 0);
				SetNextWeather("Morning");

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;	
			
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;
		
			case "16":
				//CAVE SHORE: BEFORE WOOD TOWER
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(12.00, 0);
				SetNextWeather("Heavy Storm");
				Pchar.quest.JRH_rain = "Heavy Storm";

				Pchar.perks.list.BasicDefence = true;
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
			
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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

				ChangeCharacterAddressGroup(CharacterFromID("Herrick"), "wr_cave_shore", "goto", "goto1");
				LAi_SetStayType(CharacterFromID("Herrick"));
		
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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;
		
			case "17":
				//BLUE CAVERN: REVENGE
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(11, 0);
				SetNextWeather("Clear");

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;	
			
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;

			case "18":
				//CORVETTE YELLOW DECK: REVENGE
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(23.00, 0);				
				SetNextWeather("Clear");

				Pchar.perks.list.BasicDefence = true;
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
				
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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

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
				link.l2 = DLG_TEXT[25];		//no thank you
				link.l2.go = "exit";
				link.l3 = DLG_TEXT[24];		//where_to_again
				link.l3.go = "where_to_again";
			break;
			
			case "20":
				//LIBRARY: STUDY TO SECRET
		
				GiveShip2Character(pchar,"SloopBermuda","Marquis",-1,PIRATE,true,true);
				SetCharacterShipLocation(Pchar, "Redmond_Port");

				SetCurrentTime(7, 0);
				SetNextWeather("Morning");

				Pchar.perks.list.BasicDefence = true;	
				Pchar.perks.list.GunProfessional = true;
				Pchar.perks.list.GunFighter = true;
				Pchar.perks.list.IronWill = true;
			
				ChangeCharacterAddressGroup(characterFromID("Woodes Rogers"), "wr_study", "goto", "wr_dead");
				LAi_SetActorType(CharacterFromID("Woodes Rogers"));
				LAi_ActorSetLayMode(CharacterFromID("Woodes Rogers"));
				RemoveCharacterEquip(CharacterFromID("Woodes Rogers"), BLADE_ITEM_TYPE);
				TakeItemFromCharacter(CharacterFromID("Woodes Rogers"), "bladeA5");
				Locations[FindLocation("wr_study")].locators_radius.box.box16 = 1.0;

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
				Locations[FindLocation("Redmond_UsurerHouse")].reload.l3.label = "Woodes Rogers´ library.";

				Locations[FindLocation("Redmond_Town_01")].reload.l26.name = "door_7";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.go = "Tavern_storeroom";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.emerge = "reload1";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.autoreload = "0";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.label = "Tavern storeroom.";
				Locations[FindLocation("Redmond_Town_01")].reload.l26.disable = 0;

				locations[FindLocation("wr_shop")].id.label = "Rogers' Paintings Furniture & Weapons";
				locations[FindLocation("shipyard_stairs")].reload.l1.disable = 0;//back to shya

				Locations[FindLocation("wr_church_attic")].type = "Vane_jungle";

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
