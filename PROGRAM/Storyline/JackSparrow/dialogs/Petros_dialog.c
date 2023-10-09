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
		//----TALISMAN changes for meeting on Turks after Guadeloupe capture - to send player to search for Kell - not Beckett capture at Lighthouse
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

			if(checkquestattribute("Jacks_early_days", "Petros_in_sight"))
			{
				dialog.text = DLG_TEXT[2] + GetMyFullName(Pchar) + DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];			
				link.l1.go = "Island_stuff";
//				LAi_SetActorType(PChar);				
			}
			if (checkquestattribute("Jacks_early_days", "Second_time_Petros"))
			{
				dialog.text = DLG_TEXT[7];
				link.l1 = DLG_TEXT[8];			
				link.l1.go = "Exit_to_Peter";
			}			
			if (checkquestattribute("Bonnie_talk", "Is_Blaze_in_QC"))
			{
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];			
				link.l1.go = "Arrival_at_Jamaica";
			}
			if(checkquestattribute("Bonnie_talk", "Needing_some_help") && checkquestattribute("NathanK_contract", "sealed"))
			{
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];			
				link.l1.go = "Island_stuff3";			
			}
		break;

		case "Island_stuff":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];			
			link.l1.go = "Exit_for_choice";
		break;	

		case "Ready_for_CCC_Quest":
			dialog.text = DLG_TEXT[9] + getmyname(Pchar) + DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];			
			link.l1.go = "Exit";
			LAi_ActorGoToLocator(characterFromID("Konrad Kulczycki"), "reload", "reload1", "",5.0);
			LAi_ActorGoToLocator(characterFromID("Peter Willemoes"), "reload", "reload1", "Leaving the room_Konrad2",5.0);			
			AddDialogExitQuest("Leaving the room_Konrad2");			
		break;
		
		case "Plan_for_CCC_Quest":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];			
			link.l1.go = "Plan_for_CCC_Quest2";
		break;

		case "Plan_for_CCC_Quest2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];			
			link.l1.go = "Plan_for_CCC_Quest3";
		break;
		
		case "Plan_for_CCC_Quest3":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];			
			link.l1.go = "Plan_for_CCC_Quest4";
			link.l2 = DLG_TEXT[18];			
			link.l2.go = "Exit_no_CCC_Quest";			
		break;		

		case "Plan_for_CCC_Quest4":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];			
			link.l1.go = "Exit_for_CCC_Quest";
		break;		

		case "Return_of_CCC":
			dialog.text = DLG_TEXT[28] + getmyname(Pchar) + DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];			
			link.l1.go = "Return_of_CCC2";
		break;

		case "Return_of_CCC2":
			dialog.text = DLG_TEXT[31] + getmyname(Pchar) + DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];			
			link.l1.go = "Return_of_CCC3";
		break;		

		case "Return_of_CCC3":
			dialog.text = DLG_TEXT[34] + getmyname(Pchar) + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];			
			link.l1.go = "Exit_Return_of_CCC";
		break;

// VVVVVVVVVVVVVVVVVTALISMAN CHANGES VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV

		case "Turks_after_Guadeloupe_capture":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];			
			link.l1.go = "Turks_after_Guadeloupe_capture2";
		break;
		
		case "Turks_after_Guadeloupe_capture2":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];			
			link.l1.go = "Turks_after_Guadeloupe_capture3";
		break;
		
		case "Turks_after_Guadeloupe_capture3":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];			
			link.l1.go = "Turks_after_Guadeloupe_capture4";
		break;
		
		case "Turks_after_Guadeloupe_capture4":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];			
			link.l1.go = "Turks_after_Guadeloupe_capture5";
		break;
		
		case "Turks_after_Guadeloupe_capture5":
			dialog.text = DLG_TEXT[45] + getmyname(Pchar) + DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];			
			link.l1.go = "Turks_after_Guadeloupe_capture6";
		break;
		
		case "Turks_after_Guadeloupe_capture6":
			dialog.text = DLG_TEXT[48] + getmyname(Pchar) + DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];			
			link.l1.go = "Turks_after_Guadeloupe_capture7";
		break;
		
		case "Turks_after_Guadeloupe_capture7":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];			
			link.l1.go = "Turks_after_Guadeloupe_capture8";
		break;
		
		case "Turks_after_Guadeloupe_capture8":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];			
			link.l1.go = "Exit_Turks_after_Guadeloupe_capture";
		break;
		
// ^^^^^^^^^^^^^^^^^End of TALISMAN changes ^^^^^^^^^^^^^^^^^^^^^^^^^^^^		
		case "tryout":
				dialog.text = DLG_TEXT[7];
				link.l1 = DLG_TEXT[8];			
				link.l1.go = "Exit_to_Peter";
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
		
		case "Exit_no_CCC_Quest":
			Locations[FindLocation("Guadeloupe_Plantation_inside")].reload.l1.disable = 0;		
			RemoveOfficersIndex(pchar, GetCharacterIndex("Peter Willemoes"));
			RemovePassenger(pchar, characterFromID("Peter Willemoes"));
			pchar.quest.Jacks_early_days = "Rescue_CCC";			
//			RemoveCompanion(pchar, characterFromID("Peter Willemoes"));			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_to_Peter":
			pchar.quest.Jacks_early_days = "And_now_Peter";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Peter_joins_in");			
		break;		
		
		case "Exit_for_choice":
			pchar.quest.Jacks_early_days = "And_now_Konrad";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Get_to_meet_Petros2");			
		break;		

		case "Exit_for_CCC_Quest":
			GiveItem2Character(Pchar,"Map_Doc_2");		
			Locations[FindLocation("Guadeloupe_Plantation_inside")].reload.l1.disable = 0;		
			SetOfficersIndex(Pchar, 2, getCharacterIndex("Mr. Gibbs"));		
			RemoveOfficersIndex(pchar, GetCharacterIndex("Peter Willemoes"));
			RemovePassenger(pchar, characterFromID("Peter Willemoes"));
//			RemoveCompanion(pchar, characterFromID("Peter Willemoes"));		
			pchar.quest.Jacks_early_days = "Looking_for_CCC";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Muelle_for_CCC");
		break;		

		case "Exit_Return_of_CCC":
			pchar.quest.Jacks_early_days = "And_now_Annamaria";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Go_to_meet_Annamaria_First");			
		break;
		
// TALISMAN added EXIT---->

		case "Exit_Turks_after_Guadeloupe_capture":
			if (GetAttribute(PChar, "Turks") == "Drow")
			{
				RemovePassenger(pchar, characterFromID("Cap'n Drow"));
				LAi_SetActorType(characterFromID("Cap'n Drow"));
				LAi_ActorGoToLocator(characterFromID("Cap'n Drow"), "reload", "reload3_back", "", 3.0);
			}
			LAi_SetActorType(characterFromID("Petros"));
			LAi_ActorGoToLocator(characterFromID("Petros"), "reload", "reload3_back", "", 3.0);
			pchar.quest.Jacks_early_days = "And_now_Annamaria";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Go_to_meet_Annamaria_First");
			SetShipRemovable(pchar, true);
			GiveShip2Character(pchar, "WickedWench", "Wicked Wench",-1,ENGLAND,true,true);	
		break;	

// <-----TALISMAN
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
