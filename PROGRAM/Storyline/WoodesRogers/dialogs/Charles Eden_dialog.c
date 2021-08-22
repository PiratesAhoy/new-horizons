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
		break;

		case "bribing1":
			PlaySound("VOICE\ENGLISH\Eden_cant_do.wav");			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene18"); 
		break;

		case "bribing3":
			PlaySound("VOICE\ENGLISH\Eden_why.wav");			
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene20"); 
		break;

		case "bribing5":
			PlaySound("VOICE\ENGLISH\Eden_yeah.wav");			
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene23"); 
		break;

		case "bribing6":
			PlaySound("VOICE\ENGLISH\Eden_well.wav");			
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene25"); 
		break;

		case "bribing8":
			PlaySound("VOICE\ENGLISH\Eden_watch_closely.wav");			
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene30"); 
		break;

		case "bribing10":
			PlaySound("VOICE\ENGLISH\Eden_well.wav");			
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene32"); 
		break;

		case "bribing11":
			PlaySound("VOICE\ENGLISH\Eden_yeah.wav");			
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene35"); 
		break;

		case "bribing13":
			PlaySound("VOICE\ENGLISH\Eden_so.wav");			
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene37"); 
		break;

		case "bribing16":
			PlaySound("VOICE\ENGLISH\Eden_been_here.wav");			
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene43"); 
		break;

		case "bribing17":
			PlaySound("VOICE\ENGLISH\Eden_tracked_us.wav");			
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];  
			link.l1.go = "bribing18";
		break;

		case "bribing18":
			PlaySound("VOICE\ENGLISH\Eden_dangerous_alive.wav");			
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene49"); 
		break;

		case "bribing19":
			PlaySound("VOICE\ENGLISH\Eden_so.wav");			
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];  
			link.l1.go = "bribing20";
		break;

		case "bribing20":
			PlaySound("VOICE\ENGLISH\Eden_why.wav");			
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];  
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene57"); 
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
