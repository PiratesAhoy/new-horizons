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
		
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Caesar"));
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Caesar"));
			if(IsOfficer(CharacterFromID("Pell")))				
			{
				LAi_SetActorType(characterFromID("Pell"));
				LAi_ActorTurnToCharacter(characterFromID("Pell"), characterFromID("Caesar"));
			}
			PlaySound("VOICE\ENGLISH\Odel_yourself_again.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("servant_is_Caesar2");
		break;
	
		case "wine_cellar":
			PlaySound("VOICE\ENGLISH\Odel_otherwise.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "wine_cellar1";
		break;

		case "wine_cellar1":
			PlaySound("VOICE\ENGLISH\Odel_very_good.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene_delay");
		break;

	//after scene
		case "wine_cellar2":
			PlaySound("VOICE\ENGLISH\Odel_otherwise.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "wine_cellar2_A";
		break;

		case "wine_cellar2_A":
			PlaySound("VOICE\ENGLISH\Odel_fine.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("Margaret_Pough4");
		break;

		case "wine_cellar3":
			PlaySound("VOICE\ENGLISH\Odel_get_started.wav");
			Dialog.text = DLG_TEXT[10];
			if(IsOfficer(CharacterFromID("Pell")))				
			{
				link.l1 = DLG_TEXT[11];
			}
			else link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
			AddDialogExitQuest("estate_wine_cellar1");
		break;

		case "neutral":
			PlaySound("VOICE\ENGLISH\gr_Hands1.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
		break;

		case "door_where":
			PlaySound("VOICE\ENGLISH\Odel_fine.wav");
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
			AddDialogExitQuest("Hands_door_where_done");
		break;

		case "flood":
			PlaySound("VOICE\ENGLISH\Odel_no.wav");
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
			Pchar.hands_flood = "done";
			LAi_SetOfficerType(NPChar);
		break;
	
		case "beggar":
			PlaySound("VOICE\ENGLISH\Odel_very_good.wav");
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
			AddDialogExitQuest("are_you_Hands_yes_delay");
		break;

		case "beggar_is_Hands":
			PlaySound("VOICE\ENGLISH\gr_Hands1.wav");
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "beggar_is_Hands1";
		break;

		case "beggar_is_Hands1":
			PlaySound("INTERFACE\paper_small.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "beggar_is_Hands2";
		break;

		case "beggar_is_Hands2":
			PlaySound("VOICE\ENGLISH\Odel_get_started.wav");
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "beggar_is_Hands3";
		break;

		case "beggar_is_Hands3":
			PlaySound("VOICE\ENGLISH\Odel_no.wav");
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "beggar_is_Hands4";
		break;

		case "beggar_is_Hands4":
			PlaySound("VOICE\ENGLISH\Odel_otherwise.wav");
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
			AddDialogExitQuest("Hands_shot_scene");
		break;

		case "I_am_alive":
			PlaySound("VOICE\ENGLISH\Odel_otherwise.wav");
			Dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "I_am_alive1";
		break;

		case "I_am_alive1":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "I_am_alive2";
		break;

		case "I_am_alive2":
			PlaySound("VOICE\ENGLISH\Odel_no.wav");
			Dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "I_am_alive3";
		break;

		case "I_am_alive3":
			PlaySound("VOICE\ENGLISH\Odel_fine.wav");
			Dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "I_am_alive4";
		break;

		case "I_am_alive4":
			PlaySound("VOICE\ENGLISH\Odel_very_good.wav");
			Dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
			AddDialogExitQuest("back_to_Wstad3");
		break;

		case "careen_shore":
			PlaySound("VOICE\ENGLISH\Odel_yourself_again.wav");
			Dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "careen_shore1";
		break;

		case "careen_shore1":
			SetModel(PChar, "Howard_Pyle_hat_b", Pchar.model.animation, PChar.sex, stf(PChar.model.height), true);
			GiveItem2Character(Pchar, "bb_hatA2");
			EquipCharacterByItem(Pchar, "bb_hatA2");
			PlaySound("INTERFACE\cancel.wav");	
				
			Dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "careen_shore2";
		break;

		case "careen_shore2":
			GiveItem2Character(Pchar, "book71_9_start");	
			PlaySound("INTERFACE\paper.wav");

			Dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_mutineers23");
		break;

		case "Pell_shooting":
			LAi_SetActorType(NPChar);
			LAi_ActorTurnToLocator(NPChar, "quest", "duel_mills");
			LAi_SetActorType(PChar);
			LAi_ActorTurnToLocator(PChar, "quest", "duel_christian");

			PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
			Dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_mutineers28_B");
		break;

		case "and_the_treasure":
			PlaySound("VOICE\ENGLISH\Odel_yourself_again.wav");
			Dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_transformation19");
		break;

		case "bad_weather":
			PlaySound("VOICE\ENGLISH\Odel_get_started.wav");
			Dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_transformation_end");
		break;

		case "what_about_weapons":
			PlaySound("VOICE\ENGLISH\Odel_get_started.wav");
			Dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_shore_fight_end22");
		break;

		case "fiddler_returning":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("car_slave27"));
			LAi_SetActorType(characterFromID("Pell"));
			LAi_ActorTurnToCharacter(characterFromID("Pell"), characterFromID("car_slave27"));

			PlaySound("VOICE\ENGLISH\alarm1.wav");
			Dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";
		break;

		case "priest_returning":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("car_slave11"));
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("car_slave11"));

			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			Dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_to_Mona14");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
