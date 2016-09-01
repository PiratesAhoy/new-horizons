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
			Dialog.snd = "dialogs\0\009";

				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
		break;

		case "First time Redmond":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "First time Redmond2";
		break;

		case "first time Redmond2":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyFullName(PChar) + DLG_TEXT[4];
			link.l1.go = "first time Redmond3";
		break;

		case "first time Redmond3":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "Exit first time Redmond";
		break;

		case "Exit first time Redmond":
			AddDialogExitQuest("Have_to_wait_for_Beckett");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Beckett in office":
			dialog.text = DLG_TEXT[7] + Pchar.lastname + DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit Beckett in office";
		break;

		case "Exit Beckett in office":
			if(CheckQuestAttribute("Jacks_and_Beckett", "meeting_basic_quest"))
			{
			AddDialogExitQuest("First_mission_reckoning4");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			}
			else
			{
			AddDialogExitQuest("An_offer_from_Beckett");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			}
		break;

		case "In for the reckoning":
			dialog.text = DLG_TEXT[13] + Pchar.lastname + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit In for the reckoning";
		break;

		case "Exit In for the reckoning":
			AddDialogExitQuest("First_mission_reckoning4"); // was 3
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		
		case "Silas warns of fight":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit leaving";
			link.l2 = DLG_TEXT[12] + Pchar.name + " " Pchar.lastname;
			link.l2.go = "Silas warns of fight2";
		break;

		case "Silas warns of fight2":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_fight";
		break;

		case "the Muelle reckoning":
			dialog.text = DLG_TEXT[13] + Pchar.lastname + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit the Muelle reckoning";
		break;

		case "Exit the Muelle reckoning":
			AddDialogExitQuest("the_Muelle_reckoning3");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit Leaving":
			AddDialogExitQuest("Go_out_before_fight");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_fight":
			AddDialogExitQuest("Fight_in_EITC_Office3");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;


	}
}
