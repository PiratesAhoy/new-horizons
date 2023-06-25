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

	if (your_rank == 6) your_rank_name = XI_ConvertString("Captain");
	else your_rank_name = XI_ConvertString(GetRankName(PChar, ENGLAND));
	
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

		case "Natividad_announcement":
			dialog.text = DLG_TEXT[2];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "rebel_guard":
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "exit";
		break;

		case "Natividad_approaches":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "exit";
		break;

		case "Natividad_anchored":
			dialog.text = DlG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			AddDialogExitQuest("Hornblower_Natividad_anchored4");
			link.l1.go = "exit";
		break;

		case "I_know_the_way":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10] + GetMyLastName(NPChar) + DLG_TEXT[11];
			link.l1.go = "I_know_the_way2";
		break;

		case "I_know_the_way2":
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13] + GetMyLastName(NPChar) + ".";
			link.l1.go = "exit";
		break;

		case "Natividad_captain_surrender":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "exit";
		break;

		case "Natividad_rules_of_war":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "women_aboard":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
		break;

		case "second_opinion":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";
		break;

		case "how_she_settling":
			dialog.text = "";
			link.l1 = DLG_TEXT[22];
			link.l1.go = "tending_wounded";
		break;

		case "tending_wounded":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "insisted_on_helping";
		break;

		case "insisted_on_helping":
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "no_stopping_her";
		break;

		case "no_stopping_her":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "aye_aye";
		break;

		case "aye_aye":
			dialog.text = DLG_TEXT[29];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "admirals_upstairs":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			AddDialogExitQuest("Hornblower_Eccleston_sits");
			link.l1.go = "exit";
		break;
	}
}