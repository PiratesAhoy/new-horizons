//#include "DIALOGS\Chorizo_Dialog.h"
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

			if (CheckQuestAttribute("RICARDO", "search_key"))
			{
				link.l1 = DLG_TEXT[2];
				link.l1.go = "gimmekey";
			}

			if (CheckQuestAttribute("RICARDO", "return_key"))
			{
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit_key";
			}

			link.l3 = DLG_TEXT[1];
			link.l3.go = "Exit";
		break;

		case "exit_key":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();

			AddDialogExitQuest("Ricardo_finished");
		break;

		case "gimmekey":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "Exit";
			AddDialogExitQuest("Ricardo_have_key");
		break;
	}
}