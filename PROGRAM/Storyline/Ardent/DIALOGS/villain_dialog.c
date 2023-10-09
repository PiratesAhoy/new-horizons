//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string gov_kid, gov_kid_pronoun1, gov_kid_pronoun2, gov_kid_pronoun3;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	string villain_title_France, villain_title_England;
	if (NPChar.sex == "woman")
	{
		if (CheckAttribute(NPChar, "married"))
		{
			villain_title_France = XI_ConvertString("Madame");
			villain_title_England = XI_ConvertString("Mrs.");
		}
		else
		{
			villain_title_France = XI_ConvertString("Mademoiselle");
			villain_title_England = XI_ConvertString("Miss");
		}
	}
	else
	{
		villain_title_France = XI_ConvertString("Monsieur");
		villain_title_England = XI_ConvertString("Mr.");
	}

	ref PChar;
	PChar = GetMainCharacter();

	gov_kid_pronoun1 = XI_ConvertString(GetMyPronounSubj(characterFromID(PChar.quest.romance)));		// "he" / "she"
	gov_kid_pronoun2 = XI_ConvertString(GetMyPronounObj(characterFromID(PChar.quest.romance)));		// "him" / "her"
	gov_kid_pronoun3 = XI_ConvertString(GetMyPronounPossessive(characterFromID(PChar.quest.romance)));	// "his" / "her"
	if (PChar.sex == "man")
	{
		gov_kid = XI_ConvertString("daughter");
	}
	else
	{
		gov_kid = XI_ConvertString("son");
	}
	
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

			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + "?";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "first_letter":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5] + GetMyFullName(PChar) + DLG_TEXT[6];
			link.l1.go = "first_letter2";
		break;

		case "first_letter2":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "first_letter3";
		break;

		case "first_letter3":
			dialog.text = DLG_TEXT[9] + GetMyFullName(characterFromID(PChar.quest.romance)) + ", " + gov_kid + DLG_TEXT[10];
			link.l1 = DLG_TEXT[11] + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[12];
			AddDialogExitQuest("deliver_first_CourtingLetter");
			link.l1.go = "exit";
		break;

		case "CourtingLetter_not_yet":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "CourtingLetter_not_yet_exit";
		break;

		case "CourtingLetter_not_yet_exit":
			Diag.CurrentNode = "CourtingLetter_not_yet";
			DialogExit();
		break;

		case "first_letter_delivered":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[15] + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[16];
			link.l1.go = "lie_happy";
			if (checkquestattribute("ardent_kidnap.wedding", "sad"))
			{
				link.l2 = DLG_TEXT[18] + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[19];
				link.l2.go = "lie_unhappy";
			}
			link.l3 = DLG_TEXT[17];
			link.l3.go = "truth";
		break;

		case "lie_happy":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "disgrace_exit";
			Preprocessor_AddQuestData("villain", GetMySimpleName(PChar.quest.villain));
			AddQuestRecord("Kidnap", 22);
			Preprocessor_Remove("villain");
		break;

		case "lie_unhappy":
			dialog.text = DLG_TEXT[22] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[23];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "disgrace_exit";
			Preprocessor_AddQuestData("villain", GetMySimpleName(PChar.quest.villain));
			AddQuestRecord("Kidnap", 22);
			Preprocessor_Remove("villain");
		break;

		case "truth":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, 200);
			dialog.text = DLG_TEXT[24] + GetMySimpleName(characterFromID("Grigorio Formoselle")) + DLG_TEXT[25] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[26] + GetMyName(characterFromID("Grigorio Formoselle")) + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			AddDialogExitQuest("deliver_second_CourtingLetter");
			link.l1.go = "exit";
		break;

		case "disgrace":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "disgrace_exit";
		break;

		case "disgrace_exit":
			Diag.CurrentNode = "disgrace";
			DialogExit();
		break;

		case "second_letter_delivered":
			dialog.text = DLG_TEXT[29] + GetMyLastName(PChar) + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[32];
			link.l1.go = "second_letter_delivered2";
		break;

		case "second_letter_delivered2":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, 2000);
			TakeItemFromCharacter(Pchar, "SignetRing");
			dialog.text = DLG_TEXT[33]+ GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[34] + gov_kid_pronoun3 + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			AddQuestRecord("Kidnap", 25);
			CloseQuestHeader("Kidnap");
			Preprocessor_Remove("villain");
		break;

		case "mona_attack_recognised":
			Preprocessor_Add("title", villain_title_France);
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "mona_attack_recognised2";
		break;

		case "mona_attack_recognised2":
			Preprocessor_Add("title", villain_title_France);
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "mona_attack_recognised3";
		break;

		case "mona_attack_recognised3":
			Preprocessor_Add("title", villain_title_France);
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
		break;

		case "treachery_governor":
//			if (isofficer(characterFromID(PChar.quest.romance)) && PChar.quest.alignment == "good")
			if (isofficer(characterFromID(PChar.quest.romance)))
			{
				dialog.text = DLG_TEXT[43] + GetMyRespectfullyName(PChar) + DLG_TEXT[44] + DLG_TEXT[45] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[46];
				link.l1 = "";
				AddDialogExitQuest("treachery_villain_invites_romance");
				link.l1.go = "exit";
			}
			else
			{
				CloseQuestHeader("Treachery");
				SetQuestHeader("Santiago Threat");
				Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
				AddQuestRecord("Santiago Threat", 2);
				Preprocessor_Remove("villain");
				PChar.quest.ardent_treachery_status = "goto_Santiago";
				dialog.text = DLG_TEXT[43] + GetMyRespectfullyName(PChar) + DLG_TEXT[44];
				link.l1 = DLG_TEXT[51];
				link.l1.go = "treachery_governor2";
			}
		break;

		case "treachery_governor2":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			AddDialogExitQuest("treachery_villain_calls_guards");
			link.l1.go = "exit";
		break;

		case "treachery_rejected":
			dialog.text = DLG_TEXT[47] + GetMyName(characterFromID(PChar.quest.romance)) + ".";
			link.l1 = DLG_TEXT[48] + GetMyLastName(CharacterFromId("Javier Balboa")) + DLG_TEXT[49];
			link.l1.go = "treachery_governor3";
		break;

		case "treachery_governor3":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[53];
			AddDialogExitQuest("treachery_villain_calls_guards");
			link.l1.go = "exit";
		break;

		case "hunt_guadeloupe_encounter1":
			dialog.text = DLG_TEXT[54] + GetMySimpleName(PChar) + DLG_TEXT[55];
			link.l1 = DLG_TEXT[56] + villain_title_England + " " + GetMyLastName(characterFromID(PChar.quest.villain)) + DLG_TEXT[57] + villain_title_France + " " + GetMyLastName(characterFromID(PChar.quest.villain)) + "?";
			link.l1.go = "hunt_guadeloupe_encounter1_2";
		break;

		case "hunt_guadeloupe_encounter1_2":
			dialog.text = DLG_TEXT[58] + XI_ConvertString(GetMyPronounObj(PChar)) + "!";
			link.l1 = DLG_TEXT[59];
			AddDialogExitQuest("hunt_guadeloupe_arrest1");
			link.l1.go = "exit";
		break;

		case "hunt_prison_morning":
			dialog.text = DLG_TEXT[60] + GetMyRespectfullyName(PChar) + DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "hunt_prison_morning2";
		break;

		case "hunt_prison_morning2":
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "exit";
		break;

		case "hunt_ardent_before_governor":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounObj(PChar)));
			dialog.text = DLG_TEXT[65];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "hunt_better_idea":
		//	if (PChar.sex == "man") Preprocessor_Add("pronoun", XI_ConvertString("his"));
		//	else Preprocessor_Add("pronoun", XI_ConvertString("her"));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounPossessive(PChar)));
			dialog.text = DLG_TEXT[66];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "hunt_to_ship":
			dialog.text = DLG_TEXT[67] + GetMyRespectfullyName(PChar) + DLG_TEXT[68];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "hunt_your_ship_is_mine";
		break;

		case "hunt_your_ship_is_mine":
			Preprocessor_Add("myship", PChar.Ship.Name);
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
		break;

		case "hunt_arrested_on_ship":
			dialog.text = DLG_TEXT[72] + GetMyRespectfullyName(PChar) + DLG_TEXT[73];
			link.l1 = DLG_TEXT[69];
			link.l1.go = "hunt_arrested_on_ship2";
		break;

		case "hunt_arrested_on_ship2":
			Preprocessor_Add("myship", PChar.Ship.Name);
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[71];
			link.l1.go = "exit";
		break;

		case "hunt_with_villain_in_hold":
			if (PChar.ship.type == "RN_WarGalleon" || PChar.ship.type == "Pinnace1" || PChar.ship.type == "PinnaceMerchant")
			{
				dialog.text = DLG_TEXT[75] + GetMyRespectfullyName(PChar) + DLG_TEXT[81];
				link.l1 = DLG_TEXT[82] + GetMySimpleName(characterFromID(PChar.quest.romance)) + ".";
				if (CheckQuestAttribute("hunt_romance_on_ship", "true")) link.l1.go = "hunt_convoy_romance_taunt";
				else link.l1.go = "hunt_where_is_romance";
			}
			else
			{
				dialog.text = DLG_TEXT[75] + GetMyRespectfullyName(PChar) + ".";
				link.l1 = DLG_TEXT[76];
				if (CheckQuestAttribute("hunt_romance_on_ship", "true")) link.l1.go = "hunt_romance_taunt";
				else link.l1.go = "hunt_where_is_romance_not_convoy";
			}
		break;

		case "hunt_where_is_romance":
			Preprocessor_Add("pronoun", gov_kid_pronoun1);
			Preprocessor_Add("pronoun2", gov_kid_pronoun2);
			dialog.text = DLG_TEXT[83] + DLG_TEXT[80];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "hunt_where_is_romance2";
		break;

		case "hunt_where_is_romance_not_convoy":
			Preprocessor_Add("pronoun", gov_kid_pronoun1);
			Preprocessor_Add("pronoun2", gov_kid_pronoun2);
			dialog.text = DLG_TEXT[79] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[80];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "hunt_where_is_romance2";
		break;

		case "hunt_where_is_romance2":
			Preprocessor_Add("pronoun", gov_kid_pronoun1);
			Preprocessor_Add("pronoun2", gov_kid_pronoun2);
			Preprocessor_Add("pronoun3", gov_kid_pronoun3);
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86] + DLG_TEXT[89] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[90];
			link.l1.go = "hunt_villain_plans";
		break;

		case "hunt_convoy_romance_taunt":
			Preprocessor_Add("pronoun3", gov_kid_pronoun3);
			dialog.text = DLG_TEXT[87] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[78];
			link.l1 = "";
			AddDialogExitQuest("hunt_romance_joins_villain");
			link.l1.go = "exit";
		break;

		case "hunt_romance_taunt":
			Preprocessor_Add("pronoun3", gov_kid_pronoun3);
			dialog.text = DLG_TEXT[77] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[78];
			link.l1 = "";
			AddDialogExitQuest("hunt_romance_joins_villain");
			link.l1.go = "exit";
		break;

		case "hunt_that_how_it_is":
			dialog.text = "";
			link.l1 = DLG_TEXT[88] + DLG_TEXT[89] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[90];
			link.l1.go = "hunt_villain_plans";
		break;

		case "hunt_villain_plans":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];
			link.l1.go = "hunt_villain_plans2";
		break;

		case "hunt_villain_plans2":
			Preprocessor_Add("person", XI_ConvertString(NPChar.sex));
		//	if (Characters[GetCharacterIndex(PChar.quest.villain)].sex == "man") PreProcessor_Add("pronoun2", XI_ConvertString("his"));
		//	else PreProcessor_Add("pronoun2", XI_ConvertString("her"));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounPossessive(NPChar)));
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "hunt_villain_plans3";
		break;

		case "hunt_villain_plans3":
			if (CheckQuestAttribute("hunt_romance_on_ship", "true")) dialog.text = DLG_TEXT[95] + DLG_TEXT[96] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[97];
			else dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[98] + villain_title_England + " " + GetMyLastName(characterFromID(PChar.quest.villain)) + ".";
			if (CheckAttribute(PChar, "quest.hunt_french_released")) link.l1.go = "hunt_french_release";
			else
			{
				AddDialogExitQuest("hunt_villain_leaves_hold");
				link.l1.go = "exit";
			}
		break;

		case "hunt_french_release":
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			AddDialogExitQuest("hunt_villain_leaves_hold");
			link.l1.go = "exit";
		break;

		case "finale_challenge_to_duel":
			dialog.text = DLG_TEXT[99] + GetMyRespectfullyName(PChar) + ".";
			link.l1 = DLG_TEXT[100] + villain_title_England + " " + GetMyLastName(characterFromID(PChar.quest.villain)) + DLG_TEXT[101];
			link.l1.go = "finale_challenge_to_duel2";
		break;

		case "finale_challenge_to_duel2":
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "finale_challenge_to_duel3";
		break;

		case "finale_challenge_to_duel3":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "exit";
		break;

		case "finale_challenge_to_duel_own_cabin":
			Preprocessor_Add("villain", GetMyName(CharacterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[99] + GetMyRespectfullyName(PChar) + ".";
			link.l1 = DLG_TEXT[125];
			link.l1.go = "finale_challenge_to_duel_own_cabin2";
		break;

		case "finale_challenge_to_duel_own_cabin2":
			Preprocessor_Add("admiral", GetMyFullName(CharacterFromID("French_Amiral")));
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "exit";
		break;

		case "finale_governor_cooperated":
			dialog.text = DLG_TEXT[106];
			link.l1 = "";
//			AddDialogExitQuest("finale_hostage_governor_protects_wife");
			link.l1.go = "exit";
		break;

		case "finale_now_for_you":
			Preprocessor_Add("governor", GetMyLastName(CharacterFromID("John Clifford Brin")));
			dialog.text = DLG_TEXT[107] + GetMyRespectfullyName(PChar) + DLG_TEXT[109];
			if (CheckQuestAttribute("alignment", "evil"))
			{
				link.l1 = DLG_TEXT[120];
				link.l1.go = "finale_you_would_stand_by";
			}
			else
			{
				link.l1 = DLG_TEXT[110];
				link.l1.go = "finale_need_him_alive";
			}
		break;

		case "finale_welcome":
			Preprocessor_Add("governor", GetMyLastName(CharacterFromID("John Clifford Brin")));
			dialog.text = DLG_TEXT[108] + GetMyRespectfullyName(PChar) + DLG_TEXT[109];
			if (CheckQuestAttribute("alignment", "evil"))
			{
				link.l1 = DLG_TEXT[120];
				link.l1.go = "finale_you_would_stand_by";
			}
			else
			{
				link.l1 = DLG_TEXT[110];
				link.l1.go = "finale_need_him_alive";
			}
		break;

		case "finale_need_him_alive":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "finale_curses";
		break;

		case "finale_curses":
			dialog.text = DLG_TEXT[113] + GetMyLastName(PChar) + "!";
			link.l1 = DLG_TEXT[114];
			link.l1.go = "finale_challenge_declined";
		break;

		case "finale_challenge_declined":
			Preprocessor_Add("governor", GetMyLastName(CharacterFromID("John Clifford Brin")));
			Preprocessor_Add("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID(PChar.quest.villain))));
			dialog.text = DLG_TEXT[115];
			link.l1 = DLG_TEXT[116];
			AddDialogExitQuest("finale_governor_wont_give_word");
			link.l1.go = "exit";
		break;

		case "finale_challenge_accepted":
			Preprocessor_Add("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[117] + GetMySimpleName(PChar) + DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
//			AddDialogExitQuest("finale_port_royale_hostage_duel_with_villain");
			link.l1.go = "exit";
		break;

		case "finale_you_would_stand_by":
			Preprocessor_Add("governor", GetMyLastName(CharacterFromID("John Clifford Brin")));
			dialog.text = DLG_TEXT[121];
			link.l1 = DLG_TEXT[122];
			link.l1.go = "finale_who_will_leave_upright";
		break;

		case "finale_who_will_leave_upright":
			dialog.text = DLG_TEXT[123];
			link.l1 = DLG_TEXT[124];
			AddDialogExitQuest("finale_port_royale_hostage_duel_with_villain");
			link.l1.go = "exit";
		break;

		case "wedding_forbid_this":
			dialog.text = DLG_TEXT[128];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "wedding_romance_is_mine":
			Preprocessor_Add("villain", GetMyFullName(CharacterFromID(PChar.quest.villain)));
			Preprocessor_Add("romance", GetMyName(CharacterFromID(PChar.quest.romance)));
			dialog.text = DLG_TEXT[129];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "wedding_over_my_dead_body":
			Preprocessor_Add("romance", GetMyName(CharacterFromID(PChar.quest.romance)));
			Preprocessor_Add("pronoun", gov_kid_pronoun1);
			dialog.text = DLG_TEXT[130];
			link.l1 = DLG_TEXT[131];
			link.l1.go = "exit";
		break;

		case "wedding_go_outside":
			dialog.text = "";
			link.l1 = DLG_TEXT[132];
			link.l1.go = "wedding_another_trick";
		break;

		case "wedding_another_trick":
			dialog.text = DLG_TEXT[133] + GetMyRespectfullyName(PChar) + DLG_TEXT[134];
			link.l1 = "";
			link.l1.go = "exit";
		break;
	}
}