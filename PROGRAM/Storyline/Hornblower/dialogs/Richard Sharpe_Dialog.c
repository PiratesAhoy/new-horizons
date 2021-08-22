//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
//			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

	
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(CheckQuestAttribute("Soldier_Company", "Foot"))
			{
				PlaySound("VOICE\ENGLISH\Sharpe01.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}
			if(CheckQuestAttribute("Soldier_Company", "Sergeant"))
			{
				PlaySound("VOICE\ENGLISH\Sharpe05.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}
			if(CheckQuestAttribute("Soldier_Company", "Lieutenant"))
			{
				PlaySound("VOICE\ENGLISH\Sharpe06.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}
			if(CheckQuestAttribute("Soldier_Company", "Rifles"))
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "our_first_meeting":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "our_first_meeting2";
		break;

		case "our_first_meeting2":
			PlaySound("VOICE\ENGLISH\Sharpe01.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "our_first_meeting3";
		break;		

		case "our_first_meeting3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "our_first_meeting4";
		break;
		
		case "our_first_meeting4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "our_first_meeting5";
		break;

		case "our_first_meeting5":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "our_first_meeting6";
		break;

		case "our_first_meeting6":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "our_first_meeting7";
		break;

		case "our_first_meeting7":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "our_first_meeting8";
		break;

		case "our_first_meeting8":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "our_first_meeting9";
		break;

		case "our_first_meeting9":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit_our_first_meeting";
		break;

		case "Exit_our_first_meeting":
			AddDialogExitQuest("Capture_some_Frenchmen");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "the_french_are_here":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_the_french_are_here";
		break;

		case "Exit_the_french_are_here":
			AddDialogExitQuest("Capture_some_Frenchmen3");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "a_quiet_catch":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "a_quiet_catch2";
		break;

		case "a_quiet_catch2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_a_quiet_catch";
		break;

		case "Exit_a_quiet_catch":
			AddDialogExitQuest("Now_take_the_ship");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Larr_no_knife":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit_Larr_no_knife";
		break;

		case "Exit_Larr_no_knife":
			AddDialogExitQuest("Pellew_takes_Charge");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Orders_for_Higgins":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Orders_for_Higgins";
		break;

		case "Exit_Orders_for_Higgins":
			AddDialogExitQuest("Pellew_makes_suggestion");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Looking_at_Ships":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Looking_at_Ships2";
		break;

		case "Looking_at_Ships2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit_Looking_at_Ships";
		break;

		case "Exit_Looking_at_Ships":
			AddDialogExitQuest("Into_the_Fake_Pirate_House");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Options_available":
			if(CheckQuestAttribute("Find_Pirate_Camp", "After_the_Academy"))
			{ 
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Exit_Option_available_Back_Room";
			}
			else
			{
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_Options_available";
			link.l2 = DLG_TEXT[40];
			link.l2.go = "Exit_Options_available";
			}
		break;

		case "Exit_Options_available":
			AddDialogExitQuest("Return_to_the_Tunnel");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Option_available_Back_Room":
			AddDialogExitQuest("Return_to_the_Tunnel_after_Academy");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Tunnel_tasks_complete":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Tunnel_tasks_complete2";
		break;

		case "Tunnel_tasks_complete2":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Tunnel_tasks_complete";
		break;

		case "Exit_Tunnel_tasks_complete":
			AddDialogExitQuest("Into_the_Academy_job_done");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Tunnel_tasks_complete_THIRD":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Tunnel_tasks_complete_THIRD2";
		break;

		case "Tunnel_tasks_complete_THIRD2":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Tunnel_tasks_complete_THIRD";
		break;

		case "Exit_Tunnel_tasks_complete_THIRD":
			AddDialogExitQuest("Into_the_Academy_job_done_THIRD");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Academy_task_complete":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Exit_Academy_task_complete";
		break;

		case "Exit_Academy_task_complete":
			AddDialogExitQuest("Now_find_pirate_camp");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "back_in_Charlestown":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "back_in_Charlestown2";
		break;

		case "back_in_Charlestown2":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit_back_in_Charlestown";
		break;

		case "Exit_back_in_Charlestown":
			AddDialogExitQuest("Yet_another_Meeting");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "You_lost_a_friend":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "You_lost_a_friend2";
		break;

		case "You_lost_a_friend2":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Exit_You_lost_a_friend";
		break;

		case "Exit_You_lost_a_friend":
			AddDialogExitQuest("Back_to_ship_and_Oxbay");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_new_detachment":
			PlaySound("VOICE\ENGLISH\Sharpe05.wav");
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "A_new_detachment2";
		break;

		case "A_new_detachment2":
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "A_new_detachment3";
		break;

		case "A_new_detachment3":
			PlaySound("VOICE\ENGLISH\Sharpe02.wav");
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "A_new_detachment4";
		break;

		case "A_new_detachment4":
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "A_new_detachment5";
		break;

		case "A_new_detachment5":
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "Exit_A_new_detachment";
		break;

		case "Exit_A_new_detachment":
			AddDialogExitQuest("Wellard_in_tow2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "What_rope_bridge":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "What_rope_bridge2";
		break;

		case "What_rope_bridge2":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Exit_What_rope_bridge";
		break;

		case "Exit_What_rope_bridge":
			AddDialogExitQuest("decide_to_try_the_bridge");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bad_just_the_two_of_us":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Bad_just_the_two_of_us";
		break;

		case "Exit_Bad_just_the_two_of_us":
			AddDialogExitQuest("Bad_Looking_at_bridge");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "damit_they've_seen_us":
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "damit_they've_seen_us2";
		break;

		case "damit_they've_seen_us2":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "Exit_damit_they've_seen_us";
		break;

		case "Exit_damit_they've_seen_us":
			AddDialogExitQuest("Bad_Set_up_the_attack2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "just_the_two_of_us":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_just_the_two_of_us";
		break;

		case "Exit_just_the_two_of_us":
			AddDialogExitQuest("Looking_at_bridge");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "get_into_bridge_position":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "get_into_bridge_position2";
		break;

		case "get_into_bridge_position2":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Exit_get_into_bridge_position";
		break;

		case "Exit_get_into_bridge_position":
			AddDialogExitQuest("now_start_shooting");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "we_have_the_bridge":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "Exit_we_have_the_bridge";
		break;

		case "Exit_we_have_the_bridge":
			AddDialogExitQuest("bring_up_the_rest");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_ship_retaken":
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "Exit_The_ship_retaken";
		break;

		case "Exit_The_ship_retaken":
			AddDialogExitQuest("Sharpe_in_danger2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "What_happened_there":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "What_happened_there2";
		break;

		case "What_happened_there2":
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "Exit_What_happened_there";
		break;

		case "Exit_What_happened_there":
			AddDialogExitQuest("Quelp_saved_Sharpe");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "an_observation":
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "an_observation2";
		break;

		case "an_observation2":
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "an_observation3";
		break;

		case "an_observation3":
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "an_observation4";
		break;

		case "an_observation4":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "an_observation5";
		break;

		case "an_observation5":
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "Exit_an_observation";
		break;

		case "Exit_an_observation":
			AddDialogExitQuest("the_burial_party");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Answer_with_Name":
			PlaySound("VOICE\ENGLISH\Sharpe05.wav");
			dialog.text = DLG_TEXT[183];
			link.l1.go = "Exit_Answer_with_Name";
		break;

		case "Exit_Answer_with_Name":
			AddDialogExitQuest("Promotion_confirmed");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Need_information":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "Need_information2";
		break;

		case "Need_information2":
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "Need_information3";
		break;

		case "Need_information3":
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "Exit_Need_information";
		break;

		case "Exit_Need_information":
			AddDialogExitQuest("Chadd_knows_all");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "To_Cayman_it_is":
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "To_Cayman_it_is2";
		break;

		case "To_Cayman_it_is2":
			dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Exit_To_Cayman_it_is";
		break;

		case "Exit_To_Cayman_it_is":
			AddDialogExitQuest("On_route_to_Cayman_or_Charlestown");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Cayman_start_where":
			dialog.text = DLG_TEXT[196];
			link.l1 = DLG_TEXT[197];
			link.l1.go = "Exit_Cayman_start_where";
		break;

		case "Exit_Cayman_start_where":
			AddDialogExitQuest("Looking_in_Cayman2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Who_was_that":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "Who_was_that2";
		break;

		case "Who_was_that2":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "Who_was_that3";
		break;

		case "Who_was_that3":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "Who_was_that4";
		break;

		case "Who_was_that4":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "Exit_Who_was_that";
		break;

		case "Exit_Who_was_that":
			AddDialogExitQuest("Continue_search_for_Quelp");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Still_not_happy":
			dialog.text = DLG_TEXT[198];
			link.l1 = DLG_TEXT[199];
			link.l1.go = "Still_not_happy2";
		break;

		case "Still_not_happy2":
			dialog.text = DLG_TEXT[200];
			link.l1 = DLG_TEXT[201];
			link.l1.go = "Exit_Still_not_happy";
		break;

		case "Exit_Still_not_happy":
			AddDialogExitQuest("Sharpe_Quelp_Antigua");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "In_the_outskirts":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "In_the_outskirts2";
		break;

		case "In_the_outskirts2":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114];
			link.l1.go = "Exit_In_the_outskirts";
		break;

		case "Exit_In_the_outskirts":
			AddDialogExitQuest("Go_to_Mr_Matthews");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Send_out_snipers":
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "Send_out_snipers2";
		break;

		case "Send_out_snipers2":
			dialog.text = DLG_TEXT[110];
			link.l1.go = "Exit_Send_out_snipers";
		break;

		case "Exit_Send_out_snipers":
			AddDialogExitQuest("Matthews_firing_instructions");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Midshipman_again":
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			link.l1.go = "Midshipman_again2";
		break;

		case "Midshipman_again2":
			dialog.text = DLG_TEXT[117];
			link.l1 = DLG_TEXT[118];
			link.l1.go = "Midshipman_again3";
		break;

		case "Midshipman_again3":
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[120];
			link.l1.go = "Exit_Midshipman_again";
		break;

		case "Exit_Midshipman_again":
			AddDialogExitQuest("Follow_the_French");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Protective_Ring":
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "Exit_Protective_Ring";
		break;

		case "Exit_Protective_Ring":
			AddDialogExitQuest("Riflemen_executed");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Some_rear_guard":
			dialog.text = DLG_TEXT[228];
			link.l1 = DLG_TEXT[229];
			link.l1.go = "Some_rear_guard2";
		break;

		case "Some_rear_guard2":
			dialog.text = DLG_TEXT[230];
			link.l1 = DLG_TEXT[231];
			link.l1.go = "Exit_Some_rear_guardA";
			link.l2 = DLG_TEXT[232];
			link.l2.go = "Exit_Some_rear_guardB";
		break;

		case "Exit_Some_rear_guardA":
			AddDialogExitQuest("turn_to_French_gun");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Some_rear_guardB":
			AddDialogExitQuest("Prison_with_Sharpe");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "In_the_French_prison":
			dialog.text = DLG_TEXT[233];
			link.l1 = DLG_TEXT[234];
			link.l1.go = "In_the_French_prison2";
		break;

		case "In_the_French_prison2":
			dialog.text = DLG_TEXT[235];
			link.l1 = DLG_TEXT[236];
			link.l1.go = "Exit";
		break;

		case "Shot_in_the_back":
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "Shot_in_the_back2";
		break;

		case "Shot_in_the_back2":
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "Shot_in_the_back3";
		break;

		case "Shot_in_the_back3":
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "Shot_in_the_back4";
		break;

		case "Shot_in_the_back4":
			dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "Shot_in_the_back5";
		break;

		case "Shot_in_the_back5":
			dialog.text = DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			link.l1.go = "Shot_in_the_back6";
		break;

		case "Shot_in_the_back6":
			dialog.text = DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "Shot_in_the_back7";
		break;

		case "Shot_in_the_back7":
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "Exit_Shot_in_the_back";
		break;

		case "Exit_Shot_in_the_back":
			AddDialogExitQuest("Quelp_moves_them_along");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bury_the_men":
			dialog.text = DLG_TEXT[136];
			link.l1.go = "Exit_Bury_the_men";
		break;

		case "Exit_Bury_the_men":
			AddDialogExitQuest("Quelp_leads_to_the_beach");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Choice_of_action":
			dialog.text = DLG_TEXT[151];
			link.l1 = DLG_TEXT[152];
			link.l1.go = "Exit_Follow_Quelp";
			link.l2 = DLG_TEXT[153];
			link.l2.go = "Shout_then_Follow_Quelp";
			link.l3 = DLG_TEXT[158];
			link.l3.go = "A_change_of_plan";
			link.l4 = DLG_TEXT[162];
			link.l4.go = "Confrontation";
		break;

		case "Shout_then_Follow_Quelp":
			dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "Shout_then_Follow_Quelp2";
		break;

		case "Shout_then_Follow_Quelp2":
			dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "Exit_Follow_Quelp";
		break;

		case "Exit_Follow_Quelp":
			LAi_ActorGoToLocator(characterFromID("Lt. Uriah Quelp"), "reload", "reload1_back", "",0.0);
			AddDialogExitQuest("Where_are_the_French");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "A_change_of_plan":
			dialog.text = DLG_TEXT[141];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "A_change_of_plan2";
		break;

		case "A_change_of_plan2":
			dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "A_change_of_plan3";
		break;

		case "A_change_of_plan3":
			dialog.text = DLG_TEXT[145];
			link.l1 = DLG_TEXT[159];
			link.l1.go = "A_change_of_plan4";
		break;

		case "A_change_of_plan4":
			dialog.text = DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			link.l1.go = "Exit_A_change_of_plan";
		break;

		case "Exit_A_change_of_plan":
			AddDialogExitQuest("We_will_go_another_way");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Catch_the_French_out":
			dialog.text = DLG_TEXT[172];
			link.l1 = DLG_TEXT[158];
			link.l1.go = "Catch_the_French_out2";
		break;

		case "Catch_the_French_out2":
			dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "Catch_the_French_out3";
		break;

		case "Catch_the_French_out3":
			dialog.text = DLG_TEXT[175];
			link.l1 = DLG_TEXT[176];
			link.l1.go = "Catch_the_French_out4";
		break;

		case "Catch_the_French_out4":
			dialog.text = DLG_TEXT[177];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "Catch_the_French_out5";
		break;

		case "Catch_the_French_out5":
			dialog.text = DLG_TEXT[179];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Catch_the_French_out";
		break;

		case "Exit_Catch_the_French_out":
			AddDialogExitQuest("Our_ruse_begins");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "It_won't_be_long":
			dialog.text = DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "It_won't_be_long2";
		break;

		case "It_won't_be_long2":
			dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "It_won't_be_long3";
		break;

		case "It_won't_be_long3":
			ChangeCharacterAddressGroup(characterFromID("Rifleman Mansfield"), "Antigua_shore", "reload", "reload2_back");
			dialog.text = DLG_TEXT[237];
			link.l1 = DLG_TEXT[238];
			link.l1.go = "Exit_It_won't_be_long";
		break;

		case "Exit_It_won't_be_long":
			LAi_SetOfficerType(characterFromID("Rifleman Mansfield"));
			AddDialogExitQuest("Mansfield_arrives");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Confrontation":
			LAi_ActorGoToLocator(characterFromID("Lt. Uriah Quelp"), "reload", "reload1_back", "",0.0);
			dialog.text = DLG_TEXT[141];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "Confrontation2";
		break;

		case "Confrontation2":
			dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "Confrontation3";
		break;

		case "Confrontation3":
			dialog.text = DLG_TEXT[145];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "Confrontation3A";
		break;

		case "Confrontation3A":
			dialog.text = DLG_TEXT[169];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "Confrontation4";
		break;

		case "Confrontation4":
			dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "Confrontation5";
		break;

		case "Confrontation5":
			dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "Confrontation6";
		break;

		case "Confrontation6":
			dialog.text = DLG_TEXT[164];
			link.l1 = DLG_TEXT[165];
			link.l1.go = "Confrontation7";
		break;

		case "Confrontation7":
			dialog.text = DLG_TEXT[166];
			link.l1 = DLG_TEXT[167];
			link.l1.go = "Exit_Confrontation";
		break;

		case "Exit_Confrontation":
			AddDialogExitQuest("Confront_Quelp_on_beach");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Somethings_wrong":
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "Exit_Somethings_wrong";
		break;

		case "Exit_Somethings_wrong":
			AddDialogExitQuest("Quelp_returns_from_beach");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_bodies":
			dialog.text = DLG_TEXT[139];
			link.l1 = DLG_TEXT[140];
			link.l1.go = "The_bodies2";
		break;

		case "The_bodies2":
			dialog.text = DLG_TEXT[141];
			link.l1 = DLG_TEXT[142];
			link.l1.go = "The_bodies3";
		break;

		case "The_bodies3":
			dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "The_bodies4";
		break;

		case "The_bodies4":
			dialog.text = DLG_TEXT[145];
			link.l1 = DLG_TEXT[146];
			link.l1.go = "Exit_The_bodies";
		break;

		case "Exit_The_bodies":
			AddDialogExitQuest("a_group_discussion2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Prepare_counter_attack":
			dialog.text = DLG_TEXT[147];
			link.l1 = DLG_TEXT[148];
			link.l1.go = "Prepare_counter_attack2";
		break;

		case "Prepare_counter_attack2":
			dialog.text = DLG_TEXT[149];
			link.l1 = DLG_TEXT[150];
			link.l1.go = "Exit_Prepare_counter_attack";
		break;

		case "Exit_Prepare_counter_attack":
			AddDialogExitQuest("Back_to_the_Valley");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Safe_only_just":
			dialog.text = DLG_TEXT[184];
			link.l1 = DLG_TEXT[185];
			link.l1.go = "Safe_only_just2";
		break;

		case "Safe_only_just2":
			dialog.text = DLG_TEXT[186];
			link.l1 = DLG_TEXT[187];
			link.l1.go = "Exit_Safe_only_just";
		break;

		case "Exit_Safe_only_just":
			AddDialogExitQuest("Wellesley_Fight_over2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Doesn't_look_like_much":
			dialog.text = DLG_TEXT[188];
			link.l1 = DLG_TEXT[189];
			link.l1.go = "Exit_Doesn't_look_like_much";
		break;

		case "Exit_Doesn't_look_like_much":
			AddDialogExitQuest("The_French_assualt");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_battle_is_won":
			dialog.text = DLG_TEXT[190];
			link.l1 = DLG_TEXT[191];
			link.l1.go = "Exit_The_battle_is_won";
		break;

		case "Exit_The_battle_is_won":
			AddDialogExitQuest("Report_to_the Colonel");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_parting_of_the_ways":
			dialog.text = DLG_TEXT[192];
			link.l1 = DLG_TEXT[193];
			link.l1.go = "The_parting_of_the_ways2";
		break;

		case "The_parting_of_the_ways2":
			dialog.text = DLG_TEXT[194];
			link.l1 = DLG_TEXT[195];
			link.l1.go = "Exit_The_parting_of_the_ways";
		break;

		case "Exit_The_parting_of_the_ways":
			AddDialogExitQuest("Off_to_Greenford_with_Documents");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "With_Sharpe_to_Oxbay":
			dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[203];
			link.l1.go = "With_Sharpe_to_Oxbay2";
		break;

		case "With_Sharpe_to_Oxbay2":
			dialog.text = DLG_TEXT[204];
			link.l1 = DLG_TEXT[205];
			link.l1.go = "With_Sharpe_to_Oxbay3";
		break;

		case "With_Sharpe_to_Oxbay3":
			dialog.text = DLG_TEXT[206];
			link.l1 = DLG_TEXT[207];
			link.l1.go = "With_Sharpe_to_Oxbay4";
		break;

		case "With_Sharpe_to_Oxbay4":
			dialog.text = DLG_TEXT[208];
			link.l1 = DLG_TEXT[209];
			link.l1.go = "With_Sharpe_to_Oxbay5";
		break;

		case "With_Sharpe_to_Oxbay5":
			dialog.text = DLG_TEXT[210];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "With_Sharpe_to_Oxbay6";
		break;

		case "With_Sharpe_to_Oxbay6":
			dialog.text = DLG_TEXT[211];
			link.l1 = DLG_TEXT[212];
			link.l1.go = "With_Sharpe_to_Oxbay7";
		break;

		case "With_Sharpe_to_Oxbay7":
			dialog.text = DLG_TEXT[213];
			link.l1 = DLG_TEXT[214];
			link.l1.go = "With_Sharpe_to_Oxbay8";
		break;

		case "With_Sharpe_to_Oxbay8":
			dialog.text = DLG_TEXT[215];
			link.l1 = DLG_TEXT[216];
			link.l1.go = "Exit_With_Sharpe_to_Oxbay";
		break;

		case "Exit_With_Sharpe_to_Oxbay":
			AddDialogExitQuest("Sharpe_Harper_to_Oxbay");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Which_way_to_Lighthouse":
			dialog.text = DLG_TEXT[217];
			link.l1 = DLG_TEXT[218];
			link.l1.go = "Which_way_to_Lighthouse2";
		break;

		case "Which_way_to_Lighthouse2":
			dialog.text = DLG_TEXT[219];
			link.l1 = DLG_TEXT[220];
			link.l1.go = "Which_way_to_Lighthouse3";
		break;

		case "Which_way_to_Lighthouse3":
			dialog.text = DLG_TEXT[221];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Which_way_to_Lighthouse";
		break;

		case "Exit_Which_way_to_Lighthouse":
			AddDialogExitQuest("Sharpe_Oxbay_lighthouse");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Lighthouse_dead":
			dialog.text = DLG_TEXT[222];
			link.l1 = DLG_TEXT[223];
			link.l1.go = "Exit_Lighthouse_dead";
		break;

		case "Exit_Lighthouse_dead":
			AddDialogExitQuest("The_French_Dead_Lighthouse");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Unsolved_problem":
			dialog.text = DLG_TEXT[224];
			link.l1 = DLG_TEXT[225];
			link.l1.go = "Unsolved_problem2";
		break;

		case "Unsolved_problem2":
			dialog.text = DLG_TEXT[226];
			link.l1 = DLG_TEXT[227];
			link.l1.go = "Exit_Unsolved_problem";
		break;

		case "Exit_Unsolved_problem":
			AddDialogExitQuest("Back_to_Maria_at_Greenford");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Where_is_Hogan":
			dialog.text = DLG_TEXT[239];
			link.l1 = DLG_TEXT[240];
			link.l1.go = "Where_is_Hogan2";
		break;

		case "Where_is_Hogan2":
			dialog.text = DLG_TEXT[241];
			link.l1 = DLG_TEXT[242];
			link.l1.go = "Where_is_Hogan3";
		break;

		case "Where_is_Hogan3":
			dialog.text = DLG_TEXT[243];
			link.l1 = DLG_TEXT[244];
			link.l1.go = "Where_is_Hogan4";
		break;

		case "Where_is_Hogan4":
			dialog.text = DLG_TEXT[245];
			link.l1 = DLG_TEXT[246];
			link.l1.go = "Where_is_Hogan5";
		break;

		case "Where_is_Hogan5":
			dialog.text = DLG_TEXT[247];
			link.l1 = DLG_TEXT[248];
			link.l1.go = "Where_is_Hogan6";
		break;

		case "Where_is_Hogan6":
			dialog.text = DLG_TEXT[249];
			link.l1 = DLG_TEXT[250];
			link.l1.go = "Exit_Where_is_Hogan";
		break;

		case "Exit_Where_is_Hogan":
			AddDialogExitQuest("Sea_for_Charlestown_and Friends");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Off_to_meet_Teresa":
			dialog.text = DLG_TEXT[251];
			link.l1 = DLG_TEXT[252];
			link.l1.go = "Off_to_meet_Teresa2";
		break;

		case "Off_to_meet_Teresa2":
			dialog.text = DLG_TEXT[253];
			link.l1 = DLG_TEXT[254];
			link.l1.go = "Off_to_meet_Teresa3";
		break;

		case "Off_to_meet_Teresa3":
			dialog.text = DLG_TEXT[255];
			link.l1 = DLG_TEXT[256];
			link.l1.go = "Off_to_meet_Teresa4";
		break;

		case "Off_to_meet_Teresa4":
			dialog.text = DLG_TEXT[257];
			link.l1 = DLG_TEXT[258];
			link.l1.go = "Off_to_meet_Teresa5";
		break;

		case "Off_to_meet_Teresa5":
			dialog.text = DLG_TEXT[259];
			link.l1 = DLG_TEXT[260];
			link.l1.go = "Off_to_meet_Teresa6";
		break;

		case "Off_to_meet_Teresa6":
			dialog.text = DLG_TEXT[261];
			link.l1 = DLG_TEXT[262];
			link.l1.go = "Off_to_meet_Teresa7";
		break;

		case "Off_to_meet_Teresa7":
			dialog.text = DLG_TEXT[263];
			link.l1 = DLG_TEXT[264];
			link.l1.go = "Exit_Off_to_meet_Teresa";
		break;

		case "Exit_Off_to_meet_Teresa":
			AddDialogExitQuest("To_see_Teresa");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Introduce_Teresa":
			dialog.text = DLG_TEXT[265];
			link.l1 = DLG_TEXT[266];
			link.l1.go = "Exit_Introduce_Teresa";
		break;

		case "Exit_Introduce_Teresa":
			AddDialogExitQuest("Teresa_speaks_up");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hogan_Quest_Chatter_Sharpe":
			dialog.text = DLG_TEXT[267];
			link.l1 = DLG_TEXT[268];
			link.l1.go = "Exit_Hogan_Quest_Chatter_Sharpe";
		break;

		case "Exit_Hogan_Quest_Chatter_Sharpe":
			AddDialogExitQuest("Hogan_Step_four");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Run_to_bushes":
			dialog.text = DLG_TEXT[269];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Run_to_bushes";
		break;

		case "Exit_Run_to_bushes":
			AddDialogExitQuest("Hogan_Step_sixAAA");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "I_heard_them":
			dialog.text = DLG_TEXT[270];
			link.l1 = DLG_TEXT[271];
			link.l1.go = "I_heard_them2";
		break;

		case "I_heard_them2":
			dialog.text = DLG_TEXT[272];
			link.l1 = DLG_TEXT[273];
			link.l1.go = "Exit_I_heard_them";
		break;

		case "Exit_I_heard_them":
			AddDialogExitQuest("Hogan_Step_twelve");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Even_more_Troops":
			dialog.text = DLG_TEXT[274];
			link.l1 = DLG_TEXT[275];
			link.l1.go = "Exit_Even_more_Troops";
		break;

		case "Exit_Even_more_Troops":
			AddDialogExitQuest("This_is_really_strange");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We'll_fight_from_hill":
			dialog.text = DLG_TEXT[276];
			link.l1 = DLG_TEXT[277];
			link.l1.go = "We'll_fight_from_hill2";
		break;

		case "We'll_fight_from_hill2":
			dialog.text = DLG_TEXT[278];
			link.l1 = DLG_TEXT[279];
			link.l1.go = "We'll_fight_from_hill3";
		break;

		case "We'll_fight_from_hill3":
			LAi_ActorRunToLocator(characterFromID("Patrick Harper"), "reload", "houseSp1", "",0.0);
			LAi_ActorRunToLocator(characterFromID("Rifleman Cooper"), "reload", "houseSp1", "",0.0);
			dialog.text = DLG_TEXT[280];
			link.l1 = DLG_TEXT[281];
			link.l1.go = "We'll_fight_from_hill4";
		break;

		case "We'll_fight_from_hill4":
			dialog.text = DLG_TEXT[282];
			link.l1 = DLG_TEXT[283];
			link.l1.go = "Exit_We'll_fight_from_hill";
		break;

		case "Exit_We'll_fight_from_hill":
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			AddDialogExitQuest("Collect_Harper_Cooper");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Glad_you're_here":
			dialog.text = DLG_TEXT[284];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Glad_you're_here";
		break;

		case "Exit_Glad_you're_here":
			AddDialogExitQuest("Harper_explains_Cooper");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Mop_up_time":
			dialog.text = DLG_TEXT[285];
			link.l1 = DLG_TEXT[286];
			link.l1.go = "Exit_Mop_up_time";
		break;

		case "Exit_Mop_up_time":
			AddDialogExitQuest("The_local_battle_ends");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bury_Captain_Murray":
			dialog.text = DLG_TEXT[287];
			link.l1 = DLG_TEXT[288];
			link.l1.go = "Bury_Captain_Murray2";
		break;

		case "Bury_Captain_Murray2":
			dialog.text = DLG_TEXT[289];
			link.l1 = DLG_TEXT[290];
			link.l1.go = "Exit_Bury_Captain_Murray";
		break;

		case "Exit_Bury_Captain_Murray":
			AddDialogExitQuest("Back_into_uniform");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Back_to_Hotspur_wounded":
			dialog.text = DLG_TEXT[291];
			link.l1 = DLG_TEXT[292];
			link.l1.go = "Exit_Back_to_Hotspur_wounded";
		break;

		case "Exit_Back_to_Hotspur_wounded":
			AddDialogExitQuest("Back_into_more_trouble");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Do_what_you_can":
			dialog.text = DLG_TEXT[293];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Do_what_you_can";
		break;

		case "Exit_Do_what_you_can":
			AddDialogExitQuest("To_the_woods");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Plan_to_get_home":
			dialog.text = DLG_TEXT[294];
			link.l1 = DLG_TEXT[295];
			link.l1.go = "Plan_to_get_home2";
		break;

		case "Plan_to_get_home2":
			dialog.text = DLG_TEXT[296];
			link.l1 = DLG_TEXT[297];
			link.l1.go = "Exit_Plan_to_get_home";
		break;

		case "Exit_Plan_to_get_home":
			AddDialogExitQuest("Jungles_then_beach");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Escaping_to_ship":
			dialog.text = DLG_TEXT[298];
			link.l1 = DLG_TEXT[299];
			link.l1.go = "Exit";
		break;

		case "Back_to_barracks":
			dialog.text = DLG_TEXT[300];
			link.l1 = DLG_TEXT[301];
			link.l1.go = "Exit_Back_to_barracks";
		break;

		case "Exit_Back_to_barracks":
			AddDialogExitQuest("Signal_from_flagship");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Seen_this_before":
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "reload", "reload1_back", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "reload", "reload1_back", "",0.0);
			dialog.text = DLG_TEXT[302];
			link.l1 = DLG_TEXT[303];
			link.l1.go = "Seen_this_before2";
		break;

		case "Seen_this_before2":
			dialog.text = DLG_TEXT[304];
			link.l1 = DLG_TEXT[305];
			link.l1.go = "Seen_this_before3";
		break;

		case "Seen_this_before3":
			ChangeCharacterAddress(characterFromID("Rifleman Cooper"), "None", "");
			ChangeCharacterAddress(characterFromID("Patrick Harper"), "None", "");
			dialog.text = DLG_TEXT[306];
			link.l1 = DLG_TEXT[307];
			link.l1.go = "Exit_Seen_this_before";
		break;

		case "Exit_Seen_this_before":
			AddDialogExitQuest("Finally_go_home");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Good_eye":
			dialog.text = DLG_TEXT[308];
			link.l1 = DLG_TEXT[309];
			link.l1.go = "Good_eye2";
		break;

		case "Good_eye2":
			dialog.text = DLG_TEXT[277];
			link.l1 = DLG_TEXT[310];
			link.l1.go = "Good_eye3";
		break;

		case "Good_eye3":
			dialog.text = DLG_TEXT[311];
			link.l1 = DLG_TEXT[312];
			link.l1.go = "Good_eye4";
		break;

		case "Good_eye4":
			dialog.text = DLG_TEXT[313];
			link.l1 = DLG_TEXT[314];
			link.l1.go = "Good_eye5";
		break;

		case "Good_eye5":
			dialog.text = DLG_TEXT[315];
			link.l1 = DLG_TEXT[301];
			link.l1.go = "Exit_Good_eye";
		break;

		case "Exit_Good_eye":
			AddDialogExitQuest("Other_way_to_Lighthouse");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "lets_talk_to_wolfe":
			dialog.text = DLG_TEXT[316];
			link.l1 = DLG_TEXT[317];
			link.l1.go = "exit";
			AddDialogExitQuest("interrogate_wolfe1");
		break;

		case "bad_cop":
			dialog.text = DLG_TEXT[318];
			link.l1 = DLG_TEXT[319];
			link.l1.go = "exit";
			AddDialogExitQuest("interrogate_wolfe3");
		break;

		case "bad_cop2":
			dialog.text = DLG_TEXT[320];
			link.l1 = DLG_TEXT[321];
			link.l1.go = "exit";
			AddDialogExitQuest("off_to_meet_quelp");
		break;

		case "bring_Harper_Haggman":
			dialog.text = DLG_TEXT[322];
			link.l1 = DLG_TEXT[323];
			link.l1.go = "exit";
			AddDialogExitQuest("proceed_to_jungle");
		break;

		case "Harper_Haggman_cover":
			dialog.text = DLG_TEXT[324];
			link.l1 = DLG_TEXT[325];
			link.l1.go = "exit";
			AddDialogExitQuest("quelp_at_windmill2");
		break;

		case "theyre_not_British":
			dialog.text = DLG_TEXT[326];
			link.l1 = DLG_TEXT[327];
			link.l1.go = "exit";
			AddDialogExitQuest("Harper_Haggman_fire");
		break;

		case "no_officer":
			dialog.text = DLG_TEXT[328];
			link.l1 = DLG_TEXT[329];
			link.l1.go = "no_officer2";
		break;

		case "no_officer2":
			dialog.text = DLG_TEXT[330];
			link.l1 = DLG_TEXT[331];
			link.l1.go = "no_officer3";
		break;

		case "no_officer3":
			dialog.text = DLG_TEXT[332];
			link.l1 = DLG_TEXT[333];
			link.l1.go = "exit";
		break;

		case "wrong_way":
			dialog.text = DLG_TEXT[334];
			link.l1 = DLG_TEXT[335];
			link.l1.go = "exit";
		break;

		case "here_come_reinforcements":
			dialog.text = DLG_TEXT[336];
			link.l1 = DLG_TEXT[337];
			link.l1.go = "exit";
		break;

		case "attack_voltigeurs":
			dialog.text = DLG_TEXT[338];
			link.l1 = DLG_TEXT[339];
			link.l1.go = "exit";
		break;

		case "meant_to_ask_you":
			dialog.text = DLG_TEXT[340];
			link.l1 = DLG_TEXT[341];
			link.l1.go = "meant_to_ask_you2";
		break;

		case "meant_to_ask_you2":
			dialog.text = DLG_TEXT[342];
			link.l1 = DLG_TEXT[343];
			link.l1.go = "meant_to_ask_you3";
		break;

		case "meant_to_ask_you3":
			dialog.text = DLG_TEXT[344];
			link.l1 = DLG_TEXT[345];
			link.l1.go = "exit";
		break;

		case "leaving_for_Europe":
			dialog.text = DLG_TEXT[346];
			link.l1 = DLG_TEXT[347];
			link.l1.go = "leaving_for_Europe2";
		break;

		case "leaving_for_Europe2":
			dialog.text = DLG_TEXT[348];
			link.l1 = DLG_TEXT[349];
			link.l1.go = "exit";
		break;
	}
}
