//#include "DIALOGS\PZBionicle Bill_Dialog.h"
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
			if (CheckQuestAttribute("BIONICLEBILL", "thirsty"))
			{
			    PlaySound("VOICE\ENGLISH\Bionicle.wav");
			    dialog.text = DLG_TEXT[0];
			    link.l1 = DLG_TEXT[1]; //WATER
			    link.l1.go = "Exit_bad";
			    link.l2 = DLG_TEXT[2]; //BEER
			    link.l2.go = "Exit_bad";
			    link.l3 = DLG_TEXT[3]; //WINE
			    link.l3.go = "Exit_bad";
			    link.l4 = DLG_TEXT[4]; //RUM
			    link.l4.go = "solved";
			    link.l5 = DLG_TEXT[5];
			    link.l5.go = "Exit";
			}

			else
			{
			    PlaySound("VOICE\ENGLISH\Bionicle.wav");
			    dialog.text = DLG_TEXT[6];
			    link.l1 = DLG_TEXT[7];
			    link.l1.go = "Exit";
			}
		break;

		case "solved":
			PlaySound("INTERFACE\drink.flac");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("BionicleBill_solved");
		break;

		case "Exit_bad":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
			AddDialogExitQuest("Tavern_death");
		break;
	}
}