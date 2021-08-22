
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

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Wellard_is_fine":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Wellard_is_fine2";
		break;

		case "Wellard_is_fine2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_Wellard_is_fine";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "Exit_Wellard_is_fine":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Discuss_the_Captain_again");
		break;

		case "Please_leave":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Please_leave";
		break;

		case "Exit_Please_leave":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Leaving_the_captain");
		break;

		case "The_Captain_Lives":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "The_Captain_Lives2";
		break;

		case "The_Captain_Lives2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "The_Captain_Lives3";
		break;

		case "The_Captain_Lives3":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_The_Captain_Lives";
		break;

		case "Exit_The_Captain_Lives":
			DialogExit();
			Diag.CurrentNode = "First time";
			AddDialogExitQuest("Buckland_in_Command");
		break;

		
		
		
	}
}
