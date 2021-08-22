//#include "DIALOGS\Pirates_vs_Blaze.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
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
			Dialog.snd = "voice\PIVS\PIVS001";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "continue"; 
		break;

		case "continue":
			Dialog.snd = "voice\PIVS\PIVS002";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3]; 
			Link.l1.go = "fight";
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "exit";
		break;

		case "fight":
			LAi_QuestDelay("Pirates_fight1", 0.01);	
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}