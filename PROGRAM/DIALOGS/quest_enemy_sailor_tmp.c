//#include "DIALOGS\quest_enemy_sailor_tmp.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
		case "take_HardouinBeauvallet_start":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";			

			switch(Rand(2))
			{
			case 0:
				Dialog.snd = "voice\QUEN\QUEN001";
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			break;
			case 1:
				Dialog.snd = "voice\QUEN\QUEN002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			break;
			case 2:
				Dialog.snd = "voice\QUEN\QUEN003";
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
			break;
			}
		break;

		case "exit":
			if( CheckAttribute(NPChar,"Dialog.answer") )	PChar.quest.dialog_answer.win_condition = NPChar.Dialog.answer;
			DialogExit();
		break;
	}
}
