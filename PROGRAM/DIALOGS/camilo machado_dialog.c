//#include "DIALOGS\camilo machado_dialog.h"

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
	// DeathDaisy -->
	string Diminutive;
	if(PChar.sex == "woman")
	{
		Diminutive = "girl";
	}
	else
	{
		Diminutive = "boy";
	}
	
	Preprocessor_Add("boy", Diminutive);
	Preprocessor_Add("gender", GetMyAddressForm(NPChar,PChar, ADDR_GENDER, false, false));
	// DeathDaisy <--
	
	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			

			NextDiag.TempNode = "first time";
			
			dialog.snd = "Voice\CAMA\CAMA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			//разговор с блейзом
			if (pchar.quest.main_line == "blaze_talk_with_machado")
			{
				dialog.snd = "Voice\CAMA\CAMA002";
				dialog.text = DLG_TEXT[2] + characters[GetCharacterIndex(DLG_TEXT[3])].lastname + DLG_TEXT[4];
				link.l1 = pcharrepphrase(DLG_TEXT[5], DLG_TEXT[6]);
				link.l1.go = "node_2";
			}
		break;
		
		case "node_2":
			dialog.snd = "Voice\CAMA\CAMA003";
			dialog.text = DLG_TEXT[7];
			link.l1 = pcharrepphrase(DLG_TEXT[8], DLG_TEXT[9]);
			link.l1.go = "node_3";
		break;
		
		case "node_3":
			dialog.snd = pcharrepphrase("Voice\CAMA\CAMA004", "Voice\CAMA\CAMA005");
			dialog.text = pcharrepphrase(DLG_TEXT[10], DLG_TEXT[11]);
			link.l1 = DLG_TEXT[12] + characters[GetCharacterIndex(DLG_TEXT[13])].lastname + DLG_TEXT[14];
			link.l1.go = "node_4";
		break;
		
		case "node_4":
			dialog.snd = "Voice\CAMA\CAMA006";
			dialog.text = DLG_TEXT[15] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[16])]) + DLG_TEXT[17];
			link.l1 = pcharrepphrase(DLG_TEXT[18], DLG_TEXT[19]);
			link.l1.go = "node_5";
		break;
		
		case "node_5":
			dialog.snd = "Voice\CAMA\CAMA007";
			dialog.text = DLG_TEXT[20];
			link.l1 = pcharrepphrase(DLG_TEXT[21] + characters[GetCharacterIndex(DLG_TEXT[22])].lastname + DLG_TEXT[23], DLG_TEXT[24]);
			link.l1.go = "node_6";
		break;
		
		case "node_6":
			dialog.snd = "Voice\CAMA\CAMA008";
			dialog.text = DLG_TEXT[25];
			link.l1 = pcharrepphrase(DLG_TEXT[26], DLG_TEXT[27]);
			link.l1.go = "blaze_exit_from_machado";
			AddQuestRecord("Blaze_search_Rheims", 7);
		break;

		case "blaze_exit_from_machado":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			pchar.quest.main_line = "blaze_talk_with_machado_complete";
			Locations[FindLocation("Smugglers_residence")].reload.l1.disable = 0;
			if (makeint(environment.time) > 22.0 || makeint(environment.time) < 8.0)
			{
				Locations[FindLocation("Smugglers_Lair")].reload.l6.disable = 0;
			}
			//даем возможность блейзу просто убить стражников
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition.l1 = "NPC_Death";
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition.l1.character = "Macario Regalo";
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition.l2 = "NPC_Death";
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition.l2.character = "Evaristo Filho";
			pchar.quest.kill_guards_in_rheims_house_smugglers.win_condition = "kill_guards_in_rheims_house_smugglers_complete";
			//сразу же даем квест на попадание в дом
			pchar.quest.blaze_to_rheims_house_in_smugglers.win_condition.l1 = "location";
			pchar.quest.blaze_to_rheims_house_in_smugglers.win_condition.l1.location = "Rheims_house_in_smugglers";
			pchar.quest.blaze_to_rheims_house_in_smugglers.win_condition = "blaze_to_rheims_house_in_smugglers_complete";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
