//#include "DIALOGS\Enc_Bedroom_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;
	int NPC_Meeting;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			NextDiag.TempNode = "leave";
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "leave";
			Link.l2 = DLG_TEXT[2];
			Link.l2.go = "jewels";
			Link.l3 = DLG_TEXT[3];
			Link.l3.go = "reputation";
		break;

		case "leave":
			dialog.text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit_ambush";
		break;

		case "exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_ambush":
		// PB: To prevent the fight from starting before the dialog is closed
			Ambush("Rich_Citizens", 3, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
			Lai_group_MoveCharacter(NPChar, LAI_DEFAULT_GROUP);//MAXIMUS: if not - fighters will kill an NPC first
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "jewels":
			GiveItem2Character(pchar, "jewelry" + (1 + rand(15)));
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "reputation":
			ChangeCharacterReputation(pchar, 1);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
// ccc <--
