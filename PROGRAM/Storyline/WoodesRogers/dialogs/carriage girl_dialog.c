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

			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "merchant", "girl_look");	
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "merchant", "carriage_look");	

			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				PlaySound("VOICE\ENGLISH\fre_f_a_009.wav");	
				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "exit";
				AddDialogExitQuest("carriage_girl_end"); 
			}
			else
			{
				PlaySound("VOICE\ENGLISH\fre_f_a_012.wav");	
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "carriage_girl";
			}

			Diag.TempNode = "first time";
		break;

		case "carriage_girl":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "merchant", "girl_look");	
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "merchant", "carriage_look");	

			PlaySound("VOICE\ENGLISH\fre_f_a_007.wav");			
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];  
			link.l1.go = "carriage_girl1";
		break;

		case "carriage_girl1":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "merchant", "girl_look");	
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "merchant", "carriage_look");	

			PlaySound("VOICE\ENGLISH\fre_f_a_003.wav");			
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];  
			link.l1.go = "carriage_girl2";
		break;

		case "carriage_girl2":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "merchant", "girl_look");	
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "merchant", "carriage_look");	

			PlaySound("VOICE\ENGLISH\fre_f_a_001.wav");			
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];  
			link.l1.go = "carriage_girl3";
		break;

		case "carriage_girl3":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "merchant", "girl_look");	
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "merchant", "carriage_look");	

			PlaySound("VOICE\ENGLISH\fre_f_a_005.wav");			
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];  
			link.l1.go = "carriage_girl4";
		break;

		case "carriage_girl4":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToLocator(NPchar, "merchant", "girl_look");	
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "merchant", "carriage_look");	

			PlaySound("VOICE\ENGLISH\fre_f_a_009.wav");			
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];  
			link.l1.go = "exit";
			AddDialogExitQuest("carriage_girl_end"); 
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
