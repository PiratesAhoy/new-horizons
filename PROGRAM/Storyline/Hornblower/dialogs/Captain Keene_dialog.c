
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
	string voice_path = "VOICE\ENGLISH\";
	if (CheckDirectory("RESOURCE\Sounds\VOICE\"+LanguageGetLanguage()+"\","*") > 0) voice_path = "VOICE\" + LanguageGetLanguage() + "\";

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			if (pchar.quest.My_First_ship == "meet the captain")
			{
			link.l1.go = "First_orders";
			}
			else
			{
			link.l1.go = "Exit";
			}
			Diag.TempNode = "first time";
		break;

		case "First_orders":
			dialog.text = DLG_TEXT[2] + GetMyLastName(PChar);
			link.l1 = DLG_TEXT[3];
			link.l1.go = "First_orders2";
		break;

		case "First_orders2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "First_orders3";
		break;

		case "First_orders3":
			PlaySound(voice_path + "Keene02.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_First_orders";
		break;

		case "Board_at_Charlestown":
			PlaySound(voice_path + "Keene01.wav");
			dialog.text = DLG_TEXT[17];
			link.l1.go = "Board_at_Charlestown1";
		break;

		case "Board_at_Charlestown1":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Board_at_Charlestown2";
		break;

		case "Board_at_Charlestown2":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Board_at_Charlestown3";
		break;

		case "Board_at_Charlestown3":
			PlaySound(voice_path + "Keene03.wav");
			dialog.text = DLG_TEXT[18];
			link.l1.go = "Exit_Board_at_Charlestown";
		break;

		case "issue_sailing_orders":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "issue_sailing_orders2";
		break;

		case "issue_sailing_orders2":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Exit_issue_sailing_orders";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_First_orders":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Leave_the_ship_Justinian");
		break;

		case "Exit_Board_at_Charlestown":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Agent_supply_run");
		break;

		case "Exit_issue_sailing_orders":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			AddDialogExitQuest("Sail_for_Guadeloupe");
		break;
	}
}
