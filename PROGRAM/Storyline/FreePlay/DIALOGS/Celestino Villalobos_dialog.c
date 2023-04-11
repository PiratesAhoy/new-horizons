//#include "DIALOGS\Celestino Villalobos_dialog.h"

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

			dialog.text = DLG_TEXT[0] + GetMyLastName(pchar) + DLG_TEXT[1];
			link.l1 = DLG_TEXT[2];
			link.l1.go = "begin_1";
			break;

		case "begin_1":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "begin_2";
			break;

		case "begin_2":
			dialog.snd = "Voice\CLLA\CLLA004";
			// DeathDaisy -->
			int iNation = sti(PChar.nation);
			switch(iNation)
			{
				case FRANCE:
					Preprocessor_Add("friend", DLG_TEXT[15]);
				break;

				case SPAIN:
					Preprocessor_Add("friend", DLG_TEXT[16]);
				break;

				case PORTUGAL:
					Preprocessor_Add("friend", DLG_TEXT[17]);
				break;

				case HOLLAND:
					Preprocessor_Add("friend", DLG_TEXT[18]);
				break;

				case ENGLAND:
					Preprocessor_Add("friend", DLG_TEXT[19]);
				break;

				case PIRATE:
					Preprocessor_Add("friend", DLG_TEXT[14]);
				break;

				case PERSONAL_NATION:
					Preprocessor_Add("friend", DLG_TEXT[14]);
				break;

				case GUEST1_NATION:
					if(GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN && GetCurrentPeriod() <= PERIOD_COLONIAL_POWERS)
					{
						Preprocessor_Add("friend", DLG_TEXT[20]);
					}
					else
					{
						Preprocessor_Add("friend", DLG_TEXT[19]);
					}
				break;
			}
			// DeathDaisy <--
			dialog.text = DLG_TEXT[5];
			if (CharPlayerType == PLAYER_TYPE_ROGUE)
			{
				if(PChar.sex == "woman") link.l1 = DLG_TEXT[7];
				else link.l1 = DLG_TEXT[6];
			}
			if (CharPlayerType == PLAYER_TYPE_GAMBLER)	link.l1 = DLG_TEXT[8];
			link.l1.go = "begin_3";
			break;

		case "begin_3":
			dialog.snd = "Voice\CLLA\CLLA004";
			// DeathDaisy -->
			string Puta;
			if(PChar.sex == "woman")
				Puta = DLG_TEXT[21];
			else
				Puta = DLG_TEXT[22];
			Preprocessor_Add("puta", Puta);
			Preprocessor_Add("gender", GetMyAddressForm(NPChar, PChar, ADDR_GENDER, false, false));
			// DeathDaisy <--
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "begin_4";
			break;

		case "begin_4":
			dialog.snd = "Voice\CLLA\CLLA004";
			dialog.text = DLG_TEXT[11] + GetMyLastName(pchar) + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "exit";
			AddDialogExitQuest("fightcelestino");
			break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
	}
}
