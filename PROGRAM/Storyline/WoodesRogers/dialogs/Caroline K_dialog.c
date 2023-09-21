//#include "DIALOGS\Caroline K_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
		
		Pchar.quest.wr_questinfo = "yes";

		if ( CheckAttribute(Pchar,"quest.wr_quest2") ) 
		{
			switch(Pchar.quest.wr_quest2)
			{
				case "shut_up_Caroline":
					PlaySound("VOICE\ENGLISH\gr_wench3.wav");
					dialog.text = DLG_TEXT[192];
					link.l1 = DLG_TEXT[193];		
					link.l1.go = "exit";
				break;

				case "QC_finished":
					PlaySound("VOICE\ENGLISH\gr_wench3_pos.wav");
					dialog.text = DLG_TEXT[110];
		    			link.l1 = DLG_TEXT[111];
		    			link.l1.go = "exit";
				break;

				case "not_jump_again":
					PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
					dialog.text = DLG_TEXT[75];
		    			link.l1 = DLG_TEXT[76];
		    			link.l1.go = "exit";
					AddDialogExitQuest("leave_jump_1");
				break;

				case "QC_door_check":
					PlaySound("VOICE\ENGLISH\gr_wench3.wav");
					dialog.text = DLG_TEXT[73];
		    			link.l1 = DLG_TEXT[74];
		    			link.l1.go = "exit";
					AddDialogExitQuest("leave_town_5");
				break;

				case "under_roof":
					PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
					dialog.text = DLG_TEXT[71];
		    		    	link.l1 = DLG_TEXT[72];
		    		    	link.l1.go = "exit";
				    	AddDialogExitQuest("run_and_jump_19");
				break;

				case "blaze_knocked":
					PlaySound("VOICE\ENGLISH\defoe_psst.wav");
					dialog.text = DLG_TEXT[67];
		    			link.l1 = DLG_TEXT[68];
		    			link.l1.go = "blaze_knocked_1";
				break;

				case "3thugs_are_dead":
					PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom2.wav");
					dialog.text = DLG_TEXT[65];
		    			link.l1 = DLG_TEXT[66];		
					link.l1.go = "exit";
					AddDialogExitQuest("run_and_jump");
				break;

				case "empty_store_finished":
					PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
					dialog.text = DLG_TEXT[57];
		    			link.l1 = DLG_TEXT[58];
		    			link.l1.go = "empty_store_finished_1";
				break;

				case "store_door_closed":
					PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
					dialog.text = DLG_TEXT[51];
				    	link.l1 = DLG_TEXT[52];
				    	link.l1.go = "store_door_closed_1";
				break;

				case "store_upperdoor_talk":
					PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
					dialog.text = DLG_TEXT[49];
			    		link.l1 = DLG_TEXT[50];
			   		link.l1.go = "exit";
    			    		AddDialogExitQuest("store_upperdoor");
				break;
		
				case "store_outdoors_talk_2":
					PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
					dialog.text = DLG_TEXT[48];
				    	link.l1 = DLG_TEXT[42];
				   	link.l1.go = "store_outdoors_talk_3";
				break;

				case "knife_wound":
					PlaySound("VOICE\ENGLISH\gr_wench3_oh.wav");
					dialog.text = DLG_TEXT[200];
			    		link.l1 = DLG_TEXT[201];
			   		link.l1.go = "store_outdoors_talk";
				break;

				case "warning_thug_behind":
					PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
					dialog.text = DLG_TEXT[196];
			    		link.l1 = DLG_TEXT[197];
			   		link.l1.go = "exit";
    			    		AddDialogExitQuest("Blaze_roof_fencing_3");
				break;

				case "brothel_roof_talk":
					PlaySound("VOICE\ENGLISH\gm_crew21A.wav");
					AddDialogExitQuest("Blaze_ready_to_walk_0");			
			       		dialog.text = DLG_TEXT[39];
			        	link.l1 = DLG_TEXT[40];
			        	link.l1.go = "exit";
				break;

				case "Caroline_left_brothel_room":
					PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
					dialog.text = DLG_TEXT[35];
					PlaySound("INTERFACE\locked_window.wav");
			            	link.l1 = DLG_TEXT[36];
			            	link.l1.go = "window_talk";
				break;

				case "visit_Caroline":
					PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
					dialog.text = DLG_TEXT[12];
				        link.l1 = DLG_TEXT[4];
				        link.l1.go = "greedy";
				        link.l2 = DLG_TEXT[6];
				        link.l2.go = "suspicious";
				        link.l3 = DLG_TEXT[26];
				        link.l3.go = "will_help2";
				break;
			
				case "Caroline_talk1":
					PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
					dialog.text = DLG_TEXT[24];
					link.l1 = DLG_TEXT[25];		
					link.l1.go = "exit";
				break;
			
				case "store_disguise":
					//please shut up
					dialog.text = DLG_TEXT[192];
					link.l1 = DLG_TEXT[193];		
					link.l1.go = "exit";
				break;

				case "medicine":
					PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
					Pchar.quest.wr_quest2 = "shut_up_Caroline";
					dialog.text = DLG_TEXT[138];
					link.l1 = DLG_TEXT[139];		
					link.l1.go = "medicine1";
				break;

				case "go_on_Captain":
					PlaySound("VOICE\ENGLISH\gr_wench3.wav");
					dialog.text = DLG_TEXT[198];
					link.l1 = DLG_TEXT[199];		
					link.l1.go = "exit";
				break;

				//default:
					PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom2.wav");
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[2];
					link.l1.go = "exit_bad_guy";
					link.l2 = DLG_TEXT[23];
					link.l2.go = "hesitate";
					link.l3 = DLG_TEXT[1];
					link.l3.go = "nice_guy";

				//Log_SetStringToLog("default");	
			}
			return;
		}

		PlaySound("VOICE\ENGLISH\gr_wench3.wav");
		dialog.text = DLG_TEXT[192];
		link.l1 = DLG_TEXT[193];		
		link.l1.go = "exit";

		break;

		case "exit_bad_guy":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			DialogExit();
			ChangeCharacterReputation(pchar, -10);	//5p per rep level
		break;

		case "hesitate":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "exit_bad_guy";
			link.l2 = DLG_TEXT[22];
			link.l2.go = "hesitate2";
			link.l3 = DLG_TEXT[1];
			link.l3.go = "nice_guy";
		break;
		
		case "hesitate2":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "nice_guy";
		break;

		case "nice_guy":
			PlaySound("VOICE\ENGLISH\gr_wench3_pos.wav");
			ChangeCharacterReputation(pchar, 5);
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[16];		
			link.l1.go = "exit";	//temp brake
			AddDialogExitQuest("agreed_to_help");
		break;

//brothel downstairs
//------------------------------------------------------------
//brothel room

		case "greedy":
			PlaySound("VOICE\ENGLISH\gr_wench3_oh.wav");
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "greedy2";
		break;

		case "greedy2":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "greedy3";
		break;

		case "greedy3":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "will_help";
		break;

	//.................................................
		case "suspicious":
			PlaySound("OBJECTS\DUEL\woman_hit2.wav");
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "will_help";
		break;
	//.................................................

		case "will_help":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "will_help2";
		break;
	
		case "will_help2":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "will_help3";
		break;

		case "will_help3":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "will_help4";
		break;

		case "will_help4":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "will_help5";
		break;

		case "will_help5":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "will_help6";
		break;

		case "will_help6":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";//temp testing
			AddDialogExitQuest("ready_to_leave_brothel_room1");
		break;

//brothel room
//------------------------------------------------------------
//brothel upstairs

		case "window_talk":
			PlaySound("OBJECTS\DUEL\woman_hit3.wav");
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			AddDialogExitQuest("ready_to_break_window");
		break;

//------------------------------------------------------------
//store outdoors

		case "store_outdoors_talk":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
    			AddDialogExitQuest("afraid_to_jump");
		break;

		case "store_outdoors_talk_3":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "store_outdoors_talk_4";
		break;
	
		case "store_outdoors_talk_4":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			AddDialogExitQuest("afraid_to_jump_2");
		break;

		case "store_door_closed_1":
			PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "store_door_closed_2";
		break;

		case "store_door_closed_2":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";
			AddDialogExitQuest("search_store");
		break;

		case "empty_store_finished_1":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "empty_store_finished_2";
		break;

		case "empty_store_finished_2":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "empty_store_finished_3";
		break;

		case "empty_store_finished_3":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "exit";
			AddDialogExitQuest("leave_empty_store");
		break;

		case "blaze_knocked_1":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			AddDialogExitQuest("run_and_jump_15");
		break;
//------------------------------------------------------------

		case "store_roof_talk":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "exit";
			AddDialogExitQuest("store_roof_5");
		break;

		case "shipyard_talk":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80];
			link.l1.go = "shipyard_talk_2";
		break;

		case "shipyard_talk_2":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "shipyard_talk_3";
		break;

		case "shipyard_talk_3":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "shipyard_talk_4";
		break;

		case "shipyard_talk_4":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "shipyard_talk_5";
		break;

		case "shipyard_talk_5":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "shipyard_talk_6";
		break;

		case "shipyard_talk_6":
			PlaySound("VOICE\ENGLISH\gr_wench3_oh.wav");
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "exit";
			AddDialogExitQuest("shipyard_14");
		break;

		case "shipyard_more_talk":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "shipyard_more_talk_2";
		break;

		case "shipyard_more_talk_2":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "exit";
			AddDialogExitQuest("carpenter_tools_C");
		break;

		case "shipyard_more_talk_3":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "exit";
			AddDialogExitQuest("shipyard_20");
		break;

		case "shipyard_more_talk_4":
			Pchar.quest.JRH_sky = "";			//reset
			SetCurrentTime(22.00, 0);
			SetNextWeather("Moon Night");
		
			PlaySound("VOICE\ENGLISH\gr_wench3_pos.wav");
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "shipyard_more_talk_5";
		break;

		case "shipyard_more_talk_5":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			DialogExit();
			AddDialogExitQuest("QC_gate_1");
		break;
	
		case "QC_gate_talk_1":
			PlaySound("VOICE\ENGLISH\gr_wench3_oh.wav");
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "exit";
			AddDialogExitQuest("QC_gate_5");
		break;

		case "QC_gate_talk_2":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "exit";
			AddDialogExitQuest("QC_gate_21");
		break;

		case "QC_gate_talk_3":
			PlaySound("VOICE\ENGLISH\gr_wench3_angry.wav");
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "exit";
			AddDialogExitQuest("QC_gate_36");
		break;

		case "QC_outside_gate_talk":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "QC_outside_gate_talk_2";
		break;

		case "QC_outside_gate_talk_2":
			PlaySound("VOICE\ENGLISH\gr_wench3_pos.wav");
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "money_found";
		break;

		case "money_found":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[204];
			link.l1 = DLG_TEXT[205];
			link.l1.go = "money_found_1";
		break;

		case "money_found_1":
			PlaySound("INTERFACE\coins8.wav");
			AddMoneyToCharacter(Pchar,2372);
			dialog.text = DLG_TEXT[206];
			link.l1 = DLG_TEXT[207];
			link.l1.go = "QC_outside_gate_talk_3";
		break;

		case "QC_outside_gate_talk_3":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
			AddDialogExitQuest("QC_outside_gate_3");
		break;
	
		case "thank_you":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "thank_you2";
		break;
	
		case "thank_you2":
			dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];
			link.l1.go = "exit";
			
			AddDialogExitQuest("back_in_redmond7");
		break;

		case "wash_yourself":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "exit";
			
			AddDialogExitQuest("wash_yourself");
		break;
		
		case "ck_bedroom2":
			PlaySound("VOICE\ENGLISH\gr_wench3_pos.wav");
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			if(CheckCharacterItem(Pchar,"key8"))
			{
				link.l1.go = "ck_bedroom3";
			}
			else
			{
				link.l1.go = "ck_bedroom2_A";
			}
		break;

		case "ck_bedroom2_A":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "ck_bedroom3";
		break;

		case "ck_bedroom3":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "exit";
			
			AddDialogExitQuest("ck_bedroom3");
		break;
//pдr CK steplock hint
		case "ck_bedroom4":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[203];
			link.l1.go = "exit";

			AddDialogExitQuest("steplock_bedroom");
		break;

		case "open_well":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "open_well1";
		break;

		case "open_well1":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "open_well2";
		break;

		case "open_well2":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "open_well3";
		break;

		case "open_well3":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			link.l1.go = "exit";

			AddDialogExitQuest("open_well_done");
		break;
//-----------------------------------------------------------------------------
		case "clothes":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[132];
			link.l1 = DLG_TEXT[133];
			link.l1.go = "clothes1";
		break;

		case "clothes1":
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "clothes2";
		break;

		case "clothes2":
			dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[137];
			link.l1.go = "exit";
			AddDialogExitQuest("clothes_done");
		break;
//-----------------------------------------------------------------------------
		case "medicine1":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			GiveItem2Character(Pchar, "jewelry11");//large pearl
			GiveItem2Character(Pchar, "jewelry13");
			GiveItem2Character(Pchar, "jewelry15");
			GiveItem2Character(Pchar, "jewelry14");
			//GiveItem2Character(Pchar, "jewelry16");
			PlaySound("INTERFACE\important_item.flac");
			dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "medicine2";
		break;

		case "medicine2":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[142];
			link.l1 = DLG_TEXT[143];
			link.l1.go = "medicine3";
		break;

		case "medicine3":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[144];
			link.l1 = DLG_TEXT[145];
			link.l1.go = "medicine4";
		break;

		case "medicine4":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "exit";
			AddQuestRecord("Etherbottle", "2");
		break;

		case "warning_officers":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149];
			link.l1.go = "warning_officers1";
		break;

		case "warning_officers1":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[151];
			link.l1.go = "exit";
			AddDialogExitQuest("warning_officers_done");
		break;

		case "father_is_killed":
			PlaySound("VOICE\ENGLISH\gr_wench3.wav");
			dialog.text = DLG_TEXT[152];
			link.l1 = DLG_TEXT[153];
			link.l1.go = "father_is_killed1";
		break;

		case "father_is_killed1":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "father_is_killed2";
		break;

		case "father_is_killed2":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[156];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "exit";
			AddDialogExitQuest("shipyard_ambush4");
		break;

		case "lets_leave_the_shipyard":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[158];
			link.l1 = DLG_TEXT[159];
			link.l1.go = "lets_leave_the_shipyard1";
		break;

		case "lets_leave_the_shipyard1":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			link.l1.go = "exit";
			AddDialogExitQuest("lets_leave_the_shipyard");
		break;

		case "get_help":
			PlaySound("VOICE\ENGLISH\gr_wench3_sigh.wav");
			dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "get_help1";
		break;

		case "get_help1":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[164];
			link.l1 = DLG_TEXT[165];
			link.l1.go = "exit";
			AddDialogExitQuest("friday_room8");
		break;
		
		case "not_pirates":
			dialog.text = DLG_TEXT[166];
			link.l1 = DLG_TEXT[167];
			link.l1.go = "exit";
			AddDialogExitQuest("friday_room11");
		break;

		case "wine_cellars":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[168];
			link.l1 = DLG_TEXT[169];
			link.l1.go = "wine_cellars1";
		break;

		case "wine_cellars1":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[170];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "wine_cellars2";
		break;

		case "wine_cellars2":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[172];
			link.l1 = DLG_TEXT[173];
			link.l1.go = "exit";
			AddDialogExitQuest("friday_room15");
		break;

		case "search_study":
			PlaySound("OBJECTS\DUEL\woman_hit3.wav");
			dialog.text = DLG_TEXT[174];
			link.l1 = DLG_TEXT[175];
			link.l1.go = "search_study1";
		break;

		case "search_study1":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			dialog.text = DLG_TEXT[176];
			link.l1 = DLG_TEXT[177];
			link.l1.go = "search_study2";
		break;

		case "search_study2":
			PlaySound("VOICE\ENGLISH\gr_wench3_couldnt.wav");
			dialog.text = DLG_TEXT[178];
			link.l1 = DLG_TEXT[179];
			link.l1.go = "search_study3";
		break;

		case "search_study3":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "exit";
			AddDialogExitQuest("study_puzzle6");
		break;

		case "you_found_the_chest":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[183];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room1");
		break;

		case "what_about_the_store":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			LAi_SetActorType(CharacterFromID("wench3"));
			LAi_ActorTurnToCharacter(characterFromID("wench3"), characterFromID("grandma"));
			dialog.text = DLG_TEXT[184];
			link.l1 = DLG_TEXT[185];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans6");
		break;

		case "choose_sailors":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			LAi_SetActorType(CharacterFromID("wench3"));
			LAi_ActorTurnToCharacter(characterFromID("wench3"), characterFromID("grandma"));
			dialog.text = DLG_TEXT[194];
			link.l1 = DLG_TEXT[195];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_choose_officers");
		break;

		case "Hgold_map_to_Rogers":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[186];
			link.l1 = DLG_TEXT[187];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map16");
		break;

		case "Spotswood_to_Rogers":
			PlaySound("VOICE\ENGLISH\gr_wench3_mhm.wav");
			dialog.text = DLG_TEXT[188];
			link.l1 = DLG_TEXT[189];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map22");
		break;

		case "fine_hat":
			PlaySound("VOICE\ENGLISH\gr_wench3_aye.wav");
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Minerva"));
			dialog.text = DLG_TEXT[190];
			link.l1 = DLG_TEXT[191];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map33");
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}