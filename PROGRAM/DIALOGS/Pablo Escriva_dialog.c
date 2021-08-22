//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
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

			Diag.TempNode = "Second time";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "Second time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			if (CheckAttribute(NPChar, "already_met"))
			{
				Preprocessor_Add("name", GetMySimpleName(PChar));
				link.l2 = DLG_TEXT[32];
				link.l2.go = "be_more_specific";
			}
		break;

		case "ask_for_document":
			Preprocessor_Add("name", GetMySimpleName(PChar));
			dialog.text = DLG_TEXT[4];
			if (CheckAttribute(NPChar, "already_met")) link.l1 = DLG_TEXT[32];
			else link.l1 = DLG_TEXT[5];
			link.l1.go = "be_more_specific";
			Diag.TempNode = "Second time";
		break;

		case "be_more_specific":
			Preprocessor_Add("ladlass", GetAddressForm(ADDR_INFORMAL, ENGLAND, chrsex(PChar)));
			if (CheckAttribute(NPChar, "already_met")) dialog.text = DLG_TEXT[33];
			else dialog.text = DLG_TEXT[6];
			if (CheckQuestAttribute("ardent_hunt_status", "need_forger"))
			{
				link.l1 = DLG_TEXT[7];
				link.l1.go = "hunt_need_signature";
			}
			if (CheckQuestAttribute("kapitein", "need_papers"))
			{
				link.l2 = DLG_TEXT[34];
				link.l2.go = "kapitein_need_papers";
			}
		break;

		case "hunt_need_signature":
			PChar.quest.ardent_hunt_status = "found_forger";
			dialog.text = DLG_TEXT[8];
			if (CheckAttribute(PChar, "quest.hunt_found_document"))
			{
				link.l1 = DLG_TEXT[9];
				link.l1.go = "hunt_need_uniform";
			}
			else
			{
				AddQuestRecord("Villain_Hunt", 19);
				link.l1 = DLG_TEXT[10];
				link.l1.go = "exit_need_autograph";
			}
		break;

		case "hunt_have_you_autograph":
			dialog.text = DLG_TEXT[11];
			if (CheckAttribute(PChar, "quest.hunt_found_document"))
			{
				link.l1 = DLG_TEXT[12];
				link.l1.go = "hunt_need_uniform";
			}
			else
			{
				link.l1 = DLG_TEXT[13];
				link.l1.go = "exit_need_autograph";
			}
		break;

		case "hunt_need_uniform":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "hunt_arrange_transfer";
			if (PChar.sex == "woman")
			{
				link.l2 = DLG_TEXT[16];
				link.l2.go = "hunt_choose_document";
			}
		break;

		case "hunt_choose_document":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "hunt_arrange_transfer";
			link.l2 = DLG_TEXT[25];
			link.l2.go = "hunt_arrange_requisition";
		break;

		case "hunt_arrange_transfer":
			PChar.quest.hunt_document_type = "transfer";
			PChar.quest.hunt_document_price = 2500;
			Preprocessor_Add("fullprice", "" + 2 * sti(PChar.quest.hunt_document_price));
			Preprocessor_Add("halfprice", PChar.quest.hunt_document_price);
			dialog.text = DLG_TEXT[17];
			if (sti(PChar.money) >= sti(PChar.quest.hunt_document_price))
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "exit_pay_up";
			}
			else
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "exit_need_money";
			}
		break;

		case "hunt_arrange_requisition":
			if (PChar.model == "Ardent_F") dialog.text = DLG_TEXT[26] + DLG_TEXT[27];
			else dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "hunt_arrange_requisition2";
		break;

		case "hunt_arrange_requisition2":
			PChar.quest.hunt_document_type = "requisition";
			PChar.quest.hunt_document_price = 3000;
			Preprocessor_Add("fullprice", "" + 2 * sti(PChar.quest.hunt_document_price));
			Preprocessor_Add("halfprice", PChar.quest.hunt_document_price);
			dialog.text = DLG_TEXT[17];
			if (sti(PChar.money) >= sti(PChar.quest.hunt_document_price))
			{
				link.l1 = DLG_TEXT[18];
				link.l1.go = "exit_pay_up";
			}
			else
			{
				link.l1 = DLG_TEXT[19];
				link.l1.go = "exit_need_money";
			}
		break;

		case "hunt_have_you_money":
			Preprocessor_Add("person", PChar.sex);
			Preprocessor_Add("halfprice", PChar.quest.hunt_document_price);
			dialog.text = DLG_TEXT[20];
			if (sti(PChar.money) >= sti(PChar.quest.hunt_document_price))
			{
				link.l1 = DLG_TEXT[21];
				link.l1.go = "exit_pay_up";
			}
			else
			{
				link.l1 = DLG_TEXT[22];
				link.l1.go = "exit_need_money";
			}
		break;

		case "hunt_document_done":
			if (CheckQuestAttribute("hunt_document_type", "requisition")) dialog.text = DLG_TEXT[29];
			else dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			NPChar.already_met = "true";
			AddDialogExitQuest("hunt_forger_document_done");
			link.l1.go = "exit";
		break;

/*		case "kapitein_ask_for_document":
			Preprocessor_Add("name", GetMySimpleName(PChar));
			dialog.text = DLG_TEXT[4];
			if (CheckAttribute(NPChar, "already_met")) link.l1 = DLG_TEXT[32];
			else link.l1 = DLG_TEXT[5];
			link.l1.go = "be_more_specific";
			Diag.TempNode = "Second time";
		break;

		case "kapitein_be_more_specific":
			Preprocessor_Add("ladlass", GetAddressForm(ADDR_INFORMAL, ENGLAND, chrsex(PChar)));
			if (CheckAttribute(NPChar, "already_met")) dialog.text = DLG_TEXT[33];
			else dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "kapitein_need_papers";
		break; */

		case "kapitein_need_papers":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			AddDialogExitQuest("kapitein_wait_three_days");
			link.l1.go = "exit";
		break;

		case "kapitein_document_done":
			dialog.text = DLG_TEXT[37];
			if (sti(PChar.money) >= 3000)
			{
				link.l1 = DLG_TEXT[38];
				link.l1.go = "kapitein_pay_up";
			}
			else
			{
				link.l1 = DLG_TEXT[22];
				link.l1.go = "exit_kapitein_need_money";
			}
		break;

		case "kapitein_pay_up":
			dialog.text = DLG_TEXT[39] + GetMyLastName(PChar) + "!";
			link.l1 = DLG_TEXT[31];
			NPChar.already_met = "true";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -3000);
			AddDialogExitQuest("kapitein_got_papers");
			link.l1.go = "exit";
		break;

		case "exit_need_autograph":
			Diag.CurrentNode = "hunt_have_you_autograph";
			DialogExit();
		break;

		case "exit_need_money":
			Diag.CurrentNode = "hunt_have_you_money";
			DialogExit();
		break;

		case "exit_pay_up":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -1 * sti(PChar.quest.hunt_document_price));
			AddDialogExitQuest("hunt_forger_come_back_tomorrow");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "exit_kapitein_need_money":
			Diag.CurrentNode = "kapitein_document_done";
			DialogExit();
		break;
	}
}