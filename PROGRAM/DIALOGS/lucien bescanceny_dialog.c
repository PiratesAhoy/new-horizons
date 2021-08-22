//#include "DIALOGS\lucien bescanceny_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

void ProcessDialogEvent()
{
	ref NPChar;
	
	DeleteAttribute(&Dialog,"Links");
	aref Link, NextDiag;
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
			Dialog.snd = "dialogs\0\009";

			Dialog.Text = DLG_TEXT[0];
			if (characters[GetCharacterIndex("Patric Cardone")].quest.teodoro == "4" || characters[GetCharacterIndex("Patric Cardone")].quest.teodoro == "6")
			{
				Link.l1 = DLG_TEXT[1] + GetMyName(NPChar) + DLG_TEXT[2];
				Link.l1.go = "node_1";
			}
			else
			{
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = GetMyName(NPChar) + DLG_TEXT[5];
			Link.l1.go ="node_2";
		break;

		case "node_2":
			Dialog.text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "node_3";
		break;

		case "node_3":
			Dialog.text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "node_4";
		break;

		case "node_4":
			Dialog.text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "node_5";
			Link.l2 = DLG_TEXT[12] + GetMyName(NPChar) + DLG_TEXT[13];
			Link.l2.go = "node_6";
		break;

		case "node_5":
			Dialog.text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "node_5_1";
		break;

		case "node_5_1":
			Dialog.text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "node_5_2";
		break;

		case "node_5_2":
			Dialog.text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "node_5_3";
		break;

		case "node_5_3":
			Dialog.text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "node_5_4";
			Link.l2 = DLG_TEXT[22] + GetMyName(NPChar) + DLG_TEXT[23];
			Link.l2.go = "node_6";
		break;

		case "node_5_4":
			Dialog.text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "node_5_5";
		break;

		case "node_5_5":
			Dialog.text = RandSwear();
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			AddDialogExitQuest("lucient_bescanceny_fight");
		break;

		case "node_6":
			Dialog.text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "node_6_1";
		break;

		case "node_6_1":
			Dialog.text = RandSwear();
			Link.l1 = DLG_TEXT[29];
			Link.l1.go = "node_7";
		break;

		case "node_7":
			int i = Rand (4);
			if (i == 4)
			{
				Dialog.text = DLG_TEXT[30];
				Link.l1 = DLG_TEXT[31];
				Link.l1.go = "exit";
				AddDialogExitQuest("lucient_bescanceny_fight");
			}
			else
			{
				Dialog.text = DLG_TEXT[32];
				Link.l1 = DLG_TEXT[33];
				link.l1.go = "node_8";
			}
		break;

		case "node_8":
			if (makeint(PChar.reputation) > 9)
			{
				Dialog.text = DLG_TEXT[34];
				Link.l1 = DLG_TEXT[35];
				Link.l1.go = "node_9";
			}
			else
			{
				Dialog.text = DLG_TEXT[36];
				Link.l1 = DLG_TEXT[37];
				link.l1.go = "exit";   
				AddDialogExitQuest("lucient_bescanceny_fight");
			}
		break;

		case "node_9":
			dialog.text = DLG_TEXT[38];
			Link.l1 = DLG_TEXT[39];
			Link.l1.go = "exit";
			Characters[GetCharacterIndex("Patric Cardone")].quest.teodoro = "5"; // NK thanks to Taghmon
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 1000);
				AddPartyExpChar(pchar, "Sneak", 10);
			}
			else { AddPartyExp(pchar, 1000); }
			Preprocessor_AddQuestData("Lucien", GetMyName(NPChar));
			Preprocessor_AddQuestData("Patric", GetMyName(CharacterFromID("Patric Cardone")));
			AddQuestRecord("Patric", 5); // NK
			Preprocessor_Remove("Patric");
			Preprocessor_Remove("Lucien");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode =  NextDiag.TempNode;
		break;
	}
}
