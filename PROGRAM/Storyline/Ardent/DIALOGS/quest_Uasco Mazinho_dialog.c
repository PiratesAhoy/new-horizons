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

			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + ".";
			link.l1 = DLG_TEXT[1];
			link.l1.go = "Exit";
		break;

		case "imperial_escort_load_my_cargo1":
			dialog.text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[2];
			link.l1 = DLG_TEXT[3];
			link.l1.go = "imperial_escort_load_my_cargo2";
		break;

		case "imperial_escort_load_my_cargo2":
			dialog.text = DLG_TEXT[4];
			link.l1 = DLG_TEXT[5];
			link.l1.go = "imperial_escort_load_my_cargo3";
		break;

		case "imperial_escort_load_my_cargo3":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "imperial_escort_load_my_cargo4";
		break;

		case "imperial_escort_load_my_cargo4":
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "imperial_escort_load_my_cargo5";
		break;

		case "imperial_escort_load_my_cargo5":
			dialog.text = DLG_TEXT[10];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "imperial_escort_load_my_cargo6";
		break;

		case "imperial_escort_load_my_cargo6":
			PlayStereoSound("INTERFACE\took_item.flac");
			AddMoneyToCharacter(PChar, -1 * (20 + rand(80)));
			dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			AddDialogExitQuest("imperial_escort_uasco_to_ship");
			link.l1.go = "exit";
		break;

		case "imperial_escort_where_is_cargo":
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "imperial_escort_how_do_i_unload";
		break;

		case "imperial_escort_how_do_i_unload":
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "imperial_escort_return_money";
		break;

		case "imperial_escort_return_money":
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			AddDialogExitQuest("imperial_escort_uasco_prisoner");
			link.l1.go = "exit";
		break;

		case "imperial_escort_prisoner":
			dialog.text = DLG_TEXT[20];
			link.l1 = PCharRepPhrase(DLG_TEXT[21], DLG_TEXT[22]);
			link.l1.go = "exit";
			Diag.TempNode = "imperial_escort_prisoner";
		break;

		case "imperial_escort_release":
			dialog.text = DLG_TEXT[20];
			link.l1 = PCharRepPhrase(DLG_TEXT[23], DLG_TEXT[24]);
			if (CheckQuestAttribute("imperial_escort.spy_search", "bring_uasco_ashore")) AddDialogExitQuest("imperial_escort_uasco_follow_ashore");
			link.l1.go = "exit";
			Diag.TempNode = "First time";
		break;
	}
}