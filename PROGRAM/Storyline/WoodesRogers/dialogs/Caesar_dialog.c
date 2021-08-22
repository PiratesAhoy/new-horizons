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
		
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Hands"));

			PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
			if(IsOfficer(CharacterFromID("Pell")))				
			{
				Dialog.text = DLG_TEXT[2];
			}
			else
			{
				Dialog.text = DLG_TEXT[0];
			}
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		Pchar.servant_Caesar = "done";
			AddDialogExitQuest("servant_is_Caesar1");
		break;
	
		case "Eden_saved_me":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "exit";
			AddDialogExitQuest("servant_is_Caesar3");
		break;
	
		case "shut_up":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("black_servant1"));

			PlaySound("OBJECTS\DUEL\man_attack5.wav");
			Dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "shut_up1";
		break;

		case "shut_up1":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, Pchar);

			PlaySound("OBJECTS\VOICES\DEAD\male\dead2.wav");
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "shut_up2";
		break;

		case "shut_up2":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "shut_up3";
		break;

		case "shut_up3":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			Dialog.text = DLG_TEXT[11];
			if(CheckAttribute(Pchar,"servants_info") && Pchar.servants_info == "5")
			{
				link.l1 = DLG_TEXT[40];
				link.l1.go = "exit";
				AddDialogExitQuest("Pough3_done");
			}
			else
			{
				link.l1 = DLG_TEXT[12];
				link.l1.go = "exit";
				AddDialogExitQuest("servant_is_Caesar5");
			}
		break;

		case "Knight_thief":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Margaret_Pough"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("black_servant1"));

			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			AddDialogExitQuest("Estate_end3");
		break;

		case "leaving_as_servant":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Margaret_Pough"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("black_servant1"));

			PlaySound("VOICE\ENGLISH\gm_crew5C.wav");
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			AddDialogExitQuest("Estate_end7");
		break;

		case "neutral":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
		break;

		case "neutral_silent":
			PlaySound("VOICE\ENGLISH\Jupiter_mm.wav");
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_silent";
		break;

		case "mapBB3":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "mapBB3_A";
		break;

		case "mapBB3_A":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "mapBB3_B";
		break;

		case "mapBB3_B":
			PlaySound("VOICE\ENGLISH\gm_crew5A.wav");
			Dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
			AddDialogExitQuest("Caesar_mapBB3_done");
		break;

		case "Caesars_map1":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[23];
			if(CheckAttribute(Pchar,"Caesar_GPS") && Pchar.Caesar_GPS == "visited")
			{
				link.l1 = DLG_TEXT[24];
				link.l1.go = "Caesar_GPS";
			}
			else
			{
				if(CheckAttribute(Pchar,"Turks_explosion") && Pchar.Turks_explosion == "done")
				{
					link.l1 = DLG_TEXT[31];
					link.l1.go = "Turks_explosion";
				}
				else
				{
					if(CheckAttribute(Pchar,"key30") && Pchar.key30 == "done")
					{
						//Citadel done
						link.l1 = DLG_TEXT[31];
						link.l1.go = "Caesar_key30";
					}
					else
					{
						if(CheckAttribute(Pchar,"Odel_dialog") && Pchar.Odel_dialog == "done")
						{
							link.l1 = DLG_TEXT[36];
							link.l1.go = "Caesar_Odel";
						}
						else
						{
							//nothing of Caesar done
							link.l1 = DLG_TEXT[38];
							link.l1.go = "Caesar_Odel_not_yet";
						}
					}					
				}
			}
		break;
	
		case "Caesar_GPS":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Caesar_GPS1";
		break;

		case "Caesar_GPS1":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Caesar_GPS2";
		break;

		case "Caesar_GPS2":
			PlaySound("VOICE\ENGLISH\gm_crew5A.wav");
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
			AddDialogExitQuest("Caesar_info_given");
		break;

		case "Turks_explosion":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Turks_explosion1";
		break;

		case "Turks_explosion1":
			PlaySound("VOICE\ENGLISH\gm_crew5A.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
			AddDialogExitQuest("Caesar_info_given");
		break;

		case "Caesar_key30":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Turks_explosion1";		//yes use the same
		break;

		case "Caesar_Odel":
			PlaySound("VOICE\ENGLISH\gm_crew5A.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("Caesar_info_given2");
		break;

		case "Caesar_Odel_not_yet":
			PlaySound("VOICE\ENGLISH\gm_crew5A.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("Caesar_info_given2");
		break;

		case "shore_runner":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Hands"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Hands"));

			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_mutineers21_B");
		break;

		case "shore_runner1":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Hands"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Hands"));

			PlaySound("OBJECTS\VOICES\DEAD\male\dead0.wav");
			Dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_mutineers21_D");
		break;

		case "shore_runner2":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Hands"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Hands"));

			PlaySound("VOICE\ENGLISH\gm_crew5C.wav");
			Dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "shore_runner_belt";
		break;

		case "shore_runner_belt":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Hands"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Hands"));

			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_mutineers21_F");
		break;

		case "Hands_is_back":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Hands"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Hands"));
			LAi_SetActorType(characterFromID("Hands"));
			LAi_ActorTurnToCharacter(characterFromID("Hands"), characterFromID("Caesar"));

			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			PlaySound("OBJECTS\DUEL\sabre_out.wav");

			GiveItem2Character(characterFromID("Hands"), "blade2");
			EquipCharacterByItem(characterFromID("Hands"), "blade2");
			GiveItem2Character(characterFromID("Hands"), "Pistol6");
			EquipCharacterByItem(characterFromID("Hands"), "Pistol6");
			TakenItems(characterFromID("Hands"), "pistolbullets", 2);
			TakenItems(characterFromID("Hands"), "gunpowder", 2);

			TakeItemFromCharacter(Pchar, "blade2");
			TakeItemFromCharacter(Pchar, "pistol6");
			TakenItems(Pchar, "gunpowder", -2);
			TakenItems(Pchar, "pistolbullets", -2);

			Dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Hands_is_back1";
		break;

		case "Hands_is_back1":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Hands"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Hands"));
			LAi_SetActorType(characterFromID("Hands"));
			LAi_ActorTurnToCharacter(characterFromID("Hands"), characterFromID("Caesar"));

			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			AddDialogExitQuest("careen_mutineers23_A");
		break;

		case "show_the_way":
			PlaySound("VOICE\ENGLISH\gm_crew5C.wav");
			Dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_transformation24");
		break;

		case "treasure_aboard":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "exit";
			AddDialogExitQuest("pchar_playertype");
			AddDialogExitQuest("with_treasure_to_sea3");
		break;

		case "neutral_swim":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
			AddDialogExitQuest("careen_shore_fight_end6");
		break;

		case "open_to_slaves":
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			Dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_silent";
			AddDialogExitQuest("explore_corvette20_E");
		break;

		case "locked_to_slaves":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_silent";
			AddDialogExitQuest("explore_corvette10_B");
		break;

		case "we_got_weapons":
			PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			Dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_silent";
			AddDialogExitQuest("explore_corvette32_A");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
