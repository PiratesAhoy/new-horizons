//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string gov_kid, gov_kid1, gov_kid2, merch_kid;
	string escapers = "";
	int x, y;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	if (PChar.sex == "man")
	{
		gov_kid = XI_ConvertString("her");
		gov_kid1 = XI_ConvertString("she");
		gov_kid2 = XI_ConvertString("daughter");
		merch_kid =XI_ConvertString( "him");
	}
	else
	{
		gov_kid = XI_ConvertString("him");
		gov_kid1 = XI_ConvertString("he");
		gov_kid2 = XI_ConvertString("son");
		merch_kid = XI_ConvertString("her");
	}
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "exit_reset":
			PChar.quest.speaker = NPChar.id;
			AddDialogExitQuest("reset_crewmember");
			Diag.CurrentNode = Diag.TempNode; //"First time";
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

		case "Rescued":
			if (isofficer(characterFromID("Louwe Louwman")) || isofficer(characterFromID("Giraldo Annibal")) || isofficer(characterFromID("Gheerkin Kamalaas")) || isofficer(characterFromID("Morys Badlad")))
			{
				dialog.text = DLG_TEXT[2];
				escapers = DLG_TEXT[4];
			}
			else dialog.text = DLG_TEXT[3];
			if (checkquestattribute("alignment", "evil")) link.l1 = escapers + DLG_TEXT[5];
			else link.l1 = escapers + DLG_TEXT[6];
			link.l1.go = "Exit";
		break;

		case "back_in_havana":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "back_in_havana2";
		break;

		case "back_in_havana2":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit";
		break;

		case "got_a_ship":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "got_a_ship2";
		break;

		case "got_a_ship2":
			if (checkquestattribute("alignment", "good")) dialog.text = DLG_TEXT[13];
			else dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit";
		break;

		case "follow_him":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "follow_him2";
		break;

		case "follow_him2":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit";
		break;

		case "crew_returning":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit";
		break;

		case "ready_for_payroll_ship":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit";
		break;

		case "payroll_ship_in_sight":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit";
		break;

		case "buccaneer_tavern_duel":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit";
		break;

		case "take_hostage_to_ship":
			if (PChar.sex == "woman") dialog.text = DLG_TEXT[29];
			else dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[30] + GetMyAddressForm(characterFromID(PChar.quest.romance), characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[31] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[32];
			link.l1.go = "exit";
		break;

		case "married_congrats":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
		break;

		case "abduction_move_ship":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
		break;

		case "abduction_officer_replace_romance":
			Preprocessor_Add("pronoun", gov_kid1);
			dialog.text = DLG_TEXT[41] + GetMySimpleName(characterfromID(PChar.quest.romance)) + DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
		break;

		case "abduction_romance_not_back":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37] + GetMySimpleName(characterfromID(PChar.quest.romance)) + DLG_TEXT[38];
			link.l1.go = "abduction_romance_not_back2";
		break;

		case "abduction_romance_not_back2":
			Preprocessor_Add("pronoun", gov_kid1);
			Preprocessor_Add("pronoun2", gov_kid);
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			AddDialogExitQuest("abduction_officer_return_town");
			link.l1.go = "exit";
		break;

		case "mona_attack_detach_fleet":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "mona_attack_detach_fleet2";
		break;

		case "mona_attack_detach_fleet2":
			dialog.text = DLG_TEXT[46];
			if (PChar.quest.alignment == "good") link.l1 = DLG_TEXT[47];
			else link.l1 = DLG_TEXT[48];
			link.l1.go = "mona_attack_detach_fleet3";
		break;

		case "mona_attack_detach_fleet3":
			dialog.text = DLG_TEXT[49];
			AddDialogExitQuest("mona_attack_detach_fleet");
			if (CheckAttribute(PChar, "quest.mona_attack_prepare_for_battle"))
			{
				link.l1 = DLG_TEXT[50];
				AddDialogExitQuest("mona_attack_return_to_fort");
			}
			else
			{
				link.l1 = DLG_TEXT[50] + DLG_TEXT[63];
				PChar.quest.mona_attack_prepare_for_battle = "fleet_done";
			}
			link.l1.go = "exit";
		break;

		case "mona_attack_french_on_way":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "exit";
		break;

		case "mona_attack_pass_battle_won":
			dialog.text = DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "mona_attack_pass_battle_won2";
		break;

		case "mona_attack_pass_battle_won2":
			dialog.text = DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "exit";
		break;

		case "mona_attack_rejoin_fleet":
			x = makeint(PChar.quest.mona_attack.original_fleet_size);
			y = GetCompanionQuantity(PChar);
			if ((x + y - 1) > COMPANION_MAX)
			{
				dialog.text = DLG_TEXT[51] + DLG_TEXT[53] + (y-1) + DLG_TEXT[54] + (x-1) + DLG_TEXT[55];
				link.l1 = DLG_TEXT[58];
				AddDialogExitQuest("mona_attack_goto_shipyard");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[51] + DLG_TEXT[52];
				link.l1 = DLG_TEXT[56] + GetMyName(CharacterFromID(PChar.quest.mona_attack.fleet_commander)) + DLG_TEXT[57];
				AddDialogExitQuest("mona_attack_rejoin_fleet2");
				link.l1.go = "exit";
			}
		break;

		case "mona_attack_rejoin_fleet_again":
			x = makeint(PChar.quest.mona_attack.original_fleet_size);
			y = GetCompanionQuantity(PChar);
			if ((x + y - 1) > COMPANION_MAX)
			{
				dialog.text = DLG_TEXT[59] + (x-1) + DLG_TEXT[60];
				link.l1 = DLG_TEXT[61];
				AddDialogExitQuest("mona_attack_goto_shipyard");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[62];
				link.l1 = DLG_TEXT[56] + GetMyName(CharacterFromID(PChar.quest.mona_attack.fleet_commander)) + DLG_TEXT[57];
				AddDialogExitQuest("mona_attack_rejoin_fleet2");
				link.l1.go = "exit";
			}
		break;

		case "hunt_what_we_did":
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "hunt_what_we_did2";
		break;

		case "hunt_what_we_did2":
			dialog.text = DLG_TEXT[72];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "exit";
		break;

		case "hunt_release_you":
			dialog.text = DLG_TEXT[74];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "hunt_take_knife":
			GiveItem2Character(PChar,"Barmansknife");
			EquipCharacterByItem(PChar,"Barmansknife");
			dialog.text = DLG_TEXT[75];
			link.l1 = DLG_TEXT[76];
			link.l1.go = "exit";
		break;

		case "hunt_well_done":
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			link.l1.go = "hunt_cooks_assistant";
		break;

		case "hunt_cooks_assistant":
			dialog.text = DLG_TEXT[79] + GetMySimpleName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "hunt_good_with_pan";
		break;

		case "hunt_good_with_pan":
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "hunt_cook_promotion";
		break;

		case "hunt_cook_promotion":
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "hunt_status_report";
		break;

		case "hunt_status_report":
			dialog.text = DLG_TEXT[86] + GetMySimpleName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "exit";
		break;

		case "hunt_rescue_crew_from_prison":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "hunt_how_escape";
		break;

		case "hunt_how_escape":
			dialog.text = DLG_TEXT[91];
			if (CheckCharacterItem(PChar, "fake_fort_release"))
			{
				link.l1 = DLG_TEXT[93] + DLG_TEXT[94];
				link.l1.go = "hunt_villain_nicked_stuff";
			}
			link.l2 = DLG_TEXT[92] + DLG_TEXT[94];
			link.l2.go = "hunt_villain_nicked_stuff";
		break;

		case "hunt_villain_nicked_stuff":
			Preprocessor_Add("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "exit";
		break;

		case "hunt_rescue_crew_what_now":
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "exit";
		break;

		case "hunt_rescue_glad_to_be_out":
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "exit";
		break;

		case "imperial_escort_cave_tactics":
			dialog.text = DLG_TEXT[101];
			if(CheckCharacterItem(PChar, "pistolgas"))
			{
				link.l1 = DLG_TEXT[102];
				link.l1.go = "exit_reset";
			}
			else
			{
				link.l1 = DLG_TEXT[104];
				link.l1.go = "imperial_escort_cave_tactics2";
				link.l2 = DLG_TEXT[103];
				link.l2.go = "exit_reset";				
			}
		break;

		case "imperial_escort_cave_tactics2":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "imperial_escort_cave_tactics3";
		break;

		case "imperial_escort_cave_tactics3":
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			PChar.quest.imperial_escort.cave_climber = NPChar.id;
			AddDialogExitQuest("imperial_escort_officer_prepare_climb_cave");
			link.l1.go = "exit_reset";
		break;

		case "imperial_escort_down_from_cave":
			dialog.text = "";
			link.l1 = DLG_TEXT[109];
			link.l1.go = "exit";
		break;
	}
}