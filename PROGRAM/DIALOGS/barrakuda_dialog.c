
void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	ref PChar;
	PChar = GetMainCharacter();

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			if (CheckQuestAttribute("smuggler_line", "fifth_mission_meet_with_barrakuda"))
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + ".";
				link.l1.go = "fifth_mission_meet_with_barrakuda";
			}
			if (CheckQuestAttribute("smuggler_line", "fifth_mission_wait_for_join_barrakuda"))
			{
				dialog.text = DLG_TEXT[4];
				SetCompanionIndex(PChar, -1, GetCharacterIndex("Barrakuda"));
				if (IsCompanion(NPChar))
				{
					link.l1 = DLG_TEXT[5];
					link.l1.go = "exit";
					AddDialogExitQuest("fifth_mission_accept_second");
				}
				else
				{
					link.l1 = DLG_TEXT[6];
					link.l1.go = "exit";
				}
			}
			
			NextDiag.TempNode = "First time";
		break;

		case "fifth_mission_meet_with_barrakuda":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			AddDialogExitQuest("fifth_mission_meet_with_barrakuda_2");
			link.l1.go = "exit";
		break;

		case "Exit":
			Nextdiag.CurrentNode = Nextdiag.TempNode;
			DialogExit();
		break;
	}
}
