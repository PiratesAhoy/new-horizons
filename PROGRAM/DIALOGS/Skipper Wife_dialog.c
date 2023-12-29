//#include "DIALOGS\Skipper Wife_dialog.h"

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

			dialog.snd = "Voice\CLLA\CLLA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			break;

		case "what_are_you_doing":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "dontknow";
			link.l2 = DLG_TEXT[4];
			link.l2.go = "foryou";
			link.l3 = DLG_TEXT[5];
			link.l3.go = "witness";
			link.l4 = DLG_TEXT[6];
			link.l4.go = "nothing";
			break;

		case "dontknow":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
			AddDialogExitQuest("callguards");
			break;

		case "foryou":
			dialog.snd = "Voice\CLLA\CLLA004";
			Preprocessor_Add("bastard", XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_HOSTILE, false, false))); // DeathDaisy
			Preprocessor_Add("gender", XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false))); // DeathDaisy
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			AddDialogExitQuest("lovertrouble");
			break;

		case "witness":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exitkillher";
			link.l2 = DLG_TEXT[13];
			link.l2.go = "offer";
			break;

		case "offer":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exitkillher";
			link.l2 = DLG_TEXT[16];
			link.l2.go = "exitgold";
			break;

		case "nothing":
			AddMoneyToCharacter(PChar, -500);
			dialog.snd = "Voice\CLLA\CLLA005";
			Preprocessor_Add("sir", XI_ConvertString(GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false))); // DeathDaisy
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			AddDialogExitQuest("toadmiral");
			break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;

		case "exitkillher":
			AddDialogExitQuest("killher");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;

		case "exitgold":
			AddDialogExitQuest("gold");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
	}
}
