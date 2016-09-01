//#include "DIALOGS\esteban castillo_dialog.h"
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

	ref PChar = GetMainCharacter();
	
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

			if(TradeCheck(PChar, NPChar, true)) { // NK	// LDH added true 03Jan09
				if (npchar.quest.meeting == "0")
				{
					dialog.snd = "Voice\ESCA\ESCA001";
					Dialog.Text = DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
					Link.l1 = pcharrepphrase(DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3], DLG_TEXT[4] + GetMyFullName(PChar) + DLG_TEXT[5]);
					Link.l1.go = "node_1";
					npchar.quest.meeting = "1";
				}
				else
				{
					dialog.snd = "Voice\ESCA\ESCA002";
					dialog.text = DLG_TEXT[6];
					link.l1 = pcharrepphrase(DLG_TEXT[7], DLG_TEXT[8]);
					link.l1.go = "node_3";
					link.l99 = pcharrepphrase(DLG_TEXT[9], DLG_TEXT[10]);
					link.l99.go = "exit";
				}
			// NK -->
			}
			else
			{
				dialog.text = DLG_TEXT[29] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[30];
				Link.l1 = DLG_TEXT[31];
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

		case "node_1":
			dialog.snd = "Voice\ESCA\ESCA003";
			dialog.text = DLG_TEXT[11];
			link.l1 = pcharrepphrase(DLG_TEXT[12], DLG_TEXT[13]);
			link.l1.go = "node_2";
		break;

		case "node_2":
			dialog.snd = "Voice\ESCA\ESCA004";
			dialog.text = DLG_TEXT[14];
			link.l1 = pcharrepphrase(DLG_TEXT[15], DLG_TEXT[16]);
			link.l1.go = "node_3";
			link.l2 = pcharrepphrase(DLG_TEXT[17], DLG_TEXT[18]);
			link.l2.go = "exit";
		break;

		case "node_3":
			dialog.snd = "Voice\ESCA\ESCA005";
			dialog.text = DLG_TEXT[19] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[20];
			link.l1 = pcharrepphrase(DLG_TEXT[21], DLG_TEXT[22]);
			link.l1.go = "shipyard";
			link.l2 = pcharrepphrase(DLG_TEXT[23], DLG_TEXT[24]);
			link.l2.go = "exit";
			NextDiag.TempNode = "First time";
		break;

		case "shipyard":
			Dialog.snd = "voice\OWMC\OWMC006";
			dialog.Text = DLG_TEXT[32];	// ccc 15oct04 shipyard waiting
			Link.l1 = DLG_TEXT[26];
			Link.l1.go = "SHIPYARD_interface";
			Link.l3 = DLG_TEXT[28];							//changed by KAM
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
