void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	string gov_kid, merch_kid, name, offer, gov_kid_pronoun, gov_kid_pronoun2;
	int x, y;

	ref PChar = GetMainCharacter();

	if (PChar.sex == "man")
	{
		gov_kid = "daughter";
		gov_kid_pronoun = "she";
		gov_kid_pronoun2 = "her";
		merch_kid = "son";
	}
	else
	{
		gov_kid = "son";
		gov_kid_pronoun = "he";
		gov_kid_pronoun2 = "him";
		merch_kid = "daughter";
	}

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	
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
				Preprocessor_Add("gov_kid", gov_kid);
				link.l2 = DLG_TEXT[15];
				link.l2.go = "congratulate";
			}
			if (CheckCharacterItem(PChar, "CourtingLetter"))
			{
				link.l2 = DLG_TEXT[122] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyFullName(characterFromID(PChar.quest.romance)) + ".";
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
			link.l99 = DLG_TEXT[16];
			link.l99.go = "exit";
		break;

		case "congratulate":
//			PreProcessor_Add("name", GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_TITLE, true, false));
			PreProcessor_Add("name", characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMyName(characterFromID(PChar.quest.romance)));
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
			if (GetDayTime() == DAY_TIME_NIGHT) dialog.text = GetMySimpleName(characterFromID("Grigorio Formoselle")) + DLG_TEXT[19] + gov_kid + ", " + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[20];
			else dialog.text = DLG_TEXT[28] + gov_kid + DLG_TEXT[29];
			link.l1 = DLG_TEXT[21] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[22];
			link.l1.go = "kidnap_threaten2";
		break;

		case "kidnap_threaten2":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "kidnap_threaten3";
		break;

		case "kidnap_threaten3":
			if (GetDayTime() == DAY_TIME_NIGHT) dialog.text = DLG_TEXT[25] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[26];
			else dialog.text = DLG_TEXT[30] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
		break;

		case "ransom":
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92] + GetMyFullName(characterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "ransom2";
		break;

		case "ransom2":
			dialog.text = DLG_TEXT[93] + GetMyName(characterFromID(PChar.quest.romance)) + ".";
			link.l1 = DLG_TEXT[94] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[95] + gov_kid + DLG_TEXT[96];
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
			dialog.text = DLG_TEXT[97] + GetMySimpleName(characterFromID(PChar.quest.romance)) + " to " + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[98] + offer + DLG_TEXT[101] + gov_kid + DLG_TEXT[102];
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
			link.l1 = DLG_TEXT[106] + gov_kid + DLG_TEXT[107];
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
			link.l1 = DLG_TEXT[111];
			AddDialogExitQuest("governors_revenge");
			link.l1.go = "exit";
		break;

		case "hostage_free":
			TakeItemFromCharacter(Pchar, "ExplainLetter");
			ChangeCharacterReputation(PChar, 2);
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[112] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMySimpleName(characterFromID(PChar.quest.romance)) + ".";
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
			if(!LAi_IsDead(characterFromID(PChar.quest.villain))) AddDialogExitQuest("assassination_attempt");
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
			PreProcessor_Add("child", gov_kid);
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
			PreProcessor_Add("child", gov_kid);
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
			PreProcessor_Add("child", gov_kid);
			link.l3 = DLG_TEXT[157];
			link.l3.go = "Exit_wedding_refused";
		break;

		case "hand_it_over":
			Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
			AddQuestRecord("Marriage", 10);
			Preprocessor_Remove("romance");
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
			dialog.text = DLG_TEXT[167];
			if(GetOfficersIndex(Pchar, 1) != -1)
			{
				link.l1 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 1)]) + ".";
				link.l1.go = "choose_escort_officer1";
			}
			if(GetOfficersIndex(Pchar, 2) != -1)
			{
				link.l2 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 2)]) + ".";
				link.l2.go = "choose_escort_officer2";
			}
			if(GetOfficersIndex(Pchar, 3) != -1)
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
			if(GetOfficersIndex(Pchar, 1) != -1)
			{
				link.l1 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 1)]) + ".";
				link.l1.go = "choose_escort_officer1";
			}
			if(GetOfficersIndex(Pchar, 2) != -1)
			{
				link.l2 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 2)]) + ".";
				link.l2.go = "choose_escort_officer2";
			}
			if(GetOfficersIndex(Pchar, 3) != -1)
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
			GiveItem2Character(PChar, "blade33+3");
			GiveItem2Character(PChar, "goldarmor");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "assassination":
			dialog.text = DLG_TEXT[175];
			link.l1 = GetMyName(characterFromID(PChar.quest.romance)) + "!";
			link.l1.go = "get_physician";
		break;

		case "get_physician":
			dialog.text = DLG_TEXT[176];
			link.l1 = DLG_TEXT[177] + GetMyName(characterFromID(PChar.quest.romance)) + "...";
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
			dialog.text = DLG_TEXT[182] + GetMyName(PChar) + DLG_TEXT[183] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[184];
			link.l1 = DLG_TEXT[185];
			link.l1.go = "carried_this";
		break;

		case "carried_this":
			dialog.text = DLG_TEXT[186];
			if (checkquestattribute("signet_ring_known", "true"))
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
			if (PChar.sex == "man") PreProcessor_Add("pronoun", "he");
			else PreProcessor_Add("pronoun", "she");
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
			if(PChar.married == MR_MARRIED && PChar.married.id == characters[getCharacterIndex(PChar.quest.romance)].id) dialog.text = DLG_TEXT[202];
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
		break;

		case "get_LoM":
			dialog.text = DLG_TEXT[210] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[211];
			link.l1 = DLG_TEXT[212];
			link.l1.go = "wedding_present_lom_accepted";
			link.l2 = DLG_TEXT[142];
			link.l2.go = "wedding_present_lom_rejected";
		break;

		case "convoy_return":
			dialog.text = DLG_TEXT[213] + GetMyName(PChar) + DLG_TEXT[214] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[215];
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
			dialog.text = DLG_TEXT[230] + GetMyName(PChar) + DLG_TEXT[231];
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
			AddDialogExitQuest("convoy_ending");
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

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
