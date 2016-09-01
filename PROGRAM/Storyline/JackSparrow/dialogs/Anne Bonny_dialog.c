
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
			
//			if (pchar.quest.Bonnie_talk == "Sailing_for_Turks")
//			{
//			dialog.text = DLG_TEXT[2];
//			link.l1 = DLG_TEXT[3];			
//			link.l1.go = "First_orders2";
//			}

		break;

		case "First_orders2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_First_Orders";
		break;

		
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;		
		
		case "Exit_First_Orders":
			AddDialogExitQuest("Mings_steps_in");			
			pchar.quest.Bonnie_talk = "QC_discussion_with_JPJ";
			DialogExit();
			Diag.CurrentNode = "First time";
		break;


	}
}
