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

		case "snow_brig_check":
			dialog.text = DLG_TEXT[2];
			if (PChar.sex == "man") link.l1 = DLG_TEXT[3];
			else link.l1 = DLG_TEXT[65];
			link.l1.go = "snow_brig_check2";
		break;

		case "snow_brig_check2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "snow_brig_check3";
		break;

		case "snow_brig_check3":
			dialog.text = DLG_TEXT[6];
			if (PChar.sex == "man") link.l1 = DLG_TEXT[7];
			else link.l1 = DLG_TEXT[66];
			link.l1.go = "snow_brig_check4";
			link.l2 = GetMyFullName(PChar) + ".";
			link.l2.go = "wrong_answer";
		break;

		case "snow_brig_check4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "wrong_answer";
			link.l2 = DLG_TEXT[10];
			link.l2.go = "right_answer";
		break;

		case "wrong_answer":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Exit";
			AddDialogExitQuest("back_to_prison");
		break;

		case "right_answer":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Exit";
			AddDialogExitQuest("ship_is_ours3");
		break;

		case "residence_challenge":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16] + GetMyAddressForm(characterFromID(PChar.quest.romance), characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMySimpleName(characterFromID(PChar.quest.romance)) + DLG_TEXT[17];
			link.l1.go = "Exit";
		break;

		case "hostage_cooperated":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Exit";
		break;

		case "residence_challenge_day":
			dialog.text = DLG_TEXT[20] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, true, true) + DLG_TEXT[21];
			link.l1 = DLG_TEXT[22] + GetMyFullName(characterFromID(PChar.quest.villain)) + DLG_TEXT[23] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[24];
			link.l1.go = "Exit";
		break;

		case "still_suspicious":
			dialog.text = DLG_TEXT[25] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, true) + DLG_TEXT[26] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.villain), ADDR_CIVIL, false, true) + DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "still_suspicious2";
		break;

		case "still_suspicious2":
			dialog.text = DLG_TEXT[29] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.villain), ADDR_CIVIL, true, true) + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "Exit";
		break;

		case "wrong_way_to_ring":
			dialog.text = DLG_TEXT[32] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, true) + "?";
			link.l1 = DLG_TEXT[33];
			link.l1.go = "Exit";
		break;

		case "no_church_for_you":
			dialog.text = GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, true) + DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "Exit";
		break;

		case "no_escape_to_port":
			dialog.text = DLG_TEXT[36] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, true) + DLG_TEXT[37];
			link.l1 = DLG_TEXT[38];
			link.l1.go = "Exit";
		break;

		case "did_you_get_ring":
			dialog.text = DLG_TEXT[39];
			link.l1 = DLG_TEXT[40];
			link.l1.go = "Exit";
		break;

		case "port_challenge":
			dialog.text = DLG_TEXT[41];
			link.l1 = DLG_TEXT[42];
			link.l1.go = "who_with_you";
		break;

		case "who_with_you":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
		break;

		case "cabin_boy":
			dialog.text = DLG_TEXT[45];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
		break;

		case "guard_embarrassed":
			dialog.text = DLG_TEXT[46];
			link.l1 = DLG_TEXT[47]
			link.l1.go = "exit";
		break;

		case "assassination_arrest":
			dialog.text = DLG_TEXT[48];
			link.l1 = DLG_TEXT[49];
			link.l1.go = "not_guilty";
		break;

		case "not_guilty":
			dialog.text = DLG_TEXT[50];
			link.l1 = DLG_TEXT[51];
			link.l1.go = "father_in_law";
		break;

		case "father_in_law":
			dialog.text = DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "lying";
		break;

		case "lying":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
		break;

		case "go_to_governor":
			if (PChar.sex == "man")
			{
				PreProcessor_Add("noun", "man");
				PreProcessor_Add("relation", "son");
			}
			else
			{
				PreProcessor_Add("noun", "woman");
				PreProcessor_Add("relation", "daughter");
			}
			dialog.text = DLG_TEXT[56];
			link.l1 = DLG_TEXT[57];
			link.l1.go = "exit";
		break;

		case "convoy_search":
			dialog.text = DLG_TEXT[58];
			link.l1 = DLG_TEXT[59] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[60];
			AddDialogExitQuest("convoy_searchers_arrive");
			link.l1.go = "exit";
		break;

		case "convoy_found_romance":
			dialog.text = DLG_TEXT[61];
			if (PChar.sex == "man") PreProcessor_Add("relation", "daughter");
			else PreProcessor_Add("relation", "son");
			link.l1 = DLG_TEXT[62] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[63] + GetMyFullName(characterFromID("Javier Balboa")) + DLG_TEXT[64];
			link.l1.go = "exit";
		break;			
	}
}