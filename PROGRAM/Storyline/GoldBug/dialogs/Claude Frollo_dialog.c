//#include "DIALOGS\Church crew_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

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

			PlaySound("VOICE\ENGLISH\Eng_m_c_072.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			AddDialogExitQuest("Charleston_priest2");
			
			Diag.TempNode = "first time";
		break;

		case "church_entre":
			PlaySound("VOICE\ENGLISH\Eng_m_c_072.wav");
			dialog.text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "church_entre1";
		break;

		case "church_entre1":
			PlaySound("VOICE\ENGLISH\Eng_m_c_077.wav");
			dialog.text = DLG_TEXT[3];
			Link.l1 = DLG_TEXT[4];
			Link.l1.go = "church_entre2";
		break;
		
		case "church_entre2":
			PlaySound("VOICE\ENGLISH\Eng_m_c_074.wav");
			dialog.text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "church_entre3";
		break;

		case "church_entre3":
			PlaySound("VOICE\ENGLISH\Eng_m_c_073.wav");
			dialog.text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "church_entre4";
		break;

		case "church_entre4":
			PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
			dialog.text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "church_entre5";
		break;

		case "church_entre5":
			PlaySound("VOICE\ENGLISH\Eng_m_c_059.wav");
			dialog.text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "church_entre6";
		break;

		case "church_entre6":
			PlaySound("VOICE\ENGLISH\Eng_m_c_003.wav");
			dialog.text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "church_entre7";
		break;

		case "church_entre7":
			PlaySound("VOICE\ENGLISH\Eng_m_c_075.wav");
			dialog.text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "church_entre8";
		break;

		case "church_entre8":
			PlaySound("VOICE\ENGLISH\Eng_m_c_006.wav");
			dialog.text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "exit";
			AddDialogExitQuest("church_entre_done");
		break;

		case "hymn_book":
			PlaySound("VOICE\ENGLISH\Eng_m_c_065.wav");
			dialog.text = DLG_TEXT[19];
			Link.l1 = DLG_TEXT[20];
			Link.l1.go = "hymn_book1";
		break;

		case "hymn_book1":
			PlaySound("VOICE\ENGLISH\Eng_m_c_007.wav");
			dialog.text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "hymn_book2";
		break;

		case "hymn_book2":
			PlaySound("VOICE\ENGLISH\Eng_m_c_075.wav");
			dialog.text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "hymn_book3";
		break;

		case "hymn_book3":
			PlaySound("VOICE\ENGLISH\Eng_m_c_003.wav");
			dialog.text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			AddDialogExitQuest("hymn_book_done");
		break;

		case "holy_water":
			PlaySound("INTERFACE\glass1.wav");
			LAi_QuestDelay("Poe_very_nice", 1.0);
			TakenItems(Pchar, "holy_water", 12);
			EquipCharacterbyItem(Pchar, "holy_water");
			dialog.text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "holy_water1";
		break;

		case "holy_water1":
			PlaySound("VOICE\ENGLISH\Eng_m_c_075.wav");
			dialog.text = DLG_TEXT[29];
			Link.l1 = DLG_TEXT[30];
			Link.l1.go = "holy_water2";
		break;

		case "holy_water2":
			PlaySound("VOICE\ENGLISH\Eng_m_c_003.wav");
			dialog.text = DLG_TEXT[31];
			Link.l1 = DLG_TEXT[32];
			Link.l1.go = "holy_water3";
		break;

		case "holy_water3":
			PlaySound("VOICE\ENGLISH\Eng_m_c_074.wav");
			dialog.text = DLG_TEXT[33];
			Link.l1 = DLG_TEXT[34];
			Link.l1.go = "exit";
			AddDialogExitQuest("holy_water_done");
		break;

		case "neutral":
			PlaySound("VOICE\ENGLISH\Eng_m_c_076.wav");
			dialog.text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "exit";
			Diag.TempNode = "neutral";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
