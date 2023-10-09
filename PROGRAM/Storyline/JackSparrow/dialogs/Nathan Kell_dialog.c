//#include "DIALOGS\Nathan Kell_dialog.h"
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

		break;

		case "First_meet_in_Secret_Room":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];			
			link.l1.go = "First_meet_in_Church2";
		break;	

		case "First_meet_in_Church2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];			
			link.l1.go = "First_meet_in_Church3";
		break;
		
		case "First_meet_in_Church3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + GetMyFullName(Pchar) + DLG_TEXT[8];			
			link.l1.go = "First_meet_in_Church4";
		break;

		case "First_meet_in_Church4":
			giveItem2Character(Pchar,"Map_Doc_3");
			AddQuestRecord("Aztec",15); // TALISMAN - added quest book entry
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];			
			link.l1.go = "First_meet_in_Church5";
		break;
		
		case "First_meet_in_Church5":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];			
			link.l1.go = "First_meet_in_Church6";
		break;		

		case "First_meet_in_Church6":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];			
			link.l1.go = "Exit_First_meet_in_Church";
		break;		
		
		case "Exit_First_meet_in_Church":			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Moving_along_to_be_captured");
		break;

		case "The_Watchers_over_there":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit_talk_about_other_plansxxx";
		break;

		case "talk_about_other_plans":
			dialog.text = DLG_TEXT[15] + getmyname(Pchar) + DLG_TEXT[16] + DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];			
			link.l1.go = "talk_about_other_plans2";
		break;		

		case "talk_about_other_plans2":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];			
			link.l1.go = "talk_about_other_plans3";
		break;

		case "talk_about_other_plans3":		
			dialog.text = DLG_TEXT[21] + getmyname(Pchar) + DLG_TEXT[16];
			link.l1 = DLG_TEXT[22] + getmyname(Pchar) + DLG_TEXT[23];			
			link.l1.go = "talk_about_other_plans4";
		break;

		case "talk_about_other_plans4":
			LAi_ActorGoToLocator(characterFromID("Captain Damski"), "Reload", "Reload1", "", 5.0);		
			dialog.text = DLG_TEXT[24] + getmyname(Pchar) + DLG_TEXT[25] + getmyname(Pchar) + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];			
			link.l1.go = "Exit_talk_about_other_plans";
		break; 

		case "Exit_talk_about_other_plans":			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("With_Kell_to_Oxbay");
		break;

		case "Exit_talk_about_other_plansxxx":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("With_Kell_to_OxbayXXX");
		break;

		case "A_fine_mess_to_sort":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];			
			link.l1.go = "Exit_A_fine_mess_to_sort";
		break;

		case "Exit_A_fine_mess_to_sort":			
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Kell_talks_to_Mings_Oxbay");
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Jocard_dead":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Jocard_dead2";
		break;

		case "Jocard_dead2":
			dialog.text = DLG_TEXT[34];
			link.l1 =DLG_TEXT[35];
			link.l1.go = "Jocard_dead3";
		break;

		case "Jocard_dead3":
			dialog.text = DLG_TEXT[36];
			link.l1 =DLG_TEXT[37];
			link.l1.go = "Jocard_dead4";
		break;

		case "Jocard_dead4":
			dialog.text = DLG_TEXT[38];
			link.l1 =DLG_TEXT[39];
			AddDialogExitQuest("Killing_PL_talked_to_Kell");
			link.l1.go = "exit";
		break;
	}
}
