//#include "DIALOGS\Tom Morgan_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			Dialog.snd = "voice\PADI\PADI001";

		break;
	
		case "neutral":
			PlaySound("VOICE\ENGLISH\gm_crew16A.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
		break;

		case "story":
			PlaySound("VOICE\ENGLISH\pir_capP.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "story1";
		break;

		case "story1":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "story2";
		break;

		case "story2":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "story3";
		break;

		case "story3":
			PlaySound("VOICE\ENGLISH\pir_capBB.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "story4";
		break;

		case "story4":
			PlaySound("VOICE\ENGLISH\pir_capA.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("Pell_story_interrupted");
		break;

	//-----------------------------------------------------------------

		case "story5":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "story6";
		break;

		case "story6":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "story7";
		break;

		case "story7":
			PlaySound("VOICE\ENGLISH\pir_capKK.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "story8";
		break;

		case "story8":
			PlaySound("VOICE\ENGLISH\pir_capFFF.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "story9";
		break;

		case "story9":
			PlaySound("VOICE\ENGLISH\pir_capD.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "story10";
		break;

		case "story10":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "story11";
		break;

		case "story11":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "story12";
		break;

		case "story12":
			PlaySound("VOICE\ENGLISH\blaze_no_escape.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "story13";
		break;

		case "story13":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "story14";
		break;

		case "story14":
			PlaySound("VOICE\ENGLISH\pir_capAAA.wav");
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "story15";
		break;

		case "story15":
			PlaySound("VOICE\ENGLISH\pir_capFF.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("Pell_story_told");
		break;

		case "neutral_cell":
			PlaySound("VOICE\ENGLISH\pir_capEE.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_cell";
		break;	

		case "pell_out":
			PlaySound("VOICE\ENGLISH\gm_crew16B.wav");
			Dialog.text = DLG_TEXT[34];
			if(CheckCharacterItem(Pchar,"Pell_outfit"))
			{
				link.l1 = DLG_TEXT[35];
			}
			else link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			Diag.TempNode = "pell_out";
			AddDialogExitQuest("pell_out_done");
		break;

		case "careen_ship1":
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem50");

			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_ship1_A");
		break;

		case "careen_ship2":
			TakenItems(Pchar, "gunpowder", -100);
			TakenItems(Pchar, "pistolbullets", -100);
			TakenItems(Pchar, "pistolgrapes", -100);
			GiveItem2Character(Pchar, "ammobag2");
			EquipCharacterByItem(Pchar, "ammobag2");
			TakenItems(Pchar, "gunpowder", 18);
			TakenItems(Pchar, "pistolgrapes", 18);
			SetModel(PChar, "Howard_Pyle_hat_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);	

			LAi_SetActorType(NPChar);
			LAi_ActorTurnToLocator(NPChar, "ships_other", "ship_3");
		
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem50");

			PlaySound("PEOPLE\clothes4.wav");
			PlaySound("PEOPLE\clothes4.wav");
			PlaySound("VOICE\ENGLISH\gm_crew16B.wav");
			Dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "careen_ship3";
		break;

		case "careen_ship3":
			LAi_SetActorType(NPChar);
			LAi_ActorTurnToLocator(NPChar, "ships_other", "ship_3");
		
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "randitem", "randitem50");

			PlaySound("VOICE\ENGLISH\pir_capI.wav");
			Dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_ship4");
		break;

		case "careen_corvette_returns":
			LAi_SetActorType(NPChar);
			LAi_ActorTurnToLocator(NPChar, "ships_other", "ship_2");
		
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "ships_other", "ship_2");

			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_corvette_returns1");
		break;

		case "hat_again":
			PlaySound("VOICE\ENGLISH\pir_capCC.wav");
			Dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "sloop_destroyed";
		break;

		case "sloop_destroyed":
			SetModel(PChar, "Howard_Pyle_hat_a", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			GiveItem2Character(Pchar, "bb_hatA2");
			EquipCharacterByItem(Pchar, "bb_hatA2");
			PlaySound("INTERFACE\cancel.flac");

			Dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "sloop_destroyed1";
		break;

		case "sloop_destroyed1":
			PlaySound("VOICE\ENGLISH\pir_capI.wav");
			Dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
			AddDialogExitQuest("corvette_boats");
		break;

		case "1_boat_hit":
			PlaySound("VOICE\ENGLISH\gm_crew16A.wav");
			Dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			AddDialogExitQuest("1_boat_hit_done");
		break;

		case "2_boats_sunk":
			PlaySound("VOICE\ENGLISH\pir_capAAA.wav");
			Dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";
			AddDialogExitQuest("to_the_blockhouse");
		break;

		case "what_happened":
			PlaySound("VOICE\ENGLISH\gm_crew16A.wav");
			Dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_transformation18");
		break;

		case "crew_decides":
			PlaySound("VOICE\ENGLISH\pir_capBB.wav");
			Dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end21");
		break;

		case "kill_prisoners":
			PlaySound("VOICE\ENGLISH\pir_capI.wav");
			Dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_wdeck23A");
		break;

		case "water_done":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "water_done1";
		break;

		case "water_done1":
			PlaySound("VOICE\ENGLISH\gm_crew16A.wav");
			Dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona2");
		break;

		case "violin_found":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("car_slave27"));

			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona11");
		break;

		case "swedes_arriving":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "officers", "reload3_2");
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "officers", "reload3_2");

			LAi_SetActorType(characterFromID("car_convict3"));
			LAi_ActorTurnToLocator(characterFromID("car_convict3"), "officers", "reload3_2");
			LAi_SetActorType(characterFromID("car_slave10"));
			LAi_ActorTurnToLocator(characterFromID("car_slave10"), "officers", "reload3_2");
			LAi_SetActorType(characterFromID("car_slave27"));
			LAi_ActorTurnToLocator(characterFromID("car_slave27"), "officers", "reload3_2");

			PlaySound("OBJECTS\SHIPCHARGE\gunner_fire.wav");
			Dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "exit";
		//	AddDialogExitQuest("Pyle_to_Mona24");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
