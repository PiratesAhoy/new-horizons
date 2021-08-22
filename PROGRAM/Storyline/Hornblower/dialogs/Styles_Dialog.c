//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
//			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

	
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "It's_very_quiet":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "It's_very_quiet2";
		break;

		case "It's_very_quiet2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit_It's_very_quiet";
		break;

		case "exit_It's_very_quiet":
			AddDialogExitQuest("Lighthouse_step_two");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Which_way_now":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit_Which_way_now";
		break;

		case "exit_Which_way_now":
			AddDialogExitQuest("Lighthouse_step_four");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Wolfe_not_here":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Wolfe_not_here2";
		break;

		case "Wolfe_not_here2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Wolfe_not_here3";
		break;

		case "Wolfe_not_here3":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit_Wolfe_not_here";
		break;

		case "Exit_Wolfe_not_here":
			AddDialogExitQuest("Where_is_Wolfe");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "How_far_fuse":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit_How_far_fuse";
		break;

		case "Exit_How_far_fuse":
			AddDialogExitQuest("Move_to_detonate");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "This_is_it":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_This_is_it";
		break;

		case "Exit_This_is_it":
			AddDialogExitQuest("Lighthouse_Bangs_Now");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "That_should_do_it":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_That_should_do_it";
		break;

		case "Exit_That_should_do_it":
			AddDialogExitQuest("Hammond_the_wimp");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Almost there":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_Almost there";
		break;

		case "Exit_Almost there":
			AddDialogExitQuest("Captured_by_Wolfe2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Where_marines":
			LAi_SetActorType(characterFromID("soldier1X"));
			LAi_ActorRunToLocator(characterFromID("soldier1X"), "goto", "goto07", "",4.0);
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Where_marines";
		break;

		case "Exit_Where_marines":
			AddDialogExitQuest("Captured_by_Wolfe_five");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bloody_Storeroom":
			PlaySound("VOICE\ENGLISH\Styles01.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit_Bloody_Storeroom";
		break;

		case "Exit_Bloody_Storeroom":
			AddDialogExitQuest("Crew_Wolfe_Prison5");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Bloody_Storeroom_two":
			PlaySound("VOICE\ENGLISH\Styles02.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Bloody_Storeroom_two";
		break;

		case "Exit_Bloody_Storeroom_two":
			AddDialogExitQuest("Crew_Wolfe_Prison8");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Church_Bells":
			PlaySound("AMBIENT\CHURCH\Town_alarm.wav");
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Church_Bells2";
		break;

		case "Church_Bells2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Church_Bells3";
		break;

		case "Church_Bells3":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Church_Bells4";
		break;

		case "Church_Bells4":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Church_Bells4A";
		break;

		case "Church_Bells4A":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "Church_Bells4B";
		break;

		case "Church_Bells4B":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "Church_Bells5";
		break;

		case "Church_Bells5":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Church_Bells6";
		break;

		case "Church_Bells6":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Church_Bells7";
		break;

		case "Church_Bells7":
			PlaySound("OBJECTS\duel\Fort_guns.wav");
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "Church_Bells8";
		break;

		case "Church_Bells8":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Church_Bells9";
		break;

		case "Church_Bells9":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Exit_Church_Bells";
		break;

		case "Exit_Church_Bells":
			AddDialogExitQuest("Hornblower_and_picklock5");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Found_Weapons":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Found_Weapons2";
		break;

		case "Found_Weapons2":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Exit_Found_Weapons";
		break;

		case "Exit_Found_Weapons":
			AddDialogExitQuest("Attack_the_Battery_Guns");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Plan_for_battery":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Plan_for_battery2";
		break;

		case "Plan_for_battery2":
			PlaySound("OBJECTS\duel\Fort_guns.wav");
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Plan_for_battery3";
		break;

		case "Plan_for_battery3":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "Exit_Plan_for_battery";
		break;

		case "Exit_Plan_for_battery":
			AddDialogExitQuest("Orders_for_attack_battery");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Shoot the gunners":
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "Exit_Shoot the gunners";
		break;

		case "Exit_Shoot the gunners":
			AddDialogExitQuest("Four_gunners_dead");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Spike_the_guns":
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "Exit_Spike_the_guns";
		break;

		case "Exit_Spike_the_guns":
			AddDialogExitQuest("Set_the_Charges_Guns");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Fort_Fuse_Lit":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "Exit_Fort_Fuse_Lit";
		break;

		case "Exit_Fort_Fuse_Lit":
			AddDialogExitQuest("Men_over_wall");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Almost_Home_Hotspur":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "Exit_Almost_Home_Hotspur";
		break;

		case "Exit_Almost_Home_Hotspur":
			AddDialogExitQuest("Hammond_Wolfe_Bush");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

	}
}
