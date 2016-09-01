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

	ref PChar;
	PChar = GetMainCharacter();

	
	switch(Dialog.CurrentNode)
	{
		// -----------------------------------|иалог первый - первая встреча
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
			}
			// NK <--
			NextDiag.TempNode = "Second time";
		break;

		case "quest":
			dialog.text = DLG_TEXT[9];
			link.l1 = DLG_TEXT[10];
			link.l1.go = "Second time";
			link.l2 = DLG_TEXT[11];
			link.l2.go = "exit";
		break;

		case "shipyard":
			dialog.Text = DLG_TEXT[19] + DLG_TEXT[12];	// ccc 15oct04 shipyard waiting : changed by MAXIMUS
			Link.l9 = DLG_TEXT[20];	// ccc
			Link.l9.go = "exit";	//ccc
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
