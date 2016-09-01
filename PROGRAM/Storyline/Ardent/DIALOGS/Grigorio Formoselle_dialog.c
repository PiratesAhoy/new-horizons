//#include "DIALOGS\Morgan Terror_Dialog.h"
void ProcessDialogEvent()
{
	ref NPChar;
	aref Link, Diag; //NextDiag;
	string gov_kid, merch_kid;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();

	if (PChar.sex == "man")
	{
		gov_kid = "her";
		merch_kid = "him";
	}
	else
	{
		gov_kid = "him";
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

			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "first_delivery":
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyFullName(characterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "first_delivery2";
		break;

		case "first_delivery2":
			dialog.text = DLG_TEXT[4] + gov_kid + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6] + GetMyName(characterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "first_delivery3";
		break;

		case "first_delivery3":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8] + GetMyFullName(characterFromID(PChar.quest.villain)) + DLG_TEXT[9];
			link.l1.go = "first_delivery4";
		break;

		case "first_delivery4":
			dialog.text = DLG_TEXT[10] + GetMyFullName(characterFromID(PChar.quest.villain)) + DLG_TEXT[11] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			AddDialogExitQuest("first_CourtingLetter_delivered");
			link.l1.go = "exit";
		break;

		case "second_delivery":
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];
			link.l1 = DLG_TEXT[14] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[15];
			link.l1.go = "second_delivery2";
		break;

		case "second_delivery2":
			dialog.text = DLG_TEXT[16] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.villain), ADDR_CIVIL, false, false) + " " + GetMyFullName(characterFromID(PChar.quest.villain)) + DLG_TEXT[17] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyFullName(characterFromID(PChar.quest.romance)) + ".";
			link.l1 = DLG_TEXT[18];
			AddDialogExitQuest("second_CourtingLetter_delivered");
			link.l1.go = "exit";
		break;

		case "break-in":
			dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20] + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[21];
			link.l1.go = "break-in2";
		break;

		case "break-in2":
			dialog.text = DLG_TEXT[22];
			link.l1 = DLG_TEXT[23];
			link.l1.go = "break-in3";
		break;

		case "break-in3":
			dialog.text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[25] + gov_kid + DLG_TEXT[26] + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[27];
			link.l1.go = "break-in4";
		break;

		case "break-in4":
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
		break;

		case "alarm_governor_dead":
			dialog.text = DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "exit";
		break;

		case "ransom_exchange":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33] + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[34];
			link.l1.go = "ransom_exchange2";
		break;

		case "ransom_exchange2":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "ransom_exchange3";
		break;

		case "ransom_exchange3":
			dialog.text = DLG_TEXT[37] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMySimpleName(characterFromID(PChar.quest.romance)) + ".";
			link.l1 = DLG_TEXT[38] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[39];
			link.l1.go = "ransom_exchange4";
		break;

		case "ransom_exchange4":
			dialog.text = GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[40];
			link.l1 = "...";
			AddDialogExitQuest("hostage_released");
			link.l1.go = "exit";
		break;

		case "ransom_exchange5":
			dialog.text = DLG_TEXT[41] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[42];
			link.l1 = DLG_TEXT[43];
			link.l1.go = "ransom_exchange6";
		break;

		case "ransom_exchange6":
			dialog.text = DLG_TEXT[44] + PChar.quest.ardent_kidnap.ransom + DLG_TEXT[45];
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
		break;

		case "assassination_examine_ring":
			PreProcessor_Add("villain", GetMyFullName(characterFromID(PChar.quest.villain)));
			PreProcessor_Add("romance", GetMyFullName(characterFromID(PChar.quest.romance)));
			if (PChar.sex == "man") PreProcessor_Add("pronoun", "His");
			else PreProcessor_Add("pronoun", "Her");
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
		break;
	}
}