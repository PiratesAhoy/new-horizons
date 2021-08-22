//#include "DIALOGS\Wilfred Bythesea_dialog.h"

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
						
			if (GetAttribute(NPChar, "quest.kill_ogarrio") == "0")
			{
				Dialog.snd = "voice\WIBY\WIBY001";
				dialog.text = DLG_TEXT[0] + GetMyName(Pchar) + DLG_TEXT[1];
				link.l1 = DLG_TEXT[2];
				link.l1.go = "talk_in_tavern";
			}
			if (GetAttribute(NPChar, "quest.kill_ogarrio") == "Almost_complete")
			{
				Dialog.snd = "voice\WIBY\WIBY002";
				dialog.text = DLG_TEXT[3];
				link.l1 = DLG_TEXT[4];
				link.l1.go = "killing_complete_2";
			}
			NextDiag.TempNode = "first time";
		break;
		
		case "killing_complete_2":
			Dialog.snd = "voice\WIBY\WIBY003";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 700);
				AddPartyExpChar(pchar, "Sneak", 7);
			}
			else { AddPartyExp(pchar, 700); }
			AddQuestRecord("Kill_Ogario", 4);
			CloseQuestHeader("Kill_Ogario");
			AddDialogExitQuest("remove_Wilfred_Bythesea");
		break;

		case "talk_in_tavern":
			Dialog.snd = "voice\WIBY\WIBY004";
			Dialog.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "talk_in_tavern_2";
		break;

		case "talk_in_tavern_2":
			Dialog.snd = "voice\WIBY\WIBY005";
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "talk_in_tavern_3";
		break;

		case "talk_in_tavern_3":
			Dialog.snd = "voice\WIBY\WIBY006";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "talk_in_tavern_4";
		break;
	
		case "talk_in_tavern_4":
			Dialog.snd = "voice\WIBY\WIBY007";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "talk_in_tavern_5";
		break;
		
		case "talk_in_tavern_5":
			Dialog.snd = "voice\WIBY\WIBY008";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "talk_in_tavern_6";
		break;

		case "talk_in_tavern_6":
			Dialog.snd = "voice\WIBY\WIBY009";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "talk_in_tavern_7";
		break;

		case "talk_in_tavern_7":
			Dialog.snd = "voice\WIBY\WIBY010";
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "talk_in_tavern_8";
		break;

		case "talk_in_tavern_8":
			Dialog.snd = "voice\WIBY\WIBY011";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "talk_in_tavern_9";
		break;

		case "talk_in_tavern_9":
			Dialog.snd = "voice\WIBY\WIBY012";
			dialog.text = DLG_TEXT[23] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[24])]) + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("Wifred_give_to_us_ship");
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
