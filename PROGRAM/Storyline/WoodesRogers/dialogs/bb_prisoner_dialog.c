//#include "DIALOGS\wench_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		// ----------------------------------- Диалог первый - первая встреча

		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			string prisonerid;
			prisonerid = NPChar.id;
			switch(prisonerid)
			{
				case "bb_prisoner1":
					PlaySound("VOICE\ENGLISH\gm_crew5B.wav");
				break;

				case "bb_prisoner2":
					PlaySound("VOICE\ENGLISH\gm_crew16B.wav");
				break;

				case "bb_prisoner3":
					PlaySound("VOICE\ENGLISH\gm_crew1A.wav");
				break;

				case "bb_prisoner4":
					PlaySound("VOICE\ENGLISH\pir_capF.wav");
				break;

				case "bb_prisoner5":
					PlaySound("VOICE\ENGLISH\blaze_no_escape.wav");
				break;

				case "bb_prisoner6":
					PlaySound("VOICE\ENGLISH\pir_capC.wav");
				break;

				case "bb_prisoner7":
					PlaySound("VOICE\ENGLISH\pir_capB.wav");
				break;

				case "bb_prisoner8":
					PlaySound("VOICE\ENGLISH\pir_capM.wav");
				break;

				case "bb_prisoner9":
					PlaySound("VOICE\ENGLISH\pir_capEE.wav");
				break;

				case "bb_prisoner10":
					PlaySound("VOICE\ENGLISH\pir_capFFF.wav");
				break;

				case "bb_maroon1":
					PlaySound("VOICE\ENGLISH\pir_capP.wav");	
				break;

				case "bb_maroon2":
					PlaySound("VOICE\ENGLISH\gm_crew7.wav");
					dialog.text = DLG_TEXT[12];
				break;

				case "bb_maroon3":
					PlaySound("VOICE\ENGLISH\pir_capMMM.wav");
				break;

				case "bb_maroon4":
					PlaySound("VOICE\ENGLISH\pir_capJ.wav");
				break;				
			}

			int iPhrase = rand(6);
			switch (iPhrase)
			{
				case 0:
					dialog.text = DLG_TEXT[0];
				break;

				case 1:
					dialog.text = DLG_TEXT[1];
				break;

				case 2:
					dialog.text = DLG_TEXT[2];
				break;

				case 3:
					dialog.text = DLG_TEXT[3];
				break;

				case 4:
					dialog.text = DLG_TEXT[4];
				break;

				case 5:
					dialog.text = DLG_TEXT[5];
				break;

				case 6:
					dialog.text = DLG_TEXT[6];
				break;
			}

			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";

			Diag.TempNode = "First Time";
		break;

		case "maroons_free":
			PlaySound("VOICE\ENGLISH\defoe_psst.wav");
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";

			Diag.TempNode = "maroons_free";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}