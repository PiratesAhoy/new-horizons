//#include "DIALOGS\Annabella Brin_dialog.h"
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

			Dialog.mood = "normal";

			if(NPChar.id != "Bella Brin")
			{
				//dialog.snd = "Voice\ARSI\ARSI001";
				PlaySound("VOICE\ENGLISH\Eng_f_c_006.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";

				if (pchar.quest.Jacks_early_days == "trouble_with_the_ladies")
				{
					//dialog.snd = "Voice\ARSI\ARSI002";
					PlaySound("VOICE\ENGLISH\Eng_f_c_006.wav");
					dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "Talk_to_Annabella";
				}
				if (pchar.quest.Jacks_early_days == "find_sister_one")
				{
					//dialog.snd = "Voice\ARSI\ARSI002";
					Dialog.mood = "normal";
					PlaySound("VOICE\ENGLISH\Eng_f_c_003.wav");
					dialog.text = DLG_TEXT[19];
					link.l1 = DLG_TEXT[20];
					link.l1.go = "SisterExit";				
				}
				if (pchar.quest.Jacks_early_days == "end_first_meeting")
				{
					dialog.snd = "Voice\ARSI\ARSI002";
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "SearchExit";
				}
				if (pchar.quest.Jacks_early_days == "waiting")
				{
					dialog.snd = "Voice\ARSI\ARSI002";
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "Exit";
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\Eng_f_c_001.wav");
				dialog.text = DLG_TEXT[50];
				Link.l1 = DLG_TEXT[51];
				Link.l1.go = "Exit";
			}
		break;

		case "Talk_to_Annabella":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Talk_to_Annabella2";
		break;

		case "Talk_to_Annabella2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + GetMyFullName(Pchar) + DLG_TEXT[8] ;
			link.l1.go = "Talk_to_Annabella3";
		break;		
		
		case "Talk_to_Annabella3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Talk_to_Annabella4";
		break;
		
		case "Talk_to_Annabella4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Talk_to_Annabella5";
		break;		

		case "Talk_to_Annabella5":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Talk_to_Annabella6";
		break;		

		case "Talk_to_Annabella6":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Talk_to_Annabella7";
			GiveItem2Character(Pchar,"jewelry2");	
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");			
		break;

		case "Talk_to_Annabella7":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "SearchExit";
			AddQuestRecord("My Early Days",3);
			AddPassenger(Pchar, characterFromID("Annabella Brin"), 0);
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Annabella Brinkley"));
		break;
		
		case "Talk_in_Tavern":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Talk_in_Tavern2";
		break;

		case "Talk_in_Tavern2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Talk_in_Tavern3";
		break;

		case "Talk_in_Tavern3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "Talk_in_Tavern4";
		break;

		case "Talk_in_Tavern4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Talk_in_Tavern5";
		break;

		case "Talk_in_Tavern5":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Talk_in_Tavern6";
		break;

		case "Talk_in_Tavern6":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Rescue_Go";
			link.l2 = DLG_TEXT[33];
			link.l2.go = "Rescue_Not_Go";
		break;

		case "Rescue_Go":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Get_ready_for_Rescue";
		break;

		case "Rescue_Not_Go":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Get_ready_for_Rescue";
			link.l2 = DLG_TEXT[37];
			link.l2.go = "Exit_Not_Go";
		break;

		case "Get_ready_for_Rescue":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit_for_Rescue";
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
			GiveItem2Character(Pchar,"jewelry2");
		break;		

		case "Visit_the_Big_Man":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Visit_the_Big_Man2";
		break;

		case "Visit_the_Big_Man2":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Visit_the_Big_Man3";
		break;

		case "Visit_the_Big_Man3":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Visit_the_Big_Man4";
		break;

		case "Visit_the_Big_Man4":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Exit_Visit_the_Big_Man";
		break;

		case "To_sea_to_sea":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Exit_to_sea";
		break;

		case "Sisters_to_sea":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Exit_Sisters_to_sea";
		break;

		case "Exit_Sisters_to_sea":
			AddDialogExitQuest("To_Jamaica_and_father");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_to_sea":
			AddDialogExitQuest("Saved_the_Sisters");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_for_Rescue":
			AddQuestRecord("My Early Days",5);		
			LAi_ActorGoToLocator(characterFromID("Billy Brock"), "reload", "reload1", "", 8.4);
			LAi_ActorGoToLocator(characterFromID("Annabella Brin"), "reload", "reload1", "", 8.4);		
			AddDialogExitQuest("Rescue_Exit");		
			Dialog.CurrentNode = "First time";
			pchar.quest.Jacks_early_days = "A_spot_of_bother";
			DialogExit();
		break;
		
		case "Exit_Not_Go":
			AddDialogExitQuest("Upstairs_Fight");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;
		
		case "Exit":	
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "SearchExit":
			pchar.quest.Jacks_early_days = "end_first_meeting";
			AddDialogExitQuest("now_find_a_sister");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "SisterExit":
			AddPassenger(Pchar, characterFromID("Annabella Brin"), 0);			
			SetOfficersIndex(Pchar, 1, getCharacterIndex("Annabella Brin"));
			LAi_SetOfficerType(characterFromID("Annabella Brin"));			
			pchar.quest.Jacks_early_days = "In_trouble_with_sisters";		
			AddQuestRecord("My Early Days",4);
			Pchar.quest.to_find_a_sister_capture.win_condition.l1 = "location";
			PChar.quest.to_find_a_sister_capture.win_condition.l1.character = Pchar.id;
			Pchar.quest.to_find_a_sister_capture.win_condition.l1.location = "Greenford_tavern";
			Pchar.quest.to_find_a_sister_capture.win_condition = "to_find_a_sister_capture";
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_Visit_the_Big_Man":
			AddDialogExitQuest("Skull_joins_in");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;		
	}
}