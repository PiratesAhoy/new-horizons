//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string gov_kid, gov_kid1, gov_kid2, merch_kid;
	string escapers = "";

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	if (PChar.sex == "man")
	{
		gov_kid = "her";
		gov_kid1 = "she";
		gov_kid2 = "daughter";
		merch_kid = "him";
	}
	else
	{
		gov_kid = "him";
		gov_kid1 = "he";
		gov_kid2 = "son";
		merch_kid = "her";
	}
	
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

		case "Rescued":
			if (isofficer(characterFromID("Louwe Louwman")) || isofficer(characterFromID("Giraldo Annibal")) || isofficer(characterFromID("Gheerkin Kamalaas")) || isofficer(characterFromID("Morys Badlad")))
			{
				dialog.text = DLG_TEXT[2];
				escapers = DLG_TEXT[4];
			}
			else dialog.text = DLG_TEXT[3];
			if (checkquestattribute("alignment", "evil")) link.l1 = escapers + DLG_TEXT[5];
			else link.l1 = escapers + DLG_TEXT[6];
			link.l1.go = "Exit";
		break;

		case "back_in_havana":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "back_in_havana2";
		break;

		case "back_in_havana2":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Exit";
		break;

		case "got_a_ship":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "got_a_ship2";
		break;

		case "got_a_ship2":
			if (checkquestattribute("alignment", "good")) dialog.text = DLG_TEXT[13];
			else dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "Exit";
		break;

		case "follow_him":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "follow_him2";
		break;

		case "follow_him2":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit";
		break;

		case "crew_returning":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Exit";
		break;

		case "ready_for_payroll_ship":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "Exit";
		break;

		case "payroll_ship_in_sight":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Exit";
		break;

		case "buccaneer_tavern_duel":
			dialog.text = DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			link.l1.go = "Exit";
		break;

		case "take_hostage_to_ship":
			dialog.text = DLG_TEXT[28] + gov_kid2 + "!";
			link.l1 = DLG_TEXT[29] + GetMyAddressForm(characterFromID(PChar.quest.romance), characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[30] + GetMyName(characterFromID(PChar.quest.romance)) + DLG_TEXT[31];
			link.l1.go = "exit";
		break;

		case "married_congrats":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "exit";
		break;
	}
}