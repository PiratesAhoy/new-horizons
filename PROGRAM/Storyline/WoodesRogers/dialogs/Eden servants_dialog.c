//#include "DIALOGS\Tom Morgan_dialog.h"
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
		
			Pchar.servants_info = "1";		//basic info, before behind curtain etc

			if(NPChar.id == "Caesar") 
			{
				PlaySound("VOICE\ENGLISH\gm_crew5B.wav");
			}
			else PlaySound("VOICE\ENGLISH\Poe_look.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "look_around";
		break;

		case "look_around":
			if(NPChar.id == "Caesar") 
			{
				PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			}
			else PlaySound("VOICE\ENGLISH\Poe_very_nice.wav");

			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			Diag.TempNode = "repeat_look_around";
			AddDialogExitQuest("servant_is_Caesar6");
		break;

		case "repeat_look_around":
			if(NPChar.id == "Caesar") 
			{
				PlaySound("VOICE\ENGLISH\gm_crew7.wav");
			}
			else PlaySound("VOICE\ENGLISH\Poe_very_nice.wav");

			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			Diag.TempNode = "repeat_look_around";
			AddDialogExitQuest("servant_is_Caesar7");
		break;

		case "who_are_you":
			LAi_SetActorType(NPchar);
			LAi_ActorTurnToCharacter(NPchar, characterFromID("Caesar"));
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			PlaySound("VOICE\ENGLISH\Poe_ooh.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("servant_is_Caesar4");
		break;

		case "locked_doors":
			Pchar.servants_info = "3";		//behind curtain info

			if(NPChar.id == "Caesar") 
			{
				PlaySound("OBJECTS\VOICES\DEAD\male\dead1.wav");
			}
			else PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "locked_doors1";
		break;

		case "locked_doors1":
			if(NPChar.id == "Caesar") 
			{
				PlaySound("OBJECTS\DUEL\man_hit1.wav");
			}
			else PlaySound("VOICE\ENGLISH\Poe_look.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
			Diag.TempNode = "locked_doors1";
			AddDialogExitQuest("behind_curtain");
		break;

		case "what_are_you_doing":
			if(NPChar.id == "Caesar") 
			{
				PlaySound("OBJECTS\DUEL\man_hit1.wav");
			}
			else PlaySound("OBJECTS\VOICES\DEAD\male\dead6.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			Diag.TempNode = "repeat_look_around";
			AddDialogExitQuest("Eden_office_done3");
		break;
	
		case "Caesar_pirate":
			LAi_SetActorType(characterFromID("black_servant1"));
			LAi_ActorTurnToCharacter(characterFromID("black_servant1"), characterFromID("Caesar"));

			PlaySound("VOICE\ENGLISH\Poe_obvious.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("Estate_end4");
		break;

		case "hostile":
			PlaySound("VOICE\ENGLISH\Poe_well.wav");
			Dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			Diag.TempNode = "hostile";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
