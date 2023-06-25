//#include "DIALOGS\Nigel Blythe_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit1":
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay7";
			Dialog.defCam = "8";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_9";
			Dialog.defLinkCam = "9";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
			
			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "continue";
				Link.l2 = DLG_TEXT[2];
				Link.l2.go = "kill_Art";
				NPC_meeting = "1";
			}
			else
			{
				d.Text = DLG_TEXT[3];
				Link.l1 = DLG_TEXT[4];
				Link.l1.go = "continue_kill";
			}
		break;

		case "continue_kill":
			NPChar.quest.officertype = OFFIC_TYPE_ABORDAGE;//MAXIMUS
			NPChar.quest.officerprice = 3000;//MAXIMUS
			d.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "not_listed";
			Link.l2 = DLG_TEXT[7];
			Link.l2.go = "listed_prepare";
		break;
		
		case "listed_prepare":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "listed_prepare_2";
		break;
		
		case "listed_prepare_2":
			dialog.text = DLG_TEXT[10];
			CalcEncOfficerPrice(NPChar)
//			if (makeint(pchar.money) >= CalcEncOfficerPrice(NPChar))	// LDH - should probably use this instead - 16Apr09
			if (makeint(pchar.money) >=sti(NPChar.quest.officerprice))//MAXIMUS
			{
				link.l1 = DLG_TEXT[11];
				link.l1.go = "listed";
			}
			link.l2 = DLG_TEXT[12];
			link.l2.go = "not_listed";
		break;

		case "not_used":
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "not_listed";
//			if (makeint(pchar.money) >= CalcEncOfficerPrice(NPChar))	// LDH - should probably use this instead - 16Apr09
			if (makeint(pchar.money) >=sti(NPChar.quest.officerprice))//MAXIMUS
			{
				Link.l2 = DLG_TEXT[15];
				Link.l2.go = "listed2";
			}
		break;

		case "not_listed":
			NPChar.quest.officerprice = 300;//MAXIMUS
			Diag.CurrentNode = "not_used";
			AddDialogExitQuest("Leave_Nigel");
			DialogExit();
		break;

		case "listed":
			AddDialogExitQuest("Nigel_listed");
			Diag.CurrentNode = "officer_Nig";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
		
		case "listed2":
			AddDialogExitQuest("Nigel_listed2");
			Diag.CurrentNode = "officer_Nig";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "kill_Art":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			AddDialogExitQuest("killing_artois");
		break;

		case "continue":
			AddDialogExitQuest("saving_artois");
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "officer_Nig":
			Diag.CurrentNode = "officer_Nig";
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase (DLG_TEXT[16], DLG_TEXT[17], DLG_TEXT[18], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "exit1";
		break;

		case "Setup1":
			d.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "setup_con1";
		break;

		case "Setup2":
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "con_parri";
		break;
		
		case "con_parri":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "con_parri_2";
		break;
		
		case "con_parri_2":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			Link.l1.go = "dismissed";
			link.l2 = DLG_TEXT[28];
			link.l2.go = "con_parri_off";
			link.l3 = DLG_TEXT[29];
			link.l3.go = "con_parri_3";
		break;
		
		case "con_parri_3":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "con_parri_4";
		break;
		
		case "con_parri_4":
			if (GetCurrentPeriod() < PERIOD_COLONIAL_POWERS)
			{
				dialog.text = DLG_TEXT[60];	// GR: alternative text for "a fluyt or maybe a small galleon"
				link.l1 = DLG_TEXT[61];		// instead of "a corvette or a frigate"
			}
			else
			{
				dialog.text = DLG_TEXT[32];
				link.l1 = DLG_TEXT[33];
			}
			link.l1.go = "con_parri_off";
			link.l2 = DLG_TEXT[34];
			link.l2.go = "con_parri_5";
		break;
		
		case "con_parri_off":
			DialogExit();
			if (GetCurrentPeriod() < PERIOD_COLONIAL_POWERS) AddQuestrecord("nigel", 29);
			else AddQuestrecord("nigel", 12);
			AddDialogExitQuest("nigel_third_encounter");
			ChangeCharacterReputation(pchar, -2);			
			characters[GetCharacterIndex("Nigel Blythe")].loyality = makeint(characters[GetCharacterIndex("Nigel Blythe")].loyality) - 1;
			AddPassenger(Pchar, characterFromID("Nigel Blythe"), 0);
			npchar.dialog.currentnode = "officer_Nig";
		break;
		
		case "con_parri_5":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			AddDialogExitQuest("con_parri_prepare");
			AddQuestrecord("nigel", 11);
		break;

		case "Setup_con1":
			d.Text = DLG_TEXT[37];
			Link.l1 = DLG_TEXT[38];
			Link.l1.go = "setup_con2";
		break;

		case "Setup_con2":
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "dismissed";
			Link.l2 = DLG_TEXT[41];
			Link.l2.go = "cargo_off";
			Link.l3 = DLG_TEXT[42];
			Link.l3.go = "cargo_on";
		break;
		
		case "smugglers":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "smugglers_2";
		break;
		
		case "smugglers_2":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "smugglers_exit";
			link.l2 = DLG_TEXT[47];
			link.l2.go = "smuglers_exit_fight";
		break;
		
		case "smugglers_exit":
			dialogexit();
			AddDialogExitQuest("nigel_smugglers_fight_prepare");
		break;
		
		case "smuglers_exit_fight":
			dialogexit();
			AddDialogExitQuest("we_and_nigel_smugglers_fight_prepare");
		break;
		
		case "smugglers_thanks":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			Link.l1.go = "dismissed";
			link.l2 = DLG_TEXT[50];
			link.l2.go = "smugglers_thanks_2";
		break;
		
		case "smugglers_thanks_2":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "exit";
			AddDialogExitQuest("nigel_fourth_encounter");
			AddDialogExitQuest("Nigel_Blythe_prepare_removal");
			SetCompanionIndex(Pchar, -1, GetCharacterIndex("Nigel Blythe")); // CTM
		//	SetCharacterRemovable(characterFromID("Nigel Blythe"), false); // PB
		break;

		case "dismissed":
			AddDialogExitQuest("Nigel_dissmissed");
			DialogExit();
		break;

		case "fired":
			Diag.CurrentNode = "fired";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit"
		break;

		case "cargo_off":
			AddDialogExitQuest("Nigel_cargo_off");
			AddDialogExitQuest("nigel_second_encounter");
			DialogExit();
		break;

		case "cargo_on":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "cargo_on_2";
		break;
		
		case "cargo_on_2":
			dialog.text = DLG_TEXT[57];
			if (GetSquadronFreeSpace(PChar, GOOD_CHOCOLATE) > 99)		//Petros changed from 199 so Lugger can load it
			{
				link.l1 = DLG_TEXT[58];
				link.l1.go = "exit";
				AddCharacterGoods(pchar, GOOD_CHOCOLATE, 100);	//Petros changed from 200 so Lugger can deliver
				AddDialogExitQuest("nigel_first_cargo_on");
			}
			else
			{
				link.l1 = DLG_TEXT[59];
				link.l1.go = "exit";
				AddDialogExitQuest("Nigel_cargo_off");
				AddDialogExitQuest("nigel_second_encounter");
			}
		break;
	}
}
