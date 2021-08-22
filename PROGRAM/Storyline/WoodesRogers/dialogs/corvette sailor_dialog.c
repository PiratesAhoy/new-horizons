//#include "DIALOGS\Church crew_dialog.h"
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

		//	PlaySound("VOICE\ENGLISH\ayay_captain.wav");
		/*
			if (pchar.location == "wr_cave_shore" || pchar.location == "wr_church_outside")
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
		*/
			Diag.TempNode = "first time";
		break;

		case "ok_captain":
			PlaySound("VOICE\ENGLISH\guncrew_3.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("explore_corvette12_D");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
