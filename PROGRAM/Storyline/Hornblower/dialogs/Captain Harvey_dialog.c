//#include "DIALOGS\Captain Horatio Hornblower_dialog.h"
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
			
			dialog.snd = "Voice\ARSI\ARSI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Harvey_meeting_Cayman":
			dialog.text = DLG_TEXT[3] + Pchar.lastname + DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Harvey_meeting_Cayman2";
		break;

		case "Harvey_meeting_Cayman2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Harvey_meeting_Cayman3";
		break;

		case "Harvey_meeting_Cayman3":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit_Harvey_meeting_Cayman";
		break;

		case "Exit_Harvey_meeting_Cayman":
			AddDialogExitQuest("Harvey_changes_plans");
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit":
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;

	}
}

