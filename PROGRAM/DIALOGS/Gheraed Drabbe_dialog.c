//#include "DIALOGS\Gheraed Drabbe_dialog.h"

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
			Dialog.defAni = "Sit_Look_Around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Look_Around";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\GHDR\GHDR001";
			dialog.text = DLG_TEXT[0];
			if (CheckQuestAttribute("ANIMISTS", "to_douwesen_tavern2"))
			{
				link.l1 = DLG_TEXT[1];
				link.l1.go = "talk_1";
			}
			link.l99 = DLG_TEXT[2];
			link.l99.go = "exit";

			NextDiag.TempNode = "first time";
		break;

		case "talk_1":
			dialog.snd = "Voice\GHDR\GHDR002";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "talk_2";
		break;

		case "talk_2":
			dialog.snd = "Voice\GHDR\GHDR003";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "talk_3";
		break;

		case "talk_3":
			dialog.snd = "Voice\GHDR\GHDR004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
			if (characters[GetCharacterIndex("Alistair Garcilaso")].name == "Alistair")
			{
				pchar.quest.ANIMISTS = "to_greenford";
			}
			else
			{
				pchar.quest.ANIMISTS = "to_greenford_2";
			}
			AddQuestrecord("ANIMISTS", 4);
/*			pchar.quest.to_pirates_quest_ANIMISTS.win_condition.l1 = "location";
			pchar.quest.to_pirates_quest_ANIMISTS.win_condition.l1.location = "pirate_fort";
			pchar.quest.to_pirates_quest_ANIMISTS.win_condition = "to_pirates_quest_ANIMISTS_complete";*/
			npchar.location = "none";
			ChangeCharacterAddressGroup(characterFromID("Balltesar Figueiredo"), "Greenford_tavern", "sit", "sit7");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
