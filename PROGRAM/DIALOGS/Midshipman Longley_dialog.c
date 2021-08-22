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

		case "cut_for_deal":
			dialog.text = "";
			link.l1 = DLG_TEXT[2];
			link.l1.go = "exit";
		break;

		case "evening_swim":
			dialog.text = "";
			link.l1 = DLG_TEXT[4];
			link.l1.go = "evening_swim2";
		break;

		case "evening_swim2":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "evening_swim3";
		break;

		case "evening_swim3":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
		break;

		case "which_way":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		case "wake_them_up":
			dialog.text = "";
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
		break;

		case "what_is_screaming":
			dialog.text = "";
			link.l1 = DLG_TEXT[12] + GetMyLastName(NPChar) + "?";
			link.l1.go = "not_quite_sure";
		break;

		case "not_quite_sure":
			dialog.text = DLG_TEXT[13];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "cabin_moves":
			dialog.text = "";
			link.l1 = DLG_TEXT[14] + GetMyLastName(NPChar) + DLG_TEXT[15];
			link.l1.go = "cabin_moves2";
		break;

		case "cabin_moves2":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "came_back_to_mother":
			dialog.text = DLG_TEXT[18];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "did_you_miss_me":
			dialog.text = DLG_TEXT[19];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "kiss_me_mother":
			dialog.text = DLG_TEXT[20];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "goodnight":
			dialog.text = DLG_TEXT[21];
			link.l1 = "";
			link.l1.go = "exit";
		break;
	}
}