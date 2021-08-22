//#include "DIALOGS\Havana_Crewmember_dialog.h"

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
	
	// DeathDaisy -->
	int iNation = sti(PChar.nation);
	string sNation = iNation;
	switch(iNation)
	{
		case FRANCE:
			Preprocessor_Add("hello", "Bonjour");
			Preprocessor_Add("captain", "Capitaine");
			Preprocessor_Add("mygod", "Mon dieu");
			Preprocessor_Add("assault", "Oui, a l'assaut");
			Preprocessor_Add("yes", "Oui");
		break;

		case SPAIN:
			Preprocessor_Add("hello", "Hola");
			Preprocessor_Add("captain", "Capitбn");
			Preprocessor_Add("mygod", "Dios mio");
			Preprocessor_Add("assault", "Si, asalto");
			Preprocessor_Add("yes", "Si");
		break;

		case PORTUGAL:
			Preprocessor_Add("hello", "Ola");
			Preprocessor_Add("captain", "CapitЭo");
			Preprocessor_Add("mygod", "Meu Deus");
			Preprocessor_Add("assault", "Sim, assalto");
			Preprocessor_Add("yes", "Sim");
		break;

		case HOLLAND:
			Preprocessor_Add("hello", "Hallo");
			Preprocessor_Add("captain", "Kapitein");
			Preprocessor_Add("mygod", "Mijn God");
			Preprocessor_Add("assault", "Ja, aanval");
			Preprocessor_Add("yes", "Ja");
		break;

		case ENGLAND:
			Preprocessor_Add("hello", "Hello");
			Preprocessor_Add("captain", "Captain");
			Preprocessor_Add("mygod", "My God");
			Preprocessor_Add("assault", "Yes, attack");
			Preprocessor_Add("yes", "Yes");
		break;

		case PIRATE:
			Preprocessor_Add("hello", DLG_TEXT[28]);
			Preprocessor_Add("captain", DLG_TEXT[29]);
			Preprocessor_Add("mygod", DLG_TEXT[30]);
			Preprocessor_Add("assault", DLG_TEXT[31]);
			Preprocessor_Add("yes", DLG_TEXT[32]);
		break;

		case PERSONAL_NATION:
			Preprocessor_Add("hello", DLG_TEXT[28]);
			Preprocessor_Add("captain", DLG_TEXT[29]);
			Preprocessor_Add("mygod", DLG_TEXT[30]);
			Preprocessor_Add("assault", DLG_TEXT[31]);
			Preprocessor_Add("yes", DLG_TEXT[32]);
		break;

		case GUEST1_NATION:
			if(GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN && GetCurrentPeriod() <= PERIOD_COLONIAL_POWERS)
			{
				Preprocessor_Add("hello", "Hallе");
				Preprocessor_Add("captain", "Kapten");
				Preprocessor_Add("mygod", "Min Gud");
				Preprocessor_Add("assault", "Ja, angrip");
				Preprocessor_Add("yes", "Ja");
			}
			else
			{
				Preprocessor_Add("hello", "Hello");
				Preprocessor_Add("captain", "Captain");
				Preprocessor_Add("mygod", "My God");
				Preprocessor_Add("assault", "Yes, attack");
				Preprocessor_Add("yes", "Yes");
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

		case "hello_captain":
			dialog.snd = "Voice\CLLA\CLLA004";

			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
			break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "begin_3";
			break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("tosmuggler");
			break;

		case "saved_you":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "saved_you2";
			break;

		case "saved_you2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("freeme");
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
			AddDialogExitQuest("waituntilnight");
			break;

		case "night":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("attaque");
			break;

		case "ship_is_ours":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
			AddDialogExitQuest("captured_smuggler_ship2");
			break;

		case "nowwhat":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
			break;

		case "what_shall_we_do":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[22];
		//	link.l1 = DLG_TEXT[23];
		//	link.l1.go = "TakeALook";
			link.l2 = DLG_TEXT[24];
			link.l2.go = "TakeBySea";
			break;

		case "blow_up":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "aye";
			break;

		case "aye":
			dialog.snd = "Voice\CLLA\CLLA005";
			dialog.text = DLG_TEXT[27];
			link.l1.go = "exit";
			AddDialogExitQuest("birdboarding3");
			break;

		case "TakeALook":
			AddDialogExitQuest("birdhunt1.5");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;

		case "TakeBySea":
			AddDialogExitQuest("birdhunt3");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
	}
}
