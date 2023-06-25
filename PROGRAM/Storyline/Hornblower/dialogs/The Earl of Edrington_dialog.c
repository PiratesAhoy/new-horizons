//#include "DIALOGS\Bartholomew Roberts_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	string voice_path = "VOICE\ENGLISH\";
	if (CheckDirectory("RESOURCE\Sounds\VOICE\"+LanguageGetLanguage()+"\","*") > 0) voice_path = "VOICE\" + LanguageGetLanguage() + "\";

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

			PlaySound(voice_path + "Edrington1.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Who's_in_charge":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Who's_in_charge2";
		break;

		case "Who's_in_charge2":
			LAi_SetActorType(characterFromID("Richard Sharpe"));
			LAi_SetActorType(characterFromID("Patrick Harper"));
			LAi_SetActorType(characterFromID("Rifleman Tongue"));
			LAi_SetActorType(characterFromID("Rifleman Harris"));
			LAi_SetActorType(characterFromID("Rifleman Haggman"));
			LAi_SetActorType(characterFromID("Rifleman Mansfield"));
			PlaySound(voice_path + "Edrington1.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Who's_in_charge3";
		break;

		case "Who's_in_charge3":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Who's_in_charge3A";
		break;

		case "Who's_in_charge3A":
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "goto16", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "goto19", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "goto", "goto22", "",0.0);
//			LAi_ActorGoToLocator(characterFromID("Rifleman Harris"), "goto", "goto25", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "goto", "goto27", "",0.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Mansfield"), "goto", "goto28", "",0.0);
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Who's_in_charge4";
		break;

		case "Who's_in_charge4":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Who's_in_charge5";
		break;

		case "Who's_in_charge5":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Who's_in_charge5A";
		break;

		case "Who's_in_charge5A":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Who's_in_charge6";
		break;

		case "Who's_in_charge6":
			LAi_ActorTurnToCharacter(characterFromID("Richard Sharpe"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Patrick Harper"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Tongue"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Harris"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Haggman"),(Pchar));
			LAi_ActorTurnToCharacter(characterFromID("Rifleman Mansfield"),(Pchar));
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "Who's_in_charge7";
		break;

		case "Who's_in_charge7":
			PlaySound(voice_path + "Edrington3.wav");
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Who's_in_charge8";
		break;

		case "Who's_in_charge8":
			LAi_SetOfficerType(characterFromID("Richard Sharpe"));
//			LAi_ActorTurnToCharacter((Pchar), characterFromID("Arthur Wellesley"));
			LAi_ActorTurnToCharacter(characterFromID("The Earl of Edrington"), characterFromID("Arthur Wellesley"));
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit_Who's_in_charge";
		break;

		case "Exit_Who's_in_charge":
			AddDialogExitQuest("On_to_the_Valley_for_battle");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Awoke_the_French":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Awoke_the_French2";
		break;

		case "Awoke_the_French2":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Awoke_the_French3";
		break;

		case "Awoke_the_French3":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "Awoke_the_French4";
		break;

		case "Awoke_the_French4":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Awoke_the_French5";
		break;

		case "Awoke_the_French5":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Awoke_the_French6";
		break;

		case "Awoke_the_French6":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit_Awoke_the_French";
		break;

		case "Exit_Awoke_the_French":
			AddDialogExitQuest("The_final_stand");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "About_face":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Exit_About_face";
		break;

		case "Exit_About_face":
			AddDialogExitQuest("The_final_stand3");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "set_up_the_troops":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "Exit_set_up_the_troops";
		break;

		case "Exit_set_up_the_troops":
			AddDialogExitQuest("Manned_and_ready");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "You_are_under_arrest":
			PlaySound(voice_path + "Edrington4.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "You_are_under_arrest2";
		break;

		case "You_are_under_arrest2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "You_are_under_arrest3";
		break;

		case "You_are_under_arrest3":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "You_are_under_arrest4";
		break;

		case "You_are_under_arrest4":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "Exit_You_are_under_arrest";
		break;

		case "Exit":
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Exit_You_are_under_arrest":
			AddDialogExitQuest("A_trial_for_treason");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

	}
}

