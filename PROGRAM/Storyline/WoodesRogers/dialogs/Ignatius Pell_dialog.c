//#include "DIALOGS\Tom Morgan_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			Dialog.snd = "voice\PADI\PADI001";

		break;
	
		case "neutral":
			PlaySound("VOICE\ENGLISH\gm_crew16A.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
		break;

		case "story":
			PlaySound("VOICE\ENGLISH\pir_capP.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "story1";
		break;

		case "story1":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "story2";
		break;

		case "story2":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "story3";
		break;

		case "story3":
			PlaySound("VOICE\ENGLISH\pir_capBB.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "story4";
		break;

		case "story4":
			PlaySound("VOICE\ENGLISH\pir_capA.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("Pell_story_interrupted");
		break;

	//-----------------------------------------------------------------

		case "story5":
			PlaySound("OBJECTS\DUEL\man_attack6.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "story6";
		break;

		case "story6":
			PlaySound("VOICE\ENGLISH\blaze_huh.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "story7";
		break;

		case "story7":
			PlaySound("VOICE\ENGLISH\pir_capKK.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "story8";
		break;

		case "story8":
			PlaySound("VOICE\ENGLISH\pir_capFFF.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "story9";
		break;

		case "story9":
			PlaySound("VOICE\ENGLISH\pir_capD.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "story10";
		break;

		case "story10":
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "story11";
		break;

		case "story11":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "story12";
		break;

		case "story12":
			PlaySound("VOICE\ENGLISH\blaze_no_escape.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "story13";
		break;

		case "story13":
			PlaySound("VOICE\ENGLISH\blaze_hah.wav");
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "story14";
		break;

		case "story14":
			PlaySound("VOICE\ENGLISH\pir_capAAA.wav");
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "story15";
		break;

		case "story15":
			PlaySound("VOICE\ENGLISH\pir_capFF.wav");
			Dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			AddDialogExitQuest("Pell_story_done");
		break;		

		case "neutral_cell":
			PlaySound("VOICE\ENGLISH\pir_capEE.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			Diag.TempNode = "neutral_cell";
		break;	

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
