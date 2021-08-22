//#include "DIALOGS\Cayman Citizen_dialog.h"
void ProcessDialogEvent()
{
	ref NPChar, PChar, d; 
	PChar = GetMainCharacter();
	aref Link, Diag;
	string NPC_Meeting, TempInfoCharacterID_1, TempInfoCharacterID_2;
	int DonationSize;
	
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
			Dialog.defAni = "dialog_stay1";
			Dialog.defCam = "1";
			Dialog.defSnd = "dialogs\0\017";
			Dialog.defLinkAni = "dialog_1";
			Dialog.defLinkCam = "1";
			Dialog.defLinkSnd = "dialogs\woman\024";
			Dialog.ani = "dialog_stay2";
			Dialog.cam = "1";
			Dialog.snd = "dialogs\0\009";

			if(NPChar.quest.meeting == "0")
			{
				NPC_Meeting = "1"; 
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + GetMyFullName(NPChar) + DLG_TEXT[2], DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4] + GetMyFullName(NPChar) + DLG_TEXT[5], DLG_TEXT[6] + GetMyFullName(NPChar) + DLG_TEXT[7] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[8], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[9] + GetMyFullName(PChar) + DLG_TEXT[10] + GetMyShipNameShow(PChar) + DLG_TEXT[11], DLG_TEXT[12] + GetMyFullName(PChar) + DLG_TEXT[13], DLG_TEXT[14] + GetMyName(Pchar) + DLG_TEXT[15]);
				Link.l1.go = "meeting";
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[16] + GetMyName(Pchar) + DLG_TEXT[17], DLG_TEXT[18] + TimeGreeting() + DLG_TEXT[19], DLG_TEXT[20] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[21], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[22], DLG_TEXT[23], DLG_TEXT[24]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[25], DLG_TEXT[26], DLG_TEXT[27]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[28], DLG_TEXT[29], DLG_TEXT[30]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[31], DLG_TEXT[32], DLG_TEXT[33]);
					Link.l2.go = "colony";
				}

				Link.l3 = DLG_TEXT[34];
				Link.l3.go = "exit";
			}
		break;

		case "Meeting":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[35], DLG_TEXT[36] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[37], DLG_TEXT[38], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[39], DLG_TEXT[40], DLG_TEXT[41]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[42], DLG_TEXT[43], DLG_TEXT[44]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[45], DLG_TEXT[46], DLG_TEXT[47]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[48], DLG_TEXT[49], DLG_TEXT[50]);
					Link.l2.go = "colony";
				}


				Link.l3 = DLG_TEXT[51];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
				Link.l1 = DLG_TEXT[52];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[53];
				Link.l2.go = "exit";
		break;

		case "new question":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[54] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[55], DLG_TEXT[56] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[57], DLG_TEXT[58] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[59], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[60], DLG_TEXT[61], DLG_TEXT[62]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[63], DLG_TEXT[64], DLG_TEXT[65]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[66], DLG_TEXT[67], DLG_TEXT[68]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[69], DLG_TEXT[70], DLG_TEXT[71]);
					Link.l2.go = "colony";
				}
				Link.l3 = DLG_TEXT[72];
				Link.l3.go = "exit";
		break;

		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[73] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[74], DLG_TEXT[75] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[76], DLG_TEXT[77] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[78], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{	
					Link.l1 = DLG_TEXT[79];
					Link.l1.go = "governor";
				}
				else
				{
					Link.l1 = DLG_TEXT[80];
					Link.l1.go = "tavernkeeper";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = DLG_TEXT[81];
					Link.l2.go = "shipwright";
				}
				else 
				{
					Link.l2 = DLG_TEXT[82];
					Link.l2.go = "localtrader";
				}
				Link.l3 = DLG_TEXT[145];
				Link.l3.go = "governor";
				Link.l4 = DLG_TEXT[83];
				Link.l4.go = "new question";
		break;

		case "governor":
				d.Text = DLG_TEXT[84];
				Link.l1 = DLG_TEXT[85];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[86];
				Link.l2.go = "exit";
		break;

		case "tavernkeeper":
				d.Text = DLG_TEXT[87];
				Link.l1 = DLG_TEXT[88];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[89];
				Link.l2.go = "exit";
		break;

		case "shipwright":
				d.Text = DLG_TEXT[90];
				Link.l1 = DLG_TEXT[91];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[92];
				Link.l2.go = "exit";
		break;

		case "localtrader":
				d.Text = DLG_TEXT[93];
				Link.l1 = DLG_TEXT[94];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[95];
				Link.l2.go = "exit";
		break;

		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[96], DLG_TEXT[97] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[98], DLG_TEXT[99] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[100], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[101];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[102];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[103];
			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			d.Text = DLG_TEXT[104];
			Link.l1 = DLG_TEXT[105];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[106];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[107];
			Link.l3.go = "town_store";
            DeleteAttribute(&locations[FindLocation("Grand_Cayman_town")], "reload.l3.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[108] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[109] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[110];
			Link.l1 = DLG_TEXT[111];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[112];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[113];
			Link.l3.go = "exit";
            DeleteAttribute(&locations[FindLocation("Grand_Cayman_town")], "reload.l4.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_store":
			d.Text = DLG_TEXT[114] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[115];
			Link.l1 = DLG_TEXT[116];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[117];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[118];
			Link.l3.go = "exit";
            DeleteAttribute(&locations[FindLocation("Grand_Cayman_town")], "reload.l7.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[119], DLG_TEXT[120], DLG_TEXT[121], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[122];
				Link.l1.go = "Redmond";
			}
			else
			{
				Link.l1 = DLG_TEXT[123];
				Link.l1.go = "island";
			}
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[124];
				Link.l1.go = "fort";
			}
	/*		else
			{
				Link.l1 = "С кем торгуют местные торговцы?";
				Link.l1.go = "trade";
			}*/

			Link.l2 = DLG_TEXT[125];
			Link.l2.go = "new question";
		break;

		case "Redmond":
// KK -->
			d.Text = DLG_TEXT[157];
			Link.l1 = DLG_TEXT[160];
			Link.l1.go = "PortRoyale_1";
// <-- KK
		break;

		case "Redmond_1":
			d.Text = DLG_TEXT[129];
			//Link.l1 = "Дальше...";
			//Link.l1.go = "Redmond_2";
			Link.l2 = DLG_TEXT[130];
			Link.l2.go = "new question";
		break;

// KK -->
		case "PortRoyale_1":
			d.Text = DLG_TEXT[158];
			Link.l1 = DLG_TEXT[160];
			Link.l1.go = "PortRoyale_2";
		break;

		case "PortRoyale_2":
			d.Text = DLG_TEXT[159] + DLG_TEXT[155] + GetTownSize("Redmond") + DLG_TEXT[156];
			Link.l1 = DLG_TEXT[128];
			Link.l1.go = "new question";
		break;
// <-- KK

		case "island":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[131];
					Link.l1 = DLG_TEXT[132];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[133];
					Link.l1 = DLG_TEXT[134];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[135];
					Link.l1 = DLG_TEXT[136];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[137];
			Link.l2.go = "new question";
		break;

		case "fort":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[138];
					Link.l1 = DLG_TEXT[139];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[140];
					Link.l1 = DLG_TEXT[141];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[142];
					Link.l1 = DLG_TEXT[143];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[144];
			Link.l2.go = "new question";
		break;
	}
}
