//#include "DIALOGS\Emmanuel Devlin_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
			
			dialog.snd = "Voice\DASA\DASA001";
			Dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Exit";

			if (checkquestattribute("Bonnie_talk", "meeting_her_father"))
			{
				dialog.snd = "Voice\DASA\DASA002";
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "node_2";
			}
		break;

		case "node_2":
			dialog.snd = "Voice\DASA\DASA005";
			Dialog.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "node_3";
		break;

		case "node_3":
			dialog.snd = "Voice\DASA\DASA005";
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "node_4";
		break;

		case "node_4":
			dialog.snd = "Voice\DASA\DASA005";
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "node_5";
		break;

		case "node_5":
			dialog.snd = "Voice\DASA\DASA005";
			Dialog.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "node_6";
		break;

		case "node_6":
			dialog.snd = "Voice\DASA\DASA005";
			Dialog.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "exit_to_find_sister";
		break;
		
		case "exit_to_ship":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("exit_to_ship");
		break;

		case "exit_to_find_sister":
			pchar.quest.Bonnie_talk = "Our_first_meeting";		
			AddQuestRecord("Mystery Messenger and a letter", 2);
			GiveItem2Character(PChar, "compass3");
			EquipCharacterByItem(pchar, "compass3");
			GiveItem2Character(pchar, "spyglass4");
			EquipCharacterByItem(pchar, "spyglass4");
			GiveItem2Character(pchar, "blade13+1");
			EquipCharacterByItem(pchar, "blade13+1");
			GiveItem2Character(Pchar, "pistol5+2");
			EquipCharacterByItem(pchar, "pistol5+2");
			GiveItem2Character(PChar, "first_part_map");		
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("Look_for_my_sister");			
		break;		
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
