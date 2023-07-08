
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];

	int your_rank = GetRank(PChar, ENGLAND);
	string your_rank_name;
	string el_supremo_short_name = GetAttribute(CharacterFromID("El Supremo"), "title") + " " + GetMyName(CharacterFromID("El Supremo"));

	if (your_rank == 6) your_rank_name = XI_ConvertString("Captain");
	else your_rank_name = XI_ConvertString(GetRankName(PChar, ENGLAND));

	PChar.quest.powder_needed = 500;
	PChar.quest.muskets_needed = 100;

	switch(Dialog.CurrentNode)
	{
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
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

			PlaySound("VOICE\ENGLISH\Pellew01.wav");
			if (your_rank < 6)
			{
				dialog.text = DLG_TEXT[0] + XI_ConvertString(GetRankName(PChar, ENGLAND)) + DLG_TEXT[1];
				link.l1 = DLG_TEXT[2];
				link.l1.go = "Exit";
			}
			else
			{
				dialog.text = DLG_TEXT[3] + GetMyLastName(PChar) + DLG_TEXT[4];
				link.l1 = DLG_TEXT[6];
				if (!CheckAttribute(NPChar, "your_old_rank") || sti(NPChar.your_old_rank) < your_rank)
				{
					NPChar.your_old_rank = your_rank;
					link.l1.go = "congrats";
				}
				else 
				{
					link.l1.go = "exit";
					if (your_rank == 6 && !CheckAttribute(NPChar, "quest.Natividad_given")) link.l1.go = "mission1_1";
				}
			}
		break;

		case "be_about_your_duty":
			Diag.TempNode = "be_about_your_duty";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
		break;

		case "congrats":
			dialog.text = DLG_TEXT[5] + XI_ConvertString(GetRankName(PChar, ENGLAND)) + ".";
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			if (your_rank == 6) link.l1.go = "mission1_1";
		break;

		case "mission1_1":
			NPChar.quest.Natividad_given = true;
			dialog.text = DLG_TEXT[9] + GetMyFullName(CharacterFromID("El Supremo")) + DLG_TEXT[10];
			if (FindCurrentStoryline() == FindStoryline("Hornblower"))
			{
				link.l1 = DLG_TEXT[11];
				link.l1.go = "mission1_2";
			}
			else
			{
				link.l1 = DLG_TEXT[14];
				link.l1.go = "mission1_2a";
			}
		break;

		case "mission1_2":
			dialog.text = el_supremo_short_name + DLG_TEXT[12] + el_supremo_short_name + DLG_TEXT[13];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "mission1_3";
		break;

		case "mission1_2a":
			dialog.text = el_supremo_short_name + DLG_TEXT[15] + el_supremo_short_name + DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "mission1_3";
		break;

		case "mission1_3":
			if (GetCharacterFreeSpace(PChar,GOOD_GUNPOWDER) >= makeint(PChar.quest.powder_needed))
			{
				dialog.text = DLG_TEXT[18];
				link.l1 = DLG_TEXT[19];
				link.l1.go = "exit_mission1_load_weapons";
			}
			else
			{
				dialog.text = DLG_TEXT[20] + "'" + PChar.Ship.Name + "'.";
				link.l1 = DLG_TEXT[21];
				link.l1.go = "exit_mission1_make_space";
			}
		break;

		case "mission1_3a":
			if (GetCharacterFreeSpace(PChar,GOOD_GUNPOWDER) >= makeint(PChar.quest.powder_needed))
			{
				dialog.text = DLG_TEXT[23] + your_rank_name + " " + GetMyLastName(PChar) + DLG_TEXT[24] + "'" + PChar.Ship.Name + "'" + DLG_TEXT[25];
				link.l1 = DLG_TEXT[26] + "'" + PChar.Ship.Name + "'" + ".";
				link.l1.go = "exit_mission1_load_weapons";
			}
			else
			{
				dialog.text = DLG_TEXT[22] + your_rank_name + " " + GetMyLastName(PChar) + ".";
				link.l1 = DLG_TEXT[21];
				link.l1.go = "exit_mission1_make_space";
			}
		break;

		case "great_report":
			NPChar.quest.Natividad_given = true;
			dialog.text = DLG_TEXT[27] + GetMyLastName(PChar) + DLG_TEXT[28];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "know_everyone";
		break;

		case "know_everyone":
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "ship_of_the_line1";
		break;

		case "ship_of_the_line1":
			dialog.text = DLG_TEXT[31] + GetMyLastName(PChar) + DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "ship_of_the_line2";
		break;

		case "ship_of_the_line2":
			dialog.text = DLG_TEXT[34] + PChar.Ship.Name + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			AddDialogExitQuest("Hornblower_get_Sutherland");
//			link.l1.go = "leighton_squadron";
			link.l1.go = "exit";
		break;

		case "leighton_squadron":
			if (GetCompanionQuantity(PChar) > 1)
			{
				dialog.text = DLG_TEXT[37] + "\n" + DLG_TEXT[41];
				link.l1 = DLG_TEXT[42];
				AddDialogExitQuest("Hornblower_dispose_of_prizes");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[37];
				link.l1 = "";
				link.l1.go = "blockade_Caribbean";
			}
		break;

		case "return_from_dispose_prizes":
			dialog.text = DLG_TEXT[43] + GetMyLastName(PChar) + DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "blockade_Caribbean";
		break;

		case "blockade_Caribbean":
			dialog.text = DLG_TEXT[38] + DLG_TEXT[39] + GetMyLastName(PChar) + DLG_TEXT[40];
			link.l1 = DLG_TEXT[46];
			AddDialogExitQuest("Hornblower_join_Leighton_squadron");
			link.l1.go = "exit";
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
	}
}
