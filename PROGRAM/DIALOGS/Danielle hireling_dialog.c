//#include "DIALOGS\Danielle hireling_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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

	Dialog.defAni = "dialog_stay1";
	Dialog.defCam = "1";
	Dialog.defSnd = "dialogs\0\017";
	Dialog.defLinkAni = "dialog_1";
	Dialog.defLinkCam = "1";
	Dialog.defLinkSnd = "dialogs\woman\024";
	Dialog.ani = "dialog_stay2";
	Dialog.cam = "1";

	switch(Dialog.CurrentNode)
	{
		case "first time":
			dialog.snd = "Voice\DAHA\DAHA001";
			Dialog.Text = RandSwear() + DLG_TEXT[0];
			Link.l1 = pcharrepphrase(DLG_TEXT[1],DLG_TEXT[2]);
			Link.l1.go = "exit";

			if(CheckQuestAttribute("KillerStatus","defeat"))
			{
				dialog.snd = "Voice\DAHA\DAHA002";
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
				Dialog.Text = DLG_TEXT[3];
				Link.l1 = DLG_TEXT[4];
				Link.l1.go = "KillerTalk_1";
				Link.l2 = DLG_TEXT[5];
				Link.l2.go = "KillerDeath";
			}
		break;

		case "KillerTalk_1":
			dialog.snd = "Voice\DAHA\DAHA003";
			Dialog.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "KillerDeath";
			Link.l2 = DLG_TEXT[8];
			Link.l2.go = "KillerForgive";
		break;

		case "KillerForgive":
			dialog.snd = "Voice\DAHA\DAHA004";
			Dialog.Text = DLG_TEXT[9]
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "exit";
			SetAfterDialog_Task(NPChar,ADA_DISAPPEAR,true);
		break;

		case "KillerDeath":
			dialog.snd = "Voice\DAHA\DAHA005";
			Dialog.Text = RandSwear() + DLG_TEXT[11]
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			SetAfterDialog_Task_Character(NPChar,ADA_KILL,NPChar.id,true);
		break;

		case "exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
