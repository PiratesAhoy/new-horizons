//#include "DIALOGS\Billy Brock_dialog.h"
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
			Dialog.defAni = "Sit_Look_Around";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "Sit_Look_Around";
			Dialog.cam = "1";

			dialog.snd = "Voice\BIBR\BIBR001";
			dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";

			if (PChar.quest.Lucas == "sign")
			{
				dialog.snd = "Voice\BIBR\BIBR002";
				Dialog.Text = DLG_TEXT[2];
				Link.l1 = DLG_TEXT[3];
				Link.l1.go = "Exit_sign";
			}
			if (PChar.quest.Lucas == "sign1")
			{
				dialog.snd = "Voice\BIBR\BIBR003";
				Dialog.Text = DLG_TEXT[4];
				Link.l1 = DLG_TEXT[5];
				Link.l1.go = "Exit_cash_ok";
			}
			if (PChar.quest.Lucas == "sign2")
			{
				dialog.snd = "Voice\BIBR\BIBR004";
				Dialog.Text = DLG_TEXT[6];
				Link.l1 = DLG_TEXT[7];
				Link.l1.go = "Pay";
				Link.l2 = DLG_TEXT[8];
				Link.l2.go = "No_pay";
			}

		break;

		case "Pay":
			dialog.snd = "Voice\BIBR\BIBR005";
			Dialog.Text = DLG_TEXT[9];
			Link.l1 = DLG_TEXT[10];
			Link.l1.go = "Exit_pay";

			if (makeint(PChar.money < 20000))
			{

				Dialog.Text = DLG_TEXT[11];
				Link.l1 = DLG_TEXT[12];
				Link.l1.go = "Exit_kill";
			}


		break;

		case "No_pay":
			dialog.snd = "Voice\BIBR\BIBR006";
			Dialog.Text = DLG_TEXT[13];
			Link.l1 = DLG_TEXT[14];
			Link.l1.go = "Pay";
		break;

		case "Exit_sign":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_sign2");

		break;

		case "Exit_cash_ok":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_sign7");

		break;

		case "Exit_pay":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_sign13");

		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;

		case "Exit_kill":

			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;

			AddDialogExitQuest("Lucas_kill");

		break;

	}
}
