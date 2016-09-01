//#include "DIALOGS\Thug_dialog.h"
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
			Dialog.snd = "voice\THDI\THDI001";


			PlaySound("VOICE\ENGLISH\c_brother1A.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			AddDialogExitQuest("blaze_drunk1");
		break;

		case "talk_1":
			LAi_SetActorType(characterFromID("Peter Blowhorn"));
			LAi_ActorRunToLocatorJRH(characterFromID("Peter Blowhorn"), "goto", "goto15", 0.0);
			LAi_SetActorType(characterFromID("Wench3"));
			LAi_ActorRunToLocatorJRH(characterFromID("Wench3"), "goto", "goto45", 0.0);

			PlaySound("VOICE\ENGLISH\c_brother1B.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
			AddDialogExitQuest("coastbrothers_not_fooled");
		break;

		case "talk_2":
			PlaySound("VOICE\ENGLISH\c_brother1C.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit";
			AddDialogExitQuest("coastbrothers_not_fooled_3");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
