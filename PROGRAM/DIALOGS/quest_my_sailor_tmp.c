//#include "DIALOGS\quest_my_sailor_tmp.h"
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
			
			switch(Rand(3))
			{
			case 0:
				Dialog.snd = "voice\QUMY\QUMY001";	
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			break;
			case 1:
				Dialog.snd = "voice\QUMY\QUMY002";	
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			break;
			case 2:
				Dialog.snd = "voice\QUMY\QUMY003";	
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "exit";
			break;
			case 3:
				Dialog.snd = "voice\QUMY\QUMY004";	
				dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "exit";
			break;
			}
		break;


		case "ReadyForAction":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\QUMY\QUMY005";	
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "ReadyForAction_1";
		break;

		case "ReadyForAction_1":
			Dialog.snd = "voice\QUMY\QUMY006";	
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "ReadyForAction_2";
		break;

		case "ReadyForAction_2":
			Dialog.snd = "voice\QUMY\QUMY007";	
			dialog.text = DLG_TEXT[12] + GetMyName(Pchar) + DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "ReadyForAction_3";
		break;

		case "ReadyForAction_3":
			Dialog.snd = "voice\QUMY\QUMY008";	
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "ReadyForAction_4";
		break;

		case "ReadyForAction_4":
			Dialog.snd = "voice\QUMY\QUMY009";	
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "ReadyForAction_5";
		break;

		case "ReadyForAction_5":
			Dialog.snd = "voice\QUMY\QUMY010";	
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "ReadyForAction_6";
		break;

		case "ReadyForAction_6":
			Dialog.snd = "voice\QUMY\QUMY011";	
			NextDiag.TempNode = "First time";
			AddDIalogExitQuest("frigate_sink_preparation");
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
		break;


		case "Report":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\QUMY\QUMY012";	
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "report_1";
		break;

		case "Report_1":
			AddDialogExitQuest("Fem_VolunteersJoined");
			NextDiag.tempNode = "First time";
			Dialog.snd = "voice\QUMY\QUMY013";	
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
		break;

		case "exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			DialogExit();
		break;

		case "exit":
			DialogExit();
		break;
	}
}
