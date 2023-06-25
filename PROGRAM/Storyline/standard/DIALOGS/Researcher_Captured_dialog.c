//#include "DIALOGS\Researcher_Captured_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_meeting;

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
			DialogExit();
		break;
	
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.snd = "voice\RECA\RECA001";

			Diag.TempNode = "First time";
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Node_1";
		break;

		case "Node_1":
			Dialog.snd = "voice\RECA\RECA002";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[4];
			Link.l2.go = "Node_2";
		break;

		case "Node_2":
			Dialog.snd = "voice\RECA\RECA003";
			d.Text = DLG_TEXT[5];
			Link.l1 = DLG_TEXT[6];
			Link.l1.go = "Exit";
		break;

		case "Talk_With_Blaze":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "voice\RECA\RECA004";

			d.Text = DLG_TEXT[7];
			Link.l1 = DLG_TEXT[8];
			Link.l1.go = "Talk_With_Blaze_1";
		break;

		case "Talk_With_Blaze_1":
			Dialog.snd = "voice\RECA\RECA005";
			d.Text = DLG_TEXT[9] + GetMyFullName(NPChar) + DLG_TEXT[10];
			Link.l1 = DLG_TEXT[11];
			Link.l1.go = "Talk_With_Blaze_2";
		break;

		case "Talk_With_Blaze_2":
			Dialog.snd = "voice\RECA\RECA006";
			d.Text = DLG_TEXT[12];
			Link.l1 = DLG_TEXT[13] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[14])]) + DLG_TEXT[15] + Characters[GetCharacterIndex(DLG_TEXT[16])].lastname + DLG_TEXT[17];
			Link.l1.go = "Talk_With_Blaze_3";
		break;

		case "Talk_With_Blaze_3":
			Dialog.snd = "voice\RECA\RECA007";
			d.Text = DLG_TEXT[18];
			Link.l1 = DLG_TEXT[19];
			Link.l1.go = "Talk_With_Blaze_4";
		break;

		case "Talk_With_Blaze_4":
			Dialog.snd = "voice\RECA\RECA008";
			d.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Talk_With_Blaze_5";
		break;

		case "Talk_With_Blaze_5":
			Dialog.snd = "voice\RECA\RECA009";
			d.Text = DLG_TEXT[22];
			Link.l1 = DLG_TEXT[23];
			Link.l1.go = "Talk_With_Blaze_6";
		break;

		case "Talk_With_Blaze_6":
			Dialog.snd = "voice\RECA\RECA010";
			d.Text = DLG_TEXT[24];
			Link.l1 = DLG_TEXT[25];
			Link.l1.go = "Talk_With_Blaze_7";
		break;

		case "Talk_With_Blaze_7":
			Dialog.snd = "voice\RECA\RECA011";
			d.Text = DLG_TEXT[26];
			Link.l1 = DLG_TEXT[27];
			Link.l1.go = "exit";
			AddDialogExitQuest("researcher_captured_exit_fight");
		break;

		}
}

