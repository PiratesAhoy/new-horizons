void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string your_gov_kid, your_gov_kid2, my_gov_kid, my_gov_kid2, merch_kid, name, offer, gov_kid_pronoun, gov_kid_pronoun2, gov_kid_pronoun3, merch_kid_pronoun, merch_kid_pronoun2, merch_kid_pronoun3, reward;
	int x, y;

	ref PChar = GetMainCharacter();

	gov_kid_pronoun = XI_ConvertString(GetMyPronounSubj(characterFromID(PChar.quest.romance)));
	gov_kid_pronoun2 = XI_ConvertString(GetMyPronounObj(characterFromID(PChar.quest.romance)));
	merch_kid_pronoun = XI_ConvertString(GetMyPronounSubj(characterFromID(PChar.quest.villain)));
	merch_kid_pronoun2 = XI_ConvertString(GetMyPronounObj(characterFromID(PChar.quest.villain)));
	if (PChar.sex == "man")
	{
		your_gov_kid = DLG_TEXT[431];
		your_gov_kid2 = DLG_TEXT[435];
		my_gov_kid = DLG_TEXT[433];
		my_gov_kid2 = DLG_TEXT[437];
		gov_kid_pronoun3 = XI_ConvertString("her");
		merch_kid = XI_ConvertString("son");
		merch_kid_pronoun3 = XI_ConvertString("his");
	}
	else
	{
		your_gov_kid = DLG_TEXT[432];
		your_gov_kid2 = DLG_TEXT[436];
		my_gov_kid = DLG_TEXT[434];
		my_gov_kid2 = DLG_TEXT[438];
		gov_kid_pronoun3 = XI_ConvertString("his");
		merch_kid = XI_ConvertString("daughter");
		merch_kid_pronoun3 = XI_ConvertString("her");
	}

	if(CheckAttribute(characterFromID(PChar.quest.romance), "married") && characters[getCharacterIndex(PChar.quest.romance)].married == MR_MARRIED && characters[getCharacterIndex(PChar.quest.romance)].married.id == PChar.id)
		name = GetMyName(PChar);
	else name = TranslateString("", "Capitán") + " " + GetMyLastName(PChar);

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	if (CheckQuestAttribute("invasion_status", "goto_Redmond")) PChar.quest.invasion_status = "been_to_Santiago";
	if (CheckQuestAttribute("invasion_status", "been_to_Antigua")) PChar.quest.invasion_status = "Redmond_fallen";
	
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- |иалог первый - первая встреча
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

			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];		// changed from .spa to .por by KAM
			Link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			Link.l1.go = "node_1";
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[10] + GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false) + ".";
			link.l2.go = "node_2";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "quests":
			dialog.text = DLG_TEXT[13] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[14];		// changed from .spa to .por by KAM
			if (CheckQuestAttribute("ardent_kidnap", "Engaged"))
			{
				Preprocessor_Add("your_gov_kid", your_gov_kid);
				link.l2 = DLG_TEXT[15];
				link.l2.go = "congratulate";
			}
			if (CheckCharacterItem(PChar, "CourtingLetter"))
			{
				link.l2 = DLG_TEXT[122] + characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMySimpleName(characterFromID(PChar.quest.romance)) + ".";
				link.l2.go = "see_servant";
			}
			if (CheckQuestAttribute("marriage_status", "waiting_money"))
			{
				if (makeint(PChar.money) >= makeint(PChar.quest.marriage.money))
				{
					link.l2 = DLG_TEXT[164];
					link.l2.go = "hand_it_over";
				}
			}
			if (CheckQuestAttribute("abduction_status", "taken_from_sanjuan") || CheckQuestAttribute("abduction_status", "taken_from_ship"))
			{
				dialog.text = DLG_TEXT[259] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
				link.l2 = DLG_TEXT[260] + GetMyFormalName(characterFromID(PChar.quest.romance)) + DLG_TEXT[261];
				link.l2.go = "abducted_friendly";
			}
			if (CheckQuestAttribute("ardent_treachery_status", "goto_Santiago"))
			{
				link.l2 = DLG_TEXT[283];
				link.l2.go = "threat_news";
			}
			if (CheckCharacterItem(PChar, "BattleOrders2") && !CheckAttribute(PChar, "quest.threat_governor_sent_me"))
			{
				link.l2 = DLG_TEXT[294];
				link.l2.go = "threat_got_battleorders";
			}
			if (CheckQuestAttribute("invasion_status", "been_to_Santiago") || CheckQuestAttribute("invasion_status", "Redmond_fallen"))
			{
				if (!CheckAttribute(PChar, "quest.finale_governor_sent_me"))		// Prevent repeated attempts to inform governor about Port Royale attack
				{
					Preprocessor_Add("type", XI_ConvertString(GetShipTypeName(CharacterFromID("French_Amiral"))));
					Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
					link.l2 = DLG_TEXT[332];
					link.l2.go = "finale_redmond_attack";
				}
			}
			if (CheckAttribute(PChar, "quest.redmond_fallen_known"))			// Attribute set if Antigua admiral told you Port Royale has fallen
			{
				link.l2 = DLG_TEXT[382];
				link.l2.go = "finale_redmond_fallen";
			}
			if (CheckQuestAttribute("finale_evacuate_santiago", "go_get_him"))
			{
				Preprocessor_Add("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
				Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
				link.l2 = DLG_TEXT[383];
				link.l2.go = "finale_evacuate_wont_go";
			}
			if (CheckAttribute(PChar, "quest.imperial_escort_enable") && !CheckAttribute(PChar, "quest.imperial_escort") && GetRank(PChar, SPAIN) >= 5)
			{
				link.l2 = DLG_TEXT[426];
				link.l2.go = "imperial_escort_recommendation";
			}
			link.l99 = DLG_TEXT[16];
			link.l99.go = "exit";
		break;

		case "congratulate":
			PreProcessor_Add("name", Characters[GetCharacterIndex(PChar.quest.romance)].title + " " + GetMyName(CharacterFromID(PChar.quest.romance)));
			dialog.text = DLG_TEXT[17] + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[18];
			AddDialogExitQuest("congratulated_governor");
			link.l1.go = "exit";
		break;

		case "see_servant":
			dialog.text = DLG_TEXT[123] + GetMyFullName(characterFromID("Grigorio Formoselle")) + DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "exit";
		break;

		case "kidnap_threaten":
			if (GetDayTime() == DAY_TIME_NIGHT) dialog.text = GetMySimpleName(characterFromID("Grigorio Formoselle")) + DLG_TEXT[19] + my_gov_kid2 + ", " + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[20];
			else dialog.text = DLG_TEXT[28] + my_gov_kid2 + DLG_TEXT[29];
			link.l1 = DLG_TEXT[21] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[22];
			link.l1.go = "kidnap_threaten2";
		break;

		case "kidnap_threaten2":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "kidnap_threaten3";
		break;

		case "kidnap_threaten3":
			if (GetDayTime() == DAY_TIME_NIGHT) dialog.text = DLG_TEXT[25] + GetMyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[26];
			else dialog.text = DLG_TEXT[30] + GetMyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
		break;

		case "ransom":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92] + GetMyFullName(CharacterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "ransom2";
		break;

		case "ransom2":
			dialog.text = DLG_TEXT[93] + GetMyName(CharacterFromID(PChar.quest.romance)) + ".";
			link.l1 = DLG_TEXT[94] + GetMyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[95] + your_gov_kid2 + DLG_TEXT[96];
			link.l1.go = "ransom3";
		break;

		case "ransom3":
			if (checkquestattribute("payroll_ship", "success"))
			{
				offer = DLG_TEXT[99];
				PChar.quest.ardent_kidnap.ransom = 40000;
			}
			else
			{
				offer = DLG_TEXT[100];
				PChar.quest.ardent_kidnap.ransom = 50000;
			}
			dialog.text = DLG_TEXT[97] + GetMySimpleName(CharacterFromID(PChar.quest.romance)) + " to " + GetMySimpleName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[98] + offer + DLG_TEXT[101] + my_gov_kid + DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "ransom_accept";
			link.l2 = DLG_TEXT[104];
			link.l2.go = "ransom_reject";
		break;

		case "ransom_reject":
			AddDialogExitQuest("ransom_rejected");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "ransom_accept":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106] + your_gov_kid2 + DLG_TEXT[107];
			link.l1.go = "ransom_deal";
		break;

		case "ransom_deal":
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			AddDialogExitQuest("ransom_accepted");
			link.l1.go = "exit";
		break;

		case "revenge":
			dialog.text = DLG_TEXT[110];
			if (CheckQuestAttribute("revenge_type", "kidnap_rescue") && ispassenger(characterFromID(PChar.quest.romance)))
			{
				Preprocessor_Add("romance", characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMyName(characterFromID(PChar.quest.romance)));
//				if (isofficer(characterFromID(PChar.quest.romance)))
				if (characters[getCharacterIndex(PChar.quest.romance)].location == PChar.location)
				{
					link.l1 = DLG_TEXT[318];
					if (CheckQuestAttribute("ardent_convoy", "battle_over")) link.l1.go = "revenge_romance_with_you";
					else link.l1.go = "kidnap_rescue_return";
				}
				else
				{
					link.l1 = DLG_TEXT[300];
					link.l1.go = "revenge_wasnt_me";
				}
			}
			else
			{
				link.l1 = DLG_TEXT[111];
				AddDialogExitQuest("governors_revenge");
				link.l1.go = "exit";
			}
		break;

		case "revenge_wasnt_me":
			Preprocessor_Add("my_gov_kid2", my_gov_kid2);
			Preprocessor_Add("romance", GetMyName(CharacterFromID(PChar.quest.romance)));
			Preprocessor_Add("villain", GetMySimpleName(CharacterFromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun", gov_kid_pronoun);
			Preprocessor_Add("pronoun2", gov_kid_pronoun2);
			dialog.text = DLG_TEXT[301];
			link.l1 = DLG_TEXT[302];
			link.l1.go = "revenge_wasnt_me_go_fetch";
		break;

		case "revenge_wasnt_me_go_fetch":
			Preprocessor_Add("romance", GetMyName(characterFromID(PChar.quest.romance)));
			Preprocessor_Add("pronoun", gov_kid_pronoun);
			Preprocessor_Add("pronoun2", gov_kid_pronoun2);
			dialog.text = DLG_TEXT[303];
			link.l1 = DLG_TEXT[304];
			AddDialogExitQuest("governors_revenge_fetch_romance");
			link.l1.go = "exit";
		break;

		case "revenge_failed_to_fetch":
			Preprocessor_Add("romance", GetMyName(characterFromID(PChar.quest.romance)));
			Preprocessor_Add("pronoun2", gov_kid_pronoun2);
			dialog.text = DLG_TEXT[305];
			link.l1 = DLG_TEXT[306];
			AddDialogExitQuest("governors_revenge");
			link.l1.go = "exit";
		break;

		case "revenge_romance_with_you":
			Preprocessor_Add("person", PChar.sex);
			Preprocessor_Add("pronoun", GetMyPronounSubj(PChar));
			dialog.text = GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[307];
			link.l1 = "";
			AddDialogExitQuest("governors_revenge_romance_answers");
			link.l1.go = "exit";
		break;

		case "revenge_what_sort_revenge":
			dialog.text = DLG_TEXT[308];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "revenge_you_may_go":
			Preprocessor_Add("my_gov_kid2", my_gov_kid2);
			Preprocessor_Add("romance", GetMyName(characterFromID(PChar.quest.romance)));
			Preprocessor_Add("pronoun", gov_kid_pronoun);
			dialog.text = DLG_TEXT[309] + GetMyLastName(PChar) + DLG_TEXT[310];
			link.l1 = DLG_TEXT[311];
			link.l1.go = "exit_revenge_keep_romance";
			link.l2 = DLG_TEXT[312];
			link.l2.go = "exit_revenge_leave_romance";
		break;

		case "revenge_romance_stays_with_you":
			if(GetRMRelation(PChar, SPAIN) < REL_AMNESTY)
			{
				Preprocessor_Add("my_gov_kid", my_gov_kid);
				SetRMRelation(PChar, SPAIN, REL_AMNESTY);
				dialog.text = DLG_TEXT[313] + GetMyLastName(PChar) + DLG_TEXT[314];
				link.l1 = DLG_TEXT[315];
			}
			else
			{
				Preprocessor_Add("romance", characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMyName(characterFromID(PChar.quest.romance)));
				Preprocessor_Add("pronoun", gov_kid_pronoun);
				Preprocessor_Add("pronoun3", gov_kid_pronoun3);
				dialog.text = DLG_TEXT[316];
				link.l1 = DLG_TEXT[317];
			}
			link.l1.go = "exit";
		break;

		case "hostage_free":
			TakeItemFromCharacter(Pchar, "ExplainLetter");
			ChangeCharacterReputation(PChar, 2);
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[112] + GetMyAddressForm(NPChar, CharacterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMySimpleName(CharacterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "hostage_free2";
		break;

		case "hostage_free2":
			dialog.text = DLG_TEXT[113];
			link.l1 = DLG_TEXT[114] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[115];
			link.l1.go = "hostage_free3";
		break;

		case "hostage_free3":
			if(GetRMRelation(Pchar, SPAIN) > REL_WAR)
			{
				dialog.text = DLG_TEXT[116] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[117] + gov_kid_pronoun + DLG_TEXT[118];
			}
			else
			{
				dialog.text = DLG_TEXT[116] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[117] + gov_kid_pronoun + DLG_TEXT[119];
			}
			link.l1 = DLG_TEXT[120] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[121];
			AddDialogExitQuest("governor_relaxes");
			link.l1.go = "Exit";
		break;

		case "now_youre_married":
			dialog.text = DLG_TEXT[126] + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[127];
			link.l1 = DLG_TEXT[128] + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + ".";
			link.l1.go = "back_to_residence";
		break;

		case "back_to_residence":
			dialog.text = DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "Exit";
		break;

		case "enjoy_reception":
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			if(!LAi_IsDead(characterFromID(PChar.quest.villain)) && !CheckAttribute(PChar, "quest.finale_marriage")) AddDialogExitQuest("assassination_attempt");
			link.l1.go = "Exit";
		break;

		case "reception_done":
			PreProcessor_Add("name", GetMyFirstNames(PChar, false));
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "goodnight";
		break;

		case "goodnight":
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "Exit";
		break;

		case "marriage_request":
			if(PChar.married == MR_MARRIED)
			{
				dialog.text = DLG_TEXT[173];
				link.l1 = DLG_TEXT[174];
				AddDialogExitQuest("broken_heart");
			}
			else
			{
				if (CheckCharacterItem(PChar, "ExplainLetter"))
				{
					PreProcessor_Add("pronoun", gov_kid_pronoun2);
					dialog.text = DLG_TEXT[145] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[146];
					link.l1 = DLG_TEXT[147];
				}
				else
				{
					PreProcessor_Add("pronoun", gov_kid_pronoun);
					PreProcessor_Add("name", GetMyFirstNames(characterFromID(PChar.quest.romance), false));
					dialog.text = DLG_TEXT[143] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[144];
					link.l1 = DLG_TEXT[147];
				}
				AddDialogExitQuest("marriage_partner_interrupts");
			}
			link.l1.go = "Exit";
		break;

		case "soft_heart":
			dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149];
			link.l1.go = "Exit";
		break;

		case "not_marry_pirate":
			PreProcessor_Add("my_gov_kid", my_gov_kid);
			dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[151];
			link.l1.go = "need_loadsamoney";
		break;

		case "need_loadsamoney":
			x = GetDifficulty() - 1;
			PChar.quest.marriage.money = 100000 + (100000 * x^2);
//			PChar.quest.marriage.money = 200000;
			dialog.text = DLG_TEXT[152] + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[153] + PChar.quest.marriage.money + DLG_TEXT[154];
			link.l1 = DLG_TEXT[155];
			link.l1.go = "dont_want_to_know";
			if (makeint(PChar.money) >= makeint(PChar.quest.marriage.money))
			{
				link.l2 = DLG_TEXT[156];
				link.l2.go = "hand_it_over";
			}
			PreProcessor_Add("your_gov_kid2", your_gov_kid2);
			link.l3 = DLG_TEXT[157];
			link.l3.go = "Exit_wedding_refused";
		break;

		case "dont_want_to_know":
			Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
			AddQuestRecord("Marriage", 8);
			Preprocessor_Remove("romance");
			dialog.text = DLG_TEXT[160];
			link.l1 = DLG_TEXT[161];
			PChar.quest.marriage_status = "waiting_money";
			link.l1.go = "Exit_get_more_money";
		break;

		case "ready_yet":
			dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			link.l1.go = "Exit_get_more_money";
			if (makeint(PChar.money) >= makeint(PChar.quest.marriage.money))
			{
				link.l2 = DLG_TEXT[164];
				link.l2.go = "hand_it_over";
			}
			PreProcessor_Add("your_gov_kid2", your_gov_kid2);
			link.l3 = DLG_TEXT[157];
			link.l3.go = "Exit_wedding_refused";
		break;

		case "hand_it_over":
			PlayStereoSound("INTERFACE\took_item.wav");
			x = makeint(PChar.quest.marriage.money) * -1;
			AddMoneytoCharacter(PChar, x);
			LeaveService(PChar, PIRATE, false);	// You give up being a pirate
			if(GetServedNation() == PIRATE) SetServedNation(PERSONAL_NATION);
			PChar.quest.marriage_status = "money_paid";
			dialog.text = DLG_TEXT[165];
			link.l1 = DLG_TEXT[166];
			link.l1.go = "choose_escort_first_time";
		break;

		case "choose_escort_first_time":
			if (CheckAttribute(PChar, "quest.finale_marriage"))
			{
				if(CheckAttribute(PChar, "QuestInfo.Marriage")==false)
				{
					SetQuestHeader("Marriage");
				}
				Preprocessor_AddQuestData("governor", GetMyFullName(NPChar));
				Preprocessor_AddQuestData("romance", GetMyFullName(characterFromID(PChar.quest.romance)));
				AddQuestRecord("Marriage", 18);
				Preprocessor_Remove("romance");
				Preprocessor_Remove("governor");
				dialog.text = DLG_TEXT[423];
			}
			else
			{
				AddQuestRecord("Marriage", 10);
				dialog.text = DLG_TEXT[167];
			}
			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(PChar, 1) != GetCharacterIndex(PChar.quest.romance))
			{
				link.l1 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 1)]) + ".";
				link.l1.go = "choose_escort_officer1";
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(PChar, 2) != GetCharacterIndex(PChar.quest.romance))
			{
				link.l2 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 2)]) + ".";
				link.l2.go = "choose_escort_officer2";
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(PChar, 3) != GetCharacterIndex(PChar.quest.romance))
			{
				link.l3 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 3)]) + ".";
				link.l3.go = "choose_escort_officer3";
			}
			link.l4 = DLG_TEXT[168];
			link.l4.go = "no_escort";
			link.l5 = DLG_TEXT[169];
			link.l5.go = "Exit_not_chosen_escort";
		break;

		case "choose_escort_try_again":
			dialog.text = DLG_TEXT[170];
			if(GetOfficersIndex(Pchar, 1) != -1 && GetOfficersIndex(PChar, 1) != GetCharacterIndex(PChar.quest.romance))
			{
				link.l1 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 1)]) + ".";
				link.l1.go = "choose_escort_officer1";
			}
			if(GetOfficersIndex(Pchar, 2) != -1 && GetOfficersIndex(PChar, 2) != GetCharacterIndex(PChar.quest.romance))
			{
				link.l2 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 2)]) + ".";
				link.l2.go = "choose_escort_officer2";
			}
			if(GetOfficersIndex(Pchar, 3) != -1 && GetOfficersIndex(PChar, 3) != GetCharacterIndex(PChar.quest.romance))
			{
				link.l3 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 3)]) + ".";
				link.l3.go = "choose_escort_officer3";
			}
			link.l4 = DLG_TEXT[168];
			link.l4.go = "no_escort";
			link.l5 = DLG_TEXT[169];
			link.l5.go = "Exit_not_chosen_escort";
		break;

		case "choose_escort_officer1":
			PChar.quest.wedding_escort = characters[GetOfficersIndex(Pchar, 1)].id;
			AddDialogExitQuest("escort_chosen");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "choose_escort_officer2":
			PChar.quest.wedding_escort = characters[GetOfficersIndex(Pchar, 2)].id;
			AddDialogExitQuest("escort_chosen");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "choose_escort_officer3":
			PChar.quest.wedding_escort = characters[GetOfficersIndex(Pchar, 3)].id;
			AddDialogExitQuest("escort_chosen");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "no_escort":
			PChar.quest.wedding_escort = "";
			AddDialogExitQuest("escort_chosen");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "wait_in_tavern":
			dialog.text = DLG_TEXT[171];
			link.l1 = DLG_TEXT[172];
			link.l1.go = "Exit";
		break;

		case "be_ashamed":
			dialog.text = DLG_TEXT[158];
			link.l1 = DLG_TEXT[159];
			link.l1.go = "Exit";
		break;

		case "wedding_present":
			if (CheckAttribute(PChar, "quest.finale_marriage")) AddDialogExitQuest("finale_end_story");
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "wedding_present2";
		break;

		case "wedding_present2":
			if(!IsInServiceOf(SPAIN))
			{
				dialog.text = DLG_TEXT[139];
				link.l1 = DLG_TEXT[141];
				link.l1.go = "wedding_present_lom_accepted";
				link.l2 = DLG_TEXT[142];
				link.l2.go = "wedding_present_lom_rejected";
			}
			else
			{
				dialog.text = DLG_TEXT[140];
				link.l1 = DLG_TEXT[141];
				link.l1.go = "wedding_present_sword";
			}
		break;

		case "wedding_present_lom_accepted":
			SetRank(PChar, SPAIN, GetOldRank(PChar, SPAIN));
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "wedding_present_lom_rejected":
			if(GetRMRelation(PChar, SPAIN) < REL_AMNESTY) SetRMRelation(PChar, SPAIN, REL_AMNESTY);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "wedding_present_sword":
			GiveItem2Character(PChar, "bladeC23+3");
			GiveItem2Character(PChar, "goldarmor");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "assassination":
			dialog.text = DLG_TEXT[175];
			link.l1 = GetMyName(CharacterFromID(PChar.quest.romance)) + "!";
			link.l1.go = "get_physician";
		break;

		case "get_physician":
			dialog.text = DLG_TEXT[176];
			link.l1 = DLG_TEXT[177] + GetMyName(CharacterFromID(PChar.quest.romance)) + "...";
			link.l1.go = "go_get_him";
		break;

		case "go_get_him":
			dialog.text = DLG_TEXT[178];
			link.l1 = DLG_TEXT[179];
			link.l1.go = "need_him_alive";
		break;

		case "need_him_alive":
			AddQuestRecord("Marriage", 14);
			dialog.text = DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "Exit";
		break;

		case "will_be_fine":
			dialog.text = DLG_TEXT[182] + GetMyName(PChar) + DLG_TEXT[183] + GetMyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[184];
			link.l1 = DLG_TEXT[185];
			link.l1.go = "carried_this";
		break;

		case "carried_this":
			dialog.text = DLG_TEXT[186];
			if (CheckQuestAttribute("signet_ring_known", "true"))
			{
				link.l1 = DLG_TEXT[188] + GetMyFullName(characterFromID(PChar.quest.villain)) + DLG_TEXT[189] + GetMyName(characterFromID(PChar.quest.romance)) + ".";
				link.l1.go = "villain_hired_assassin";
			}
			else
			{
				link.l1 = DLG_TEXT[187];
				AddDialogExitQuest("assassination_grigorio_explains_ring");
				link.l1.go = "Exit";
			}
		break;

		case "villain_hired_assassin":
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			AddQuestRecord("Marriage", 16);
			Preprocessor_Remove("villain");
			dialog.text = DLG_TEXT[190] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[191];
			PreProcessor_Add("pronoun", merch_kid_pronoun);
			link.l1 = DLG_TEXT[192] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[193] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[194];
			link.l1.go = "retaliation_and_rest";			
		break;

		case "retaliation_and_rest":
			PreProcessor_Add("pronoun", gov_kid_pronoun);
			dialog.text = DLG_TEXT[195] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[196];
			link.l1 = DLG_TEXT[197];
			AddDialogExitQuest("assassination_fade_to_next_day");
			link.l1.go = "Exit";
		break;

		case "romance_recovered":
			dialog.text = DLG_TEXT[198] + GetMyName(PChar) + DLG_TEXT[199] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[200];
			link.l1 = DLG_TEXT[201];
			link.l1.go = "Exit";
		break;

		case "convoy_letter_reprisal":
			if (PChar.married == MR_MARRIED && PChar.married.id == characters[getCharacterIndex(PChar.quest.romance)].id) dialog.text = DLG_TEXT[202];
			else dialog.text = DLG_TEXT[203];
			dialog.text = dialog.text + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[204];
			link.l1 = DLG_TEXT[205];
			link.l1.go = "convoy_safety_warning";
		break;

		case "convoy_safety_warning":
			PreProcessor_Add("pronoun", gov_kid_pronoun2);
			dialog.text = DLG_TEXT[206] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[207];
			link.l1 = DLG_TEXT[208] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[209];
			if(!IsInServiceOf(SPAIN)) link.l1.go = "get_LoM";
			else link.l1.go = "Exit";
			if (checkquestattribute("abduction_status", "go_to_church") || CheckQuestAttribute("abduction_status", "been_to_church")) link.l1.go = "abduction_reward";
		break;

		case "get_LoM":
			dialog.text = DLG_TEXT[210] + GetMyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[211];
			link.l1 = DLG_TEXT[212];
			link.l1.go = "wedding_present_lom_accepted";
			link.l2 = DLG_TEXT[142];
			link.l2.go = "wedding_present_lom_rejected";
		break;

		case "convoy_return":
			dialog.text = DLG_TEXT[213] + name + DLG_TEXT[214] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[215];
			link.l1 = DLG_TEXT[216] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[217] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[218];
			link.l1.go = "convoy_believed_this";
		break;

		case "convoy_believed_this":
			dialog.text = DLG_TEXT[219];
			link.l1 = DLG_TEXT[220] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[221];
			link.l1.go = "convoy_confused";
		break;

		case "convoy_confused":
			PreProcessor_Add("pronoun", gov_kid_pronoun);
			dialog.text = GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[222];
			link.l1 = DLG_TEXT[223];
			link.l1.go = "convoy_take_ship";
		break;

		case "convoy_take_ship":
			dialog.text = DLG_TEXT[224];
			link.l1 = DLG_TEXT[225];
			link.l1.go = "convoy_other_ships";
		break;

		case "convoy_other_ships":
			if (PChar.ship.type == "RN_WarGalleon" || PChar.ship.type == "PO_WarGalleon" || PChar.ship.type == "FR_WarGalleon" || PChar.ship.type == "NL_WarGalleon" || PChar.ship.type == "SP_WarGalleon" || PChar.ship.type == "FR_Licorne")
			{
				dialog.text = DLG_TEXT[226];
				link.l1 = DLG_TEXT[227];
				AddDialogExitQuest("convoy_get_ship_back");
				link.l1.go = "Exit";
			}
			else
			{
				if (PChar.quest.ardent_convoy == "put_ship_back") dialog.text = DLG_TEXT[245];
				else
				{
					PChar.quest.ardent_convoy = "put_ship_back";
					dialog.text = DLG_TEXT[244] + DLG_TEXT[245];
				}
				link.l1 = DLG_TEXT[58];
				link.l1.go = "Exit_get_ship";
			}
		break;

		case "convoy_interesting_idea":
			dialog.text = DLG_TEXT[228];
			link.l1 = DLG_TEXT[229];
			link.l1.go = "Exit";
		break;

		case "convoy_next_day":
			PreProcessor_Add("dutch_gov", GetMyLastName(characterFromID("Hans Kloss")));
			dialog.text = DLG_TEXT[230] + name + DLG_TEXT[231];
			link.l1 = DLG_TEXT[232];
			link.l1.go = "Exit";
		break;

		case "convoy_agree_ship":
			PreProcessor_Add("pronoun", gov_kid_pronoun);
			PreProcessor_Add("pronoun2", gov_kid_pronoun2);
			dialog.text = DLG_TEXT[233];
			link.l1 = DLG_TEXT[234] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[235];
			link.l1.go = "Exit";
		break;

		case "convoy_return_from_trade":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "convoy_return_from_trade2";
			link.l2 = DLG_TEXT[10] + GetCharacterAddressForm(NPChar, ADDR_TITLE, false, false) + ".";
			link.l2.go = "node_2";
		break;

		case "convoy_return_from_trade2":
			dialog.text = DLG_TEXT[236] + GetMyName(PChar) + "?";
			link.l1 = DLG_TEXT[237] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[238] + GetMyFullName(characterFromID("Hans Kloss")) + DLG_TEXT[239];;
			link.l1.go = "convoy_return_from_trade3";
		break;

		case "convoy_return_from_trade3":
			dialog.text = DLG_TEXT[240] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[241];
			PreProcessor_Add("pronoun", gov_kid_pronoun);
			if (PChar.quest.alignment == "good") link.l1 = DLG_TEXT[242];
			else link.l1 = DLG_TEXT[243];
			link.l1.go = "exit_convoy_ending1";
			link.l2 = DLG_TEXT[281] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[282];
			link.l2.go = "exit_convoy_ending2";
		break;

		case "spain_betrayal":
			dialog.text = DLG_TEXT[279];
			link.l1 = DLG_TEXT[280];
			AddDialogExitQuest("back_to_prison");
			link.l1.go = "exit";
		break;

		case "romance_dead":
			dialog.text = DLG_TEXT[246] + GetMyName(characterFromID(PChar.quest.romance)) + "?";
			PreProcessor_Add("pronoun", gov_kid_pronoun);
			link.l1 = DLG_TEXT[247];
			link.l1.go = "romance_dead2";
		break;

		case "romance_dead2":
			dialog.text = DLG_TEXT[248] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[249];
			link.l1 = DLG_TEXT[250] + GetMyName(characterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "romance_dead3";
		break;

		case "romance_dead3":
			dialog.text = DLG_TEXT[251];
			link.l1 = DLG_TEXT[252];
			Preprocessor_AddQuestData("romance", GetMyName(characterFromID(PChar.quest.romance)));
			Preprocessor_AddQuestData("governor", GetMySimpleName(characterFromID("Javier Balboa")));
			AddQuestRecord("Convoy Strike", 14);
			CloseQuestHeader("Convoy Strike");
			Preprocessor_Remove("governor");
			Preprocessor_Remove("romance");
			link.l1.go = "Exit_romance_dead";
		break;

		case "youre_responsible":
			if (HaveLetterOfMarque(SPAIN))
			{
				dialog.text = DLG_TEXT[253] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[255];
				LeaveService(PChar, SPAIN, false);
			}
			else dialog.text = DLG_TEXT[253] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[254];
			Locations[FindLocation("Santiago_Town_01")].dangerous = true;
			Locations[FindLocation("Santiago_port")].dangerous = true;
			link.l1 = DLG_TEXT[256];
			link.l1.go = "Exit_responsible";
		break;

		case "youre_enemy":
			if (HaveLetterOfMarque(SPAIN)) LeaveService(PChar, SPAIN, true);
			SetRMRelation(PChar, SPAIN, REL_WAR);
			dialog.text = DLG_TEXT[257];
			link.l1 = DLG_TEXT[258];
			link.l1.go = "Exit_responsible";
		break;

		case "abducted_friendly":
			dialog.text = DLG_TEXT[262];
			PreProcessor_Add("pronoun", gov_kid_pronoun2);
			if (CheckAttribute(characterFromID(PChar.quest.romance),"officer")) link.l1 = characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[263] + DLG_TEXT[265];
			else
			{
				PreProcessor_Add("pronoun2", gov_kid_pronoun);
				link.l1 = characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[264] + DLG_TEXT[265];
			}
			link.l1.go = "abducted_no_ransom";
		break;

		case "abducted_no_ransom":
			dialog.text = DLG_TEXT[266] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + DLG_TEXT[267] + characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[268];
			link.l1 = DLG_TEXT[269];
			AddDialogExitQuest("abduction_seen_governor");
			link.l1.go = "Exit";
		break;

		case "abduction_return":
			dialog.text = GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[270];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "abduction_outrage":
			dialog.text = DLG_TEXT[271] + GetMySimpleName(characterFromID(PChar.quest.villain)) + ".";
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "abduction_reward":
			if(!IsInServiceOf(SPAIN))
			{
				if(GetRMRelation(PChar, SPAIN) < REL_AMNESTY) dialog.text = DLG_TEXT[272] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[274];
				else dialog.text = DLG_TEXT[272] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[275];
				link.l1 = DLG_TEXT[276];
				link.l1.go = "wedding_present_lom_accepted";
				link.l2 = DLG_TEXT[142];
				link.l2.go = "wedding_present_lom_rejected";
			}
			else
			{
				dialog.text = DLG_TEXT[272] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[273];
				link.l1 = DLG_TEXT[276];
				link.l1.go = "wedding_present_sword";
			}
		break;

		case "kidnap_rescue_return":
			PreProcessor_Add("pronoun", merch_kid_pronoun);
			dialog.text = GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[277] + GetMySimpleName(PChar) + DLG_TEXT[278];
			link.l1 = "";
			AddDialogExitQuest("kidnap_rescue_romance_to_governor1");
			link.l1.go = "exit";
		break;

		case "kidnap_rescue_received_letter":
			PreProcessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			PreProcessor_Add("merch_kid_pronoun2", merch_kid_pronoun2);
			PreProcessor_Add("merch_kid_pronoun3", merch_kid_pronoun3);
			dialog.text = DLG_TEXT[319] + GetMyName(PChar) + DLG_TEXT[320];
//			AddDialogExitQuest("kidnap_rescue_romance_to_governor2");
			link.l1.go = "exit";
		break;

		case "kidnap_rescue_believe_you":
			PlayStereoSound("INTERFACE\paper_small.wav");
			PreProcessor_Add("romance", GetMyName(characterFromID(PChar.quest.romance)));
			PreProcessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[321];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "kidnap_rescue_propose_deal":
			Preprocessor_Add("romance", GetMyName(characterFromID(PChar.quest.romance)));
			Preprocessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[322] + GetMyLastName(PChar) + DLG_TEXT[325] + DLG_TEXT[326];
			if(!IsInServiceOf(SPAIN))
			{
				if(GetRMRelation(PChar, SPAIN) < REL_AMNESTY) dialog.text = DLG_TEXT[322] + GetMyLastName(PChar) + DLG_TEXT[323] + DLG_TEXT[325] + DLG_TEXT[326];
				else dialog.text = DLG_TEXT[322] + GetMyLastName(PChar) + DLG_TEXT[324] + DLG_TEXT[325] + DLG_TEXT[326];
			}
			link.l1 = DLG_TEXT[327];
			link.l1.go = "kidnap_rescue_deal_agreed";
		break;

		case "kidnap_rescue_deal_agreed":
			Preprocessor_Add("romance", GetMyName(characterFromID(PChar.quest.romance)));
			Preprocessor_Add("my_gov_kid2", my_gov_kid2);
			Preprocessor_Add("pronoun2", gov_kid_pronoun2);
			dialog.text = DLG_TEXT[328] + GetMyLastName(PChar) + DLG_TEXT[329] + GetMyLastName(PChar) + DLG_TEXT[330];
			link.l1 = DLG_TEXT[331];
			link.l1.go = "exit";
		break;

		case "threat_news":
			DeleteQuestAttribute("ardent_treachery_status");
			dialog.text = DLG_TEXT[284] + name + "?";
			link.l1 = DLG_TEXT[285];
			link.l1.go = "threat_we_have_some_time";
		break;

		case "threat_we_have_some_time":
			dialog.text = DLG_TEXT[286];
			link.l1 = DLG_TEXT[287];
			link.l1.go = "threat_your_job";
		break;

		case "threat_your_job":
			dialog.text = DLG_TEXT[288];
			if (PChar.quest.alignment == "good")
			{
				link.l1 = DLG_TEXT[289];
				link.l1.go = "threat_agree_goto_guadeloupe";
			}
			link.l2 = DLG_TEXT[290];
			link.l2.go = "threat_demand_expenses";
		break;

		case "threat_agree_goto_guadeloupe":
			dialog.text = DLG_TEXT[291];
			link.l1 = DLG_TEXT[293];
			PChar.quest.threat_burglary_reward = "honour";
			AddDialogExitQuest("threat_alternate_guadeloupe_setup");
			link.l1.go = "exit";
		break;

		case "threat_demand_expenses":
			dialog.text = DLG_TEXT[292];
			link.l1 = DLG_TEXT[293];
			PChar.quest.threat_burglary_reward = "money";
			AddDialogExitQuest("threat_alternate_guadeloupe_setup");
			link.l1.go = "exit";
		break;

		case "threat_got_battleorders":
			if (CheckQuestAttribute("threat_burglary_reward", "honour"))
			{
				dialog.text = DLG_TEXT[295] + name + DLG_TEXT[296] + DLG_TEXT[298];
				GiveItem2Character(PChar, "medal1");
				ChangeCharacterReputation(PChar, 10);
			}
			else
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneytoCharacter(PChar, 5000);
				dialog.text = DLG_TEXT[295] + name + DLG_TEXT[297] + DLG_TEXT[298];
			}
			DeleteQuestAttribute("threat_burglary_reward");
			PChar.quest.threat_governor_sent_me = "true";
			Preprocessor_AddQuestData("governor", GetMySimpleName(characterFromID("Javier Balboa")));
			AddQuestRecord("Santiago Threat", 5);
			Preprocessor_Remove("governor");
			link.l1 = DLG_TEXT[299];
			link.l1.go = "exit";
		break;

		case "finale_redmond_attack":
			if (CheckQuestAttribute("invasion_status", "Redmond_fallen"))
			{
				Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
				dialog.text = DLG_TEXT[349] + name + DLG_TEXT[350];
				link.l1 = DLG_TEXT[351];
				link.l1.go = "finale_redmond_fallen_santiago_next";
			}
			else
			{
				Preprocessor_Add("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
				dialog.text = DLG_TEXT[333];
				link.l1 = DLG_TEXT[334];
				link.l1.go = "finale_santiago_next";
			}
		break;

		case "finale_santiago_next":
			dialog.text = DLG_TEXT[335] + DLG_TEXT[336];
			link.l1 = DLG_TEXT[337];
			link.l1.go = "finale_proposition1";
		break;

		case "finale_proposition1":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			dialog.text = DLG_TEXT[338];
			link.l1 = DLG_TEXT[339];
			link.l1.go = "finale_proposition_no_way";
			link.l2 = DLG_TEXT[340];
			link.l2.go = "finale_proposition_accepted";
		break;

		case "finale_proposition_no_way":
			Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			if (CheckQuestAttribute("payroll_ship", "success")) dialog.text = DLG_TEXT[341] + name + DLG_TEXT[342] + DLG_TEXT[343];
			else dialog.text = DLG_TEXT[341] + name + DLG_TEXT[342];
			link.l1 = DLG_TEXT[344];
			link.l1.go = "finale_proposition_accepted";
		break;

		case "finale_proposition_accepted":
			if (!CheckAttribute(PChar, "QuestInfo.Battle Royale")) SetQuestHeader("Battle Royale");
			Preprocessor_AddQuestData("governor", GetMySimpleName(CharacterFromID("Javier Balboa")));
			if(!CheckAttribute(PChar, "quest.finale_galleons") && GetCompanionQuantity(PChar) <= COMPANION_MAX-2)
			{
				AddQuestRecord("Battle Royale", 4);
				Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
				dialog.text = DLG_TEXT[345] + DLG_TEXT[346];
				link.l1 = DLG_TEXT[347];
				PChar.quest.finale_galleons_assigned_by = "Javier Balboa";
				AddDialogExitQuest("finale_assign_galleons");
			}
			else
			{
				AddQuestRecord("Battle Royale", 3);
				Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
				dialog.text = DLG_TEXT[345];
				link.l1 = DLG_TEXT[348];
			}
			Preprocessor_Remove("governor");
			link.l1.go = "exit";
		break;

		case "finale_redmond_fallen":
			Preprocessor_Add("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			dialog.text = DLG_TEXT[333];
			link.l1 = DLG_TEXT[334];
			link.l1.go = "finale_redmond_fallen_santiago_next";
		break;

		case "finale_redmond_fallen_santiago_next":
			PChar.quest.invasion_status = "Santiago_threatened";
			Preprocessor_Add("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			dialog.text = DLG_TEXT[335] + DLG_TEXT[352];
			link.l1 = DLG_TEXT[353];
			link.l1.go = "finale_redmond_fallen_goto_havana";
		break;

		case "finale_redmond_fallen_goto_havana":
			dialog.text = DLG_TEXT[354];
			link.l1 = DLG_TEXT[355];
			if (CheckAttribute(PChar, "quest.redmond_fallen_known"))
			{
				DeleteQuestAttribute("redmond_fallen_known");
				Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
				Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
				AddQuestRecord("Battle Royale", 27);
				Preprocessor_Remove("governor");
				Preprocessor_Remove("admiral");
			}
			else
			{
				if (!CheckAttribute(PChar, "QuestInfo.Battle Royale")) SetQuestHeader("Battle Royale");
				AddQuestRecord("Battle Royale", 6);
				AddDialogExitQuest("finale_port_royale_fallen");
			}
			PChar.quest.finale_governor_sent_me = "true";
			link.l1.go = "exit";
		break;

		case "finale_after_port_royale_reward":
			dialog.text = DLG_TEXT[356] + name + DLG_TEXT[357];
			link.l1 = DLG_TEXT[358];
			link.l1.go = "finale_after_port_royale_choose_reward";
		break;

		case "finale_after_port_royale_choose_reward":
			if(CheckAttribute(PChar, "quest.French_flagship.name")) Preprocessor_Add("warship", PChar.quest.French_flagship.name);
			else Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			dialog.text = DLG_TEXT[359] + DLG_TEXT[378];		// Default - pay money
			link.l1 = DLG_TEXT[380] + DLG_TEXT[381];
			link.l1.go = "exit_finale_pay_for_port_royale";

			if (!HaveLetterOfMarque(SPAIN) && !CheckAttribute(PChar, "quest.spain_betrayal"))
			{							// You don't already have a LoM, so offer one
				dialog.text = DLG_TEXT[359] + DLG_TEXT[366];
				if (HaveLetterOfMarque(ENGLAND))
				{
					link.l1 = DLG_TEXT[367];
					link.l1.go = "finale_already_got_English_LOM";
				}
				link.l2 = DLG_TEXT[368];
				link.l3 = DLG_TEXT[369];
				if (!LAi_IsDead(characterFromID(PChar.quest.romance)) && PChar.married == MR_SINGLE && !CheckAttribute(PChar, "quest.spain_betrayal"))
				{
					link.l2.go = "finale_accept_LOM_propose_marriage";
					link.l3.go = "finale_reject_LOM_propose_marriage";
				}
				else
				{
					link.l2.go = "finale_accept_LOM";
					link.l3.go = "finale_reject_LOM";
				}
			}

			if (HaveLetterOfMarque(SPAIN) && !LAi_IsDead(characterFromID(PChar.quest.romance))) // You already have Spanish LoM, so get promoted
			{
				NPChar.templand = GetCharacterLand(PChar);
				Promote(&PChar, &NPChar, SPAIN);
				if (GetRank(PChar, SPAIN) < 3) Promote(&PChar, &NPChar, SPAIN); // Double promotion if low rank
				dialog.text = DLG_TEXT[359] + DLG_TEXT[375] + TranslateString(GetRankName(PChar, SPAIN),"") + DLG_TEXT[376] + (GetCharacterLand(PChar) - sti(NPChar.templand)) + DLG_TEXT[377];
				DeleteAttribute(NPChar,"templand");
				if (!LAi_IsDead(characterFromID(PChar.quest.romance)) && PChar.married == MR_SINGLE && !CheckAttribute(PChar, "quest.spain_betrayal"))
				{
					link.l1 = DLG_TEXT[197];
					link.l1.go = "finale_propose_marriage2";
				}
				else
				{
					link.l1 = DLG_TEXT[380] + DLG_TEXT[381];
					link.l1.go = "exit_finale_promoted";
				}
			}

			if (LAi_IsDead(characterFromID(PChar.quest.romance)))	// If Lucia / Edmundo dead, governor forgives you instead of reward
			{
				Preprocessor_Add("My_gov_kid", FirstLetterUp(my_gov_kid));
				Preprocessor_Add("my_gov_kid2", my_gov_kid2);
				Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
				dialog.text = DLG_TEXT[359] + DLG_TEXT[379];
				link.l1 = DLG_TEXT[380] + DLG_TEXT[381];
				AddDialogExitQuest("finale_end_story");
				link.l1.go = "exit";
			}
		break;

		case "finale_already_got_English_LOM":
			dialog.text = DLG_TEXT[370];
			link.l1 = DLG_TEXT[371];
			link.l2 = DLG_TEXT[372];
			if (!LAi_IsDead(characterFromID(PChar.quest.romance)) && PChar.married == MR_SINGLE && !CheckAttribute(PChar, "quest.spain_betrayal"))
			{
				link.l1.go = "finale_accept_LOM_propose_marriage";
				link.l2.go = "finale_reject_LOM_propose_marriage";
			}
			else
			{
				link.l1.go = "finale_accept_LOM";
				link.l2.go = "finale_reject_LOM";
			}
		break;

		case "finale_accept_LOM":
			SetRank(PChar, SPAIN, GetOldRank(PChar, SPAIN));
			Promote(&PChar, &NPChar, SPAIN);
			dialog.text = DLG_TEXT[373] + name + ".";
			Preprocessor_AddQuestData("governor", GetMyLastName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Battle Royale", 17);
			Preprocessor_Remove("governor");
			AddDialogExitQuest("finale_end_story");
			link.l1 = DLG_TEXT[380] + DLG_TEXT[381];
			link.l1.go = "exit";
		break;

		case "finale_reject_LOM":
			dialog.text = DLG_TEXT[374];
			Preprocessor_AddQuestData("governor", GetMyLastName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Battle Royale", 20);
			Preprocessor_Remove("governor");
			link.l1 = DLG_TEXT[380] + DLG_TEXT[381];
			AddDialogExitQuest("finale_end_story");
			link.l1.go = "exit";
		break;

		case "finale_accept_LOM_propose_marriage":
			SetRank(PChar, SPAIN, GetOldRank(PChar, SPAIN));
			Promote(&PChar, &NPChar, SPAIN);
			dialog.text = DLG_TEXT[373] + name + ".";
			link.l1 = DLG_TEXT[197];
			link.l1.go = "finale_propose_marriage2";
		break;

		case "finale_reject_LOM_propose_marriage":
			dialog.text = DLG_TEXT[374];
			link.l1 = DLG_TEXT[422];
			link.l1.go = "finale_propose_marriage2";
		break;

		case "finale_evacuate_wont_go":
			PChar.quest.finale_evacuate_santiago = "wont_go";
			dialog.text = DLG_TEXT[384];
			link.l1 = DLG_TEXT[385];
			link.l1.go = "finale_evacuate_cant_make_me";
		break;

		case "finale_evacuate_cant_make_me":
			Preprocessor_Add("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			dialog.text = DLG_TEXT[386];
			link.l1 = DLG_TEXT[387];
			if (LAi_IsDead(characterFromID(PChar.quest.romance))) link.l1.go = "finale_farewell";
			else link.l1.go = "finale_evacuate_take_kid";
		break;

		case "finale_farewell":
			dialog.text = DLG_TEXT[393];
			link.l1 = DLG_TEXT[394];
			AddDialogExitQuest("finale_evacuate_santiago_prepare_for_french_fleet");
			link.l1.go = "exit";
		break;

		case "finale_evacuate_take_kid":
			Preprocessor_Add("my_gov_kid2", my_gov_kid2);
			Preprocessor_Add("romance", GetMyRespectfullyName(CharacterFromID(PChar.quest.romance)));
//			if (!isofficer(CharacterFromID(PChar.quest.romance)) && !ispassenger(CharacterFromID(PChar.quest.romance)) && !iscompanion(CharacterFromID(PChar.quest.romance)))
			if (Characters[GetCharacterIndex(PChar.quest.romance)].location == PChar.location)
			{
				dialog.text = DLG_TEXT[388] + DLG_TEXT[390];
			}
			else
			{
				dialog.text = DLG_TEXT[389] + DLG_TEXT[390];
			}
			if (Characters[GetCharacterIndex(PChar.quest.romance)].location == PChar.location)
			{
				link.l1 = DLG_TEXT[391];
				AddDialogExitQuest("finale_evacuate_santiago_take_romance");
			}
			else
			{
				link.l1 = DLG_TEXT[392];
				AddDialogExitQuest("finale_evacuate_santiago_prepare_for_french_fleet");
			}
			link.l1.go = "exit";
		break;

		case "finale_go_kid_go":
			Preprocessor_Add("romance", GetMyName(CharacterFromID(PChar.quest.romance)));
			dialog.text = DLG_TEXT[395];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "finale_after_santiago_reward":
			dialog.text = DLG_TEXT[396] + name + "!";
			link.l1 = DLG_TEXT[397];
			link.l1.go = "finale_after_santiago_reward2";
		break;

		case "finale_after_santiago_reward2":
			if(CheckAttribute(PChar, "quest.French_flagship.name")) Preprocessor_Add("warship", PChar.quest.French_flagship.name);
			else Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			if (CheckAttribute(PChar, "quest.finale_galleons") && makeint(PChar.quest.finale_galleons) > 0)
			{
				dialog.text = DLG_TEXT[398] + DLG_TEXT[399] + DLG_TEXT[400];
			}
			else dialog.text = DLG_TEXT[398] + DLG_TEXT[400];
			link.l1 = DLG_TEXT[401];			
			link.l1.go = "finale_after_port_santiago_receive_rewards";
		break;

		case "finale_after_port_santiago_receive_rewards":
			Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
			Preprocessor_Add("my_gov_kid2", my_gov_kid2);
			reward = "";
			if(GetRMRelation(PChar, SPAIN) < REL_AMNESTY)
			{
				reward = DLG_TEXT[403];
				SetRMRelation(PChar, SPAIN, REL_AMNESTY);
			}
			if (LAi_IsDead(characterFromID(PChar.quest.romance)))
			{
				if (reward == "") reward = DLG_TEXT[404] + DLG_TEXT[406];
				else reward = reward + DLG_TEXT[405] + DLG_TEXT[406];
				AddDialogExitQuest("finale_end_story");
				link.l1.go = "exit";
			}
			else
			{
				if (CheckAttribute(PChar, "quest.spain_betrayal")) link.l1.go = "exit";
				else link.l1.go = "finale_after_santiago_promotion_or_lom";
			}
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, 100000);
			if (reward == "") reward = DLG_TEXT[408];
			else reward = reward + DLG_TEXT[407];
			dialog.text = reward;
			link.l1 = DLG_TEXT[409];
		break;


		case "finale_after_santiago_promotion_or_lom":
			if (!HaveLetterOfMarque(SPAIN) && !CheckAttribute(PChar, "quest.spain_betrayal"))
			{							// You don't already have a LoM, so offer one
				dialog.text = DLG_TEXT[410] + DLG_TEXT[366];
				if (HaveLetterOfMarque(ENGLAND))
				{
					link.l1 = DLG_TEXT[367];
					link.l1.go = "finale_already_got_English_LOM";
				}
				link.l2 = DLG_TEXT[368];
				link.l3 = DLG_TEXT[369];
				if (!LAi_IsDead(characterFromID(PChar.quest.romance)) && PChar.married == MR_SINGLE && !CheckAttribute(PChar, "quest.spain_betrayal"))
				{
					link.l2.go = "finale_accept_LOM_propose_marriage";
					link.l3.go = "finale_reject_LOM_propose_marriage";
				}
				else
				{
					link.l2.go = "finale_accept_LOM";
					link.l3.go = "finale_reject_LOM";
				}
			}

			if (HaveLetterOfMarque(SPAIN))				// You already have Spanish LoM, so get promoted
			{
				NPChar.templand = GetCharacterLand(PChar);
				Promote(&PChar, &NPChar, SPAIN);
				if (GetRank(PChar, SPAIN) < 3) Promote(&PChar, &NPChar, SPAIN); // Double promotion if low rank
				dialog.text = DLG_TEXT[410] + DLG_TEXT[375] + TranslateString(GetRankName(PChar, SPAIN),"") + DLG_TEXT[376] + (GetCharacterLand(PChar) - sti(NPChar.templand)) + DLG_TEXT[377];
				DeleteAttribute(NPChar,"templand");
				if (!LAi_IsDead(characterFromID(PChar.quest.romance)) && PChar.married == MR_SINGLE)
				{
					link.l1 = DLG_TEXT[197];
					link.l1.go = "finale_propose_marriage2";
				}
				else
				{
					link.l1 = DLG_TEXT[380] + DLG_TEXT[381];
					link.l1.go = "exit_finale_promoted";
				}
			}
		break;

		case "finale_propose_marriage2":
			Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
			Preprocessor_Add("villain", GetMyFullName(CharacterFromID(PChar.quest.villain)));
			Preprocessor_Add("My_gov_kid", FirstLetterUp(my_gov_kid));
			Preprocessor_Add("pronoun", gov_kid_pronoun);
			Preprocessor_Add("pronoun2", gov_kid_pronoun2);
			if (!LAi_IsDead(characterFromID(PChar.quest.villain))) dialog.text = DLG_TEXT[411] + DLG_TEXT[360] + DLG_TEXT[362];
			else dialog.text = DLG_TEXT[411] + DLG_TEXT[361] + DLG_TEXT[362];
			if(GetRMRelation(PChar, SPAIN) < REL_AFTERATTACK) dialog.text = dialog.text + DLG_TEXT[430];
			if (PChar.sex == "woman") Preprocessor_Add("my_spouse", XI_ConvertString("my husband"));
			else Preprocessor_Add("my_spouse", XI_ConvertString("my wife"));
			if (PChar.quest.alignment == "good")
			{
				link.l1= DLG_TEXT[363];
				if (Characters[GetCharacterIndex(PChar.quest.romance)].location == PChar.location) link.l1.go = "exit_finale_romance_answers_marriage";
				else link.l1.go = "finale_marriage_governor_answers_for_romance";
				link.l2 = DLG_TEXT[364];
				link.l2.go = "finale_marriage_rejected";
			}
			else
			{
				link.l1 = DLG_TEXT[364];
				link.l1.go = "finale_marriage_rejected";
				link.l2= DLG_TEXT[363];
				if (Characters[GetCharacterIndex(PChar.quest.romance)].location == PChar.location) link.l2.go = "exit_finale_romance_answers_marriage";
				else link.l2.go = "finale_marriage_governor_answers_for_romance";
			}
		break;

		case "finale_marriage_governor_answers_for_romance":
			Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
			Preprocessor_Add("pronoun2", gov_kid_pronoun2);
			dialog.text = DLG_TEXT[412];
			link.l1 = DLG_TEXT[413];
			link.l1.go = "finale_marriage_do_you_have_ring";
		break;

		case "finale_marriage_rejected":
			dialog.text = DLG_TEXT[365];
			link.l1 = DLG_TEXT[381];
			AddDialogExitQuest("finale_end_story");
			link.l1.go = "exit";
		break;

		case "finale_marriage_do_you_have_ring":
			if(GetRMRelation(PChar, SPAIN) < REL_AFTERATTACK) SetRMRelation(PChar, SPAIN, REL_AMNESTY);
			if(!CheckAttribute(PChar, "quest.betrayed_spain"))
			{
				PChar.quest.betrayed_spain.win_condition.l1 = "relation";
				PChar.quest.betrayed_spain.win_condition.l1.relation = "Hostile";
				PChar.quest.betrayed_spain.win_condition.l1.nation = "Spain";
				PChar.quest.betrayed_spain.win_condition = "betrayed_spain";
			}
			PChar.quest.finale_marriage = "true";
			dialog.text = DLG_TEXT[414];
			if (CheckCharacterItem(PChar, "jewelry7")) // Gold emerald ring
			{
				link.l1 = DLG_TEXT[415];
				link.l1.go = "finale_marriage_gold_ring";
			}
			if (CheckCharacterItem(PChar, "jewelry10")) // Gold sapphire ring
			{
				link.l2 = DLG_TEXT[416];
				link.l2.go = "finale_marriage_sapphire_ring";
			}
			if (!CheckCharacterItem(PChar, "jewelry7") && !CheckCharacterItem(PChar, "jewelry10"))
			{
				link.l3 = DLG_TEXT[417];
				link.l3.go = "finale_marriage_no_ring";
			}
		break;

		case "finale_marriage_gold_ring":
			TakeItemFromCharacter(Pchar, "jewelry7");
			GiveItem2Character(PChar, "jewelry7_q");
			PChar.quest.wedding_ring = "jewelry7_q";
			dialog.text = DLG_TEXT[418];
			link.l1 = DLG_TEXT[419];
			link.l1.go = "choose_escort_first_time";
		break;

		case "finale_marriage_sapphire_ring":
			TakeItemFromCharacter(Pchar, "jewelry10");
			GiveItem2Character(PChar, "jewelry10_q");
			PChar.quest.wedding_ring = "jewelry10_q";
			dialog.text = DLG_TEXT[418];
			link.l1 = DLG_TEXT[419];
			link.l1.go = "choose_escort_first_time";
		break;

		case "finale_marriage_no_ring":
			GiveItem2Character(PChar, "jewelry10_q");
			PChar.quest.wedding_ring = "jewelry10_q";
			Preprocessor_Add("my_gov_kid", my_gov_kid);
			Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
			dialog.text = DLG_TEXT[420];
			link.l1 = DLG_TEXT[421];
			link.l1.go = "choose_escort_first_time";
		break;

		case "finale_villain_was_traitor":
			Preprocessor_Add("villain", GetMyFullName(CharacterFromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun3", merch_kid_pronoun3);
			dialog.text = DLG_TEXT[424];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "finale_reconsecrate_with_wedding":
			dialog.text = DLG_TEXT[425];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "imperial_escort_recommendation":
			SetQuestHeader("Imperial Escort");
			Preprocessor_AddQuestData("admiral", GetMyFullName(CharacterFromID("Jusepe Guimaraes")));
			Preprocessor_AddQuestData("governor", GetMyFullName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Imperial Escort", 50);
			Preprocessor_Remove("governor");
			Preprocessor_Remove("admiral");
			if(CheckAttribute(PChar, "quest.French_flagship.name")) Preprocessor_Add("warship", PChar.quest.French_flagship.name);
			else Preprocessor_Add("warship", Characters[GetCharacterIndex("French_Amiral")].Ship.Name);
			dialog.text = DLG_TEXT[427] + GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[428];
			link.l1 = DLG_TEXT[429];
			link.l1.go = "exit";
		break;

		case "Exit_get_more_money":
			AddDialogExitQuest("marriage_governor_waits");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_wedding_refused":
			AddDialogExitQuest("broken_heart");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_get_ship":
			NextDiag.CurrentNode = "convoy_other_ships";
			DialogExit();
		break;

		case "Exit_not_chosen_escort":
			if(OFFICER_MAX <= 4) logit("Hint: To make an officer available as an escort, assign that officer to one of the shore party slots.");
			else logit("Hint: To make an officer available as an escort, assign that officer to one of the first three shore party slots.");
			PChar.quest.marriage_status = "need_escort";
			AddDialogExitQuest("marriage_governor_waits");
			DialogExit();
			NextDiag.CurrentNode = "choose_escort_try_again";
		break;

		case "Exit_romance_dead":
			NextDiag.CurrentNode = "youre_responsible";
			DialogExit();
		break;

		case "Exit_responsible":
			NextDiag.CurrentNode = "youre_enemy";
			DialogExit();
		break;

		case "exit_convoy_ending1":
			AddDialogExitQuest("convoy_ending");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_convoy_ending2":
			AddDialogExitQuest("convoy_ending_goodbye");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_revenge_keep_romance":
			AddDialogExitQuest("governors_revenge_keep_romance");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_revenge_leave_romance":
			AddDialogExitQuest("governors_revenge_leave_romance");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_finale_pay_for_port_royale":
			Preprocessor_AddQuestData("governor", GetMyLastName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Battle Royale", 16);
			Preprocessor_Remove("governor");
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneytoCharacter(PChar, 100000);
			AddDialogExitQuest("finale_end_story");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_finale_promoted":
			Preprocessor_AddQuestData("governor", GetMyLastName(CharacterFromID("Javier Balboa")));
			AddQuestRecord("Battle Royale", 18);
			Preprocessor_Remove("governor");
			AddDialogExitQuest("finale_end_story");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_finale_romance_answers_marriage":
			AddDialogExitQuest("finale_marriage_romance_accepts");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
