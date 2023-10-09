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
			Dialog.snd = "voice\PAJO\PAJO001";

			if(GetAttribute(NPChar, "quest.meeting") != "1")
			{
				Dialog.Text = DLG_TEXT[0]; // KK
				Link.l1 = DLG_TEXT[2] + DLG_TEXT[47] + GetMyFullName(PChar) + ".";
			}
			else
			{
				Dialog.Text = DLG_TEXT[45] + GetMyName(PChar) + DLG_TEXT[46];
				Link.l1 = DLG_TEXT[2];
			}
			link.l1.go = "node_3";
			link.l2 = DLG_TEXT[1];
			Link.l2.go = "node_2";
			NextDiag.TempNode = "First time";
		break;

		case "node_2":
			Dialog.snd = "voice\PAJO\PAJO002";
			dialog.text = DLG_TEXT[3];
			link.l1 = DLG_TEXT[4];
			link.l1.go = "node_2a";
			ChangeCharacterReputation(pchar, -1);
		break;

		case "node_2a":
			LAi_QuestDelay("God_hit_us", 0.1);
			Dialog.snd = "voice\PAJO\PAJO002";
			if(GetAttribute(NPChar, "quest.meeting") != "1") dialog.text = DLG_TEXT[43];
			else dialog.text = DLG_TEXT[48] + GetMyLastName(PChar) + ".";
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
		break;

		case "node_3":
			NPChar.quest.meeting = "1";
			Dialog.snd = "voice\PAJO\PAJO003";
			dialog.text = DLG_TEXT[5];
			link.l1 = DLG_TEXT[6];
			link.l1.go = "donation";
			if(CheckAttribute(NPChar, "nation"))
			{
				link.l2 = DLG_TEXT[7];
				link.l2.go = "ispoved";
			}
			link.l3 = DLG_TEXT[8];
			link.l3.go = "exit";
		break;

		case "donation":
			Dialog.snd = "voice\PAJO\PAJO004";
			dialog.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "No donation";
// NK -->
			// TIH --> do once, and only up to a certain level due to limitations on game Aug29'06
			int iRepRank = 150;
			if (sti(PChar.rank) < 50) { iRepRank = makeint(sqrt(sqrt(sti(PChar.rank)^5))); }
			if(sti(PChar.money)>=500 * iRepRank)
			{
				Link.l2 = DLG_TEXT[38] + (500 * iRepRank) + DLG_TEXT[39];
				Link.l2.go = "donation paid_500";
			}
			if(sti(PChar.money)>=2500 * iRepRank)
			{
				Link.l3 = DLG_TEXT[40] + (2500 * iRepRank) + DLG_TEXT[41];
				Link.l3.go = "donation paid_2500";
			}
			if(sti(PChar.money)>=5000 * iRepRank)
			{
				Link.l4 = DLG_TEXT[42] + (5000 * iRepRank) + DLG_TEXT[41];
				Link.l4.go = "donation paid_5000";
			}
		break;

		case "No donation":
			Dialog.snd = "voice\PADO\PADO042";
			dialog.Text = DLG_TEXT[14];
			Link.l1 = DLG_TEXT[15];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[16];
			Link.l2.go = "exit";
		break;

		case "donation paid_500":
			Dialog.snd = "voice\PADO\PADO043";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_2500":
			Dialog.snd = "voice\PADO\PADO043";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 2500 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
		break;
		
		case "donation paid_5000":
			Dialog.snd = "voice\PADO\PADO043";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5))));
			pchar.quest.donate = makeint(pchar.quest.donate) + 5000 * makeint(sqrt(sqrt(makeint(pchar.rank)^5)));
			dialog.Text = DLG_TEXT[23];
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "node_3";
			Link.l2 = DLG_TEXT[25];
			Link.l2.go = "exit";
			AddDialogExitQuest("donation");
// NK <--
		break;

		case "ispoved":
			Dialog.snd = "voice\PAJO\PAJO006";
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[28];
			link.l2.go = "ispoved_1";
		break;

		case "ispoved_1":
			Dialog.snd = "voice\PAJO\PAJO007";	
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			link.l1.go = "ispoved_2";
		break;

		case "ispoved_2":
			Preprocessor_Add("nation",GetNationDescByType(sti(NPChar.nation)));
			Dialog.snd = "voice\PAJO\PAJO008";
			dialog.text = DLG_TEXT[31];
			link.l1 = DLG_TEXT[32];
			link.l1.go = "ispoved_3";
			link.l2 = DLG_TEXT[33];
			link.l2.go = "ispoved_4";
		break;

		case "ispoved_3":
			Dialog.snd = "voice\PAJO\PAJO009";
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "exit";
		break;

		case "ispoved_4":
			Dialog.snd = "voice\PAJO\PAJO010";
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			link.l1.go = "exit";
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
