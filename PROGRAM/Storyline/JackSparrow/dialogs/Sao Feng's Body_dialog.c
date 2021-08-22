//#include "DIALOGS\padre Domingues_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

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
			Dialog.snd = "voice\PADO\PADO001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			NextDiag.TempNode = "first time";
		break;


		case "Twins_in_cave":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Twins_in_cave2";
		break;

		case "Twins_in_cave2":
			if (GetAttribute(pchar, "girls" != "1"))
			{
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";

			}
			else
			{
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "Twins_in_cave3";
			}
		break;
		
		case "Twins_in_cave3":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("Story_Domingues_released");
		break;
		
		case "Twins_in_muelle":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			addDialogExitQuest("to_tavern_with_girls");
		break;

		case "After_Tavern":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			addDialogExitQuest("return_priest_complete");
		break;

		case "Twins_in_muelle_shore":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			addDialogExitQuest("to_shore_with_girls");
		break;

		case "After_shore":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			addDialogExitQuest("return_priest_complete");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
