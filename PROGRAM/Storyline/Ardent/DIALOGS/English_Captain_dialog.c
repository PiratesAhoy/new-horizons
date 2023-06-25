//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

	
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
			link.l1.go = "Exit";
		break;

		case "what_is_the_meaning":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[4];
			link.l1.go = "nonsense_no_prisoners";
		break;

		case "nonsense_no_prisoners":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "outrage";
		break;

		case "outrage":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "how_you_got_person_aboard":
			if (PChar.sex == "man")
			{
				Preprocessor_Add("pronoun", XI_ConvertString("she"));
				link.l1 = DLG_TEXT[11];
			}
			else
			{
				Preprocessor_Add("pronoun", XI_ConvertString("he"));
				link.l1 = DLG_TEXT[12];
			}
			dialog.text = DLG_TEXT[10];
			link.l1.go = "whats_your_game";
		break;

		case "whats_your_game":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14] + GetMyFullName(CharacterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "exit";
		break;
	}
}