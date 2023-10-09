//#include "DIALOGS\Merciless Mark_dialog.h"
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

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if(checkquestattribute("Jacks_early_days", "Now_at_Guadeloupe"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3] + GetMyFullName(Pchar) + DLG_TEXT[4];			
				link.l1.go = "Guadeloupe_stuff";
			}
			if (checkquestattribute("Jacks_early_days", "Travel_to_Petros"))
			{
				dialog.text = DLG_TEXT[13];
				link.l1 = DLG_TEXT[14];			
				link.l1.go = "Petros_trip";
			}			
		break;

		case "Guadeloupe_stuff":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];			
			link.l1.go = "Exit_for_choice";
		break;	

		case "Show_me_where_to_go":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];			
			link.l1.go = "Show_me_where_to_go2";
		break;
		
		case "Show_me_where_to_go2":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];			
			link.l1.go = "Show_me_where_to_go3";
		break;

		case "Show_me_where_to_go3":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];			
			link.l1.go = "Exit_Show_me_where_to_go";
		break;
		
		case "Petros_trip":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];			
			link.l1.go = "Petros_trip2";
			LAi_ActorAnimation(characterFromID("Mr. Gibbs"), "StandUp", "", 1.0);
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Mr. Gibbs"));			
		break;		

		case "Petros_trip2":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];			
			link.l1.go = "Exit_Petros_trip";
			ChangeCharacterAddressGroup(characterFromID("Mr. Gibbs"),"Pointe_a_pitre_Tavern", "goto", "goto4");			
		break;		

		case "Island_stuff8":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];			
			link.l1.go = "Exit_Island_stuff";
		break;
		
		case "Arrival_at_Jamaica":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];			
			link.l1.go = "Arrival_at_Jamaica2";
		break;

		case "Arrival_at_Jamaica2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];			
			link.l1.go = "ExitJamaicaArrival";
		break;

		case "meet_Guadelope_Tavern_Again":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "meet_Guadeloupe_Tavern_Again2";
		break;

		case "meet_Guadeloupe_Tavern_Again2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit_for_Treasure_Discussion";
		break;
		
		case "Exit_Show_me_where_to_go":		
			pchar.quest.Jacks_early_days = "Travel_to_Petros";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Refit_and_sleep");
		break;

		case "Exit_for_choice":
			pchar.quest.Jacks_early_days = "Talking_at_Guadeloupe";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Drow_starts_to_talk");			
		break;		

		case "Exit_Petros_trip":
			pchar.quest.Jacks_early_days = "Petros_in_sight";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("To_Anse_Casse_Bois");
		break;		

		case "Exit_for_Treasure_Discussion":
			TakeItemFromCharacter(pchar, "Map_Doc_3");
			TakeItemFromCharacter(pchar, "Map_Doc_2");
			TakeItemFromCharacter(pchar, "Map_Doc_1");
			pchar.quest.Jacks_early_days = "Nearer_the_Treasure";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Discuss_the_Treasure_Details");
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
