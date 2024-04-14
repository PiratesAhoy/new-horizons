
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
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			NextDiag.TempNode = "first time";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			//разговор с блейзом
			if (CheckQuestAttribute("smuggler_line", "begin"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "node_2";
			}
		break;
		
		case "node_2":
			dialog.text = GetMyFullName(CharacterFromID("Desmond Ray Beltrop")) + DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "node_3";
		break;
		
		case "node_3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit_smuggler_line_begin";
			link.l2 = DlG_TEXT[8];
			link.l2.go = "exit_smuggler_line_decline";
		break;


		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_smuggler_line_begin":
			AddDialogExitQuest("smuggler_line_begin_exit");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_smuggler_line_decline":
			AddDialogExitQuest("smuggler_line_not_begin_exit");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
