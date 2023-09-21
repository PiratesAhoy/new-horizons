//#include "DIALOGS\Father Bernard_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	int DonationSize, iTest;
// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------
    int Rank;
    int intHealthPoints;
    int intFreeSkill;
    int intLeadership;
    int intFencing;
    int intSailing;
    int intAccuracy;
    int intCannons;
    int intGrappling;
    int intRepair;
    int intDefence;
    int intCommerce;
    int intSneak;
    int intFreePerks;
    int intMoney;
    int intResetPrice;
// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	Preprocessor_Add("Father", GetMyFirstNames(CharacterFromID("Father Bernard"), false));
	if (PChar.sex == "man") Preprocessor_Add("addr", XI_ConvertString("my son"));
	else Preprocessor_Add("addr", XI_ConvertString("my child"));
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
//			if (PChar.sex == "man") Preprocessor_Add("pronoun", XI_ConvertString("his"));
//			else Preprocessor_Add("pronoun", XI_ConvertString("her"));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounPossessive(PChar)));
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
				dialog.snd = "Voice\FATB\FATB001";
				d.Text = TimeGreeting() + DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1] + GetMyFullName(PChar) + DLG_TEXT[2] + GetMyShipNameShow(PChar) + DLG_TEXT[3];
				Link.l1.go = "meeting";
				NPC_Meeting = "1"; 
			}
			else
			{
//				if (PChar.sex == "man") Preprocessor_Add("pronoun2", XI_ConvertString("his"));
//				else  Preprocessor_Add("pronoun2", XI_ConvertString("her"));
				Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounPossessive(PChar)));
				dialog.snd1 = "Voice\FATB\FATB002";
				dialog.snd2 = "Voice\FATB\FATB003";
				dialog.snd3 = "Voice\FATB\FATB004";
				if (PChar.sex == "man") Preprocessor_Add("addr_upper", FirstLetterUp(XI_ConvertString("my son")));
				else Preprocessor_Add("addr_upper", FirstLetterUp(XI_ConvertString("my child")));
				d.Text = RandPhrase(DLG_TEXT[4] + GetMyName(Pchar) + DLG_TEXT[5], DLG_TEXT[6] + GetMyName(Pchar) + DLG_TEXT[7], DLG_TEXT[8], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = GetMyFullName(NPChar) + DLG_TEXT[9];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[10];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[11];
				Link.l3.go = "exit";
			}
		break;

		case "Meeting":
			dialog.snd = "Voice\FATB\FATB005";
				d.Text = DLG_TEXT[12] + DLG_TEXT[13] + DLG_TEXT[151] + GetMyFullName(NPChar) + DLG_TEXT[152]; // NK 04-14 //Cat
				Link.l1 = DLG_TEXT[14];
				Link.l1.go = "donation";
				Link.l2 = DLG_TEXT[15];
				Link.l2.go = "quest lines";
				Link.l3 = DLG_TEXT[16];
				Link.l3.go = "exit";
		break;


		case "quest lines":
			iTest = 0;
			dialog.snd = "Voice\FATB\FATB006";
			d.Text = DLG_TEXT[17];
			if (npchar.quest.church_help == "" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "church_help";
				iTest = iTest + 1;
			}

			if (npchar.quest.church_help != "" && npchar.quest.church_help != "to_greenford" && npchar.quest.church_help != "done" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[19];
				link.l1.go = "church_help_done";
				itest = iTest + 1;
			}

			if (npchar.quest.church_help != "" && npchar.quest.church_help == "to_greenford" && npchar.quest.church_help != "done" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[19];
				link.l1.go = "church_help_done";
				itest = iTest + 1;
			}

//			if (npchar.quest.church_help == "done" && pchar.quest.ANIMISTS == "FRIGATE_LOST")
			if (npchar.quest.church_help == "done" && CheckQuestAttribute("ANIMISTS", "FRIGATE_LOST"))
			{
				link.l1 = DLG_TEXT[20];
				link.l1.go = "ANIMISTS_letter";
			}
			if (CheckQuestAttribute("ANIMISTS", "letter_to_father_bernard"))
			{
				link.l1 = DLG_TEXT[21];
				link.l1.go = "letter_to_father_bernard";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher"))
			{
				link.l1 = DLG_TEXT[26];
				link.l1.go = "to_prison_for_teacher";
			}
			if (CheckQuestAttribute("ANIMISTS", "to_prison_for_teacher_2"))
			{
				dialog.snd = "Voice\FATB\FATB008";
				dialog.text = DLG_TEXT[27];
				link.l1 = DLG_TEXT[28];
				link.l1.go = "exit";
				AddQuestRecord("ANIMISTS", 33);		// GR: moved here from case "to_prison_for_teacher_3" so that questbook is updated when you receive letter
				GiveItem2Character(pchar, "letter_prison");
				pchar.quest.ANIMISTS = "to_prison_for_teacher_3";
			}
			if (CheckQuestAttribute("ANIMISTS", "completed") && npchar.quest.ANIMISTS != "completed")
			{
				dialog.snd = "Voice\FATB\FATB009";
				dialog.text = DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "destroyed_sekt";
			}
			if (CheckQuestAttribute("artois_line", "found_gold") && makeint(pchar.money) >=4000)
			{
				link.l3 = DLG_TEXT[31]; // NK
				link.l3.go = "exit"; // NK
				AddDialogExitQuest("artois_donate_done");
			}
			if (CheckAttribute(PChar, "quest.romance") && CheckAttribute(characterFromID(PChar.quest.romance), "married") && characters[getCharacterIndex(PChar.quest.romance)].married == MR_MARRIED && characters[getCharacterIndex(PChar.quest.romance)].married.id == characters[getCharacterIndex(PChar.quest.villain)].id && !CheckAttribute(characterFromID(PChar.quest.romance), "married.annulled") && characters[getCharacterIndex(PChar.quest.romance)].location == "Redmond_church")
			{
				Preprocessor_Add("romance", GetMyFullName(characterFromID(PChar.quest.romance)));
				Preprocessor_Add("villain", GetMyFullName(characterFromID(PChar.quest.villain)));
				link.l4 = DLG_TEXT[170];
				link.l4.go = "ardent_abduction_sad_marriage1"; // NK
			}
// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------
			if(!AUTO_SKILL_SYSTEM) // El Rapido
			{
				Link.l98 = DLG_TEXT[134];
				Link.l98.go = "ResetCharacterDialog";
			}
// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------
			Link.l99 = DLG_TEXT[32];
			Link.l99.go = "no quest";
		break;

		case "destroyed_sekt":
			if (CheckQuestAttribute("ANIMISTSZ", "children_returned"))
			{
				if(AUTO_SKILL_SYSTEM)
				{
					AddPartyExpChar(pchar, "Leadership", 7000);
					AddPartyExpChar(pchar, "Sneak", 70);
				}
				else { AddPartyExp(pchar, 7000); }
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(pchar, 15000);
				dialog.snd = "Voice\FATB\FATB010";
				dialog.text = DLG_TEXT[33];
				link.l1 = DLG_TEXT[35];
				link.l1.go = "exit";
				npchar.quest.ANIMISTS = "completed";
				CloseQuestHeader("animists");
			}
			else
			{
				if(AUTO_SKILL_SYSTEM)
				{
					AddPartyExpChar(pchar, "Leadership", 7000);
					AddPartyExpChar(pchar, "Sneak", 70);
				}
				else { AddPartyExp(pchar, 7000); }
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(pchar, 15000);
				dialog.snd = "Voice\FATB\FATB010";
				dialog.text = DLG_TEXT[33];
				link.l1 = DLG_TEXT[34];
				link.l1.go = "exit";
				npchar.quest.ANIMISTS = "completed";
				CloseQuestHeader("animists");
			}
		break;

		case "to_prison_for_teacher":
			dialog.snd = "Voice\FATB\FATB011";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "to_prison_for_teacher_2";
		break;

		case "to_prison_for_teacher_2":
			dialog.snd = "Voice\FATB\FATB012";
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "to_prison_for_teacher_3";
		break;

		case "to_prison_for_teacher_3":
			dialog.snd = "Voice\FATB\FATB013";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_prison_for_teacher_2";
			AddDialogExitQuest("wait_in_church_for_letters");
		break;

 		case "kill_all_ANIMISTS_in_churcha":  //
			dialog.text = DLG_TEXT[22] + GetCharacterFullName(DLG_TEXT[23]) + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "kill_all_ANIMISTS_in_church";
		break;	

		case "kill_all_ANIMISTS_in_church":
			dialog.snd = "Voice\FATB\FATB014";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "kill_all_ANIMISTS_in_church_2";
		break;

		case "kill_all_ANIMISTS_in_church_2":
			dialog.snd = "Voice\FATB\FATB015";
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "kill_all_ANIMISTS_in_church_3";
			AddQuestRecord("ANIMISTS", 23);
		break;

		case "kill_all_ANIMISTS_in_church_3":
			if (pchar.quest.animists == "barkue_drown")
			{
				dialog.snd = "Voice\FATB\FATB016";
				dialog.text = DLG_TEXT[45];
				link.l1 = DLG_TEXT[46];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "to_muelle_for_rumors";
			}
			else
			{
				dialog.snd = "Voice\FATB\FATB017";
				dialog.text = DLG_TEXT[47];
				link.l1 = DLG_TEXT[48];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS = "first_time_Masse";
				AddDialogExitQuest("meeting_with_Jaoquin_De_Masse");
			}
		break;

		case "letter_to_father_bernard":
			dialog.snd = "Voice\FATB\FATB019";
			dialog.text = DLG_TEXT[51] + GetCharacterFullName(DLG_TEXT[52]) + DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "letter_to_father_bernard_2";
		break;

		case "letter_to_father_bernard_2":
			dialog.snd = "Voice\FATB\FATB020";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "letter_to_father_bernard_3";
		break;

		case "letter_to_father_bernard_3":
			dialog.snd = "Voice\FATB\FATB021";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "letter_to_father_bernard_4";
		break;

		case "letter_to_father_bernard_4":
			dialog.snd = "Voice\FATB\FATB022";
			dialog.text = DLG_TEXT[157];
			link.l1 = DLG_TEXT[158];
			link.l1.go = "letter_to_father_bernard_5";  // --> Cat
		break;

		case "letter_to_father_bernard_5":
			AddDialogExitQuest("father_Gareth_stopping_us");
			dialog.snd = "Voice\FATB\FATB022";
			Preprocessor_Add("person", PChar.sex);
			dialog.text = DLG_TEXT[59];
			link.l1 = DLG_TEXT[60];
			link.l1.go = "exit";
		break;

		case "ANIMISTS_letter":
			if (makeint(pchar.reputation) >= 50)
			{
				dialog.snd = "Voice\FATB\FATB023";
				dialog.text = DLG_TEXT[61];
				link.l1 = DLG_TEXT[62];
				link.l1.go = "ANIMISTS_letter_2";
			}
			else
			{
				dialog.snd = "Voice\FATB\FATB024";
				dialog.text = DLG_TEXT[63];
				link.l1 = DLG_TEXT[64];
				link.l1.go = "exit";
			}
		break;

		case "ANIMISTS_letter_2":
			dialog.snd = "Voice\FATB\FATB025";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "ANIMISTS_letter_3";
		break;

		case "ANIMISTS_letter_3":
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];  // --> Cat
			link.l1.go = "ANIMISTS_letters_4a";
		break;
		
		case "ANIMISTS_letters_4a":
			dialog.text = DLG_TEXT[153];
			link.l1 = DLG_TEXT[154];
			link.l1.go = "ANIMISTS_letters_4";
		break;

		case "ANIMISTS_letters_4":
			dialog.snd = "Voice\FATB\FATB027";
			dialog.text = DLG_TEXT[69] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[70])]) + DLG_TEXT[72]; // <-- Cat
			link.l1 = DLG_TEXT[73];
			link.l1.go = "ANIMISTS_letters_5a";
		break;

		case "ANIMISTS_letters_5a":
			dialog.text = DLG_TEXT[159];
			link.l1 = DLG_TEXT[160];
			link.l1.go = "exit";
			npchar.quest.ANIMISTS = "letter2_padred";
			AddDialogExitQuest("Story_Gareth_deception");
		break;

		case "ANIMISTS_letters_5":
			dialog.snd = "Voice\FATB\FATB028";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "ANIMISTS_letters_6";
		break;

		case "ANIMISTS_letters_6":
			dialog.snd = "Voice\FATB\FATB029";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "ANIMISTS_letters_7";
		break;

		case "ANIMISTS_letters_7":
			dialog.snd = "Voice\FATB\FATB030";
			dialog.text = DLG_TEXT[78] + GetCharacterFullName(DLG_TEXT[79]) + DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "ANIMISTS_letters_8";
		break;
			
		case "ANIMISTS_letters_8":
			AddQuestRecord("ANIMISTS", 8);
			pchar.quest.ANIMISTS = "letter_to_domingues";
			GiveItem2Character(pchar, "letter_to_domingues");
			if (PChar.sex == "man") Preprocessor_Add("addr", XI_ConvertString("my son"));
			else Preprocessor_Add("addr", XI_ConvertString("my child"));
			dialog.text = DLG_TEXT[161];
			link.l1 = DLG_TEXT[162];
			link.l1.go = "exit";
			pchar.quest.to_muelle_for_letter.win_condition.l1 = "location";
			pchar.quest.to_muelle_for_letter.win_condition.l1.location = "IslaMuelle";
			pchar.quest.to_muelle_for_letter.win_condition = "to_muelle_for_letter";
		break;

		case "church_help_done":
			dialog.snd = "Voice\FATB\FATB031";
			dialog.text = DLG_TEXT[82];
			if (npchar.quest.church_help != "bad_dautch" && npchar.quest.church_help != "to_dautch" && npchar.quest.church_help != "after_off" && npchar.quest.church_help != "letters_1" && npchar.quest.church_help != "letters_2" && npchar.quest.church_help != "dautch_denied" && npchar.quest.church_help != "without_letters" && npchar.quest.church_help != "almost_done" && npchar.quest.church_help != "good_dautch" && npchar.quest.church_help != "good_off")
			{
				link.l1 = DLG_TEXT[84];
				link.l1.go = "exit";
			}
			if (npchar.quest.church_help == "bad_dautch" || npchar.quest.church_help == "to_dautch" || npchar.quest.church_help == "after_off" || npchar.quest.church_help == "letters_1" || npchar.quest.church_help == "letters_2" || npchar.quest.church_help == "dautch_denied" || npchar.quest.church_help == "without_letters")
			{
				link.l1 = GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[83])]) + DLG_TEXT[85];
				link.l1.go = "church_help_bad";
			}
			if ( npchar.quest.church_help == "almost_done" || npchar.quest.church_help == "good_dautch" || npchar.quest.church_help == "good_off" || npchar.quest.church_help == "without_letters")
			{
				link.l2 = GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[86])]) + DLG_TEXT[88];
				link.l2.go = "church_help_good";
			}
		break;

		case "church_help_good":
			dialog.snd = "Voice\FATB\FATB032";
			dialog.text = DLG_TEXT[89];
			if (NPChar.quest.church_help == "without_letters") link.l1 = DLG_TEXT[182] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[86])]) + DLG_TEXT[183];
			else link.l1 = DLG_TEXT[90];
			link.l1.go = "church_help_good_2";
		break;

		case "church_help_good_2":
			dialog.snd = "Voice\FATB\FATB033";
			dialog.text = DLG_TEXT[91];
			link.l1 = DLG_TEXT[92];  // <-- Cat
			link.l1.go = "exit";
//			link.l2 = DLG_TEXT[155];
//			link.l2.go = "ANIMISTS_letter_2";  // --> Cat
			AddQuestRecord("church_help", 13);
			CloseQuestHeader("church_help");
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, 2500);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 5000);
				AddPartyExpChar(pchar, "Sneak", 50);
			}
			else { AddPartyExp(pchar, 5000); }
			ChangeCharacterReputation(pchar, 5);
			ChangeCharacterAddress(characterFromID("Gilbert Ballester"), "none", "none");
			if (NPChar.quest.church_help != "without_letters") TakeItemFromCharacter(pchar, "pornushka");
			npchar.quest.church_help = "done";
			SetRumourState("Children_GreenChurch", false); // NK
			Preprocessor_Add("Father", GetMyFirstNames(CharacterFromID("Father Bernard"), false));
		break;

		case "church_help_bad":
			dialog.snd = "Voice\FATB\FATB034";
			dialog.text = DLG_TEXT[93];
			if (NPChar.quest.church_help == "without_letters") link.l1 = DLG_TEXT[184] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[86])]) + DLG_TEXT[185];
			else link.l1 = DLG_TEXT[94];
			link.l1.go = "church_help_bad_2";
		break;

		case "church_help_bad_2":
			dialog.snd = "Voice\FATB\FATB035";
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];  // <-- Cat
			link.l1.go = "exit";
//			link.l2 = DLG_TEXT[156];
//			link.l2.go = "ANIMISTS_letter_2";  // --> Cat
			AddQuestRecord("church_help", 14);
			CloseQuestHeader("church_help");
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, 2500);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 20);
			}
			else { AddPartyExp(pchar, 2000); }
			ChangeCharacterAddress(characterFromID("father jerald"), "none", "none");
			characters[GetCharacterIndex("Gilbert Ballester")].dialog.filename = "father jerald_dialog.c";
			if (NPChar.quest.church_help != "without_letters") TakeItemFromCharacter(pchar, "pornushka");
			npchar.quest.church_help = "done";
			SetRumourState("Children_GreenChurch", false); // NK
			Preprocessor_Add("Father", GetMyFirstNames(CharacterFromID("Father Bernard"), false));
		break;

		case "church_help":
			if (makeint(pchar.reputation) >= (REPUTATION_GOOD + REPUTATION_PLAIN)/2)
			{
				dialog.snd = "Voice\FATB\FATB036";
				dialog.text = DLG_TEXT[97];
				link.l1 = DLG_TEXT[98];
				link.l1.go = "church_help_2";
			}
			else
			{
				dialog.snd = "Voice\FATB\FATB037";
				dialog.text = DLG_TEXT[99];
				link.l1 = DLG_TEXT[100];
				link.l1.go = "exit";
			}
		break;

		case "church_help_2":
			dialog.snd = "Voice\FATB\FATB038";
			dialog.text = DLG_TEXT[101];
			link.l1 = DLG_TEXT[102];
			link.l1.go = "church_help_3";
		break;

		case "church_help_3":
			dialog.snd = "Voice\FATB\FATB039";
			dialog.text = DLG_TEXT[103];
			link.l1 = DLG_TEXT[104];
			link.l1.go = "church_help_4";
		break;

		case "church_help_4":
			dialog.snd = "Voice\FATB\FATB040";
			dialog.text = DLG_TEXT[105];
			link.l1 = DLG_TEXT[106];
			link.l1.go = "church_help_5";
		break;

		case "church_help_5":
			dialog.snd = "Voice\FATB\FATB041";
			dialog.text = DLG_TEXT[107] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[108])]) + DLG_TEXT[110];
			link.l1 = DLG_TEXT[111];
			link.l1.go = "church_help_6";
		break;

		case "church_help_6":
			dialog.snd = "Voice\FATB\FATB042";
			SetQuestHeader("Church_help");
			AddQuestRecord("Church_help", 1);
			npchar.quest.church_help = "to_greenford";
			Preprocessor_Add("Father", GetMyFirstNames(CharacterFromID("Father Bernard"), false));
			if (PChar.sex == "man") Preprocessor_Add("addr", XI_ConvertString("my son"));
			else Preprocessor_Add("addr", XI_ConvertString("my child"));
			dialog.text = DLG_TEXT[112];
			link.l1 = DLG_TEXT[113];
			link.l1.go = "exit";
		break;

		case "No quest":
			dialog.snd = "Voice\FATB\FATB043";
			d.Text = DLG_TEXT[114];
			Link.l1 = DLG_TEXT[115];
			Link.l1.go = "donation";
			Link.l2 = DLG_TEXT[116];
			Link.l2.go = "exit";
		break;

		case "donation":
			dialog.snd = "Voice\FATB\FATB044";
			d.Text = DLG_TEXT[117];
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "No donation";
// NK -->
			// TIH --> do once, and only up to a certain level due to limitations on game Aug29'06
			int iRepRank = 150;
			if (sti(PChar.rank) < 50) { iRepRank = makeint(sqrt(sqrt(sti(PChar.rank)^5))); }
			if(sti(PChar.money)>=500 * iRepRank)
			{
				Link.l2 = DLG_TEXT[163] + (500 * iRepRank) + DLG_TEXT[164];
				Link.l2.go = "donation paid_500";
			}
			if(sti(PChar.money)>=2500 * iRepRank)
			{
				Link.l3 = DLG_TEXT[165] + (2500 * iRepRank) + DLG_TEXT[167];
				Link.l3.go = "donation paid_2500";
			}
			if(sti(PChar.money)>=5000 * iRepRank)
			{
				Link.l4 = DLG_TEXT[166] + (5000 * iRepRank) + DLG_TEXT[167];
				Link.l4.go = "donation paid_5000";
			}
			/* prior method, broken
			if(makeint(PChar.money)>=500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{	
				Link.l2 = DLG_TEXT[163] + (500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[164];
				Link.l2.go = "donation paid_500";
			}
			if(makeint(PChar.money)>=2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{
				Link.l3 = DLG_TEXT[165] + (2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[167];
				Link.l3.go = "donation paid_2500";
			}
			if(makeint(PChar.money)>=5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{	
				Link.l4 = DLG_TEXT[166] + (5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[167];
				Link.l4.go = "donation paid_5000";
			}
			*/
			// TIH <--
		break;

		case "No donation":
			dialog.snd = "Voice\FATB\FATB045";
			d.Text = DLG_TEXT[122];
			Link.l1 = DLG_TEXT[123];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[124];
			Link.l2.go = "exit";
		break;

		case "donation paid_500":
			dialog.snd = "Voice\FATB\FATB046";
		    PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			d.Text = DLG_TEXT[125];
			Link.l1 = DLG_TEXT[126];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[127];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_2500":
			dialog.snd = "Voice\FATB\FATB046";
		    PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			d.Text = DLG_TEXT[128];
			Link.l1 = DLG_TEXT[129];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[130];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_5000":
			dialog.snd = "Voice\FATB\FATB046";
		    PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			d.Text = DLG_TEXT[131];
			Link.l1 = DLG_TEXT[132];
			Link.l1.go = "quest lines";
			Link.l2 = DLG_TEXT[133];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
// NK <--
		break;
// JRH -->
		case "shipyard_hint":
			d.Text = DLG_TEXT[168];
			Link.l1 = DLG_TEXT[169];
			Link.l1.go = "exit";
			LAi_SetPriestType(NPChar);
		break;
// <-- JRH

// GR: Ardent storyline -->
		case "ardent_abduction_sad_marriage1":
			Preprocessor_Add("romance", GetMyFullName(characterFromID(PChar.quest.romance)));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(PChar)));
			Preprocessor_Add("pronoun2", XI_ConvertString(GetMyPronounPossessive(PChar)));
		/*	if (PChar.sex == "man")
			{
				Preprocessor_Add("pronoun", XI_ConvertString("she"));
				Preprocessor_Add("pronoun2", XI_ConvertString("her"));
			}
			else
			{
				Preprocessor_Add("pronoun", XI_ConvertString("he"));
				Preprocessor_Add("pronoun2", XI_ConvertString("his"));
			}*/
			dialog.text = DLG_TEXT[171];
			link.l1 = DLG_TEXT[172];
			link.l1.go = "ardent_abduction_sad_marriage2";
		break;

		case "ardent_abduction_sad_marriage2":
			Preprocessor_Add("romance", GetMyName(CharacterFromID(PChar.quest.romance)));
//			if (PChar.sex == "man") Preprocessor_Add("pronoun", XI_ConvertString("her"));
//			else Preprocessor_Add("pronoun", XI_ConvertString("his"));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounPossessive(CharacterFromID(PChar.quest.romance))));
			dialog.text = DLG_TEXT[173];
			link.l1 = DLG_TEXT[174];
			link.l1.go = "ardent_abduction_sad_marriage3";
		break;

		case "ardent_abduction_sad_marriage3":
			if (PChar.sex == "man") Preprocessor_Add("romance_child", XI_ConvertString("my child"));
			else Preprocessor_Add("romance_child", XI_ConvertString("my son"));
			dialog.text = DLG_TEXT[175];
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("abduction_confession_interlude");
		break;

		case "ardent_abduction_story_checks_out":
			Preprocessor_Add("romance", GetMyName(characterFromID(PChar.quest.romance)));
//			if (PChar.sex == "man") Preprocessor_Add("pronoun", XI_ConvertString("she"));
//			else Preprocessor_Add("pronoun", XI_ConvertString("he"));
			Preprocessor_Add("pronoun", XI_ConvertString(GetMyPronounSubj(CharacterFromID(PChar.quest.romance))));
			dialog.text = DLG_TEXT[176];
			link.l1 = DLG_TEXT[178];
			link.l1.go = "ardent_abduction_story_checks_out2";
		break;

		case "ardent_abduction_story_checks_out2":
			dialog.text = DLG_TEXT[179];
			link.l1 = "...";
			link.l1.go = "exit";
			AddDialogExitQuest("abduction_romance_will_pay");
		break;

		case "ardent_abduction_write_to_rome":
			Preprocessor_Add("romance", GetMyName(characterFromID(PChar.quest.romance)));
			Preprocessor_Add("villain", GetMyName(characterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[180];
			link.l1 = DLG_TEXT[181];
			link.l1.go = "exit";
		break;
// <-- GR: Ardent storyline

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- start -----------
		case "ResetCharacterDialog":
             intMoney = makeint(PChar.money);
             if(!CheckAttribute(PChar,"ResetCount")) 
             {
                PChar.ResetCount        = 1;
                PChar.ResetCount.Skills = 0;
                PChar.ResetCount.Perks  = 0;
             }
             else
             {
		  if(sti(PChar.ResetCount) > 10000000) PChar.ResetCount = sti(PChar.ResetCount) + 10; // NK bugfix 05-04-19
                else PChar.ResetCount        = sti(PChar.ResetCount) * 10;
                PChar.ResetCount.Skills = sti(PChar.ResetCount.Skills) +1;
                if (sti(PChar.ResetCount.Skills) > 1)
                {
                    PChar.ResetCount.Perks  = sti(PChar.ResetCount.Skills) -1;
                }
             }
             intResetPrice = 5000 * sti(PChar.ResetCount);
			 if(intResetPrice < 0) intResetPrice = intMoney; // NK bugfix for <0 05-04-19
             if(intMoney > intResetPrice)
             {
                switch(PChar.ResetCount.Skills)
                 {
                        case "0":
                            d.Text = DLG_TEXT[135] + 
                                     intResetPrice + 
                                     DLG_TEXT[136]
                                     ;
    		            break;
                        
                        case "1":
                            d.Text = DLG_TEXT[137] + 
                                     PChar.ResetCount.Skills + 
                                     DLG_TEXT[138] +
                                     DLG_TEXT[142] +
                                     intResetPrice + 
                                     DLG_TEXT[143]
                                     ;
    		            break;
                        
                        case "2":
                            d.Text = DLG_TEXT[137] + 
                                     PChar.ResetCount.Skills + 
                                     DLG_TEXT[139] +
                                     PChar.ResetCount.Perks + 
                                     DLG_TEXT[140] +
                                     DLG_TEXT[142] +
                                     intResetPrice + 
                                     DLG_TEXT[143]
                                     ;
    		            break;
                        
                        //default:
                            d.Text = DLG_TEXT[137] + 
                                     PChar.ResetCount.Skills + 
                                     DLG_TEXT[139] +
                                     PChar.ResetCount.Perks + 
                                     DLG_TEXT[141] +
                                     DLG_TEXT[142] +
                                     intResetPrice + 
                                     DLG_TEXT[143]
                                     ;
    		            break;
                 }
                Link.l1    = DLG_TEXT[144];
                Link.l1.go = "ResetCharacter";
                Link.l2    = DLG_TEXT[145];
                Link.l2.go = "exit";
             }
             else
             {
		if (PChar.sex == "man") Preprocessor_Add("addr_upper", FirstLetterUp(XI_ConvertString("my son")));
		else Preprocessor_Add("addr_upper", FirstLetterUp(XI_ConvertString("my child")));
                d.Text     = DLG_TEXT[148] +
                             intResetPrice + 
                             DLG_TEXT[149]
                             ;
                Link.l1    = DLG_TEXT[150];
                Link.l1.go = "exit";
             }
		break;

	case "ResetCharacter":
        intMoney      = sti(PChar.money) - intResetPrice;
        if (intMoney < 0) 
        {
            intMoney = 0;
        }
        PChar.money   = intMoney;
        intLeaderShip = PChar.skill.Leadership;
        intFencing    = PChar.skill.Fencing;
        intSailing    = PChar.skill.Sailing;
        intAccuracy   = PChar.skill.Accuracy;
        intCannons    = PChar.skill.Cannons;
        intGrappling  = PChar.skill.Grappling;
        intRepair     = PChar.skill.Repair;
        intDefence    = PChar.skill.Defence;
        intCommerce   = PChar.skill.Commerce;
        intSneak      = PChar.skill.Sneak;
        intFreeSkill  = makeint(PChar.skill.freeskill) -
                        makeint(PChar.ResetCount.Skills) +
                          intLeaderShip + 
                          intFencing + 
                          intSailing + 
                          intAccuracy + 
                          intCannons + 
                          intGrappling + 
                          intRepair + 
                          intDefence + 
                          intCommerce + 
                          intSneak - 
                          10;
        if (intFreeSkill < 0) 
        {
            intFreeSkill = 0;
        }
        PChar.skill.freeskill  = intFreeSkill;
        PChar.skill.Leadership = "1";
        PChar.skill.Fencing    = "1";
        PChar.skill.Sailing    = "1";
        PChar.skill.Accuracy   = "1";
        PChar.skill.Cannons    = "1";
        PChar.skill.Grappling  = "1";
        PChar.skill.Repair     = "1";
        PChar.skill.Defence    = "1";
        PChar.skill.Commerce   = "1";
        PChar.skill.Sneak      = "1";
        intFreePerks           = sti(PChar.perks.freepoints) -
                                 sti(PChar.ResetCount.Perks);
        if ( IsCharacterPerkOn(PChar,"BasicDefence") )            { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"AdvancedDefence") )         { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"Toughness") )               { intFreePerks++; } // El Rapido
        if ( IsCharacterPerkOn(PChar,"SwordplayProfessional") )   { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"Rush") )                    { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"CriticalHit") )             { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"Gunman") )                  { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"GunProfessional") )         { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"FastReload") )              { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"ImmediateReload") )         { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"HullDamageUp") )            { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"SailsDamageUp") )           { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"CrewDamageUp") )            { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"CriticalShoot") )           { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"LongRangeShoot") )          { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"CannonProfessional") )      { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"LongRangeGrappling") )      { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"MusketsShoot") )            { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"GrapplingProfessional") )   { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"InstantBoarding") )         { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"BasicDamageControl") )        { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"AdvancedDamageControl") )     { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"ProfessionalDamageControl") ) { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"BasicFirstAid") )		  { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"AdvancedFirstAid") )	  { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"Rigging") )        	  { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"RiggingAdvance") )          { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"LightRepair") )             { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"InstantRepair") )           { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"ShipSpeedUp") )             { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"ShipTurnRateUp") )          { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"StormProfessional") )       { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"Turn180") )                 { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"SandbankManeuver") )        { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"SailingProfessional") )     { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"IronWill") )                { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"SharedExperience") )        { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"Brander") )                 { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"Troopers") )                { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"Trustworthy") )             { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"BasicCommerce") )           { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"AdvancedCommerce") )        { intFreePerks++; }
        if ( IsCharacterPerkOn(PChar,"BasicLandOwner") )          { intFreePerks++; }
        if (intFreePerks < 0) 
        {
            intFreePerks = 0;
        }
        PChar.perks.freepoints = intFreePerks;
        
        DeleteAttribute(PChar,"perks.list.BasicDefence");
        DeleteAttribute(PChar,"perks.list.AdvancedDefence");
        DeleteAttribute(PChar,"perks.list.Toughness"); // El Rapido
        DeleteAttribute(PChar,"perks.list.SwordplayProfessional");
        DeleteAttribute(PChar,"perks.list.Rush");
        DeleteAttribute(PChar,"perks.list.CriticalHit");
        DeleteAttribute(PChar,"perks.list.Gunman");
        DeleteAttribute(PChar,"perks.list.GunProfessional");
        DeleteAttribute(PChar,"perks.list.FastReload");
        DeleteAttribute(PChar,"perks.list.ImmediateReload");
        DeleteAttribute(PChar,"perks.list.HullDamageUp");
        DeleteAttribute(PChar,"perks.list.SailsDamageUp");
        DeleteAttribute(PChar,"perks.list.CrewDamageUp");
        DeleteAttribute(PChar,"perks.list.CriticalShoot");
        DeleteAttribute(PChar,"perks.list.LongRangeShoot");
        DeleteAttribute(PChar,"perks.list.CannonProfessional");
        DeleteAttribute(PChar,"perks.list.LongRangeGrappling");
        DeleteAttribute(PChar,"perks.list.MusketsShoot");
        DeleteAttribute(PChar,"perks.list.GrapplingProfessional");
        DeleteAttribute(PChar,"perks.list.InstantBoarding");
        DeleteAttribute(PChar,"perks.list.BasicDamageControl");
        DeleteAttribute(PChar,"perks.list.AdvancedDamageControl");
        DeleteAttribute(PChar,"perks.list.ProfessionalDamageControl");
        DeleteAttribute(PChar,"perks.list.BasicFirstAid");
        DeleteAttribute(PChar,"perks.list.AdvancedFirstAid");
        DeleteAttribute(PChar,"perks.list.Rigging");
        DeleteAttribute(PChar,"perks.list.RiggingAdvance");
        DeleteAttribute(PChar,"perks.list.LightRepair");
        DeleteAttribute(PChar,"perks.list.InstantRepair");
        DeleteAttribute(PChar,"perks.list.ShipSpeedUp");
        DeleteAttribute(PChar,"perks.list.ShipTurnRateUp");
        DeleteAttribute(PChar,"perks.list.StormProfessional");
        DeleteAttribute(PChar,"perks.list.Turn180");
        DeleteAttribute(PChar,"perks.list.SandbankManeuver");
        DeleteAttribute(PChar,"perks.list.SailingProfessional");
        DeleteAttribute(PChar,"perks.list.IronWill");
        DeleteAttribute(PChar,"perks.list.SharedExperience");
        DeleteAttribute(PChar,"perks.list.Brander");
        DeleteAttribute(PChar,"perks.list.Troopers");
        DeleteAttribute(PChar,"perks.list.Trustworthy");
        DeleteAttribute(PChar,"perks.list.BasicCommerce");
        DeleteAttribute(PChar,"perks.list.AdvancedCommerce");
        DeleteAttribute(PChar,"perks.list.BasicLandOwner");
        
        Rank = PChar.rank;
        // um, huh? This gives pchar WAY more health than even the max-difficulty enemies get per level!
        // for now, commenting it out. NK 05-07-08
        /*intHealthPoints = 50 + (Rank * (4 + GetDifficulty() + ((GetDifficulty()-1)*4)));
        LAi_SetHP(PChar,LAi_GetCharacterHP(PChar),makefloat(intHealthPoints));*/
        ResetHP(&PChar);
	Preprocessor_Add("person", XI_ConvertString(PChar.sex));
        d.Text     = DLG_TEXT[146];
        Link.l1    = DLG_TEXT[147];
        Link.l1.go = "ExitToCharacterSheet";
    break;

    case "ExitToCharacterSheet":
        DialogExit();			
		LaunchCharacter(PChar);
	break;
// -- Scheffnow -- 2004-01-14 -- ResetCharacterMod -- end -------------


		
	}
}
