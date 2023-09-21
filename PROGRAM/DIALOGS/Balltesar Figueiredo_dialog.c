//#include "DIALOGS\Balltesar Figueiredo_dialog.h"

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
			Dialog.defAni = "Sit_look_around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_look_around";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\BAFI\BAFI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (CheckQuestAttribute("ANIMISTS", "to_greenford") || CheckQuestAttribute("ANIMISTS", "after_pirates") || CheckQuestAttribute("ANIMISTS", "after_samuelle"))
			{
				dialog.snd = "Voice\BAFI\BAFI002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "ANIMISTS_1";
			}
			NextDiag.TempNode = "first time";
		break;

		case "ANIMISTS_1":
			dialog.snd = "Voice\BAFI\BAFI003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "ANIMISTS_2";
		break;

		case "ANIMISTS_2":
			dialog.snd = "Voice\BAFI\BAFI004";
			dialog.text = DLG_TEXT[6];
			if (makeint(pchar.money) >= 1)
			{
				link.l1 = DLG_TEXT[7];
				link.l1.go = "ANIMISTS_3";
			}
			link.l2 = DLG_TEXT[8];
			link.l2.go = "ANIMISTS_bad";
		break;

		case "ANIMISTS_3":
			dialog.snd = "Voice\BAFI\BAFI005";
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "ANIMISTS_4";
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(pchar, -1);
		break;

		case "ANIMISTS_4":
			dialog.snd = "Voice\BAFI\BAFI006";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "ANIMISTS_5";
		break;

		case "ANIMISTS_5":
			dialog.snd = "Voice\BAFI\BAFI007";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_qc";
			npchar.location = "none";
			AddQuestrecord("ANIMISTS", 6);
		break;

		case "ANIMISTS_bad":
			dialog.snd = "Voice\BAFI\BAFI008";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "ANIMISTS_4";
			OfficersReaction("bad");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
