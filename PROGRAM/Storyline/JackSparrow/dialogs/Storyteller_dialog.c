//#include "DIALOGS\Jack_dialog.h"
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
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\THDI\THDI001";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Tavern_stuck":
			Dialog.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "exit";
			AddDialogExitQuest("opening_3");
		break;

		case "Tavern_Story":
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "exit";
			AddDialogExitQuest("Take_a_seat_BB");
		break;

		case "Tavern_Story2":
			Dialog.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "Tavern_Story3";
		break;

		case "Tavern_Story3":
			Dialog.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Tavern_Story4";
		break;

		case "Tavern_story4":
			Dialog.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Tavern_Story5";
		break;

		case "Tavern_story5":
			Dialog.Text = DLG_TEXT[12];
			Link.l1.go = "Tavern_Story6";
		break;

		case "Tavern_story6":
			Dialog.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Tavern_Story7";
		break;

		case "Tavern_story7":
			Dialog.Text = DLG_TEXT[15];
			Link.l1.go = "exit";
			AddDialogExitQuest("TotBB_HtC3");
		break;

		case "Tavern_story8":
			Dialog.Text = DLG_TEXT[16];
			if (GetAttribute(pchar, "Chevalle") == "Mutiny")
			{
				Link.l1 = DLG_TEXT[17];
				Link.l1.go = "tavern_Story9";
			}
			Link.l2 = DLG_TEXT[18];
			Link.l2.go = "tavern_Story10";
			//AddDialogExitQuest("TotBB_HtC3");
		break;

		case "Tavern_story9":
			Dialog.Text = DLG_TEXT[19];
			Link.l1.go = "exit";
			AddDialogExitQuest("10_years_tortuga");
		break;

		case "Tavern_story10":
			if (GetAttribute(pchar, "Chevalle") == "Mutiny")
			{
				Dialog.Text = DLG_TEXT[20];
			}
			else
			{
				Dialog.Text = DLG_TEXT[21];
			}	
			Link.l1.go = "exit";
			AddDialogExitQuest("Tortuga_Get_ready_for_Film2");
		break;

		case "Tavern_story11":
			Dialog.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "exit";
			AddDialogExitQuest("Tortuga_Meet_Annamaria_for_ship2");
		break;

		case "Exit":
			DialogExit();
		break;
	}
}
