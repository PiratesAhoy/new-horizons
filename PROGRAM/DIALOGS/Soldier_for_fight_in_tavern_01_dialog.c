//#include "DIALOGS\Soldier_for_fight_in_tavern_01_dialog.h"

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
			
		case "DieMotherFucker":

			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\SFNT\SFNT001";

			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "DieMotherFucker_2";
		break;	
			
		case "First time":

			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";			
			
			//потасовка в таверне
			if (pchar.quest.main_line == "talk_in_tavern_begin")
			{
				if (pchar.id == "Danielle")
				{
					Dialog.snd = "voice\SFNT\SFNT002";
					Dialog.Text = DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4];
					Link.l1 = DLG_TEXT[5];
					Link.l1.go = "node_2_danielle";
				}
				else
				{
					Dialog.snd = "voice\SFNT\SFNT003";
					dialog.text = DLG_TEXT[6];
					link.l1 = DLG_TEXT[7];
					link.l1.go = "node_2_kick";
				}
			}
			//арест блейза
			if (pchar.quest.main_line == "fawn_death")
			{
				Dialog.snd = "voice\SFNT\SFNT004";
				dialog.text = DLG_TEXT[8] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go = "node_3_blaze";
			}
			if (pchar.quest.main_line == "after_soldier_kick")
			{
				Dialog.snd = "voice\SFNT\SFNT005";
				dialog.text = DLG_TEXT[11];
				link.l1 = DLG_TEXT[12];
				link.l1.go = "exit";
				AddDialogExitQuest("fighting_in_tavern");
			}
		break;

		case "DieMotherFucker_2":
			Dialog.snd = "voice\SFNT\SFNT006";
			Dialog.Text = DLG_TEXT[13] + characters[GetCharacterIndex(DLG_TEXT[14])].lastname + DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "DieMotherFucker_3";
		break;

		case "DieMotherFucker_3":
			Dialog.snd = "voice\SFNT\SFNT007";
			AddDialogExitQuest("Fem_BoatswainFoundsTheClue");
			Dialog.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "exit";
		break;

		case "node_2_kick":
			Dialog.snd = "voice\SFNT\SFNT008";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "node_2_kick_2";
		break;

		case "node_2_kick_2":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			AddDialogExitQuest("kicked_by_soldier_complete");
		break;

		case "node_3_blaze":
			Dialog.snd = "voice\SFNT\SFNT009";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit_arrest";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit_arrest":
			EndQuestMovie();TrackQuestMovie("end","Soldier_for_fight_in_tavern_01_dialog.c -> exit_arrest");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.gun = "";
			pchar.blade = "";
			AddDialogExitQuest("blaze_to_prison_complete");
		break;
	}
}
