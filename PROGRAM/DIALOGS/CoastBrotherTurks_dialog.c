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
		
			if(CheckAttribute(Pchar,"CB_Turks") && Pchar.CB_Turks == "warning2")
			{
				//start fight here

				PauseAllSounds();
				PlaySound("VOICE\ENGLISH\c_brother21.wav");
				Dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
				AddDialogExitQuest("Coastbrothers_Turks_attack");
			}
			else
			{
				if(CheckAttribute(Pchar,"CB_Turks") && Pchar.CB_Turks == "warning1")
				{
					PlaySound("VOICE\ENGLISH\c_brother1C.wav");
					Pchar.CB_Turks = "warning2";
					Dialog.text = DLG_TEXT[2];
					link.l1 = DLG_TEXT[3];
					link.l1.go = "exit";
				}
			}
			else
			{
				PlaySound("VOICE\ENGLISH\gr_Richards.wav");
				Pchar.CB_Turks = "warning1";
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "Exit";
			}
		break;

		case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;
	}
}
