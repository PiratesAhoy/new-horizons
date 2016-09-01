//#include "DIALOGS\Oswald Chappel_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
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
			Dialog.snd = "voice\OSCH\OSCH001";

			if(CheckQuestAttribute("Turks_and_the_French", "turks quest again"))
			{
				Dialog.Text = DLG_TEXT[2] + PChar.lastname + ", I believe.";
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "Interceptor for Sale";
			}
			else
			{
				Dialog.Text = DLG_TEXT[0];
				Link.l1 = DLG_TEXT[1];
				Link.l1.go = "exit";
			}
		break;

		case "Interceptor for Sale":
			Dialog.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "Interceptor for Sale2";
		break;

		case "Interceptor for Sale2":
			Dialog.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "Interceptor for Sale3";
		break;

		case "Interceptor for Sale3":
			Dialog.Text = DLG_TEXT[8];
			Link.l1 = DLG_TEXT[9];
			Link.l1.go = "Interceptor_exit_first";
		break;

		case "Interceptor_exit_first":
			DialogExit();
			AddDialogExitQuest("Purchase_Interceptor");
		break;

		case "Interceptor_at_Turks_Dock":
			Dialog.Text = DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Interceptor_at_Turks_Dock2";
		break;

		case "Interceptor_at_Turks_Dock2":
			Dialog.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "Interceptor_at_Turks_Dock3";
		break;

		case "Interceptor_at_Turks_Dock3":
			Dialog.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "Interceptor_at_Turks_Dock4";
		break;

		case "Interceptor_at_Turks_Dock4":
			Dialog.Text = DLG_TEXT[16];
			Link.l1 = DLG_TEXT[17];
			Link.l1.go = "Interceptor_at_Turks_Dock5";
		break;

		case "Interceptor_at_Turks_Dock5":
			Dialog.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Interceptor_at_Turks_Dock6";
		break;

		case "Interceptor_at_Turks_Dock6":
			Dialog.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Interceptor_at_Turks_Dock7";
		break;

		case "Interceptor_at_Turks_Dock7":
			Dialog.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Interceptor_at_Turks_Dock8";
		break;

		case "Interceptor_at_Turks_Dock8":
			Dialog.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "Interceptor_at_Turks_Dock9";
		break;

		case "Interceptor_at_Turks_Dock9":
			Dialog.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "Interceptor_at_Dock_exit";
		break;

		case "Interceptor_at_Dock_exit":
			DialogExit();
			AddDialogExitQuest("Purchase_Interceptor_now_Turner");
		break;
	}
}

