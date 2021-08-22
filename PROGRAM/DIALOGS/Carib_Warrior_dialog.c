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

		case "join_you":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "stay_on_ship";
		break;

		case "stay_on_ship":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "go_to_beach";
		break;

		case "go_to_beach":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
		break;

		case "follow_me1":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "bridge_warning":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "nobody_lives_there";
		break;

		case "nobody_lives_there":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "people_warning";
		break;

		case "people_warning":
			Preprocessor_AddQuestData("warrior", GetMyFullName(CharacterFromID("Carib_Warrior")));
			AddQuestRecord("crystal_skull", 5);
			Preprocessor_Remove("warrior");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
		break;

		case "walk_to_side":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "search_for_skull":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "you_not_find";
		break;

		case "you_not_find":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
		break;

		case "found_skull":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit"
		break;

		case "second_bridge_warning":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
		break;

		case "skull_stolen":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
		break;

		case "not_Karoukera":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
		break;

		case "give_him_skull":
			dialog.text = "";
			link.l1 = DLG_TEXT[28] + GetMySimpleName(NPChar) + DLG_TEXT[29];
			link.l1.go = "skull_sacred";
		break;

		case "skull_sacred":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "are_you_sure";
		break;

		case "are_you_sure":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "agree_to_give_skull";
		break;

		case "agree_to_give_skull":
			dialog.text = DLG_TEXT[34];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "trapped":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "cannibalism";
		break;

		case "cannibalism":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "what_you_eat";
		break;

		case "what_you_eat":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "bones";
		break;

		case "bones":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42] + GetMyLastName(CharacterFromID("Archaeologist_captain")) + DLG_TEXT[43];
			link.l1.go = "he_has_skull";
		break;

		case "he_has_skull":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "pirates";
		break;

		case "pirates":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			AddDialogExitQuest("crysskull_move_rock");
			link.l1.go = "exit";
		break;

		case "report_to_chief":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			Preprocessor_Add("Pronoun1", FirstLetterUp(XI_ConvertString(GetMyPronounSubj(PChar))));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(PChar)));
			dialog.text = DLG_TEXT[56];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "should_be_on_beach":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "exit";
		break;

// ---- The next couple of cases are for a crewman because I can't be bothered creating a whole new pair of dialog files for a couple of lines!
		case "found_skull_in_chest":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
		break;

		case "diver_found_skull":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "exit";
		break;

// ---- And this one is for an officer who will help you move a rock if "Carib_Warrior" is dead
		case "trapped_without_warrior":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53] + GetMySimpleName(CharacterFromID("Archaeologist_captain")) + DLG_TEXT[54];
			AddDialogExitQuest("crysskull_move_rock");
			link.l1.go = "exit";
		break;
	}
}