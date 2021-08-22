//#include "DIALOGS\John Long_dialog.h"
// object	Dialog;	declared in dialog.c
// ref		NPChar; declared in dialog.c
//#include "Dialogs\blaze_dialog_defines.c"


void ProcessDialogEvent()
{
	int tmpLangFileID = LanguageOpenFile("interface_strings.txt");
	ref NPChar;
	aref Link, Diag;

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makearef(Diag, NPChar.Dialog);

	ref PChar;
	PChar = GetMainCharacter();
	ref lcn = &Locations[FindLocation(PChar.location)];
	
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
			Dialog.snd = "voice\PADI\PADI001";
			
			PlaySound("VOICE\ENGLISH\Eng_m_c_022.wav");
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
			
			Diag.TempNode = "first time";
		break;

		case "sorry":
			Dialog.text = DLG_TEXT[0];
			link.l1 = DLG_TEXT[1];
			link.l1.go = "exit";
		break;

		case "dialog_start":
			PlaySound("VOICE\ENGLISH\Eng_m_c_039.wav");
			Dialog.text = DLG_TEXT[7];
			link.l1 = DLG_TEXT[8];

			int freespace = GetCargoFreeSpace(Pchar);
			LogIt("freespace = " + freespace);

			if(freespace > 0)
			{
				
				link.l1.go = "goods";
			}
			else 
			{
				link.l1.go = "exit";
				AddDialogExitQuest("Long_short_delay");
			}
		break;

		case "goods":
			int cottongoods1 = GetSquadronGoods(Pchar, GOOD_COTTON);
			int chocolategoods1 = GetSquadronGoods(Pchar, GOOD_CHOCOLATE);
			int sugargoods1 = GetSquadronGoods(Pchar, GOOD_SUGAR);

			AddCharacterGoods(Pchar, GOOD_COTTON, 1);
			AddCharacterGoods(Pchar, GOOD_CHOCOLATE, 145);
			AddCharacterGoods(Pchar, GOOD_SUGAR, 250);

			int cottongoods2 = GetSquadronGoods(Pchar, GOOD_COTTON);
			int chocolategoods2 = GetSquadronGoods(Pchar, GOOD_CHOCOLATE);
			int sugargoods2 = GetSquadronGoods(Pchar, GOOD_SUGAR);
		
			if(cottongoods2 > cottongoods1) Pchar.quest.cotton = "yes";
			if(chocolategoods2 > chocolategoods1) Pchar.quest.chocolate = "yes";
			if(sugargoods2 > sugargoods1) Pchar.quest.sugar = "yes";

			PlaySound("VOICE\ENGLISH\Eng_m_c_021.wav");
			Dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "exit";
			AddDialogExitQuest("Long_goods2");
		break;

		case "amnesty":
			PlaySound("VOICE\ENGLISH\Eng_m_c_042.wav");
			Dialog.text = DLG_TEXT[17];
			link.l1 = DLG_TEXT[18];
			link.l1.go = "exit";
			AddDialogExitQuest("Long_amnesty1");
		break;

		case "open_galley":
			PlaySound("VOICE\ENGLISH\Eng_m_c_041.wav");
			Dialog.text = DLG_TEXT[19];
			link.l1 = DLG_TEXT[20];
			link.l1.go = "open_galley1";
		break;

		case "open_galley1":
			PlaySound("VOICE\ENGLISH\Eng_m_c_040.wav");
			Dialog.text = DLG_TEXT[21];
			link.l1 = DLG_TEXT[22];
			link.l1.go = "open_galley2";
		break;

		case "open_galley2":
			PlaySound("VOICE\ENGLISH\Eng_m_c_032.wav");
			Dialog.text = DLG_TEXT[23];
			link.l1 = DLG_TEXT[24];
			link.l1.go = "exit";
			AddDialogExitQuest("Long_to_quarterdeck");
		break;

		case "final_threat":
			PlaySound("VOICE\ENGLISH\Eng_m_c_039.wav");
			Dialog.text = DLG_TEXT[11];
			link.l1 = DLG_TEXT[12];
			link.l1.go = "final_threat1";
		break;

		case "final_threat1":
			PlaySound("VOICE\ENGLISH\Eng_m_c_056.wav");
			Dialog.text = DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "final_threat2";
		break;

		case "final_threat2":
			PlaySound("VOICE\ENGLISH\Eng_m_c_041.wav");
			Dialog.text = DLG_TEXT[15];
			link.l1 = DLG_TEXT[16];
			link.l1.go = "exit";
			AddDialogExitQuest("Long_final_threat2");
		break;

		case "Exit":
			DialogExit();
			Diag.CurrentNode = Diag.TempNode;
		break;
	}
}
