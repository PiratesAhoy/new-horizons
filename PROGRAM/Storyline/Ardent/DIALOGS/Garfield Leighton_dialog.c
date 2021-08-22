//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	string governors_kid, pronoun;
	ref PChar;
	PChar = GetMainCharacter();

	int pirate_relation = RELATION_NEUTRAL;
	if (PChar.quest.background == "smuggler" || GetServedNation() == PIRATE) pirate_relation = RELATION_FRIEND;
	if (PChar.quest.background == "smuggler" && IsInAnyService()) pirate_relation = RELATION_ENEMY;
	if (PChar.quest.background == "pirate" && GetServedNation() != PIRATE) pirate_relation = RELATION_NEUTRAL;
	if (PChar.quest.background == "pirate" && GetRMRelation(PChar, PIRATE) <= REL_WAR) pirate_relation = RELATION_ENEMY;

	if (PChar.sex == "man")
	{
		governors_kid = DLG_TEXT[57];
		pronoun = XI_ConvertString("her");
	}
	else
	{
		governors_kid = DLG_TEXT[58];
		pronoun = XI_ConvertString("him");
	}
	
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

			if (pirate_relation < RELATION_ENEMY || LAi_IsDead(characterFromID("Mary Wood")))
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
			}
			else
			{
				dialog.text = DLG_TEXT[37];
				link.l1 = DLG_TEXT[38];
				AddDialogExitQuest("meet_Mary_Wood");
			}
			link.l1.go = "Exit";
		break;

		case "abduction_meeting":
			switch(pirate_relation)
			{
				case RELATION_FRIEND:
					Preprocessor_Add("background", PChar.quest.background);
					dialog.text = DLG_TEXT[2] + GetMyName(PChar) + "?";
					link.l1 = DLG_TEXT[7];
				break;
				case RELATION_NEUTRAL:
					dialog.text = DLG_TEXT[3] + GetMyName(PChar) + DLG_TEXT[4];
					link.l1 = DLG_TEXT[8];
				break;
				case RELATION_ENEMY:
					dialog.text = DLG_TEXT[5] + GetMyName(PChar) + DLG_TEXT[6];
					link.l1 = DLG_TEXT[9];
				break;
			}
			link.l1.go = "abduction_request_help";
		break;

		case "abduction_request_help":
			Preprocessor_Add("pronoun", pronoun);
			if (pirate_relation == RELATION_FRIEND)
			{
				dialog.text = DLG_TEXT[10];
				if (PChar.sex == "woman") link.l1 = DLG_TEXT[14] + DLG_TEXT[16] + DLG_TEXT[17];
				else link.l1 = DLG_TEXT[14] + DLG_TEXT[15] + DLG_TEXT[17];
				link.l1.go = "abduction_whodunnit";
			}
			else
			{
				dialog.text = DLG_TEXT[11];
				link.l1 = DLG_TEXT[12];
				link.l1.go = "abduction_you_offer_deal";
			}
		break;

		case "abduction_you_offer_deal":
			Preprocessor_Add("pronoun", pronoun);
			dialog.text = DLG_TEXT[13];
			if (PChar.sex == "woman") link.l1 = DLG_TEXT[14] + DLG_TEXT[16] + DLG_TEXT[17];
			else link.l1 = DLG_TEXT[14] + DLG_TEXT[15] + DLG_TEXT[17];
			link.l1.go = "abduction_whodunnit";
		break;

		case "abduction_whodunnit":
			Preprocessor_Add("governors_kid", governors_kid);
			Preprocessor_Add("pronoun", pronoun);
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "abduction_he_offers_deal";
		break;

		case "abduction_he_offers_deal":
			if (pirate_relation == RELATION_FRIEND)
			{
				dialog.text = DLG_TEXT[20] + DLG_TEXT[21] + GetMySimpleName(characterFromID("Wilfred Roscoe")) + DLG_TEXT[22] + GetMyName(characterFromID("Wilfred Roscoe")) + DLG_TEXT[23];
			}
			else
			{
				dialog.text = DLG_TEXT[20] + DLG_TEXT[24] + GetMySimpleName(characterFromID("Wilfred Roscoe")) + DLG_TEXT[25] + GetMyName(characterFromID("Wilfred Roscoe")) + DLG_TEXT[26];
			}
			Preprocessor_AddQuestData("pirate", GetMySimpleName(characterfromID("Wilfred Roscoe")));
			AddQuestRecord("Abduction", 6);
			Preprocessor_Remove("pirate");
			PChar.quest.abduction_status = "rescue_pirate";
			AddDialogExitQuest("abduction_guadeloupe_setup");
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit_not_done";
		break;

		case "abduction_still_here":
			if (pirate_relation == RELATION_FRIEND)
			{
				if (PChar.sex == "man") PreProcessor_Add("ladlass", XI_ConvertString("lad"));
				else PreProcessor_Add("ladlass", XI_ConvertString("lass"));
				dialog.text = DLG_TEXT[28];
			}
			else dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30] + GetMySimpleName(characterFromID("Wilfred Roscoe")) + ".";
			link.l1.go = "exit_not_done";
		break;

		case "abduction_rescue_done":
			Preprocessor_AddQuestData("pirate1", GetMySimpleName(characterfromID("Wilfred Roscoe")));
			Preprocessor_AddQuestData("pirate2", GetMySimpleName(characterfromID("Garfield Leighton")));
			Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
			AddQuestRecord("Abduction", 14);
			Preprocessor_Remove("romance");
			Preprocessor_Remove("pirate2");
			Preprocessor_Remove("pirate1");
			if (PChar.sex == "man")
			{
				PreProcessor_Add("person", XI_ConvertString("woman"));
				Preprocessor_Add("governors_kid", governors_kid);
			}
			else
			{
				PreProcessor_Add("person", XI_ConvertString("man"));
				Preprocessor_Add("governors_kid", governors_kid);
			}
			if (pirate_relation == RELATION_FRIEND)
			{
				dialog.text = DLG_TEXT[31] + GetMyName(characterFromID("Wilfred Roscoe")) + DLG_TEXT[32];
				link.l1 = DLG_TEXT[33];
			}
			else
			{
				dialog.text = DLG_TEXT[34] + GetMyName(characterFromID("Wilfred Roscoe")) + DLG_TEXT[35];
				link.l1 = DLG_TEXT[36];
			}
			AddDialogExitQuest("abduction_roscoe_joins_leighton");
			link.l1.go = "exit";
		break;			

		case "exit_not_done":
			Diag.CurrentNode = "abduction_still_here";
			DialogExit();
		break;

		case "imperial_escort_meeting":
			if(pirate_relation != RELATION_ENEMY)
			{
				if(IsOfficer(CharacterFromID(PChar.quest.romance)) && !CheckQuestAttribute("revenge_type", "kidnap_rescue") && !CheckQuestAttribute("revenge_type", "kidnap_rescue_convoy_agreed") && !CheckQuestAttribute("revenge_type", "assassin"))
				{
					Preprocessor_Add("governors_kid", governors_kid);
					dialog.text = DLG_TEXT[39] + GetMyName(PChar) + DLG_TEXT[41];
					link.l1 = DLG_TEXT[42] + GetMyFullName(CharacterFromID(PChar.quest.romance)) + ".";
					link.l1.go = "imperial_escort_introduce_romance";
				}
				else
				{
					dialog.text = DLG_TEXT[39] + GetMyName(PChar) + DLG_TEXT[40];
					link.l1 = DLG_TEXT[47];
					link.l1.go = "imperial_escort_whodunnit";
				}
			}
			else
			{
				dialog.text = DLG_TEXT[45] + GetMyLastName(PChar) + DLG_TEXT[46];
				link.l1 = DLG_TEXT[47];
				link.l1.go = "imperial_escort_whodunnit";
			}
		break;

		case "imperial_escort_introduce_romance":
			dialog.text = DLG_TEXT[43] + GetMyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[44];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "imperial_escort_whodunnit";
		break;

		case "imperial_escort_whodunnit":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "imperial_escort_ransom";
		break;

		case "imperial_escort_ransom":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "imperial_escort_no_pirate";
		break;

		case "imperial_escort_no_pirate":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "imperial_escort_maybe_france";
		break;

		case "imperial_escort_maybe_france":
			dialog.text = DLG_TEXT[54] + GetMyFullName(GetTownGovernor("Tortuga")) + DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			AddDialogExitQuest("imperial_escort_visit_Tortuga_governor");
			link.l1.go = "exit";
		break;
	}
}