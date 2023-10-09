//#include "DIALOGS\Sir Christopher Mings_dialog.h"
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

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if(checkquestattribute("Bonnie_talk", "Needing_some_help") && checkquestattribute("Mings_contract", "open"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];			
				link.l1.go = "Island_stuff";
			}
			if (checkquestattribute("Bonnie_talk", "Hunting_for_Blaze") && checkquestattribute("Chosen_Quest", "Mings"))
			{
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];			
				link.l1.go = "Exit";
			}			
			if (checkquestattribute("Bonnie_talk", "Is_Blaze_in_QC"))
			{
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];
				link.l1.go = "Arrival_at_QC";
			}
			if(checkquestattribute("Bonnie_talk", "Needing_some_help") && checkquestattribute("Mings_contract", "sealed"))
			{
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "Island_stuff3";
			}
		break;

		case "Island_stuff":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];			
			link.l1.go = "Exit_for_choice";
		break;

		case "Island_stuff3":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];			
			link.l1.go = "Island_stuff4";
		break;
		
		case "Island_stuff4":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];			
			link.l1.go = "Island_stuff5";
		break;

		case "Island_stuff5":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];			
			link.l1.go = "Island_stuff6";
		break;
		
		case "Island_stuff6":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];			
			link.l1.go = "Island_stuff7";
		break;

		case "Island_stuff7":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Island_stuff8";
		break;

		case "Island_stuff8":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Island_stuff";
		break;

		case "Arrival_at_QC":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Arrival_at_QC2";
		break;

		case "Arrival_at_QC2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "ExitQCArrival";
		break;

		case "Mings_buts_in_at_QC":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Mings_buts_in_at_QC2";
		break;

		case "Mings_buts_in_at_QC2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Mings_buts_in_at_QC3";
		break;		

		case "Mings_buts_in_at_QC3":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Mings_buts_in_at_QC4";
		break;

		case "Mings_buts_in_at_QC4":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Mings_buts_in_at_QC5";
		break;

		case "Mings_buts_in_at_QC5":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit_Mings_buts_in_at_QC";
		break;

		case "around_the_room":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "around_the_room2";
		break;

		case "around_the_room2":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Exit_around_the_room";
		break;

		case "Jamaica_here_we_come":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit_for_Jamaica";
		break;

		case "Exit_for_Jamaica":
			pchar.quest.Bonnie_talk = "Blaze_in_Jamaica";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Off_with_Mings_to_Jamaica");
		break;
		
		case "Exit_Island_stuff":
			pchar.quest.Mings_contract = "done";
			pchar.quest.Armada_contract = "done";
			pchar.quest.Catalina_contract = "done";
			pchar.quest.CCC_contract = "done";
			pchar.quest.Merciless_contract = "done";
			pchar.quest.Maximus_contract = "done";
			pchar.quest.Petros_contract = "done";
			pchar.quest.ThomasT_contract = "done";
			pchar.quest.NathanK_contract = "done";
			pchar.quest.Bonnie_talk = "Needing_family_help";
			pchar.quest.Chosen_Quest = "Mings";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Moving_right_along");
		break;

		case "Exit_for_choice":
			pchar.quest.Mings_contract = "sealed";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ExitQCArrival":
			ChangeCharacterAddressGroup(characterfromID("High Sea Lass"),"QC_residence", "goto", "goto3");			
			ChangeCharacterAddressGroup(characterfromID("Bartholomew Roberts"),"QC_residence", "goto", "goto4");
			ChangeCharacterAddressGroup(characterfromID("Morgan Terror"),"QC_town", "goto", "goto16");		
			pchar.quest.Bonnie_talk = "Talk_to_the_chief";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Sir_Christopher_Quest3");
		break;

		case "Exit_Mings_buts_in_at_QC":
			pchar.quest.Bonnie_talk = "Words_from_Skull";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Skull_speaks_up");
		break;

		case "Exit_around_the_room":
			pchar.quest.Bonnie_talk = "Words_from_others";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Others_speak_up");
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
