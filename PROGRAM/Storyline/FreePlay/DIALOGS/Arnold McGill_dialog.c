//#include "DIALOGS\Arnold McGill_dialog.h"

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
	switch(iNation)
	{
		case FRANCE:
			Preprocessor_Add("yes", "oui");
			Preprocessor_Add("attack", "A l'attaque");
		break;

		case SPAIN:
			Preprocessor_Add("yes", "si");
			Preprocessor_Add("attack", "Al ataque");
		break;

		case PORTUGAL:
			Preprocessor_Add("yes", "sim");
			Preprocessor_Add("attack", "Al ataque");
		break;

		case HOLLAND:
			Preprocessor_Add("yes", "ja");
			Preprocessor_Add("attack", "Aanvallen");
		break;

		case ENGLAND:
			Preprocessor_Add("yes", "yes");
			Preprocessor_Add("attack", "Attack");
		break;

		case PIRATE:
			Preprocessor_Add("yes", DLG_TEXT[12]);
			Preprocessor_Add("attack", DLG_TEXT[13]);
		break;

		case PERSONAL_NATION:
			Preprocessor_Add("yes", DLG_TEXT[12]);
			Preprocessor_Add("attack", DLG_TEXT[13]);
		break;

		case GUEST1_NATION:
			if(GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN && GetCurrentPeriod() <= PERIOD_COLONIAL_POWERS)
			{
				Preprocessor_Add("yes", "ja");
				Preprocessor_Add("attack", "Angrip");
			}
			else
			{
				Preprocessor_Add("yes", "yes");
				Preprocessor_Add("attack", "Attack");
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
			AddDialogExitQuest("killyou");
		break;

		case "attack":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "exit";
			AddDialogExitQuest("killyou");
		break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "exit";
			AddDialogExitQuest("tosmuggler");
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

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
