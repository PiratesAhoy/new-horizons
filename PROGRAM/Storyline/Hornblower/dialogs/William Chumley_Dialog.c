//#include "DIALOGS\Morgan Terror_Dialog.h"
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
			Dialog.snd = "dialogs\0\009";

			if(CheckQuestAttribute("Soldier_Company", "Foot"))
			{
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
			}
			if(CheckQuestAttribute("Soldier_Company", "Rifles"))
			{
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Exit";
			}
		break;

		case "landed_at_French_Beach":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "Exit_landed_at_French_Beach";
		break;

		case "Exit_landed_at_French_Beach":
			AddDialogExitQuest("Now_the_French");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Prepare_for_Battle":
			dialog.text = DLG_TEXT[6] + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit_Prepare_for_Battle";
		break;

		case "Exit_Prepare_for_Battle":
			AddDialogExitQuest("Face_Off");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "French_Battle_over":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "French_Battle_over2";
		break;

		case "French_Battle_over2":
			PlaySound("OBJECTS\DUEL\French_DrumsB.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			LAi_ActorGoToLocator(characterFromID("Richard Sharpe"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Cooper"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Haggman"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Patrick Harper"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Tongue"), "goto", "citizen06", "",25.0);
			LAi_ActorGoToLocator(characterFromID("Rifleman Higgins"), "goto", "citizen06", "",25.0);
			link.l1.go = "French_Battle_over3";
		break;

		case "French_Battle_over3":
			dialog.text = DLG_TEXT[12] + Pchar.lastname + ".";
			link.l1 = DLG_TEXT[14];
			link.l1.go = "French_Battle_over4";
		break;

		case "French_Battle_over4":
			dialog.text = DLG_TEXT[15] + Pchar.lastname + DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_French_Battle_over";
		break;

		case "Exit_French_Battle_over":
			AddDialogExitQuest("Battle_over_now_Redmond");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "Battle_over_now_Oxbay":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_Battle_over_now_Oxbay";
		break;

		case "Exit_Battle_over_now_Oxbay":
			AddDialogExitQuest("Pellew_sends_you_to_Greenford");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "I_have_to_arrest_you":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "I_have_to_arrest_you2";
		break;

		case "I_have_to_arrest_you2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit_I_have_to_arrest_you";
		break;

		case "Exit_I_have_to_arrest_you":
			AddDialogExitQuest("The_Court_Martial_Begins");
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

		case "exit":
			Diag.CurrentNode = "First time";
			DialogExit();
		break;

	
			}
}
