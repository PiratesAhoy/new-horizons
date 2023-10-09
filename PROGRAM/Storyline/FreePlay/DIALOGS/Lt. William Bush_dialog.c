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

		case "A rum lot":
			dialog.text = DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "Odd allies";
		break;

		case "Odd allies":
			dialog.text = DLG_TEXT[4];
			link.l1 = GetMyFullName(CharacterFromID("El Supremo")) + DLG_TEXT[5];
			link.l1.go = "Arms for him";
		break;

		case "Arms for him":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7] + GetAttribute(CharacterFromID("El Supremo"), "title") + " " + GetMyName(CharacterFromID("El Supremo")) + DLG_TEXT[8];
			link.l1.go = "exit";
		break;

		case "If not back":
			dialog.text = "";
			link.l1 = DLG_TEXT[9];
			link.l1.go = "On our side";
		break;

		case "On our side":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "exit";
		break;

		case "Provisions and cargo":
			dialog.text = "";
			link.l1 = DLG_TEXT[12];
			link.l1.go = "Send lookout for Natividad";
		break;

		case "Send lookout for Natividad":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "Send lookout for Natividad2";
		break;

		case "Send lookout for Natividad2":
			dialog.text = DLG_TEXT[13];
			link.l1 = "";
			AddDialogExitQuest("Hornblower_exchange_weapons_for_supplies");
			link.l1.go = "exit";
		break;

		case "Natividad sighted":
			dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "Natividad sighted2";
		break;

		case "Natividad sighted2":
			dialog.text = DLG_TEXT[17];
			link.l1 = "";
			link.l1.go = "Natividad sighted3";
		break;

		case "Natividad sighted3":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go = "Natividad sighted4";
		break;

		case "Natividad sighted4":
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "Natividad sighted5";
		break;

		case "Natividad sighted5":
			dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "Natividad sighted6";
		break;

		case "Natividad sighted6":
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "Aye-aye_sir";
		break;

		case "Natividad gamble":
			dialog.text = "";
			link.l1 = DLG_TEXT[25];
			link.l1.go = "Natividad gamble2";
		break;

		case "Natividad gamble2":
			dialog.text = "";
			link.l1 = DLG_TEXT[26];
			AddDialogExitQuest("Hornblower_Natividad_plan");
			link.l1.go = "exit";
		break;

		case "put_them_in_irons":
			dialog.text = "";
			link.l1 = DLG_TEXT[27] + PChar.ship.name + DLG_TEXT[28];
			link.l1.go = "exit";
		break;

		case "shes_a_beauty":
			dialog.text = DLG_TEXT[29] + PChar.quest.oldship.name + DLG_TEXT[30];
			link.l1 = DLG_TEXT[31];
			link.l1.go = "wot_no_prize";
		break;

		case "wot_no_prize":
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "your_share_worth_loads";
		break;

		case "your_share_worth_loads":
			dialog.text = DLG_TEXT[34];
			link.l1 = DLG_TEXT[35];
			link.l1.go = "you_said_hes_mad";
		break;

		case "you_said_hes_mad":
			dialog.text = DLG_TEXT[36];
			link.l1 = DLG_TEXT[37];
			AddDialogExitQuest("Hornblower_Natividad_handover");
			link.l1.go = "exit";
		break;

		case "El_Supremo_boarding":
			dialog.text = DLG_TEXT[38];
			link.l1 = DLG_TEXT[39];
			link.l1.go = "fire_salute";
		break;

		case "fire_salute":
			dialog.text = DLG_TEXT[40];
			link.l1.go = "";
			AddDialogExitQuest("Hornblower_11_gun_salute");
			link.l1.go = "exit";
		break;

		case "return_to_ship":
			dialog.text = "";
			link.l1 = DLG_TEXT[41] +"'" + PChar.quest.oldship.name + "'";
			link.l1.go = "exit";
		break;

		case "lugger_report":
			dialog.text = "";
			link.l1 = DLG_TEXT[42];
			link.l1.go = "lugger_report2";
		break;

		case "lugger_report2":
			dialog.text = DLG_TEXT[43];
			link.l1 = DLG_TEXT[44];
			link.l1.go = "Aye-aye_sir";
		break;

		case "Bring the prisoners":
			dialog.text = "";
			link.l1 = DLG_TEXT[45];
			link.l1.go = "exit_fetch_prisoners";
		break;

		case "exit_fetch_prisoners":
			dialog.text = DLG_TEXT[13];
			link.l1 = "";
			AddDialogExitQuest("Hornblower_Bush_to_get_prisoners2");
			link.l1.go = "exit";
		break;

		case "still_ship_of_war":
			dialog.text = "";
			link.l1 = DLG_TEXT[46];
			link.l1.go = "exit";
		break;

		case "Aye-aye_sir":
			dialog.text = DLG_TEXT[13];
			link.l1 = "";
			link.l1.go = "exit";
		break;

		case "Signal_from_the_flagship":
			dialog.text = DLG_TEXT[47];
			link.l1 = DLG_TEXT[48];
			link.l1.go = "Signal_from_the_flagship2";
		break;

		case "Signal_from_the_flagship2":
			dialog.text = DLG_TEXT[49];
			link.l1 = "";
			link.l1.go = "exit";
		break;
	}
}