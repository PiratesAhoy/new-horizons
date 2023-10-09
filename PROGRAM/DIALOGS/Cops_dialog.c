//#include "DIALOGS\Cops_dialog.h"
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
			
			dialog.snd = "Voice\COPS\COPS001";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "meeting"; 
		break;

		case "Meeting":
			dialog.snd = "Voice\COPS\COPS002";
			d.Text = DLG_TEXT[2];
			Link.l2 = DLG_TEXT[3];
			Link.l2.go = "fight"; 
			Link.l3 = DLG_TEXT[4];
			Link.l3.go = "court";
		break;

		case "fight":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			AddDialogExitQuest("artois_fight_in_tavern_upstairs");
		break;
		
				
		case "court":
			AddDialogExitQuest("pause");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

	}
}