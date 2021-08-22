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



		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit under arrest":
			AddDialogExitQuest("into_position_Cayman2");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
