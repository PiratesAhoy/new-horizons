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

			if(NPChar.id == "bb_crew8")
			{ 
				PlaySound("VOICE\ENGLISH\Barbossa01.wav");
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
				AddDialogExitQuest("Charleston_gp_explosion4");
			}

			if(NPChar.id == "bb_crew5")
			{ 
				PlaySound("VOICE\ENGLISH\pir_capFF.wav");
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
				AddDialogExitQuest("Charleston_gp_explosion7");
			}

			if(NPChar.id == "Richards")
			{ 
				PlaySound("OBJECTS\DUEL\man_hit1.wav");
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "Richards1";
			}
			
			Diag.TempNode = "first time";
		break;

		case "Richards1":
			PlaySound("VOICE\ENGLISH\blaze_drunk2.wav");
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Richards_back11");
		break;

		case "Richards_huh":
			PlaySound("VOICE\ENGLISH\gm_crew5C.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "Richards_huh1";
		break;

		case "Richards_huh1":
			PlaySound("VOICE\ENGLISH\gm_crew5A.wav");
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("Richards_back15");
		break;

		case "neutral":
			if(NPChar.id == "bb_crew8")
			{ 
				PlaySound("VOICE\ENGLISH\Barbossa01.wav");
				dialog.text = DLG_TEXT[13];
				link.l1 = DLG_TEXT[15];
				link.l1.go = "exit";
			}

			if(NPChar.id == "bb_crew5")
			{ 
				PlaySound("VOICE\ENGLISH\pir_capFF.wav");
				dialog.text = DLG_TEXT[12];
				link.l1 = DLG_TEXT[16];
				link.l1.go = "exit";
			}

			if(NPChar.id == "Richards")
			{ 
				PlaySound("OBJECTS\DUEL\man_hit1.wav");
				dialog.text = DLG_TEXT[14];
				link.l1 = DLG_TEXT[17];
				link.l1.go = "exit";
			}
			AddDialogExitQuest("bb_crew2_neutral_done");
		break;

		case "more_dutch":
			//Richards
			LAi_ActorTurnToCharacter(characterFromID("Richards"), characterFromID("Eden"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));
		
			PlaySound("OBJECTS\DUEL\man_hit1.wav");
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene27");
		break;

		case "spanish_crew":
			//gunner Morton
			LAi_ActorTurnToCharacter(characterFromID("bb_crew5"), characterFromID("Eden"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("Eden"));
			
			PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene28");
		break;

		case "no_crew":
			//qm Miller
			LAi_ActorTurnToCharacter(characterFromID("bb_crew8"), characterFromID("bb_crew5"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("bb_crew8"));
		
			PlaySound("VOICE\ENGLISH\Barbossa01.wav");
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene29");
		break;

		case "cargo_sugar":
			//qm Miller
			LAi_ActorTurnToCharacter(characterFromID("bb_crew8"), characterFromID("Teach"));
			LAi_ActorTurnToCharacter(Pchar, characterFromID("bb_crew8"));
			LAi_ActorTurnToCharacter(characterFromID("Teach"), characterFromID("bb_crew8"));
		
			PlaySound("VOICE\ENGLISH\pir_capC.wav");
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("Eden_bribing_scene38");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
