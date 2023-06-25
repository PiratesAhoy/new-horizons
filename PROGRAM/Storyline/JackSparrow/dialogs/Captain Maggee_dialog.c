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
		
		case "story":
			Dialog.snd = "voice\RAFA\RAFA003";
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "story2";
		break;
		
		case "story2":
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Exit_1"
		break;
		
		case "sail_Maggee1":
			if (GetAttribute(PChar, "Luc_Time") == "months")
			{
				Dialog.Text = DLG_TEXT[6];
				Link.l1 = DLG_TEXT[7];
			}
			else
			{
				Dialog.Text = DLG_TEXT[22];
				Link.l1 = DLG_TEXT[23];
			}
			Link.l1.go = "sail_Maggee2"
		break;
		
		case "sail_Maggee2":
			if (GetAttribute(PChar, "Luc_Time") == "months")
			{
				Dialog.Text = DLG_TEXT[8];
			}
			else
			{
				Dialog.Text = DLG_TEXT[24];
			}
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "sail_Maggee3"
		break;
		
		case "sail_Maggee3":
			Dialog.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "exit_2"
		break;
		
		case "Goodbye_at_Antigua":
			Dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Goodbye_at_Antigua2"
		break;
		
		case "Goodbye_at_Antigua2":
			Dialog.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "exit_3"
		break;

		case "Meeting_Tia":
			Dialog.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "Meeting_Tia2"
		break;

		case "Meeting_Tia2":
			Dialog.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Meeting_Tia3"
		break;

		case "Meeting_Tia3":
			Dialog.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "exit";
			addDialogExitQuest("Tia_and_Maggee2");
		break;
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
		
		case "Exit_1":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			
			AddDialogExitQuest("after_Maggee");
		break;
		
		case "Exit_2":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			
			AddDialogExitQuest("Sail_with_Maggee");
		break;
		
		case "Exit_3":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			
			AddDialogExitQuest("Goodbye_Maggee");
		break;
	}
}
