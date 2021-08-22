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

		case "introductions":
			dialog.text = GetMySimpleName(NPChar) + DLG_TEXT[2] + your_rank_name + " " + GetMyLastName(PChar) + "?";
			link.l1 = DLG_TEXT[3];
			link.l1.go = "good news";
		break;

		case "good news":
			dialog.text = DLG_TEXT[4] + your_rank_name + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "new allies";
		break;

		case "new allies":
			Preprocessor_Add("rank", your_rank_name);
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "too good";
		break;

		case "too good":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		case "new king":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "wise to run";
		break;

		case "wise to run":
			dialog.text = DLG_TEXT[13] + your_rank_name + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "joking";
		break;

		case "joking":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "exit";
		break;

		case "gave_away_Natividad":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "exit";
		break;

		case "adios":
			Preprocessor_Add("name", GetMyLastName(CharacterFromID(PChar.quest.Hornblower_officer)));
			dialog.text = "";
			link.l1 = DLG_TEXT[20];
			link.l1.go = "exit";
		break;
	}
}