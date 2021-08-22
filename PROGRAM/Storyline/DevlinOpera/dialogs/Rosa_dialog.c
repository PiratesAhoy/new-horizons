//#include "DIALOGS\Rosa_Dialog.h"
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
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "2";
		break;

		case "2":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "3";
		break;

		case "3":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("Scavenger_hunt_to_Beach");
		break;

		case "Rosaprog":
			dialog.text = DLG_TEXT[06];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exitprog";
		break;

		case "exitprog":
			Dialog.CurrentNode = "Rosaprog";		
			DialogExit();
		break;
	}
}