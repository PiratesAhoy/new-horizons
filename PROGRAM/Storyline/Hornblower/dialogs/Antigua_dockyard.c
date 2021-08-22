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
		case "First time":
			Dialog.defAni = "Gov_Dialog_1";
			Dialog.ani = "Gov_Dialog_2";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.cam = "1";

			if(NPChar.quest.meeting == "0")
			{
				dialog.snd = "Voice\DAFA\DAFA001";
				d.Text = TimeGreeting() + DLG_TEXT[0] + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2] + GetMySimpleName(PChar) + DLG_TEXT[3] + GetMyShipNameShow(PChar) + DLG_TEXT[4];
				Link.l1.go = "meeting";
				npchar.quest.Meeting = "1"; 
			}
			else
			{
				dialog.snd = "Voice\DAFA\DAFA002";
				d.Text = TimeGreeting() + DLG_TEXT[5] + GetMyName(PChar) + DLG_TEXT[6] + DLG_TEXT[7];
				Link.l1 = DLG_TEXT[8] + GetMyShipNameShow(PChar) + DLG_TEXT[9];
				Link.l1.go = "Shipyard";
				Link.l2 = DLG_TEXT[10];
				Link.l2.go = "exit";
			}
		break;

		case "Meeting":
			dialog.snd = "Voice\DAFA\DAFA003";
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12] + DLG_TEXT[13];
			Link.l1.go = "Shipyard";
			Link.l2 = DLG_TEXT[15];
			Link.l2.go = "exit";
		break;

		case "shipyard":
			dialog.snd = "Voice\DAFA\DAFA006";
			d.Text = DLG_TEXT[30] + " " + DLG_TEXT[16] + GetMyName(PChar) + DLG_TEXT[17];	// ccc 15oct04 shipyard waiting : changed by MAXIMUS
			Link.l1 = DLG_TEXT[24];
			Link.l1.go = "SHIPYARD_interface";
			Link.l2 = DLG_TEXT[25];
			Link.l2.go = "Cannons_interface";
			Link.l3 = DLG_TEXT[26];
			Link.l3.go = "Exit";
		break;

		// PB -->
		case "SHIPYARD_interface":
			GiveShip2Character(pchar,pchar.ship.type,pchar.ship.name,-1,ENGLAND,true,true);
			LogIt("The " + GetMyShipNameShow(PChar) + " was repaired and reprovisioned");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;

		case "CANNONS_interface":
			if(CheckQuestAttribute("Get_bigger_guns","Antigua_Dockyard"))
			{
				AddQuestRecord("My First Ship", 15);
				pchar.quest.Now_Join_The_Justinian.win_condition.l1 = "locator";
				pchar.quest.Now_Join_The_Justinian.win_condition.l1.location = "Antigua_port";
				pchar.quest.Now_Join_The_Justinian.win_condition.l1.locator_group = "reload";
				pchar.quest.Now_Join_The_Justinian.win_condition.l1.locator = "Sea_2_back";
				pchar.quest.Now_Join_The_Justinian.win_condition = "Now_Join_The_Justinian";
				DeleteAttribute(pchar,"quest.Get_bigger_guns");
			}
			GiveShip2Character(pchar,pchar.ship.type,pchar.ship.name,-1,ENGLAND,false,false);
			LogIt("The " + GetMyShipNameShow(PChar) + " was repaired and new guns were installed");
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
		// PB <--

		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			DialogExit();
		break;
	}
}
