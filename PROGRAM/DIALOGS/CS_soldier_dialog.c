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
			link.l2 = DLG_TEXT[1];
			link.l2.go = "Exit";

			if (CheckQuestAttribute("colombian_silver.status", "start") && GetAttribute(NPChar, "quest.colombian_silver.talked") != "yes" && sti(PChar.money) >= 2)
			{
				link.l1 = DLG_TEXT[2];
				link.l1.go = "join_me";
			}
		break;

		case "join_me":
			NPChar.quest.colombian_silver.talked = "yes";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			PChar.quest.colombian_silver.tavern1_friend = NPChar.id;
			AddDialogExitQuest("colombian_silver_join_soldier");
			link.l1.go = "exit";
		break;

		case "why_are_you_here":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "stuck_here1";
		break;

		case "stuck_here1":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "stuck_here2";
		break;

		case "stuck_here2":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "officers_hate_us";
		break;

		case "officers_hate_us":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			AddDialogExitQuest("colombian_silver_leave_soldier");
			link.l1.go = "exit";
		break;
	}
}