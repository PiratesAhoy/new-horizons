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
	
	string iDay, iMonth, cargoid, questbookname;
	iDay = environment.date.day;
	iMonth = environment.date.month;
	string lastspeak_date = iday + " " + iMonth;
	if(!CheckAttribute(NPChar, "last_hire"))
	{
		NPChar.last_hire = "";
	}
	ref ctown = GetCurrentTown();
	
	switch(Dialog.CurrentNode)
	{
		//Levis add waiting times in tavern:
		case "room":
			link.l9 = DLG_TEXT[16];
			link.l9.go = "Wait_Time";
		break;
		
		case "Wait_Time":
			Dialog.Text = DLG_TEXT[17];
			Link.l1 = DLG_TEXT[18];
			Link.l1.go = "Wait1hour";
			Link.l2 = DLG_TEXT[19];
			Link.l2.go = "Wait3hours";
			Link.l3 = DLG_TEXT[20];
			Link.l3.go = "Wait8hours";
			Link.l4 = DLG_TEXT[21];
			Link.l4.go = "exit";
		break;
		
		case "Wait1hour":
			DialogExit();
			LAi_Fade("", "");
			WaitDate("", 0,0,0,1,0);
		break;
		
		case "Wait3hours":
			DialogExit();
			LAi_Fade("", "");
			WaitDate("", 0,0,0,3,0);
		break;
		
		case "Wait8hours":
			DialogExit();
			LAi_Fade("", "");
			WaitDate("", 0,0,0,8,0);
		break;
		
	    case "gather_information":
    		Diag.CurrentNode = Diag.TempNode;
			DialogExit();
			LaunchNews();
		break;

		case "Hire_Officer":
			d.Text = DLG_TEXT[1];
			Link.l1 = DLG_TEXT[2];
			Link.l1.go = "Find_Boatswain";
			Link.l2 = DLG_TEXT[3];
			Link.l2.go = "Find_Cannoneer";
			Link.l3 = DLG_TEXT[4];
			Link.l3.go = "Find_Quartermaster";
			Link.l4 = DLG_TEXT[5];
			Link.l4.go = "Find_Navigator";
			Link.l5 = DLG_TEXT[6];
			Link.l5.go = "Find_FirstMate";
			Link.l6 = DLG_TEXT[7];
			Link.l6.go = "Find_Carpenter";
			Link.l7 = DLG_TEXT[8];
			Link.l7.go = "Find_Doctor";
			Link.l8 = DLG_TEXT[9];
			Link.l8.go = "Find_DeckFighter";
			Link.l9 = DLG_TEXT[10];
			Link.l9.go = "exit";
		break;

		case "Find_Boatswain":
			NPChar.last_hire = lastspeak_date;
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			CreateOfficerType(OFFIC_TYPE_BOATSWAIN, sti(PChar.skill.Leadership));
		break;

		case "Find_Cannoneer":
			NPChar.last_hire = lastspeak_date;
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			CreateOfficerType(OFFIC_TYPE_CANNONEER, sti(PChar.skill.Leadership));
		break;

		case "Find_Quartermaster":
			NPChar.last_hire = lastspeak_date;
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			CreateOfficerType(OFFIC_TYPE_QMASTER, sti(PChar.skill.Leadership));
		break;

		case "Find_Navigator":
			NPChar.last_hire = lastspeak_date;
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			CreateOfficerType(OFFIC_TYPE_NAVIGATOR, sti(PChar.skill.Leadership));
		break;

		case "Find_FirstMate":
			NPChar.last_hire = lastspeak_date;
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			CreateOfficerType(OFFIC_TYPE_FIRSTMATE, sti(PChar.skill.Leadership));
		break;

		case "Find_Carpenter":
			NPChar.last_hire = lastspeak_date;
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			CreateOfficerType(OFFIC_TYPE_CARPENTER, sti(PChar.skill.Leadership));
		break;

		case "Find_Doctor":
			NPChar.last_hire = lastspeak_date;
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			CreateOfficerType(OFFIC_TYPE_DOCTOR, sti(PChar.skill.Leadership));
		break;

		case "Find_DeckFighter":
			NPChar.last_hire = lastspeak_date;
			d.Text = DLG_TEXT[11];
			Link.l1 = DLG_TEXT[12];
			Link.l1.go = "exit";
			CreateOfficerType(OFFIC_TYPE_ABORDAGE, sti(PChar.skill.Leadership));
		break;
	}

	//Taken from switch so it works in both instances
	if (Dialog.CurrentNode == "Second time" || Dialog.CurrentNode == "First Time")
	{
		if (GetAttribute(npchar, "quest.meeting") == "1")
		{
			if(NPChar.last_hire != lastspeak_date)
			{
				Link.l1 = DLG_TEXT[0];
				Link.l1.go = "Hire_Officer";
			}
			link.l2 = LinkRandPhrase(DLG_TEXT[13], DLG_TEXT[14], DLG_TEXT[15]);
      		link.l2.go = "gather_information";
		}else{
			npchar.quest.meeting = "1";
		}
	}
}