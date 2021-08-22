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

			string crewid;
			crewid = NPChar.id;
			switch(crewid)
			{
				case "bb_crew1":
					PlaySound("VOICE\ENGLISH\pir_capCCC.wav");
				break;

				case "bb_crew2":
					PlaySound("VOICE\ENGLISH\defoe_psst.wav");
				break;

				case "bb_crew3":
					PlaySound("VOICE\ENGLISH\guncrew_3.wav");
				break;

				case "bb_crew4":
					PlaySound("VOICE\ENGLISH\pir_capM.wav");
				break;

				case "bb_crew5":
					PlaySound("VOICE\ENGLISH\pir_capFF.wav");
				break;

				case "bb_crew6":
					PlaySound("VOICE\ENGLISH\gm_crew5C.wav");
				break;

				case "bb_crew7":
					PlaySound("VOICE\ENGLISH\pir_capEE.wav");
				break;

				case "bb_crew8":
					PlaySound("VOICE\ENGLISH\Barbossa01.wav");
				break;

				case "bb_crew9":
					PlaySound("VOICE\ENGLISH\pir_capC.wav");
				break;

				case "bb_crew10":
					PlaySound("VOICE\ENGLISH\gr_Hgold3.wav");
				break;

				case "bb_crew11":
					PlaySound("VOICE\ENGLISH\FredBob.wav");
				break;

				case "bb_crew12":
					PlaySound("VOICE\ENGLISH\Maynard_hey_there.wav");
				break;

				case "bb_crew13":
					PlaySound("VOICE\ENGLISH\pir_capKK.wav");
				break;

				case "bb_crew14":
					PlaySound("VOICE\ENGLISH\pir_capI.wav");
				break;

				case "bb_crew15":
					PlaySound("VOICE\ENGLISH\gm_crew16B.wav");
				break;

				case "bb_crew16":
					PlaySound("VOICE\ENGLISH\pir_capR11.wav");
				break;

				case "bb_crew17":
					PlaySound("VOICE\ENGLISH\Jupiter_2.wav");
				break;

				case "bb_crew18":
					PlaySound("VOICE\ENGLISH\gm_crew7.wav");
				break;

				case "bb_crew19":
					PlaySound("VOICE\ENGLISH\pir_capP.wav");
				break;

				case "bb_crew20":
					PlaySound("VOICE\ENGLISH\gm_crew16A.wav");
				break;
			}

			if(Pchar.location == "bb_QAR_deck")
			{
				int iPhrase = rand(9);
				switch (iPhrase)
				{
					case 0:
						dialog.text = DLG_TEXT[11];
					break;

					case 1:
						dialog.text = DLG_TEXT[12];
					break;

					case 2:
						dialog.text = DLG_TEXT[13];
					break;

					case 3:
						dialog.text = DLG_TEXT[14];
					break;

					case 4:
						dialog.text = DLG_TEXT[15];
					break;

					case 5:
						dialog.text = DLG_TEXT[16];
					break;

					case 6:
						dialog.text = DLG_TEXT[17];
					break;

					case 7:
						dialog.text = DLG_TEXT[18];
					break;

					case 8:
						dialog.text = DLG_TEXT[19];
					break;

					case 9:
						dialog.text = DLG_TEXT[20];
					break;
				}

				link.l1 = DLG_TEXT[21];
				link.l1.go = "exit";
			}
			else
			{
				iPhrase = rand(9);
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

					case 7:
						dialog.text = DLG_TEXT[7];
					break;

					case 8:
						dialog.text = DLG_TEXT[8];
					break;

					case 9:
						dialog.text = DLG_TEXT[9];
					break;
				}

				link.l1 = DLG_TEXT[10];
				link.l1.go = "exit";
			}

			Diag.TempNode = "First Time";
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}