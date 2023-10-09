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
			
			PlaySound("VOICE\ENGLISH\Fre_m_c_011.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "chimney";
		break;

		case "chimney":
			PlaySound("VOICE\ENGLISH\Fre_m_c_072.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "chimney1";
		break;

		case "chimney1":
			PlaySound("VOICE\ENGLISH\Fre_m_c_075.wav");
			Dialog.text = DLG_TEXT[4];
			if(CheckCharacterItem(Pchar,"book69A") || CheckCharacterItem(Pchar,"book69B") || CheckCharacterItem(Pchar,"book69C"))
			{
				link.l1 = DLG_TEXT[5];
				link.l1.go = "chimney2";
			}
			else
			{
				link.l2 = DLG_TEXT[10];
				link.l2.go = "no_logbook";
			}
		break;

		case "chimney2":
			PlaySound("VOICE\ENGLISH\Fre_m_c_074.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "chimney3";
		break;

		case "chimney3":
			PlaySound("VOICE\ENGLISH\Fre_m_c_035.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("chimney_done");
		break;

		case "open_hut":
			PlaySound("VOICE\ENGLISH\Fre_m_c_032.wav");
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "open_hut1";
		break;

		case "open_hut1":
			PlaySound("VOICE\ENGLISH\Fre_m_c_003.wav");
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			AddDialogExitQuest("open_hut_done");
		break;

		case "no_logbook":
			PlaySound("VOICE\ENGLISH\Fre_m_c_049.wav");
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			AddDialogExitQuest("Arot_gone");
		break;

		case "inside_hut":
			PlaySound("VOICE\ENGLISH\Fre_m_c_004.wav");
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "inside_hut1";
		break;

		case "inside_hut1":
			PlaySound("VOICE\ENGLISH\Fre_m_c_010.wav");
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "inside_hut2";
		break;

		case "inside_hut2":
			PlaySound("VOICE\ENGLISH\Fre_m_c_018.wav");
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "inside_hut3";
		break;

		case "inside_hut3":
			PlaySound("VOICE\ENGLISH\Fre_m_c_017.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "inside_hut4";
		break;

		case "inside_hut4":
			PlaySound("VOICE\ENGLISH\Fre_m_c_013.wav");
			Dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "inside_hut5";
		break;

		case "inside_hut5":
			PlaySound("VOICE\ENGLISH\Fre_m_c_016.wav");
			Dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "inside_hut6";
		break;

		case "inside_hut6":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			Dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "inside_hut7";
		break;

		case "inside_hut7":
			PlaySound("VOICE\ENGLISH\Fre_m_c_001.wav");
			Dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "inside_hut8";
		break;
		
		case "inside_hut8":
			PlaySound("VOICE\ENGLISH\Fre_m_c_073.wav");
			Dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "inside_hut9";
		break;

		case "inside_hut9":
			PlaySound("VOICE\ENGLISH\Fre_m_c_062.wav");
			Dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "inside_hut10";
		break;

		case "inside_hut10":
			PlaySound("VOICE\ENGLISH\Fre_m_c_021.wav");
			Dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "inside_hut11";
		break;

		case "inside_hut11":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			Dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "inside_hut12";
		break;

		case "inside_hut12":
			PlaySound("VOICE\ENGLISH\Fre_m_c_075.wav");
			Dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "inside_hut13";
		break;

		case "inside_hut13":
			PlaySound("VOICE\ENGLISH\Fre_m_c_026.wav");
			Dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "inside_hut14";
		break;

		case "inside_hut14":
			PlaySound("VOICE\ENGLISH\Fre_m_c_018.wav");
			Dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
			AddDialogExitQuest("inside_hut_done");
		break;

		case "neutral_inside":
			PlaySound("VOICE\ENGLISH\Fre_m_c_035.wav");
			Dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
			
			AddDialogExitQuest("neutral_inside_repeat");
		break;

		case "neutral_islet":
			PlaySound("VOICE\ENGLISH\Fre_m_c_018.wav");
			Dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
			
			AddDialogExitQuest("neutral_islet_repeat");
		break;


		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
