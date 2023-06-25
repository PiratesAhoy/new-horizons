//#include "DIALOGS\Oxbay citizen_dialog.h"
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
				d.Text = RandPhrase(DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[2], DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[5], DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7] + NPChar.name + " " + NPChar.lastname + DLG_TEXT[8], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[9] + GetMyFullName(PChar) + DLG_TEXT[10] + GetMyShipNameShow(PChar) + DLG_TEXT[11], DLG_TEXT[12] + GetMyFullName(PChar) + DLG_TEXT[13], DLG_TEXT[14] + PChar.name + DLG_TEXT[15]);
				Link.l1.go = "Meeting";

/*				if(CheckQuestAttribute("Nigel_lost", "1"))	// Probably copied from "Oxbay_citizen_dialog.c", not needed because Nigel Blythe does not do anything at Charlestown
				{ 
					Link.l1 = DLG_TEXT[16] + Characters[GetCharacterIndex(DLG_TEXT[17])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[18])].lastname + DLG_TEXT[19];
					Link.l1.go = "Meeting1";
				} */
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				if (PChar.sex == "woman") Preprocessor_Add("yourself", XI_ConvertString("herself"));
				else Preprocessor_Add("yourself", XI_ConvertString("himself"));
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[20] + PChar.name + DLG_TEXT[21], DLG_TEXT[22] + Pchar.name + DLG_TEXT[23], DLG_TEXT[24] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + Pchar.lastname + DLG_TEXT[25], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[26], DLG_TEXT[27], DLG_TEXT[28]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[29], DLG_TEXT[30], DLG_TEXT[31]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[32], DLG_TEXT[33], DLG_TEXT[34]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[35], DLG_TEXT[36], DLG_TEXT[37]);
					Link.l2.go = "colony";
				}

/*				if(CheckQuestAttribute("Nigel_lost", "1"))	// Probably copied from "Oxbay_citizen_dialog.c", not needed because Nigel Blythe does not do anything at Charlestown
				{ 
					Link.l1 = DLG_TEXT[16] + Characters[GetCharacterIndex(DLG_TEXT[17])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[18])].lastname + DLG_TEXT[19];
					Link.l1.go = "Meeting1";
				} */

				Link.l3 = DLG_TEXT[38];
				Link.l3.go = "exit";
			}
	    	break;

/*		case "Meeting1":
			d.Text = DLG_TEXT[39];
			Link.l1 = DLG_TEXT[40];
			Link.l1.go = "exit";
		break; */

		case "Meeting":
			    if(NPChar.sex == "man")
			    {
			    	dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				   d.Text = RandPhrase(DLG_TEXT[41] + PChar.name + DLG_TEXT[42], DLG_TEXT[43] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[44], DLG_TEXT[45] + PChar.name + DLG_TEXT[46], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				}
				else
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				   d.Text = RandPhrase(DLG_TEXT[47] + PChar.name + DLG_TEXT[48], DLG_TEXT[49] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[50], DLG_TEXT[51] + PChar.name + DLG_TEXT[52], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				}
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[53], DLG_TEXT[54], DLG_TEXT[55]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[56], DLG_TEXT[57], DLG_TEXT[58]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[59], DLG_TEXT[60], DLG_TEXT[61]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[62], DLG_TEXT[63], DLG_TEXT[64]);
					Link.l2.go = "colony";
				}


				Link.l3 = DLG_TEXT[65];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
				Link.l1 = DLG_TEXT[66];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[67];
				Link.l2.go = "exit";
		break;

		case "new question":
			    if(NPChar.sex == "man")
			    {
			    	dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				    d.Text = RandPhrase(DLG_TEXT[68] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[69], DLG_TEXT[70] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[71], DLG_TEXT[72], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3); 
				}
				else
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				    d.Text = RandPhrase(DLG_TEXT[73] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[74], DLG_TEXT[75] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[76], DLG_TEXT[77], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				}
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[78], DLG_TEXT[79], DLG_TEXT[80]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[81], DLG_TEXT[82], DLG_TEXT[83]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[84], DLG_TEXT[85], DLG_TEXT[86]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[87], DLG_TEXT[88], DLG_TEXT[89]);
					Link.l2.go = "colony";
				}


				Link.l3 = DLG_TEXT[90];
				Link.l3.go = "exit";
		break;

		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[91] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[92], DLG_TEXT[93], DLG_TEXT[94], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1) == 0)
				{	
					Link.l1 = DLG_TEXT[95];
					Link.l1.go = "governor";
				}
				else
				{
					Link.l1 = DLG_TEXT[96] + Characters[GetCharacterIndex(DLG_TEXT[97])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[98])].lastname + DLG_TEXT[99];
					Link.l1.go = "tavernkeeper";
				}
				if(Rand(1) == 0)	
				{
					Link.l2 = DLG_TEXT[100] + Characters[GetCharacterIndex(DLG_TEXT[101])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[102])].lastname + DLG_TEXT[103];
					Link.l2.go = "shipwright";
				}
				else 
				{
					Link.l2 = DLG_TEXT[104] + Characters[GetCharacterIndex(DLG_TEXT[105])].name + " " + Characters[GetCharacterIndex(DLG_TEXT[106])].lastname + DLG_TEXT[107];
					Link.l2.go = "localtrader";
				}
				Link.l3 = DLG_TEXT[108];
				Link.l3.go = "new question";
		break;

		case "governor":
				d.Text = DLG_TEXT[109] + GetMyFullName(CharacterFromID(DLG_TEXT[110])) + DLG_TEXT[111];
				Link.l1 = DLG_TEXT[112];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[113];
				Link.l2.go = "exit";
		break;

		case "tavernkeeper":
				d.Text = DLG_TEXT[114];
				Link.l1 = DLG_TEXT[115];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[116];
				Link.l2.go = "exit";
		break;

		case "shipwright":
				d.Text = DLG_TEXT[117];
				Link.l1 = DLG_TEXT[118];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[119];
				Link.l2.go = "exit";
		break;

		case "localtrader":
				d.Text = DLG_TEXT[120];
				Link.l1 = DLG_TEXT[121];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[122];
				Link.l2.go = "exit";
		break;

		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[123] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + DLG_TEXT[124], DLG_TEXT[125], DLG_TEXT[126] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + DLG_TEXT[127], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);

			Link.l1 = DLG_TEXT[128];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[129];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[130];
			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			d.Text = DLG_TEXT[131];
			Link.l1 = DLG_TEXT[132];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[133];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[134];
			Link.l3.go = "town_store";
			DeleteAttribute(&locations[FindLocation("Charlestown_port")], "reload.l4.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[135]
			Link.l1 = DLG_TEXT[136];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[137];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[138];
			Link.l3.go = "exit";
			DeleteAttribute(&locations[FindLocation("Charlestown_port")], "reload.l5.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_store":
			d.Text = DLG_TEXT[139] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, true) + DLG_TEXT[140];
			Link.l1 = DLG_TEXT[141];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[142];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[143];
			Link.l3.go = "exit";
			DeleteAttribute(&locations[FindLocation("Charlestown_port")], "reload.l6.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[144], DLG_TEXT[145], DLG_TEXT[146], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[147];
				Link.l1.go = "Charlestown";
			}
			else
			{
				Link.l1 = DLG_TEXT[148];
				Link.l1.go = "island";
			}
	//		if(Rand(1)== 0)
	//		{
				Link.l2 = DLG_TEXT[149];
				Link.l2.go = "fort";
	//		}
	/*		else
			{
				Link.l2 = "С кем торгуют местные торговцы?";
				Link.l2.go = "trade";
			}*/

			Link.l3 = DLG_TEXT[150];
			Link.l3.go = "new question";
		break;

		case "Charlestown":
			d.Text = DLG_TEXT[151] + DLG_TEXT[170] + GetTownSize("Charlestown") + DLG_TEXT[171]; // NK
			Link.l1 = DLG_TEXT[152];
			Link.l1.go = "Charlestown_1";
			Link.l2 = DLG_TEXT[153];
			Link.l2.go = "new question";
		break;

		case "Charlestown_1":
			d.Text = DLG_TEXT[154];
			//Link.l1 = "Дальше...";
			//Link.l1.go = "Redmond_2";
			Link.l2 = DLG_TEXT[155];
			Link.l2.go = "new question";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[156];
					Link.l1 = DLG_TEXT[157];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[158];
					Link.l1 = DLG_TEXT[159];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[160];
					Link.l1 = DLG_TEXT[161];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[162];
			Link.l2.go = "new question";
		break;

		case "fort":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[163];
					Link.l1 = DLG_TEXT[164];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[165]
					Link.l1 = DLG_TEXT[166];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[167];
					Link.l1 = DLG_TEXT[168];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[169];
			Link.l2.go = "new question";
		break;

	} // end of switch; 

}