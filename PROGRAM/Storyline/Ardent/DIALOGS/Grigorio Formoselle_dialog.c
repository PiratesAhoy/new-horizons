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

/*	if (PChar.sex == "man")
	{
		gov_kid = XI_ConvertString("her");
		merch_kid = XI_ConvertString("him");
	}
	else
	{
		gov_kid = XI_ConvertString("him");
		merch_kid = XI_ConvertString("her");
	} */
	gov_kid = XI_ConvertString(GetMyPronounObj(CharacterFromID(PChar.quest.romance)));
	merch_kid = XI_ConvertString(GetMyPronounObj(CharacterFromID(PChar.quest.villain)));
	
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
			link.l1 = DLG_TEXT[3] + GetMyFullName(CharacterFromID(PChar.quest.romance)) + ".";
			link.l1.go = "first_delivery2";
		break;

		case "first_delivery2":
			dialog.text = DLG_TEXT[4] + gov_kid + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6] + GetMyName(CharacterFromID(PChar.quest.romance)) + ".";
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
//			link.l1 = DLG_TEXT[14] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.romance), ADDR_CIVIL, false, false) + " " + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[15];
			link.l1 = DLG_TEXT[14] + GetMyFullName(characterFromID(PChar.quest.romance)) + DLG_TEXT[15];
			link.l1.go = "second_delivery2";
		break;

		case "second_delivery2":
			dialog.text = DLG_TEXT[16] + GetMyAddressForm(NPChar, characterFromID(PChar.quest.villain), ADDR_CIVIL, false, false) + " " + GetMyFullName(characterFromID(PChar.quest.villain)) + DLG_TEXT[17] + GetMyFullName(characterFromID(PChar.quest.romance)) + ".";
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
			dialog.text = DLG_TEXT[37] + GetMyFullName(characterFromID(PChar.quest.romance)) + ".";
			link.l1 = DLG_TEXT[38] + characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[39];
			link.l1.go = "ransom_exchange4";
		break;

		case "ransom_exchange4":
			dialog.text = characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[40];
			link.l1 = "...";
			AddDialogExitQuest("hostage_released");
			link.l1.go = "exit";
		break;

		case "ransom_exchange5":
			dialog.text = DLG_TEXT[41] + characters[getCharacterIndex(PChar.quest.romance)].title + " " + GetMyFirstNames(characterFromID(PChar.quest.romance), false) + DLG_TEXT[42];
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
			if (PChar.sex == "man") PreProcessor_Add("pronoun", XI_ConvertString("his"));
			else PreProcessor_Add("pronoun", XI_ConvertString("her"));
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "exit";
		break;

		case "imperial_escort_jailbreak":
			dialog.text = DLG_TEXT[49];
			link.l1 = DLG_TEXT[50];
			link.l1.go = "imperial_escort_stay_here";
		break;

		case "imperial_escort_stay_here":
			dialog.text = DLG_TEXT[51] + GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[52];
			link.l1 = DLG_TEXT[53];
			link.l1.go = "imperial_escort_get_your_stuff";
		break;

		case "imperial_escort_get_your_stuff":
			dialog.text = DLG_TEXT[54];
			link.l1 = DLG_TEXT[55];
			link.l1.go = "exit";
		break;

		case "imperial_escort_ships_impounded":
			if(sti(PChar.quest.imperial_escort.original_fleet_size) == 1) dialog.text = DLG_TEXT[56] + DLG_TEXT[58];
			else dialog.text = DLG_TEXT[57] + DLG_TEXT[58];
			link.l1 = DLG_TEXT[59];
			link.l1.go = "exit";
		break;

		case "imperial_escort_explanation":
			dialog.text = DLG_TEXT[60];
			link.l1 = DLG_TEXT[61];
			link.l1.go = "imperial_escort_explanation2";
		break;

		case "imperial_escort_explanation2":
			dialog.text = GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[62] + GetMyFullName(CharacterFromID("Javier Balboa")) + DLG_TEXT[63] + GetMyFullName(CharacterFromID("Imperial_envoy")) + DLG_TEXT[64] + GetMyLastName(PChar) + "!";
			link.l1 = DLG_TEXT[65] + GetMyName(NPChar) + DLG_TEXT[66];
			link.l1.go = "exit";
		break;

		case "imperial_escort_remind_stuff":
			dialog.text = DLG_TEXT[67];
			if(!CheckAttribute(PChar, "quest.imperial_escort_get_stuff"))	// The "get_stuff" quest is not active because you already retrieved your stuff
			{
				link.l1 = DLG_TEXT[68];
				link.l1.go = "imperial_escort_no_port";
			}
			else								// The "get_stuff" quest is still active because you didn't go to the unconscious commandant
			{
				link.l1 = DLG_TEXT[69];					// Go back and get stuff
				link.l1.go = "exit";
				link.l2 = DLG_TEXT[70];					// Don't bother with stuff
				link.l2.go = "imperial_escort_no_port";
			}
		break;

		case "imperial_escort_no_port":
			dialog.text = DLG_TEXT[71];
			link.l1 = DLG_TEXT[72];
			AddDialogExitQuest("imperial_escort_ships_impounded");
			link.l1.go = "exit";
		break;
	}
}