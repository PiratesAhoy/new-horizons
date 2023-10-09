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

		case "ardent_convoy_was_here":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "be_nice";
		break;

		case "be_nice":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "where_buy";
			if (CheckCharacterItem(PChar, "potionwine"))
			{
				link.l2 = DLG_TEXT[6];
				link.l2.go = "offer_wine";
			}
			if (CheckCharacterItem(PChar, "potionrum"))
			{
				link.l3 = DLG_TEXT[7];
				link.l3.go = "offer_rum";
			}
		break;

		case "where_buy":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit_Abequa_waits";
		break;

		case "offer_wine":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[12];
			TakeItemFromCharacter(PChar, "potionwine");
			AddDialogExitQuest("convoy_to_curacao");
			link.l1.go = "exit";
		break;

		case "offer_rum":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			TakeItemFromCharacter(PChar, "potionrum");
			AddDialogExitQuest("convoy_to_curacao");
			link.l1.go = "exit";
		break;

		case "exit_Abequa_waits":
			Diag.CurrentNode = "be_nice";
			AddDialogExitQuest("convoy_Abequa_waits");
			DialogExit();
		break;
	}
}