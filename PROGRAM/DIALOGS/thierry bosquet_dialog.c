//#include "DIALOGS\thierry bosquet_dialog.h"
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
			Dialog.defAni = "Sit_Left_Strong_Yes";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_stay1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Left_Dialog_1";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if (npchar.quest.gambling == "done_1")
			{
				dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "exit";
			}
			if (npchar.quest.gambling == "done")
			{
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "exit";
			}
			if (npchar.quest.gambling == "done_1"  && pchar.location == "Falaise_de_fleur_jungle")
			{
				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "in_jungles";
			}
			if (npchar.quest.gambling == "0")
			{
				Dialog.text = DLG_TEXT[6];
				link.l1 = DLG_TEXT[7];
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[8];
				link.l2.go = "node_1";

			}
			if (npchar.quest.gambling == "2")
			{
				dialog.text = DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go = "payment";
			}
			if (npchar.quest.gambling =="1")
			{
				dialog.text = DLG_TEXT[11];
				link.l1 = DLG_TEXT[12];
				link.l1.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;

		case "fight":
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "fight_1";
		break;

		case "fight_1":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			pchar.quest.prepare_thierry_bosquet_fight.win_condition.l1 = "location";
			pchar.quest.prepare_thierry_bosquet_fight.win_condition.l1.location = "Falaise_de_Fleur_jungle";
			pchar.quest.prepare_thierry_bosquet_fight.win_condition = "prepare_thierry_bosquet_fight";
			npchar.quest.gambling = "done_1";
		break;

		case "node_1":
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "node_2";
			link.l2 = DLG_TEXT[19];
			link.l2.go = "exit";
		break;

		case "node_2":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			if (makeint(pchar.money) >= 500)
			{
				link.l2 = DLG_TEXT[22];
				link.l2.go = "node_3";
			}
		break;

		case "node_3":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[25];
			link.l2.go = "node_4";
		break;

		case "node_4":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			npchar.quest.gambling = "1";
		break;

		case "payment":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "payment_1";
		break;

		case "payment_1":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "fight";
		break;

		case "in_jungles":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
			npchar.quest.gambling = "done";
			AddDialogExitQuest("thierry_bosquet_fight");
		break;
	
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}