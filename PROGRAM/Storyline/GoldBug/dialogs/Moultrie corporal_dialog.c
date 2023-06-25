//#include "DIALOGS\Peter Blowhorn_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;
	
	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	ref PChar;
	PChar = GetMainCharacter();
	if(!CheckAttribute(NPChar, "quest.item_date")) NPChar.quest.item_date = NPChar.quest.meeting;

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";			
		
			Dialog.snd = "voice\PEBL\PEBL001";
			PlaySound("VOICE\ENGLISH\Dave_Edna_2.wav");
			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;
	
		case "who are you":
			PlaySound("VOICE\ENGLISH\Dave_Edna_7.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "who are you1";
		break;

		case "who are you1":
			PlaySound("VOICE\ENGLISH\Dave_Edna_3.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "who are you2";
		break;

		case "who are you2":
			PlaySound("AMBIENT\JAIL\chains2.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("note_to_corporal");
		break;

		//-------------------------------------------------	

		case "who are you3":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("corporal_revolver");
		break;

		//-------------------------------------------------

		case "who are you4":	
			PlaySound("VOICE\ENGLISH\Dave_Edna_1.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("Legrand_revolver");
		break;

		//-------------------------------------------------

		case "who are you5":
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			PlaySound("AMBIENT\JAIL\sigh2.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("corporal_ammo");
		break;

		//-------------------------------------------------

		case "who are you6":
			PlaySound("VOICE\ENGLISH\Dave_Edna_2.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("Legrand_ammo");
		break;

		//-------------------------------------------------

		case "who are you7":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("corporal_rope");
		break;

		//-------------------------------------------------

		case "who are you8":
			PlaySound("OBJECTS\VOICES\DEAD\male\dead7.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("Legrand_rope");
		break;

		case "Exit":
		//	NextDiag.CurrentNode = NextDiag.TempNode;
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}
