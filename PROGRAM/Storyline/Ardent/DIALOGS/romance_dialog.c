//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	int n;
	string gov_kid, gov_kid_pronoun, gov_kid_pronoun2, gov_kid_pronoun3, merch_kid, merch_kid_pronoun, merch_kid_pronoun2, merch_kid_pronoun3, spouse_of;
	string tmp;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar = GetMainCharacter();

	gov_kid_pronoun = XI_ConvertString(GetMyPronounSubj(CharacterFromID(PChar.quest.romance)));
	gov_kid_pronoun2 = XI_ConvertString(GetMyPronounObj(CharacterFromID(PChar.quest.romance)));
	gov_kid_pronoun3 = XI_ConvertString(GetMyPronounPossessive(CharacterFromID(PChar.quest.romance)));
	merch_kid_pronoun = XI_ConvertString(GetMyPronounSubj(CharacterFromID(PChar.quest.villain)));
	merch_kid_pronoun2 = XI_ConvertString(GetMyPronounObj(CharacterFromID(PChar.quest.villain)));
	merch_kid_pronoun3 = XI_ConvertString(GetMyPronounPossessive(CharacterFromID(PChar.quest.villain)));
	if (PChar.sex == "man")
	{
		gov_kid = XI_ConvertString("daughter");
		merch_kid = XI_ConvertString("son");
//		merch_kid_pronoun3 = XI_ConvertString("his");
	}
	else
	{
		gov_kid = XI_ConvertString("son");
		merch_kid = XI_ConvertString("daughter");
//		merch_kid_pronoun3 = XI_ConvertString("her");
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
			if (isofficer(NPChar)) dialog.text = DLG_TEXT[0] + DLG_TEXT[514] + ".";
			if (CheckAttribute(NPChar, "married") && sti(NPChar.married) == MR_MARRIED && NPChar.married.id == PChar.id) dialog.text = DLG_TEXT[0] + DLG_TEXT[515] + ".";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			if (!CheckAttribute(NPChar, "quest.old_abordagemode"))
			{
				link.l2 = DLG_TEXT[497];
				if (CheckAttribute(NPChar, "AbordageMode") && sti(NPChar.AbordageMode) == true) link.l2.go = "Boarding_Active";
				else link.l2.go = "Boarding_Inactive";
			}
		break;

		case "Boarding_Active":
			if (CalcCharacterSkill(PChar, SKILL_FENCING) <= 5) dialog.text = DLG_TEXT[498];
			else dialog.text = DLG_TEXT[499];
			if (PChar.quest.alignment == "good") link.l1 = DLG_TEXT[500] + GetMyName(NPChar) + DLG_TEXT[501];
			else link.l1 = DLG_TEXT[502];
			link.l1.go = "Boarding_Stay_on_Ship";
			link.l2 = DLG_TEXT[506];
			link.l2.go = "Exit";
		break;

		case "Boarding_Stay_on_Ship":
			NPChar.AbordageMode = 0;
			if (NPChar.sex == "woman") dialog.text = DLG_TEXT[503];
			else dialog.text = DLG_TEXT[504];
			link.l1 = DLG_TEXT[505];
			link.l1.go = "Exit";
		break;

		case "Boarding_Inactive":
			if (NPChar.sex == "woman") dialog.text = DLG_TEXT[507];
			else dialog.text = DLG_TEXT[508];
			link.l1 = DLG_TEXT[509];
			link.l1.go = "Boarding_Join_In";
			link.l2 = DLG_TEXT[510];
			link.l2.go = "Exit";
		break;

		case "Boarding_Join_In":
			NPChar.AbordageMode = 1;
			if (NPChar.sex == "woman") dialog.text = DLG_TEXT[511];
			else dialog.text = DLG_TEXT[512];
			link.l1 = DLG_TEXT[513];
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
				dialog.text = DLG_TEXT[93];
				link.l1 = DLG_TEXT[94];
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
			if (!CheckAttribute(PChar,"quest.bored_in_san_juan"))
			{
				link.l3 = DLG_TEXT[31];		
				link.l3.go = "release";
			}
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
			if (PChar.quest.alignment == "good" && n >= 1 && CheckAttribute(PChar, "married") && sti(PChar.married) == MR_SINGLE)
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
				dialog.text = DLG_TEXT[175];
				link.l1 = DLG_TEXT[176];
				link.l1.go = "exit_cabin";
			}
		break;

		case "officer2":
//			dialog.text = DLG_TEXT[41] + gov_kid + DLG_TEXT[42];	// Preprocessed "daughter" and "son" don't work in languages with gendered "the"
			if (NPChar.sex == "man") dialog.text = DLG_TEXT[41] + DLG_TEXT[43] + DLG_TEXT[44];
			else dialog.text = DLG_TEXT[41] + DLG_TEXT[42] + DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "first_mate";
			link.l2 = DLG_TEXT[46];
			link.l2.go = "doctor";
			link.l3 = DLG_TEXT[47];
			link.l3.go = "quartermaster";				// was "carpenter"
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

		case "quartermaster":						// was "carpenter"
			AddDialogExitQuest("recruit_quartermaster");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "marry":
			n = makeint(PChar.quest.ardent_kidnap.voyage_stage);
			if (n<2 && !CheckAttribute(PChar,"quest.bored_in_san_juan"))
			{
				dialog.text = DLG_TEXT[48] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[49];
				link.l1 = DLG_TEXT[50];
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
					PChar.quest.kidnap_hostage_dead.over = "yes";
				}
				dialog.text = DLG_TEXT[138];
				link.l1 = DLG_TEXT[139];
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
						dialog.text = DLG_TEXT[116];
						if (CheckAttribute(PChar,"quest.bored_in_san_juan")) link.l1 = DLG_TEXT[122];
						else link.l1 = DLG_TEXT[119] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[120];
						link.l1.go = "marry_love_logic";
						if (CalcCharacterSkill(PChar, SKILL_LEADERSHIP) >= 5)
						{
							link.l2 = DLG_TEXT[117];
							link.l2.go = "marry_love_flattery";
						}
						if(PChar.sex == "man")
						{
							if (CheckCharacterItem(PChar, "jewelry9") || CheckCharacterItem(PChar, "jewelry13") || CheckCharacterItem(PChar, "jewelry14") || CheckCharacterItem(PChar, "jewelry15") || CheckCharacterItem(PChar, "jewelry16"))
							{
								link.l3 = DLG_TEXT[124];
								link.l3.go = "marry_give_jewellery";
							}
						}
						else
						{
							if(ENABLE_WEAPONSMOD == 1)
							{
								if (CheckCharacterItem(PChar, "blade4+3") || CheckCharacterItem(PChar, "blade47+3") || CheckCharacterItem(PChar, "blade16+3") || CheckCharacterItem(PChar, "blade44+3"))
								{
									link.l3 = DLG_TEXT[124];
									link.l3.go = "marry_give_weapon";
								}
							}
							else
							{
								if (CheckCharacterItem(PChar, "blade4") || CheckCharacterItem(PChar, "blade47") || CheckCharacterItem(PChar, "blade16") || CheckCharacterItem(PChar, "blade44"))
								{
									link.l3 = DLG_TEXT[124];
									link.l3.go = "marry_give_weapon";
								}
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
						dialog.text = DLG_TEXT[128];
						link.l1 = DLG_TEXT[155];
						link.l1.go = "exit_options_open";
						if (CheckCharacterItem(PChar, "jewelry8")) // Bronze ring
						{
							link.l2 = DLG_TEXT[129];
							link.l2.go = "marry_offer_bronze_ring";
						}
						if (CheckCharacterItem(PChar, "jewelry6")) // Silver ring
						{
							link.l3 = DLG_TEXT[130];
							link.l3.go = "marry_offer_silver_ring";
						}
						if (CheckCharacterItem(PChar, "jewelry7")) // Gold emerald ring
						{
							link.l4 = DLG_TEXT[131];
							link.l4.go = "marry_offer_gold_ring";
						}
						if (CheckCharacterItem(PChar, "jewelry10")) // Gold sapphire ring
						{
							link.l5 = DLG_TEXT[132];
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
					dialog.text = DLG_TEXT[113];
					link.l1 = DLG_TEXT[115];
					link.l1.go = "exit_make_peace_spain";
					link.l2 = DLG_TEXT[114];
					link.l2.go = "forget_it";
//					link.l2.go = "exit_options_open";
				}
			}
		break;

		case "marry_love_logic":
			if (CheckAttribute(PChar,"quest.bored_in_san_juan"))
			{
				NPChar.quest.love_me = true;
				dialog.text = DLG_TEXT[123];
				link.l1 = DLG_TEXT[156];
				link.l1.go = "marry";
			}
			else
			{
				dialog.text = DLG_TEXT[121];
				link.l1 = DLG_TEXT[159];
				link.l1.go = "exit_options_open";
				link.l2 = DLG_TEXT[171];
				link.l2.go = "exit_forget_it";
			}
		break;

		case "marry_love_flattery":
			NPChar.quest.love_me = true;
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "marry";
		break;

		case "marry_give_jewellery":
			dialog.text = DLG_TEXT[160];
			if (CheckCharacterItem(PChar, "jewelry9"))
			{
				link.l1 = DLG_TEXT[161];
				link.l1.go = "marry_gift_cross";
			}
			if (CheckCharacterItem(PChar, "jewelry13"))
			{
				link.l2 = DLG_TEXT[162];
				link.l2.go = "marry_gift_silver_brooch";
			}
			if (CheckCharacterItem(PChar, "jewelry14"))
			{
				link.l3 = DLG_TEXT[163];
				link.l3.go = "marry_gift_gold_brooch";
			}
			if (CheckCharacterItem(PChar, "jewelry15"))
			{
				link.l4 = DLG_TEXT[164];
				link.l4.go = "marry_gift_pendant";
			}
			if (CheckCharacterItem(PChar, "jewelry16"))
			{
				link.l5 = DLG_TEXT[165];
				link.l5.go = "marry_gift_necklace";
			}
		break;

		case "marry_give_weapon":
			dialog.text = DLG_TEXT[160];
			if(ENABLE_WEAPONSMOD == 1)
			{
				if (CheckCharacterItem(PChar, "blade4+3"))
				{
					link.l1 = DLG_TEXT[166];
					link.l1.go = "marry_gift_rejected";
				}
				if (CheckCharacterItem(PChar, "blade47+3"))
				{
					link.l2 = DLG_TEXT[167];
					link.l2.go = "marry_gift_light_tizona";
				}
				if (CheckCharacterItem(PChar, "blade16+3"))
				{
					link.l3 = DLG_TEXT[168];
					link.l3.go = "marry_gift_tizona";
				}
				if (CheckCharacterItem(PChar, "blade44+3"))
				{
					link.l4 = DLG_TEXT[169];
					link.l4.go = "marry_gift_cup_hilt";
				}
			}
			else
			{
				if (CheckCharacterItem(PChar, "blade4"))
				{
					link.l1 = DLG_TEXT[166];
					link.l1.go = "marry_gift_rejected";
				}
				if (CheckCharacterItem(PChar, "blade47"))
				{
					link.l2 = DLG_TEXT[167];
					link.l2.go = "marry_gift_light_tizona";
				}
				if (CheckCharacterItem(PChar, "blade16"))
				{
					link.l3 = DLG_TEXT[168];
					link.l3.go = "marry_gift_tizona";
				}
				if (CheckCharacterItem(PChar, "blade44"))
				{
					link.l4 = DLG_TEXT[169];
					link.l4.go = "marry_gift_cup_hilt";
				}
			}
		break;

		case "marry_gift_marry_gift_cross":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(PChar, "jewelry9");
			GiveItem2Character(CharacterFromID(PChar.quest.romance), "jewelry9");
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "marry";
		break;

		case "marry_gift_silver_brooch":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(PChar, "jewelry13");
			GiveItem2Character(CharacterFromID(PChar.quest.romance), "jewelry13");
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "marry";
		break;

		case "marry_gift_gold_brooch":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(PChar, "jewelry14");
			GiveItem2Character(CharacterFromID(PChar.quest.romance), "jewelry14");
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "marry";
		break;

		case "marry_gift_pendant":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(PChar, "jewelry15");
			GiveItem2Character(CharacterFromID(PChar.quest.romance), "jewelry15");
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "marry";
		break;

		case "marry_gift_necklace":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(PChar, "jewelry16");
			GiveItem2Character(CharacterFromID(PChar.quest.romance), "jewelry16");
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "marry";
		break;

		case "marry_gift_light_tizona":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(PChar, "blade47+3");
			GiveItem2Character(CharacterFromID(PChar.quest.romance), "blade47+3");
			if(IsEquipCharacterByItem(PChar, "blade47+3")) EquipCharacterByItem(PChar, "bladeX4");
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "marry";
		break;

		case "marry_gift_tizona":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(PChar, "blade16+3");
			GiveItem2Character(CharacterFromID(PChar.quest.romance), "blade16+3");
			if(IsEquipCharacterByItem(PChar, "blade16+3")) EquipCharacterByItem(PChar, "bladeX4");
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "marry";
		break;

		case "marry_gift_cup_hilt":
			NPChar.quest.love_me = true;
			TakeItemFromCharacter(PChar, "blade44+3");
			GiveItem2Character(CharacterFromID(PChar.quest.romance), "blade44+3");
			if(IsEquipCharacterByItem(PChar, "blade44+3")) EquipCharacterByItem(PChar, "bladeX4");
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[156];
			link.l1.go = "marry";
		break;

		case "marry_gift_rejected":
			dialog.text = DLG_TEXT[125];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "exit_options_open";
			link.l2 = DLG_TEXT[171];
			link.l2.go = "forget_it";
		break;

		case "marry_offer_bronze_ring":
			dialog.text = DLG_TEXT[135];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "exit_options_open";
			link.l2 = DLG_TEXT[171];
			link.l2.go = "forget_it";
		break;

		case "marry_offer_silver_ring":
			dialog.text = DLG_TEXT[133] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[134];
			link.l1 = DLG_TEXT[170];
			link.l1.go = "exit_options_open";
			link.l2 = DLG_TEXT[171];
			link.l2.go = "forget_it";
		break;

		case "marry_offer_gold_ring":
			TakeItemFromCharacter(PChar, "jewelry7");
			GiveItem2Character(PChar, "jewelry7_q");
			PChar.quest.wedding_ring = "jewelry7_q";
			PChar.quest.marriage_status = "ring_chosen";
			dialog.text = DLG_TEXT[136];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "marry";
		break;

		case "marry_offer_sapphire_ring":
			TakeItemFromCharacter(PChar, "jewelry10");
			GiveItem2Character(PChar, "jewelry10_q");
			PChar.quest.wedding_ring = "jewelry10_q";
			PChar.quest.marriage_status = "ring_chosen";
			dialog.text = DLG_TEXT[137];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "marry";
		break;

		case "marry_try_again":
			switch(PChar.quest.marriage_status)
			{
				case "make_peace_spain":
					dialog.text = DLG_TEXT[62] + GetMyFirstNames(PChar, false) + ". " + DLG_TEXT[153];
					if(GetRMRelation(Pchar, SPAIN) > REL_WAR)
					{
						link.l1 = DLG_TEXT[154] + DLG_TEXT[127];
						link.l1.go = "marry";
					}
					else
					{
						link.l1 = DLG_TEXT[155];
						link.l1.go = "exit_make_peace_spain";
						link.l2 = DLG_TEXT[114];
						link.l2.go = "forget_it";
					}
				break;

				dialog.text = DLG_TEXT[62] + GetMyName(PChar) + ".";	// Only drop to here if no specific marriage_status identified
				link.l1 = DLG_TEXT[157];
				link.l1.go = "officer";
				if(sti(PChar.married) == MR_SINGLE)
				{
					link.l2 = DLG_TEXT[158];
					link.l2.go = "marry";
				}
				link.l3 = DLG_TEXT[1];
				link.l3.go = "exit_options_open";
			}
		break;

		case "options":
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			link.l1 = DLG_TEXT[157];
			link.l1.go = "officer";
			if(sti(PChar.married) == MR_SINGLE)
			{
				link.l2 = DLG_TEXT[158];
				link.l2.go = "marry";
			}
			link.l3 = DLG_TEXT[1];
			link.l3.go = "exit_options_open";
		break;

		case "no_escape":
			dialog.text = DLG_TEXT[415];
			link.l1 = DLG_TEXT[416];
			link.l1.go = "no_escape2";
		break;

		case "no_escape2":
			dialog.text = DLG_TEXT[417];
			link.l1 = DLG_TEXT[418] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[419];
			link.l1.go = "no_escape3";
		break;

		case "no_escape3":
			dialog.text = DLG_TEXT[420];
			link.l1 = DLG_TEXT[421];
			link.l1.go = "no_want_escape";
		break;

		case "no_want_escape":
			dialog.text = DLG_TEXT[422];
			link.l1 = DLG_TEXT[53];
			AddDialogExitQuest("writing_letter");
			link.l1.go = "exit_letter";
		break;

		case "letter":
			dialog.text = DLG_TEXT[51] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			AddDialogExitQuest("writing_letter");
			link.l1.go = "exit_letter";
		break;

		case "exit_letter":
			Diag.CurrentNode = "still_writing";
			DialogExit();
		break;

		case "still_writing":
			dialog.text = DLG_TEXT[413];
			link.l1 = DLG_TEXT[414];
			link.l1.go = "exit_letter";
		break;

		case "letter_done":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			AddDialogExitQuest("deliver_ExplainLetter");
			link.l1.go = "exit_cabin";
		break;

		case "visit_father":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[58];
			link.l1.go = "exit";
		break;

		case "just_released":
			dialog.text = DLG_TEXT[59] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "exit";
		break;

		case "bored_in_san_juan":
			PChar.quest.bored_in_san_juan = "waiting";
			dialog.text = DLG_TEXT[62] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[63];
			link.l1.go = "bored_in_san_juan2";
		break;

		case "bored_in_san_juan2":
			dialog.text = DLG_TEXT[64];
			link.l1 = DLG_TEXT[65];
			link.l1.go = "officer";
			link.l2 = DLG_TEXT[66] + GetMySimpleName(CharacterFromID(PChar.quest.villain)) + DLG_TEXT[67];
			link.l2.go = "marry";
			link.l3 = DLG_TEXT[68];
			link.l3.go = "exit";
		break;

		case "second_CourtingLetter_delivered":
			TakeItemFromCharacter(PChar, "CourtingLetter");
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70] + GetMyFullName(PChar) + DLG_TEXT[71];
			link.l1.go = "second_CourtingLetter_delivered2";
		break;

		case "second_CourtingLetter_delivered2":
			PChar.quest.ardent_kidnap.wedding = "sad";
			if (PChar.sex == "man") Preprocessor_Add("pronoun", XI_ConvertString("he"));
			else Preprocessor_Add("pronoun", XI_ConvertString("she"));
			dialog.text = DLG_TEXT[72] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[73];
			link.l1 = DLG_TEXT[74];
			link.l1.go = "letter_offer_help";
			link.l2 = DLG_TEXT[75];
			link.l2.go = "letter_kidnap";
			link.l3 = DLG_TEXT[77];
			link.l3.go = "letter_courier";
		break;

		case "letter_courier":
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79] + GetMyFullName(characterFromID(PChar.quest.villain)) + DLG_TEXT[80];
			link.l1.go = "exit";
			AddDialogExitQuest("second_CourtingLetter_return_with_answer");
		break;

		case "letter_kidnap":
			dialog.text = DLG_TEXT[81];
			link.l1 = DLG_TEXT[82];
			link.l1.go = "letter_kidnap2";
			link.l2 = DLG_TEXT[91];
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
			link.l1 = DLG_TEXT[76];
			link.l1.go = "letter_offer_help2";
			link.l2 = DLG_TEXT[92];
			link.l2.go = "letter_kidnap";
		break;

		case "letter_offer_help2":
			PChar.quest.ardent_kidnap.status = "cooperate";
			dialog.text = DLG_TEXT[14] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "letter_fake_kidnap";
			if (CheckCharacterItem(PChar, "pistolbow") && CheckCharacterItem(PChar, "bladearrows"))
			{
				link.l2 = DLG_TEXT[83];
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
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "letter_bow2";
		break;

		case "letter_bow2":
			dialog.text = DLG_TEXT[86];
			link.l1 = DLG_TEXT[87];
			link.l1.go = "letter_bow3";
		break;

		case "letter_bow3":
			dialog.text = DLG_TEXT[88] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[89];
			link.l1 = DLG_TEXT[90];
			link.l1.go = "exit";
			AddDialogExitQuest("second_CourtingLetter_bow_escape");
		break;

		case "run_for_ship":
			dialog.text = DLG_TEXT[95];
			if (PChar.location.from_sea == "Cuba_shore_02") link.l1 = DLG_TEXT[411];
			else link.l1 = DLG_TEXT[96];
			link.l1.go = "exit";
		break;

		case "bow_rescue_climbed_in":
			dialog.text = DLG_TEXT[97] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + ".";
			link.l1 = DLG_TEXT[98];
			link.l1.go = "bow_rescue_tie_rope";
		break;

		case "bow_rescue_tie_rope":
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "exit";
		break;

		case "bow_rescue_outside_residence":
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "exit";
		break;

		case "just_a_cabin_boy":
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
		break;

		case "naughty_guard":
			dialog.text = DLG_TEXT[104];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
		break;

		case "board_before_he_remembers":
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "how_i_know_guard";
		break;

		case "how_i_know_guard":
			dialog.text = DLG_TEXT[107];
			link.l1 = DLG_TEXT[108];
			link.l1.go = "guards_problem";
		break;

		case "guards_problem":
			dialog.text = DLG_TEXT[109];
			if (PChar.location.from_sea == "Cuba_shore_02") link.l1 = DLG_TEXT[412];
			else link.l1 = DLG_TEXT[110];
			link.l1.go = "exit";
		break;

		case "wedding_night":
			dialog.text = DLG_TEXT[111];
			link.l1 = DLG_TEXT[112];
			AddDialogExitQuest("get_lost_player");
			link.l1.go = "exit";
		break;

		case "explain_absence":
			dialog.text = DLG_TEXT[140] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[141] + GetMySimpleName(PChar) + DLG_TEXT[142] + GetMySimpleName(characterFromID(PChar.quest.villain)) + ".";
			link.l1 = DLG_TEXT[143];
			link.l1.go = "exit";
		break;

		case "marriage_proposed":
			dialog.text = DLG_TEXT[144] + GetMyFirstNames(PChar, false) + DLG_TEXT[145];
			link.l1 = DLG_TEXT[146];
			link.l1.go = "exit";
		break;

		case "broken-hearted":
			dialog.text = DLG_TEXT[147];
			link.l1 = DLG_TEXT[148];
			Diag.TempNode = "dont_talk_to_me";
			link.l1.go = "exit";
		break;

		case "dont_talk_to_me":
			dialog.text = DLG_TEXT[151];
			link.l1 = DLG_TEXT[152];
			link.l1.go = "exit";
			Diag.TempNode = "dont_talk_to_me";
		break;

		case "marriage_accepted":
			DeleteQuestAttribute("bored_in_san_juan");
			DeleteQuestAttribute("ardent_kidnap");
			dialog.text = DLG_TEXT[149];
			link.l1 = DLG_TEXT[150];
			link.l1.go = "exit";
		break;

		case "forget_it":
			if(Characters[GetMainCharacterIndex()].location == "Tutorial_Deck") dialog.text = DLG_TEXT[173];
			else dialog.text = DLG_TEXT[172];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "exit_forget_it";
		break;

		case "ask_favour":
			if(CheckQuestAttribute("revenge_type","assassin")) dialog.text = DLG_TEXT[177] + GetMyName(PChar) + DLG_TEXT[178];
			else dialog.text = DLG_TEXT[179];
			link.l1 = DLG_TEXT[180];
			link.l1.go = "convoy_request";
		break;

		case "convoy_request":
			PreProcessor_Add("pronoun", merch_kid_pronoun);
			PreProcessor_Add("pronoun2", merch_kid_pronoun2);
			if(CheckAttribute(PChar,"quest.assassination")) dialog.text = DLG_TEXT[181] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[182];
			else dialog.text = DLG_TEXT[183] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[184];
			dialog.text = dialog.text + DLG_TEXT[185] + GetMyName(PChar) + DLG_TEXT[186];
			link.l1 = DLG_TEXT[187];
			link.l1.go = "convoy_thought_about_it";
		break;

		case "convoy_thought_about_it":
			dialog.text = DLG_TEXT[188];
			PreProcessor_Add("pronoun", merch_kid_pronoun);
			link.l1 = DLG_TEXT[189] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[190];
			link.l1.go = "convoy_summarised";
		break;

		case "convoy_summarised":
			SetQuestHeader("Convoy Strike");
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			Preprocessor_AddQuestData("romance", GetMyFullName(characterFromID(PChar.quest.romance)));
			Preprocessor_AddQuestData("romance1", GetMyName(characterFromID(PChar.quest.romance)));
			Preprocessor_AddQuestData("pronoun1", merch_kid_pronoun);
			Preprocessor_AddQuestData("pronoun2", gov_kid_pronoun2);
			AddQuestRecord("Convoy Strike", 1);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("pronoun1");
			Preprocessor_Remove("romance1");
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			dialog.text = DLG_TEXT[191];
			if(PChar.married == MR_MARRIED && PChar.married.id == characters[getCharacterIndex(PChar.quest.romance)].id) link.l1 = DLG_TEXT[192];
			else link.l1 = DLG_TEXT[193];
			link.l1.go = "exit";
		break;

		case "convoy_officer":
			dialog.text = DLG_TEXT[194];
			link.l1 = DLG_TEXT[195] + DLG_TEXT[40];
			link.l1.go = "officer2";
		break;

		case "convoy_how_take_convoy":
			dialog.text = DLG_TEXT[196] + GetMyName(PChar) + "?";
			if(CheckQuestAttribute("revenge_type","assassin"))
			{
				link.l1 = DLG_TEXT[201] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[202];
				link.l1.go = "convoy_interested_prepare";
			}
			else
			{
				if (PChar.sex == "man") spouse_of = DLG_TEXT[198];
				else spouse_of = DLG_TEXT[199];
				link.l1 = DLG_TEXT[197] + spouse_of + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[200];
				AddDialogExitQuest("convoy_arrive_port_plan1");
				link.l1.go = "exit";
			}
		break;

		case "convoy_interested_prepare":
			dialog.text = DLG_TEXT[203];
			link.l1 = DLG_TEXT[204];
			AddDialogExitQuest("convoy_arrive_port");
			link.l1.go = "exit";
		break;

		case "convoy_recognised":
			dialog.text = DLG_TEXT[205];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_recognised2":
			dialog.text = DLG_TEXT[206];
			link.l1 = DLG_TEXT[207];
			link.l1.go = "convoy_recognised3";
		break;

		case "convoy_recognised3":
			if(CheckQuestAttribute("revenge_type","kidnap_rescue")) dialog.text = DLG_TEXT[323] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[324];
			else dialog.text = DLG_TEXT[208];
			link.l1 = DLG_TEXT[209];
			link.l1.go = "convoy_recognised4";
		break;

		case "convoy_recognised4":
			dialog.text = DLG_TEXT[210] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[211];
			link.l1 = DLG_TEXT[212];
			link.l1.go = "convoy_recognised5";
		break;

		case "convoy_recognised5":
			dialog.text = DLG_TEXT[213];
			link.l1 = DLG_TEXT[201] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[202];
			link.l1.go = "convoy_interested_prepare";
		break;

		case "convoy_be_quiet":
			dialog.text = DLG_TEXT[214];
			link.l1 = DLG_TEXT[215];
			link.l1.go = "convoy_negotiate";
		break;

		case "convoy_negotiate":
			dialog.text = DLG_TEXT[216] + Characters[GetCharacterIndex("Convoy_Captain1")].Ship.Name + DLG_TEXT[217] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[218] + GetMyFullName(characterFromID("Javier Balboa")) + DLG_TEXT[219];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_show_letter":
			dialog.text = DLG_TEXT[220];
			link.l1 = DLG_TEXT[221];
			link.l1.go = "exit";
		break;

		case "convoy_choose_officer_first_time":
			dialog.text = DLG_TEXT[224];
			if(GetOfficersIndex(PChar, 1) != -1)
			{
				link.l1 = GetMySimpleName(characters[GetOfficersIndex(PChar, 1)]) + ".";
				link.l1.go = "convoy_choose_officer1";
			}
			if(GetOfficersIndex(PChar, 2) != -1)
			{
				link.l2 = GetMySimpleName(characters[GetOfficersIndex(PChar, 2)]) + ".";
				link.l2.go = "convoy_choose_officer2";
			}
			if(GetOfficersIndex(PChar, 3) != -1)
			{
				link.l3 = GetMySimpleName(characters[GetOfficersIndex(PChar, 3)]) + ".";
				link.l3.go = "convoy_choose_officer3";
			}
			link.l4 = DLG_TEXT[225];
			link.l4.go = "exit_not_chosen_officer";
		break;

		case "convoy_officer_try_again":
			dialog.text = DLG_TEXT[228];
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
			link.l4 = DLG_TEXT[225];
			link.l4.go = "exit_not_chosen_officer";
		break;

		case "convoy_choose_officer1":
			if (GetOfficersIndex(Pchar, 1) == GetCharacterIndex(PChar.quest.romance))
			{
				dialog.text = DLG_TEXT[226];
				link.l1 = DLG_TEXT[227];
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
				dialog.text = DLG_TEXT[226];
				link.l1 = DLG_TEXT[227];
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
				dialog.text = DLG_TEXT[226];
				link.l1 = DLG_TEXT[227];
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
			dialog.text = DLG_TEXT[222];
			link.l1 = DLG_TEXT[223];
			AddDialogExitQuest("convoy_romance_removes_cloak");
			link.l1.go = "exit";
		break;

		case "convoy_dispose_ships":
			dialog.text = DLG_TEXT[229];
			if(CheckQuestAttribute("revenge_type","kidnap_rescue")) dialog.text = DLG_TEXT[229] + DLG_TEXT[325];
			link.l1 = DLG_TEXT[230];
			link.l1.go = "exit";
		break;

		case "convoy_dispose_ships2":
			dialog.text = DLG_TEXT[231] + GetMyName(PChar) + ".";
			if(CheckQuestAttribute("revenge_type","kidnap_rescue")) dialog.text = DLG_TEXT[231] + GetMyName(PChar) + "." + DLG_TEXT[326];
			link.l1 = DLG_TEXT[232];
			link.l1.go = "exit";
		break;

		case "convoy_dispose_just_my_ship":
			dialog.text = DLG_TEXT[401];
			link.l1 = DLG_TEXT[230];
			link.l1.go = "exit";
		break;

		case "convoy_dispose_just_my_ship2":
			dialog.text = DLG_TEXT[402] + GetMyName(PChar) + DLG_TEXT[403];
			link.l1 = DLG_TEXT[404];
			link.l1.go = "exit_convoy_dispose_just_my_ship";
			link.l2 = DLG_TEXT[405];
			link.l2.go = "exit";
		break;

		case "convoy_after_governor":
			dialog.text = DLG_TEXT[233];
			link.l1 = DLG_TEXT[234];
			link.l1.go = "convoy_you_failed";
		break;

		case "convoy_you_failed":
			dialog.text = DLG_TEXT[235];
			link.l1 = DLG_TEXT[242];
			link.l1.go = "convoy_wrote_letter";
			if (PChar.quest.alignment == "good")
			{
				dialog.text = DLG_TEXT[235] + DLG_TEXT[236];
				link.l1 = DLG_TEXT[237];
				link.l1.go = "convoy_funny";
			}
		break;

		case "convoy_funny":
			dialog.text = DLG_TEXT[238];
			link.l1 = DLG_TEXT[239];
			link.l1.go = "convoy_if_governor_could_see_us";
		break;

		case "convoy_if_governor_could_see_us":
			dialog.text = DLG_TEXT[240];
			link.l1 = DLG_TEXT[241];
			link.l1.go = "convoy_wrote_letter";
		break;

		case "convoy_wrote_letter":
			dialog.text = DLG_TEXT[243];
			link.l1 = DLG_TEXT[244];
			link.l1.go = "exit";
		break;

		case "convoy_propose_trade":
			PreProcessor_Add("dutch_gov", GetMyLastName(characterFromID("Hans Kloss")));
			PreProcessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			if(CheckAttribute(characterFromID(PChar.quest.romance), "married") && characters[getCharacterIndex(PChar.quest.romance)].married == MR_MARRIED && characters[getCharacterIndex(PChar.quest.romance)].married.id == PChar.id)
				dialog.text = DLG_TEXT[245];
			else dialog.text = DLG_TEXT[302];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_ask_to_take_ship":
			PreProcessor_Add("ship", Characters[GetCharacterIndex("Javier Balboa")].Ship.Name);
			PreProcessor_Add("dutch_gov", GetMyLastName(characterFromID("Hans Kloss")));
			dialog.text = DLG_TEXT[246];
			link.l1 = DLG_TEXT[247];
			link.l1.go = "convoy_confident";
		break;

		case "convoy_confident":
			dialog.text = DLG_TEXT[248];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_free_slot":
			PreProcessor_Add("ship", Characters[GetCharacterIndex(PChar.quest.romance)].Ship.Name);
			dialog.text = DLG_TEXT[249];
			link.l1 = DLG_TEXT[250];
			link.l1.go = "exit";
		break;

		case "convoy_free_slot2":
			dialog.text = DLG_TEXT[251] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[252];
			link.l1.go = "exit";
		break;

		case "convoy_interrupt_recognition":
			dialog.text = GetMyFullName(PChar) + DLG_TEXT[253];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_give_trade_letter":
			dialog.text = DLG_TEXT[254];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "convoy_flattery":
			dialog.text = DLG_TEXT[255];
			if (PChar.quest.alignment == "good") link.l1 = DLG_TEXT[256];
			else link.l1 = DLG_TEXT[257];
			link.l1.go = "exit";
		break;

		case "convoy_done_wrong":
			dialog.text = DLG_TEXT[303];
			link.l1 = DLG_TEXT[304];
			link.l1.go = "convoy_goodbye";
		break;

		case "convoy_goodbye":
			if(CheckAttribute(characterFromID(PChar.quest.romance), "married") && characters[getCharacterIndex(PChar.quest.romance)].married == MR_MARRIED && characters[getCharacterIndex(PChar.quest.romance)].married.id == PChar.id)
				dialog.text = DLG_TEXT[306] + GetMyName(PChar) + ".";
			else
				dialog.text = DLG_TEXT[305] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[306] + GetMyName(characterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "exit";
		break;

		case "want_silk":
			dialog.text = DLG_TEXT[258];
			link.l1 = DLG_TEXT[259];
			link.l1.go = "silk_approved";
			link.l2 = DLG_TEXT[260];
			link.l2.go = "exit_silk_rejected";
		break;

		case "silk_approved":
			dialog.text = DLG_TEXT[261];
			link.l1 = DLG_TEXT[262];
			link.l1.go = "exit_silk_approved";
		break;

		case "new_clothes":
			dialog.text = DLG_TEXT[263];
			link.l1 = DLG_TEXT[264];
			link.l1.go = "exit";
		break;

		case "abduction_found_in_cell":
			dialog.text = DLG_TEXT[265] + GetMyName(PChar) + DLG_TEXT[266];
			if (!CheckCharacterItem(PChar, "lockpick"))
			{
				link.l1 = DLG_TEXT[267];
				link.l1.go = "abduction_corridor_to_house";
				Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
				Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
				AddQuestRecord("Abduction", 17);
				Preprocessor_Remove("villain");
				Preprocessor_Remove("romance");
				Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "abduction_where_did_you_come_from";
			}
			else
			{
				link.l1 = DLG_TEXT[271];
				AddDialogExitQuest("abduction_release_romance");
				link.l1.go = "exit";
			}
		break;

		case "abduction_corridor_to_house":
			dialog.text = DLG_TEXT[268] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[269];
			link.l1 = DLG_TEXT[270];
			link.l1.go = "exit";
		break;

		case "abduction_return_with_lockpick":
			dialog.text = DLG_TEXT[272];
			link.l1 = DLG_TEXT[273];
			link.l1.go = "exit";
		break;

		case "abduction_romance_free":
			dialog.text = DLG_TEXT[274];
			link.l1 = DLG_TEXT[275];
			link.l1.go = "exit";
		break;

		case "abduction_romance_confronts_merchant":
			Preprocessor_Add("pronoun", merch_kid_pronoun2);
			if (CheckQuestAttribute("ardent_kidnap.status", "in_downing_prison"))
			dialog.text = GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[277];
			else dialog.text = GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[276] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[277];
			link.l1 = DLG_TEXT[278] + GetMyFullName(characterFromID(PChar.quest.villain)) + "?";
			link.l1.go = "exit";
		break;

		case "abduction_romance_suggests_church":
			dialog.text = DLG_TEXT[279];
			link.l1 = DLG_TEXT[280];
			link.l1.go = "exit";
		break;

		case "abduction_romance_will_pay_church":
			dialog.text = DLG_TEXT[281];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "abduction_accuse_abductor":
// Figure out attributes to detect if abducted from San Juan or from ship, then use DLG_TEXT[283] or DLG_TEXT[284]
			switch(PChar.quest.revenge_type)
			{
				case "san_juan":
					tmp = DLG_TEXT[284];
				break;

				case "officer":
					tmp = DLG_TEXT[285] + GetMySimpleName(PChar) + DLG_TEXT[286];
				break;
			}
			Preprocessor_Add("pronoun", merch_kid_pronoun2);
			dialog.text = DLG_TEXT[282] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[283] + tmp + DLG_TEXT[287] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[288] + GetMySimpleName(PChar) + ".";
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "abduction_revenge_plan":
			dialog.text = DLG_TEXT[289] + GetMySimpleName(PChar) + DLG_TEXT[290];
			link.l1 = DLG_TEXT[291] + GetMyName(characterFromID(PChar.quest.romance)) + "?";
			link.l1.go = "convoy_request";
		break;

		case "abduction_officer_request_leave":
			dialog.text = DLG_TEXT[292];
			link.l1 = DLG_TEXT[293] + GetMyName(characterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "exit";
		break;

		case "kidnap_rescue_found_in_cell":
			dialog.text = GetMySimpleName(PChar) + DLG_TEXT[308];
			link.l1 = DLG_TEXT[309];
			link.l1.go = "kidnap_rescue_found_in_cell2";
		break;

		case "kidnap_rescue_found_in_cell2":
			dialog.text = DLG_TEXT[310];
			if (!CheckCharacterItem(PChar, "lockpick"))
			{
				link.l1 = DLG_TEXT[311] + DLG_TEXT[267];
				link.l1.go = "abduction_corridor_to_house";
				Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
				Preprocessor_AddQuestData("pronoun", gov_kid_pronoun2);
				AddQuestRecord("Dungeon", 4);
				Preprocessor_Remove("pronoun");
				Preprocessor_Remove("romance");
				Characters[GetCharacterIndex("Gilbert Downing")].dialog.CurrentNode = "abduction_where_did_you_come_from";
			}
			else
			{
				link.l1 = DLG_TEXT[311] + DLG_TEXT[271];
				AddDialogExitQuest("abduction_release_romance");
				link.l1.go = "exit";
			}
		break;

		case "kidnap_rescue_report1":
			Preprocessor_Add("pronoun_PC", FirstLetterUp(merch_kid_pronoun));
			Preprocessor_Add("pronoun_villain", merch_kid_pronoun);
			dialog.text = DLG_TEXT[294] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[295] + GetMyName(PChar) + DLG_TEXT[296];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "kidnap_rescue_who_do_you_believe":
			Preprocessor_Add("gov_kid", gov_kid);
			Preprocessor_Add("person", XI_ConvertString(characters[getCharacterIndex(PChar.quest.villain)].sex));
			if (PChar.sex == "woman") dialog.text = DLG_TEXT[298];
			else dialog.text = DLG_TEXT[297];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "kidnap_rescue_already_in_hand":
			Preprocessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun3", merch_kid_pronoun3);
			dialog.text = DLG_TEXT[299] + GetMySimpleName(PChar) + DLG_TEXT[300];
			link.l1 = DLG_TEXT[301];
			link.l1.go = "exit";
		break;

		case "kidnap_rescue_propose_convoy1":
			Preprocessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[312];
			link.l1 = DLG_TEXT[313];
			link.l1.go = "kidnap_rescue_propose_convoy2";
		break;

		case "kidnap_rescue_propose_convoy2":
			dialog.text = DLG_TEXT[314];
			link.l1 = DLG_TEXT[315];
			link.l1.go = "kidnap_rescue_propose_convoy3";
		break;

		case "kidnap_rescue_propose_convoy3":
			PreProcessor_Add("pronoun", merch_kid_pronoun);
			PreProcessor_Add("pronoun2", merch_kid_pronoun2);
			dialog.text = DLG_TEXT[316] + DLG_TEXT[183] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[184] + DLG_TEXT[317];
			link.l1 = DLG_TEXT[318];
			link.l1.go = "kidnap_rescue_propose_convoy4";
		break;

		case "kidnap_rescue_propose_convoy4":
			Preprocessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[319];
			link.l1 = DLG_TEXT[320];
			link.l1.go = "kidnap_rescue_propose_convoy5";
		break;

		case "kidnap_rescue_propose_convoy5":
			Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
			AddQuestRecord("Dungeon", 5);
			CloseQuestHeader("Dungeon");
			Preprocessor_AddQuestData("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			Preprocessor_AddQuestData("romance", GetMySimpleName(characterFromID(PChar.quest.romance)));
			Preprocessor_AddQuestData("romance1", GetMyName(characterFromID(PChar.quest.romance)));
			Preprocessor_AddQuestData("pronoun1", merch_kid_pronoun);
			Preprocessor_AddQuestData("pronoun2", gov_kid_pronoun2);
			SetQuestHeader("Convoy Strike");
			AddQuestRecord("Convoy Strike", 1);
			Preprocessor_Remove("pronoun2");
			Preprocessor_Remove("pronoun1");
			Preprocessor_Remove("romance1");
			Preprocessor_Remove("romance");
			Preprocessor_Remove("villain");
			Preprocessor_Add("villain", GetMySimpleName(characterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[321];
			link.l1 = DLG_TEXT[322] + DLG_TEXT[40];
			link.l1.go = "officer2";
		break;

		case "treachery_reject_villain":
			dialog.text = DLG_TEXT[327] + GetMyName(characterFromID(PChar.quest.villain)) + "!";
			link.l1 = "";
			AddDialogExitQuest("threat_goto_santiago");
			AddDialogExitQuest("treachery_romance_rejects_villain");
			link.l1.go = "exit";
		break;

		case "threat_goto_santiago":
			dialog.text = GetMyName(PChar) + ", " + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[391];
			link.l1 = DLG_TEXT[392];
			link.l1.go = "threat_go_santiago_now";
		break;

		case "threat_go_santiago_now":
			dialog.text = DLG_TEXT[393];
			link.l1 = DLG_TEXT[394] + GetMyName(characterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "exit";
		break;

		case "hunt_join_villain":
			Preprocessor_AddQuestData("pronoun", merch_kid_pronoun);
			Preprocessor_Add("background", PChar.quest.background);
			dialog.text = DLG_TEXT[328] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[329];
			link.l1 = DLG_TEXT[330] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[331];
			link.l1.go = "hunt_join_villain2";
		break;

		case "hunt_join_villain2":
			dialog.text = DLG_TEXT[332] + GetMyName(PChar) + ".";
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "hunt_release_you":
			dialog.text = DLG_TEXT[334];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "hunt_take_knife":
			GiveItem2Character(PChar,"Piratesdagger");
			EquipCharacterByItem(PChar,"Piratesdagger");
			dialog.text = DLG_TEXT[335];
			link.l1 = DLG_TEXT[336];
			link.l1.go = "exit";
		break;

		case "hunt_explain_deceit":
			Preprocessor_AddQuestData("pronoun", merch_kid_pronoun);
			dialog.text = DLG_TEXT[337] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[338];
			link.l1 = DLG_TEXT[339] + GetMyName(CharacterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "hunt_equipment";
			link.l2 = DLG_TEXT[340];
			link.l2.go = "hunt_equipment";
			link.l3 = DLG_TEXT[341];
			link.l3.go = "hunt_explain_deceit2";
		break;

		case "hunt_explain_deceit2":
			dialog.text = DLG_TEXT[342] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[343] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[344];
			link.l1 = DLG_TEXT[345];
			link.l1.go = "hunt_equipment";
		break;

		case "hunt_equipment":
			dialog.text = DLG_TEXT[346];
			link.l1 = DLG_TEXT[347];
			link.l1.go = "hunt_status_report";
		break;

		case "hunt_status_report":
			dialog.text = DLG_TEXT[348];
			link.l1 = DLG_TEXT[349] + GetMySimpleName(characterFromID(PChar.quest.villain)) + "?";
			link.l1.go = "hunt_where_villain";
		break;

		case "hunt_where_villain":
			Preprocessor_AddQuestData("pronoun", merch_kid_pronoun);
			Preprocessor_AddQuestData("pronoun2", merch_kid_pronoun2);
			Preprocessor_AddQuestData("pronoun3", merch_kid_pronoun3);
			dialog.text = GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[350];
			link.l1 = DLG_TEXT[351];
			link.l1.go = "hunt_jump_ship";
		break;

		case "hunt_jump_ship":
			Preprocessor_AddQuestData("pronoun", merch_kid_pronoun);
			Preprocessor_AddQuestData("pronoun2", merch_kid_pronoun2);
			dialog.text = DLG_TEXT[352] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[353];
			link.l1 = DLG_TEXT[354] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[355];
			link.l1.go = "hunt_crew_ashore";
			link.l2 = DLG_TEXT[356] + GetMySimpleName(characterFromID(PChar.quest.villain)) + DLG_TEXT[357];
			link.l2.go = "hunt_still_doubtful";
		break;

		case "hunt_still_doubtful":
			if (CheckQuestAttribute("alignment","good"))
			{
				dialog.text = DLG_TEXT[358] + GetMyName(characterFromID(PChar.quest.villain)) + DLG_TEXT[359];
				link.l1 = DLG_TEXT[360];
			}
			else
			{
				dialog.text = DLG_TEXT[361];
				link.l1 = DLG_TEXT[362];
			}
			link.l1.go = "hunt_crew_ashore";
		break;

		case "hunt_crew_ashore":
			dialog.text = DLG_TEXT[363];
			link.l1 = DLG_TEXT[364];
			link.l1.go = "exit";
		break;

		case "hunt_rescue_crew_how":
			dialog.text = DLG_TEXT[365] + GetMyName(PChar) + "?";
			link.l1 = DLG_TEXT[366] + GetMyName(characterFromID(PChar.quest.romance)) + "?";
			link.l1.go = "hunt_rescue_crew_persuade";
		break;

		case "hunt_rescue_crew_persuade":
			dialog.text = DLG_TEXT[367];
			link.l1 = DLG_TEXT[368];
			link.l1.go = "hunt_rescue_crew_letter";
		break;

		case "hunt_rescue_crew_letter":
			dialog.text = DLG_TEXT[369];
			link.l1 = DLG_TEXT[370];
			link.l1.go = "hunt_rescue_crew_specimen";
		break;

		case "hunt_rescue_crew_specimen":
			dialog.text = DLG_TEXT[371];
			link.l1 = DLG_TEXT[372];
			link.l1.go = "exit";
		break;

		case "hunt_seen_backdoor":
			dialog.text = GetMyName(PChar) + DLG_TEXT[373];
			if (GetDayTime() == DAY_TIME_NIGHT) link.l1 = DLG_TEXT[374];
			else link.l1 = DLG_TEXT[374] + DLG_TEXT[375];
			link.l1.go = "exit";
		break;

		case "hunt_did_you_get_it":
			dialog.text = DLG_TEXT[376];
			if (CheckAttribute(PChar, "quest.hunt_found_document"))
			{
				link.l1 = DLG_TEXT[377];
				link.l1.go = "hunt_goto_tavern";
			}
			else
			{
				link.l1 = DLG_TEXT[378];
				link.l1.go = "exit";
			}
		break;

		case "hunt_consider_forgery":
			dialog.text = DLG_TEXT[388];
			if (CheckAttribute(PChar, "quest.hunt_found_document"))
			{
				Preprocessor_Add("document", PChar.quest.hunt_found_document);
				link.l1 = DLG_TEXT[389];
				link.l1.go = "hunt_goto_tavern";
			}
			else
			{
				link.l1 = DLG_TEXT[390];
				link.l1.go = "exit_still_need_autograph";
			}
		break;

		case "hunt_goto_tavern":
			dialog.text = DLG_TEXT[379] + GetMyName(PChar) + DLG_TEXT[380];
			link.l1 = DLG_TEXT[381] + GetMyName(characterFromID(PChar.quest.romance)) + "!";
			link.l1.go = "hunt_business_first";
		break;

		case "hunt_business_first":
			dialog.text = DLG_TEXT[382];
			link.l1 = DLG_TEXT[383];
			AddDialogExitQuest("hunt_with_romance_to_tavern");
			link.l1.go = "exit";
		break;

		case "hunt_document_done":
			dialog.text = DLG_TEXT[384];
			link.l1 = DLG_TEXT[385];
			link.l1.go = "hunt_need_uniform";
		break;

		case "hunt_need_uniform":
			dialog.text = DLG_TEXT[386];
			link.l1 = DLG_TEXT[387];
			link.l1.go = "exit";
		break;

		case "governors_revenge_reply":
			Preprocessor_Add("villain", GetMyName(characterFromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun", merch_kid_pronoun);
			Preprocessor_Add("pronoun2", merch_kid_pronoun2);
			dialog.text = DLG_TEXT[395] + GetMySimpleName(PChar) + DLG_TEXT[396] + GetMyName(PChar) + DLG_TEXT[397];
			link.l1 = "";
//			AddDialogExitQuest("governors_revenge_what_sort_revenge");
			link.l1.go = "exit";
		break;

		case "governors_revenge_report_convoy_taken":
			Preprocessor_Add("villain", GetMyName(characterFromID(PChar.quest.villain)));
			Preprocessor_Add("pronoun", merch_kid_pronoun);
			dialog.text = GetMyName(PChar) + DLG_TEXT[398];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "governors_revenge_still_with_you":
			Preprocessor_Add("romance", GetMyName(characterFromID(PChar.quest.romance)));
			dialog.text = DLG_TEXT[399];
			link.l1 = DLG_TEXT[400];
			link.l1.go = "exit";
		break;

		case "finale_stay_with_father":
			dialog.text = DLG_TEXT[406];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "finale_win_or_avenge":
			dialog.text = DLG_TEXT[407];
			link.l1 = DLG_TEXT[408];
			link.l1.go = "exit";
		break;

		case "finale_accept_marriage":
			dialog.text = DLG_TEXT[409] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[410] + GetMyName(NPChar) + ".";
			link.l1.go = "exit";
		break;

		case "imperial_escort_jailbreak":
			dialog.text = DLG_TEXT[423];
			link.l1 = DLG_TEXT[424] + GetMyName(NPChar) + "?";
			link.l1.go = "imperial_escort_how_did_you_pass_guards";
		break;

		case "imperial_escort_how_did_you_pass_guards":
			dialog.text = DLG_TEXT[425];
			link.l1 = DLG_TEXT[426];
			link.l1.go = "imperial_escort_get_your_stuff";
		break;

		case "imperial_escort_get_your_stuff":
			dialog.text = DLG_TEXT[427];
			link.l1 = DLG_TEXT[428];
			link.l1.go = "exit";
		break;

		case "imperial_escort_ships_impounded":
			if(sti(PChar.quest.imperial_escort.original_fleet_size) == 1) dialog.text = DLG_TEXT[429] + DLG_TEXT[431];
			else dialog.text = DLG_TEXT[430] + DLG_TEXT[431];
			link.l1 = DLG_TEXT[432];
			link.l1.go = "exit";
		break;

		case "imperial_escort_explanation":
			dialog.text = DLG_TEXT[433];
			link.l1 = DLG_TEXT[434];
			link.l1.go = "imperial_escort_explanation2";
		break;

		case "imperial_escort_explanation2":
			dialog.text = GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[435] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[436] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[437];
			link.l1 = DLG_TEXT[438];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[440] + GetMyName(NPChar) + "?";
			link.l2.go = "imperial_escort_trader_explanation";
			link.l3 = DLG_TEXT[439];
			link.l3.go = "imperial_escort_nocapture_explanation";
		break;

		case "imperial_escort_trader_explanation":
			NPChar.quest.imperial_escort.trader_explained = "true";
			dialog.text = DLG_TEXT[442];
			link.l1 = DLG_TEXT[438];
			link.l1.go = "exit";
			if(GetAttribute(NPChar, "quest.imperial_escort.nocapture_explained") != "true")
			{
				link.l2 = DLG_TEXT[439];
				link.l2.go = "imperial_escort_nocapture_explanation";
			}
		break;

		case "imperial_escort_nocapture_explanation":
			NPChar.quest.imperial_escort.nocapture_explained = "true";
			dialog.text = DLG_TEXT[441];
			link.l1 = DLG_TEXT[438];
			link.l1.go = "exit";
			if(GetAttribute(NPChar, "quest.imperial_escort.trader_explained") != "true")
			{
				link.l2 = DLG_TEXT[440] + GetMyName(NPChar) + "?";
				link.l2.go = "imperial_escort_trader_explanation";
			}
		break;

		case "imperial_escort_remind_stuff":
			dialog.text = DLG_TEXT[443];
			if(!CheckAttribute(PChar, "quest.imperial_escort_get_stuff"))	// The "get_stuff" quest is not active because you already retrieved your stuff
			{
				link.l1 = DLG_TEXT[444];
				link.l1.go = "imperial_escort_no_port";
			}
			else								// The "get_stuff" quest is still active because you didn't go to the unconscious commandant
			{
				link.l1 = DLG_TEXT[445];				// Go back and get stuff
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[446];				// Don't bother with stuff
				link.l2.go = "imperial_escort_no_port";
			}
		break;

		case "imperial_escort_no_port":
			dialog.text = DLG_TEXT[447];
			link.l1 = DLG_TEXT[448];
			AddDialogExitQuest("imperial_escort_ships_impounded");
			link.l1.go = "exit";
		break;

		case "imperial_escort_kidnappers_cave":
			dialog.text = DLG_TEXT[449] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[450] + GetMyFullName(CharacterFromID("imperial_envoy")) + ".";
			link.l1.go = "imperial_escort_subdue_kidnappers";
		break;

		case "imperial_escort_subdue_kidnappers":
			dialog.text = DLG_TEXT[451];
			if(CheckCharacterItem(PChar, "pistolgas"))
			{
				link.l1 = DLG_TEXT[452];
				link.l1.go = "imperial_escort_ether_yes";
			}
			if(CheckCharacterItem(PChar, "pistolstink"))
			{
				link.l2 = DLG_TEXT[453];
				link.l2.go = "imperial_escort_stinkpot_no";
			}
			if(CheckCharacterItem(PChar, "pistolgrenade"))
			{
				link.l3 = DLG_TEXT[454];
				link.l3.go = "imperial_escort_grenade_no";
			}
			link.l4 = DLG_TEXT[455] + GetMyName(NPChar) + "?";
			link.l4.go = "imperial_escort_cave_suggestion";
		break;

		case "imperial_escort_ether_yes":
			dialog.text = DLG_TEXT[456];
			link.l1 = DLG_TEXT[457];
			AddDialogExitQuest("imperial_escort_outside_kidnap_cave2");
			link.l1.go = "exit";
		break;

		case "imperial_escort_stinkpot_no":
			dialog.text = DLG_TEXT[458];
			link.l1 = DLG_TEXT[460];
			link.l1.go = "imperial_escort_cave_suggestion";
		break;

		case "imperial_escort_grenade_no":
			dialog.text = DLG_TEXT[459];
			link.l1 = DLG_TEXT[460];
			link.l1.go = "imperial_escort_cave_suggestion";
		break;

		case "imperial_escort_cave_suggestion":
			dialog.text = DLG_TEXT[461];
			if(CheckCharacterItem(PChar, "pistolgas"))
			{
				link.l1 = DLG_TEXT[462];
				AddDialogExitQuest("imperial_escort_outside_kidnap_cave2");
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = DLG_TEXT[463];
				link.l1.go = "imperial_escort_try_havana";
			}
		break;

		case "imperial_escort_try_havana":
			dialog.text = DLG_TEXT[464];
			link.l1 = DLG_TEXT[465];
			link.l1.go = "exit_imperial_escort_havana_for_ether";
			link.l2 = DLG_TEXT[489];
			link.l2.go = "imperial_escort_cave_tactics";
		break;

		case "imperial_escort_let_me_talk":
			dialog.text = DLG_TEXT[466] + GetMyFullName(CharacterFromID("Rosa Zambrano")) + DLG_TEXT[467];
			link.l1 = DLG_TEXT[468];
			link.l1.go = "imperial_escort_trust_earned";
		break;

		case "imperial_escort_trust_earned":
			dialog.text = DLG_TEXT[469];
			if(sti(PChar.money) >= 200)
			{
				PlayStereoSound("INTERFACE\took_item.wav");
				AddMoneyToCharacter(PChar, -200);
				link.l1 = DLG_TEXT[470] + GetMyName(NPChar) + DLG_TEXT[471] + DLG_TEXT[472];
				link.l1.go = "imperial_escort_enough_money";
			}
			else
			{
				link.l1 = DLG_TEXT[470] + GetMyName(NPChar) + DLG_TEXT[471] + DLG_TEXT[473];
				link.l1.go = "imperial_escort_no_money";
			}
		break;

		case "imperial_escort_enough_money":
			dialog.text = DLG_TEXT[474] + GetMyName(PChar) + DLG_TEXT[475];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "imperial_escort_no_money":
			dialog.text = DLG_TEXT[476];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "imperial_escort_bought_ether":
			dialog.text = DLG_TEXT[477] + GetMyName(PChar) + ".";
			link.l1 = DLG_TEXT[478] + GetMyName(NPChar) + DLG_TEXT[479];
			link.l1.go = "exit";
		break;

		case "imperial_escort_cave_return":
			dialog.text = DLG_TEXT[480];
			if(CheckCharacterItem(PChar, "pistolgas"))
			{
				link.l1 = DLG_TEXT[481];
				link.l1.go = "exit";
			}
			else
			{
				link.l1 = DLG_TEXT[482];
				link.l1.go = "imperial_escort_cave_return_no_ether";
				
			}
		break;

		case "imperial_escort_cave_return_no_ether":
			dialog.text = DLG_TEXT[483];
			link.l1 = DLG_TEXT[484];
			link.l1.go = "exit";
		break;			

		case "imperial_escort_clear_air":
			dialog.text = DLG_TEXT[485];
			link.l1 = DLG_TEXT[486];
			link.l1.go = "exit";
		break;

		case "imperial_escort_in_cave_no_agent":
			dialog.text = DLG_TEXT[487];
			link.l1 = DLG_TEXT[488];
			link.l1.go = "exit";
		break;

		case "imperial_escort_cave_tactics":
			dialog.text = DLG_TEXT[490] + GetMyName(PChar) + DLG_TEXT[491];
			link.l1 = DLG_TEXT[492] + GetMyName(NPChar) + DLG_TEXT[493];
			link.l1.go = "imperial_escort_cave_tactics2";
			link.l2 = DLG_TEXT[496];
			link.l2.go = "exit_imperial_escort_no_ether";
		break;

		case "imperial_escort_cave_tactics2":
			dialog.text = DLG_TEXT[494];
			link.l1 = DLG_TEXT[495];
			PChar.quest.imperial_escort.cave_climber = NPChar.id;
			AddDialogExitQuest("imperial_escort_officer_climbs_cave");
			link.l1.go = "exit_imperial_escort_no_ether";
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

		case "exit_convoy_dispose_just_my_ship":
			AddDialogExitQuest("convoy_goto_shipyard");
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "exit_not_chosen_officer":
			if(OFFICER_MAX <= 4) logit(TranslateString("","Hint: To make an officer available to command your ship, assign that officer to one of the shore party slots."));
			else logit(TranslateString("","Hint: To make an officer available to command your ship, assign that officer to one of the first three shore party slots."));
			PChar.quest.convoy.officer_status = "need_officer";
			AddDialogExitQuest("convoy_romance_waits");
			Diag.CurrentNode = "convoy_officer_try_again";
			DialogExit();
		break;

		case "exit_silk_rejected":
			AddDialogExitQuest("reset_silk");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit_silk_approved":
			AddDialogExitQuest("romance_makes_clothes");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit_still_need_autograph":
			Diag.CurrentNode = "hunt_consider_forgery";
			DialogExit();
		break;

		case "exit_imperial_escort_no_ether":
			AddDialogExitQuest("imperial_escort_outside_kidnap_cave2");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit_imperial_escort_havana_for_ether":
			AddDialogExitQuest("imperial_escort_havana_for_ether");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}