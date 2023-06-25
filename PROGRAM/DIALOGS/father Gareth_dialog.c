//#include "DIALOGS\father Gareth_dialog.h"

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

	if (PChar.sex == "man") Preprocessor_Add("addr", XI_ConvertString("my son"));
	else Preprocessor_Add("addr", XI_ConvertString("my child"));
	
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
			
			dialog.snd = "Voice\FATG\FATG001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (CheckQuestAttribute("ANIMISTS", "frigate_lost"))
			{
				dialog.snd = "Voice\FATG\FATG002";
				Preprocessor_Add("person", PChar.sex);
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}
			if (CheckQuestAttribute("ANIMISTS", "before_knight"))
			{
				dialog.snd = "Voice\FATG\FATG003";
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "exit";
				AddDialogExitQuest("fight_with_ANIMISTS_in_church");
			}			
			NextDiag.TempNode = "first time";
		break;
		
		case "letter_to_domingues":  // --> Cat		
				dialog.text = DLG_TEXT[13];
				link.l1 = DLG_TEXT[14];
				link.l1.go = "letter_to_domingues_1";
		break;

		case "letter_to_domingues_1":
			dialog.snd = "Voice\FATG\FATG004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "letter_to_domingues_2";
		break;

		case "letter_to_domingues_2":
			dialog.snd = "Voice\FATG\FATG005";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "letter_to_domingues_3";
		break;

		case "letter_to_domingues_3":
			dialog.snd = "Voice\FATG\FATG006";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			AddDialogExitQuest("Story_Gareth_deception2");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
