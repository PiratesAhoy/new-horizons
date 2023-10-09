//#include "DIALOGS\ralph fawn_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
			Dialog.snd = "voice\RAFA\RAFA001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;
		
		case "turks_prison":
			Dialog.snd = "voice\RAFA\RAFA003";
			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "story1";
		break;
		
		case "story1":
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Exit_1";
			AddDialogExitQuest("hit_captain_guard_talk_captain");
		break;
		
		case "after_hit":
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Exit_1";
			AddDialogExitQuest("to_turks_prison_load");			
		break;
		
		//Gives player two choices surrender or attack
		case "turks_prison_inside":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "turks_prison_captured_walk_cell";
			link.l2 = DLG_TEXT[8];
			link.l2.go = "turks_prison_figh_guards";
		break;
		
		case "turks_prison_surrender":
			Dialog.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Exit_1";
			AddDialogExitQuest("captain_prison_throw_to_cell");			
		break;
		
		case "turks_prison_captured_walk_cell":
            DialogExit();
			AddDialogExitQuest("turks_prison_captured_walk");
		break;
		
		case "turks_prison_figh_guards":
			DialogExit();
			AddDialogExitQuest("turks_prison_figh_guards");
		break;

		case "Exit_1":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
		
	}
}
