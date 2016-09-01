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

	Npchar.nation = Characters[getCharacterIndex("St John's Commander")].nation;

	int bribe = ( GetCharacterShipHP(Pchar) - sti(Pchar.ship.hp) ) * 10;
	
	switch(Dialog.CurrentNode)
	{
		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";
			// -->SJG
			if(CheckCharacterItem(Pchar,"EITC_Passport"))
			{
				d.Text = DLG_TEXT[25];
				Link.l1 = DLG_TEXT[26];
				Link.l1.go = "EITCman";
			}
			else
			{
				d.Text = DLG_TEXT[0];
				if(sti(PChar.money)>bribe )
				{
					Link.l0 = DLG_TEXT[1] + bribe + DLG_TEXT[2];
					Link.l0.go = "bribe";
				}
				Link.l1 = DLG_TEXT[3];
				if(GetRMRelation(Pchar, sti(NPChar.nation) ) < REL_NEUTRAL )
				{Link.l1.go = "lomfalse";}else{Link.l1.go = "lomtrue";}
				Link.l12 = DLG_TEXT[4];
				Link.l12.go = "deny";
				Link.l2 = DLG_TEXT[5];
				Link.l2.go = "duty";
				Link.l3 = Randswear() + DLG_TEXT[6];
				Link.l3.go = "exit";
			}
			// <--SJG
		break;

		case "duty":
			d.Text = DLG_TEXT[7];
			if(sti(PChar.money)>bribe )
			{
			Link.l0 = DLG_TEXT[1] + bribe + DLG_TEXT[2];
			Link.l0.go = "bribe";
			}
			Link.l1 = DLG_TEXT[3];
			if(GetRMRelation(Pchar, sti(NPChar.nation) ) < REL_NEUTRAL )
			{Link.l1.go = "lomfalse";}else{Link.l1.go = "lomtrue";}
			Link.l3 = Randswear() + DLG_TEXT[6];
			Link.l3.go = "exit";
		break;

		case "lomfalse":
			if(frnd() < 0.7 )
			{
				d.Text = DLG_TEXT[8];
				Link.l99 = Randswear() + DLG_TEXT[9];
				Link.l99.go = "fight";
			}
			else
			{
				d.Text = DLG_TEXT[10];
				link.l1 = DLG_TEXT[11];
				link.l1.go = "trade";
			}
		break;

		case "lomtrue":
		  bribe = bribe/2;
			AddMoneytoCharacter(Pchar, -bribe);
			d.Text = DLG_TEXT[12] + bribe + DLG_TEXT[13];
			link.l1 = DLG_TEXT[14];
			link.l1.go = "trade";
		break;
		// -->SJG
		case "EITCman":
			d.Text = DLG_TEXT[27];
			link.l1 = DLG_TEXT[28];
			link.l1.go = "trade";
		break;
		// <--SJG
		case "deny":
			d.Text = DLG_TEXT[15];
			Link.l1 = DLG_TEXT[16];
			Link.l1.go = "deny2";
			Link.l2 = DLG_TEXT[17];
			Link.l2.go = "exit";
		break;

		case "deny2":
			if(frnd() < 0.3 )
			{
				d.Text = Randswear() + DLG_TEXT[18];
				Link.l99 = Randswear() + DLG_TEXT[19];
				Link.l99.go = "fight";
			}
			else
			{
				d.Text = DLG_TEXT[20];
				link.l1 = DLG_TEXT[21];
				link.l1.go = "trade";
			}
		break;

		case "bribe":
			if(frnd() < 0.2 )
			{
				d.Text = DLG_TEXT[22];
				Link.l99 = Randswear() + DLG_TEXT[23];
				Link.l99.go = "fight";
			}
			else
			{
			AddMoneytoCharacter(Pchar, -bribe);
			d.Text = DLG_TEXT[24];
			link.l1 = DLG_TEXT[11];
			link.l1.go = "trade";
			}
		break;


// ----------- exits ------------------------
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "trade":
			//Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();

			Pchar.ship.sp = GetCharacterShipSP(Pchar);
			DeleteAttribute(Pchar,"ship.sails");
			DeleteAttribute(Pchar,"ship.masts");

			Pchar.ship.hp = GetCharacterShipHP(Pchar);
			DeleteAttribute(Pchar,"ship.blots");
		break;

		case "fight":
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_039.wav");
			LAi_group_SetRelation(NPchar.chr_ai.group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			Ambush("navy", 3, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
			//Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
