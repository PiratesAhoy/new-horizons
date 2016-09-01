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

			if(NPChar.id == "Fletcher Christian")
			{
				PlaySound("VOICE\ENGLISH\pir_capQ.wav");
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[13];
				link.l1.go = "Exit";
			} 
		
			if(NPChar.id == "Constable Mills")
			{
				PlaySound("VOICE\ENGLISH\Mutineer_Mills.wav");
				dialog.text = DLG_TEXT[16];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "Exit";
			} 

			if(NPChar.id == "Midshipman Young")
			{
				PlaySound("VOICE\ENGLISH\pir_capEE.wav");
				dialog.text = DLG_TEXT[14];
				link.l1 = DLG_TEXT[15];
				link.l1.go = "Exit";
			} 

			NextDiag.TempNode = "First time";
		break;


		case "Young":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
			PlaySound("VOICE\ENGLISH\Mutineer_Young.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_cabin3");
		break;

		case "Mills":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "goto", "goto8");
			PlaySound("VOICE\ENGLISH\Mutineer_Mills.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_cabin4");
		break;

		case "Christian":
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
			PlaySound("VOICE\ENGLISH\Mutineer_Christian.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_cabin5");
		break;

		case "Christian2":
			PlaySound("VOICE\ENGLISH\pir_capM.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit";
			AddDialogExitQuest("mutiny_officers2");
		break;

		case "Young2":
			PlaySound("VOICE\ENGLISH\pir_capC.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Exit";
	//	NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers4");
		break;
		
		case "Mills2":
			PlaySound("VOICE\ENGLISH\gm_crew16B.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Exit";
	//	NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers6");
		break;
	//-----------------------------------------------------------
		case "Mills3":
			PlaySound("VOICE\ENGLISH\Mutineer_Mills.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers9");
		break;

		case "Young3":
			PlaySound("VOICE\ENGLISH\pir_capEE.wav");
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers10");
		break;

		case "Christian3":
			PlaySound("VOICE\ENGLISH\pir_capQ.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		NextDiag.TempNode = "First time";
			AddDialogExitQuest("mutiny_officers11");
		break;


	//-----------------------------------------------------------
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
