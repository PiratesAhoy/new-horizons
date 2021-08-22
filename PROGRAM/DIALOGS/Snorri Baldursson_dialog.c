//#include "DIALOGS\Snorri Baldursson_dialog.h"
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
			Dialog.defAni = "Sit_Look_Around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Look_Around";
			Dialog.cam = "1";
			Dialog.snd = "voice\SNBA\SNBA001";

			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Exit_fight";

		break;

		case "Exit_fight":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_sign_fight2_1");


		break;

	}
}
