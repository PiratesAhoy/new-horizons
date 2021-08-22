//#include "DIALOGS\Tom Morgan_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			Dialog.snd = "voice\PADI\PADI001";
			
			if(IsDay())
			{
				PlaySound("VOICE\ENGLISH\grandma_3.wav");
				Dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "at_his_club";
			}
			else
			{
				PlaySound("VOICE\ENGLISH\grandma_6.wav");
				PlaySound("VOICE\ENGLISH\grandma_6.wav");
				Dialog.text = DLG_TEXT[0];
				link.l1 = DLG_TEXT[1];
				link.l1.go = "my_husband";
			}
		break;

		case "my_husband":
			PlaySound("VOICE\ENGLISH\grandma_3.wav");
			Dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "at_his_club";
		break;
//ok for both day and night
		case "at_his_club":
			PlaySound("VOICE\ENGLISH\grandma_4.wav");
			Dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "secret_society";
		break;

		case "secret_society":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			Dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Maltains";
		break;

		case "Maltains":
			PlaySound("VOICE\ENGLISH\grandma_7.wav");
			PlaySound("VOICE\ENGLISH\grandma_7.wav");
			Dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			if(IsDay())
			{
				link.l1.go = "closed_for_day";
			}
			else
			{
				link.l1.go = "exit";
				Diag.TempNode = "neutral";
			}
			AddQuestRecord("Israel_Hands", "15");			
		break;

		case "closed_for_day":
			PlaySound("VOICE\ENGLISH\grandma_1.wav");
			Dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			Diag.TempNode = "neutral";
			AddQuestRecord("Israel_Hands", "16");
		break;

		case "neutral":
			PlaySound("VOICE\ENGLISH\grandma_7.wav");
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";

			Diag.TempNode = "neutral";
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
