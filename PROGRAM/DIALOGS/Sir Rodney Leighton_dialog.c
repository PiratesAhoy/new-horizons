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
	int your_rank = GetRank(PChar, ENGLAND);
	string your_rank_name;
	string el_supremo_short_name = GetAttribute(CharacterFromID("El Supremo"), "title") + " " + GetMyName(CharacterFromID("El Supremo"));

	if (your_rank == 6) your_rank_name = "Captain";
	else your_rank_name = GetRankName(PChar, ENGLAND);

	PChar.quest.powder_needed = 500;
	PChar.quest.muskets_needed = 100;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "be_about_your_duty":
			Diag.TempNode = "be_about_your_duty";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
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

			if (your_rank < 6)
			{
				dialog.text = DLG_TEXT[0] + GetRankName(PChar, ENGLAND) + DLG_TEXT[1];
				link.l1 = DLG_TEXT[2];
				link.l1.go = "Exit";
			}
			else
			{
				if (!CheckAttribute(NPChar, "already_met"))
				{
					dialog.text = DLG_TEXT[3];
					link.l1 = DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5];
					NPChar.already_met = 1;
				}
				else
				{
					dialog.text = DLG_TEXT[6] + your_rank_name + " " + GetMyLastName(PChar) + DLG_TEXT[7];
					link.l1 = DLG_TEXT[9];
				}
				if (!CheckAttribute(NPChar, "your_old_rank") || sti(NPChar.your_old_rank) != your_rank)
				{
					NPChar.your_old_rank = your_rank;
					link.l1.go = "congrats";
				}
				else 
				{
					link.l1.go = "exit";
					if (your_rank == 6) link.l1.go = "mission1_1";
				}
			}
		break;

		case "congrats":
			dialog.text = DLG_TEXT[8] + GetRankName(PChar, ENGLAND) + ".";
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			if (your_rank == 6) link.l1.go = "mission1_1";
		break;

		case "mission1_1":
			dialog.text = DLG_TEXT[12] + GetMyFullName(CharacterFromID("El Supremo")) + DLG_TEXT[13];
			if (FindCurrentStoryline() == FindStoryline("Hornblower"))
			{
				link.l1 = DLG_TEXT[14];
				link.l1.go = "mission1_2";
			}
			else
			{
				link.l1 = DLG_TEXT[17];
				link.l1.go = "mission1_2a";
			}
		break;

		case "mission1_2":
			dialog.text = el_supremo_short_name + DLG_TEXT[15] + el_supremo_short_name + DLG_TEXT[16];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "mission1_3";
		break;

		case "mission1_2a":
			dialog.text = el_supremo_short_name + DLG_TEXT[18] + el_supremo_short_name + DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "mission1_3";
		break;

		case "mission1_3":
			if (GetCharacterFreeSpace(PChar,GOOD_GUNPOWDER) >= makeint(PChar.quest.powder_needed))
			{
				dialog.text = DLG_TEXT[21];
				link.l1 = DLG_TEXT[22];
				link.l1.go = "exit_mission1_load_weapons";
			}
			else
			{
				dialog.text = DLG_TEXT[23] + "'" + PChar.Ship.Name + "'.";
				link.l1 = DLG_TEXT[24];
				link.l1.go = "exit_mission1_make_space";
			}
		break;

		case "mission1_3a":
			if (GetCharacterFreeSpace(PChar,GOOD_GUNPOWDER) >= makeint(PChar.quest.powder_needed))
			{
				dialog.text = DLG_TEXT[26] + your_rank_name + " " + GetMyLastName(PChar) + DLG_TEXT[27] + "'" + PChar.Ship.Name + "'" + DLG_TEXT[28];
				link.l1 = DLG_TEXT[29] + "'" + PChar.Ship.Name + "'" + ".";
				link.l1.go = "exit_mission1_load_weapons";
			}
			else
			{
				dialog.text = DLG_TEXT[25] + your_rank_name + " " + GetMyLastName(PChar) + ".";
				link.l1 = DLG_TEXT[24];
				link.l1.go = "exit_mission1_make_space";
			}
		break;

		case "exit_mission1_load_weapons":
			AddCharacterGoods(pchar, GOOD_GUNPOWDER, makeint(PChar.quest.powder_needed));
			TakeNItems(PChar, "pistolmketB", makeint(PChar.quest.muskets_needed));
			Diag.CurrentNode = "be_about_your_duty";
			AddDialogExitQuest("hornblower_place_el_supremo");
			PChar.quest.hornblower_extra_missions = "weapons_aboard";
			bQuestDisableSeaEnter = false;
			DialogExit();
		break;

		case "exit_mission1_make_space":
			PChar.quest.hornblower_extra_missions = "make_space_for_weapons";
			bQuestDisableSeaEnter = true;
			Diag.CurrentNode = "mission1_3a";
			DialogExit();
		break;

		case "bridgetown_intro":
			dialog.text = "";
			link.l1 = your_rank_name + " " + GetMyLastName(PChar) + DLG_TEXT[40];
			link.l1.go = "lady_barbara_aboard";
		break;

		case "lady_barbara_aboard":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "famous_exploits";
		break;

		case "famous_exploits":
			dialog.text = DLG_TEXT[43] + your_rank_name + DLG_TEXT[44] + GetCannonMaxQuantity(PChar) + DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "very_fortunate";
		break;

		case "very_fortunate":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "admiralty_policy";
		break;

		case "admiralty_policy":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "you_gave_away_prize";
		break;

		case "you_gave_away_prize":
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "irresponsible_action";
		break;

		case "irresponsible_action":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "to_be_married";
		break;

		case "to_be_married":
			dialog.text = DLG_TEXT[55] + your_rank_name + DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "free_confidences";
		break;

		case "free_confidences":
			dialog.text = DLG_TEXT[58];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "here_you_are_my_dear":
			dialog.text = DLG_TEXT[59];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "families":
			dialog.text = DLG_TEXT[60];
			link.l1 = "";
			link.l1.go = "exit";
		break;
	}
}