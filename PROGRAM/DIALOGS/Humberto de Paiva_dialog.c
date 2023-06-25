//#include "DIALOGS\Humberto de Paiva_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting;
	
	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	string iDay, iMonth;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	
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
			

			if(TradeCheck(PChar, NPChar, true)) { // NK
				if(NPChar.quest.meeting == "0")
				{
					dialog.snd = "Voice\HUDP\HUDP001";
					d.Text = TimeGreeting() + DLG_TEXT[0] + GetMyFullName(NPChar) + DLG_TEXT[1];
					Link.l1 = DLG_TEXT[2] + GetMyFullName(PChar) + DLG_TEXT[3] + GetMyShipNameShow(PChar) + DLG_TEXT[4];
					Link.l1.go = "meeting";
					NPChar.quest.meeting = "1"; 
				}
				else
				{
					dialog.snd = "Voice\HUDP\HUDP002";
					d.Text = TimeGreeting() + DLG_TEXT[5] + GetMyName(Pchar) + DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7];
					Link.l1 = DLG_TEXT[8];
					Link.l1.go = "Shipyard";
					Link.l2 = DLG_TEXT[9];
					Link.l2.go = "quest lines";
					Link.l99 = DLG_TEXT[10];
					Link.l99.go = "exit";
				}
			// NK -->
			}
			else
			{
				dialog.text = DLG_TEXT[27] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[28];
				Link.l1 = DLG_TEXT[29];
				Link.l1.go = "exit";
				if(sti(PChar.Skill.Commerce)>=5)
				{
					Link.l2 = TranslateString("","high_trade_1");
					Link.l2.go = "high_price";
				}
				Diag.TempNode = "First time";
			}
			// NK <--
		break;

		case "high_price":
			dialog.text = TranslateString("","high_trade_2");
			link.l1 = TranslateString("","high_trade_3");
			link.l1.go = "shipyard_high";
			link.l2 = TranslateString("","high_trade_4");
			link.l2.go = "exit";
			Diag.TempNode = "First time";
		break;

		case "shipyard_high":
			dialog.Text = TranslateString("","high_trade_5");
			Link.l1 = TranslateString("","high_trade_6");
			Link.l1.go = "SHIPYARD_interface_high";
			Link.l3 = TranslateString("","high_trade_4");
			Link.l3.go = "Exit";
			Diag.TempNode = "First time";
		break;

		case "SHIPYARD_interface_high":
			Diag.TempNode = "First time";
			if(npchar.quest.Meeting != lastspeak_date)
			{
				FillShipsList(&NPChar); // NK

				npchar.quest.Meeting = lastspeak_date;
			}			
			DialogExit();
			tradeHigh = true;
			LaunchShipyard(npchar);
		break;

		case "Meeting":
			dialog.snd = "Voice\HUDP\HUDP003";
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12] + GetMyName(NPChar) +DLG_TEXT[13];				
			Link.l1.go = "Shipyard";		
			Link.l2 = DLG_TEXT[14];
			Link.l2.go = "quest lines";
			Link.l3 = DLG_TEXT[15];
			Link.l3.go = "exit";
		break;

		case "quest lines":
			dialog.snd = "Voice\HUDP\HUDP004";
			d.Text = DLG_TEXT[16] + GetMyName(Pchar) + DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "no quest";
		break;

		case "No quest":
			dialog.snd = "Voice\HUDP\HUDP005";
			d.Text = DLG_TEXT[19] + GetMyName(Pchar) + DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "Shipyard";
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
		break;

		case "shipyard":
			dialog.snd = "Voice\HUDP\HUDP006";
			d.Text = DLG_TEXT[30] + DLG_TEXT[23];	// ccc 15oct04 shipyard waiting : changed by MAXIMUS
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "SHIPYARD_interface";
			Link.l3 = DLG_TEXT[26];							//changed by KAM
			Link.l3.go = "exit";							//changed by KAM
		break;

		case "SHIPYARD_interface":
			Diag.CurrentNode = Diag.TempNode;
			
			if (npchar.quest.Meeting != lastspeak_date)
			{
				FillShipsList(&NPChar); // NK

				npchar.quest.Meeting = lastspeak_date;
			}

			DialogExit();
			LaunchShipyard(npchar);
		break;

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		
	}
}