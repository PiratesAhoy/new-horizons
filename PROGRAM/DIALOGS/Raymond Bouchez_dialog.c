//#include "DIALOGS\Raymond Bouchez_dialog.h"

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
			Dialog.snd = "voice\RABO\RABO001";
			
			dialog.text = DLG_TEXT[0] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[1])]) + DLG_TEXT[2];
			link.l1 = " ";
			link.l1.go = "exit";
			characters[GetCharacterIndex("Virginie d'Espivant")].dialog.currentnode = "speak_1";
			AddDialogExitQuest("virginie_speak");

			NextDiag.TempNode = "first time";
		break;

		case "speak_1":
			Dialog.snd = "voice\RABO\RABO002";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Falaise_de_Fleur_officiant")].dialog.currentnode = "sister";
			AddDialogExitQuest("sister_speak");
		break;

		case "speak_2":
			Dialog.snd = "voice\RABO\RABO003";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "fight_prepare";
		break;

		case "fight_prepare":
			Dialog.snd = "voice\RABO\RABO004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
			characters[GetCharacterIndex("Virginie d'Espivant")].dialog.currentnode = "speak_3";
			AddDialogExitQuest("virginie_speak");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
