//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	int your_rank = GetRank(PChar, ENGLAND);
	string your_rank_name;
	string el_supremo_short_name = GetAttribute(CharacterFromID("El Supremo"), "title") + " " + GetMyName(CharacterFromID("El Supremo"));

	if (your_rank == 6) your_rank_name = "Captain";
	else your_rank_name = GetRankName(PChar, ENGLAND);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode; //"First time";
			DialogExit();
		break;

	
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
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "Hernandez_comes_aboard":
			dialog.text = your_rank_name + " " + GetMyLastName(PChar) + DLG_TEXT[2] + GetMyFullName(NPChar) + DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "Hernandez_comes_aboard2";
		break;

		case "Hernandez_comes_aboard2":
			dialog.text = DLG_TEXT[5] + GetMyFullName(CharacterFromID("El Supremo")) + ".";
			link.l1 = DLG_TEXT[6] + GetMyFullName(CharacterFromID("El Supremo")) + "?";
			link.l1.go = "Hernandez_comes_aboard3";
		break;

		case "Hernandez_comes_aboard3":
			dialog.text = DLG_TEXT[7];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "Hernandez_warns_about_paths":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9] + el_supremo_short_name + DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		case "Hernandez_respect_El_Supremo":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			AddDialogExitQuest("Hornblower_Hernandez_shuts_up");
			link.l1.go = "exit";
		break;

		case "Supply_order":
			dialog.text = "";
			link.l1 = DLG_TEXT[13];
			link.l1.go = "We_have_rum";
		break;

		case "We_have_rum":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
//			AddDialogExitQuest("Hornblower_exchange_weapons_for_supplies");
			link.l1.go = "exit";
		break;
	}
}