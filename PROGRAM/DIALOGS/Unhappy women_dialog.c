//#include "DIALOGS\Unhappy women_dialog.h"

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
						
			Dialog.snd = "voice\UNWO\UNWO001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "talk_6";  // --cat
			
			if (!CheckAttribute(pchar, "quest.ANIMISTS"))
			{
				Dialog.snd = "voice\UNWO\UNWO002";
				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "talk_1";
			}
			if (CheckQuestAttribute("ANIMISTS", "denied"))
			{
				link.l1 = DLG_TEXT[4];
				link.l1.go = "exit";
				pchar.quest.ANIMISTS.over = "yes";
			}
//			if (CheckQuestAttribute("ANIMISTS", "completed") && npchar.quest.ANIMISTS != "completed")
			if (CheckQuestAttribute("ANIMISTS", "completed") && GetAttribute(NPChar, "quest.ANIMISTS") != "completed")
			{
				Dialog.snd = "voice\UNWO\UNWO003";
				dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "destroyed_sekt";
				pchar.quest.ANIMISTSZ = "children_returned";   //  Cat
			}

			NextDiag.TempNode = "first time";
		break;

		case "destroyed_sekt":
			Dialog.snd = "voice\UNWO\UNWO004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "exit";
			if(AUTO_SKILL_SYSTEM)
			{
				AddPartyExpChar(pchar, "Leadership", 4000);
				AddPartyExpChar(pchar, "Sneak", 40);
			}
			else { AddPartyExp(pchar, 4000); }
			npchar.quest.ANIMISTS = "completed";
			AddDialogExitQuest("womens_leave_town");
		break;

		case "talk_1":
			Dialog.snd = "voice\UNWO\UNWO005";
			if (PChar.sex == "woman") dialog.text = DLG_TEXT[23];
			else dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "talk_2";
		break;

		case "talk_2":
			Dialog.snd = "voice\UNWO\UNWO006";
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "talk_3";
		break;

		case "talk_3":
			Dialog.snd = "voice\UNWO\UNWO007";
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "talk_4a";
		break;
		
		case "talk_4a":    // --> cat
			Dialog.snd = "voice\UNWO\UNWO005";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "talk_4";
		break;  // <-- cat

		case "talk_4":
			Dialog.snd = "voice\UNWO\UNWO008";
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "talk_5";
		break;

		case "talk_5":
			Dialog.snd = "voice\UNWO\UNWO009";
			dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			SetQuestHeader("ANIMISTS");
			AddQuestrecord("ANIMISTS", 1);
			pchar.quest.ANIMISTS = "begin";
			SetRumourState("Children_start", false); // NK
		break;
		
		case "talk_6":  // --> cat
			Dialog.snd = "voice\UNWO\UNWO006";
			Preprocessor_Add("title", GetAddressForm(ADDR_POLITE, ENGLAND, PChar.sex == "woman"));
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
		break;  // <-- cat

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
