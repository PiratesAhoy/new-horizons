//#include "DIALOGS\tavern fightingman_dialog.h"

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
			Dialog.snd = "voice\TAFI\TAFI001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "drink";
			link.l2 = DLG_TEXT[2];
			link.l2.go = "exit";
			
			NextDiag.TempNode = "first time";
		break;

		case "drink":
			dialog.text = DLG_TEXT[3];
	//JRH check for enough gold -->
			if (makeint(pchar.money) >= 400)
			{
				link.l1 = DLG_TEXT[4];
				link.l1.go = "exit";
				GiveItem2Character(Pchar,"pistolgas");
				PlayStereoSound("INTERFACE\took_item.flac");
				AddMoneyToCharacter(Pchar, -400);
			}
			else
			{
				Link.l2 = DLG_TEXT[5];
				Link.l2.go = "exit";
			}
	//JRH <--
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
