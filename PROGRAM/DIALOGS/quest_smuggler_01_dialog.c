//#include "DIALOGS\quest_smuggler_01_dialog.h"

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

			NextDiag.TempNode = "first time";

			//разговор с блейзом
			if (pchar.quest.main_line == "blaze_talk_with_duarte")
			{
				Dialog.snd = "voice\QUS1\QUS1001";
				dialog.text = DLG_TEXT[0] + characters[GetCharacterIndex(DLG_TEXT[1])].lastname + DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "node_2";
			}
		break;

		case "node_2":
			Dialog.snd = "voice\QUS1\QUS1002";
			dialog.text = DLG_TEXT[4] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[5])]) + DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "node_3";
		break;
		
		case "node_3":
			Dialog.snd = "voice\QUS1\QUS1003";
			dialog.text = DLG_TEXT[8] + characters[(GetCharacterIndex(DLG_TEXT[9]))].lastname + DLG_TEXT[10];
			link.l1 = pcharrepphrase(DLG_TEXT[11], DLG_TEXT[12]);
		link.l1.go = "node_4";
		break;                   
		
		case "node_4":
			Dialog.snd = pcharrepphrase("voice\QUS1\QUS1004", "voice\QUS1\QUS1005");
			dialog.text = pcharrepphrase(DLG_TEXT[13], DLG_TEXT[14]);
			link.l1 = pcharrepphrase(DLG_TEXT[15] + characters[GetCharacterIndex(DLG_TEXT[16])].lastname + DLG_TEXT[17], DLG_TEXT[18]);
			link.l1.go = "node_5";
		break;                   
		
		case "node_5":
			Dialog.snd = pcharrepphrase("voice\QUS1\QUS1006", "voice\QUS1\QUS1007");
			dialog.text = pcharrepphrase(DLG_TEXT[19] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[20])]) + DLG_TEXT[21], DLG_TEXT[22]);
			link.l1 = pcharrepphrase(DLG_TEXT[23] + characters[GetCharacterIndex(DLG_TEXT[24])].lastname + DLG_TEXT[25], DLG_TEXT[26] + characters[GetCharacterIndex(DLG_TEXT[27])].lastname + DLG_TEXT[28]);
			link.l1.go = "node_6";
		break;                   
		
		case "node_6":
			Dialog.snd = pcharrepphrase("voice\QUS1\QUS1008", "voice\QUS1\QUS1009");
			dialog.text = pcharrepphrase(DLG_TEXT[29] +GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[30])]) + DLG_TEXT[31], DLG_TEXT[32] + characters[GetCharacterIndex(DLG_TEXT[33])].lastname + DLG_TEXT[34]);
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
			AddDialogExitQuest("blaze_exit_to_beltrop");
			npchar.location = "none";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
