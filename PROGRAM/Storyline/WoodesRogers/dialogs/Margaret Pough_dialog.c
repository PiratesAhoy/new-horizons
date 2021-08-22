//#include "DIALOGS\John Long_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			Dialog.snd = "voice\PADI\PADI001";
			
			Diag.TempNode = "first time";
		break;

		case "what":
			PlaySound("VOICE\ENGLISH\Eng_f_c_001.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "what1";
		break;

		case "what1":
			PlaySound("VOICE\ENGLISH\Eng_f_c_004.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "what2";
		break;

		case "what2":
			PlaySound("VOICE\ENGLISH\Eng_f_c_002.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "what3";
		break;

		case "what3":
			PlaySound("VOICE\ENGLISH\Eng_f_c_006.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("Pough_done");
		break;

		case "unlock":
			PlaySound("VOICE\ENGLISH\Eng_f_c_005.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "unlock1";
		break;

		case "unlock1":
			PlaySound("VOICE\ENGLISH\Eng_f_c_002.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "unlock2";
		break;

		case "unlock2":
			PlaySound("VOICE\ENGLISH\Eng_f_c_003.wav");
			Dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			AddDialogExitQuest("Pough2_done");
		break;

		case "chapel":
			PlaySound("VOICE\ENGLISH\Eng_f_c_007.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "chapel1";
		break;

		case "chapel1":
			PlaySound("VOICE\ENGLISH\Eng_f_c_003.wav");
			Dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			
			if(IsOfficer(CharacterFromID("Hands")))				
			{
				link.l1.go = "exit";
				AddDialogExitQuest("Pough3_done");
			}
			else link.l1.go = "chapel2";
		break;

		case "chapel2":
			PlaySound("VOICE\ENGLISH\Eng_f_c_001.wav");
			Dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
			AddDialogExitQuest("Pough3_done_no_Hands");
		break;

		case "Tobias_Knight":
			PlaySound("VOICE\ENGLISH\Eng_f_c_003.wav");
			Dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("Pough4_done");
		break;

		case "neutral":
			PlaySound("VOICE\ENGLISH\Eng_f_c_005.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("Pough2_done");
		break;

		case "Knight_hurt":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Caesar"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("black_servant1"));
			PlaySound("VOICE\ENGLISH\Eng_f_c_016.wav");
			Dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "exit";
			AddDialogExitQuest("Estate_end2");
		break;

		case "sell_the_slave":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Caesar"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("black_servant1"));
			PlaySound("VOICE\ENGLISH\Eng_f_c_018.wav");
			Dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "exit";
			AddDialogExitQuest("Estate_end6");
		break;

		case "stop_them":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Caesar"));
			LAi_SetActorType(Pchar);
			LAi_ActorTurnToCharacter(Pchar, characterFromID("black_servant1"));
			PlaySound("OBJECTS\DUEL\woman_hit3.wav");
			Dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("Estate_end8");
		break;

		case "hostile":
			PlaySound("OBJECTS\VOICES\DEAD\female\dead_wom5.wav");
			Dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			Diag.TempNode = "hostile";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
