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

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
