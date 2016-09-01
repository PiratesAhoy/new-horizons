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
				d.Text = RandPhrase(DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + GetMyFullName(NPChar) + DLG_TEXT[2], DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4] + GetMyFullName(NPChar) + DLG_TEXT[5], DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7] + GetMyFullName(NPChar) + DLG_TEXT[8], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[9] + GetMyFullName(PChar) + DLG_TEXT[10] + GetMyShipNameShow(PChar) + DLG_TEXT[11], DLG_TEXT[12] + GetMyFullName(PChar) + DLG_TEXT[13], DLG_TEXT[14] + Pchar.lastname + DLG_TEXT[15]);
				Link.l1.go = "Meeting";

				if(CheckQuestAttribute("Nigel_lost", "1"))
				{ 
					Link.l1 = DLG_TEXT[16] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[17])]) + DLG_TEXT[19];
					Link.l1.go = "Meeting1";
				}
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[20] + GetMyShipNameShow(PChar) + DLG_TEXT[21], DLG_TEXT[22] + Pchar.lastname + DLG_TEXT[23], DLG_TEXT[24] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + Pchar.lastname + DLG_TEXT[25], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
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

				if(CheckQuestAttribute("Nigel_lost", "1"))
				{ 
					Link.l5 = DLG_TEXT[38] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[39])]) + DLG_TEXT[41];
					Link.l5.go = "Meeting1";
				}

				Link.l3 = DLG_TEXT[42];
				Link.l3.go = "exit";
			}
	    	break;

		case "Meeting1":
			d.Text = DLG_TEXT[43];
			Link.l1 = DLG_TEXT[44];
			Link.l1.go = "exit";
		break;

		case "Meeting":
			    if(NPChar.sex == "man")
			    {
			    	dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				   d.Text = RandPhrase(DLG_TEXT[45] + Pchar.lastname + DLG_TEXT[46], DLG_TEXT[47] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[48], DLG_TEXT[49] + GetMyName(Pchar) + DLG_TEXT[50], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				}
				else
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				   d.Text = RandPhrase(DLG_TEXT[51] + GetMyName(Pchar) + DLG_TEXT[52], DLG_TEXT[53] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[54], DLG_TEXT[55] + Pchar.lastname + DLG_TEXT[56], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				}
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[57], DLG_TEXT[58], DLG_TEXT[59]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[60], DLG_TEXT[61], DLG_TEXT[62]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[63], DLG_TEXT[64], DLG_TEXT[65]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[66], DLG_TEXT[67], DLG_TEXT[68]);
					Link.l2.go = "colony";
				}


				Link.l3 = DLG_TEXT[69];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
				Link.l1 = DLG_TEXT[70];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[71];
				Link.l2.go = "exit";
		break;

		case "new question":
			    if(NPChar.sex == "man")
			    {
			    	dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				    d.Text = RandPhrase(DLG_TEXT[72] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[73], DLG_TEXT[74] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[75], DLG_TEXT[76], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3); 
				}
				else
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				    d.Text = RandPhrase(DLG_TEXT[77] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[78], DLG_TEXT[79] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[80], DLG_TEXT[81], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				}
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[82], DLG_TEXT[83], DLG_TEXT[84]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[85], DLG_TEXT[86], DLG_TEXT[87]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[88], DLG_TEXT[89], DLG_TEXT[90]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[91], DLG_TEXT[92], DLG_TEXT[93]);
					Link.l2.go = "colony";
				}


				Link.l3 = DLG_TEXT[94];
				Link.l3.go = "exit";
		break;

		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[95] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[96], DLG_TEXT[97], DLG_TEXT[98], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1) == 0)
				{	
					Link.l1 = DLG_TEXT[99];
					Link.l1.go = "governor";
				}
				else
				{
					Link.l1 = DLG_TEXT[100] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[101])]) + DLG_TEXT[103];
					Link.l1.go = "tavernkeeper";
				}
				if(Rand(1) == 0)	
				{
					Link.l2 = DLG_TEXT[104] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[105])]) + DLG_TEXT[107];
					Link.l2.go = "shipwright";
				}
				else 
				{
					Link.l2 = DLG_TEXT[108] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[109])]) + DLG_TEXT[111];
					Link.l2.go = "localtrader";
				}
				Link.l3 = DLG_TEXT[112];
				Link.l3.go = "new question";
		break;

		case "governor":
				d.Text = DLG_TEXT[113];
				Link.l1 = DLG_TEXT[114];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[115];
				Link.l2.go = "exit";
		break;

		case "tavernkeeper":
				d.Text = DLG_TEXT[116];
				Link.l1 = DLG_TEXT[117];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[118];
				Link.l2.go = "exit";
		break;

		case "shipwright":
				d.Text = DLG_TEXT[119];
				Link.l1 = DLG_TEXT[120];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[121];
				Link.l2.go = "exit";
		break;

		case "localtrader":
				d.Text = DLG_TEXT[122];
				Link.l1 = DLG_TEXT[123];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[124];
				Link.l2.go = "exit";
		break;

		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[125] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[126], DLG_TEXT[127], DLG_TEXT[128] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[129], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);

			Link.l1 = DLG_TEXT[130];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[131];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[132];
			Link.l3.go = "town_store";
		break;

		case "town_tavern":
			d.Text = DLG_TEXT[133];
			Link.l1 = DLG_TEXT[134];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[135];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[136];
			Link.l3.go = "town_store";
			DeleteAttribute(&locations[Findlocation("Oxbay_town")], "reload.l11.goto_disable"); // SS: Unlock Fast Travel
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[137]
			Link.l1 = DLG_TEXT[138];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[139];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[140];
			Link.l3.go = "exit";
			DeleteAttribute(&locations[Findlocation("Oxbay_town")], "reload.l13.goto_disable"); // SS: Unlock Fast Travel
		break;

		case "town_store":
			d.Text = DLG_TEXT[141] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[142];
			Link.l1 = DLG_TEXT[143];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[144];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[145];
			Link.l3.go = "exit";
			DeleteAttribute(&locations[Findlocation("Oxbay_town")], "reload.l10.goto_disable"); // SS: Unlock Fast Travel
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[146], DLG_TEXT[147], DLG_TEXT[148], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[149];
				Link.l1.go = "Oxbay";
			}
			else
			{
				Link.l1 = DLG_TEXT[150];
				Link.l1.go = "island";
			}
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[151];
				Link.l1.go = "fort";
			}
	/*		else
			{
				Link.l1 = "С кем торгуют местные торговцы?";
				Link.l1.go = "trade";
			}*/

			Link.l2 = DLG_TEXT[152];
			Link.l2.go = "new question";
		break;

		case "Oxbay":
			d.Text = DLG_TEXT[174] + DLG_TEXT[172] + GetTownSize("Oxbay") + DLG_TEXT[173]; // KK
			Link.l1 = DLG_TEXT[155];
			Link.l1.go = "new question";
		break;

		case "Oxbay_1":
			d.Text = DLG_TEXT[156];
			//Link.l1 = "Дальше...";
			//Link.l1.go = "Redmond_2";
			Link.l2 = DLG_TEXT[157];
			Link.l2.go = "new question";
		break;

		case "island":
			d.Text = DLG_TEXT[175]; // KK
			Link.l1 = DLG_TEXT[164];
			Link.l1.go = "new question";
		break;

		case "fort":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[165];
					Link.l1 = DLG_TEXT[166];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[167]
					Link.l1 = DLG_TEXT[168];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[169];
					Link.l1 = DLG_TEXT[170];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[171];
			Link.l2.go = "new question";
		break;
	} // end of switch; 
}
