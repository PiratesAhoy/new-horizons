//#include "DIALOGS\RelationAgent_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d;
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, PeaceGroup;
	int Nation, Sum;
	// RM -->
	int iNation;
	string sNation;
	// RM <--

	DeleteAttribute(&Dialog,"Links");

	makeref(NPChar,CharacterRef);
	makearef(Link, Dialog.Links);
	makeref(d, Dialog);
	makearef(Diag, NPChar.Dialog);

	switch(Dialog.CurrentNode)
	{
		// -----------------------------------Диалог первый - первая встреча
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "First time":
			Dialog.defAni = "dialog_stay2";
			Dialog.defCam = "2";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";

			if(Pchar.quest.RelationAgentMet == "0")
			{
				Dialog.snd = "voice\REDI\REDI001";
				d.Text = DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1];
				Link.l1 = DLG_TEXT[2];
				Link.l1.go = "Tutorial";
				NPC_Meeting = "1";
				Pchar.quest.RelationAgentMet = "1"; // NK
			}
			else
			{
				if(NPChar.quest.meeting == "0")
				{
					Dialog.snd = "voice\REDI\REDI002";
					d.Text = DLG_TEXT[3];
					Link.l1 = DLG_TEXT[4] + GetMyFullName(Pchar) + DLG_TEXT[5];
					Link.l1.go = "Service";
					Link.l2 = DLG_TEXT[6];
					Link.l2.go = "Exit";
				}
				else
				{
					Dialog.snd = "voice\REDI\REDI003";
					d.Text = DLG_TEXT[7]; // NK
					Link.l1 = DLG_TEXT[8];
					Link.l1.go = "Service";
					Link.l2 = DLG_TEXT[9];
					Link.l2.go = "exit";

				}
			}

		break;

		case "Service":
			Dialog.snd = "voice\REDI\REDI004";
			if(ProfessionalNavyNation() != UNKNOWN_NATION) // PB: For Commissioned Naval Officers
			{
				d.Text = "But... You are a commissioned navy officer. I don't trust the likes of you!";
				Link.l1 = "Well, the feeling is mutual. You scoundrel and scallywag! I'd better get out of here while I can.";
				Link.l1.go = "exit";
			}
			else
			{
				d.Text = DLG_TEXT[10];
				if(GetRMRelation(PChar, ENGLAND) < REL_AMNESTY) // RM
				{
					Link.l1 = DLG_TEXT[11];
					Link.l1.go = "England"; // NK bugfix 04-09-17 was England

				}
				if(GetRMRelation(PChar, SPAIN) < REL_AMNESTY) // RM
				{
					Link.l2 = DLG_TEXT[12];
					Link.l2.go = "Spain";
				}
				if(GetRMRelation(PChar, PORTUGAL) < REL_AMNESTY) // RM
				{
					Link.l3 = DLG_TEXT[13];
					Link.l3.go = "Portugal";
				}
				if(GetRMRelation(PChar, HOLLAND) < REL_AMNESTY) // RM
				{
					Link.l4 = DLG_TEXT[14];
					Link.l4.go = "Holland";
				}
				if(GetRMRelation(PChar, FRANCE) < REL_AMNESTY) // RM
				{
					Link.l5 = DLG_TEXT[15];
					Link.l5.go = "France";
				}
				if (CheckGuestNation(GUEST1_NATION, AMERICA))
				{
					if(GetRMRelation(PChar, AMERICA) < REL_AMNESTY) // RM
					{
						Link.l5 = DLG_TEXT[15];
						Link.l5.go = "America";
					}
				}
				Link.l6 = DLG_TEXT[16];
				Link.l6.go = "exit";
			}
		break;

		case "Tutorial":
			Dialog.snd = "voice\REDI\REDI005";
			d.Text = DLG_TEXT[17];
			Link.l99 = DLG_TEXT[18];
			Link.l99.go = "Tutorial_1";
		break;

		case "Tutorial_1":
			Dialog.snd = "voice\REDI\REDI006";
			d.Text = DLG_TEXT[19];
			Link.l99 = DLG_TEXT[20];
			Link.l99.go = "Tutorial_2";
		break;

		case "Tutorial_2":
			Dialog.snd = "voice\REDI\REDI007";
			d.Text = DLG_TEXT[21];
			Link.l99 = DLG_TEXT[22];
			Link.l99.go = "Tutorial_3";
		break;

		case "Tutorial_3":
			Dialog.snd = "voice\REDI\REDI008";
			d.Text = DLG_TEXT[23];
			Link.l99 = DLG_TEXT[24];
			Link.l99.go = "Tutorial_4";
		break;

		case "Tutorial_4":
			Dialog.snd = "voice\REDI\REDI009";
			d.Text = DLG_TEXT[25];
			Link.l99 = DLG_TEXT[26];
			Link.l99.go = "Service";
		break;

		case "England": // NK bugfix 04-09-17 was England
			iNation = GetNationTypeByID(Dialog.CurrentNode);
			sNation = iNation;
			Pchar.quest.Relations.nation = iNation;
			Pchar.quest.Relations.sum = RMAmnestyCost(PChar, iNation) * 1.5;
			Dialog.snd = "voice\REDI\REDI010";
			d.Text = DLG_TEXT[27] + ShowMoney(-sti(Pchar.quest.Relations.sum)) + DLG_TEXT[28];
			Link.l1 = DLG_TEXT[29];
			if(GetCharacterMoney(PChar) < 0-makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";
			}
			else
			{
				Link.l1.go = "Agreed";
			}
			Link.l2 = DLG_TEXT[30];
			Link.l2.go = "exit";
		break;

		case "Spain":
			iNation = GetNationTypeByID(Dialog.CurrentNode);
			sNation = iNation;
			Pchar.quest.Relations.nation = iNation;
			Pchar.quest.Relations.sum = RMAmnestyCost(PChar, iNation) * 1.5;
			Dialog.snd = "voice\REDI\REDI011";
			d.Text = DLG_TEXT[31] + ShowMoney(-sti(Pchar.quest.Relations.sum)) + DLG_TEXT[32];
			Link.l1 = DLG_TEXT[33];
			if(GetCharacterMoney(PChar) < 0-makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";
			}
			else
			{
				Link.l1.go = "Agreed";
			}
			Link.l2 = DLG_TEXT[34];
			Link.l2.go = "exit";
		break;

		case "France":
			iNation = GetNationTypeByID(Dialog.CurrentNode);
			sNation = iNation;
			Pchar.quest.Relations.nation = iNation;
			Pchar.quest.Relations.sum = RMAmnestyCost(PChar, iNation) * 1.5;
			Dialog.snd = "voice\REDI\REDI012";
			d.Text = DLG_TEXT[35] + ShowMoney(-sti(Pchar.quest.Relations.sum)) + DLG_TEXT[36];
			Link.l1 = DLG_TEXT[37];
			if(GetCharacterMoney(PChar) < 0-makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";
			}
			else
			{
				Link.l1.go = "Agreed";
			}
			Link.l2 = DLG_TEXT[38];
			Link.l2.go = "exit";
		break;

		case "Portugal":
			iNation = GetNationTypeByID(Dialog.CurrentNode);
			sNation = iNation;
			Pchar.quest.Relations.nation = iNation;
			Pchar.quest.Relations.sum = RMAmnestyCost(PChar, iNation) * 1.5;
			Dialog.snd = "voice\REDI\REDI013";
			d.Text = DLG_TEXT[39] + ShowMoney(-sti(Pchar.quest.Relations.sum)) + DLG_TEXT[40];
			Link.l1 = DLG_TEXT[41];
			if(GetCharacterMoney(PChar) < 0-makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";
			}
			else
			{
				Link.l1.go = "Agreed";
			}
			Link.l2 = DLG_TEXT[42];
			Link.l2.go = "exit";
		break;

		case "Holland":
			iNation = GetNationTypeByID(Dialog.CurrentNode);
			sNation = iNation;
			Pchar.quest.Relations.nation = iNation;
			Pchar.quest.Relations.sum = RMAmnestyCost(PChar, iNation) * 1.5;
			Dialog.snd = "voice\REDI\REDI014";
			d.Text = DLG_TEXT[43] + ShowMoney(-sti(Pchar.quest.Relations.sum)) + DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			if(GetCharacterMoney(PChar) < 0-makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";
			}
			else
			{
				Link.l1.go = "Agreed";
			}
			Link.l2 = DLG_TEXT[46];
			Link.l2.go = "exit";
		break;

		case "America":
			iNation = GetNationTypeByID(Dialog.CurrentNode);
			sNation = iNation;
			Pchar.quest.Relations.nation = iNation;
			Pchar.quest.Relations.sum = RMAmnestyCost(PChar, iNation) * 1.5;
			Dialog.snd = "voice\REDI\REDI014";
			d.Text = DLG_TEXT[43] + ShowMoney(-sti(Pchar.quest.Relations.sum)) + DLG_TEXT[44];
			Link.l1 = DLG_TEXT[45];
			if(GetCharacterMoney(PChar) < 0-makeint(Pchar.quest.Relations.sum))
			{
				Link.l1.go = "No_money";
			}
			else
			{
				Link.l1.go = "Agreed";
			}
			Link.l2 = DLG_TEXT[46];
			Link.l2.go = "exit";
		break;

		case "No_Money":
			Dialog.snd = "voice\REDI\REDI015";
			d.Text = DLG_TEXT[47];
			Link.l1 = DLG_TEXT[48];
			Link.l1.go = "exit";
		break;

		case "Agreed":
			Dialog.snd = "voice\REDI\REDI016";
			RMAmnesty(PChar, sti(Pchar.quest.relations.nation));
			PlayStereoSound("INTERFACE\took_item.wav");
			AddMoneyToCharacter(PChar, makeint(Pchar.quest.Relations.sum)); // RM
			DeleteAttribute(Pchar, "quest.Relations");
			d.Text = DLG_TEXT[49];
			Link.l1 = DLG_TEXT[50];
			Link.l1.go = "Exit";
			Link.l2 = DLG_TEXT[51];
			Link.l2.go = "Service";
		break;


	}
}