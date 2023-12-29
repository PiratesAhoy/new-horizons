//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string NPC_Meeting;

	int NPC_commerce, PC_commerce, price;
	int price_red = 3250;
	int price_white = 2750;
	int price_blue = 8100;
	float cost_multiplier;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	NPC_commerce = CalcCharacterSkill(NPChar, SKILL_COMMERCE);
	PC_commerce = CalcCharacterSkill(PChar, SKILL_COMMERCE);
	cost_multiplier = (1.0 + (NPC_commerce - PC_commerce)/10.0) * 1.2;
	string title = FirstLetterUp(XI_ConvertString("Captain"));
	if (GetRank(PChar, sti(NPChar.nation)) > 0) title = XI_ConvertString(GetRankName(PChar, sti(NPChar.nation)));
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
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
			if(NPChar.quest.meeting == "0")
			{
				NPC_Meeting = "1";
				dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + ".";
				link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + ".";
				link.l1.go = "intro";
			}
			else
			{
				switch(GetAttribute(PChar, "quest.crys_skull_status"))
				{
					case "quest_rejected":
						dialog.text = DLG_TEXT[35] + title + " " + GetMyLastName(PChar) + DLG_TEXT[36];
						link.l1 = DLG_TEXT[37];
						link.l1.go = "quest_accepted";
						link.l2 = DLG_TEXT[6];
						link.l2.go = "sales";
						link.l3 = DLG_TEXT[7];
						link.l3.go = "exit";
					break;

					case "find_Caribs":
						dialog.text = DLG_TEXT[38] + title + " " + GetMyLastName(PChar) + "?";
						link.l1 = DLG_TEXT[39];
						link.l1.go = "exit";
						link.l2 = DLG_TEXT[6];
						link.l2.go = "sales";
					break;

					dialog.text = DLG_TEXT[3] + title + " " + GetMyLastName(PChar) + DLG_TEXT[94];
					if (!CheckAttribute(PChar, "quest.crys_skull_status"))
					{
						dialog.text = DLG_TEXT[3] + title + " " + GetMyLastName(PChar) + DLG_TEXT[4];
						link.l1 = DLG_TEXT[5];
						link.l1.go = "quest";
					}
					link.l2 = DLG_TEXT[6];
					link.l2.go = "sales";
					link.l3 = DLG_TEXT[7];
					link.l3.go = "exit";
				}
			}
		break;

		case "intro":
			Preprocessor_Add("person", XI_ConvertString(PChar.sex));
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "quest";
			link.l2 = DLG_TEXT[6];
			link.l2.go = "sales";
			link.l3 = DLG_TEXT[7];
			link.l3.go = "exit";
		break;

		case "quest":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "quest2";
		break;

		case "quest2":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "quest3";
		break;

		case "quest3":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "quest_decision";
		break;

		case "quest_decision":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "quest_accepted";
			link.l2 = DLG_TEXT[32];
			link.l2.go = "quest_rejected";
		break;

		case "quest_accepted":
			dialog.text = DLG_TEXT[33] + title + " " + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[23];
			SetRumourState("crys_skull", false);
			AddDialogExitQuest("crysskull_initiate");
			link.l1.go = "exit";
			PChar.quest.crys_skull_status = "find_Caribs";
		break;

		case "quest_rejected":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			PChar.quest.crys_skull_status = "quest_rejected";
		break;

		case "sales":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "buy_white";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "buy_red";
			link.l3 = DLG_TEXT[11];
			link.l3.go = "buy_blue";
			if (!CheckAttribute(PChar, "quest.crys_skull_status"))
			{
				link.l4 = DLG_TEXT[12];
				link.l4.go = "quest";
			}
			link.l5 = DLG_TEXT[13];
			link.l5.go = "exit";
		break;

		case "buy_red":
			price = makeint(price_red * cost_multiplier);
			NPChar.item = "roseskull";
			NPChar.price = "" + price;
			dialog.text = DLG_TEXT[14] + price + DLG_TEXT[17];
			if (makeint(PChar.money) >= price)
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "buy_deal";
				link.l2 = DLG_TEXT[20];
			}
			else link.l2 = DLG_TEXT[19];
			link.l2.go = "no_deal";
		break;

		case "buy_white":
			price = makeint(price_white * cost_multiplier);
			NPChar.item = "whiteskull";
			NPChar.price = "" + price;
			dialog.text = DLG_TEXT[15] + price + DLG_TEXT[17];
			if (makeint(PChar.money) >= price)
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "buy_deal";
				link.l2 = DLG_TEXT[20];
			}
			else link.l2 = DLG_TEXT[19];
			link.l2.go = "no_deal";
		break;

		case "buy_blue":
			price = makeint(price_blue * cost_multiplier);
			NPChar.item = "blueskull";
			NPChar.price = "" + price;
			dialog.text = DLG_TEXT[16] + price + DLG_TEXT[17];
			if (makeint(PChar.money) >= price)
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "buy_deal";
				link.l2 = DLG_TEXT[20];
			}
			else link.l2 = DLG_TEXT[19];
			link.l2.go = "no_deal";
		break;

		case "buy_deal":
			if (!CheckAttribute(NPChar, "item") || !CheckAttribute(NPChar, "price"))
			{
				dialog.text = "Something is wrong - either I don't know the item or I don't know the price!");
				link.l1 = "Oops...";
				link.l1.go = "exit";
			}
			else
			{
				price = makeint(NPChar.price);
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(pchar, -1 * price);
				GiveItem2Character(PChar, NPChar.item);
				dialog.text = DLG_TEXT[21] + title + " " + GetMyLastName(PChar) + ".";
				link.l1 = DLG_TEXT[23];
				link.l1.go = "exit";
				DeleteAttribute(NPChar, "price");
				DeleteAttribute(NPChar, "item");
			}
		break;

		case "no_deal":
			dialog.text = DLG_TEXT[22] + title + " " + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			DeleteAttribute(NPChar, "price");
			DeleteAttribute(NPChar, "item");
		break;

		case "welcome_back":
			dialog.text = DLG_TEXT[40] + GetMyLastName(PChar) + DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "no_further_business";
			if (CheckQuestAttribute("crys_skull_status", "traded"))
			{
				link.l1 = DLG_TEXT[43];
				link.l1.go = "tell_me_about_adventure";
			}
			if(CheckCharacterItem(PChar, "cryskull"))
			{
				link.l1 = DLG_TEXT[44];
				link.l1.go = "how_get_skull";
			}
		break;

		case "no_further_business":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46] + GetMyFullName(characterFromID("Archaeologist_captain")) + DLG_TEXT[82];
			link.l1.go = "talk_about_enemy_captain";
		break;

		case "tell_me_about_adventure":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48] + GetMyFullName(NPChar) + DLG_TEXT[49];
			link.l1.go = "skull_was_theirs";
		break;

		case "skull_was_theirs":
			string reward;
			if (PChar.quest.crysskull.ultimatum == "hostage") reward = DLG_TEXT[53];
			else reward = DLG_TEXT[54];
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[52] + reward;
			link.l1.go = "anything_else";
			if(CheckCharacterItem(PChar, "tomahawk_chief"))
			{
				link.l2 = DLG_TEXT[51];
				link.l2.go = "tomahawk_offer";
			}
		break;

		case "tomahawk_offer":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "anything_else";
			link.l2 = DLG_TEXT[58];
			link.l2.go = "sell_tomahawk_low";
			if (CalcCharacterSkill(PChar, SKILL_COMMERCE) >= 5)
			{
				link.l3 = DLG_TEXT[59];
				link.l3.go = "sell_tomahawk_high";
			}
		break;

		case "sell_tomahawk_low":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, 15000);
			TakeItemFromCharacter(PChar, "tomahawk_chief");
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81] + GetMyFullName(characterFromID("Archaeologist_captain")) + DLG_TEXT[82];
			link.l1.go = "talk_about_enemy_captain";
		break;

		case "sell_tomahawk_high":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, 20000);
			TakeItemFromCharacter(PChar, "tomahawk_chief");
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "anything_else";
		break;

		case "how_get_skull":
			string ultimatum, followup;
			if (PChar.quest.crysskull.ultimatum == "hostage")
			{
				ultimatum = DLG_TEXT[64];
				followup = DLG_TEXT[66];
			}
			else
			{
				ultimatum = DLG_TEXT[65];
				followup = DLG_TEXT[67];
			}
			if (CheckQuestAttribute("crys_skull_status", "defeated_Caribs")) followup = DLG_TEXT[68];
			dialog.text = DLG_TEXT[62];
			link.l1 = DLG_TEXT[63] + ultimatum + followup;
			if (PChar.quest.crysskull.ultimatum == "hostage" || CheckQuestAttribute("crys_skull_status", "defeated_Caribs")) link.l1.go = "sell_skull_for_gold";
			else link.l1.go = "trade_skull_for_antidote";
		break;

		case "sell_skull_for_gold":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, 20000);
			TakeItemFromCharacter(PChar, "cryskull");
			Preprocessor_AddQuestData("researcher", GetMyFullName(NPChar));
			if (CheckQuestAttribute("crys_skull_status", "defeated_Caribs"))
			{
				AddQuestRecord("crystal_skull", 13);
				dialog.text = DLG_TEXT[71];
			}
			else
			{
				Preprocessor_AddQuestData("hostage", GetMyFullName(GetCharacter(sti(PChar.quest.crysskull.hostage))));
				AddQuestRecord("crystal_skull", 14);
				Preprocessor_Remove("hostage");
				dialog.text = DLG_TEXT[69];
				AddDialogExitQuest("crysskull_officer_betrayed");
			}
			Preprocessor_Remove("researcher");
			link.l1 = DLG_TEXT[72];
			link.l1.go = "anything_else";
		break;

		case "trade_skull_for_antidote":
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[73];
			link.l1.go = "trade_skull_for_antidote2";
		break;

		case "trade_skull_for_antidote2":
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "trade_skull_for_antidote3";
			link.l2 = DLG_TEXT[76];
			link.l2.go = "time_nearly_up";
		break;

		case "time_nearly_up":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "trade_skull_for_antidote3";
		break;

		case "trade_skull_for_antidote3":
			PlayStereoSound("INTERFACE\important_item.flac");
			TakeItemFromCharacter(PChar, "cryskull");
			dialog.text = DLG_TEXT[77];
			link.l1 = DLG_TEXT[78];
			AddDialogExitQuest("crysskull_researcher_fetches_antidote");
			link.l1.go = "exit";
		break;

		case "here_is_antidote":
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "no_complaints";
		break;

		case "no_complaints":
			Preprocessor_AddQuestData("researcher", GetMyFullName(NPChar));
			AddQuestRecord("crystal_skull", 15);
			Preprocessor_Remove("researcher");
			PlayStereoSound("INTERFACE\drink.flac");
			PChar.quest.crysskull_poison_player.over = "yes";
			dialog.text = DLG_TEXT[92];
			link.l1 = DLG_TEXT[93];
			link.l1.go = "anything_else";
		break;

		case "anything_else":
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81] + GetMyFullName(characterFromID("Archaeologist_captain")) + DLG_TEXT[82];
			link.l1.go = "talk_about_enemy_captain";
		break;

		case "talk_about_enemy_captain":
			dialog.text = GetMyFullName(characterFromID("Archaeologist_captain")) + DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "talk_about_enemy_captain2";
		break;

		case "talk_about_enemy_captain2":
			dialog.text = DLG_TEXT[85] + GetMyFullName(characterFromID("Archaeologist_captain")) + DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "colleague_ruined";
		break;

		case "colleague_ruined":
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(PChar, SKILL_LEADERSHIP, 5000);
				AddPartyExpChar(PChar, SKILL_SNEAK, 500);
			}
			else { AddPartyExp(PChar, 5000); }
			Preprocessor_AddQuestData("researcher", GetMyFullName(NPChar));
			Preprocessor_AddQuestData("enemy_captain", GetMyFullName(CharacterFromID("Archaeologist_captain")));
			AddQuestRecord("crystal_skull", 16);
			Preprocessor_Remove("enemy_captain");
			Preprocessor_Remove("researcher");
			CloseQuestHeader("crystal_skull");
			PChar.quest.crys_skull_status = "complete";
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "exit";
		break;
	}
}