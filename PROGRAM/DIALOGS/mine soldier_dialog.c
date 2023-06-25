//#include "DIALOGS\mine soldier_dialog.h"

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
	
	// DeathDaisy: Persuasion tags for the skill checks, if enabled
	string PersuasionSuccess = "";
	string PersuasionFailure = "";
	if(PERSUASION_TAGS){ 
		PersuasionSuccess = XI_ConvertString("Persuasion_Success") + " ";
		PersuasionFailure = XI_ConvertString("Persuasion_Failure") + " ";
	}

	
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
			Dialog.snd = "voice\MISO\MISO001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "slave_in_oxbay_mine_begin_1" || pchar.quest.main_line == "blaze_in_mine")
			{
				Dialog.snd = "voice\MISO\MISO002";
				Dialog.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "node_2";
			}
			NextDiag.TempNode = "first time";
		break;

		case "node_2":
			Dialog.snd = "voice\MISO\MISO003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "node_3";
		break;

		case "node_3":
			Dialog.snd = "voice\MISO\MISO004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "node_4";
		break;

		case "node_4":
			if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 5)
			{
				Dialog.snd = "voice\MISO\MISO005";
				dialog.text = PersuasionSuccess + DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "exit";
				AddDialogExitQuest("mine_soldier_resque_exit");
			}
			else
			{
				Dialog.snd = "voice\MISO\MISO006";
				dialog.text = PersuasionFailure + DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "exit";
				AddDialogExitQuest("second_speak_with_leborio_in_mines");
			}
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
