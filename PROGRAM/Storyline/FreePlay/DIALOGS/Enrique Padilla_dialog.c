//#include "DIALOGS\Enrique Padilla_dialog.h"
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

			Dialog.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "Exit";
			break;

		case "begin_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			// DeathDaisy -->
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false));
			if(iNation == PERSONAL_NATION)
				Preprocessor_Add("sir2", XI_ConvertString("sir"));
			else
				Preprocessor_Add("sir2", GetAddressForm(ADDR_POLITE, iNation, chrsex(NPChar)));
			// DeathDaisy <--
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "begin_2";
			break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1.go = "exit";
			AddDialogExitQuest("LaCroix_jail");
			break;

		case "brokenout":
			dialog.snd = "Voice\CLLA\CLLA004";
			// DeathDaisy -->
			switch(iNation)
			{
				case FRANCE:
					Preprocessor_Add("attack", "MES HOMMES, ATTAQUEZ");
				break;

				case SPAIN:
					Preprocessor_Add("attack", "HOMBRES, AL ATAQUE");
				break;

				case PORTUGAL:
					Preprocessor_Add("attack", "HOMENS, AO ATAQUE");
				break;

				case HOLLAND:
					Preprocessor_Add("attack", "MANNEN, AANVAL");
				break;

				case ENGLAND:
					Preprocessor_Add("attack", "MEN, ATTACK");
				break;

				case PIRATE:
					Preprocessor_Add("attack", DLG_TEXT[12]);
				break;

				case PERSONAL_NATION:
					Preprocessor_Add("attack", DLG_TEXT[12]);
				break;

				case GUEST1_NATION:
					if(GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN && GetCurrentPeriod() <= PERIOD_COLONIAL_POWERS)
					{
						Preprocessor_Add("attack", "MДN, ANGRIP");
					}
					else
					{
						Preprocessor_Add("attack", "MEN, ATTACK");
					}
				break;
			}
			// DeathDaisy <--
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
			AddDialogExitQuest("spanishattack2");
			break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "begin_5";
			break;

		case "begin_5":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[9];
			link.l1.go = "exit";
			break;

		case "begin_6":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
			AddDialogExitQuest("meetadmiral3");
			break;

		case "begin_7":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "begin_8";
			link.l2 = DLG_TEXT[20];
			link.l2.go = "begin_10";
			break;

		case "begin_8":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "begin_9";
			break;

		case "begin_9":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
			AddDialogExitQuest("Esteban_officer");
			break;

		case "begin_10":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "exit";
			AddDialogExitQuest("Esteban_leaves");
			break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
	}
}
