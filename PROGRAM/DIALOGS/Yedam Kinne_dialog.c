//#include "DIALOGS\Yedam Kinne_dialog.h"

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
			Dialog.snd = "voice\YEKI\YEKI001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (characters[GetCharacterIndex("Father Bernard")].quest.church_help == "to_dautch")
			{
				link.l1 = DLG_TEXT[2];
				link.l1.go = "church_help";
			}
			NextDiag.TempNode = "first time";
		break;

		case "church_help":
			Dialog.snd = "voice\YEKI\YEKI002";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "good";
			link.l2 = DLG_TEXT[5];
			link.l2.go = "bad";
		break;

		case "good":
			Dialog.snd = "voice\YEKI\YEKI003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "good_2";
		break;

		case "good_2":
			Dialog.snd = "voice\YEKI\YEKI004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "good_3";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "bad";
		break;

		case "good_3":
			Dialog.snd = "voice\YEKI\YEKI005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "good_4";
			link.l2 = DLG_TEXT[13];
			link.l2.go = "bad";
		break;

		case "good_4":
			Dialog.snd = "voice\YEKI\YEKI006";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "good_5";
		break;

		case "good_5":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 3)
			{
				Dialog.snd = "voice\YEKI\YEKI007";
				dialog.text = DLG_TEXT[16];
				if (makeint(pchar.money) >=2000)
				link.l1 = DLG_TEXT[17];
				link.l1.go = "good_6";
				if (makeint(pchar.rank) > 4)
				{
					link.l2 = DLG_TEXT[18];
					link.l2.go = "good_7";
				}
			}
			else
			{
				Dialog.snd = "voice\YEKI\YEKI008";
				dialog.text = DLG_TEXT[19];
				link.l1 = DLG_TEXT[20];
				link.l1.go = "exit";
				characters[GetCharacterIndex("Father Bernard")].quest.church_help = "dautch_denied";
				if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) > 0)
				{
					AddQuestRecord("Ammand", 9);
				}
				else
				{
					AddQuestRecord("church_help", 9);
				}
				pchar.quest.Church_help = "Yedam";  //  --Cat
			}
		break;

		case "good_6":
			Dialog.snd = "voice\YEKI\YEKI009";
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -2000);
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) > 0)
			{
				AddQuestRecord("Ammand", 10);
			}
			else
			{
				AddQuestRecord("church_help", 10);
			}
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 900);
				AddPartyExpChar(pchar, "Sneak", 500);
			}
			else { AddPartyExp(pchar, 900); }
			characters[GetCharacterIndex("Father bernard")].quest.church_help = "good_dautch";
			pchar.quest.Church_help = "Yedam";  //  --Cat
		break;

		case "good_7":
			Dialog.snd = "voice\YEKI\YEKI010";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			if(sti(GetStorylineVar(FindCurrentStoryline(), "JACK_SPARROW")) > 0)
			{
				AddQuestRecord("Ammand", 10);
			}
			else
			{
				AddQuestRecord("church_help", 10);
			}
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1200);
				AddPartyExpChar(pchar, "Sneak", 12);
			}
			else { AddPartyExp(pchar, 1200); }
			characters[GetCharacterIndex("Father bernard")].quest.church_help = "good_dautch";
			pchar.quest.Church_help = "Yedam";  //  --Cat
		break;

		case "bad":
			Dialog.snd = "voice\YEKI\YEKI011";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "bad_2";
		break;

		case "bad_2":
			Dialog.snd = "voice\YEKI\YEKI012";
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "exit";
			AddDialogExitQuest("Yedam_kinne_attack");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "return_visit":
			Dialog.snd = "voice\YEKI\YEKI001";
			NextDiag.TempNode = "return_visit";
			if (CheckAttribute(NPChar, "done_business"))
			{
				dialog.text = DLG_TEXT[43] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + DLG_TEXT[44];
				link.l1 = DLG_TEXT[45];
			}
			else
			{
				dialog.text = DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
			}
			link.l1.go = "return_visit2";
		break;

		case "return_visit2":
			dialog.text = DLG_TEXT[31];
			if (CheckAttribute(PChar, "quest.abduction_need_pass"))
			{
				link.l1 = DLG_TEXT[32];
				link.l1.go = "ardent_abduction_pass3";
			}
			if (CheckQuestAttribute("kapitein", "need_papers"))
			{
				link.l2 = DLG_TEXT[46];
				link.l2.go = "kapitein_need_papers2";
			}
			link.l3 = DLG_TEXT[42];
			link.l3.go = "exit";
		break;

		case "ardent_abduction_pass2":
			Dialog.snd = "voice\YEKI\YEKI002";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "ardent_abduction_pass3";
		break;

		case "ardent_abduction_pass3":
			Dialog.snd = "voice\YEKI\YEKI003";
			dialog.text = DLG_TEXT[33];
			if (makeint(pchar.money >= 5000))
			{
				link.l1 = DLG_TEXT[34];
				link.l1.go = "ardent_abduction_good_pass";
			}
			if (makeint(pchar.money >= 500))
			{
				link.l2 = DLG_TEXT[35];
				link.l2.go = "ardent_abduction_cheap_pass";
			}
			link.l3 = DLG_TEXT[36];
			link.l3.go = "Exit";
		break;

		case "ardent_abduction_good_pass":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5000);
			dialog.text = DLG_TEXT[37];
			AddDialogExitQuest("abduction_wait_for_pass");
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit";
			NextDiag.TempNode = "ardent_abduction_wait_for_pass";
		break;

		case "ardent_abduction_good_pass2":
			GiveItem2Character(PChar, "PrisonPass");
			NPChar.done_business = "true";
			AddQuestRecord("Abduction", 12);
			NextDiag.TempNode = "First time";
			Dialog.snd = "voice\YEKI\YEKI004";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit";
		break;

		case "ardent_abduction_cheap_pass":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -500);
			GiveItem2Character(PChar, "FakePrisonPass");
			NPChar.done_business = "true";
			AddQuestRecord("Abduction", 13);
			Dialog.snd = "voice\YEKI\YEKI004";
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit";
		break;

		case "ardent_abduction_wait_for_pass":
			NextDiag.TempNode = "ardent_abduction_wait_for_pass";
			Dialog.snd = "voice\YEKI\YEKI005";
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "Exit";
		break;

		case "kapitein_need_papers2":
			Dialog.snd = "voice\YEKI\YEKI002";
			dialog.text = DLG_TEXT[47];
			if (makeint(pchar.money >= 3000)) link.l1 = DLG_TEXT[48];
			else link.l1 = DLG_TEXT[49];
			AddDialogExitQuest("kapitein_wait_for_papers");
			NextDiag.TempNode = "kapitein_wait_for_papers";
			link.l1.go = "exit";
		break;

		case "kapitein_wait_for_papers":
			Dialog.snd = "voice\YEKI\YEKI005";
			NextDiag.TempNode = "kapitein_wait_for_papers";
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "exit";
		break;

		case "kapitein_document_done":
			dialog.text = DLG_TEXT[50];
			if (sti(PChar.money) >= 3000)
			{
				link.l1 = DLG_TEXT[51];
				link.l1.go = "kapitein_pay_up";
			}
			else
			{
				link.l1 = DLG_TEXT[49];
				link.l1.go = "exit_kapitein_need_money";
			}
		break;

		case "kapitein_pay_up":
			dialog.text = DLG_TEXT[52] + GetMyLastName(PChar) + "!";
			link.l1 = DLG_TEXT[40];
			NPChar.done_business = "true";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -3000);
			AddDialogExitQuest("kapitein_got_papers");
			link.l1.go = "exit";
		break;

		case "exit_kapitein_need_money":
			NextDiag.CurrentNode = "kapitein_document_done";
			DialogExit();
		break;
	}
}
