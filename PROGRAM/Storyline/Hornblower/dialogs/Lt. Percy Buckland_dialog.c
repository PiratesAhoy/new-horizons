//#include "DIALOGS\Bartholomew Roberts_dialog.h"
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

	string voice_path = "VOICE\ENGLISH\";
	if (CheckDirectory("RESOURCE\Sounds\VOICE\"+LanguageGetLanguage()+"\","*") > 0) voice_path = "VOICE\" + LanguageGetLanguage() + "\";

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
		break;

		case "Course Settings":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Course Settings2";
		break;

		case "Course Settings2":
			LAi_SetActorType(PChar);
			LAi_ActorRunToLocator((Pchar), "reload", "boatr", "", 10.0);
			LAi_ActorGoToLocator(characterFromID("Archie Kennedy"), "goto", "goto13", "", 10.0);
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Course Settings3"
		break;

		case "Course Settings3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Exit_for_Kennedy";
		break;

		case "Sail_round_the_island":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Sail_round_the_island2";
		break;

		case "Sail_round_the_island2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Exit_Sail_round_the_island";
		break;

		case "Sawyer_to_Buckland":
			dialog.text = DLG_TEXT[42];
			link.l1.go = "Exit_Sawyer_to_Buckland";
		break;

		case "Exit_Sawyer_to_Buckland":
			AddDialogExitQuest("Sawyer_again_Bush");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Buckland_says_Laudanum":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Buckland_says_Laudanum2";
		break;

		case "Buckland_says_Laudanum2":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Exit_Buckland_says_Laudanum";
		break;

		case "Exit_Buckland_says_Laudanum":
			AddDialogExitQuest("Talk_with_officers3");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Now_I'm_Captain":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Now_I'm_Captain2";
		break;

		case "Now_I'm_Captain2":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Now_I'm_Captain3";
		break;

		case "Now_I'm_Captain3":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Now_I'm_Captain4";
		break;

		case "Now_I'm_Captain4":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "Now_I'm_Captain5";
		break;

		case "Now_I'm_Captain5":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_Now_I'm_Captain";
		break;

		case "Exit_Now_I'm_Captain":
			AddDialogExitQuest("Land_at_Cuban_Beach");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "the_fort_is_ours":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "the_fort_is_ours2";
		break;

		case "the_fort_is_ours2":
			dialog.text = DLG_TEXT[5] + Pchar.lastname + DLG_TEXT[6];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Exit_the_fort_is_ours";
		break;

		case "Exit_the_fort_is_ours":
			AddDialogExitQuest("Buckland_and_Ortega");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "take_the_surrender":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "take_the_surrender2";
		break;

		case "take_the_surrender2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_take_the_surrender";
		break;

		case "Exit_take_the_surrender":
			AddDialogExitQuest("Send_prisoners_to_ship");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "blow_up_fort":
			dialog.text = Pchar.lastname + DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "blow_up_fort2";
		break;

		case "blow_up_fort2":
			dialog.text = DLG_TEXT[14] + DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "blow_up_fort3";
		break;

		case "blow_up_fort3":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit_blow_up_fort";
		break;

		case "Exit_blow_up_fort":
			AddDialogExitQuest("Buckland_leaves_fort");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "the_ship_recovered":
			PlaySound(voice_path + "Hornblwr02.wav");
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "the_ship_recovered2";
		break;

		case "the_ship_recovered2":
			PlaySound(voice_path + "Buckland03.wav");
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "the_ship_recovered3";
		break;

		case "the_ship_recovered3":
			PlaySound(voice_path + "Buckland04.wav");
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_the_ship_recovered";
		break;

		case "Exit_the_ship_recovered":
			AddDialogExitQuest("senior_man_now");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Court_Martial_four":
			dialog.text = DLG_TEXT[54];
			link.l1.go = "Exit_Court_Martial_four";
		break;

		case "Exit_Court_Martial_four":
			AddDialogExitQuest("The_Court_Martial_Begins7");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "dispose_of_the_body":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_dispose_of_the_body";
		break;

		case "why_were_you_late":
//			dialog.snd = "Voice\ARSI\ARSI003";
			PlaySound(voice_path + "Buckland01.wav");
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "why_were_you_late2";
		break;

		case "why_were_you_late2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_why_were_you_late";
		break;

		case "Claytons_body":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Claytons_body";
		break;

		case "Let_the_Captain_decide":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Let_the_Captain_decide2";
		break;

		case "Let_the_Captain_decide2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit_Let_the_Captain_decide";
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Course_Redmond":
			AddDialogExitQuest("take over the ship4");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Sail_round_the_island":
			AddQuestRecord("My First Ship", 7);
			AddDialogExitQuest("Bush_and_me_to_sea");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Find_the_Naval_Station":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Find_the_Naval_Station";
		break;

		case "Exit_Find_the_Naval_Station":
//			AddQuestRecord("My First Ship", 7);
			AddDialogExitQuest("Collect_new_officers2");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "ExitWhichPort":
			AddQuestRecord("Battle Bloodied", 3);
			AddDialogExitQuest("Make_sail_for_Greenford");		
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Exit_dispose_of_the_body":
			AddDialogExitQuest("Bush_Leaves_Upstairs");		
			NextDiag.CurrentNode = "First time";		
			DialogExit();
		break;

		case "Exit_for_Kennedy":
			AddDialogExitQuest("Meet_Archie_Kennedy");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_why_were_you_late":
			AddDialogExitQuest("Showdown_with_Simpson");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Claytons_body":
			AddDialogExitQuest("A_Grim_Situation");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Let_the_Captain_decide":
			AddDialogExitQuest("Off_to_Redmond_Clayton_dead");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
	}
}

