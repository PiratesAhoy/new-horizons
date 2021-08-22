//#include "DIALOGS\Rabel Yverneau_dialog.h"
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

		case "Exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;


		case "First time":
			AddDialogExitQuest("Story_French_squadron_restored"); // KK
			Dialog.defAni = "Sit_HeadonHand";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_HeadonHand";
			Dialog.cam = "1";
			Dialog.snd = "voice\RAYV\RAYV001";
			Diag.TempNode = "Talk_AfterTavern";			
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1] + GetMyFullName(NPChar) + DLG_TEXT[2];
			Link.l1.go = "First time_1";	
		break;

		case "First time_1":
			Dialog.snd = "voice\RAYV\RAYV002";
			d.Text = DLG_TEXT[3];
			Link.l1 = GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[4])]) + DLG_TEXT[5];
			Link.l1.go = "First time_2";	
		break;

		case "First time_2":
			Dialog.snd = "voice\RAYV\RAYV003";
			d.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7] + GetMyFullName(PChar) + DLG_TEXT[8] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[9])]) + DLG_TEXT[10];
			Link.l1.go = "Node_2";	
		break;

		case "Node_2":
			Dialog.snd = "voice\RAYV\RAYV004";
			d.Text = RandSwear() + DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "Node_3";
		break;

		case "Node_3":
			Dialog.snd = "voice\RAYV\RAYV005";
			d.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Node_4";
		break;

		case "Node_4":
			Dialog.snd = "voice\RAYV\RAYV006";
			d.Text = DLG_TEXT[15] + GetMyName(&Characters[GetCharacterIndex(DLG_TEXT[16])]) + DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "Node_5";
		break;

		case "Node_5":
			Dialog.snd = "voice\RAYV\RAYV007";
			d.Text = DLG_TEXT[19]; 
			Link.l2 = DLG_TEXT[20];
			Link.l2.go = "Node_6";
		break;

		case "Node_6":
			Dialog.snd = "voice\RAYV\RAYV008";
			d.Text = DLG_TEXT[21];
			Link.l1 = DLG_TEXT[22];
			Link.l1.go = "exit";
			DoQuestCheckDelay("Story_Blaze_and_Rabel_Leave_tavern", 1.0);
		break;

		case "Talk_AfterTavern":
			Dialog.snd = "voice\RAYV\RAYV009";
			d.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "Exit";
		break;

		case "Let's get out":
			Dialog.snd = "voice\RAYV\RAYV010";
			Diag.TempNode = "Just_a_talk";
			d.Text = DLG_TEXT[25];
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "exit";
			AddDialogExitQuest("rabel_yverneau_exit_run");
		break;

		case "Just_a_talk":
			Dialog.snd = "voice\RAYV\RAYV011";
			Diag.TempNode = "Just_a_talk";
			d.Text = DLG_TEXT[27];
			Link.l1 = DLG_TEXT[28];
			Link.l1.go = "Exit";
		break;



		}
}

