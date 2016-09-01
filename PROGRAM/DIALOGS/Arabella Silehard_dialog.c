//#include "DIALOGS\Arabella Silehard_dialog.h"
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

			if (PChar.quest.Lucas == "search1")
			{
				dialog.snd = "Voice\ARSI\ARSI002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3] + Characters[GetCharacterIndex(DLG_TEXT[4])].lastname + DLG_TEXT[5] + GetCharacterFullName(DLG_TEXT[6]) + DLG_TEXT[7];
				link.l1.go = "Find_Lucas1";
			}
		break;

		case "Find_Lucas1":
			dialog.snd = "Voice\ARSI\ARSI003";
			dialog.text = DLG_TEXT[8];
			link.l1 = GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[9])]) + DLG_TEXT[10];
			link.l1.go = "Find_Lucas2";
			link.l2 = DLG_TEXT[11] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[12])]) + DLG_TEXT[13] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[14])]) + DLG_TEXT[15];
			link.l2.go = "Find_Lucas3";
		break;

		case "Find_Lucas2":
			dialog.snd = "Voice\ARSI\ARSI004";
			dialog.text = DLG_TEXT[16] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[17])]) + DLG_TEXT[18];
			link.l1 = DLG_TEXT[19] + Characters[GetCharacterIndex(DLG_TEXT[20])].lastname + DLG_TEXT[21];
			link.l1.go = "Find_Lucas_exit";
		break;

		case "Find_Lucas3":
			dialog.snd = "Voice\ARSI\ARSI005";
			dialog.text = DLG_TEXT[22] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[23])]) + DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Find_Lucas_exit";
		break;

		case "Find_Lucas_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();

			AddDialogExitQuest("Lucas_search2");
		break;

		case "Exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

	}
}