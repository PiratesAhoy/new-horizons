//#include "DIALOGS\Redmond Soldier_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_go_away":
			float locx;
			float locy;
			float locz;
			string goawaylocator;
			GetCharacterPos(NPChar, &locx, &locy, &locz);
			goawaylocator = LAi_FindNearestFreeLocator("patrol", locx, locy, locz);
			LAi_SetActorType(NPchar);
			LAi_ActorGoToLocator(NPchar, "patrol", goawaylocator, "", 10.0);

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;


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

			if(NPChar.id == "Bessop_guard1")
			{
				PlaySound("VOICE\ENGLISH\pir_capM.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			else
			{
				if(NPChar.id == "Bessop_guard2")
				{
					PlaySound("VOICE\ENGLISH\pir_capEE.wav");
					dialog.text = DLG_TEXT[0];
					link.l1 = DLG_TEXT[1];
					link.l1.go = "exit";
				}
			}
			else
			{
				//patrol				

				int patrolvoice = rand(2);
				switch (patrolvoice)
				{
					case 0:
						PlaySound("VOICE\ENGLISH\blaze_what_was_that.wav");
					break;

					case 1:
						PlaySound("VOICE\ENGLISH\blaze_heard_something.wav");
					break;

					case 2:
						PlaySound("VOICE\ENGLISH\blaze_huh.wav");
					break;
				}

				if(CheckAttribute(Pchar,"quest.bessop_pchar_safe") && Pchar.quest.bessop_pchar_safe == "yes")
				{
					LAi_SetSitType(Pchar);
				}

				dialog.text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "exit_go_away";
				AddDialogExitQuest("bessop_hide_from_patrol");
			}

	/*
			if(NPChar.id == "Bessop_guard1") PlaySound("VOICE\ENGLISH\pir_capM.wav");
			if(NPChar.id == "Bessop_guard2") PlaySound("VOICE\ENGLISH\pir_capEE.wav");
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
	*/
		break;

		case "no_entrance1":
			PlaySound("VOICE\ENGLISH\pir_capKK.wav");
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			AddDialogExitQuest("no_entrance1_done");
		break;

		case "no_entrance2":
			PlaySound("VOICE\ENGLISH\pir_capHH.wav");
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("no_entrance2_done");
		break;

		case "no_entrance3":
			PlaySound("VOICE\ENGLISH\pir_capFF.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("no_entrance3_done");
		break;

		case "no_entrance4":
			PlaySound("VOICE\ENGLISH\pir_capFFF.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			AddDialogExitQuest("no_entrance4_done");
		break;
	}
}
