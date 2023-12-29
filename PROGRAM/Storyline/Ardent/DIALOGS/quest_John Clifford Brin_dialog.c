//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, ch;
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

			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + ".";
			link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + ".";
			link.l1.go = "exit";
		break;

		case "finale_going_to_ship":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "exit";
		break;

		case "finale_here_to_evacuate":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			Preprocessor_Add("admiral", GetMyFullName(CharacterFromID("Antigua_Portadmiral")));
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[5];
			link.l1.go = "finale_evacuate_where_is_ship";
		break;

		case "finale_evacuate_where_is_ship":
			TakeItemFromCharacter(PChar, "BattleOrders");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + TranslateString("",GetCharacterShipLocationName(PChar)) + ".";
			link.l1.go = "finale_evacuate_get_family";
		break;

		case "finale_evacuate_get_family":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "finale_evacuate_offer_money";
		break;

		case "finale_evacuate_offer_money":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			AddDialogExitQuest("finale_port_royale_evacuation_get_family");
			link.l1.go = "exit";
		break;

		case "finale_evacuate_introduce_family":
			Preprocessor_Add("wife", GetMyFullName(CharacterFromID("Elizabeth O_Brien")));
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
		break;

		case "finale_you_defeated_warship":
			Preprocessor_Add("warship", PChar.quest.French_flagship.name);
			dialog.text = DLG_TEXT[14] + GetMyRespectfullyName(PChar) + DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "finale_new_deal";
		break;

		case "finale_new_deal":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "finale_new_deal_accepted";
		break;

		case "finale_new_deal_accepted":
			PChar.quest.finale_fort_reward = 200000;
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
		break;

		case "finale_return_after_fort":
			dialog.text = DLG_TEXT[21] + GetMyRespectfullyName(PChar) + DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "finale_dismiss_soldiers";
		break;

		case "finale_dismiss_soldiers":
			dialog.text = DLG_TEXT[24];
			if (CheckQuestAttribute("governor_hostage", "John Clifford Brin")) link.l1 = "...";
			else link.l1 = DLG_TEXT[25];
			AddDialogExitQuest("finale_port_royale_dismiss_soldiers");
			link.l1.go = "exit";
		break;

		case "finale_pay_up":
			dialog.text = "...";
			link.l1 = DLG_TEXT[25];
			link.l1.go = "finale_reward_for_warship";
		break;

		case "finale_reward_for_warship":
			PlayStereoSound("INTERFACE\took_item.flac");
			if (CheckAttribute(PChar, "quest.finale_fort_reward"))
			{
				dialog.text = DLG_TEXT[26];
				AddMoneytoCharacter(PChar, sti(PChar.quest.finale_fort_reward));
				DeleteQuestAttribute("finale_fort_reward");
			}
			else
			{
				dialog.text = DLG_TEXT[58];
				AddMoneytoCharacter(PChar, 200000);
			}
			Preprocessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[26];
			makeref(ch, Characters[GetCharacterIndex(PChar.quest.villain)]);
			if (LAi_IsDead(ch))
			{
				link.l1 = DLG_TEXT[27];
				if (CheckAttribute(ch, "quest.place_of_death") && ch.quest.place_of_death == "ship");
				{
					Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID(PChar.quest.villain))));
					Preprocessor_Add("warship", PChar.quest.French_flagship.name);
					link.l1 = DLG_TEXT[27] + DLG_TEXT[28];
				}
				link.l1.go = "finale_reward_for_villain";
			}
			else
			{
				link.l1 = DLG_TEXT[30];
				link.l1.go = "finale_now_about_warship";
			}
		break;

		case "finale_reward_for_villain":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter(PChar, 10000);
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "finale_now_about_warship";
		break;

		case "finale_now_about_warship":
			Preprocessor_Add("warship", PChar.quest.French_flagship.name);
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "finale_commandeer_warship";
		break;

		case "finale_commandeer_warship":
			Preprocessor_Add("warship", PChar.quest.French_flagship.name);
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "finale_cannot_be_serious";
		break;

		case "finale_cannot_be_serious":
			Preprocessor_Add("warship", PChar.quest.French_flagship.name);
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "finale_just_joking";
		break;

		case "finale_just_joking":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			if (HaveLetterOfMarque(ENGLAND)) link.l1.go = "finale_already_have_LOM";
			else link.l1.go = "finale_offer_LOM";
		break;

		case "finale_offer_LOM":
			dialog.text = DLG_TEXT[39];
			if (HaveLetterOfMarque(SPAIN))
			{
				link.l1 = DLG_TEXT[40];
				link.l1.go = "finale_already_got_Spanish_LOM";
			}
			link.l2 = DLG_TEXT[41];
			link.l2.go = "finale_accept_LOM";
			link.l3 = DLG_TEXT[42];
			link.l3.go = "finale_reject_LOM";
		break;

		case "finale_already_got_Spanish_LOM":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "finale_accept_LOM";
			link.l2 = DLG_TEXT[47];
			link.l2.go = "finale_reject_LOM";
		break;

		case "finale_accept_LOM":
			SetRank(PChar, ENGLAND, GetOldRank(PChar, ENGLAND));
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[78] + DLG_TEXT[48];
			AddDialogExitQuest("finale_port_royale_finished_rewards");
			PChar.quest.warship_named = "true";
			link.l1.go = "exit";
		break;

		case "finale_reject_LOM":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[48];
			AddDialogExitQuest("finale_port_royale_finished_rewards");
			link.l1.go = "exit";
		break;

		case "finale_already_have_LOM":
			Preprocessor_Add("warship", PChar.quest.French_flagship.name);
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[78] + DLG_TEXT[48];
			AddDialogExitQuest("finale_port_royale_finished_rewards");
			PChar.quest.warship_named = "true";
			link.l1.go = "exit";
		break;

		case "finale_dont_harm_wife":
			dialog.text = DLG_TEXT[50] + GetMyName(characterFromID("Elizabeth O_Brien")) + "!";
			link.l1 = "";
//			AddDialogExitQuest("finale_hostage_villain_turns_to_player");
			link.l1.go = "exit";
		break;

		case "finale_you_ask_too_much":
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(characterFromID(PChar.quest.villain))));
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "finale_agree_safe_conduct";
		break;

		case "finale_agree_safe_conduct":
			Preprocessor_Add("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[53] + GetMySimpleName(PChar) + DLG_TEXT[54];
			link.l1 = "";
//			AddDialogExitQuest("finale_hostage_safe_conduct_granted");
			link.l1.go = "exit";
		break;

		case "finale_villain_dead_in_residence":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter(PChar, 10000);
			Preprocessor_Add("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[55];
			if (CheckAttribute(PChar, "quest.finale_fort_reward")) link.l1 = DLG_TEXT[56] + PChar.quest.finale_fort_reward + ".";
			else link.l1 = DLG_TEXT[57];
			link.l1.go = "finale_reward_for_warship2";
		break;

		case "finale_reward_for_warship2":
			PlayStereoSound("INTERFACE\took_item.flac");
			if (CheckAttribute(PChar, "quest.finale_fort_reward"))
			{
				dialog.text = DLG_TEXT[26];
				AddMoneytoCharacter(PChar, sti(PChar.quest.finale_fort_reward));
				DeleteQuestAttribute("finale_fort_reward");
			}
			else
			{
				dialog.text = DLG_TEXT[58];
				AddMoneytoCharacter(PChar, 200000);
			}
			if (HaveLetterOfMarque(ENGLAND))
			{
				link.l1 = DLG_TEXT[30] + " " + DLG_TEXT[48];
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = DLG_TEXT[30];
				link.l1.go = "finale_offer_LOM2";
			}
		break;

		case "finale_offer_LOM2":
			dialog.text = DLG_TEXT[66];
			if (HaveLetterOfMarque(SPAIN))
			{
				link.l1 = DLG_TEXT[40];
				link.l1.go = "finale_already_got_Spanish_LOM";
			}
			link.l2 = DLG_TEXT[41];
			link.l2.go = "finale_accept_LOM";
			link.l3 = DLG_TEXT[42];
			link.l3.go = "finale_reject_LOM";
		break;

		case "finale_you_would_let_villain_kill_me":
			Preprocessor_Add("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(characterFromID(PChar.quest.villain))));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID(PChar.quest.villain))));
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "finale_why_trust_you";
		break;

		case "finale_why_trust_you":
			Preprocessor_Add("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "finale_that_is_true";
		break;

		case "finale_that_is_true":
			Preprocessor_Add("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(characterFromID(PChar.quest.villain))));
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "finale_evil_reward_for_villain";
		break;

		case "finale_evil_reward_for_villain":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter(PChar, 10000);
			dialog.text = DLG_TEXT[65];
			if (CheckAttribute(PChar, "quest.finale_fort_reward")) link.l1 = DLG_TEXT[56] + PChar.quest.finale_fort_reward + ".";
			else link.l1 = DLG_TEXT[57];
			link.l1.go = "finale_reward_for_warship2";
		break;

		case "finale_what_happened":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[68];
			link.l1.go = "finale_thank_admiral";
		break;

		case "finale_thank_admiral":
			Preprocessor_Add("admiral", GetMyFullName(CharacterFromID("Antigua_Portadmiral")));
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "finale_dont_believe_you";
		break;

		case "finale_dont_believe_you":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			Preprocessor_Add("warship", PChar.quest.French_flagship.name);
			if (HaveLetterOfMarque(ENGLAND)) dialog.text = DLG_TEXT[71] + DLG_TEXT[73] + DLG_TEXT[74];
			else dialog.text = DLG_TEXT[71] + DLG_TEXT[72] + DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			AddDialogExitQuest("finale_soldier_reports_victory");
			link.l1.go = "exit";
		break;

		case "finale_so_it_is_true":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneytoCharacter(PChar, 200000);
			dialog.text = DLG_TEXT[76] + GetMyRespectfullyName(PChar) + DLG_TEXT[77];
			if (LAi_IsDead(characterFromID(PChar.quest.villain)))
			{
				Preprocessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
				makeref(ch, Characters[GetCharacterIndex(PChar.quest.villain)]);
				link.l1 = DLG_TEXT[27];
				if (CheckAttribute(ch, "quest.place_of_death") && ch.quest.place_of_death == "ship");
				{
					Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounObj(characterFromID(PChar.quest.villain))));
					Preprocessor_Add("warship", PChar.quest.French_flagship.name);
					link.l1 = DLG_TEXT[27] + DLG_TEXT[28];
				}
				link.l1.go = "finale_reward_for_villain";
			}
			else
			{
				link.l1 = DLG_TEXT[30];
				link.l1.go = "finale_now_about_warship";
			}
		break;
	}
}