//#include "DIALOGS\Artois Voysey_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = "First Time";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit1":
			AddDialogExitQuest("shore_ship3");
			DialogExit();
		break;

		case "exit2":
			DialogExit();
		break;

		case "exit_not_killing_PL":
			AddDialogExitQuest("not_killing_PL");
			Diag.CurrentNode = "First Time";
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
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
		
			if(NPChar.quest.meeting == "0")
			{
				d.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "exit_not_killing_PL";

//				if (GetAttribute(Pchar, "Jack") == "Pirate_Lord" && GetAttribute(Pchar, "Turks") == "Brotherhood")
				{
					Link.l2 = DLG_TEXT[2];
					Link.l2.go = "kill_him";
					NPC_meeting = "1";
				}
				if (CheckQuestAttribute("pirate_lord", "true"))		// GR: Unfair to block this because you picked the "Brock/Brinkley" start
				{
					Link.l2 = DLG_TEXT[2];
					Link.l2.go = "kill_him";
					NPC_meeting = "1";
				}
			}
			else
			{
				d.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "exit";
//				if (GetAttribute(Pchar, "Jack") == "Pirate_Lord" && GetAttribute(Pchar, "Turks") == "Brotherhood")
				if (CheckQuestAttribute("pirate_lord", "true"))		// GR: Unfair to block this because you picked the "Brock/Brinkley" start
				{
					Link.l2 = DLG_TEXT[3];
					Link.l2.go = "kill_him";
				}
			}
		break;

		case "kill_him":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			AddDialogExitQuest("killing_PL");
		break;
		
		case "That's_my_Slave":
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "continue";
		break;

		case "continue":
			dialog.snd = "Voice\ARVO\ARVO003";
			d.Text = DLG_TEXT[6];
			Link.l99 = DLG_TEXT[7];
			Link.l99.go = "exit1";
		break;

		case "hang":
			d.Text = DLG_TEXT[8];
			Link.l99 = DLG_TEXT[9];
			Link.l99.go = "hang2";
		break;

		case "hang2":
			d.Text = DLG_TEXT[10];
			Link.l99 = DLG_TEXT[11];
			Link.l99.go = "exit";
			AddDialogExitQuest("Blaze_Jocard_Bos'un_Hung");
		break;
	}
}
