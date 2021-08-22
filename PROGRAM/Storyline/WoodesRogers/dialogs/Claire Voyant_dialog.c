//#include "DIALOGS\Claire Voyant_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


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
			
			if(CheckAttribute(Pchar,"quest.med_Claire") && Pchar.quest.med_Claire == "acetum")
			{
				PlaySound("VOICE\ENGLISH\claire_light.wav");
				Dialog.text = DLG_TEXT[38];
				link.l1 = DLG_TEXT[39];
				link.l1.go = "exit";
			}
			else
			{
				PlaySound("VOICE\ENGLISH\claire_items.wav");

				if(CheckCharacterItem(Pchar,"pistolmdchest_F2B") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_C") 
				    || CheckCharacterItem(Pchar,"pistolmdchest_F2B_S") || CheckCharacterItem(Pchar,"pistolmdchest_F2B_CS")
				    || CheckCharacterItem(Pchar,"pistolmdchest_F3B") || CheckCharacterItem(Pchar,"pistolmdchest_F3B_C") 
				    || CheckCharacterItem(Pchar,"pistolmdchest_F3B_S") || CheckCharacterItem(Pchar,"pistolmdchest_F3B_CS"))
				{
					Dialog.text = DLG_TEXT[4];
					link.l1 = DLG_TEXT[5];
					link.l1.go = "give_medicine";
				}
				else 
				{
					Dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "bring_the_chest";
				}
			}

			Diag.TempNode = "First time";
		break;

		case "bring_the_chest":
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
		break;

		case "give_medicine":
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "give_medicine1";
		break;

		case "give_medicine1":
			DialogExit();
			Diag.TempNode = "First time";
			
			AddMoneyToCharacter(NPChar,-10000);
			LaunchCharacterItemChange(NPChar);
		break;

		case "psst":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe1");
		break;

		case "mind_reading":
			PlaySound("VOICE\ENGLISH\claire_welcome.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "mind_reading1";
		break;

		case "mind_reading1":
			PlaySound("AMBIENT\JAIL\sigh.wav");
			PlaySound("AMBIENT\JAIL\sigh.wav");
			PlaySound("AMBIENT\JAIL\sigh.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe4");
		break;

		case "more_documents":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe6");
		break;

		case "more_documents1":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe9");
		break;

		case "pistols":
			PlaySound("VOICE\ENGLISH\claire_hmm.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "pistols1";
		break;

		case "pistols1":
			PlaySound("VOICE\ENGLISH\claire_items.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe12");
		break;

		case "see_future":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "see_future1";
		break;

		case "see_future1":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("claire_and_defoe14");
		break;

		case "magic_key":
			PlaySound("VOICE\ENGLISH\claire_help.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "magic_key1";
		break;

		case "magic_key1":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			LAi_SetActorType(CharacterFromID("Claire Voyant"));
			LAi_ActorTurnToCharacter(characterFromID("Claire Voyant"), characterFromID("Defoe"));
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_to_port9");
		break;

		case "breathe_on_key":
			PlaySound("VOICE\ENGLISH\claire_items.wav");
			LAi_SetActorType(CharacterFromID("Claire Voyant"));
			LAi_ActorTurnToCharacter(characterFromID("Claire Voyant"), characterFromID("Defoe"));
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_to_port11");
		break;

		case "crew_is_complete":
			PlaySound("VOICE\ENGLISH\claire_help.wav");
			LAi_SetActorType(CharacterFromID("Claire Voyant"));
			LAi_ActorTurnToCharacter(characterFromID("Claire Voyant"), characterFromID("grandma"));
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans15");
		break;

		case "claire_crew_lines":
			PlaySound("VOICE\ENGLISH\claire_help.wav");
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
			AddDialogExitQuest("pchar_choose_sailors_and_officers");
		break;

		case "notebook":
			PlaySound("VOICE\ENGLISH\claire_fortune.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map13");
		break;

		case "Teach_joke":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map25");
		break;

		case "sloop2":
			PlaySound("VOICE\ENGLISH\claire_welcome.wav");
			Dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
			AddDialogExitQuest("sloop3");
		break;

		case "sloop4":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
			AddDialogExitQuest("sloop5");
		break;

		case "sloop6":
			PlaySound("VOICE\ENGLISH\claire_help.wav");
			Dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "sloop6_A";
		break;

		case "sloop6_A":
			PlaySound("VOICE\ENGLISH\claire_hmm.wav");
			if(GetAttribute(pchar, "book72_edenL") == "read" && GetAttribute(pchar, "book72_handsL") == "read" 
			&& GetAttribute(pchar, "book72_richardsL") == "read" && GetAttribute(pchar, "book72_caesarL") == "read")
			{
				//you have got all info from the book
				Dialog.text = DLG_TEXT[69];
				link.l1 = DLG_TEXT[70];
				link.l1.go = "sloop6_B";
			}
			else 
			{
				Dialog.text = DLG_TEXT[72];
				link.l1 = DLG_TEXT[73];
				link.l1.go = "exit";
		//		AddDialogExitQuest("sloop7");		//not until book72 is entirely read through
				AddDialogExitQuest("HOP_read_check");
			}
		break;

		case "sloop6_B":
			PlaySound("VOICE\ENGLISH\claire_welcome.wav");
			Dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
			AddDialogExitQuest("sloop7");
		break;

		case "sloop8":
			PlaySound("VOICE\ENGLISH\claire_items.wav");
			Dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			AddDialogExitQuest("sloop9");
		break;

		case "platina":
			PlaySound("VOICE\ENGLISH\claire_items.wav");
			Dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "platina1";
		break;

		case "platina1":
			PlaySound("VOICE\ENGLISH\claire_hmm.wav");
			Dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "platina2";
		break;

		case "platina2":
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			locations[FindLocation("wr_farm_alchemy2")].type = "silent_residence";
			PostEvent("LoadSceneSound", 0.1);

			Dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
			AddDialogExitQuest("pchar_ooh");
			AddDialogExitQuest("wait_grandma_finale5");
		break;

		case "meditation":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "officers", "off_3");
			PlaySound("VOICE\ENGLISH\claire_help.wav");
			Dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "meditation1";
		break;

		case "meditation1":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "officers", "off_3");
			PlaySound("VOICE\ENGLISH\claire_fortune.wav");
			Dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "meditation2";
		break;

		case "meditation2":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "officers", "off_3");
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_transformation2");
		break;

		case "meditation3":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "black1");
			PlaySound("VOICE\ENGLISH\claire_welcome.wav");
			Dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_transformation5");
		break;

		case "meditation_end":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "black1");
			PlaySound("VOICE\ENGLISH\claire_light.wav");
			Dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_transformation10");
		break;

		case "magic_items":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "officers", "off_3");
			PlaySound("VOICE\ENGLISH\claire_welcome.wav");
			Dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "exit";
			AddDialogExitQuest("Pyle_transformation14");
		break;

		case "treasure_lost":	
			PlaySound("VOICE\ENGLISH\claire_hmm.wav");
			Dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_boo2");
		break;

		case "tickets":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("jrh"));
			LAi_SetActorType(Pchar));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Defoe"));
			PlaySound("VOICE\ENGLISH\claire_hmm.wav");
			Dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "tickets1";			
		break;

		case "tickets1":
			PlaySound("INTERFACE\paper_small.wav");	
			PlaySound("VOICE\ENGLISH\claire_welcome.wav");
			Dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "exit";
			AddDialogExitQuest("bonus_chapter5");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
