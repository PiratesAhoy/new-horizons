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
			Dialog.snd = "voice\MEHU\MEHU004";
			dialog.text = DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "to_barkue_4";
		break;

		case "to_barkue_4":
			Dialog.snd = "voice\MEHU\MEHU005";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			pchar.quest.ANIMISTS = "to_barkue_complete";
			AddDialogExitQuest("to_barkue_complete");
			npchar.location = "none";
			SetCompanionIndex(pchar, -1, GetCharacterIndex(npchar.id));
			SetCharacterRemovable(npchar, false);
		break;
			
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
