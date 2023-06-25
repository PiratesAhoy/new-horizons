//#include "DIALOGS\Fake Shaw_Dialog.h"
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

			dialog.text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];		// changed from .spa to .por by KAM
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "guvna2";

			if (CheckQuestAttribute("GOVERNOR", "angry"))
			{
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit";
			}
		break;

		case "guvna2":
			dialog.text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "guvna3";
		break;

		case "guvna3":
			dialog.text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "guvna4";
		break;

		case "guvna4":
			dialog.text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "guvna5";
		break;

		case "guvna5":
			dialog.text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "guvna6";
		break;

		case "guvna6":
			dialog.text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "guvna7";
		break;

		case "guvna7":
			dialog.text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "guvna8";
		break;

		case "guvna8":
			dialog.text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "exit";
			AddDialogExitQuest("Back_from_Cayman_city");
		break;
	}
}