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

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
		
			d.Text = DLG_TEXT[5];
			Link.l99 = DLG_TEXT[6];
			Link.l99.go = "exit2";
		break;
		
		case "knock out":
			d.Text = DLG_TEXT[0];
			Link.l99 = DLG_TEXT[1];
			Link.l99.go = "knock out2";
		break;
		
		case "knock out2":
			d.Text = DLG_TEXT[2];
			Link.l99 = DLG_TEXT[3];
			Link.l99.go = "knock out3";
		break;
		
		case "knock out3":
			d.Text = DLG_TEXT[4];
			Link.l99.go = "exit";
			AddDialogExitQuest("Slaver_knock");
		break;	
		
		case "Halt":
			d.Text = DLG_TEXT[5];
			Link.l99 = DLG_TEXT[7];
			Link.l99.go = "exit";
			AddDialogExitQuest("Killing_slave_guards");
		break;

		case "artois_lay":
			dialog.snd = "Voice\ANAC\ANAC004";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "artois_lay_2";
		break;

		case "artois_lay_2":
			dialog.snd = "Voice\ANAC\ANAC005";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "artois_lay_3";
		break;

		case "artois_lay_3":
			dialog.snd = "Voice\ANAC\ANAC006";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("fight_for_artois_with_child_of_giens");
		break;
	}
}
