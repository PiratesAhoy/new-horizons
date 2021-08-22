//#include "DIALOGS\elzire ayarai_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"

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
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			
			dialog.snd = "Voice\ELAY\ELAY001";
			Dialog.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "exit";
			if (characters[GetCharacterIndex("pater Jourdain")].quest.prihod == "0")
			{
				dialog.snd = "Voice\ELAY\ELAY002";
				Dialog.Text = DLG_TEXT[3];
				Link.l1 = DLG_TEXT[4];
				Link.l1.go = "exit";
			}
			if (characters[GetCharacterIndex("pater Jourdain")].quest.prihod == "1")
			{
				dialog.snd = "Voice\ELAY\ELAY003";
				Dialog.text = DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "node_1";
			}
			if (characters[GetCharacterIndex("pater Jourdain")].quest.prihod == "2")
			{
				dialog.snd = "Voice\ELAY\ELAY004";
				Dialog.Text = DLG_TEXT[7] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[8];
				Link.l1 = DLG_TEXT[9];
				Link.l1.go = "exit";
			}
			if (characters[GetCharacterIndex("pater Jourdain")].quest.prihod == "3")
			{
				dialog.snd = "Voice\ELAY\ELAY005";
				Dialog.Text = DLG_TEXT[10];
				Link.l1 = DLG_TEXT[11];
				Link.l1.go = "exit";
			}
			NextDiag.TempNode = "First time";
		break;

		case "node_1":
			dialog.snd = "Voice\ELAY\ELAY006";
			Dialog.text = DLG_TEXT[12];
			link.l1 = DLG_TEXT[13];
			link.l1.go = "node_2";
		break;

		case "node_2":
			dialog.snd = "Voice\ELAY\ELAY007";
			dialog.text = DLG_TEXT[14];
			link.l1 = DLG_TEXT[15];
			link.l1.go = "node_3";
		break;

		case "node_3":
			dialog.snd = "Voice\ELAY\ELAY008";
			dialog.text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "node_4";
		break;

		case "node_4":
			dialog.snd = "Voice\ELAY\ELAY009";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[18];
			link.l1 = DLG_TEXT[19];
			link.l1.go ="node_5";
		break;

		case "node_5":
			dialog.snd = "Voice\ELAY\ELAY010";
			dialog.text = DLG_TEXT[20];
			link.l1 = DLG_TEXT[21];
			link.l1.go = "exit";

			link.l2 = DLG_TEXT[22];
			link.l2.go = "node_6";
			characters[GetCharacterIndex("pater Jourdain")].quest.prihod = "3";
		break;

		case "node_6":
			dialog.snd = "Voice\ELAY\ELAY011";
			dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "node_7";
		break;

		case "node_7":
			dialog.snd = "Voice\ELAY\ELAY012";
			dialog.text = DLG_TEXT[25];
			link.l1 = DLG_TEXT[26];
			link.l1.go = "exit";
			link.l2 = DLG_TEXT[27];
			link.l2.go = "node_8";
		break;

		case "node_8":
			dialog.snd = "Voice\ELAY\ELAY013";
			dialog.text = DLG_TEXT[28];
			link.l1 = DLG_TEXT[29];
			link.l1.go = "exit";
			if (makeint(pchar.money) >= 1000)
			{
				link.l2 = DLG_TEXT[30];
				link.l2.go = "node_9";
			}
			else
			{
				link.l2 = DLG_TEXT[31];
				link.l2.go = "exit";
				characters[GetCharacterIndex("pater Jourdain")].quest.prihod = "1";
			}
		break;

		case "node_9":
			dialog.snd = "Voice\ELAY\ELAY014";
			Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
			dialog.text = DLG_TEXT[32];
			link.l1 = DLG_TEXT[33];
			link.l1.go = "node_10";
			link.l2 = DLG_TEXT[34];
			link.l2.go = "exit";
		break;

		case "node_10":
			dialog.snd = "Voice\ELAY\ELAY015";
			dialog.text = DLG_TEXT[35];
			link.l1 = DLG_TEXT[36];
			link.l1.go = "exit";
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, -1000);
			characters[GetCharacterIndex("pater Jourdain")].quest.prihod = "2";
		break;
		
		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
