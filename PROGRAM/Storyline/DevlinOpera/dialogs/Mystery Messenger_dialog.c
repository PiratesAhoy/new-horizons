
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

			dialog.text = DLG_TEXT[0] + GetMyFullName(PChar) + "?";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Talking";
		break;

		case "Talking":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_letter";
		break;

		case "Malaga":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Malaga2";
		break;

		case "Malaga2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Greenford2Santiago");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_letter":
			AddDialogExitQuest("ReceivedLetter");

			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Outside_puzzle":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Outside_puzzle2";
		break;

		case "Outside_puzzle2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Outside_puzzle3";
		break;

		case "Outside_puzzle3":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Outside_puzzle4";
		break;

		case "Outside_puzzle4":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Outside_puzzle5";
		break;

		case "Outside_puzzle5":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Outside_puzzle6";
		break;

		case "Outside_puzzle6":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Outside_puzzle7";
			SetQuestHeader("My Life as a Waitress");
			AddQuestRecord("My Life as a Waitress", 1);
			AddQuestRecord("My Life as a Waitress", 2);
			AddQuestRecord("My Life as a Waitress", 3);
			AddQuestRecord("My Life as a Waitress", 4);
			AddQuestRecord("My Life as a Waitress", 5);
			AddQuestRecord("My Life as a Waitress", 6);
			AddQuestRecord("My Life as a Waitress", 7);
		break;

		case "Outside_puzzle7":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Outside_puzzle_Bonnie");
		break;

		case "Welcome_Cayman":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Welcome_Cayman2";
		break;

		case "Welcome_Cayman2":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Welcome_Cayman3";
		break;

		case "Welcome_Cayman3":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("Snakes_Questionmark");
		break;
	}
}
