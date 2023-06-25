//#include "DIALOGS\QC citizen_dialog.h"

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
			Dialog.snd = "voice\QCSI\QCSI001";
			
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.text = randphrase(DLG_TEXT[0], DLG_TEXT[1], DLG_TEXT[2], &dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(!Rand(3)) dialog.text = DLG_TEXT[4] + GetTownSize(GetCurrentTownID()) + DLG_TEXT[5]; // NK
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			NextDiag.TempNode = "first time";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "drink":
			NextDiag.TempNode = "first time";
	
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay1";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\COSO\COSO045";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "drink_2";
		break;

		case "drink_2":
			dialog.snd = "Voice\COSO\COSO046";
			dialog.text = DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "drink_exit";
			link.l2 = DLG_TEXT[11];
			link.l2.go = "fight_exit";
		break;

		case "drink_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			npchar.location = "none";
		break;

		case "fight_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
			AddDialogExitQuest("fight_with_soldier_for_drink");
		break;
	}
}
