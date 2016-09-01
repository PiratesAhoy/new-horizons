//#include "DIALOGS\quest_sapper.h"
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
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "First time_1";
		break;
		
				
		case "First time_1":
			NextDiag.TempNode = "DoNotDisturb";
			AddDialogExitQuest("bomb_laying_go");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
		break;

		case "DoNotDisturb":
			NextDiag.TempNode = "DoNotDisturb";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit";
		break;

		case "LetsGetTheHellOuttaHere":
			NextDiag.TempNode = "DoNotDisturb";
			AddDialogExitQuest("bomb_laying_go");

			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit";
		break;





			if( CheckQuestAttribute("frigate_sink","bombLaying") )
			{
				PChar.quest.frigate_sink = "bombLayingOk";
				dialog.text = DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "bomb laying exit";
			}
			if( CheckQuestAttribute("frigate_sink","bombReady") )
			{
				PChar.quest.frigate_sink = "bombReadyOk";
				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "bomb laying ok exit";
			}
		

		case "bomb laying exit":
			PChar.quest.bomb_laying_go.win_condition = "bomb_laying_go";
			DialogExit();
		break;

		case "bomb laying ok exit":
			PChar.quest.bomb_laying_exit.win_condition = "bomb_laying_exit";
			DialogExit();
		break;

		case "exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;
	}
}
