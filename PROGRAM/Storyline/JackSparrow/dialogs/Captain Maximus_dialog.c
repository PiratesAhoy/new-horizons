//#include "DIALOGS\Captain Maximus_dialog.h"
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

			Dialog.mood = "normal";

			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

		break;

		case "meet_Drow&Rackham_Again":
			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit_at_Dock";
		break;

		case "Warning_message":
			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_Warning";
		break;

		case "We_Found_the_Motherload":
			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "We_Found_the_Motherload2";
		break;

		case "We_Found_the_Motherload2":
			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "We_Found_the_Motherload3";
		break;

		case "We_Found_the_Motherload3":
			GiveModel2Player("47_Jack_Skel", true);
			dialog.snd = "Voice\ARGU\ARGU001";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit_We_Found_the_Motherload";
		break;

		case "Going_for_the_Doctor":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Going_for_the_Doctor2";
		break;

		case "Going_for_the_Doctor2":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Going_for_the_Doctor3";
		break;
		
		case "Going_for_the_Doctor3":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_Going_for_the_Doctor";
		break;
		
		case "Exit_Going_for_the_Doctor":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Philippe_and_Maximus_get_Doctor");
		break;

		case "Exit_We_Found_the_Motherload":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Move_the_Treasure");
		break;

		case "Exit_at_Dock":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("On_to_the_Guadelope_Tavern");
		break;

		case "Exit_Warning":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Maximus_and_Philippe3");
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

	}
}
