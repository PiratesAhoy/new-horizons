//#include "DIALOGS\Claire Larrouse_dialog.h"

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
			
			// TIH --> no need to set these, as they just get reset below by something Aug31'06
			//dialog.text = DLG_TEXT[0];
			//link.l1 = DLG_TEXT[1];
			//link.l1.go = "exit";
			// TIH <--
			
			// Swindler 2006-07-03: Check, if PChar has too many ships to
			// start quest properly.
			// TIH --> fixed the ships check to be actual code Aug31'06
			int numFleet = GetCompanionQuantity(PChar);
			//bool tooManyShipsForQuest = GetCompanionIndex(pchar,1) != -1 && GetCompanionIndex(pchar,2) == -1 && GetCompanionIndex(pchar,3) == -1;
			//if (makeint(pchar.rank) > 4 && PChar.Quest.Story_OxbayCaptured == "1" && tooManyShipsForQuest) // PB: Can't get quest before Oxbay is captured
			if (sti(PChar.rank) > 4 && numFleet < COMPANION_MAX)
			{
				dialog.snd = "Voice\CLLA\CLLA001";
				//MAXIMUS: player already has a deal with NPC -->
				if(CheckAttribute(pchar,"quest.to_oxbay_mines_with_larrouse.win_condition.l1.location"))
				{
					dialog.text = DLG_TEXT[22] + " " + DLG_TEXT[66];
					link.l1 = DLG_TEXT[0];
					link.l1.go = "exit";
				}
				else
				{
					if (PChar.model == "50_33_40Claire") dialog.text = DLG_TEXT[76];
					else dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "begin";
				}
				//MAXIMUS: player already has a deal with NPC <--
			}
			else
			{
				dialog.snd = "Voice\CLLA\CLLA002";
				if (numFleet >= 4)
				{
					dialog.text = DLG_TEXT[1];
				} 
				else 
				{
					if (PChar.model == "50_33_40Claire") dialog.text = DLG_TEXT[77];
					else dialog.text = DLG_TEXT[4];
				}
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
				SetQuestHeader("larrouse");
				AddQuestrecord("larrouse", 1);
			}
			// TIH <--
			NextDiag.TempNode = "first time";
		break;

		case "begin":
			dialog.snd = "Voice\CLLA\CLLA003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "begin_2";
		break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_3";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "exit";
		break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "begin_4";
		break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA006";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "begin_6";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "exit";
		break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA007";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_7";
		break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA008";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			SetRumourState("Clair_start", false); // NK
			AddQuestRecord("larrouse", 2);
			SetCompanionIndex(pchar, -1, getcharacterIndex(npchar.id));
			SetCharacterRemovable(npchar, false);
			pchar.quest.to_oxbay_mines_with_larrouse.win_condition.l1 = "location";
			pchar.quest.to_oxbay_mines_with_larrouse.win_condition.l1.location = "Oxbay";
			pchar.quest.to_oxbay_mines_with_larrouse.win_condition = "to_oxbay_mines_with_larrouse_complete";
			npchar.location = "none";
		break;

		case "in_canyon":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			PlaceFleetNearShore("Oxbay_Lighthouse"); // PW fleet at lighthouse shore in case fight claire in canyon
			if (npchar.quest.goldmine == "0" || npchar.quest.goldmine == "1")
			{
				dialog.snd = "Voice\CLLA\CLLA009";
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];
				link.l1.go = "in_canyon_2";
			}
			else
			{
				dialog.snd = "Voice\CLLA\CLLA010";
				dialog.text = DLG_TEXT[22];
				link.l1 = DLG_TEXT[23];
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "in_canyon";
		break;

		case "in_canyon_2":
			dialog.snd = "Voice\CLLA\CLLA011";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "in_canyon_3";
		break;

		case "in_canyon_3":
			dialog.snd = "Voice\CLLA\CLLA012";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogexitQuest("to_the_gold_for_fight");
			npchar.quest.goldmine = "2";
		break;

		case "abording_mine":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\CLLA\CLLA013";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "abording_mine_1";
			NextDiag.TempNode = "abording_mine";
		break;

		case "abording_mine_1":
			dialog.snd = "Voice\CLLA\CLLA014";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "abording_mine_2";
			link.l2 = DLG_TEXT[32];
			link.l2.go = "abording_bad";

			locations[FindLocation("Oxbay_canyon")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l2.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l3.disable = 0;
			locations[FindLocation("Oxbay_canyon")].reload.l4.disable = 0;
		break;

		case "abording_mine_2":
			dialog.snd = "Voice\CLLA\CLLA015";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
			
			AddQuestRecord("larrouse", 3);
			pchar.quest.to_gold_konvoy.win_condition.l1 = "location";
			pchar.quest.to_gold_konvoy.win_condition.l1.location = "Oxbay_jungle_02";
			pchar.quest.to_gold_konvoy.win_condition = "to_gold_konvoy_complete";
			Locations[FindLocation("Oxbay_jungle_02")].vcskip = true; // KK
			AddDialogExitQuest("larrouse_becomes_officer");
		break;

		case "abording_bad":
			dialog.snd = "Voice\CLLA\CLLA016";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "abording_bad_fight_exit";
			link.l2 = DLG_TEXT[37];
			link.l2.go = "abording_mine_2";
		break;

		case "abording_bad_fight_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddQuestRecord("larrouse", 4);
			AddDialogExitQuest("abording_bad_fight_exit");
		break;

		case "kill_konvoy":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\CLLA\CLLA017";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";

			AddDialogExitQuest("konvoy_go_away");

			NextDiag.TempNode = "in_canyon";
		break;

		case "konvoy_away":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\CLLA\CLLA018";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";

			NextDiag.TempNode = "in_canyon";
			RemoveCharacterCompanion(pchar, npchar);
			AddDialogExitQuest("Clair_away");
		break;

		case "konvoy_killed":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\CLLA\CLLA019";
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "konvoy_killed_2";

			NextDiag.TempNode = "in_canyon";
		break;

		case "konvoy_killed_2":
			dialog.snd = "Voice\CLLA\CLLA020";
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "konvoy_killed_3";
		break;

		case "konvoy_killed_3":
			dialog.snd = "Voice\CLLA\CLLA021";
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";

			locations[FindLocation("Oxbay_jungle_02")].reload.l1.disable = 0;
			locations[FindLocation("Oxbay_jungle_03")].reload.l2.disable = 1;
			locations[FindLocation("Oxbay_jungle_03")].reload.l3.disable = 1;

			pchar.quest.escape_to_shore.win_condition.l1 = "location";
			pchar.quest.escape_to_shore.win_condition.l1.location = "Oxbay_shore_02";
			pchar.quest.escape_to_shore.win_condition = "escape_to_shore";
		break;

		case "escape_to_shore":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\CLLA\CLLA022";
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";

			AddDialogExitQuest("fighting_in_shore");

			NextDiag.TempNode = "in_canyon";
		break;

		case "fight_in_shore_completed":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\CLLA\CLLA023";
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "half";
			link.l2 = DLG_TEXT[52];
			link.l2.go = "want_more";
			link.l3 = DLG_TEXT[53];
			link.l3.go = "fight_in_shore_for_gold";

			NextDiag.TempNode = "in_canyon";
		break;

		case "half":
			dialog.snd = "Voice\CLLA\CLLA024";
			dialog.text = DLG_TEXT[54] + makeint(npchar.quest.goldmine)*10000 + DLG_TEXT[55] + makeint(npchar.quest.goldmine)*5000 + DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "half_2";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, makeint(npchar.quest.goldmine)*5000);
			if(AUTO_SKILL_SYSTEM)
			{
				AddCharacterExpChar(pchar, "Leadership", 2250);
				AddCharacterExpChar(pchar, "Sneak", 2250);
				AddPartyExpChar(pchar, "Leadership", 2250);
				AddPartyExpChar(pchar, "Sneak", 2250);
			}
			else
			{
				AddCharacterExp(pchar, 4500);
				AddPartyExp(pchar, 4500);
			}
		break;

		case "half_2":
			dialog.snd = "Voice\CLLA\CLLA025";
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "hire";
			link.l2 = DLG_TEXT[60];
			link.l2.go = "not_hire";
		break;

		case "hire":
			dialog.snd = "Voice\CLLA\CLLA026";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62] + GetMyName(NPChar) + DLG_TEXT[63];
			link.l1.go = "exit";
			AddQuestRecord("larrouse", 14);
			AddDialogExitQuest("from_shore_to_ship");
			SetCharacterRemovable(npchar, true);
		break;

		case "not_hire":
			dialog.snd = "Voice\CLLA\CLLA027";
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
			AddDialogExitQuest("from_shore_to_ship");
			pchar.quest.clair_to_muelle.win_condition.l1 = "location";
			pchar.quest.clair_to_muelle.win_condition.l1.location = "Oxbay";
			pchar.quest.clair_to_muelle.win_condition = "clair_to_muelle";
			RemoveCharacterCompanion(pchar, npchar);
			AddQuestRecord("larrouse", 13);
		break;

		case "for_hire":
			dialog.snd = "Voice\CLLA\CLLA028";
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[68];
			link.l2.go = "for_hire_2";
		break;

		case "for_hire_2":
			dialog.snd = "Voice\CLLA\CLLA029";
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "exit";
			AddPassenger(pchar, npchar, -1);
			SetCompanionIndex(pchar, -1, getCharacterIndex(npchar.id));
			npchar.dialog.currentnode = "to_canyon";
		break;

		case "want_more":
			dialog.snd = "Voice\CLLA\CLLA030";
			dialog.text  = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "half";
			link.l2 = DLG_TEXT[73];
			link.l2.go = "fight_in_shore_for_gold";
		break;

		case "fight_in_shore_for_gold":
			dialog.snd = "Voice\CLLA\CLLA031";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "exit";
			AddDialogExitQuest("abording_bad_fight_exit");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
