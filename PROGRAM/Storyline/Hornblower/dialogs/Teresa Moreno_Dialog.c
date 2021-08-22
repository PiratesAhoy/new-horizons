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
			link.l1.go = "Exit";
		break;

		case "This_is_my_plan":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "This_is_my_plan2";
		break;

		case "This_is_my_plan2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "This_is_my_plan3";
		break;

		case "This_is_my_plan3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "This_is_my_plan4";
		break;

		case "This_is_my_plan4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "This_is_my_plan5";
		break;

		case "This_is_my_plan5":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "This_is_my_plan6";
		break;

		case "This_is_my_plan6":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "This_is_my_plan7";
		break;

		case "This_is_my_plan7":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "This_is_my_plan8";
		break;

		case "This_is_my_plan8":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "This_is_my_plan9";
		break;

		case "This_is_my_plan9":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_This_is_my_plan";
		break;

		case "Exit_This_is_my_plan":
			AddDialogExitQuest("Hogan_and_Relict");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hogan_on_Guadeloupe":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_Hogan_on_Guadeloupe";
		break;

		case "Exit_Hogan_on_Guadeloupe":
			AddDialogExitQuest("Land_Guedeloupe_for_Hogan");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Hogan_Quest_Chatter":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_Hogan_Quest_Chatter";
		break;

		case "Exit_Hogan_Quest_Chatter":
			AddDialogExitQuest("Hogan_Step_three");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Fork_then_Left":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit_Fork_then_Left";
		break;

		case "Exit_Fork_then_Left":
			AddDialogExitQuest("Which_path_to_take");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Keep_to_the_right":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit_Keep_to_the_right";
		break;

		case "Exit_Keep_to_the_right":
			AddDialogExitQuest("Plantation_at_last");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Go_to_Hogans_house":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Go_to_Hogans_house2";
		break;

		case "Go_to_Hogans_house2":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Go_to_Hogans_house3";
		break;

		case "Go_to_Hogans_house3":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit_Go_to_Hogans_house";
		break;

		case "Exit_Go_to_Hogans_house":
			AddDialogExitQuest("walk_through_plantation");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "My_Mission":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit_My_Mission";
		break;

		case "Exit_My_Mission":
			AddDialogExitQuest("Hogan_Discussion4");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Richard_has_Gone":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Richard_has_Gone2";
		break;

		case "Richard_has_Gone2":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "Exit_Richard_has_Gone";
		break;

		case "Exit_Richard_has_Gone":
			AddDialogExitQuest("Next_stop_Church");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "I_will_get_Relic":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "I_will_get_Relic2";
		break;

		case "I_will_get_Relic2":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "Exit_I_will_get_Relic";
		break;

		case "Exit_I_will_get_Relic":
			AddDialogExitQuest("Gone_to_back_room");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "The_Relic_I_have":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "Exit_The_Relic_I_have";
		break;

		case "Exit_The_Relic_I_have":
			AddDialogExitQuest("Options_outside_church");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Relic_to_Ship":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "Exit_Relic_to_Ship";
		break;

		case "Exit_Relic_to_Ship":
			AddDialogExitQuest("Harper_on_Relic");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Take_Relic_to_Ship":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "Exit_Take_Relic_to_Ship";
		break;

		case "Exit_Take_Relic_to_Ship":
			AddDialogExitQuest("Chose_Teresa2");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "We_Part_Company":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "We_Part_Company2";
		break;

		case "We_Part_Company2":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "Exit_We_Part_Company";
		break;

		case "Exit_We_Part_Company":
			AddDialogExitQuest("Back_to_the_war");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Leave_you_with_Sharpe":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "Leave_you_with_Sharpe2";
		break;

		case "Leave_you_with_Sharpe2":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "Leave_you_with_Sharpe3";
		break;

		case "Leave_you_with_Sharpe3":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "Leave_you_with_Sharpe4";
		break;

		case "Leave_you_with_Sharpe4":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "Exit_Leave_you_with_Sharpe";
		break;

		case "Exit_Leave_you_with_Sharpe":
			AddDialogExitQuest("Hotspur_behind_us");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "looking_for_Wolfe":
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63];
			link.l1.go = "looking_for_Wolfe2";
		break;

		case "looking_for_Wolfe2":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "looking_for_Wolfe3";
		break;

		case "looking_for_Wolfe3":
			if(CheckQuestAttribute("know_about_Wolfe", "None"))
			{
				pchar.quest.know_about_Wolfe = "Moreno";
				SetQuestHeader("Hunt the Traitors");
				AddQuestRecord("Hunt the Traitors", 1);
			}
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "exit";

			Group_CreateGroup("wolfes_Ship"); 
			Group_AddCharacter("wolfes_Ship", "Thomas Wolfe");
			Group_SetGroupCommander("wolfes_Ship", "Thomas Wolfe");
			Group_SetTaskAttack("wolfes_Ship",  PLAYER_GROUP, true);
			Group_LockTask("wolfes_Ship"); 
			Sea_LoginGroupNow("wolfes_Ship");
			characters[GetCharacterIndex("Thomas Wolfe")].nosurrender = 2;
			Group_SetAddress("wolfes_Ship", "FalaiseDeFleur", "Quest_Ships","Quest_Ship_9");
		break;

	}
}
