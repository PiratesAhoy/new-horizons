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

			Dialog.mood = "normal";

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

			if(checkquestattribute("Jacks_early_days", "first_meeting"))
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];			
				link.l1.go = "Introduction_and_offer";
			}
			if (checkquestattribute("Jacks_early_days", "Mings_upstairs_meeting"))
			{
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];			
				link.l1.go = "Upstairs_meeting";
			}			
			if (checkquestattribute("Jacks_early_days", "Mings_compass_meeting"))
			{
				dialog.text = DLG_TEXT[41];
				link.l1 = DLG_TEXT[42];			
				link.l1.go = "Compass_meeting";
			}
			if (checkquestattribute("Jacks_early_days", "Mings_second_compass_meeting"))
			{
				dialog.text = DLG_TEXT[34] + Pchar.name + DLG_TEXT[35];
				link.l1 = DLG_TEXT[36];
				link.l1.go = "Compass_meeting2";
			}
		break;

		case "Introduction_and_offer":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyFullName(Pchar) + DLG_TEXT[4];
			link.l1.go = "Exit_to_Sit";			
//			link.l1.go = "Introduction2";
		break;

		case "Introduction2":
			Dialog.defAni = "Sit_Look_Around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "Sit_Look_Around";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Look_Around";
			Dialog.cam = "1";
			Dialog.snd = "voice\VIМА\VIМА008";
			
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];			
			link.l1.go = "Introduction3";
		break;

		case "Introduction3":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];			
			link.l1.go = "Introduction4";
		break;
		
		case "Introduction4":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];			
			link.l1.go = "Introduction5";
			link.l2 =DLG_TEXT[11];
			link.l2.go = "Introduction6";
		break;

		case "Introduction5":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];			
			link.l1.go = "Exit_for_upstairs_meeting";
		break;

		case "Introduction6":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];			
			link.l1.go = "Exit_Introduction_and leave";
		break;
		
		case "Upstairs_meeting":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];			
			link.l1.go = "Upstairs_meeting2";
		break;

		case "Upstairs_meeting2":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Upstairs_meeting3";
		break;

		case "Upstairs_meeting3":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Upstairs_meeting4";
		break;

		case "Upstairs_meeting4":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Upstairs_meeting5";
		break;

		case "Upstairs_meeting5":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Upstairs_meeting6";
		break;

		case "Upstairs_meeting6":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Upstairs_meeting7";
		break;

		case "Upstairs_meeting7":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Upstairs_meeting8";
		break;		

		case "Upstairs_meeting8":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_Upstairs_meeting";
		break;

		case "Compass_meeting":
			if (CheckCharacterItem(Pchar,"aztec_compass") && CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Compass_Meeting2";
			}
			if (CheckCharacterItem(Pchar,"aztec_compass") && !CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
			dialog.text = DLG_TEXT[44];			
			link.l2 = DLG_TEXT[47];
			link.l2.go = "Compass_Meeting2A";
			}
			if (!CheckCharacterItem(Pchar,"aztec_compass") && !CheckCharacterItem(Pchar,"Map_Doc_1"))
			{
			dialog.text = DLG_TEXT[45];			
			link.l3 = DLG_TEXT[48];			
			link.l3.go = "Compass_Meeting2X";
			ChangeCharacterReputation(pchar, -2);
			}
		break;

		case "Compass_Meeting2":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "Compass_Meeting3";
		break;

		case "Compass_Meeting3":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[57];
			AddMoneyToCharacter(pchar, +5000);			
			link.l1.go = "Exit_Compass_Meeting3";
		break;

		case "Compass_Meeting2A":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Compass_Meeting3A";
		break;

		case "Compass_Meeting3A":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Exit_Compass_Meeting3A";
		break;

		case "Compass_Meeting2X":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Exit_Compass_Meeting3X";
		break;		

		case "Solution_to_the_Mess":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "Solution_to_the_Mess2";
		break;		
		
		case "Solution_to_the_Mess2":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "Solution_to_the_Mess3";
		break;		
		
		case "Solution_to_the_Mess3":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "Exit_Solution_to_Mess";
		break;	

		case "Mings_A_fine_mess_to_sort":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Exit_Mess_to_Sort";
		break;

		case "Mings_summation":
			dialog.text = DLG_TEXT[67] + getmyname(pchar) + DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "Exit_Kell_Guadeloupe";
			link.l2 = DLG_TEXT[70];
			link.l2.go = "Exit_Konrad_and_Petros";
		break;		

		case "Exit_Konrad_and_Petros":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("KK_Petros_Kell_fleet");
		break;

		case "Exit_Kell_Guadeloupe":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Kell_and_me_to_Guadeloupe");
		break;
		
		case "Exit_Solution_to_Mess":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Discussion_with_Konrad_re_Wicked_Wench");
		break;
		
		case "Exit_Mess_to_Sort":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Discussion_with_Mings_and_Kell");
		break;
		
		case "Exit_Compass_Meeting3":
			AddQuestRecord("The Brotherhood",11);
			pchar.quest.Jacks_early_days = "Get_ready_for_Guadeloupe";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Off_with_Gibbs_to_Guadeloupe");
		break;
		
		case "Exit_Compass_Meeting3A":			
			pchar.quest.Jacks_early_days = "Mings_quest_Antigua";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Back_to_Antigua_for_Map");
		break;

		case "Exit_Compass_Meeting3X":			
			pchar.quest.Jacks_early_days = "NO_QUEST";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("End_of_Mings_Quest");
		break;		
		
		case "Exit_Upstairs_meeting":
			SetQuestHeader("The Brotherhood");
			AddQuestRecord("The Brotherhood",2);
			pchar.quest.Jacks_early_days = "Mings_First_run_Beckett";		
			AddMoneyToCharacter(pchar, +2000);
			ChangeCharacterReputation(pchar, +2);
			AddDialogExitQuest("Beckett_for_Mings");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_to_Sit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Sit_with_Sir_Christopher");
		break;

		case "Exit_Introduction_and leave":
			pchar.quest.Jacks_early_days = "first_meeting";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
//			AddDialogExitQuest("Start_Again_In_Tavern");	// GR: this doesn't seem to trigger
		break;

		case "Exit_for_upstairs_meeting":
			AddQuestRecord("The Brotherhood",1);
			pchar.quest.Jacks_early_days = "Upstairs_room";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Mings_step_two");
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
