//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	int n;
	string gov_kid, merch_kid;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar = GetMainCharacter();

	if (PChar.sex == "man")
	{
		gov_kid = "daughter";
		merch_kid = "son";
	}
	else
	{
		gov_kid = "son";
		merch_kid = "daughter";
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

			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "intruder":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "threat";
			if (checkquestattribute("ardent_kidnap.wedding", "sad"))
			{
				link.l2 = DLG_TEXT[8];
				link.l2.go = "offer";
			}
		break;

		case "threat":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "threat2";
		break;

		case "threat2":
			PChar.quest.ardent_kidnap.status = "hostile";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
		break;

		case "offer":
			PChar.quest.ardent_kidnap.status = "cooperate";
			dialog.text = DLG_TEXT[9] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[10];
			link.l1 = DLG_TEXT[11] + GetMyName(characterFromID(PChar.quest.villain)) + ".";
			link.l1.go = "offer2";
		break;

		case "offer2":
			dialog.text = DLG_TEXT[12] + GetMyName(characterFromID("Grigorio Formoselle")) + "!";
			link.l1 = DLG_TEXT[13];
			link.l1.go = "offer3";
		break;

		case "offer3":
			dialog.text = DLG_TEXT[14] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
		break;

		case "guard_help":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			AddDialogExitQuest("kidnap_battle");
			link.l1.go = "exit";
		break;

		case "answer_guard":
			if (GetDayTime() == DAY_TIME_NIGHT)
			{
				dialog.text = DLG_TEXT[19];
				link.l1 = DLG_TEXT[20];
				AddDialogExitQuest("kidnap_cooperate");
			}
			else
			{
				dialog.text = DLG_TEXT[94];
				link.l1 = DLG_TEXT[95];
				AddDialogExitQuest("kidnap_cooperate_day");
			}
			link.l1.go = "exit";
		break;

		case "apologise":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
		break;

		case "what_next":
			dialog.text = DLG_TEXT[23];
			if (checkquestattribute("ardent_kidnap.status", "cooperate"))
			{
				link.l1 = DLG_TEXT[24];
				link.l1.go = "kidnap_guest";
				link.l2 = DLG_TEXT[25];
				link.l2.go = "betrayed";
			}
			else
			{
				link.l1 = DLG_TEXT[25];
				AddDialogExitQuest("kidnap_prisoner");
				link.l1.go = "exit";
			}
		break;

		case "betrayed":
			if (PChar.quest.alignment == "good") ChangeCharacterReputation(pchar, -2);
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			AddDialogExitQuest("kidnap_prisoner");
			link.l1.go = "exit";
		break;

		case "kidnap_guest":
			AddDialogExitQuest("kidnap_guest");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "not_mistreated":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
		break;

		case "reached_a_decision":
			n = makeint(PChar.quest.ardent_kidnap.voyage_stage);
			dialog.text = DLG_TEXT[30];
			link.l3 = DLG_TEXT[31];		
			link.l3.go = "release";
			if (n >= 1)
			{
				link.l1 = DLG_TEXT[32];
				link.l1.go = "officer";
			}
			if (PChar.quest.alignment == "evil")
			{
				link.l2 = DLG_TEXT[25];
				link.l2.go = "betrayed";
			}
			if (PChar.quest.alignment == "good" && n >= 1 && sti(PChar.married) == MR_SINGLE)
			{
				link.l2 = DLG_TEXT[33];
				link.l2.go = "marry";
			}
			link.l4 = DLG_TEXT[34];
			link.l4.go = "exit_cabin";
		break;

		case "exit_cabin":
			Diag.CurrentNode = "reached_a_decision";
			DialogExit();
		break;

		case "release":
			dialog.text = DLG_TEXT[35] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "release_confirmed";
			link.l2 = DLG_TEXT[38];
			link.l2.go = "exit_cabin";
		break;

		case "release_confirmed":
			AddDialogExitQuest("release_guest");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "officer":
			if(GetRMRelation(PChar, SPAIN) > REL_WAR)
			{
				dialog.text = DLG_TEXT[39];
				link.l1 = DLG_TEXT[40];
				link.l1.go = "officer2";
			}
			else
			{
				dialog.text = DLG_TEXT[176];
				link.l1 = DLG_TEXT[177];
				link.l1.go = "exit_cabin";
			}
		break;

		case "officer2":
			if (PChar.sex == "man") dialog.text = DLG_TEXT[41] + gov_kid + DLG_TEXT[42] + DLG_TEXT[43] + DLG_TEXT[45];
			else dialog.text = DLG_TEXT[41] + gov_kid + DLG_TEXT[42] + DLG_TEXT[44] + DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "first_mate";
			link.l2 = DLG_TEXT[47];
			link.l2.go = "doctor";
			link.l3 = DLG_TEXT[48];
			link.l3.go = "carpenter";
		break;

		case "first_mate":
			AddDialogExitQuest("recruit_first_mate");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "doctor":
			AddDialogExitQuest("recruit_doctor");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "carpenter":
			AddDialogExitQuest("recruit_carpenter");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "marry":
			n = makeint(PChar.quest.ardent_kidnap.voyage_stage);
			if (n<2 && !CheckAttribute(PChar,"quest.ardent_kidnap.bored"))
			{
				dialog.text = DLG_TEXT[49] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[50];
				link.l1 = DLG_TEXT[51];
				link.l1.go = "exit_cabin";
			}
			else
			{
				if(!CheckQuestAttribute("marriage_status", "proposed") && !CheckQuestAttribute("marriage_status", "looking_for_love") && !CheckQuestAttribute("marriage_status", "ring_chosen"))
				{
					PChar.quest.marriage_status = "proposed";
					SetQuestHeader("Marriage");
					Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
					AddQuestRecord("Marriage", 1);
					Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
					AddQuestRecord("Kidnap", 27);
					Preprocessor_Remove("romance");
					CloseQuestHeader("Kidnap");
					DeleteQuestAttribute("ardent_kidnap");
				}
				dialog.text = DLG_TEXT[139];
				link.l1 = DLG_TEXT[140];
				link.l1.go = "exit_marriage_proposal_accepted";
				if(GetRMRelation(PChar, SPAIN) > REL_WAR)
				{
					if(!CheckAttribute(characterFromID(PChar.quest.romance),"quest.love_me") && !CheckQuestAttribute("marriage_status", "ring_chosen"))
					{
						if(!CheckQuestAttribute("marriage_status", "looking_for_love"))
						{
							PChar.quest.marriage_status = "looking_for_love";
							Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
							if(PChar.sex == "man") AddQuestRecord("Marriage", 4);
							else AddQuestRecord("Marriage", 5);
							Preprocessor_Remove("romance");
						}
						dialog.text = DLG_TEXT[117];
						if (CheckAttribute(PChar,"quest.ardent_kidnap.bored")) link.l1 = DLG_TEXT[123];
						else link.l1 = DLG_TEXT[120] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[121];
						link.l1.go = "marry_love_logic";
						if (CalcCharacterSkill(PChar, SKILL_LEADERSHIP) >= 5)
						{
							link.l2 = DLG_TEXT[118];
							link.l2.go = "marry_love_flattery";
						}
						if(PChar.sex == "man")
						{
							if (CheckCharacterItem(PChar, "jewelry9") || CheckCharacterItem(PChar, "jewelry13") || CheckCharacterItem(PChar, "jewelry14") || CheckCharacterItem(PChar, "jewelry15") || CheckCharacterItem(PChar, "jewelry16"))
							{
								link.l3 = DLG_TEXT[125];
								link.l3.go = "marry_give_jewellery";
							}
						}
						else
						{
							if (CheckCharacterItem(PChar, "blade4+3") || CheckCharacterItem(PChar, "blade47+3") || CheckCharacterItem(PChar, "blade16+3") || CheckCharacterItem(PChar, "blade44+3"))
							{
								link.l3 = DLG_TEXT[125];
								link.l3.go = "marry_give_weapon";
							}
						}
					}
					if(CheckAttribute(characterFromID(PChar.quest.romance),"quest.love_me") && !CheckQuestAttribute("marriage_status", "ring_chosen"))
					{
						if(!CheckQuestAttribute("marriage_status", "need_ring") && !CheckQuestAttribute("marriage_status", "ring_chosen"))
						{
							PChar.quest.marriage_status = "need_ring";
							Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
							AddQuestRecord("Marriage", 6);
							Preprocessor_Remove("romance");
						}
						dialog.text = DLG_TEXT[129];
						link.l1 = DLG_TEXT[156];
						link.l1.go = "exit_options_open";
						if (CheckCharacterItem(PChar, "jewelry8")) // Bronze ring
						{
							link.l2 = DLG_TEXT[130];
							link.l2.go = "marry_offer_bronze_ring";
						}
						if (CheckCharacterItem(PChar, "jewelry6")) // Silver ring
						{
							link.l3 = DLG_TEXT[131];
							link.l3.go = "marry_offer_silver_ring";
						}
						if (CheckCharacterItem(PChar, "jewelry7")) // Gold emerald ring
						{
							link.l4 = DLG_TEXT[132];
							link.l4.go = "marry_offer_gold_ring";
						}
						if (CheckCharacterItem(PChar, "jewelry10")) // Gold sapphire ring
						{
							link.l5 = DLG_TEXT[133];
							link.l5.go = "marry_offer_sapphire_ring";
						}
					}
				}
				if (GetRMRelation(PChar, SPAIN) <= REL_WAR)
				{
					if(!CheckQuestAttribute("marriage_status", "make_peace_spain"))
					{
						PChar.quest.marriage_status = "make_peace_spain";
						Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
						AddQuestRecord("Marriage", 3);
						Preprocessor_Remove("romance");
					}
					dialog.text = DLG_TEXT[114];
					link.l1 = DLG_TEXT[116];
					link.l1.go = "exit_make_peace_spain";
					link.l2 = DLG_TEXT[115];
					link.l2.go = "forget_it";
//					link.l2.go = "exit_options_open";
				}
			}
		break;

		case "marry_love_logic":
			if (CheckAttribute(PChar,"quest.ardent_kidnap.bored"))
			{
				NPChar.quest.love_me = true;
				dialog.text = DLG_TEXT[124];
				link.l1 = DLG_TEXT[157];
				link.l1.go = "marry";
			}
			else
			{
				dialog.text = DLG_TEXT[122];
				link.l1 = DLG_TEXT[160];
				link.l1.go = "exit_options_open";
				link.l2 = DLG_TEXT[172];
				link.l2.go = "exit_forget_it";
			}
		break;

		case "marry_love_flattery":
			NPChar.quest.love_me = true;
			dialog.text = DLG_TEXT[119];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "marry";
		break;

		case "marry_give_jewellery":
			dialog.text = DLG_TEXT[161];
			if (CheckCharacterItem(PChar, "jewelry9"))
			{
				link.l1 = DLG_TEXT[162];
				link.l1.go = "marry_gift_cross";
			}
			if (CheckCharacterItem(PChar, "jewelry13"))
			{
				link.l2 = DLG_TEXT[163];
				link.l2.go = "marry_gift_silver_brooch";
			}
			if (CheckCharacterItem(PChar, "jewelry14"))
			{
				link.l3 = DLG_TEXT[164];
				link.l3.go = "marry_gift_gold_brooch";
			}
			if (CheckCharacterItem(PChar, "jewelry15"))
			{
				link.l4 = DLG_TEXT[165];
				link.l4.go = "marry_gift_pendant";
			}
			if (CheckCharacterItem(PChar, "jewelry16"))
			{
				link.l5 = DLG_TEXT[166];
				link.l5.go = "marry_gift_necklace";
			}
		break;

		case "marry_give_weapon":
			dialog.text = DLG_TEXT[161];
			if (CheckCharacterItem(PChar, "blade4+3"))
			{
				link.l1 = DLG_TEXT[167];
				link.l1.go = "marry_gift_rejected";
			}
			if (CheckCharacterItem(PChar, "blade47+3"))
			{
				link.l2 = DLG_TEXT[168];
				link.l2.go = "marry_gift_light_tizona";
			}
			if (CheckCharacterItem(PChar, "blade16+3"))
			{
				link.l3 = DLG_TEXT[169];
				link.l3.go = "marry_gift_tizona";
			}
			if (CheckCharacterItem(PChar, "blade44+3"))
			{
				link.l4 = DLG_TEXT[170];
				link.l4.go = "marry_gift_cup_hilt";
			}
		break;

		case "marry_gift_marry_gift_cross":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(Pchar, "jewelry9");
			GiveItem2Character(characterFromID(PChar.quest.romance), "jewelry9");
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "marry";
		break;

		case "marry_gift_silver_brooch":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(Pchar, "jewelry13");
			GiveItem2Character(characterFromID(PChar.quest.romance), "jewelry13");
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "marry";
		break;

		case "marry_gift_gold_brooch":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(Pchar, "jewelry14");
			GiveItem2Character(characterFromID(PChar.quest.romance), "jewelry14");
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "marry";
		break;

		case "marry_gift_pendant":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(Pchar, "jewelry15");
			GiveItem2Character(characterFromID(PChar.quest.romance), "jewelry15");
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "marry";
		break;

		case "marry_gift_necklace":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(Pchar, "jewelry16");
			GiveItem2Character(characterFromID(PChar.quest.romance), "jewelry16");
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "marry";
		break;

		case "marry_gift_light_tizona":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(Pchar, "blade47+3");
			GiveItem2Character(characterFromID(PChar.quest.romance), "blade47+3");
			if(IsEquipCharacterByItem(PChar, "blade47+3")) EquipCharacterByItem(PChar, "bladeX4");
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "marry";
		break;

		case "marry_gift_tizona":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(Pchar, "blade16+3");
			GiveItem2Character(characterFromID(PChar.quest.romance), "blade16+3");
			if(IsEquipCharacterByItem(PChar, "blade16+3")) EquipCharacterByItem(PChar, "bladeX4");
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "marry";
		break;

		case "marry_gift_cup_hilt":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(Pchar, "blade44+3");
			GiveItem2Character(characterFromID(PChar.quest.romance), "blade44+3");
			if(IsEquipCharacterByItem(PChar, "blade44+3")) EquipCharacterByItem(PChar, "bladeX4");
			dialog.text = DLG_TEXT[127];
			link.l1 = DLG_TEXT[157];
			link.l1.go = "marry";
		break;

		case "marry_gift_rejected":
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "exit_options_open";
			link.l2 = DLG_TEXT[172];
			link.l2.go = "forget_it";
		break;

		case "marry_offer_bronze_ring":
			dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "exit_options_open";
			link.l2 = DLG_TEXT[172];
			link.l2.go = "forget_it";
		break;

		case "marry_offer_silver_ring":
			dialog.text = DLG_TEXT[134] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[135];
			link.l1 = DLG_TEXT[171];
			link.l1.go = "exit_options_open";
			link.l2 = DLG_TEXT[172];
			link.l2.go = "forget_it";
		break;

		case "marry_offer_gold_ring":
			TakeItemFromCharacter(Pchar, "jewelry7");
			GiveItem2Character(characterFromID(PChar.quest.romance), "jewelry7_q");
			PChar.quest.wedding_ring = "jewelry7_q";
			PChar.quest.marriage_status = "ring_chosen";
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "marry";
		break;

		case "marry_offer_sapphire_ring":
			TakeItemFromCharacter(Pchar, "jewelry10");
			GiveItem2Character(characterFromID(PChar.quest.romance), "jewelry10_q");
			PChar.quest.wedding_ring = "jewelry10_q";
			PChar.quest.marriage_status = "ring_chosen";
			dialog.text = DLG_TEXT[138];
			link.l1 = DLG_TEXT[128];
			link.l1.go = "marry";
		break;

		case "marry_try_again":
			switch(PChar.quest.marriage_status)
			{
				case "make_peace_spain":
					dialog.text = DLG_TEXT[63] + GetMyFirstNames(PChar, false) + ". " + DLG_TEXT[154];
					if(GetRMRelation(Pchar, SPAIN) > REL_WAR)
					{
						link.l1 = DLG_TEXT[155] + DLG_TEXT[128];
						link.l1.go = "marry";
					}
					else
					{
						link.l1 = DLG_TEXT[156];
						link.l1.go = "exit_make_peace_spain";
						link.l2 = DLG_TEXT[115];
						link.l2.go = "forget_it";
					}
				break;

				dialog.text = DLG_TEXT[63] + GetMyName(PChar) + ".";	// Only drop to here if no specific marriage_status identified
				link.l1 = DLG_TEXT[158];
				link.l1.go = "officer";
				if(sti(PChar.married) == MR_SINGLE)
				{
					link.l2 = DLG_TEXT[159];
					link.l2.go = "marry";
				}
				link.l3 = DLG_TEXT[1];
				link.l3.go = "exit_options_open";
			}
		break;

		case "options":
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			link.l1 = DLG_TEXT[158];
			link.l1.go = "officer";
			if(sti(PChar.married) == MR_SINGLE)
			{
				link.l2 = DLG_TEXT[159];
				link.l2.go = "marry";
			}
			link.l3 = DLG_TEXT[1];
			link.l3.go = "exit_options_open";
		break;

		case "letter":
			dialog.text = DLG_TEXT[52] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "exit_letter";
		break;

		case "exit_letter":
			Diag.CurrentNode = "letter_done";
			DialogExit();
		break;

		case "letter_done":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			AddDialogExitQuest("deliver_ExplainLetter");
			link.l1.go = "exit_cabin";
		break;

		case "visit_father":
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[59];
			link.l1.go = "exit";
		break;

		case "just_released":
			dialog.text = DLG_TEXT[60] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
		break;

		case "bored_in_san_juan":
			PChar.quest.ardent_kidnap.bored = "waiting";
			dialog.text = DLG_TEXT[63] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[64];
			link.l1.go = "bored_in_san_juan2";
		break;

		case "bored_in_san_juan2":
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "officer";
			link.l2 = DLG_TEXT[67] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[68];
			link.l2.go = "marry";
			link.l3 = DLG_TEXT[69];
			link.l3.go = "exit";
		break;

		case "second_CourtingLetter_delivered":
			TakeItemFromCharacter(Pchar, "CourtingLetter");
			dialog.text = DLG_TEXT[70];
			link.l1 = DLG_TEXT[71] + GetMyFullName(PChar) + DLG_TEXT[72];
			link.l1.go = "second_CourtingLetter_delivered2";
		break;

		case "second_CourtingLetter_delivered2":
			PChar.quest.ardent_kidnap.wedding = "sad";
			if (PChar.sex == "man") Preprocessor_Add("pronoun", "He");
			else Preprocessor_Add("pronoun", "She");
			dialog.text = DLG_TEXT[73] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "letter_offer_help";
			link.l2 = DLG_TEXT[76];
			link.l2.go = "letter_kidnap";
			link.l3 = DLG_TEXT[78];
			link.l3.go = "letter_courier";
		break;

		case "letter_courier":
			dialog.text = DLG_TEXT[79];
			link.l1 = DLG_TEXT[80] + GetMyFullName(characterFromID(PChar.quest.villain)) + DLG_TEXT[81];
			link.l1.go = "exit";
			AddDialogExitQuest("second_CourtingLetter_return_with_answer");
		break;

		case "letter_kidnap":
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "letter_kidnap2";
			link.l2 = DLG_TEXT[92];
			link.l2.go = "letter_offer_help2";
		break;

		case "letter_kidnap2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			PChar.quest.ardent_kidnap.status = "hostile";
			AddDialogExitQuest("second_CourtingLetter_kidnap");
		break;

		case "letter_offer_help":
			dialog.text = DLG_TEXT[9] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[10];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "letter_offer_help2";
			link.l2 = DLG_TEXT[93];
			link.l2.go = "letter_kidnap";
		break;

		case "letter_offer_help2":
			PChar.quest.ardent_kidnap.status = "cooperate";
			dialog.text = DLG_TEXT[14] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "letter_fake_kidnap";
			if (CheckCharacterItem(PChar, "pistolbow") && CheckCharacterItem(PChar, "bladearrows"))
			{
				link.l2 = DLG_TEXT[84];
				link.l2.go = "letter_bow";
			}
		break;

		case "letter_fake_kidnap":
			PChar.quest.ardent_kidnap.status = "cooperate";
			AddDialogExitQuest("second_CourtingLetter_kidnap");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "letter_bow":
			dialog.text = DLG_TEXT[85];
			link.l1 = DLG_TEXT[86];
			link.l1.go = "letter_bow2";
		break;

		case "letter_bow2":
			dialog.text = DLG_TEXT[87];
			link.l1 = DLG_TEXT[88];
			link.l1.go = "letter_bow3";
		break;

		case "letter_bow3":
			dialog.text = DLG_TEXT[89] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "exit";
			AddDialogExitQuest("second_CourtingLetter_bow_escape");
		break;

		case "run_for_ship":
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "exit";
		break;

		case "bow_rescue_climbed_in":
			dialog.text = DLG_TEXT[98] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + ".";
			link.l1 = DLG_TEXT[99];
			link.l1.go = "bow_rescue_tie_rope";
		break;

		case "bow_rescue_tie_rope":
			dialog.text = DLG_TEXT[100];
			link.l1 = DLG_TEXT[101];
			link.l1.go = "exit";
		break;

		case "bow_rescue_outside_residence":
			dialog.text = DLG_TEXT[102];
			link.l1 = DLG_TEXT[103];
			link.l1.go = "exit";
		break;

		case "just_a_cabin_boy":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
		break;

		case "naughty_guard":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
		break;

		case "board_before_he_remembers":
			dialog.text = DLG_TEXT[106];
			link.l1 = DLG_TEXT[107];
			link.l1.go = "how_i_know_guard";
		break;

		case "how_i_know_guard":
			dialog.text = DLG_TEXT[108];
			link.l1 = DLG_TEXT[109];
			link.l1.go = "guards_problem";
		break;

		case "guards_problem":
			dialog.text = DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "exit";
		break;

		case "wedding_night":
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			AddDialogExitQuest("get_lost_player");
			link.l1.go = "exit";
		break;

		case "explain_absence":
			dialog.text = DLG_TEXT[141] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[142] + GetMySimpleName(PChar) + DLG_TEXT[143] + GetMySimpleName(characterFromID(PChar.quest.villain)) + ".";
			link.l1 = DLG_TEXT[144];
			link.l1.go = "exit";
		break;

		case "marriage_proposed":
			dialog.text = DLG_TEXT[145] + GetMyFirstNames(PChar, false) + DLG_TEXT[146];
			link.l1 = DLG_TEXT[147];
			link.l1.go = "exit";
		break;

		case "broken-hearted":
			dialog.text = DLG_TEXT[148];
			link.l1 = DLG_TEXT[149];
			Diag.TempNode = "dont_talk_to_me";
			link.l1.go = "exit";
		break;

		case "dont_talk_to_me":
			dialog.text = DLG_TEXT[152];
			link.l1 = DLG_TEXT[153];
			link.l1.go = "exit";
			Diag.TempNode = "dont_talk_to_me";
		break;

		case "marriage_accepted":
			dialog.text = DLG_TEXT[150];
			link.l1 = DLG_TEXT[151];
			link.l1.go = "exit";
		break;

		case "forget_it":
			if(Characters[GetMainCharacterIndex()].location == "Tutorial_Deck") dialog.text = DLG_TEXT[174];
			else dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[175];
			link.l1.go = "exit_forget_it";
		break;

		case "ask_favour":
			if(CheckAttribute(PChar,"quest.assassination")) dialog.text = DLG_TEXT[178] + GetMyName(PChar) + DLG_TEXT[179];
			else dialog.text = DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "convoy_request";
		break;

		case "convoy_request":
			if(PChar.sex == "man")
			{
				PreProcessor_Add("pronoun", "he");
				PreProcessor_Add("pronoun2", "him");
			}
			else
			{
				PreProcessor_Add("pronoun", "she");
				PreProcessor_Add("pronoun2", "her");
			}
			if(CheckAttribute(PChar,"quest.assassination")) dialog.text = DLG_TEXT[182] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[183];
			else dialog.text = DLG_TEXT[184] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[185];
			dialog.text = dialog.text + DLG_TEXT[186] + GetMyName(PChar) + DLG_TEXT[187];
			link.l1 = DLG_TEXT[188];
			link.l1.go = "convoy_thought_about_it";
		break;

		case "convoy_thought_about_it":
			dialog.text = DLG_TEXT[189];
			if (PChar.sex == "man") PreProcessor_Add("pronoun", "he");
			else PreProcessor_Add("pronoun", "she");
			link.l1 = DLG_TEXT[190] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[191];
			link.l1.go = "convoy_summarised";
		break;

		case "convoy_summarised":
			SetQuestHeader("Convoy Strike");
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			Preprocessor_AddQuestData("romance", GetMyName(characterFromID(PChar.quest.romance)));
			if (PChar.sex == "man")
			{
				Preprocessor_AddQuestData("pronoun1", "he");
				Preprocessor_AddQuestData("pronoun2", "her");
			}
			else
			{
				Preprocessor_AddQuestData("pronoun1", "she");
				Preprocessor_AddQuestData("pronoun2", "him");
			}
			AddQuestRecord("Convoy Strike", 1);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("pronoun1");
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			dialog.text = DLG_TEXT[192];
			if(PChar.married == MR_MARRIED && PChar.married.id == characters[getCharacterIndex(PChar.quest.romance)].id) link.l1 = DLG_TEXT[193];
			else link.l1 = DLG_TEXT[194];
			link.l1.go = "exit";
		break;

		case "convoy_officer":
			dialog.text = DLG_TEXT[195];
			link.l1 = DLG_TEXT[196] + DLG_TEXT[40];
			link.l1.go = "officer2";
		break;

		case "convoy_how_take_convoy":
			dialog.text = DLG_TEXT[197] + GetMyName(PChar) + "?";
			if (CheckAttribute(PChar,"quest.assassination"))
			{
				link.l1 = DLG_TEXT[200] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[201];
				link.l1.go = "convoy_interested_prepare";
			}
			else
			{
				if (PChar.sex == "man") PreProcessor_Add("spouse", "wife");
				else PreProcessor_Add("spouse", "husband");
				link.l1 = DLG_TEXT[198] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[199];
				link.l1.go = "exit";
			}
		break;

		case "convoy_interested_prepare":
			dialog.text = DLG_TEXT[202];
			link.l1 = DLG_TEXT[203];
//			link.l1.go = "convoy_choose_officer_first_time";
			link.l1.go = "exit";
		break;

		case "convoy_recognised":
			dialog.text = DLG_TEXT[204];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_recognised2":
			dialog.text = DLG_TEXT[205];
			link.l1 = DLG_TEXT[206];
			link.l1.go = "convoy_recognised3";
		break;

		case "convoy_recognised3":
			dialog.text = DLG_TEXT[207];
			link.l1 = DLG_TEXT[208];
			link.l1.go = "convoy_recognised4";
		break;

		case "convoy_recognised4":
			dialog.text = DLG_TEXT[209] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[210];
			link.l1 = DLG_TEXT[211];
			link.l1.go = "convoy_recognised5";
		break;

		case "convoy_recognised3":
			dialog.text = DLG_TEXT[212];
			link.l1 = DLG_TEXT[200] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[201];
			link.l1.go = "convoy_interested_prepare";
		break;

		case "convoy_be_quiet":
			dialog.text = DLG_TEXT[213];
			link.l1 = DLG_TEXT[214];
			link.l1.go = "convoy_negotiate";
		break;

		case "convoy_negotiate":
			dialog.text = DLG_TEXT[215] + Characters[GetCharacterIndex("Convoy_Captain1")].Ship.Name + DLG_TEXT[216] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[217] + GetMyFullName(characterFromID("Javier Balboa")) + DLG_TEXT[218];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_show_letter":
			dialog.text = DLG_TEXT[219];
			link.l1 = DLG_TEXT[220];
			link.l1.go = "exit";
		break;

		case "convoy_choose_officer_first_time":
			dialog.text = DLG_TEXT[223];
			if(GetOfficersIndex(Pchar, 1) != -1)
			{
				link.l1 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 1)]) + ".";
				link.l1.go = "convoy_choose_officer1";
			}
			if(GetOfficersIndex(Pchar, 2) != -1)
			{
				link.l2 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 2)]) + ".";
				link.l2.go = "convoy_choose_officer2";
			}
			if(GetOfficersIndex(Pchar, 3) != -1)
			{
				link.l3 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 3)]) + ".";
				link.l3.go = "convoy_choose_officer3";
			}
			link.l4 = DLG_TEXT[224];
			link.l4.go = "exit_not_chosen_officer";
		break;

		case "convoy_officer_try_again":
			dialog.text = DLG_TEXT[227];
			if(GetOfficersIndex(Pchar, 1) != -1)
			{
				link.l1 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 1)]) + ".";
				link.l1.go = "convoy_choose_officer1";
			}
			if(GetOfficersIndex(Pchar, 2) != -1)
			{
				link.l2 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 2)]) + ".";
				link.l2.go = "convoy_choose_officer2";
			}
			if(GetOfficersIndex(Pchar, 3) != -1)
			{
				link.l3 = GetMySimpleName(characters[GetOfficersIndex(Pchar, 3)]) + ".";
				link.l3.go = "convoy_choose_officer3";
			}
			link.l4 = DLG_TEXT[224];
			link.l4.go = "exit_not_chosen_officer";
		break;

		case "convoy_choose_officer1":
			if (GetOfficersIndex(Pchar, 1) == GetCharacterIndex(PChar.quest.romance))
			{
				dialog.text = DLG_TEXT[225];
				link.l1 = DLG_TEXT[226];
				link.l1.go = "convoy_officer_try_again";
			}
			else
			{
				PChar.quest.convoy_officer = characters[GetOfficersIndex(Pchar, 1)].id;
				AddDialogExitQuest("convoy_final_preparations2");
				DialogExit();
				Diag.CurrentNode = Diag.TempNode;
			}
		break;

		case "convoy_choose_officer2":
			if (GetOfficersIndex(Pchar, 2) == GetCharacterIndex(PChar.quest.romance))
			{
				dialog.text = DLG_TEXT[225];
				link.l1 = DLG_TEXT[226];
				link.l1.go = "convoy_officer_try_again";
			}
			else
			{
				PChar.quest.convoy_officer = characters[GetOfficersIndex(Pchar, 2)].id;
				AddDialogExitQuest("convoy_final_preparations2");
				DialogExit();
				Diag.CurrentNode = Diag.TempNode;
			}
		break;

		case "convoy_choose_officer3":
			if (GetOfficersIndex(Pchar, 3) == GetCharacterIndex(PChar.quest.romance))
			{
				dialog.text = DLG_TEXT[225];
				link.l1 = DLG_TEXT[226];
				link.l1.go = "convoy_officer_try_again";
			}
			else
			{
				PChar.quest.convoy_officer = characters[GetOfficersIndex(Pchar, 3)].id;
				AddDialogExitQuest("convoy_final_preparations2");
				DialogExit();
				Diag.CurrentNode = Diag.TempNode;
			}
		break;

		case "convoy_aboard_ship":
			dialog.text = DLG_TEXT[221];
			link.l1 = DLG_TEXT[222];
			AddDialogExitQuest("convoy_romance_removes_cloak");
			link.l1.go = "exit";
		break;

		case "convoy_dispose_ships":
			dialog.text = DLG_TEXT[228];
			link.l1 = DLG_TEXT[229];
			link.l1.go = "exit";
		break;

		case "convoy_dispose_ships2":
			dialog.text = DLG_TEXT[230] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[231];
			link.l1.go = "exit";
		break;

		case "convoy_after_governor":
			dialog.text = DLG_TEXT[232];
			link.l1 = DLG_TEXT[233];
			link.l1.go = "convoy_you_failed";
		break;

		case "convoy_you_failed":
			dialog.text = DLG_TEXT[234];
			link.l1 = DLG_TEXT[241];
			link.l1.go = "convoy_wrote_letter";
			if (PChar.quest.alignment == "good")
			{
				dialog.text = DLG_TEXT[234] + DLG_TEXT[235];
				link.l1 = DLG_TEXT[236];
				link.l1.go = "convoy_funny";
			}
		break;

		case "convoy_funny":
			dialog.text = DLG_TEXT[237];
			link.l1 = DLG_TEXT[238];
			link.l1.go = "convoy_if_governor_could_see_us";
		break;

		case "convoy_if_governor_could_see_us":
			dialog.text = DLG_TEXT[239];
			link.l1 = DLG_TEXT[240];
			link.l1.go = "convoy_wrote_letter";
		break;

		case "convoy_wrote_letter":
			dialog.text = DLG_TEXT[242];
			link.l1 = DLG_TEXT[243];
			link.l1.go = "exit";
		break;

		case "convoy_propose_trade":
			PreProcessor_Add("dutch_gov", GetMyLastName(characterFromID("Hans Kloss")));
			PreProcessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[244];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_ask_to_take_ship":
			PreProcessor_Add("ship", Characters[GetCharacterIndex("Javier Balboa")].Ship.Name);
			PreProcessor_Add("dutch_gov", GetMyLastName(characterFromID("Hans Kloss")));
			dialog.text = DLG_TEXT[245];
			link.l1 = DLG_TEXT[246];
			link.l1.go = "convoy_confident";
		break;

		case "convoy_confident":
			dialog.text = DLG_TEXT[247];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_free_slot":
			PreProcessor_Add("ship", Characters[GetCharacterIndex("Javier Balboa")].Ship.Name);
			dialog.text = DLG_TEXT[248];
			link.l1 = DLG_TEXT[249];
			link.l1.go = "exit";
		break;

		case "convoy_free_slot2":
			dialog.text = DLG_TEXT[250] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[251];
			link.l1.go = "exit";
		break;

		case "convoy_interrupt_recognition":
			dialog.text = GetMyFullName(PChar) + DLG_TEXT[252];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_give_trade_letter":
			dialog.text = DLG_TEXT[253];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_flattery":
			dialog.text = DLG_TEXT[254];
			if (PChar.quest.alignment == "good") link.l1 = DLG_TEXT[255];
			else link.l1 = DLG_TEXT[256];
			link.l1.go = "exit";
		break;

		case "want_silk":
			dialog.text = DLG_TEXT[257];
			link.l1 = DLG_TEXT[258];
			link.l1.go = "silk_approved";
			link.l2 = DLG_TEXT[259];
			link.l2.go = "exit_silk_rejected";
		break;

		case "silk_approved":
			dialog.text = DLG_TEXT[260];
			link.l1 = DLG_TEXT[261];
			link.l1.go = "exit_silk_approved";
		break;

		case "new_clothes":
			dialog.text = DLG_TEXT[262];
			link.l1 = DLG_TEXT[263];
			link.l1.go = "exit";
		break;

		case "exit_make_peace_spain":
			Diag.CurrentNode = "marry_try_again";
			DialogExit();
		break;

		case "exit_options_open":
			Diag.CurrentNode = "options";
			DialogExit();
		break;

		case "exit_forget_it":
			Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
			AddQuestRecord("Marriage", 2);
			Preprocessor_Remove("romance");
			CloseQuestHeader("Marriage");
			Diag.CurrentNode = "dont_talk_to_me";
			AddDialogExitQuest("forget_marriage");
			DialogExit();
		break;

		case "exit_marriage_proposal_accepted":
			Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
			AddQuestRecord("Marriage", 7);
			Preprocessor_Remove("romance");
			AddDialogExitQuest("marriage_proposal_accepted");
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "exit_not_chosen_officer":
			if(OFFICER_MAX <= 4) logit("Hint: To make an officer available to command your ship, assign that officer to one of the shore party slots.");
			else logit("Hint: To make an officer available to command your ship, assign that officer to one of the first three shore party slots.");
			PChar.quest.convoy.officer_status = "need_officer";
			AddDialogExitQuest("convoy_romance_waits");
			Diag.CurrentNode = "convoy_officer_try_again";
			DialogExit();
		break;

		case "exit_silk_rejected":
			AddDialogExitQuest("reset_silk");
			Diag.CurrentNode = "Diag.TempNode";
			DialogExit();
		break;

		case "exit_silk_approved":
			AddDialogExitQuest("romance_makes_clothes");
			Diag.CurrentNode = "Diag.TempNode";
			DialogExit();
		break;
	}
}