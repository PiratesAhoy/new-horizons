
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];

	int your_rank = GetRank(PChar, ENGLAND);
	string your_rank_name;
	if (your_rank == 6) your_rank_name = "Captain";
	else your_rank_name = GetRankName(PChar, ENGLAND);

	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;
		
		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;

		case "welcome_aboard":
			dialog.text = your_rank_name + " " + GetMyLastName(PChar) + "?";
			link.l1 = DLG_TEXT[2];
			link.l1.go = "welcome_aboard2";

		break;

		case "welcome_aboard2":
			dialog.text = DLG_TEXT[3] + GetMyLastName(NPChar) + ". " + GetMyFullName(NPChar) + ".";
			Preprocessor_Add("name", GetMyLastName(NPChar));
			link.l1 = DLG_TEXT[4];
			link.l1.go = "welcome_aboard3";
		break;

		case "welcome_aboard3":
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "welcome_aboard4";

		break;

		case "welcome_aboard4":
			dialog.text = DLG_TEXT[7] + GetMyLastName(CharacterFromID("Spanish_lugger_captain")) + DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
		break;

		case "require_passage":
			dialog.text = DLG_TEXT[10] + your_rank_name + DLG_TEXT[11];
			link.l1 = DLG_TEXT[12] + "'" + PChar.Ship.Name + "'!";
			link.l1.go = "should_we_swim";
		break;

		case "should_we_swim":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "isla_muelle";
		break;

		case "isla_muelle":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "we_were_captured";
		break;

		case "we_were_captured":
			dialog.text = DLG_TEXT[17] + "'" + PChar.Ship.Name + "'!";
			link.l1 = DLG_TEXT[18];
			link.l1.go = "offended";
		break;

		case "offended":
			dialog.text = DLG_TEXT[19];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "you_cant_stay_aboard":
			dialog.text = "";
			link.l1 = DLG_TEXT[20];
			link.l1.go = "butchering_maniac";
		break;

		case "butchering_maniac":
			dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "death_either_way";
		break;

		case "death_either_way":
			dialog.text = DLG_TEXT[23];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "regret_insistence":
			dialog.text = "";
			link.l1 = DLG_TEXT[24] + GetMyLastName(CharacterFromID(PChar.quest.Hornblower_officer)) + DLG_TEXT[25];
			link.l1.go = "exit";
		break;

		case "not_disturbing":
			dialog.text = DLG_TEXT[26] + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Hornblower_thinks_otherwise";
		break;

		case "Hornblower_thinks_otherwise":
			dialog.text = DLG_TEXT[28] + your_rank_name + DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "not_his_fault";
		break;

		case "not_his_fault":
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "best_officer_in_service";
		break;

		case "best_officer_in_service":
			dialog.text = DLG_TEXT[33] + your_rank_name + DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
		break;

		case "not_so_gentle":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37] + strupper(GetMyLastName(PChar)) + "!";
			link.l1.go = "exit";
		break;

		case "answer_longley1":
			dialog.text = DLG_TEXT[38];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "answer_longley2":
			dialog.text = DLG_TEXT[39];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "not_know_how_to_kiss":
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[41];
			link.l1.go = "kiss_goodnight";
		break;

		case "kiss_goodnight":
			dialog.text = DLG_TEXT[42];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "how_did_you_know":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "goodbye_longley";
		break;

		case "goodbye_longley":
			dialog.text = DLG_TEXT[45];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "sweet_leighton":
			dialog.text = DLG_TEXT[46];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "goodbye_hornblower":
			dialog.text = DLG_TEXT[47] + your_rank_name + " " + GetMyLastName(PChar) + DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "exit";
		break;

		case "meet_after_briefing":
			dialog.text = DLG_TEXT[50] + GetMyLastName(PChar) + DLG_TEXT[51];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "meet_after_briefing2":
			dialog.text = "";
			link.l1 = DLG_TEXT[52];
			link.l1.go = "thanks_for_bringing_me";
		break;

		case "thanks_for_bringing_me":
			dialog.text = DLG_TEXT[53];
			link.l1 = DLG_TEXT[54];
			link.l1.go = "about_the_wedding";
		break;

		case "about_the_wedding":
			dialog.text = DLG_TEXT[55];
			link.l1 = DLG_TEXT[56];
			link.l1.go = "goodbye_again";
		break;

		case "goodbye_again":
			dialog.text = DLG_TEXT[57] + GetMyName(PChar) + DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
		break;
	}
}
