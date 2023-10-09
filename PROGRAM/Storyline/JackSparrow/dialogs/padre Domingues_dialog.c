//#include "DIALOGS\padre Domingues_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

	ref PChar;
	PChar = GetMainCharacter();

	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\PADO\PADO001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[2];
			link.l2.go = "donation";
			link.l99 = DLG_TEXT[3];
			link.l99.go = "exit";
			NextDiag.TempNode = "first time";
		break;

		case "quests":
			iTest = 0;
			Dialog.snd = "voice\PADO\PADO002";
			dialog.text = DLG_TEXT[4];
			if (pchar.quest.main_line == "danielle_speak_with_almost_dead_rheims_complete" && iTest < QUEST_COUNTER)
			{
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "blaze_to_library";
				iTest = iTest + 1;
			}
			if (pchar.quest.main_line == "compramat_done" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[6];
				link.l1.go = "compramat_done";
				ChangeCharacterReputation(pchar, -1);
			}
			if (pchar.quest.main_line == "compramat_bul_bul" && iTest < QUEST_COUNTER)
			{
				link.l1 = DLG_TEXT[7];
				link.l1.go = "compramat_bul_bul";
			}
			if (CheckQuestAttribute("ANIMISTS", "letter_to_domingues"))
			{
				link.l1 = DLG_TEXT[8];
				link.l1.go = "letter_good";
				TakeItemFromCharacter(pchar, "letter_to_domingues");
			}
			if (CheckQuestAttribute("ANIMISTS", "letter_to_domingues_opened"))
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "letter_bad";
			}
			if (CheckQuestAttribute("ANIMISTS", "barkue_drown"))
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "barkue_drown";
				LAi_SetStayType(characterFromID("father Bernard"));
			}
			if (CheckQuestAttribute("ANIMISTS","to_barkue_complete"))
			{
				link.l1 = DLG_TEXT[11];
				link.l1.go = "to_barkue_complete";
				RemoveCharacterCompanion(pchar, characterFromID("Mergildo Hurtado"));
				ChangeCharacterAddress(characterFromID("Mergildo Hurtado"), "none", "");
			LAi_SetStayType(characterFromID("father Bernard"));
			}
			link.l99 = DLG_TEXT[12];
			link.l99.go = "exit";
		break;

		case "to_barkue_complete":
			Dialog.snd = "voice\PADO\PADO003";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "to_barkue_complete_2";
		break;

		case "to_barkue_complete_2":
			Dialog.snd = "voice\PADO\PADO004";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "to_barkue_complete_3";
		break;

		case "to_barkue_complete_3":
			Dialog.snd = "voice\PADO\PADO005";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "to_barkue_complete_4";
		break;
		
		case "to_barkue_complete_4":
			dialog.text = DLG_TEXT[118];
			link.l1 = DLG_TEXT[119];
			link.l1.go = "to_barkue_complete_5";
		break;
		
		case "to_barkue_complete_5":
			dialog.text = DLG_TEXT[120];
			link.l1 = DLG_TEXT[121];
			link.l1.go = "to_barkue_complete_6";
		break;

		case "to_barkue_complete_6":
			Dialog.snd = "voice\PADO\PADO006";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "to_bernard_2";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 3500);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2500);
				AddPartyExpChar(pchar, "Sneak", 25);
			}
			else { AddPartyExp(pchar, 2500); }
			AddQuestRecord("Sao Feng", 19);
		break;

		case "barkue_drown":
			Dialog.snd = "voice\PADO\PADO007";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "barkue_drown_2";
		break;

		case "barkue_drown_2":
			Dialog.snd = "voice\PADO\PADO008";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "to_bernard";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 2500);
			AddQuestRecord("Sao Feng", 18);
		break;

		case "to_bernard":
			Dialog.snd = "voice\PADO\PADO009";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "to_bernard_a";
		break;
		
		case "to_bernard_a":
			dialog.text = DLG_TEXT[122];
			link.l1 = DLG_TEXT[123];
			link.l1.go = "to_bernard_b";
		break;
		
		case "to_bernard_b":
			dialog.text = DLG_TEXT[124];
			link.l1 = DLG_TEXT[125];
			link.l1.go = "to_bernard_c";
		break;
		
		case "to_bernard_c":
			dialog.text = DLG_TEXT[126];
			link.l1 = DLG_TEXT[127];
			link.l1.go = "to_bernard_2";
		break;

		case "to_bernard_2":
			Dialog.snd = "voice\PADO\PADO010";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "to_bernard_3";
		break;

		case "to_bernard_3":
			Dialog.snd = "voice\PADO\PADO011";
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "letter_to_father_bernard";
			AddDialogExitQuest("oops_ANIMISTS_want_letter_again");
			GiveItem2Character(pchar, "letter_to_bernard");
			AddQuestRecord("Sao Feng", 20);
		break;

		case "letter_good":
			Dialog.snd = "voice\PADO\PADO012";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "letter_good_2";
		break;

		case "letter_bad":
			Dialog.snd = "voice\PADO\PADO013";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "letter_bad_exit";
			link.l2 = DLG_TEXT[35];
			link.l2.go = "letter_bad_2";
		break;

		case "letter_bad_2":
			Dialog.snd = "voice\PADO\PADO014";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "letter_bad_3";
		break;

		case "letter_bad_3":
			Dialog.snd = "voice\PADO\PADO015";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "prepare_for_bark";
			ChangeCharacterReputation(pchar, -5);
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 1000);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1500);
				AddPartyExpChar(pchar, "Sneak", 15);
			}
			else { AddPartyExp(pchar, 1500); }
			AddQuestRecord("Sao Feng", 12);
		break;

		case "letter_bad_exit":
			Dialog.snd = "voice\PADO\PADO016";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "letter_bad_exit_2";
			link.l2 = DLG_TEXT[42];
			link.l2.go = "letter_bad_2";
		break;

		case "letter_bad_exit_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			
			ChangeCharacterReputation(pchar, -15);
			AddQuestRecord("Sao Feng", 13);
			CloseQuestheader("Sao Feng");
		break;

		case "letter_good_2":
			Dialog.snd = "voice\PADO\PADO017";
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44] + GetcharacterFullname(DLG_TEXT[45]) + DLG_TEXT[46];
			link.l1.go = "letter_good_3";
		break;

		case "letter_good_3":
			Dialog.snd = "voice\PADO\PADO018";
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "letter_good_4";
		break;

		case "letter_good_4":
			Dialog.snd = "voice\PADO\PADO019";
			dialog.text = DLG_TEXT[49] + GetcharacterFullname(DLG_TEXT[50]) + DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "letter_good_5";
		break;

		case "letter_good_5":
			Dialog.snd = "voice\PADO\PADO020";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "prepare_for_bark";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 2000);
			ChangeCharacterReputation(pchar, 1);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1700);
				AddPartyExpChar(pchar, "Sneak", 17);
			}
			else { AddPartyExp(pchar, 1700); }
		break;

		case "prepare_for_bark":
			Dialog.snd = "voice\PADO\PADO021";
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "prepare_for_bark_2";
		break;

		case "prepare_for_bark_2":
			Dialog.snd = "voice\PADO\PADO022";
			dialog.text = DLG_TEXT[57];
			link.l1 = DLG_TEXT[58];
			link.l1.go = "prepare_for_bark_3";
		break;

		case "prepare_for_bark_3":
			Dialog.snd = "voice\PADO\PADO023";
			dialog.text = DLG_TEXT[59] + GetCharacterFullName(DLG_TEXT[60]) + DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_barkue";
			AddDialogExitQuest("prepare_for_barkue");
		break;
		
		case "Domingues_in_cave":
			dialog.text = DLG_TEXT[128];
			link.l1 = DLG_TEXT[129];
			link.l1.go = "Domingues_in_cave2";
		break;

		case "Domingues_in_cave2":
			if (CheckQuestAttribute("ANIMISTS","comp"))
			{
				dialog.text = DLG_TEXT[130];
				link.l1 = DLG_TEXT[133];
				link.l1.go = "Domingues_in_cave3";
			}
			else
			{
				dialog.text = DLG_TEXT[136];
				link.l1 = DLG_TEXT[137];
				link.l1.go = "exit";
				AddDialogExitQuest("Domingues_warning");
			}
		break;
		
		case "Domingues_in_cave3":
			dialog.text = DLG_TEXT[134];
			link.l1 = DLG_TEXT[135];
			link.l1.go = "exit";
			pchar.girls = "1";
			//AddDialogExitQuest("Story_Domingues_released");
		break;

		case "Thank_You":
			dialog.text = DLG_TEXT[143];
			link.l1 = DLG_TEXT[144];
			link.l1.go = "exit";
			AddDialogExitQuest("return_priest_complete3");
		break;

		case "compramat_bul_bul":
			Dialog.snd = "voice\PADO\PADO024";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "compramat_bul_bul_2";
		break;

		case "compramat_bul_bul_2":
			Dialog.snd = "voice\PADO\PADO025";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "compramat_bul_bul_3";
		break;

		case "compramat_bul_bul_3":
			Dialog.snd = "voice\PADO\PADO026";
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "compramat_bul_bul_4";
		break;

		case "compramat_bul_bul_4":
			Dialog.snd = "voice\PADO\PADO027";
			dialog.text = DLG_TEXT[69];
			link.l1 = DLG_TEXT[70];
			link.l1.go = "library";
		break;

		case "compramat_done":
			Dialog.snd = "voice\PADO\PADO028";
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			link.l1.go = "compramat_done_2";
			link.l2 = DLG_TEXT[73];
			link.l2.go = "compramat_not_done";
		break;

		case "compramat_not_done":
			Dialog.snd = "voice\PADO\PADO029";
			dialog.text = DLG_TEXT[74];
			link.l1 = DLG_TEXT[75];
			link.l1.go = "compramat_not_done_2";
		break;

		case "compramat_not_done_2":
			Dialog.snd = "voice\PADO\PADO030";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "compramat_not_done_3";
		break;

		case "compramat_not_done_3":
			Dialog.snd = "voice\PADO\PADO031";
			dialog.text = DLG_TEXT[78];
			link.l1 = DLG_TEXT[79];
			link.l1.go = "compramat_not_done_4";
		break;

		case "compramat_not_done_4":
			Dialog.snd = "voice\PADO\PADO032";
			dialog.text = DLG_TEXT[80];
			link.l1 = DLG_TEXT[81];
			link.l1.go = "compramat_done_3";
			ChangeCharacterReputation(pchar, -3);
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, 5000);
		break;

		case "compramat_done_2":
			Dialog.snd = "voice\PADO\PADO033";
			dialog.text = DLG_TEXT[82];
			link.l1 = DLG_TEXT[83];
			link.l1.go = "compramat_done_3";
		break;

		case "compramat_done_3":
			Dialog.snd = "voice\PADO\PADO034";
			dialog.text = DLG_TEXT[84];
			link.l1 = DLG_TEXT[85];
			link.l1.go = "library";
		break;

		case "library":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("come_to_library");
		break;

		case "blaze_to_library":
			Dialog.snd = "voice\PADO\PADO035";
			Dialog.Text = DLG_TEXT[86];
			Link.l1 = DLG_TEXT[87];
			Link.l1.go = "blaze_to_library_2";
		break;

		case "blaze_to_library_2":
			Dialog.snd = "voice\PADO\PADO036";
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "blaze_to_library_3";
		break;

		case "blaze_to_library_3":
			Dialog.snd = "voice\PADO\PADO037";
			dialog.text = DLG_TEXT[90] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[91])]) + DLG_TEXT[93];
			link.l1 = DLG_TEXT[94];
			link.l1.go = "blaze_to_library_4";
		break;

		case "blaze_to_library_4":
			Dialog.snd = "voice\PADO\PADO038";
			dialog.text = DLG_TEXT[95];
			link.l1 = DLG_TEXT[96];
			link.l1.go = "blaze_to_library_5";
		break;

		case "blaze_to_library_5":
			Dialog.snd = "voice\PADO\PADO039";
			dialog.text = DLG_TEXT[97];
			link.l1 = DLG_TEXT[98];
			link.l1.go = "blaze_to_library_6";
		break;

		case "blaze_to_library_6":
			Dialog.snd = "voice\PADO\PADO040";
			dialog.text = DLG_TEXT[99];
			link.l1 = DLG_TEXT[100];
			link.l1.go = "exit";
			AddDialogExitQuest("prepare_for_meet_ferro");
		break;
		
		case "donation":
			Dialog.snd = "voice\PADO\PADO041";
			dialog.Text = DLG_TEXT[101];
			Link.l1 = DLG_TEXT[102];
			Link.l1.go = "No donation";
// NK -->
			// TIH --> do once, and only up to a certain level due to limitations on game Aug29'06
			int iRepRank = 150;
			if (sti(PChar.rank) < 50) { iRepRank = makeint(sqrt(sqrt(sti(PChar.rank)^5))); }
			if(sti(PChar.money)>=500 * iRepRank)
			{
				Link.l2 = DLG_TEXT[138] + (500 * iRepRank) + DLG_TEXT[139];
				Link.l2.go = "donation paid_500";
			}
			if(sti(PChar.money)>=2500 * iRepRank)
			{
				Link.l3 = DLG_TEXT[140] + (2500 * iRepRank) + DLG_TEXT[141];
				Link.l3.go = "donation paid_2500";
			}
			if(sti(PChar.money)>=5000 * iRepRank)
			{
				Link.l4 = DLG_TEXT[142] + (5000 * iRepRank) + DLG_TEXT[141];
				Link.l4.go = "donation paid_5000";
			}
			/* prior method, broken
			if(makeint(PChar.money)>=500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{	
				Link.l2 = DLG_TEXT[138] + (500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[139];
				Link.l2.go = "donation paid_500";
			}
			if(makeint(PChar.money)>=2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{
				Link.l3 = DLG_TEXT[140] + (2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[141];
				Link.l3.go = "donation paid_2500";
			}
			if(makeint(PChar.money)>=5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{	
				Link.l4 = DLG_TEXT[142] + (5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[141];
				Link.l4.go = "donation paid_5000";
			}
			*/
			// TIH <--
		break;

		case "No donation":
			Dialog.snd = "voice\PADO\PADO042";
			dialog.Text = DLG_TEXT[106];
			Link.l1 = DLG_TEXT[107];
			Link.l1.go = "quests";
			Link.l2 = DLG_TEXT[108];
			Link.l2.go = "exit";
		break;

		case "donation paid_500":
			Dialog.snd = "voice\PADO\PADO043";
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.Text = DLG_TEXT[109];
			Link.l1 = DLG_TEXT[110];
			Link.l1.go = "quests";
			Link.l2 = DLG_TEXT[111];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_2500":
			Dialog.snd = "voice\PADO\PADO043";
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.Text = DLG_TEXT[112];
			Link.l1 = DLG_TEXT[113];
			Link.l1.go = "quests";
			Link.l2 = DLG_TEXT[114];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_5000":
			Dialog.snd = "voice\PADO\PADO043";
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.Text = DLG_TEXT[115];
			Link.l1 = DLG_TEXT[116];
			Link.l1.go = "quests";
			Link.l2 = DLG_TEXT[117];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
// NK <--
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
