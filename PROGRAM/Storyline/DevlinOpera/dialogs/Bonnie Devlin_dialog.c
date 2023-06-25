//#include "DIALOGS\Bonnie Devlin_dialog.h"
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
			
			dialog.snd = "Voice\ARSI\ARSI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if (pchar.quest.Bonnie_talk == "Our_first_meeting")			
			{
				dialog.snd = "Voice\ARSI\ARSI002";
				dialog.text = DLG_TEXT[2] + GetMyName(Pchar) + DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "Talk_to_Bonnie";
			}
		break;

		case "Talk_to_Bonnie":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "Talk_to_Bonnie2";
		break;

		case "Talk_to_Bonnie2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Talk_to_Bonnie3";
		break;		
		
		case "Talk_to_Bonnie3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Talk_to_Bonnie4";
		break;
		
		case "Talk_to_Bonnie4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[11] + GetMyName(Pchar) + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit_Sisters_begin_search";
		break;		

		case "getting_warmer":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit_getting_warmer";
		break;

		case "Arrived_in_Turks":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Arrived_in_Turks2";
		break;

		case "Arrived_in_Turks2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_crewmember_Turks";
		break;

		case "Asking_around_QC":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_askinground";
		break;

		case "Sailho_Blaze2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit";
			AddDialogExitQuest("Meet_Blaze_Guad4");
		break;

		case "Sailho_Blaze3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit";
			AddDialogExitQuest("Meet_Blaze_Guad6");
		break;

		case "Meeting_blaze":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Meeting_blaze2";
		break;

		case "Meeting_blaze2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Exit";
			AddDialogExitQuest("meet_Blaze_below3");
		break;

//--------------------------------------------------------------


		case "Bonnie_Debriefing":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("srsly_Blaze");
		break;

		case "optimism":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("map_search");
		break;

		case "Santiago_arrival":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("Santiago_switch_to_Blaze");
		break;

		case "Santiago_story":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("Santiago_crewmember");
		break;

//--------------------------------------------------------------

		case "Bonnie_Debriefing_Santiagofullmap":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("celebrating_Blaze");
		break;

		case "please_glue":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("glue_map2");
		break;

		case "map_now_glued":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "map_now_glued2";
		break;

		case "map_now_glued2":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			AddDialogExitQuest("To_first_X");
		break;

//--------------------------------------------------------------

		case "Domingo_arrival":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Domingo_arrival2";
		break;

		case "Domingo_arrival2":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			AddDialogExitQuest("to_Domingo_tavern");
		break;
//--------------------------------------------------------------

		case "Good_luck":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "exit";
			AddDialogExitQuest("in_Puzzle_tavern");
		break;

		case "New_look":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "New_look2";
		break;

		case "New_look2":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "New_look3";
		break;

		case "New_look3":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "exit";
			AddDialogExitQuest("Blaze_gambling_again");
		break;

		case "Bonnie_SD_Deb":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
			AddDialogExitQuest("Domingo_Debriefing4");
		break;

		case "Bonnie_SD_Deb2":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "Bonnie_SD_Deb3";
		break;

		case "Bonnie_SD_Deb3":
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			AddDialogExitQuest("Domingo_Debriefingfin");
		break;

//--------------------------------------------------------------

		case "Snakes":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			AddDialogExitQuest("Blaze_matters_hands");
		break;

//--------------------------------------------------------------

		case "Standard":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;
		
		case "Exit_Sisters_begin_search":
			SetQuestHeader("Such Devoted Sisters");
			AddQuestRecord("Such Devoted Sisters",1);
			pchar.quest.Bonnie_talk = "Sailing_for_Turks";			
			AddDialogExitQuest("And_on_to_Turks");		
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Exit_crewmember_Turks":			
			AddDialogExitQuest("crewmember_Turks");		
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Exit_askinground":			
			AddDialogExitQuest("For_Nevis_new4");		
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Exit_getting_warmer":
			Locations[FindLocation("Turks_townhall")].reload.l1.disable = 0;
			DisableFastTravel(false);
			AddQuestRecord("Such Devoted Sisters",4);
			pchar.quest.Bonnie_talk = "Sailing_for_Nevis";
			AddDialogExitQuest("And_on_to_Nevis");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
		
		case "Exit":	
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "SearchExit":
			AddDialogExitQuest("to_find_a_sister");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "SisterExit":
			AddPassenger(Pchar, characterFromID("Annabella Brin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Annabella Brin"));
			LAi_SetOfficerType(characterFromID("Annabella Brin"));
			pchar.quest.Jacks_early_days = "In_trouble_with_sisters";
			AddQuestRecord("My Early Days","4");
			AddDialogExitQuest("to_the_tavern_with_Brin");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
	}
}

