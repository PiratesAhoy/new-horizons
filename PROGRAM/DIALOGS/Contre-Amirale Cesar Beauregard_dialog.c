//#include "DIALOGS\Contre-Amirale Cesar Beauregard_dialog.h"

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
			dialog.snd = "Voice\CLLA\CLLA004";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "yourstory7";
			if (!CheckAttribute(NPChar, "birdwatch2"))
			{
				link.l2 = DLG_TEXT[4];
				link.l2.go = "yourstory3";
			}
			break;

		case "yourstory2":
			dialog.snd = "Voice\CLLA\CLLA004";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "yourstory3";
			break;

		case "yourstory3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "yourstory4";
			break;

		case "yourstory4":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "yourstory5";
			break;

		case "yourstory5":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "yourstory6";
//			link.l2 = DLG_TEXT[13];
//			link.l2.go = "yourstory7";
			break;

		case "yourstory6":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "yourstory8";
			link.l2 = DLG_TEXT[17];
			link.l2.go = "exit";
			break;

		case "yourstory7":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
//			link.l2 = DLG_TEXT[17];
//			link.l2.go = "yourstory8";
			break;

		case "yourstory8":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "yourstory9";
			break;

		case "yourstory9":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "yourstory10";
			link.l2 = DLG_TEXT[17];
			link.l2.go = "exit";
			break;

		case "yourstory10":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "go";
			break;

		case "go":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("birdwatch");
			break;

		case "letter":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "letter2";
			break;

		case "letter2":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "letter3";
			break;

		case "letter3":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "letter4";
			break;

		case "letter4":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[32];
			link.l1.go = "exit";
			AddDialogExitQuest("birdhunt");
			break;

		case "weldone1":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "weldone2";
			break;

		case "weldone2":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "Exit";
			AddDialogExitQuest("free_to_go");
			break;

		case "nothing":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
	}
}
