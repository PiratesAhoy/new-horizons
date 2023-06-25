//#include "DIALOGS\Sofia Guterres_dialog.h"
	
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
			Dialog.snd = "voice\SOGU\SOGU001";
			
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "exit21";
			
			if (pchar.quest.main_line == "night_for_rheims_house")
			{
				Dialog.snd = "voice\SOGU\SOGU002";
				dialog.text = DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4];
				link.l1 = pcharrepphrase(DLG_TEXT[5], DLG_TEXT[6]);
				link.l1.go = "node_2";
			}
			if (npchar.quest.sex == "1")
			{
				if (CalcCharacterSkill(pchar, SKILL_LEADERSHIP) > 3)
				{
					Dialog.snd = "voice\SOGU\SOGU003";
					dialog.text = DLG_TEXT[7];
					link.l1 = DLG_TEXT[8];
					link.l1.go = "exit";
				}
				else
				{
					Dialog.snd = "voice\SOGU\SOGU004";
					dialog.text = DLG_TEXT[9];
					link.l1 = DLG_TEXT[10];
					link.l1.go = "exit";
				}
			}
			NextDiag.TempNode = "first time";
		break;

		case "node_2":
			Dialog.snd = "voice\SOGU\SOGU005";
			dialog.text = DLG_TEXT[11] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[12])]) + DLG_TEXT[14] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "sex";
			link.l2 = DLG_TEXT[17];
			link.l2.go = "node_3";
		break;

		case "node_3":
			Dialog.snd = "voice\SOGU\SOGU006";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
		break;

		case "sex":
			pchar.quest.sex_in_room.win_condition = "sex_complete";
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "exit21":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit":
			AddQuestRecord("Blaze_search_Rheims", 8);
			Locations[FindLocation("Smugglers_Lair")].reload.l6.disable = 0;
			Locations[FindLocation("Room_in_tavern")].reload.l1.disable = 0;
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			npchar.quest.sex = "done";
			//ActGotoLocator(npchar, "reload", "reload1",0);
			pchar.quest.sofia_exit_from_room.win_condition.l1 = "locator";
			pchar.quest.sofia_exit_from_room.win_condition.l1.location = "Smugglers_tavern_upstairs";
			pchar.quest.sofia_exit_from_room.win_condition.l1.locator_group = "reload";
			pchar.quest.sofia_exit_from_room.win_condition.l1.locator = "reload1";
			pchar.quest.sofia_exit_from_room.win_condition.l1.character = npchar.id;
			pchar.quest.sofia_exit_from_room.win_condition = "sofia_exit_from_room_complete";
		break;
	}
}
