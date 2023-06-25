//#include "DIALOGS\Thomas Dover_dialog.h"
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
		
			if(CheckAttribute(Pchar,"quest.medicine_quest") && Pchar.quest.medicine_quest == "started")
			{
				switch(Pchar.quest.med_Selkirk)
				{
					PlaySound("VOICE\ENGLISH\Eng_m_c_075.wav");

					case "church_hint":
						Dialog.text = DLG_TEXT[56];
						link.l1 = DLG_TEXT[57];
						link.l1.go = "church_hint1";
					break;

					case "friday_hint":
						Dialog.text = DLG_TEXT[62];
						link.l1 = DLG_TEXT[63];
						link.l1.go = "exit";
					break;

					case "friday_medicine":
						Pchar.quest.med_Selkirk = "neutral";//only once Friday arrives
						Dialog.text = DLG_TEXT[64];
						link.l1 = DLG_TEXT[65];
						link.l1.go = "exit";
						AddDialogExitQuest("friday_medicine");
					break;

					case "neutral":
						PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
						Dialog.text =  DLG_TEXT[0];
						link.l1 = DLG_TEXT[1];
						link.l1.go = "exit";
					break;

					//default:
					//this should mean only greeting - it didn't!
		 			return;
				}
				return;
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
				Dialog.text =  DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
				Diag.TempNode = "First time";
			}
		break;

		case "marooned":
			PlaySound("VOICE\ENGLISH\Eng_m_c_072.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "marooned2";
		break;

		case "marooned2":
			PlaySound("VOICE\ENGLISH\Eng_m_c_074.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "marooned3";
		break;

		case "marooned3":
			PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "marooned4";
		break;

		case "marooned4":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "marooned5";
		break;

		case "marooned5":
			PlaySound("OBJECTS\DUEL\man_attack5.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "marooned6";
		break;

		case "marooned6":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "marooned7";
		break;

		case "marooned7":
			PlaySound("AMBIENT\JAIL\cough.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "marooned8";
		break;

		case "marooned8":
			PlaySound("VOICE\ENGLISH\Eng_m_c_075.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("friday_arrives");
		break;

		case "translate":
			PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("translate_over");
		break;

		case "librarian":
			PlaySound("VOICE\ENGLISH\Eng_m_c_078.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "librarian1";
		break;

		case "librarian1":
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "librarian2";
		break;

		case "librarian2":
			PlaySound("VOICE\ENGLISH\Eng_m_c_077.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "librarian3";
		break;

		case "librarian3":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "librarian4";
		break;

		case "librarian4":
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "librarian5";
		break;

		case "librarian5":
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "librarian6";
		break;

		case "librarian6":
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
		Diag.TempNode = "first time";
			AddDialogExitQuest("librarian_over");
		break;
			
		case "sack":
			PlaySound("VOICE\ENGLISH\Eng_m_c_075.wav");
			Dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "sack2";
		break;

		case "sack2":
			Dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "sack3";
		break;	

		case "sack3":
			Dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
			AddDialogExitQuest("selkirk_got_glasses");
		break;	

		case "warning":
			PlaySound("VOICE\ENGLISH\Eng_m_c_074.wav");
			Dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "warning2";
		break;

		case "warning2":
			Dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "warning3";
		break;

		case "warning3":
			PlaySound("VOICE\ENGLISH\Eng_m_c_073.wav");
			Dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "warning4";
		break;

		case "warning4":
			Dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "warning5";
		break;

		case "warning5":
			Dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
			AddDialogExitQuest("warning_finished");
		break;

		case "new_warning":
			Dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "new_warning2";
		break;

		case "new_warning2":
			Dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "new_warning3";
		break;

		case "new_warning3":
			Dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
			AddDialogExitQuest("new_warning_finished");
		break;
	//----------------------------------------------------------------------
		case "church_hint1":
			Dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "church_hint2";
		break;

		case "church_hint2":
			Dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "church_hint3";
		break;

		case "church_hint3":
			Dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
			AddDialogExitQuest("church_hint_done");
		break;
	//----------------------------------------------------------------------
		case "friday_hint":
			Dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "exit";
		break;
	//----------------------------------------------------------------------
		case "Dampier_bad":
			PlaySound("VOICE\ENGLISH\Eng_m_c_069.wav");	
			Dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "exit";
			AddDialogExitQuest("Dampier_warning_given");
		break;
	
		case "bible":
			PlaySound("VOICE\ENGLISH\Eng_m_c_072.wav");
			Dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "bible1";
		break;

		case "bible1":
			PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
			GiveItem2Character(Pchar, "bible");
			Dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
			AddDialogExitQuest("bible_given");
		break;

		case "safe_room":
			PlaySound("VOICE\ENGLISH\Eng_m_c_075.wav");
			Dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "safe_room1";
		break;

		case "safe_room1":
			Dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "exit";
			AddDialogExitQuest("friday_room7");
		break;

		case "swim_captain":
			PlaySound("VOICE\ENGLISH\Eng_m_c_077.wav");
			Dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "swim_captain1";
		break;

		case "swim_captain1":
			Dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "exit";
			AddDialogExitQuest("friday_room14");
		break;

		case "kidnapped":
			PlaySound("VOICE\ENGLISH\Eng_m_c_077.wav");
			Dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "kidnapped1";
		break;

		case "kidnapped1":
			PlaySound("VOICE\ENGLISH\Eng_m_c_075.wav");
			Dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_mine_search21");
		break;

		case "way_out":
			PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
			Dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_mine_search28");
		break;

		case "open_window":
			PlaySound("VOICE\ENGLISH\Eng_m_c_069.wav");
			Dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_mine_search30");
		break;	

		case "got_the_key":
			PlaySound("VOICE\ENGLISH\Eng_m_c_001.wav");
			Dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "got_the_key1";
		//	AddDialogExitQuest("end_corvette_fight2");
		break;

	case "got_the_key1":
			PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
			Dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "exit";
			AddDialogExitQuest("end_corvette_fight2");
		break;

		case "cannon_is_loaded":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "exit";
			AddDialogExitQuest("Vane_broadside2");
		break;

		case "blaze_not_wounded":
			PlaySound("VOICE\ENGLISH\Eng_m_c_074.wav");
			Dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "exit";
			AddDialogExitQuest("corvette_greetings_dialog");
		break;

		case "friday_found_open_hatch":
			PlaySound("VOICE\ENGLISH\Eng_m_c_072.wav");
			Dialog.text = DLG_TEXT[94];
			link.l1 = DLG_TEXT[95];
			link.l1.go = "exit";
			AddDialogExitQuest("galleon_search4");
		break;

		case "no_crew":
			LAi_SetStayType(CharacterFromID("Selkirk"));
			ChangeCharacterAddressGroup(characterFromID("Selkirk"), "ck_drawing_room", "goto", "stay5");

			LAi_SetActorType(CharacterFromID("grandma"));
			LAi_ActorTurnToCharacter(CharacterFromID("grandma"), characterFromID("Selkirk"));
			LAi_SetActorType(characterFromID("Wench3"));
			LAi_ActorTurnToCharacter(characterFromID("Wench3"), characterFromID("Selkirk"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Selkirk"));

			PlaySound("VOICE\ENGLISH\Eng_m_c_077.wav");
			Dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "exit";
			AddDialogExitQuest("grandma_future_plans10");
		break;

		case "someone_on_the_roof":
			PlaySound("VOICE\ENGLISH\Eng_m_c_077.wav");
			LAi_SetActorType(CharacterFromID("Selkirk"));
			LAi_ActorTurnToCharacter(CharacterFromID("Selkirk"), characterFromID("grandma"));
			Dialog.text = DLG_TEXT[98];
			link.l1 = DLG_TEXT[99];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_monkey4");
		break;

		case "two_islands":
			PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
			Dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map12");
		break;

		case "BBs_treasure":
			PlaySound("VOICE\ENGLISH\Eng_m_c_069.wav");
			LAi_SetActorType(CharacterFromID("Selkirk"));
			LAi_ActorTurnToCharacter(CharacterFromID("Selkirk"), characterFromID("Defoe"));
			Dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "exit";
			AddDialogExitQuest("drawing_room_map20");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
