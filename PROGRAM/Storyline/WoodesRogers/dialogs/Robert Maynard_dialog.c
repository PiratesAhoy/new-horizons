//#include "DIALOGS\Thug_dialog.h"
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
			Dialog.snd = "voice\THDI\THDI001";
		break;

		case "start":
			PlaySound("VOICE\ENGLISH\Maynard_steady_there.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "start_1";
		break;

		case "start_1":
			PlaySound("VOICE\ENGLISH\Maynard_make_deal.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "start_2";
		break;

		case "start_2":
			PlaySound("VOICE\ENGLISH\Maynard_too_bad.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
		break;

		case "bridge":
			PlaySound("VOICE\ENGLISH\Maynard_hey_there.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
		break;

		case "anchor":
			PlaySound("VOICE\ENGLISH\Maynard_very_well.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("maynard_tower");
		break;

		case "tower":
			PlaySound("VOICE\ENGLISH\Maynard_very_good.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "tower_1";
		break;

		case "tower_1":
			PlaySound("VOICE\ENGLISH\Maynard_I_said.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "tower_2";
		break;

		case "tower_2":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "tower_3";
		break;

		case "tower_3":
			PlaySound("VOICE\ENGLISH\Maynard_was_right.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "tower_4";
		break;

		case "tower_4":
			PlaySound("VOICE\ENGLISH\pir_capAAA.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "tower_5";
		break;

		case "tower_5":
			PlaySound("VOICE\ENGLISH\Maynard_no_plunder.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "tower_6";
		break;

		case "tower_6":
			PlaySound("VOICE\ENGLISH\Maynard_big_swindel.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "tower_7";
		break;

		case "tower_7":
			PlaySound("VOICE\ENGLISH\Maynard_too_bad.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "tower_8";
		break;

		case "tower_8":
			PlaySound("VOICE\ENGLISH\Maynard_very_well.wav");
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("maynard_tower_done");
		break;

		case "repeat":
			PlaySound("VOICE\ENGLISH\Maynard_hey_there.wav");
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("maynard_tower_done");
		break;		

		case "Exit":
			LAi_SetPlayerType(Pchar);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
