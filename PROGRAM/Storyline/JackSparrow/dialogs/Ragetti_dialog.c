//#include "DIALOGS\Bootstrap Bill Turner_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
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
			Dialog.snd = "voice\PEDI\PEDI001";

			Dialog.mood = "normal";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

// -->SJG This is temporary dialog till Davy Jones character is done

			if (CheckQuestAttribute("Beckett", "Ragetti_Join"))
			{
				Dialog.snd = "voice\PEDI\PEDI002";
				Dialog.Text = DLG_TEXT[28];
				Link.l1 = DLG_TEXT[29];
				Link.l1.go = "starttoexplain";
			}
			if (CheckQuestAttribute("main_line", "resque_researcher_good"))
			{
				Dialog.snd = "voice\REDI\REDI002";
				dialog.text = DLG_TEXT[62];
				link.l1 = DLG_TEXT[63];
				link.l1.go = "exit";
			}
			if (CheckQuestAttribute("main_line", "resque_researcher_bad"))
			{
				Dialog.snd = "voice\REDI\REDI003";
				dialog.text = DLG_TEXT[64];
				link.l1 = DLG_TEXT[65];
				link.l1.go = "exit";
			}
			if (CheckQuestAttribute("main_line", "resque_researcher_complete"))
			{
				Dialog.snd = "voice\REDI\REDI004";
				Dialog.Text = DLG_TEXT[66] + DLG_TEXT[67];
				Link.l1 = DLG_TEXT[68];
				Link.l1.go = "to_oxbay_by_prisoner_escape_researcher_2";
			}
			if (CheckQuestAttribute("main_line", "meet_in_lighthouse"))
			{
				Dialog.snd = "voice\REDI\REDI005";
				dialog.text = DLG_TEXT[69];
				link.l1 = DLG_TEXT[70];
				link.l1.go = "exit";
				AddDialogExitQuest("first_speak_with_danielle_in_lighthouse")
			}
			if (CheckQuestAttribute("main_line", "blaze_search_danielle_again") || CheckQuestAttribute("main_line", "blaze_search_danielle_again_10"))
			{
				Dialog.snd = "voice\REDI\REDI006";
				dialog.text = DLG_TEXT[71] + DLG_TEXT[73];
				link.l1 = DLG_TEXT[74];
				link.l1.go = "blaze_search_danielle_again_2";
			}
			if (CheckQuestAttribute("main_line", "without_ship"))
			{
				Dialog.snd = "voice\REDI\REDI007";
				dialog.text = DLG_TEXT[75] + PChar.name + DLG_TEXT[76];
				link.l1 = DLG_TEXT[77];
				link.l1.go = "without_ship";
			}
			if (CheckQuestAttribute("main_line", "see_yaht"))
			{
				Dialog.snd = "voice\REDI\REDI008";
				dialog.text = DLG_TEXT[78];
				link.l1 = DLG_TEXT[79];
				link.l1.go = "see_yaht_2";
			}
//			Diag.TempNode = "first time";			
// <--SJG
			NextDiag.TempNode = "first time";
		break;

		case "node_2":
			Dialog.snd = "voice\PEDI\PEDI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "node_3";
		break;

		case "node_3":
			Dialog.snd = "voice\PEDI\PEDI004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			pchar.quest.main_line = "after_speak_with_peasant";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			EndQuestMovie();TrackQuestMovie("end","peasant_dialog.c -> Exit");
		break;

// -->SJG
		case "First_Meeting_With_Bootstrap_Tortuga":
			Dialog.snd = "voice\PEDI\PEDI004";
			dialog.text = DLG_TEXT[197];
			link.l1 = DLG_TEXT[198];
			link.l1.go = "Meeting_With_Bootstrap_Tortuga";
		break;

		case "Meeting_With_Bootstrap_Tortuga":
			Dialog.snd = "voice\PEDI\PEDI004";
			dialog.text = DLG_TEXT[199];
			link.l1 = DLG_TEXT[200];
			link.l1.go = "Meeting_With_Bootstrap_Tortuga2";
		break;

		case "Meeting_With_Bootstrap_Tortuga2":
			Dialog.snd = "voice\PEDI\PEDI004";
			dialog.text = DLG_TEXT[201];
			link.l1 = DLG_TEXT[202];
			link.l1.go = "Meeting_With_Bootstrap_Tortuga3";
		break;	

		case "Meeting_With_Bootstrap_Tortuga3":
			Dialog.snd = "voice\PEDI\PEDI004";
			dialog.text = DLG_TEXT[203];
			link.l1 = DLG_TEXT[204];
			link.l1.go = "Exit_Meeting_With_Bootstrap_Tortuga";
		break;

		case "Exit_Meeting_With_Bootstrap_Tortuga":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Bootstrapjoinscrew");
			AddQuestRecord("Mystery Woman",5);
		break;
		
		case "starttoexplain":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "cutin";
			EnableEquip(pchar, BLADE_ITEM_TYPE, true);
			EnableEquip(pchar, GUN_ITEM_TYPE, true);
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, BLADE_ITEM_TYPE));
			EquipCharacterByItem(pchar, FindCharacterItemByGroup(pchar, GUN_ITEM_TYPE));
		break;

		case "cutin":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Find_Ragetti_and_Pintel2");
		break;


		case "freeatlast3":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "freeatlast4";        
			Locations[FindLocation("Douwesen_shore_01")].reload.l2.disable = false;
			Locations[FindLocation("Douwesen_shore_01")].reload.l3.disable = false;

		break;

		case "freeatlast4":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "freeatlast5";
		break;

		case "freeatlast5":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "freeatlast6";
		break;

		case "freeatlast6":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "freeatlast7";
		break;

		case "freeatlast7":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "freeatlastExit";
		break;

		case "freeatlastexit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Bootstrapwandersoff");
		break;
		
		case "Bootstrap_at_Turks":
			dialog.text = DLG_TEXT[44] + PChar.lastname + DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "Bootstrap_at_Turks2";
		break;

		case "Bootstrap_at_Turks2":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Bootstrap_at_Turks3";
		break;

		case "Bootstrap_at_Turks3":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "Bootstrap_at_Turks4";
		break;

		case "Bootstrap_at_Turks4":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "Bootstrap_at_Turks5";
		break;

		case "Bootstrap_at_Turks5":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "Bootstrap_at_Turks6";
		break;

		case "Bootstrap_at_Turks6":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "Bootstrap_at_Turks7";
		break;

		case "Bootstrap_at_Turks7":
			dialog.text = DLG_TEXT[57] + PChar.name + DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "Bootstrap_at_Turks_exit";
		break;

		case "Bootstrap_at_Turks_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("BootstrapleavesTurks");
		break;

		case "Split_up_for_now":
			dialog.text = DLG_TEXT[205];
			link.l1 = DLG_TEXT[206];
			link.l1.go = "Exit_split_up";
		break;

		case "Exit_split_up":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Split_up_for_search");
		break;

		case "The_diamond_trade":
			dialog.text = DLG_TEXT[207];
			link.l1 = DLG_TEXT[208];
			link.l1.go = "Exit_diamond_trade";
		break;

		case "Join_with_Barbossa":
			dialog.text = DLG_TEXT[211];
			link.l1 = DLG_TEXT[212];
			link.l1.go = "Exit_Barbossa";
		break;

		case "Exit_Barbossa":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Bootstrap_leaves_ship");
			pchar.quest.Jacks_early_days = "xxx";
		break;

		case "Exit_diamond_trade":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Look_for_Eastwood");
			pchar.quest.Jacks_early_days = "xxx";
			AddQuestRecord("Mystery Woman",7);
		break;

		case "Looking_at_dead_body":
			dialog.text = DLG_TEXT[209];
			link.l1 = DLG_TEXT[210];
			link.l1.go = "Exit_dead_body";
		break;

		case "Exit_dead_body":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Look_for_Eastwood_again");
		break;
	}
}