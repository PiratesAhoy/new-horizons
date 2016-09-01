//#include "DIALOGS\Gordon Carpenter_dialog.h"
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
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;


		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "continue0";		
		break;

		case "continue0":
			d.Text = DLG_TEXT[2];
			Link.l99 = DLG_TEXT[3];
			Link.l99.go = "Meeting";
		break;

		case "Meeting":
			LAI_QuestDelay("talk_about_ruby", 1);
			Diag.CurrentNode = "continue";
			DialogExit();
		break;

		case "continue":
			d.Text = DLG_TEXT[4];
			Link.l99 = DLG_TEXT[5];
			Link.l99.go = "continue1";
		break;

		case "continue1":
			d.Text = DLG_TEXT[6];
			Link.l99 = DLG_TEXT[7];
			Link.l99.go = "continue2";
		break;

		case "continue2":
			d.Text = DLG_TEXT[8];
			Link.l99 = DLG_TEXT[9];
			Link.l99.go = "continue3";
		break;

		case "continue3":
			d.Text = DLG_TEXT[10];
			Link.l99 = DLG_TEXT[11];
			Link.l99.go = "exit" // NK - 04-09 "continue4";
			AddDialogExitQuest("Story_CursedCoinsFinished"); // NK ditto
		break;

		case "continue4":
			AddDialogExitQuest("Story_CursedCoinsFinished");
			d.Text = DLG_TEXT[12];
			Link.l99 = DLG_TEXT[13];
			Link.l99.go = "exit";
		break;
	}
}