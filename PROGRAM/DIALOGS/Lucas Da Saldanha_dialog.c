//#include "DIALOGS\Lucas Da Saldanha_dialog.h"
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
			Dialog.snd = "dialogs\0\009";
			
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			if(IsOfficer(CharacterFromID("Lucas Da Saldanha"))) AddDialogExitQuest("Lucas_officer"); // GR: Switch to normal officer dialog
			link.l1.go = "Exit";

		break;

		case "free":

				dialog.text = DLG_TEXT[2];
				link.l1 = DLG_TEXT[3];
				link.l1.go = "Exit_talk1_end";

		break;

		case "free_fight":

				dialog.text = DLG_TEXT[4];
				link.l1 = DLG_TEXT[5];
				link.l1.go = "Exit_talk1_fight_end";

		break;

		case "free1":

			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + GetMyFullName(PChar) + DLG_TEXT[8];
			link.l1.go = "free2";

		break;

		case "free2":

			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "free3";

		break;

		case "free3":

			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Exit_talk2_end";

		break;

		case "join":

			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit_join";
			link.l2 = DLG_TEXT[15];
			link.l2.go = "no_join";

		break;

		case "no_join":

			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "Exit_no_join";

		break;

		case "join_loop":

			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit_join";
			link.l2 = DLG_TEXT[20];
			link.l2.go = "Exit_join_loop";
		break;

		case "poem_1":

			/*
			Усталые глаза почти не видят
			Сиянья звезд в манящей вышине.
			Их свет холодный можно ненавидеть,
			А можно просто взять себе.

			Соткать из льдистых нитей покрывало,
			Ему доверив сокровенность снов,
			А если этого окажется вдруг мало -
			Порвать его на бессполезность слов.

			Сорвать цветок, в подарок своей Даме,
			А по пути - швырнуть его куда-то в грязь.
			Сменить стихи на меч, и рваться к славе,
			А после удивляться - как же низко можно пасть.

			Свой наточить клинок, готовясь к бою...
			И спрятать в ножны, испугавшись боли.
			*/

		break;

		case "Exit":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

		break;

		case "Exit_free1":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_talk1_1");

		break;

		case "Exit_talk1_end":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_talk1_1");

		break;

		case "Exit_talk2_end":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_talk2_1");

		break;

		case "Exit_talk1_fight_end":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_fight_talk1_1");

		break;

		case "Exit_join":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_join");

		break;

		case "Exit_no_join":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_no_join");

		break;

		case "Exit_join_loop":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			Characters[GetCharacterIndex("Lucas Da Saldanha")].dialog.CurrentNode = "join_loop";

		break;

	}
}
