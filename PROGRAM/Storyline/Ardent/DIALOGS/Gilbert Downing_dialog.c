//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string gov_kid, merch_kid, your_kid, your_kid2, pronoun, pronoun2, pronoun3;
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	if (Characters[GetCharacterIndex(PChar.quest.villain)].sex == "man")
	{
		merch_kid = DLG_TEXT[89];
		your_kid = DLG_TEXT[91];
		your_kid2 = DLG_TEXT[93];
	}
	else
	{
		merch_kid = DLG_TEXT[90];
		your_kid = DLG_TEXT[92];
		your_kid2 = DLG_TEXT[94];
	}
	pronoun = XI_ConvertString(GetMyPronounSubj(CharacterFromId(PChar.quest.villain))); // "he" / "she"
	pronoun2 = XI_ConvertString(GetMyPronounPossessive(CharacterFromId(PChar.quest.villain))); // "his" / "her"
	pronoun3 = XI_ConvertString(GetMyPronounObj(CharacterFromId(PChar.quest.villain))); // "him" / "her"

	DeleteQuestAttribute("ardent_kidnap.find_merchant");
	
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

			dialog.text = DLG_TEXT[0] + GetMyLastName(characterFromID(PChar.quest.villain)) + DLG_TEXT[1];
			if(CheckAttribute(PChar,"quest.ardent_kidnap"))
			{
				link.l1 = DLG_TEXT[3];
				link.l1.go = "ask_kid";
			}
			if(CheckQuestAttribute("abduction_status", "pirate_rescued") || CheckQuestAttribute("abduction_status", "married_villain"))
			{
				link.l1 = DLG_TEXT[7] + GetMyFullName(characterFromID(PChar.quest.romance)) + ".";
				link.l1.go = "abduction_visit1_2";
			}
			link.l2 = DLG_TEXT[2];
			link.l2.go = "exit";
		break;

		case "ask_kid":
			dialog.text = DLG_TEXT[4] + merch_kid + ", " + GetMyFirstNames(CharacterFromID(PChar.quest.villain), false) + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
		break;

		case "abduction_visit1":
			dialog.text = DLG_TEXT[0] + GetMyLastName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[7] + GetMyFullName(CharacterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "abduction_visit1_2";
		break;

		case "abduction_visit1_2":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromId(PChar.quest.romance)))); // "she" / "he"
			dialog.text = DLG_TEXT[8] + merch_kid + ", " + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + ".";
			link.l1 = DLG_TEXT[9] + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[10];
			link.l1.go = "abduction_visit1_3";
		break;

		case "abduction_visit1_3":
			dialog.text = DLG_TEXT[11];
			switch(PChar.quest.revenge_type)
			{
				case "san_juan":
					link.l1 = DLG_TEXT[12] + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[13];
				break;

				case "officer":
					Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromId(PChar.quest.romance)))); // "she" / "he"
					link.l1 = DLG_TEXT[37] + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[38] + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[13];
				break;
			}
			link.l1.go = "abduction_visit1_4";
		break;

		case "abduction_visit1_4":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			Diag.TempNode = "hostile";
			AddDialogExitQuest("abduction_port_royale_witness");
			link.l1.go = "exit";
		break;

		case "hostile":
			NPChar.quest.attitude = "hostile";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "abduction_where_did_you_come_from":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "abduction_where_did_you_come_from2";
		break;

		case "abduction_where_did_you_come_from2":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21] + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + DLG_TEXT[22] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[23];
			link.l1.go = "abduction_where_did_you_come_from3";
		break;

		case "abduction_where_did_you_come_from3":
			dialog.text = DLG_TEXT[24] + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[25] + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + ".";
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromId(PChar.quest.romance)))); // "she" / "he"
			link.l1 = DLG_TEXT[26];
			link.l1.go = "abduction_where_did_you_come_from4";
		break;

		case "abduction_where_did_you_come_from4":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			Diag.TempNode = "hostile";
			GiveItem2Character(PChar, "lockpick");
			AddDialogExitQuest("abduction_got_lockpick");
			PlayStereoSound("INTERFACE\important_item.wav");
			Logit(TranslateString("","You have been given a lockpick."));
			link.l1.go = "exit";
		break;

		case "abduction_romance_released":
			dialog.text = DLG_TEXT[29];
			Preprocessor_Add("your_kid", your_kid);
			link.l1 = DLG_TEXT[30] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[31];
			AddDialogExitQuest("abduction_romance_confronts_merchant");
			link.l1.go = "exit";
		break;

		case "abduction_merchant_refuses_to_betray":
//			if (Characters[GetCharacterIndex(PChar.quest.villain)].sex == "man") Preprocessor_Add("pronoun2", "his");
//			else  Preprocessor_Add("pronoun2", "her");
			Preprocessor_Add("pronoun2", pronoun2); // "his" / "her"
			Preprocessor_Add("pronoun3", pronoun3); // "him" / "her"
			dialog.text = DLG_TEXT[32] + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + DLG_TEXT[33] + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + DLG_TEXT[34];
			link.l1 = DLG_TEXT[35] + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + DLG_TEXT[36];
			link.l1.go = "exit";
		break;

		case "kidnap_rescue_buy_wine":
			Preprocessor_Add("your_kid", your_kid);
			dialog.text = DLG_TEXT[0] + GetMyLastName(characterFromID(PChar.quest.villain)) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[39] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[40];
			link.l1.go = "kidnap_rescue_wine_gone";
		break;

		case "kidnap_rescue_wine_gone":
			PChar.quest.ardent_kidnap.status = "no_wine";
//			if (Characters[GetCharacterIndex(PChar.quest.villain)].sex == "man") Preprocessor_Add("pronoun2", "his");
//			else  Preprocessor_Add("pronoun2", "her");
			Preprocessor_Add("pronoun2", pronoun2);
			dialog.text = DLG_TEXT[41] + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			AddDialogExitQuest("kidnap_rescue_setup_witness");
			link.l1.go = "exit";
		break;

		case "hunt_ask_gilbert":
			if (CheckAttribute(NPChar, "quest.attitude") && NPChar.quest.attitude == "hostile") dialog.text = DLG_TEXT[44];
			else dialog.text = DLG_TEXT[0] + GetMyLastName(characterFromID(PChar.quest.villain)) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[45] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[46];
			link.l1.go = "hunt_prove_it";
		break;

		case "hunt_prove_it":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "hunt_not_proven";
		break;

		case "hunt_not_proven":
			Preprocessor_Add("your_kid2", your_kid2);
//			if (Characters[GetCharacterIndex(PChar.quest.villain)].sex == "man") Preprocessor_Add("pronoun2", "his");
//			else  Preprocessor_Add("pronoun2", "her");
			Preprocessor_Add("pronoun2", pronoun2); // "his" / "her"
			dialog.text = DLG_TEXT[49] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[50];
			if (CheckAttribute(NPChar, "quest.attitude") && NPChar.quest.attitude == "hostile") link.l1 = DLG_TEXT[51] + DLG_TEXT[52] + GetMyFullName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[53] + DLG_TEXT[54] + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + DLG_TEXT[55];
			else link.l1 = DLG_TEXT[51] + DLG_TEXT[54] + GetMyFirstNames(characterFromID(PChar.quest.villain), false) + DLG_TEXT[55];
			link.l1.go = "hunt_still_not_betray";
		break;

		case "hunt_still_not_betray":
			Preprocessor_Add("kid", merch_kid);
			Preprocessor_Add("pronoun", pronoun); // "he" / "she"
			if (Characters[GetCharacterIndex(PChar.quest.villain)].sex == "man") dialog.text = DLG_TEXT[56];
			else dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[59] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[60] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[61];
			link.l1.go = "hunt_honour";
		break;

		case "hunt_honour":
			Preprocessor_Add("kid", merch_kid);
			if (Characters[GetCharacterIndex(PChar.quest.villain)].sex == "man") dialog.text = DLG_TEXT[62];
			else dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "hunt_no_choice";
		break;

		case "hunt_no_choice":
			Preprocessor_Add("pronoun", pronoun); // "he" / "she"
			dialog.text = DLG_TEXT[65] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[66];
			link.l1 = DLG_TEXT[67];
			link.l1.go = "hunt_ship_unknown";
		break;

		case "hunt_ship_unknown":
			dialog.text = DLG_TEXT[68] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			AddDialogExitQuest("hunt_villain_to_st_martin");
			link.l1.go = "exit";
		break;

		case "museum_open":
			dialog.text = DLG_TEXT[71] + GetMyRespectfullyName(PChar) + DLG_TEXT[72];
			if (makeint(PChar.money) >= 20)
			{
				link.l1 = DLG_TEXT[73];
				link.l1.go = "museum_buy_ticket";
			}
			link.l2 = DLG_TEXT[74];
			link.l2.go = "museum_no_ticket";
			link.l3 = DLG_TEXT[75];
			link.l3.go = "museum_in_without_paying";
		break;

		case "museum_buy_ticket":
			dialog.text = DLG_TEXT[81];
			Diag.TempNode = "First time";
			AddDialogExitQuest("museum_gilbert_opens_door");
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, -20);
			link.l1 = DLG_TEXT[82];
			link.l1.go = "exit";
		break;

		case "museum_no_ticket":
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			Diag.TempNode = "museum_try_again";
			link.l1.go = "exit";
		break;

		case "museum_try_again":
			dialog.text = DLG_TEXT[85] + GetMyRespectfullyName(PChar) + DLG_TEXT[86];
			if (makeint(PChar.money) >= 20)
			{
				link.l1 = DLG_TEXT[73];
				link.l1.go = "museum_buy_ticket";
			}
			link.l2 = DLG_TEXT[74];
			link.l2.go = "museum_no_ticket";
			link.l3 = DLG_TEXT[75];
			link.l3.go = "museum_in_without_paying";
		break;

		case "museum_in_without_paying":
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "museum_other_way_in";
		break;

		case "museum_other_way_in":
			dialog.text = DLG_TEXT[78];
			if (makeint(PChar.money) >= 20)
			{
				link.l1 = DLG_TEXT[79];
				link.l1.go = "museum_buy_ticket";
			}
			link.l2 = DLG_TEXT[80];
			link.l2.go = "museum_no_ticket";
		break;

		case "museum_go_in":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "exit";
		break;
	}
}