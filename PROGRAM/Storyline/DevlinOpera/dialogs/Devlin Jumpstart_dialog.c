//#include "DIALOGS\Devlin Jumpstart_Dialog.h"
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
                        link.l2 = DLG_TEXT[2];
			link.l2.go = "Jump_Rum";
                        link.l3 = DLG_TEXT[3];
			link.l3.go = "Jump_Santiago";
                        link.l4 = DLG_TEXT[4];
			link.l4.go = "Jump_Domingo";
                        link.l5 = DLG_TEXT[5];
			link.l5.go = "Jump_Cayman";

		break;

		case "Jump_Rum":
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");

			AddDialogExitQuest("Jump_Rum");

			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "Jump_Santiago":
			SetCurrentTime(10.00, 0);
			SetNextWeather("Clear");

			AddDialogExitQuest("Jump_Santiago");

			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "Jump_Domingo":
			SetNextWeather("Clear");

			AddDialogExitQuest("Jump_Domingo");

			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

		case "Jump_Cayman":
			SetNextWeather("Clear");

			AddDialogExitQuest("Jump_Cayman");

			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;
	}
}