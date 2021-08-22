//#include "DIALOGS\Corentin Lucay_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
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
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "one":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\COLU\COLU001";
			dialog.text = DLG_TEXT[0] + GetMyLastName(&Characters[GetCharacterIndex(DLG_TEXT[1])]) + DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Bernardo Gamboa")].dialog.currentnode = "one";
			AddDialogExitQuest("second_talk_in_gamboa_ship");
		break;

		case "two":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
			
			dialog.snd = "Voice\COLU\COLU002";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";

			characters[GetCharacterIndex("Bernardo Gamboa")].dialog.currentnode = "two";
			AddDialogExitQuest("second_talk_in_gamboa_ship");
		break;

		case "three":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
			
			dialog.snd = "Voice\COLU\COLU003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Pusasn_in_the_ship");
		break;
	}
}