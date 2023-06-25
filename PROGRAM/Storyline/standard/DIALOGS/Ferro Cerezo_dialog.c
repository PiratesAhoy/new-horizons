//#include "DIALOGS\Ferro Cerezo_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

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
			Dialog.snd = "dialogs\0\009";
			
			dialog.snd = "Voice\FECE\FECE001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "search_for_Ferro_Cerezo" || pchar.quest.main_line == "search_for_Ferro_Cerezo_find")
			{
				dialog.snd = "Voice\FECE\FECE002";
				Dialog.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + GetMyName(NPChar) + DLG_TEXT[4];
				Link.l1.go = "talk_in_tavern";
			}
			if ( CheckQuestAttribute("Story_DominguesCompromat","Find") )
			{
				dialog.snd = "Voice\FECE\FECE003";
				dialog.text = DLG_TEXT[5]+GetCharacterFullName(DLG_TEXT[6])+DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8] + GetMyName(NPChar) + DLG_TEXT[9];
				Link.l1.go = "Danielle_talk_1";
			}

			NextDiag.TempNode = "first time";
		break;

		case "Danielle_talk_1":
			dialog.snd = "Voice\FECE\FECE004";
			dialog.text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Danielle_talk_2";
		break;

		case "Danielle_talk_2":
			dialog.snd = "Voice\FECE\FECE005";
			dialog.text = DLG_TEXT[12]+characters[getCharacterIndex(DLG_TEXT[13])].lastname + DLG_TEXT[14];
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP)>7 && sti(pchar.reputation)<30)
			{
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Danielle_intimidate_1";
			}
			if ( sti(PChar.rank) > 7 )
			{
				link.l2 = DLG_TEXT[16];
				link.l2.go = "Danielle_rank_1";
			}
			link.l3 = DLG_TEXT[17];
			link.l3.go = "Danielle_buy_1";
		break;

		case "Danielle_intimidate_1":
			dialog.snd = "Voice\FECE\FECE006";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19] + GetCharacterFullName(pchar.id);
			link.l1.go = "Danielle_intimidate_2";
		break;

		case "Danielle_intimidate_2":
			dialog.snd = "Voice\FECE\FECE007";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Danielle_intimidate_3";
		break;

		case "Danielle_intimidate_3":
			dialog.snd = "Voice\FECE\FECE008";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Danielle_intimidate_4";
		break;

		case "Danielle_intimidate_4":
			dialog.snd = "Voice\FECE\FECE009";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("Danielle_intimidate_FerroCerezo");
		break;

		case "Danielle_rank_1":
			dialog.snd = "Voice\FECE\FECE010";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("Danielle_rank_Domingues_compromat_complete");
		break;

		case "Danielle_buy_1":
			if (CalcCharacterSkill(pchar, SKILL_COMMERCE) > 4)
			{
				dialog.snd = "Voice\FECE\FECE011";
				dialog.text = DLG_TEXT[28];
				link.l1 = DLG_TEXT[29];
				link.l1.go = "Danielle_buy_2";
				if (sti(pchar.money >= 10000))
				{
					link.l2 = DLG_TEXT[30];
					link.l2.go = "Danielle_buy_complete";
					pchar.quest.money_to_ferro = 10000;
				}
			}
			else
			{
				dialog.snd = "Voice\FECE\FECE012";
				dialog.text = DLG_TEXT[31];
				link.l1 = DLG_TEXT[32];
				link.l1.go = "exit";
				AddDialogExitQuest("Danielle_buy_Domingues_compromat_denied");
				pchar.quest.Story_DominguesCompromat = "after_speak";
			}
		break;

		case "Danielle_buy_2":
			if (CalcCharacterSkill(pchar, SKILL_COMMERCE) > 5)
			{
				dialog.snd = "Voice\FECE\FECE013";
				dialog.text = DLG_TEXT[33];
				link.l1 = DLG_TEXT[34];
				link.l1.go = "Danielle_buy_3";
				if (sti(pchar.money >= 9000))
				{
					link.l2 = DLG_TEXT[35];
					link.l2.go = "Danielle_buy_complete";
					pchar.quest.money_to_ferro = 9000;
				}
			}
			else
			{
				dialog.snd = "Voice\FECE\FECE014";
				dialog.text = DLG_TEXT[36];
				link.l1 = DLG_TEXT[37];
				link.l1.go = "exit";
				AddDialogExitQuest("Danielle_buy_Domingues_compromat_denied");
			}
		break;

		case "Danielle_buy_3":
			if (CalcCharacterSkill(pchar, SKILL_COMMERCE) > 6)
			{
				dialog.snd = "Voice\FECE\FECE015";
				dialog.text = DLG_TEXT[38];
				link.l1 = DLG_TEXT[39];
				link.l1.go = "Danielle_money_none";
				if (makeint(pchar.money >= 8000))
				{
					link.l2 = DLG_TEXT[40];
					link.l2.go = "Danielle_buy_complete";
					pchar.quest.money_to_ferro = 8000;
				}
			}
			else
			{
				dialog.snd = "Voice\FECE\FECE016";
				dialog.text = DLG_TEXT[41];
				link.l1 = DLG_TEXT[42];
				link.l1.go = "exit";
				AddDialogExitQuest("Danielle_buy_Domingues_compromat_denied");
			}
		break;

		case "Danielle_money_none":
			dialog.snd = "Voice\FECE\FECE017";
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
			AddDialogExitQuest("Danielle_buy_Domingues_compromat_denied");
		break;

		case "Danielle_buy_complete":
			dialog.snd = "Voice\FECE\FECE018";
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			AddDialogExitQuest("Danielle_buy_Domingues_compromat_complete");
		break;

		case "talk_in_tavern":
			dialog.snd = "Voice\FECE\FECE019";
			Dialog.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "talk_in_tavern_2";
		break;

		case "talk_in_tavern_2":
			dialog.snd = "Voice\FECE\FECE020";
			dialog.text = DLG_TEXT[49] + GetMySimpleName(characters[getCharacterIndex(DLG_TEXT[50])]) + DLG_TEXT[51];
			link.l1 = DLG_TEXT[52];
			link.l1.go = "talk_in_tavern_3";
		break;

		case "talk_in_tavern_3":
			dialog.snd = "Voice\FECE\FECE021";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "talk_in_tavern_4";
		break;

		case "talk_in_tavern_4":
			dialog.snd = "Voice\FECE\FECE022";
			AddQuestRecord("search_danielle", 3);
			// DeathDaisy ->
			if(PChar.sex == "woman"){
				Preprocessor_Add("boy", XI_ConvertString("girl"));
			}
			else{
				Preprocessor_Add("boy", XI_ConvertString("boy"));
			}
			// DeathDaisy <--
			dialog.text = DLG_TEXT[55];
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) && makeint(pchar.reputation) < 30)
			{
				link.l1 = DLG_TEXT[56];
				link.l1.go = "leadership";
			}
			link.l2 = DLG_TEXT[57];
			link.l2.go = "money";
		break;

		case "leadership":
			dialog.snd = "Voice\FECE\FECE023";
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59] + GetMyFullName(PChar) + DLG_TEXT[60];
			link.l1.go = "leadership_2";
		break;

		case "leadership_2":
			dialog.snd = "Voice\FECE\FECE024";
			dialog.text = DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "leadership_3";
		break;

		case "leadership_3":
			dialog.snd = "Voice\FECE\FECE025";
			dialog.text = DLG_TEXT[63];
			link.l1 = DLG_TEXT[64];
			link.l1.go = "leadership_4";
		break;

		case "leadership_4":
			dialog.snd = "Voice\FECE\FECE026";
			dialog.text = DLG_TEXT[65];
			link.l1 = DLG_TEXT[66];
			link.l1.go = "leadership_5";
		break;

		case "leadership_5":
			dialog.snd = "Voice\FECE\FECE027";
			dialog.text = DLG_TEXT[67];
			link.l1 = DLG_TEXT[68];
			link.l1.go = "compramat_done";
			AddQuestRecord("search_danielle", 4);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 20);
			}
			else { AddPartyExp(pchar, 2000); }
		break;

		case "money":
			if (CalcCharacterSkill(pchar, SKILL_COMMERCE) > 4)
			{
				dialog.snd = "Voice\FECE\FECE028";
				dialog.text = DLG_TEXT[69];
				link.l1 = DLG_TEXT[70];
				link.l1.go = "money_2";
				if (makeint(pchar.money >= 10000))
				{
					link.l2 = DLG_TEXT[71];
					link.l2.go = "money_end";
					pchar.quest.money_to_ferro = 10000;
					if(AUTO_SKILL_SYSTEM)
					{
						AddPartyExpChar(pchar, "Leadership", 1000);
						AddPartyExpChar(pchar, "Sneak", 10);
					}
					else { AddPartyExp(pchar, 1000); }
				}
				link.l3 = DLG_TEXT[72];
				link.l3.go = "money_11";
			}	
			else
			{
				dialog.snd = "Voice\FECE\FECE029";
				dialog.text = DLG_TEXT[73];
				if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) && makeint(pchar.reputation) < 30)
				{
					link.l1 = DLG_TEXT[74];
					link.l1.go = "leadership";
				}
				link.l2 = DLG_TEXT[75];
				link.l2.go = "talk_exit";
			}
		break;

		case "money_11":
			dialog.snd = "Voice\FECE\FECE030";
			dialog.text = DLG_TEXT[76];
			link.l1 = DLG_TEXT[77];
			link.l1.go = "talk_exit";
		break;

		case "money_2":
			if (CalcCharacterSkill(pchar, SKILL_COMMERCE) > 5)
			{
				dialog.snd = "Voice\FECE\FECE031";
				dialog.text = DLG_TEXT[78];
				link.l1 = DLG_TEXT[79];
				link.l1.go = "money_3";
				if (makeint(pchar.money >= 9000))
				{
					link.l2 = DLG_TEXT[80];
					link.l2.go = "money_end";
					pchar.quest.money_to_ferro = 9000;
					if(AUTO_SKILL_SYSTEM)
					{
						AddPartyExpChar(pchar, "Leadership", 2000);
						AddPartyExpChar(pchar, "Sneak", 20);
					}
					else { AddPartyExp(pchar, 2000); }
				}
			}
			else
			{
				dialog.snd = "Voice\FECE\FECE032";
				dialog.text = DLG_TEXT[81];
				link.l1 = DLG_TEXT[82];
				link.l1.go = "talk_exit";
			}
		break;

		case "money_3":
			if (CalcCharacterSkill(pchar, SKILL_COMMERCE) > 6)
			{
				dialog.snd = "Voice\FECE\FECE033";
				dialog.text = DLG_TEXT[83];
				link.l1 = DLG_TEXT[84];
				link.l1.go = "money_none";
				if (makeint(pchar.money >= 8000))
				{
					link.l2 = DLG_TEXT[85];
					link.l2.go = "money_end";
					pchar.quest.money_to_ferro = 8000;
				}
			}
			else
			{
				dialog.snd = "Voice\FECE\FECE034";
				dialog.text = DLG_TEXT[86];
				link.l1 = DLG_TEXT[87];
				link.l1.go = "talk_exit";
			}
		break;

		case "money_none":
			dialog.snd = "Voice\FECE\FECE035";
			dialog.text = DLG_TEXT[88];
			link.l1 = DLG_TEXT[89];
			link.l1.go = "talk_exit";
		break;

		case "money_end":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -(makeint(pchar.quest.money_to_ferro)));
			GiveItem2Character(pchar, "domingues_fucked");
			pchar.quest.main_line = "compramat_done";
			AddQuestRecord("search_danielle", 5);
		break;

		case "compramat_done":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			GiveItem2Character(pchar, "domingues_fucked");
			pchar.quest.main_line = "compramat_done";
		break;

		case "talk_exit":
			dialog.snd = "Voice\FECE\FECE036";
			dialog.text = DLG_TEXT[90];
			link.l1 = DLG_TEXT[91];
			link.l1.go = "talk_in_exit_exit";
		break;

		case "talk_in_exit_2":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 4)
			{
				dialog.snd = "Voice\FECE\FECE037";
				dialog.text = DLG_TEXT[92];
				link.l1 = DLG_TEXT[93];
				link.l1.go = "talk_in_exit_3";
			}
			else
			{
				dialog.snd = "Voice\FECE\FECE038";
				dialog.text = DLG_TEXT[94];
				link.l1 = DLG_TEXT[95];
				link.l1.go = "talk_in_exit_exit";
			}
		break;

		case "talk_in_exit_3":
			dialog.snd = "Voice\FECE\FECE039";
			dialog.text = DLG_TEXT[96];
			link.l1 = DLG_TEXT[97];
			link.l1.go = "compramat_done";
			AddQuestRecord("search_danielle", 4);
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 2000);
				AddPartyExpChar(pchar, "Sneak", 20);
			}
			else { AddPartyExp(pchar, 2000); }
		break;

		case "talk_in_exit_exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("prepare_ferro_to_Sea");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
