//#include "DIALOGS\Ernesto Haraldo_Dialog.h"
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
			link.l1.go = "2";
		break;

		case "2":
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "3";
		break;

		case "3":
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "4";
		break;

		case "4":
			Dialog.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "5";
		break;

		case "5":
			Dialog.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "talk";
			Link.l2 = DLG_TEXT[10];
			Link.l2.go = "exit_drink";
		break;

		case "exit_drink":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("drink_with_Ernesto");
		break;

		case "wineglass":
			Dialog.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "wineglass2";
		break;

		case "wineglass2":
			Dialog.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "wineglass3";
                        PlaySound("INTERFACE\drink.wav");
		break;

		case "wineglass3":
			Dialog.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "exit";
			AddDialogExitQuest("caught");
		break;

		case "talk":
			Dialog.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "talk2";
		break;

		case "talk2":
			Dialog.Text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "talk3";
		break;

		case "talk3":
			Dialog.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "talk4";
		break;

		case "talk4":
			Dialog.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "talk5";
		break;

		case "talk5":
			Dialog.Text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			AddDialogExitQuest("Bonnie_returns_Martinica_talked");
		break;
	}
}