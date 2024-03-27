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
	if (your_rank == 6) your_rank_name = XI_ConvertString("Captain");
	else your_rank_name = XI_ConvertString(GetRankName(PChar, ENGLAND));

	int muskets, powder;
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
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
			link.l1.go = "talk_to_admiral";
		break;

		case "talk_to_admiral":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
		break;

		case "meet_Hornblower":
			if (GetCargoGoods(PChar, GOOD_GUNPOWDER) < makeint(PChar.quest.powder_needed) || GetCharacterItem(PChar, "pistolmketB") < makeint(PChar.quest.muskets_needed))
			{
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "delivery_failure2";
			}
			else
			{
				dialog.text = DLG_TEXT[11];
				link.l1 = DLG_TEXT[12];
				link.l1.go = "exit";
				Diag.TempNode = "meet_Hornblower";
			}
		break;

		case "delivery_failure":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "delivery_failure2";
		break;

		case "delivery_failure2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "bluff_called";
		break;

		case "bluff_called":
			if (FindCurrentStoryline() == FindStoryline("hornblower")) dialog.text = DLG_TEXT[8] + DLG_TEXT[9];
			else dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[10];
			AddDialogExitQuest("hornblower_execution");
			link.l1.go = "exit";
		break;

		case "introduction":
			dialog.text = "";
			link.l1 = your_rank_name + " " + GetMySimpleName(PChar) + DLG_TEXT[11];
			link.l1.go = "introduction2";
		break;

		case "introduction2":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "have_you_brought_stuff";
		break;

		case "have_you_brought_stuff":
			dialog.text = DLG_TEXT[14];
			if (GetCharacterItem(PChar, "pistolmketB") < makeint(PChar.quest.muskets_needed)) muskets = GetCharacterItem(PChar, "pistolmketB");
			else muskets = makeint(PChar.quest.muskets_needed);
			if (GetCargoGoods(PChar, GOOD_GUNPOWDER) < makeint(PChar.quest.powder_needed)) powder = GetCargoGoods(PChar, GOOD_GUNPOWDER);
			else powder = makeint(PChar.quest.powder_needed);
			link.l1 = muskets + DLG_TEXT[15] + powder + DLG_TEXT[16];
			if (GetCargoGoods(PChar, GOOD_GUNPOWDER) < makeint(PChar.quest.powder_needed) || GetCharacterItem(PChar, "pistolmketB") < makeint(PChar.quest.muskets_needed)) link.l1.go = "delivery_failure";
			else link.l1.go = "land_your_cargo";
		break;

		case "land_your_cargo":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "i_gave_order";
		break;

		case "i_gave_order":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20] + PChar.Ship.Name + DLG_TEXT[21];
			link.l1.go = "fort_threatened";
		break;

		case "fort_threatened":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			AddDialogExitQuest("Hornblower_El_Supremo_checks_window");
			link.l1.go = "exit";
		break;

		case "we_are_allies":
			dialog.text = DLG_TEXT[24];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "next_move":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "burning_city";
		break;

		case "burning_city":
			dialog.text = DLG_TEXT[27];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "Natividad_announced":
			dialog.text = DLG_TEXT[28] + your_rank_name + DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "Natividad_announced2";
		break;

		case "Natividad_announced2":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "Natividad_announced3";
		break;

		case "Natividad_announced3":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "Natividad_announced4";
		break;

		case "Natividad_announced4":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "capture_Natividad";
		break;

		case "capture_Natividad":
			Preprocessor_Add("rank", your_rank_name);
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "capture_Natividad2";
		break;

		case "capture_Natividad2":
			dialog.text = DLG_TEXT[39] + your_rank_name + DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "capture_Natividad3";
		break;

		case "capture_Natividad3":
			dialog.text = DLG_TEXT[42] + your_rank_name + DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			AddQuestRecord("Natividad", 4);
			link.l1.go = "exit";
		break;

		case "wrong_signal":
			dialog.text = DLG_TEXT[45] + your_rank_name + DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "disrespect";
		break;

		case "disrespect":
			dialog.text = DLG_TEXT[48] + your_rank_name + DLG_TEXT[49];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "you_did_not_kill_many":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "where_are_officers";
		break;

		case "where_are_officers":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "future_plans";
		break;

		case "future_plans":
			dialog.text = DLG_TEXT[54];
			link.l1 = "";
			link.l1.go = "exit";
		break;
	}
}