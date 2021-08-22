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

			if(CheckAttribute(CharacterFromID("Isabelle de Cussy"), "quest.my_name")) NPChar.quest.my_name = Characters[GetCharacterIndex("Isabelle de Cussy")].quest.my_name;
			else NPChar.quest.my_name = GetMyFullName(PChar);

			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "imperial_escort_transport_to_muelle":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3] + NPChar.quest.my_name + ".";
			link.l1.go = "imperial_escort_transport_to_muelle2";
		break;

		case "imperial_escort_transport_to_muelle2":
			dialog.text = DLG_TEXT[4] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[5];
			link.l1 = DLG_TEXT[6] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + "?";
			link.l1.go = "imperial_escort_transport_to_muelle3";
		break;

		case "imperial_escort_transport_to_muelle3":
			dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];
			link.l1.go = "imperial_escort_transport_to_muelle4";
		break;

		case "imperial_escort_transport_to_muelle4":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "imperial_escort_transport_to_muelle5";
		break;

		case "imperial_escort_transport_to_muelle5":
			dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "exit";
		break;

		case "imperial_escort_spy_ashore":
			dialog.text = DLG_TEXT[13] + GetMySimpleName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "imperial_escort_spy_ashore2";
		break;

		case "imperial_escort_spy_ashore2":
			Preprocessor_Add("pronoun2", GetMyPronounObj(CharacterFromID(GetTownGovernorID("Port au Prince"))));
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17] + "'" + GetMyName(CharacterFromID("Uasco Mazinho")) + "'.";
			link.l1.go = "exit";
		break;

		case "imperial_escort_fake_uasco":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			dialog.text = RandPhrase(TimeGreeting() + DLG_TEXT[18] + GetAddressForm(ADDR_CIVIL, SPAIN, chrsex(PChar)) + DLG_TEXT[19], DLG_TEXT[20] + GetAddressForm(ADDR_CIVIL, SPAIN, chrsex(PChar)) + DLG_TEXT[21], DLG_TEXT[22] + GetAddressForm(ADDR_CIVIL, SPAIN, chrsex(PChar)) + DLG_TEXT[23], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			link.l1 = DLG_TEXT[24];
			link.l1.go = "imperial_escort_cargo_job_accepted";
		break;

		case "imperial_escort_cargo_job_accepted":
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, -50);
			dialog.text = DLG_TEXT[25] + GetAddressForm(ADDR_CIVIL, SPAIN, chrsex(PChar)) + DLG_TEXT[26];
			link.l1 = DLG_TEXT[27];
			AddDialogExitQuest("imperial_escort_spy_follows_to_ship");
			link.l1.go = "exit";
		break;

		case "imperial_escort_deck_disguised":
			dialog.text = DLG_TEXT[28] + GetMyFullName(CharacterFromID("Isabelle de Cussy")) + DLG_TEXT[29];
			link.l1 = DLG_TEXT[30] + GetMyFullName(CharacterFromID("Jusepe Guimaraes")) + DLG_TEXT[31] + GetMyFullName(PChar) + DLG_TEXT[32];
			link.l1.go = "imperial_escort_deck_fight1";
		break;

		case "imperial_escort_deck_fight1":
			dialog.text = DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
		break;

		case "imperial_escort_deck":
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "imperial_escort_just_a_docker";
		break;

		case "imperial_escort_just_a_docker":
			NPChar.name = TranslateString("", "Gilles");
			NPChar.lastname = TranslateString("", "Clouzot");
			dialog.text = DLG_TEXT[37] + GetAddressForm(ADDR_CIVIL, SPAIN, chrsex(PChar)) + DLG_TEXT[38] + GetMyFullName(CharacterFromID("Uasco Mazinho")) + DLG_TEXT[39];
			link.l1 = DLG_TEXT[40] + GetMyFullName(NPChar) + DLG_TEXT[41];
			link.l1.go = "imperial_escort_deck_fight2";
		break;

		case "imperial_escort_deck_fight2":
			dialog.text = DLG_TEXT[42] + DLG_TEXT[33];
			link.l1 = DLG_TEXT[34];
			link.l1.go = "exit";
		break;

		case "imperial_escort_spy_rumbled":
			PlayStereoSound("INTERFACE\drink.wav");
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "exit";
		break;
	}
}