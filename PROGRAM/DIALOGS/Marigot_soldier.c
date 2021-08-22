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
			link.l1.go = "siege";
			link.l2 = DLG_TEXT[2];
			link.l2.go = "you";
			link.l3 = DLG_TEXT[3];
			link.l3.go = "way";
			link.l4 = DLG_TEXT[4];
			link.l4.go = "support";
			link.l5 = DLG_TEXT[5];
			link.l5.go = "exit";
		break;

		case "siege":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";

		break;

		case "you":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";

		break;

		case "way":
			dialog.text = DLG_TEXT[10];
			link.l2 = DLG_TEXT[11];
			link.l2.go = "exit";
		break;

		case "support":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
		break;

		case "Exit":
			LAi_CreateFantomGroup("Soldiers", 5, LAI_GROUP_ENEMY, LAI_GROUP_ENEMY, HOLLAND, OFFIC_TYPE_GUARD, 0, true, "", "", "", "");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;

	}
}
