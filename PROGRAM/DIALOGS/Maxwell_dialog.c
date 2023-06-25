//#include "DIALOGS\Maxwell_dialog.h"

void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);
	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = "continue2";
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
			Dialog.snd = "voice\MAXW\MAXW001";

			Preprocessor_Add("sir", FirstLetterUp(GetAddressForm(ADDR_POLITE, ENGLAND, chrsex(PChar))));
			d.Text = DLG_TEXT[0];
			Link.l1 = DLG_TEXT[1];
			Link.l1.go = "continue"; 
		break;

		case "continue":
			Dialog.snd = "voice\MAXW\MAXW002";
			d.Text = DLG_TEXT[2];
			Link.l1 = DLG_TEXT[3]; 
			Link.l1.go = "continue1";
		break;

		case "continue1":
			Dialog.snd = "voice\MAXW\MAXW003";
			d.Text = DLG_TEXT[4];
			Link.l1 = DLG_TEXT[5];
			Link.l1.go = "continue2";
		break;
		
		case "continue2":
			dialog.text = DLG_TEXT[6];
			link.l1 = DLG_TEXT[7];
			link.l1.go = "continue3";
		break;
		
		case "continue3":
			AddQuestrecord("nigel", 25);
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[8];
			link.l1 = DLG_TEXT[9];
			link.l1.go = "exit";
//			characters[GetCharacterIndex("Lambrecht Fobes")].dialog.currentnode = "continue";
			pchar.quest.nigel_away_for_ship = "talk_with_clauss";
			npchar.location = "none";
		break;
	}
}
