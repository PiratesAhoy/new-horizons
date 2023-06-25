//#include "DIALOGS\Skipper_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	
	int iNation = sti(PChar.nation); // DeathDaisy
	string sNation = iNation; // DeathDaisy
	
	// DeathDaisy -->
	switch(iNation)
	{
		case FRANCE:
			Preprocessor_Add("attack", DLG_TEXT[17]);
			Preprocessor_Add("hello", DLG_TEXT[18]);
			Preprocessor_Add("captain", DLG_TEXT[19]);
		break;

		case SPAIN:
			Preprocessor_Add("attack", DLG_TEXT[20]);
			Preprocessor_Add("hello", DLG_TEXT[21]);
			Preprocessor_Add("captain", DLG_TEXT[22]);
		break;

		case PORTUGAL:
			Preprocessor_Add("attack", DLG_TEXT[23]);
			Preprocessor_Add("hello", DLG_TEXT[24]);
			Preprocessor_Add("captain", DLG_TEXT[25]);
		break;

		case HOLLAND:
			Preprocessor_Add("attack", DLG_TEXT[26]);
			Preprocessor_Add("hello", DLG_TEXT[27]);
			Preprocessor_Add("captain", DLG_TEXT[28]);
		break;

		case ENGLAND:
			Preprocessor_Add("attack", DLG_TEXT[32]);
			Preprocessor_Add("hello", DLG_TEXT[33]);
			Preprocessor_Add("captain", DLG_TEXT[34]);
		break;

		case PIRATE:
			Preprocessor_Add("attack", DLG_TEXT[14]);
			Preprocessor_Add("hello", DLG_TEXT[15]);
			Preprocessor_Add("captain", DLG_TEXT[16]);
		break;

		case PERSONAL_NATION:
			Preprocessor_Add("attack", DLG_TEXT[14]);
			Preprocessor_Add("hello", DLG_TEXT[15]);
			Preprocessor_Add("captain", DLG_TEXT[16]);
		break;

		case GUEST1_NATION:
			if(GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN && GetCurrentPeriod() <= PERIOD_COLONIAL_POWERS)
			{
				Preprocessor_Add("attack", DLG_TEXT[29]);
				Preprocessor_Add("hello", DLG_TEXT[30]);
				Preprocessor_Add("captain", DLG_TEXT[31]);
			}
			else
			{
				Preprocessor_Add("attack", DLG_TEXT[32]);
				Preprocessor_Add("hello", DLG_TEXT[33]);
				Preprocessor_Add("captain", DLG_TEXT[34]);
			}
		break;
	}
	// DeathDaisy <--


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

			dialog.snd = "Voice\CLLA\CLLA001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			break;

		case "seeyou":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "exit";
			AddDialogExitQuest("attaque2");
			break;

		case "hey":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("nextstep3");
			break;


		case "begin2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			break;

		case "boarding":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "begin_5";
			break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("attaque");
			break;

		case "how":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("birdboarding4");
			break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
	}
}
