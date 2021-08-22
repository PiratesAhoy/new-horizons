//#include "DIALOGS\Mergildo Hurtado_dialog.h"
	
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
			Dialog.snd = "voice\MEHU\MEHU001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (CheckQuestAttribute("ANIMISTS", "to_barkue"))
			{
				Dialog.snd = "voice\MEHU\MEHU002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "to_barkue_2";
			}
		break;

		case "to_barkue_2":
			Dialog.snd = "voice\MEHU\MEHU003";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "to_barkue_3";
		break;

		case "to_barkue_3":
			Dialog.snd = "voice\MEHU\MEHU003";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "to_barkue_4";
		break;

		case "to_barkue_4":
			Dialog.snd = "voice\MEHU\MEHU004";
			dialog.text = DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			if (GetCompanionQuantity(PChar) < COMPANION_MAX) link.l1.go = "to_barkue_5";
			else link.l1.go = "too_many_ships";
		break;

		case "to_barkue_5":
			Dialog.snd = "voice\MEHU\MEHU005";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_barkue_complete";
			AddDialogExitQuest("to_barkue_complete");
			npchar.location = "none";
			SetCompanionIndex(pchar, -1, GetCharacterIndex(npchar.id));
			SetCharacterRemovable(npchar, false);
		break;

// GR: fix for Mergildo unable to join you if you have a full fleet -->
		case "too_many_ships":
			int numships = GetCompanionQuantity(PChar);
			Dialog.snd = "voice\MEHU\MEHU004";
			Preprocessor_Add("numships", numships);
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			AddDialogExitQuest("to_barkue_too_many_ships");
			NextDiag.TempNode = "too_many_ships_recheck";
			link.l1.go = "exit";
		break;

		case "too_many_ships_recheck":
			Dialog.snd = "voice\MEHU\MEHU005";
			if (GetCompanionQuantity(PChar) < COMPANION_MAX)
			{
				dialog.text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[12];
				link.l1.go = "exit";
				PChar.quest.ANIMISTS = "to_barkue_complete";
				AddDialogExitQuest("to_barkue_complete");
				NPChar.location = "none";
				SetCompanionIndex(PChar, -1, GetCharacterIndex(NPChar.id));
				SetCharacterRemovable(NPChar, false);
				bQuestDisableSeaEnter = false;	// Mergildo should now join you, so unlock sea
			}
			else
			{
				dialog.text = DLG_TEXT[14];
				link.l1 = DLG_TEXT[21];
				link.l1.go = "exit";
			}
		break;
// <-- GR: end of fix

		case "Aye_Captain":
			Dialog.text = DLG_TEXT[13];
			link.l1.go = "exit";
			if (GetAttribute(Pchar, "Colours") == "1")
			{
				AddDialogExitQuest("To_Do");
			}
			else
			{
				AddDialogExitQuest("Not_to_Do");
			}
		break;

		case "False Colours":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "False Colours2";
		break;

		case "False Colours2":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
			AddDialogExitQuest("Mercer_False_surv_talk2");
			AddQuestRecord("Sao Feng", 1);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
