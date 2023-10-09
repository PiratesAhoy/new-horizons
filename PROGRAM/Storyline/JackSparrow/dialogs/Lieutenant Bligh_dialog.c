//#include "DIALOGS\Bartholomew Roberts_dialog.h"
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

			Dialog.mood = "normal";

			dialog.snd = "Voice\ARSI\ARSI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";

		break;

		case "First_meet_Bligh":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "First_meet_Bligh2";
		break;

		case "First_meet_Bligh2":
			Change_Mood("angry");

			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_first_meet";
		break;

		case "meet_Bligh_in_Guadeloupe":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "meet_Bligh_in_Guadeloupe2";
		break;

		case "meet_Bligh_in_Guadeloupe2":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "meet_Bligh_in_Guadeloupe3";
		break;

		case "meet_Bligh_in_Guadeloupe3":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "meet_Bligh_in_Guadeloupe4";
		break;

		case "meet_Bligh_in_Guadeloupe4":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "Exit_meet_Bligh_in_Guadeloupe";
		break;

		case "False Colours":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "False Colours2";
		break;

		case "False Colours2":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			if(HasThisShip("Black Pearl")) link.l1.go = "False Colours3";
			else link.l1.go = "False Colours3_no_Pearl";
		break;

		case "False Colours3":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "False Colours4";
		break;

		case "False Colours3_no_Pearl":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			if (LAi_IsDead(characterFromID("Mergildo Hurtado")))
			{
				AddDialogExitQuest("Mercer_False_die");
			}
			else
			{
				AddDialogExitQuest("Mercer_False_surv");
			}
		break;

		case "False Colours4":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			if (LAi_IsDead(characterFromID("Mergildo Hurtado")))
			{
				AddDialogExitQuest("Mercer_False_die");
			}
			else
			{
				AddDialogExitQuest("Mercer_False_surv");
			}
		break;

		case "Exit_meet_Bligh_in_Guadeloupe":
			AddDialogExitQuest("Goodbye_to_Lieutenant Bligh");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_first_meet":
			LAi_SetActorType(characterFromID("Lieutenant Bligh"));
			AddDialogExitQuest("having_met_Bligh");
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit":
			Dialog.CurrentNode = "First time";
			DialogExit();
		break;

	}
}

