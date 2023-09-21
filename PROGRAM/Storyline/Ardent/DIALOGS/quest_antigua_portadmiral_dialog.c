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

	Npchar.nation = Characters[getCharacterIndex("St John's Commander")].nation;

	if (CheckQuestAttribute("invasion_status", "goto_Redmond")) PChar.quest.invasion_status = "been_to_Antigua";
	if (CheckQuestAttribute("invasion_status", "been_to_Santiago")) PChar.quest.invasion_status = "Redmond_fallen";

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADI\PADI001";

			Dialog.text =  DLG_TEXT[0];
			link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[2];
			link.l1.go = "intro";
		break;

		case "intro":
			if(GetRMRelation(Pchar, sti(NPChar.nation) ) <= REL_WAR )
			{
				Dialog.text = GetMyFullName(PChar) + DLG_TEXT[3];
				link.l1 = Randswear();
				link.l1.go = "fight";
			}
			else
			{
				Preprocessor_Add("background", XI_ConvertString(PChar.quest.background));
				Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
				if (CheckQuestAttribute("treachery_peace_england", "reward")) Dialog.text = GetMyFullName(PChar) + DLG_TEXT[4] + DLG_TEXT[5] + DLG_TEXT[7];
				else Dialog.text = GetMyFullName(PChar) + DLG_TEXT[4] + DLG_TEXT[6] + DLG_TEXT[7];
				if (CheckCharacterItem(PChar, "BattleOrders"))
				{
					link.l1 = DLG_TEXT[44];
					link.l1.go = "ardent_hunt_offer_document_first_time";
				}
				else
				{
					link.l1 = DLG_TEXT[8];
					link.l1.go = "ardent_hunt_info1";
				}
			}
		break;

		case "ardent_hunt_info1":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			if (CheckQuestAttribute("invasion_status", "Redmond_fallen"))
			{
				dialog.text = DLG_TEXT[56] + DLG_TEXT[58] + GetMyLastName(PChar) + ".";
				link.l1 = DLG_TEXT[23];
				AddDialogExitQuest("reset_antigua_portadmiral");
				AddDialogExitQuest("finale_port_royale_fallen");
				link.l1.go = "exit";
			}
			else
			{
				Dialog.text = DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go = "ardent_hunt_info2";
			}
		break;

		case "ardent_hunt_info2":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "ardent_hunt_info3";
		break;

		case "ardent_hunt_info3":
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "ardent_hunt_all_now";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "ardent_hunt_half_now";
			link.l3 = DLG_TEXT[16];
			link.l3.go = "ardent_hunt_all_later";
		break;

		case "ardent_hunt_all_now":
			Preprocessor_AddQuestData("ship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			Preprocessor_AddQuestData("amount", "3500");
			AddQuestRecord("Villain_Hunt", 7);
			Preprocessor_Remove("amount");
			Preprocessor_Remove("ship");
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "ardent_hunt_deal_done";
			PChar.quest.hunt_admiral_owes = 0;
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, 3500);
		break;

		case "ardent_hunt_half_now":
			PChar.quest.hunt_admiral_owes = 2500;
			Preprocessor_AddQuestData("ship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			Preprocessor_AddQuestData("amount1", "2500");
			Preprocessor_AddQuestData("amount2", PChar.quest.hunt_admiral_owes);
			AddQuestRecord("Villain_Hunt", 8);
			Preprocessor_Remove("amount2");
			Preprocessor_Remove("amount1");
			Preprocessor_Remove("ship");
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "ardent_hunt_deal_done";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, 2500);
		break;

		case "ardent_hunt_all_later":
			PChar.quest.hunt_admiral_owes = 6000;
			Preprocessor_AddQuestData("ship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			Preprocessor_AddQuestData("amount", PChar.quest.hunt_admiral_owes);
			AddQuestRecord("Villain_Hunt", 9);
			Preprocessor_Remove("amount");
			Preprocessor_Remove("ship");
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "ardent_hunt_deal_done";
		break;

		case "ardent_hunt_deal_done":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			Dialog.text = DLG_TEXT[21] + GetMyRespectfullyName(PChar) + DLG_TEXT[22];
			if (makeint(PChar.quest.hunt_admiral_owes) == 0) link.l1 = DLG_TEXT[23];
			else link.l1 = DLG_TEXT[23] + DLG_TEXT[24];
			Diag.TempNode = "ardent_hunt_why_still_here";
			AddDialogExitQuest("hunt_admiral_owes_money");
			AddDialogExitQuest("sink_dauphin_escort");
			link.l1.go = "exit";
		break;

		case "ardent_hunt_why_still_here":
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
		break;

		case "ardent_hunt_pay_balance": // This case is only activated if the admiral owes you money
			Preprocessor_AddQuestData("amount", PChar.quest.hunt_admiral_owes);
			AddQuestRecord("Villain_Hunt", 10);
			Preprocessor_Remove("amount");
			Preprocessor_Add("amount", PChar.quest.hunt_admiral_owes);
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			Dialog.text = DLG_TEXT[27] + GetMyRespectfullyName(PChar) + DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "ardent_hunt_battle_report";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, makeint(PChar.quest.hunt_admiral_owes));
			PChar.quest.hunt_admiral_owes = 0;
			DeleteQuestAttribute("hunt_admiral_ready_to_pay");
		break;

		case "ardent_hunt_return_visit": // This case is activated if you bring "BattleOrders", you previously reported the ship at Marigot and the admiral does not owe you money
			Dialog.text = DLG_TEXT[34] + GetMyRespectfullyName(PChar) + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "ardent_hunt_offer_document";
		break;

		case "ardent_hunt_battle_report":
			Preprocessor_AddQuestData("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			AddQuestRecord("Villain_Hunt", 11);
			Preprocessor_Remove("warship");
			if (CheckQuestAttribute("invasion_status", "Redmond_fallen"))
			{
				if (!CheckAttribute(PChar, "QuestInfo.Battle Royale")) SetQuestHeader("Battle Royale");
				Preprocessor_AddQuestData("governor", GetMySimpleName(CharacterFromID("Javier Balboa")));
				AddQuestRecord("Battle Royale", 5);
				Preprocessor_Remove("governor");
				Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
				Dialog.text = DLG_TEXT[30] + "\n" + DLG_TEXT[59];
				link.l1 = DLG_TEXT[60];
				AddDialogExitQuest("reset_antigua_portadmiral");
				AddDialogExitQuest("finale_port_royale_fallen");
				PChar.quest.redmond_fallen_known = "true";
				link.l1.go = "exit";
			}
			else
			{
				Dialog.text = DLG_TEXT[30];
				if (CheckCharacterItem(PChar, "BattleOrders"))
				{
					Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
					link.l1 = DLG_TEXT[31] + DLG_TEXT[33];
					link.l1.go = "ardent_hunt_offer_document";
				}
				else
				{
					if (!CheckAttribute(PChar, "QuestInfo.Battle Royale")) SetQuestHeader("Battle Royale");
					Preprocessor_AddQuestData("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
					Preprocessor_AddQuestData("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID(PChar.quest.villain))));
					AddQuestRecord("Battle Royale", 2);
					Preprocessor_Remove("pronoun");
					Preprocessor_Remove("villain");
					Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
					link.l1 = DLG_TEXT[31] + DLG_TEXT[32];
					AddDialogExitQuest("reset_antigua_portadmiral");
					link.l1.go = "exit";
				}
			}
		break;

		case "ardent_hunt_offer_document":
			PChar.quest.hunt_document_paid = "false";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "ardent_hunt_propose_mission";
//			link.l1.go = "ardent_hunt_need_to_consider"; // Temporary end-point until finale is written
		break;

		case "ardent_hunt_propose_mission":
			if (CheckQuestAttribute("invasion_status", "Redmond_fallen"))
			{
				if (!CheckAttribute(PChar, "QuestInfo.Battle Royale")) SetQuestHeader("Battle Royale");
				Preprocessor_AddQuestData("governor", GetMySimpleName(CharacterFromID("Javier Balboa")));
				AddQuestRecord("Battle Royale", 5);
				Preprocessor_Remove("governor");
				TakeItemFromCharacter(PChar, "BattleOrders");
				Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
				dialog.text = DLG_TEXT[57] + DLG_TEXT[58] + GetMyLastName(PChar) + ".";
				link.l1 = DLG_TEXT[23];
				AddDialogExitQuest("reset_antigua_portadmiral");
				AddDialogExitQuest("finale_port_royale_fallen");
				PChar.quest.redmond_fallen_known = "true";
				link.l1.go = "exit";
			}
			else
			{
				Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
				dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "ardent_hunt_propose_mission2";
			}
		break;

		case "ardent_hunt_propose_mission2":
			if (CheckQuestAttribute("hunt_document_paid", "true"))
			{
				dialog.text = DLG_TEXT[41];
			}
			else
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(PChar, 10000);
				dialog.text = DLG_TEXT[41] + DLG_TEXT[42];
			}
			if (!CheckAttribute(PChar, "QuestInfo.Battle Royale")) SetQuestHeader("Battle Royale");
			Preprocessor_AddQuestData("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			AddQuestRecord("Battle Royale", 1);
			Preprocessor_Remove("warship");
			DeleteQuestAttribute("hunt_document_paid");
			link.l1 = DLG_TEXT[43];
			AddDialogExitQuest("reset_antigua_portadmiral");
			AddDialogExitQuest("sink_dauphin_escort");
			AddDialogExitQuest("finale_port_royale_evacuation_setup");
			link.l1.go = "exit";
		break;

		case "ardent_hunt_offer_document_first_time":
			PChar.quest.hunt_document_paid = "false";
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "ardent_hunt_whats_document_worth";
		break;

		case "ardent_hunt_whats_document_worth":
			if (CheckQuestAttribute("invasion_status", "Redmond_fallen"))
			{
				TakeItemFromCharacter(PChar, "BattleOrders");
				if (!CheckAttribute(PChar, "QuestInfo.Battle Royale")) SetQuestHeader("Battle Royale");
				Preprocessor_AddQuestData("governor", GetMySimpleName(CharacterFromID("Javier Balboa")));
				AddQuestRecord("Battle Royale", 5);
				Preprocessor_Remove("governor");
				Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
				dialog.text = DLG_TEXT[57] + DLG_TEXT[58] + GetMyLastName(PChar) + ".";
				link.l1 = DLG_TEXT[23];
				AddDialogExitQuest("reset_antigua_portadmiral");
				AddDialogExitQuest("finale_port_royale_fallen");
				PChar.quest.redmond_fallen_known = "true";
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[47];
				link.l1 = DLG_TEXT[48];
				link.l1.go = "ardent_hunt_propose_mission_1a";
//				link.l1.go = "ardent_hunt_need_to_consider2"; // Temporary end-point until finale is written
				link.l2 = DLG_TEXT[49];
				link.l2.go = "ardent_hunt_document_advance_payment";
			}
		break;

		case "ardent_hunt_document_advance_payment":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, 5000);
			PChar.quest.hunt_document_paid = "true";
			dialog.text = DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "ardent_hunt_propose_mission_1a";
//			link.l1.go = "ardent_hunt_need_to_consider2"; // Temporary end-point until finale is written
		break;

		case "ardent_hunt_propose_mission_1a":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "ardent_hunt_propose_mission2";
		break;

		case "ardent_hunt_need_to_consider":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			if (CheckQuestAttribute("hunt_document_paid", "true"))
			{
				dialog.text = DLG_TEXT[53];
			}
			else
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(PChar, 10000);
				dialog.text = DLG_TEXT[53] + DLG_TEXT[42];
			}
			DeleteQuestAttribute("hunt_document_paid");
			TakeItemFromCharacter(PChar, "BattleOrders");
			link.l1 = DLG_TEXT[55];
			AddDialogExitQuest("reset_antigua_portadmiral");
			AddDialogExitQuest("sink_dauphin_escort");
			link.l1.go = "exit";
		break;

		case "ardent_hunt_need_to_consider2":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			if (CheckQuestAttribute("hunt_document_paid", "true"))
			{
				dialog.text = DLG_TEXT[54];
			}
			else
			{
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(PChar, 10000);
				dialog.text = DLG_TEXT[54] + DLG_TEXT[42];
			}
			DeleteQuestAttribute("hunt_document_paid");
			TakeItemFromCharacter(PChar, "BattleOrders");
			link.l1 = DLG_TEXT[55];
			AddDialogExitQuest("reset_antigua_portadmiral");
			AddDialogExitQuest("sink_dauphin_escort");
			link.l1.go = "exit";
		break;

// --------------------- exits -----------------
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
//			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "fight":
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_039.wav");
			LAi_group_SetRelation(NPchar.chr_ai.group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			Ambush("Soldiers", 3, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, ""); // GR: was "navy"
//			Diag.CurrentNode = Diag.TempNode;
//			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}