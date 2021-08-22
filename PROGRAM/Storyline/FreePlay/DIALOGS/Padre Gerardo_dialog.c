//#include "DIALOGS\Padre Gerardo_dialog.h"
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
	string Father;

	// DeathDaisy -->
	switch(iNation)
	{
		case FRANCE:
			Father = "prкtre";
			Preprocessor_Add("allez", "Allez");
		break;

		case SPAIN:
			Father = "padre";
			Preprocessor_Add("allez", "Deprisa");
		break;

		case PORTUGAL:
			Father = "Padre";
			Preprocessor_Add("allez", "Va");
		break;

		case HOLLAND:
			Father = "priester";
			Preprocessor_Add("allez", "Haast");
		break;

		case ENGLAND:
			Father = "priest";
			Preprocessor_Add("allez", "Hurry");
		break;

		case PIRATE:
			Father = DLG_TEXT[13];
			Preprocessor_Add("allez", DLG_TEXT[14]);
		break;

		case PERSONAL_NATION:
			Father = DLG_TEXT[13];
			Preprocessor_Add("allez", DLG_TEXT[14]);
		break;

		case GUEST1_NATION:
			if(GetCurrentPeriod() >= PERIOD_THE_SPANISH_MAIN && GetCurrentPeriod() <= PERIOD_COLONIAL_POWERS)
			{
				Father = "prдst";
				Preprocessor_Add("allez", "Skynda");
			}
			else
			{
				Father = "priest";
				Preprocessor_Add("allez", "Hurry");
			}
		break;
	}
	// DeathDaisy <--
	
	Preprocessor_Add("father", Father);

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
			Dialog.snd = "dialogs\0\009";
			
			
			
			dialog.text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "node_1";
			break;

		case "whatthe":
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "whatthe2";
			break;

		case "whatthe2":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "whatthe3";
			break;

		case "whatthe3":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "whatthe4";
			break;

		case "whatthe4":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "Exit";
			AddDialogExitQuest("gettingrobes");
			break;

		case "plan1":
			if (GetCurrentPeriod() >= PERIOD_REVOLUTIONS) dialog.text = DLG_TEXT[15];
			else dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "plan2";
			break;

		case "plan2":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "Yes";
			//	link.l2 = DLG_TEXT[12];
			//	link.l2.go = "No";
			break;

		case "Yes":
			AddDialogExitQuest("padreofficer");
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;

		case "No":
			AddDialogExitQuest("nopadreofficer");	 // PB: Doesn't lead anywhere yet
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
			break;
	}
}