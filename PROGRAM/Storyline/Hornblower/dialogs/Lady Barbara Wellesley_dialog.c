
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
			dialog.text = DLG_TEXT[3] + your_rank_name + DLG_TEXT[4] + GetMyFullName(NPChar) + ".";
			link.l1 = DLG_TEXT[5] + NPChar.title + " " + GetMyName(NPChar) + ".";
			link.l1.go = "welcome_aboard3";
		break;

		case "welcome_aboard3":
			dialog.text = DLG_TEXT[6] + your_rank_name + ".";
			link.l1 = DLG_TEXT[7];
			link.l1.go = "welcome_aboard4";
		break;

		case "welcome_aboard4":
			dialog.text = DLG_TEXT[8] + GetMyLastName(CharacterFromID("Spanish_lugger_captain")) + DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
		break;

		case "require_passage":
			dialog.text = DLG_TEXT[11] + your_rank_name + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13] + "'" + PChar.Ship.Name + "'!";
			link.l1.go = "should_we_swim";
		break;

		case "should_we_swim":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "isla_muelle";
		break;

		case "isla_muelle":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "we_were_captured";
		break;

		case "we_were_captured":
			dialog.text = DLG_TEXT[18] + "'" + PChar.Ship.Name + "'!";
			link.l1 = DLG_TEXT[19];
			link.l1.go = "offended";
		break;

		case "offended":
			dialog.text = DLG_TEXT[20];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "you_cant_stay_aboard":
			dialog.text = "";
			link.l1 = DLG_TEXT[21];
			link.l1.go = "butchering_maniac";
		break;

		case "butchering_maniac":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "death_either_way";
		break;

		case "death_either_way":
			dialog.text = DLG_TEXT[24];
			link.l1 = "...";
			link.l1.go = "exit";
		break;

		case "regret_insistence":
			dialog.text = "";
			link.l1 = DLG_TEXT[25] + GetMyLastName(CharacterFromID(PChar.quest.Hornblower_officer)) + DLG_TEXT[26];
			link.l1.go = "exit";
		break;

		case "not_disturbing":
			dialog.text = DLG_TEXT[27] + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[28];
			link.l1.go = "Hornblower_thinks_otherwise";
		break;

		case "Hornblower_thinks_otherwise":
			dialog.text = DLG_TEXT[29] + your_rank_name + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "not_his_fault";
		break;

		case "not_his_fault":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "best_officer_in_service";
		break;

		case "best_officer_in_service":
			dialog.text = DLG_TEXT[34] + your_rank_name + DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
		break;

		case "not_so_gentle":
			dialog.text = DLG_TEXT[37];
			link.l1 = DLG_TEXT[38] + strupper(GetMyLastName(PChar)) + "!";
			link.l1.go = "exit";
		break;

		case "answer_longley1":
			dialog.text = DLG_TEXT[39];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "answer_longley2":
			dialog.text = DLG_TEXT[40];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "not_know_how_to_kiss":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "kiss_goodnight";
		break;

		case "kiss_goodnight":
			dialog.text = DLG_TEXT[43];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "how_did_you_know":
			dialog.text = DLG_TEXT[44];
			link.l1 = DLG_TEXT[45];
			link.l1.go = "goodbye_longley";
		break;

		case "goodbye_longley":
			dialog.text = DLG_TEXT[46];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "sweet_leighton":
			dialog.text = DLG_TEXT[47];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "goodbye_hornblower":
			dialog.text = DLG_TEXT[48] + your_rank_name + " " + GetMyLastName(PChar) + DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
		break;

		case "meet_after_briefing":
			dialog.text = DLG_TEXT[51] + GetMyLastName(PChar) + DLG_TEXT[52];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "meet_after_briefing2":
			dialog.text = "";
			link.l1 = DLG_TEXT[53];
			link.l1.go = "sorry_about_news";
		break;

		case "sorry_about_news":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "you_have_a_son";
		break;

		case "you_have_a_son":
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "you_have_a_son2";
		break;

		case "you_have_a_son2":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "goodbye_again";
		break;

		case "goodbye_again":
			dialog.text = DLG_TEXT[60] + GetMyName(PChar) + DLG_TEXT[61];
			link.l1 = DLG_TEXT[62];
			link.l1.go = "exit";
		break;
	}
}
