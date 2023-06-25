//#include "DIALOGS\Pepin Bertillon_dialog.h"
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
			Dialog.snd = "voice\PEBE\PEBE001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1]+ Characters[GetCharacterIndex(DLG_TEXT[2])].name +" "+ Characters[GetCharacterIndex(DLG_TEXT[3])].lastname +DLG_TEXT[4];
			link.l1.go = "1";

		break;

		case "1":
			Dialog.snd = "voice\PEBE\PEBE002";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "2";

		break;

		case "2":
			Dialog.snd = "voice\PEBE\PEBE003";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_kill";
			if (FindCurrentStoryline() != FindStoryline("Assassin"))
			{
				link.l2 = DLG_TEXT[9];
				link.l2.go = "Exit_spare";
			}
		break;

		case "Exit_kill":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterReputation(pchar, -10);

			AddDialogExitQuest("Hit_kill_Pepin");

		break;

		case "Exit_spare":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			ChangeCharacterReputation(pchar, -5);

			AddDialogExitQuest("Hit_spare_Pepin");

		break;

	}
}
