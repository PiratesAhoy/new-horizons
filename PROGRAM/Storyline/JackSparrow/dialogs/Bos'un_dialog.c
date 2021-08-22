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

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "exit";
		break;
		
		case "Got Away":
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Got Away2";
		break;

		case "Got Away2":
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Got Away3";
		break;

		case "Got Away3":
			if (GetAttribute(pchar, "Bosun") == "Cursed")
			{
				d.Text = DLG_TEXT[8];
				Link.l1 = DLG_TEXT[9];
				Link.l1.go = "exit";
			}
			else
			{	
				d.Text = DLG_TEXT[6];
				Link.l1 = DLG_TEXT[7];
				Link.l1.go = "exit";
			}
			AddDialogExitQuest("before_shore_ship2");
		break;

		case "Plan":
			dialog.snd = "Voice\ARVO\ARVO003";
			d.Text = DLG_TEXT[10];
			Link.l99 = DLG_TEXT[11];
			Link.l99.go = "Plan2";
		break;

		case "Plan2":
			dialog.snd = "Voice\ARVO\ARVO003";
			d.Text = DLG_TEXT[12];
			if (GetAttribute(pchar, "Bosun") == "Cursed")
			{
				Link.l99 = DLG_TEXT[14];
				Link.l99.go = "exit";
			}
			else
			{
				Link.l99 = DLG_TEXT[13];
				Link.l99.go = "exit";
			}
			AddDialogExitQuest("To_Eleuthera");
		break;
		
		case "crew":
			d.Text = DLG_TEXT[15];
			Link.l99 = DLG_TEXT[16];
			Link.l99.go = "exit";
			AddDialogExitQuest("Slaver_knock5");
		break;
		
		case "On_Deck":
			d.Text = DLG_TEXT[17];
			Link.l99 = DLG_TEXT[18];
			Link.l99.go = "exit";
			AddMoneyToCharacter(PChar, 20000);
			PlayStereoSound("INTERFACE\took_item.wav");
			AddDialogExitQuest("Jocard_Deck5");
		break;

		case "Nigel":
			d.Text = DLG_TEXT[19];
			Link.l99 = DLG_TEXT[20];
			Link.l99.go = "exit";
			AddDialogExitQuest("Nigel_runs");
		break;
	}
}
