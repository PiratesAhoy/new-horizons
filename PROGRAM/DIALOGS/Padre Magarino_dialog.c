//#include "DIALOGS\padre Domingues_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, NextDiag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(NextDiag, NPChar.Dialog);
	int iTest;

	ref PChar;
	PChar = GetMainCharacter();
	
	if (PChar.sex == "man") Preprocessor_Add("addr", XI_ConvertString("my son"));
	else Preprocessor_Add("addr", XI_ConvertString("my child"));

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
			Dialog.snd = "voice\PADO\PADO001";
			
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "quests";
			link.l2 = DLG_TEXT[2];
			link.l2.go = "donation";
			link.l99 = DLG_TEXT[3];
			link.l99.go = "exit";
			NextDiag.TempNode = "first time";
		break;

		case "quests":
			iTest = 0;
			Dialog.snd = "voice\PADO\PADO002";
			dialog.text = DLG_TEXT[4];
// Add quest-related responses here
			link.l99 = DLG_TEXT[5];
			link.l99.go = "exit";
		break;
		
		case "donation":
			Dialog.snd = "voice\PADO\PADO041";
			dialog.Text = DLG_TEXT[6];
			Link.l1 = DLG_TEXT[7];
			Link.l1.go = "No donation";
// NK -->
			// TIH --> do once, and only up to a certain level due to limitations on game Aug29'06
			int iRepRank = 150;
			if (sti(PChar.rank) < 50) { iRepRank = makeint(sqrt(sqrt(sti(PChar.rank)^5))); }
			if(sti(PChar.money)>=500 * iRepRank)
			{
				Link.l2 = DLG_TEXT[23] + (500 * iRepRank) + DLG_TEXT[24];
				Link.l2.go = "donation paid_500";
			}
			if(sti(PChar.money)>=2500 * iRepRank)
			{
				Link.l3 = DLG_TEXT[25] + (2500 * iRepRank) + DLG_TEXT[26];
				Link.l3.go = "donation paid_2500";
			}
			if(sti(PChar.money)>=5000 * iRepRank)
			{
				Link.l4 = DLG_TEXT[27] + (5000 * iRepRank) + DLG_TEXT[26];
				Link.l4.go = "donation paid_5000";
			}
			/* prior method, broken
			if(makeint(PChar.money)>=500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{	
				Link.l2 = DLG_TEXT[23] + (500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[24];
				Link.l2.go = "donation paid_500";
			}
			if(makeint(PChar.money)>=2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{
				Link.l3 = DLG_TEXT[25] + (2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[26];
				Link.l3.go = "donation paid_2500";
			}
			if(makeint(PChar.money)>=5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))))
			{	
				Link.l4 = DLG_TEXT[27] + (5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)))) + DLG_TEXT[26];
				Link.l4.go = "donation paid_5000";
			}
			*/
			// TIH <--
		break;

		case "No donation":
			Dialog.snd = "voice\PADO\PADO042";
			dialog.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "quests";
			Link.l2 = DLG_TEXT[13];
			Link.l2.go = "exit";
		break;

		case "donation paid_500":
			Dialog.snd = "voice\PADO\PADO043";
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "quests";
			Link.l2 = DLG_TEXT[16];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_2500":
			Dialog.snd = "voice\PADO\PADO043";
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "quests";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_5000":
			Dialog.snd = "voice\PADO\PADO043";
		    PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "quests";
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
// NK <--
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "wedding_consent1":
			Dialog.snd = "voice\PADO\PADO043";
			dialog.text = DLG_TEXT[28] + PChar.quest.groom + DLG_TEXT[55] + PChar.quest.bride + DLG_TEXT[29];
			if (PChar.sex == "man") link.l1 = DLG_TEXT[41];
			else link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
		break;

		case "wedding_consent2":
			Dialog.snd = "voice\PADO\PADO043";
			dialog.text = DLG_TEXT[31];
			if (PChar.sex == "man") link.l1 = DLG_TEXT[32];
			else link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
		break;

		case "wedding_consent3":
			Dialog.snd = "voice\PADO\PADO043";
			dialog.text = DLG_TEXT[33];
			if (PChar.sex == "man") link.l1 = DLG_TEXT[34];
			else link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
		break;

		case "his_vow":
			Preprocessor_Add("groom", PChar.quest.groom);
			Preprocessor_Add("bride", PChar.quest.bride);
			Dialog.snd = "voice\PADO\PADO043";
			dialog.text = DLG_TEXT[36];
			if (PChar.sex == "man")
			{
				link.l1 = DLG_TEXT[37];
				link.l1.go = "her_vow";
			}
			else
			{
				link.l1 = DLG_TEXT[39];
				AddDialogExitQuest("Wedding_vow_his_answer");
				link.l1.go = "exit";
			}
		break;

		case "her_vow":
			Preprocessor_Add("groom", PChar.quest.groom);
			Preprocessor_Add("bride", PChar.quest.bride);
			Dialog.snd = "voice\PADO\PADO043";
			dialog.text = DLG_TEXT[38];
			if (PChar.sex == "man")
			{
				link.l1 = DLG_TEXT[39];
				AddDialogExitQuest("Wedding_vow_her_answer");
			}
			else
			{
				link.l1 = DLG_TEXT[37];
				AddDialogExitQuest("Wedding_bless_rings");
			}
			link.l1.go = "exit";
		break;

		case "bless_rings":
			Dialog.snd = "voice\PADO\PADO043";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
		break;

		case "final_blessing":
			Dialog.snd = "voice\PADO\PADO043";
			dialog.text = DLG_TEXT[40];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
		break;

		case "ardent_interruption1":
			dialog.text = DLG_TEXT[42];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "ardent_interruption2":
			Preprocessor_Add("villain", GetMyFullName(CharacterFromID(PChar.quest.villain)));
			Preprocessor_Add("romance", GetMyFullName(CharacterFromID(PChar.quest.romance)));
			if (PChar.sex == "man") dialog.text = DLG_TEXT[43] + DLG_TEXT[45] + DLG_TEXT[46];
			else dialog.text = DLG_TEXT[43] + DLG_TEXT[44] + DLG_TEXT[46];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "ardent_no_fight_in_church":
			dialog.text = DLG_TEXT[47];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "ardent_about_to_sin":
			dialog.text = "";
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
		break;

		case "ardent_church_desecrated":
			Preprocessor_Add("villain", GetMyFullName(CharacterFromID(PChar.quest.villain)));
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "exit";
		break;

		case "ardent_loyal_to_church_first":
			dialog.text = DLG_TEXT[51];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "ardent_proceed_with_wedding":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "ardent_resume_wedding";
		break;

		case "ardent_resume_wedding":
			dialog.text = DLG_TEXT[54] + DLG_TEXT[33];
			if (PChar.sex == "man") link.l1 = DLG_TEXT[34];
			else link.l1 = DLG_TEXT[39];
			link.l1.go = "exit";
		break;
	}
}
