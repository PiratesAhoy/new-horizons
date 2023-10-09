//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	int x;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	string romance_title = XI_ConvertString(Characters[GetCharacterIndex(PChar.quest.romance)].title);
	
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

		case "snow_brig_check":
			dialog.text = DLG_TEXT[2];
			if (PChar.sex == "man") link.l1 = DLG_TEXT[3];
			else link.l1 = DLG_TEXT[65];
			link.l1.go = "snow_brig_check2";
		break;

		case "snow_brig_check2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "snow_brig_check3";
		break;

		case "snow_brig_check3":
			dialog.text = DLG_TEXT[6];
			if (PChar.sex == "man") link.l1 = DLG_TEXT[7];
			else link.l1 = DLG_TEXT[66];
			link.l1.go = "snow_brig_check4";
			link.l2 = GetMyFullName(PChar) + ".";
			link.l2.go = "wrong_answer";
		break;

		case "snow_brig_check4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "wrong_answer";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "right_answer";
		break;

		case "wrong_answer":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Exit";
			AddDialogExitQuest("back_to_prison");
		break;

		case "right_answer":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit";
			AddDialogExitQuest("ship_is_ours3");
		break;

		case "residence_challenge":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16] + GetMyFullName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[17];
			link.l1.go = "Exit";
		break;

		case "hostage_cooperated":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit";
		break;

		case "residence_challenge_day":
			dialog.text = DLG_TEXT[20] + GetMyFullName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[21];
			IF (PChar.sex == "woman")
			{
				link.l1 = DLG_TEXT[206] + GetMyRespectfullyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[207];
				link.l1.go = "residence_challenge_tailor";
			}
			else
			{
				link.l1 = DLG_TEXT[22] + GetMyFullName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[23] + GetMyRespectfullyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[24];
				link.l1.go = "Exit";
			}
		break;

		case "residence_challenge_tailor":
			dialog.text = DLG_TEXT[208];
			link.l1 = DLG_TEXT[209];
			link.l1.go = "Exit";
		break;

		case "still_suspicious":
			dialog.text = DLG_TEXT[25] + GetMyRespectfullyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[26] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.villain), ADDR_CIVIL, false, true) + DLG_TEXT[27];
			if (PChar.sex == "woman")
			{
				link.l1 =DLG_TEXT[210];
				link.l1.go = "still_suspicious2F";
			}
			else
			{
				link.l1 = DLG_TEXT[28];
				link.l1.go = "still_suspicious2";
			}
		break;

		case "still_suspicious2":
			dialog.text = DLG_TEXT[29] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.villain), ADDR_CIVIL, true, true) + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit";
		break;

		case "still_suspicious2F":
			dialog.text =DLG_TEXT[211];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit";
		break;

		case "wrong_way":
			if (PChar.sex == "woman")
			{
				dialog.text = DLG_TEXT[212];
				link.l1= DLG_TEXT[213];
			}
			else
			{
				dialog.text = DLG_TEXT[32] + GetMyRespectfullyName(CharacterFromID(PChar.quest.romance)) + "?";
				link.l1 = DLG_TEXT[33];
			}
			link.l1.go = "Exit";
		break;

		case "no_church_for_you":
			if (PChar.sex == "woman")
			{
				dialog.text = DLG_TEXT[216];
				link.l1 = DLG_TEXT[217];
			}
			else
			{
				dialog.text = GetMyFullName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[34];
				link.l1 = DLG_TEXT[35];
			}
			link.l1.go = "Exit";
		break;

		case "no_escape_to_port":
			if (PChar.sex == "woman")
			{
				dialog.text = DLG_TEXT[214];
				link.l1 = DLG_TEXT[215];
			}
			else
			{
				dialog.text = DLG_TEXT[36] + GetMyRespectfullyName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[37];
				link.l1 = DLG_TEXT[38];
			}
			link.l1.go = "Exit";
		break;

		case "did_you_get_ring":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			AddDialogExitQuest("out_of_store_ring2");
			link.l1.go = "Exit";
		break;

		case "brooch_to_Edmundo":
			dialog.text = DLG_TEXT[218] + GetMySimpleName(CharacterFromID(PChar.quest.romance)) + DLG_TEXT[219] + GetMyAddressForm(NPChar, CharacterFromID(PChar.quest.romance), ADDR_POLITE, false, false) + DLG_TEXT[220];
			link.l1 = "...";
			link.l1.go = "Exit";
		break;

		case "disguise_fail":
			if (CheckAttribute(NPChar, "nation")) PChar.quest.detector_group = GetSoldiersGroup(sti(NPChar.nation));
			else PChar.quest.detector_group = GetSoldiersGroup(GetTownNation(GetCurrentTownID()));
			AddDialogExitQuest("disguise_failed");
			dialog.text = DLG_TEXT[221] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[222];
			link.l1 = DLG_TEXT[223];
			link.l1.go = "exit";
		break;

		case "port_challenge":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "who_with_you";
		break;

		case "who_with_you":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
		break;

		case "cabin_boy":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
		break;

		case "guard_embarrassed":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47]
			link.l1.go = "exit";
		break;

		case "assassination_arrest":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "not_guilty";
		break;

		case "not_guilty":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "father_in_law";
		break;

		case "father_in_law":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "lying";
		break;

		case "lying":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
		break;

		case "go_to_governor":
			Preprocessor_Add("noun", XI_ConvertString(PChar.sex));
			if (PChar.sex == "man") PreProcessor_Add("relation-in-law", DLG_TEXT[204]);
			else PreProcessor_Add("relation-in-law", DLG_TEXT[205]);
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "exit";
		break;

		case "convoy_search":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[60];
			AddDialogExitQuest("convoy_searchers_arrive");
			link.l1.go = "exit";
		break;

		case "convoy_found_romance":
			dialog.text = DLG_TEXT[61];
			if (PChar.sex == "man") PreProcessor_Add("relation", XI_ConvertString("daughter"));
			else PreProcessor_Add("relation", XI_ConvertString("son"));
			link.l1 = DLG_TEXT[62] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[63] + GetMyFullName(characterFromID("Javier Balboa")) + DLG_TEXT[64];
			link.l1.go = "exit";
		break;

		case "French_first_time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "French_Exit";
		break;

		case "French_Exit":
			Diag.CurrentNode = "French_first_time";
			DialogExit();
		break;

		case "abduction_challenge":
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "abduction_entry_options";
		break;

		case "abduction_entry_options":
			dialog.text = DLG_TEXT[71];
			if (CheckCharacterItem(PChar, "PrisonPass") || CheckCharacterItem(PChar, "FakePrisonPass"))
			{
				link.l1 = DLG_TEXT[72];
				link.l1.go = "abduction_check_pass";
			}
			link.l2 = DLG_TEXT[73];
			link.l2.go = "abduction_offer_bribe";
			link.l3 = DLG_TEXT[74];
			link.l3.go = "exit_try_again";
			link.l4 = DLG_TEXT[75];
			link.l4.go = "abduction_fight_guards";
		break;

		case "abduction_check_pass":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "French_Exit";
			if (CheckCharacterItem(PChar, "PrisonPass") || CalcCharacterSkill(pchar, SKILL_LEADERSHIP) + CalcCharacterSkill(pchar, SKILL_SNEAK) > 7)
			{
				if (!CheckCharacterItem(PChar, "PrisonPass") && CalcCharacterSkill(pchar, SKILL_LEADERSHIP) + CalcCharacterSkill(pchar, SKILL_SNEAK) <= 10)
				{
					PChar.quest.abduction_guard_status = "fakepass";
				}
				dialog.text = DLG_TEXT[76];
				link.l1 = DLG_TEXT[77];
				link.l1.go = "exit_pass_accepted";
			}
		break;

		case "abduction_offer_bribe":
			dialog.text = DLG_TEXT[80];
			if (makeint(pchar.money >= 5000))
			{
				link.l1 = DLG_TEXT[81];
				link.l1.go = "exit_bribe_accepted";
			}
			link.l2 = DLG_TEXT[82];
			link.l2.go = "exit_try_again";
		break;

		case "abduction_demand_second_bribe":
			dialog.text = DLG_TEXT[83];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "abduction_fight_guards";
			if (makeint(pchar.money >= 5000))
			{
				link.l2 = DLG_TEXT[85];
				link.l2.go = "exit_bribe_accepted";
			}
		break;

		case "abduction_demand_fine":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[84];
			link.l1.go = "abduction_fight_guards";
			if (makeint(pchar.money >= 5000))
			{
				link.l2 = DLG_TEXT[85];
				link.l2.go = "exit_bribe_accepted";
			}
		break;

		case "abduction_fight_guards":
			AddDialogExitQuest("abduction_fight_guards");
			Diag.CurrentNode = "French_first_time";
			DialogExit();
		break;

		case "abduction_exit_challenge":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "exit";
		break;

		case "abduction_apology":
			dialog.text = DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "abduction_come_along";
		break;

		case "abduction_come_along":
			dialog.text = DLG_TEXT[91];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "abduction_check_prisoner":
			dialog.text = DLG_TEXT[92];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "mona_attack_what_no_uniform":
			dialog.text = DLG_TEXT[93];
			link.l1 = DLG_TEXT[94] + GetMyFullName(CharacterFromID("French_Captain1")) + DLG_TEXT[95];
			link.l1.go = "mona_attack_get_back_into_uniform";
		break;

		case "mona_attack_get_back_into_uniform":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "mona_attack_ordered_to_flagship";
		break;

		case "mona_attack_who_are_they":
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "mona_attack_hang_them_all";
		break;

		case "mona_attack_hang_them_all":
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "mona_attack_ordered_to_flagship";
		break;

		case "mona_attack_are_you_captain":
			dialog.text = DLG_TEXT[98] + GetMyFullName(CharacterFromID("French_Captain1")) + "?";
			link.l1 = DLG_TEXT[99];
			link.l1.go = "mona_attack_ordered_to_flagship";
		break;

		case "mona_attack_ordered_to_flagship":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[105];
			link.l1.go = "mona_attack_ordered_to_flagship2";
		break;

		case "mona_attack_ordered_to_flagship2":
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107] + GetMySimpleName(CharacterFromID("French_Captain1")) + DLG_TEXT[108];
			link.l1.go = "exit";
		break;

		case "treachery_reinforcements":
			dialog.text = DLG_TEXT[109];
			link.l1 = DLG_TEXT[110];
			link.l1.go = "exit";
		break;

		case "treachery_reinforcements2":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			link.l1.go = "exit";
		break;

		case "treachery_survivor":
			PreProcessor_Add("person", XI_ConvertString(PChar.sex));
			dialog.text = DLG_TEXT[113];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "treachery_story_confirmed":
			dialog.text = DLG_TEXT[114];
			link.l1 = DLG_TEXT[115];
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, 5);
			link.l1.go = "exit";
		break;

		case "treachery_goto_governor":
			dialog.text = DLG_TEXT[116];
			link.l1 = DLG_TEXT[117];
			link.l1.go = "exit";
		break;

		case "hunt_guard_arrest":
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[138];
			link.l1.go = "exit_surrender";
			link.l2 = DLG_TEXT[139];
			link.l2.go = "exit_resist_arrest";
		break;

		case "hunt_taunt_guard":
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			link.l1.go = "hunt_taunt_guard2";
		break;

		case "hunt_taunt_guard2":
			dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "hunt_taunt_guard3";
		break;

		case "hunt_taunt_guard3":
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "hunt_taunt_guard4";
		break;

		case "hunt_taunt_guard4":
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "exit";
		break;

		case "hunt_flirt_guard":
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[126];
			link.l1.go = "hunt_flirt_guard2";
		break;

		case "hunt_flirt_guard2":
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "hunt_flirt_guard3";
		break;

		case "hunt_flirt_guard3":
			dialog.text = DLG_TEXT[129];
			link.l1 = DLG_TEXT[130];
			link.l1.go = "hunt_flirt_guard4";
		break;

		case "hunt_flirt_guard4":
			dialog.text = DLG_TEXT[131];
			link.l1 = DLG_TEXT[132];
			link.l1.go = "exit";
		break;

		case "hunt_teach_manners":
			dialog.text = DLG_TEXT[133];
			link.l1 = DLG_TEXT[134];
			link.l1.go = "exit";
		break;

		case "hunt_get_comfortable":
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[136];
			link.l1.go = "exit";
		break;

		case "hunt_fort_what_business":
			dialog.text = DLG_TEXT[140];
			link.l1 = DLG_TEXT[141];
			link.l1.go = "hunt_fort_authority";
		break;

		case "hunt_fort_authority":
			dialog.text = DLG_TEXT[142];
			if (CheckCharacterItem(PChar, "fake_fort_release"))
			{
				link.l1 = DLG_TEXT[144];
				link.l1.go = "hunt_fort_release";
			}
			link.l2 = DLG_TEXT[143];
			link.l2.go = "exit_hunt_fort_fight";
		break;

		case "hunt_fort_release":
			if (PChar.model == "Ardent_Fr" || PChar.model == "Ardent_FrF" || CheckQuestAttribute("hunt_document_type", "requisition"))
			{
				if (PChar.model == "Ardent_Fr" || PChar.model == "Ardent_FrF")
				{
					Preprocessor_Add("person", XI_ConvertString("man"));
					Preprocessor_Add("pronoun", XI_ConvertString("he"));
				}
				else
				{
					Preprocessor_Add("person", XI_ConvertString(PChar.sex));
					Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar)));
				}
				dialog.text = DLG_TEXT[145];
				link.l1 = DLG_TEXT[146];
				AddDialogExitQuest("hunt_fort_crew_released");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[147];
				link.l1 = DLG_TEXT[148];
				link.l1.go = "exit_hunt_fort_fight";
			}
		break;

		case "finale_port_royale_fort_battle_over":
			Preprocessor_Add("governor", GetMyFullName(CharacterFromID("John Clifford Brin")));
			dialog.text = DLG_TEXT[149] + GetMyFullName(CharacterFromID("Redmond Commander")) + DLG_TEXT[150];
			link.l1 = DLG_TEXT[151] + GetMyFullName(PChar) + DLG_TEXT[152];
			link.l1.go = "finale_french_no_problem";
		break;

		case "finale_french_no_problem":
			dialog.text = DLG_TEXT[153];
			link.l1 = DLG_TEXT[154];
			link.l1.go = "finale_offer_escort";
		break;

		case "finale_offer_escort":
			dialog.text = DLG_TEXT[155];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "finale_insist_escort";
		break;

		case "finale_insist_escort":
			dialog.text = DLG_TEXT[157];
			link.l1 = DLG_TEXT[158];
			link.l1.go = "exit";
		break;

		case "finale_report_victory_at_sea":
			dialog.text = DLG_TEXT[159];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "imperial_escort_arrest":
			dialog.text = DLG_TEXT[160] + GetMyFullName(PChar) + DLG_TEXT[161];
			link.l1 = DLG_TEXT[162];
			link.l1.go = "imperial_escort_arrest2";
		break;

		case "imperial_escort_arrest2":
			dialog.text = DLG_TEXT[163];
			link.l1 = DLG_TEXT[164];
			link.l1.go = "exit";
		break;

		case "imperial_escort_santiago_arrest":
			dialog.text = DLG_TEXT[165] + GetMyFullName(PChar) + DLG_TEXT[166] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[167];
			link.l1 = DLG_TEXT[168];
			link.l1.go = "exit";
		break;

		case "imperial_escort_santiago_arrest2":
			dialog.text = DLG_TEXT[169];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "imperial_escort_santiago_arrest3":
			dialog.text = DLG_TEXT[170];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "exit";
		break;

		case "imperial_escort_havana_arrest":
			dialog.text = DLG_TEXT[165] + GetMyFullName(PChar) + DLG_TEXT[166] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[172] + GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "exit";
		break;

		case "imperial_escort_outside_santiago_townhall":
			dialog.text = DLG_TEXT[175] + GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false) + DLG_TEXT[176];
			link.l1 = DLG_TEXT[177];
			link.l1.go = "exit";
		break;

		case "imperial_escort_after_santiago_townhall":
			dialog.text = DLG_TEXT[178] + GetMyFullName(CharacterFromID("Emiliano de Guzmбn")) + DLG_TEXT[179];
			link.l1 = DLG_TEXT[180] + GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[181];
			link.l1.go = "exit";
		break;

		case "imperial_escort_report_crime":
			dialog.text = DLG_TEXT[182];
			link.l1 = DLG_TEXT[183] + GetMyFullName(PChar) + DLG_TEXT[184];
			link.l1.go = "imperial_escort_is_that_the_spy";
		break;

		case "imperial_escort_is_that_the_spy":
			dialog.text = DLG_TEXT[185] + GetAddressForm(ADDR_CIVIL, SPAIN, chrsex(PChar)) + DLG_TEXT[186];
			link.l1 = DLG_TEXT[187] + GetMyFullName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[188] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[189];
			PChar.quest.imperial_escort.spy_arrester = NPChar.id;
			AddDialogExitQuest("imperial_escort_guard_arrests_spy");
			link.l1.go = "exit";
		break;

		case "imperial_escort_which_one_is_spy":
			dialog.text = DLG_TEXT[190] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[191];
			link.l1 = DLG_TEXT[192];
			link.l1.go = "exit";
		break;

		case "imperial_escort_which_one_is_spy2":
			dialog.text = "...";
			link.l1 = DLG_TEXT[193];
			link.l1.go = "exit";
		break;

		case "imperial_escort_spy_answer1":
			dialog.text = DLG_TEXT[194];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "imperial_escort_spy_answer2":
			dialog.text = DLG_TEXT[195];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "imperial_escort_spy_revealed":
			dialog.text = "";
			link.l1 = DLG_TEXT[196];
			link.l1.go = "imperial_escort_how_do_you_know";
		break;

		case "imperial_escort_how_do_you_know":
			dialog.text = DLG_TEXT[197];
			link.l1 = DLG_TEXT[198];
			link.l1.go = "imperial_escort_why_spy_confess";
		break;

		case "imperial_escort_why_spy_confess":
			dialog.text = DLG_TEXT[199];
			link.l1 = DLG_TEXT[200] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[201];
			link.l1.go = "exit";
		break;

		case "imperial_escort_spy_poisoned":
			dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[203];
			link.l1.go = "exit";
		break;


		case "exit_try_again":
			AddDialogExitQuest("abduction_reset_guards");
			Diag.CurrentNode = "abduction_entry_options";
			DialogExit();
		break;

		case "exit_pass_accepted":
			AddDialogExitQuest("abduction_open_barracks_door");
			Diag.CurrentNode = "French_first_time";
			DialogExit();
		break;

		case "exit_bribe_accepted":
			PChar.quest.abduction_guard_status = "bribed";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, -5000);
			AddMoneyToCharacter(NPChar, 5000);
			AddDialogExitQuest("abduction_open_barracks_door");
			Diag.CurrentNode = "French_first_time";
			DialogExit();
		break;

		case "exit_surrender":
			AddDialogExitQuest("to_guadeloupe_prison1");
			Diag.CurrentNode = "French_first_time";
			DialogExit();
		break;

		case "exit_resist_arrest":
			AddDialogExitQuest("hunt_resist_arrest");
			Diag.CurrentNode = "French_first_time";
			DialogExit();
		break;

		case "exit_hunt_fort_fight":
			AddDialogExitQuest("hunt_fort_fight");
			Diag.CurrentNode = "French_first_time";
			DialogExit();
		break;
	}
}