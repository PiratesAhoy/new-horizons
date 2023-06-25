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
			PlaySound("VOICE\ENGLISH\gm_crew9D.wav");
			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;
	
		case "what_you_want":
			PlaySound("VOICE\ENGLISH\gm_crew9B.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "what_you_want1";
		break;

		case "what_you_want1":
			PlaySound("VOICE\ENGLISH\gm_crew9D.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "what_you_want2";
		break;

		case "what_you_want2":
			PlaySound("VOICE\ENGLISH\gm_crew9A.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "what_you_want3";
		break;

		case "what_you_want3":
			PlaySound("VOICE\ENGLISH\blaze_puh.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "what_you_want4";
		break;

		case "what_you_want4":
			PlaySound("VOICE\ENGLISH\blaze_sigh.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "what_you_want5";
		break;

		case "what_you_want5":
			PlaySound("VOICE\ENGLISH\gm_crew9C.wav");
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "what_you_want6";
		break;

		case "what_you_want6":
			PlaySound("VOICE\ENGLISH\gm_crew9A.wav");
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "what_you_want7";
		break;

		case "what_you_want7":
			PlaySound("VOICE\ENGLISH\gm_crew9B.wav");
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("sergeant_leaves");
		break;

		case "Exit":
		//	NextDiag.CurrentNode = NextDiag.TempNode;
			NextDiag.CurrentNode = "First time";
			DialogExit();
		break;
	}
	LanguageCloseFile(tmpLangFileID);
}
