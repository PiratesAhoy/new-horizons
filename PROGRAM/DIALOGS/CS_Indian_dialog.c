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
	int medicine_aboard, medicine_required, medicine_cost, money_required;
	
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

			dialog.text = TimeGreeting() + DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "have_you_medicine":
			dialog.text = DLG_TEXT[2];
			if(GetSquadronGoods(PChar, GOOD_TREATMENT) >= 100)
			{
				link.l1 = DLG_TEXT[11];
				link.l1.go = "unload";
			}
			else
			{
				link.l1 = DLG_TEXT[3];
				if(GetSquadronGoods(PChar, GOOD_TREATMENT) == 0) link.l1 = DLG_TEXT[4];
				link.l1.go = "deal_off";
			}
			link.l2 = DLG_TEXT[5];
			link.l2.go = "new_deal";
			if(PChar.Location != PChar.location.from_sea)
			{
				link.l1.go = "where_ship";
				link.l2.go = "where_ship";
			}
		break;

		case "where_ship":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			AddDialogExitQuest("colombian_silver_reset_indians1");
			link.l1.go = "exit";
		break;

		case "deal_off":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			AddDialogExitQuest("colombian_silver_indians_leave_shore");
			link.l1.go = "exit";
		break;

		case "new_deal":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "new_deal2";
		break;

		case "new_deal2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[15];
			PChar.quest.colombian_silver.status = "not_unloaded_medicine";
			AddDialogExitQuest("colombian_silver_follow_indian1");
			link.l1.go = "exit";
		break;

		case "unload":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			AddDialogExitQuest("colombian_silver_unload_medicine");
			link.l1.go = "exit";
		break;

		case "follow_me":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			AddDialogExitQuest("colombian_silver_follow_indian1");
			link.l1.go = "exit";
		break;

		case "bitten":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "bitten2";
		break;

		case "bitten2":
			string antidote = "";
			medicine_aboard = sti(GetSquadronGoods(PChar, GOOD_TREATMENT));
			if(CheckCharacterItem(PChar, "potion3") || CheckCharacterItem(PChar, "potion3")) antidote = DLG_TEXT[19];
			dialog.text = DLG_TEXT[18] + antidote;
			if(CheckQuestAttribute("colombian_silver.status", "unloaded_medicine"))
			{
				dialog.text = dialog.text + DLG_TEXT[38];
				link.l1 = DLG_TEXT[37];
				AddDialogExitQuest("colombian_silver_heal_from_bite");
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = dialog.text + DLG_TEXT[20];
				if(medicine_aboard == 0)
				{
					link.l1 = DLG_TEXT[22];
					link.l1.go = "no_medicine";
				}
				if(medicine_aboard > 0)
				{
					link.l1 = DLG_TEXT[23] + medicine_aboard + DLG_TEXT[24];
					link.l1.go = "not_enough_medicine";
				}
				if(medicine_aboard >= 100)
				{
					link.l1 = DLG_TEXT[21];
					AddDialogExitQuest("colombian_silver_order_medicine");
					link.l1.go = "exit";
				}
			}
		break;

		case "no_medicine":
			dialog.text = DLG_TEXT[25] + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			AddDialogExitQuest("colombian_silver_poisoned");
			link.l1.go = "exit";
		break;

		case "not_enough_medicine":
			if(sti(GetSquadronGoods(PChar, GOOD_TREATMENT)) >= 50)
			{
				medicine_required = 100 - sti(GetSquadronGoods(PChar, GOOD_TREATMENT));
				medicine_cost = makeint(1.5 * GetStoreGoodsPrice(Stores[GetTownStoreIndex("Cartagena")], GOOD_TREATMENT, PRICE_TYPE_BUY, NPChar, 0));
				money_required = medicine_required * medicine_cost;
				dialog.text = DLG_TEXT[29] + DLG_TEXT[31] + money_required + DLG_TEXT[32];
				if(sti(PChar.money) >= money_required)
				{
					PChar.quest.colombian_silver.money_required = money_required;
					link.l1 = DLG_TEXT[33];
					link.l1.go = "pay_difference";
				}
				else
				{
					link.l1 = DLG_TEXT[35];
					link.l1.go = "no_pay_difference";
				}
				link.l2 = DLG_TEXT[34];
				link.l2.go = "no_pay_difference";				
			}
			if(sti(GetSquadronGoods(PChar, GOOD_TREATMENT)) < 50)
			{
				dialog.text = DLG_TEXT[29] + DLG_TEXT[30];
				link.l1 = DLG_TEXT[37];
				AddDialogExitQuest("colombian_silver_order_medicine");
				link.l1.go = "exit";
			}
			if(sti(GetSquadronGoods(PChar, GOOD_TREATMENT)) < 25)
			{
				dialog.text = DLG_TEXT[28] + DLG_TEXT[26];
				link.l1 = DLG_TEXT[27];
				AddDialogExitQuest("colombian_silver_poisoned");
				link.l1.go = "exit";
			}
		break;

		case "pay_difference":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, sti(PChar.quest.colombian_silver.money_required) * -1);
			PChar.quest.colombian_silver.status = "paid_difference";
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[37];
			AddDialogExitQuest("colombian_silver_order_medicine");
			link.l1.go = "exit";
		break;

		case "no_pay_difference":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			AddDialogExitQuest("colombian_silver_order_medicine");
			link.l1.go = "exit";
		break;

		case "back_to_jungle":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "exit";
		break;

		case "go_away":
			dialog.text = DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "exit";
		break;

		case "go_to_Spanish":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit";
		break;

		case "go_away_friend":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47];
			link.l1.go = "exit";
		break;
	}
}