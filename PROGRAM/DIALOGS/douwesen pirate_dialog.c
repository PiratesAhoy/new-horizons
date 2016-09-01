//#include "DIALOGS\douwesen pirate_dialog.h"

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
			
			dialog.snd = "Voice\DOPI\DOPI001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_4" && makeint(pchar.reputation) >= 25)
			{
				dialog.snd = "Voice\DOPI\DOPI002";
				Dialog.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[4])]) + DLG_TEXT[6];
				Link.l1.go = "denied";
			}
			if (pchar.quest.main_line == "blaze_to_incas_collection_begin_4" && makeint(pchar.reputation) < 25)
			{
				dialog.snd = "Voice\DOPI\DOPI003";
				dialog.text = DLG_TEXT[7] + GetMyFullName(PChar) + DLG_TEXT[8];
				link.l1 = DLG_TEXT[9];
				link.l1.go = "access";
			}
			if (pchar.quest.main_line == "to_douwesen_pirates" || pchar.quest.main_line == "after_speak_with_peasant")
			{
				link.l1 = DLG_TEXT[10];
				link.l1.go = "to_douwesen_pirates_2";
			}
			//B. -->
			if(FindFirstContrabandGoods(PChar) != -1 && Pchar.location.from_sea == "Douwesen_shore_01")
			{
				link.l2 = DLG_TEXT[25] + locations[FindLocation("Douwesen_shore_01")].name + DLG_TEXT[26];
				link.l2.go = "Smuggling";
			}
			//B. <--
			NextDiag.TempNode = "first time";
		break;

		case "to_douwesen_pirates_2":
			dialog.snd = "Voice\DOPI\DOPI004";
			dialog.text = DLG_TEXT[11] + characters[GetCharacterIndex(DLG_TEXT[12])].lastname + DLG_TEXT[13];
			link.l1 = DLG_TEXT[14] + characters[GetCharacterIndex(DLG_TEXT[15])].lastname + DLG_TEXT[16];
			link.l1.go = "to_douwesen_pirates_3";
		break;

		case "to_douwesen_pirates_3":
			dialog.snd = "Voice\DOPI\DOPI005";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			pchar.quest.main_line = "after_talk_with_douwesen_pirate";
			AddQuestRecord("Where_are_i", 3);
		break;

		case "access":
			dialog.snd = "Voice\DOPI\DOPI006";
			AddQuestRecord("blaze_to_incas_collection", 6);
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
			pchar.quest.main_line = "blaze_to_incas_collection_begin_5";
		break;

		case "denied":
			dialog.snd = "Voice\DOPI\DOPI007";
			Dialog.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "denied_2";
		break;

		case "denied_2":
			dialog.snd = "Voice\DOPI\DOPI008";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddDialogExitQuest("Pieter_nolt_fight");
		break;

		case "fight":
			AddQuestRecord("blaze_to_incas_collection", 5);
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
		//B. -->
		case "Smuggling":
			if(CheckAttribute(Pchar, "quest.Contraband.Active") && Pchar.quest.Contraband.Active == true)
			{
				dialog.snd = "voice\SMAG\SMAG006";
				dialog.text = DLG_TEXT[30];
				Link.l1 = DLG_TEXT[31];
				Link.l1.go = "Exit";
			}
			else
			{
				dialog.snd = "voice\SMAG\SMAG007";
				dialog.text = DLG_TEXT[27] + locations[FindLocation("Douwesen_shore_01")].name + DLG_TEXT[28];
				Link.l1 = DLG_TEXT[29];
				Link.l1.go = "Smuggling_exit";
			}
		break;

		case "Smuggling_exit":
			NextDiag.CurrentNode = NextDiag.TempNode;
			PlaceSmugglersOnShore("Douwesen_shore_01");
			Pchar.Quest.Contraband.active = true;
			DialogExit();
		break;
		//B. <--
	}
}
