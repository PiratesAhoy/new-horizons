//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	int money;

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

		case "meet_Doolin":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "not_a_pirate";
		break;

		case "not_a_pirate":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "choices";
		break;

		case "choices":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "on_our_way";
			if (checkquestattribute("alignment", "good") && checkquestattribute("payroll_ship", "success"))
			{
				link.l2 = DLG_TEXT[8];
				link.l2.go = "free_meal";
			}
			if (checkquestattribute("alignment", "evil"))
			{
				link.l2 = DLG_TEXT[11];
				link.l2.go = "steal_boat";
			}
		break;

		case "on_our_way":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, -50);
			AddDialogExitQuest("sail_with_doolin");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "free_meal":
			ChangeCharacterReputation(PChar, 2);
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			AddDialogExitQuest("sail_with_doolin");
		break;

		case "steal_boat":
			ChangeCharacterReputation(PChar, -2);
			AddDialogExitQuest("steal_doolins_boat");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "sell_fish":
			dialog.text = DLG_TEXT[12] + GetMyName(Pchar) + DLG_TEXT[13];
			if(CheckAttribute(PChar,"money")) money = makeint(PChar.money);
			else money = 0;
			if (money >= 20)
			{
				link.l1 = DLG_TEXT[14];
				link.l1.go = "buy_fish";
			}
			link.l2 = DLG_TEXT[15];
			link.l2.go = "exit_fish";
		break;

		case "buy_fish":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "buy_fish2";
		break;

		case "buy_fish2":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -20);
			AddCharacterGoods(PChar, GOOD_WHEAT, 2);
			if (isofficer(characterFromID("Two Dogs"))) AddDialogExitQuest("bass_joke");
			Diag.CurrentNode = "sell_fish";
			DialogExit();
		break;

		case "exit_fish":
			Diag.CurrentNode = "sell_fish";
			DialogExit();
		break;
		
	}
}