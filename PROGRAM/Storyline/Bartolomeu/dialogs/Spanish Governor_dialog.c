//#include "DIALOGS\Arturo Campos_dialog.h"

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
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";			
		break;

		case "gov_1":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "gov_2";
		break;

		case "gov_2":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "gov_3";
		break;

		case "gov_3":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "gov_4";
		break;

		case "gov_4":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "gov_5";
		break;
		
		case "gov_5":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "gov_6";
		break;

		case "gov_6":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "gov_7";
		break;

		case "gov_7":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "gov_8";
		break;

		case "gov_8":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "gov_9";
		break;

		case "gov_9":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "gov_10";
		break;

		case "gov_10":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "gov_11";
		break;

		case "gov_11":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "gov_12";
		break;

		case "gov_12":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "gov_13";
		break;
		
		case "gov_13":
			dialog.snd = "Voice\REGR\REGR008";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			AddDialogExitQuest("giflecole");			
		break;		

               case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;		

                       break;

	}
}
