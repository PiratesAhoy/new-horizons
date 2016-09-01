//#include "DIALOGS\William Blaker_dialog.h"
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
			Dialog.snd = "voice\WIBL\WIBL001";
			NPChar.dialog.firstRun = "run";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if( CheckQuestAttribute("story_FindRheims","Rheims_info_denied") )
			{
				Dialog.snd = "voice\WIBL\WIBL002";
				dialog.text = DLG_TEXT[2]+GetCharacterFullName(DLG_TEXT[3]) + DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "FindRheims_1";
			}
		break;

		case "FindRheims_1":
			Dialog.snd = "voice\WIBL\WIBL003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			if( CalcCharacterSkill(PChar,SKILL_LEADERSHIP)>4 )	link.l1.go = "FindRheims_2";
			else	link.l1.go = "FindRheims_3";
			if( sti(PChar.Money)>=10 )
			{
				link.l2 = DLG_TEXT[8];
				link.l2.go = "FindRheims_4";
			}
			link.l3 = DLG_TEXT[9];
			link.l3.go = "FindRheims_5";
		break;

		case "FindRheims_2":
			Dialog.snd = "voice\WIBL\WIBL004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "FindRheims_story";
		break;

		case "FindRheims_3":
			Dialog.snd = "voice\WIBL\WIBL005";
			dialog.text = DLG_TEXT[12];
			link.l1 = RandSwear()+DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("Danielle_QC_tavern_kick");
		break;

		case "FindRheims_4":
			Dialog.snd = "voice\WIBL\WIBL006";
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar,-10);
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "FindRheims_story";
		break;

		case "FindRheims_5":
			Dialog.snd = "voice\WIBL\WIBL007";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "FindRheims_story":
			Dialog.snd = "voice\WIBL\WIBL008";
			dialog.text = DLG_TEXT[18]+GetCharacterFullName(DLG_TEXT[19])+DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "FindRheims_story_1";
		break;

		case "FindRheims_story_1":
			Dialog.snd = "voice\WIBL\WIBL009";
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "FindRheims_story_2";
		break;

		case "FindRheims_story_2":
			Dialog.snd = "voice\WIBL\WIBL010";
			dialog.text = DLG_TEXT[24]+GetCharacterFullName(DLG_TEXT[25])+DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddQuestRecord("Story_Find_Rheims",105);
			PChar.quest.story_FindRheims = "to_Camilo_Machado";
		break;

		case "exit":
			DialogExit();
		break;
	}
}
