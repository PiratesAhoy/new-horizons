// #include "DIALOGS\Enc_Tradepost.h"
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

	int bribe = GetMaxCrewQuantity(pchar)*3;

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

			d.Text = DLG_TEXT[0];
			if(sti(PChar.money)>bribe )
			{
				Link.l0 = DLG_TEXT[1]+bribe+DLG_TEXT[2];
				Link.l0.go = "bribe";
			}
			Link.l1 = DLG_TEXT[3];
			if(GetRMRelation(Pchar, sti(NPChar.nation) ) < REL_NEUTRAL ) { Link.l1.go = "lomfalse"; }else{ Link.l1.go = "lomtrue"; }
			Link.l12 = DLG_TEXT[4];
			Link.l12.go = "deny";
			Link.l13 = DLG_TEXT[5];
			Link.l13.go = "admiral";
			Link.l2 = DLG_TEXT[6];
			Link.l2.go = "duty";
			Link.l3 = Randswear()+DLG_TEXT[7];
			Link.l3.go = "exit";
		break;

		case "duty":
			d.Text = DLG_TEXT[8];
			Link.l1.go = "duty2";
		break;

		case "duty2":
			d.Text = DLG_TEXT[31];
			if(sti(PChar.money)>bribe )
			{
				Link.l0 = DLG_TEXT[9]+bribe+DLG_TEXT[10];
				Link.l0.go = "bribe";
			}
			Link.l1 = DLG_TEXT[3];
			if(GetRMRelation(Pchar, sti(NPChar.nation) ) < REL_NEUTRAL ) { Link.l1.go = "lomfalse"; }else{ Link.l1.go = "lomtrue"; }
			Link.l3 = Randswear()+DLG_TEXT[7];
			Link.l3.go = "exit";
		break;

		case "lomfalse":
			if(frnd() < 0.7 )
			{
				d.Text = DLG_TEXT[11];
				Link.l99 = Randswear()+DLG_TEXT[12];
				Link.l99.go = "fight";
			}
			else
			{
				d.Text = DLG_TEXT[13];
				link.l1 = DLG_TEXT[14];
				link.l1.go = "trade";
				Link.l3 = DLG_TEXT[15];
				Link.l3.go = "exit";
			}
		break;

		case "lomtrue":
			d.Text = DLG_TEXT[16];
			link.l1 = DLG_TEXT[17];
			link.l1.go = "trade";
			Link.l3 = DLG_TEXT[15];
			Link.l3.go = "exit";
		break;

		case "admiral":
			d.Text = DLG_TEXT[18];
			Link.l3 = DLG_TEXT[19];
			Link.l3.go = "exit";
		break;

		case "deny":
			d.Text = DLG_TEXT[20];
			Link.l1 = DLG_TEXT[21];
			Link.l1.go = "deny2";
			Link.l2 = DLG_TEXT[22];
			Link.l2.go = "exit";
		break;

		case "deny2":
			if(frnd() < 0.3 )
			{
				d.Text = Randswear()+DLG_TEXT[23];
				Link.l99 = Randswear()+DLG_TEXT[24];
				Link.l99.go = "fight";
			}
			else
			{
				d.Text = DLG_TEXT[25];
				link.l1 = DLG_TEXT[26];
				link.l1.go = "trade";
			}
		break;

		case "bribe":
			if(frnd() < 0.2 )
			{
				d.Text = DLG_TEXT[27];
				Link.l99 = Randswear()+DLG_TEXT[28];
				Link.l99.go = "fight";
			}
			else
			{
				AddMoneytoCharacter(Pchar, -bribe);
				d.Text = DLG_TEXT[29];
				link.l1 = DLG_TEXT[30];
				link.l1.go = "trade";
				Link.l3 = DLG_TEXT[15];
				Link.l3.go = "exit";
			}
		break;


// ----------- exits ------------------------
		case "exit":
			//Diag.CurrentNode = Diag.TempNode;
			//NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "trade":
			//Diag.CurrentNode = Diag.TempNode;
			//NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
			pchar.ship.crew.morale=sti(pchar.ship.crew.morale)-20;  // reward: crew moral. Change figure to your liking
			if(sti(pchar.ship.crew.morale)<11) pchar.ship.crew.morale=11;
			SetCrewQuantity(&pchar, GetMaxCrewQuantity(&pchar));
		break;

		case "fight":
			PlaySound("VOICE\" + LanguageGetLanguage() + "\Eng_m_a_039.wav");
			LAi_group_SetRelation(NPchar.chr_ai.group, LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
			Ambush("navy", 3, LAI_GROUP_ENEMY, LAI_GROUP_NEUTRAL, "");
			//Diag.CurrentNode = Diag.TempNode;
			//NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
