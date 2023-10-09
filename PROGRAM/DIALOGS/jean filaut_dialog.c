//#include "DIALOGS\jean filaut_dialog.h"
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

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;

	int cash;

	ref PChar;
	PChar = GetMainCharacter();

	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(TradeCheck(PChar, NPChar, true)) { // NK
				Dialog.Text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3];
				Link.l1.go = "Second Time";
				NextDiag.TempNode = "Second time";
			// NK -->
			}
			else
			{
				dialog.text = DLG_TEXT[16] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[17];
				Link.l1 = DLG_TEXT[18];
				Link.l1.go = "exit";
				NextDiag.TempNode = "First time";
			}
			// NK <--
		break;

		case "Second time":
			if(TradeCheck(PChar, NPChar, true)) { // NK
				dialog.text = DLG_TEXT[4] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[5];
				link.l1 = DLG_TEXT[6];
				link.l1.go = "shipyard";
				link.l2 = DLG_TEXT[7];
				link.l2.go = "quest";
				link.l99 = DLG_TEXT[8];
				link.l99.go = "exit";
			// NK -->
			}
			else
			{
				dialog.text = DLG_TEXT[16] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[17];
				Link.l1 = DLG_TEXT[18];
				Link.l1.go = "exit";
				if(sti(PChar.Skill.Commerce)>=5)
				{
					Link.l2 = TranslateString("","high_trade_1");
					Link.l2.go = "high_price";
				}
				NextDiag.TempNode = "First time";
			}
			// NK <--
		break;

		case "high_price":
			dialog.text = TranslateString("","high_trade_2");
			link.l1 = TranslateString("","high_trade_3");
			link.l1.go = "shipyard_high";
			link.l2 = TranslateString("","high_trade_4");
			link.l2.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "shipyard_high":
			dialog.Text = TranslateString("","high_trade_5");
			Link.l1 = TranslateString("","high_trade_6");
			Link.l1.go = "SHIPYARD_interface_high";
			Link.l3 = TranslateString("","high_trade_4");
			Link.l3.go = "Exit";
			NextDiag.TempNode = "First time";
		break;

		case "SHIPYARD_interface_high":
			NextDiag.TempNode = "First time";
			if(npchar.quest.Meeting != lastspeak_date)
			{
				FillShipsList(&NPChar); // NK

				npchar.quest.Meeting = lastspeak_date;
			}			
			DialogExit();
			tradeHigh = true;
			LaunchShipyard(npchar);
		break;

		case "quest":
			if (isofficer(characterFromID("Rys Bloom")))
			{
				dialog.text = DLG_TEXT[23] + GetMySimpleName(characterFromID("Rys Bloom")) + DLG_TEXT[24];
				link.l1 = DLG_TEXT[25];
				link.l1.go = "quest2";
				link.l2 = DLG_TEXT[26];
				link.l2.go = "exit";
			}
			else
			{
				dialog.text = DLG_TEXT[9];
				link.l1 = DLG_TEXT[10];
				link.l1.go = "Second time";
				link.l2 = DLG_TEXT[11];
				link.l2.go = "exit";
			}
		break;

		case "quest2":
			dialog.text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			AddDialogExitQuest("martinique_shipyard_work");
			link.l1.go = "exit";
		break;

		case "job_done":
			cash = 1500;
			PreProcessor_Add("cash", cash);
			dialog.text = DLG_TEXT[29];
			link.l1 = DLG_TEXT[30];
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(pchar, cash);
			link.l1.go = "exit";
		break;

		case "shipyard":
			dialog.Text = DLG_TEXT[19] + DLG_TEXT[12];	// ccc 15oct04 shipyard waiting : changed by MAXIMUS
			Link.l1 = DLG_TEXT[13];
			Link.l1.go = "SHIPYARD_interface";
			Link.l3 = DLG_TEXT[15];							//changed by KAM
			Link.l3.go = "Exit";							//changed by KAM
		break;

		case "SHIPYARD_interface":
			NextDiag.CurrentNode = NextDiag.TempNode;

			if (npchar.quest.Meeting != lastspeak_date)
			{
				FillShipsList(&NPChar); // NK

				npchar.quest.Meeting = lastspeak_date;
			}
			
			DialogExit();
			LaunchShipyard(npchar);
		break;

		case "Exit":
			DialogExit();
			NextDiag.CurrentNode = NextDiag.TempNode;
		break;
	}
}
