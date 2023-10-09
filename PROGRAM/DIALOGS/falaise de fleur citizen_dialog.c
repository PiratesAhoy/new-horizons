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
		// ----------------------------------- Диалог первый - первая встреча
		
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
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1], DLG_TEXT[2] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[3], DLG_TEXT[4] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[5], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				d.defAni = "dialog_stay1";
				d.defCam = "1";
				d.defSnd = "dialogs\woman\004";

				d.defLinkAni = "dialog_1";
				d.defLinkCam = "1";
				d.defLinkSnd = "dialogs\0\047";

				d.ani = "dialog_stay2";
				d.cam = "1";
				d.snd = "dialogs\woman\006";
				Link.l1 = LinkRandPhrase(DLG_TEXT[6] + GetMyFullName(PChar) + DLG_TEXT[7] + GetMyShipNameShow(PChar) + DLG_TEXT[8], DLG_TEXT[9] + GetMyFullName(PChar) + DLG_TEXT[10], DLG_TEXT[11] + GetMyName(Pchar) + DLG_TEXT[12]);
				Link.l1.go = "meeting";
			}
			else
			{
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[13] + GetMyName(Pchar) + DLG_TEXT[14], DLG_TEXT[15] + GetMyName(Pchar) + DLG_TEXT[16] + TimeGreeting() + DLG_TEXT[17], DLG_TEXT[18] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[19], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[20], DLG_TEXT[21]), pcharrepphrase(DLG_TEXT[22], DLG_TEXT[23]), pcharrepphrase(DLG_TEXT[24], DLG_TEXT[25]));
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[26], DLG_TEXT[27]), pcharrepphrase(DLG_TEXT[28], DLG_TEXT[29]), pcharrepphrase(DLG_TEXT[30], DLG_TEXT[31]));
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[32], DLG_TEXT[33]), pcharrepphrase(DLG_TEXT[34], DLG_TEXT[35]), pcharrepphrase(DLG_TEXT[36], DLG_TEXT[37]));
					Link.l2.go = "info";
				}
				{
					Link.l2 = LinkRandPhrase(pcharrepphrase(DLG_TEXT[38], DLG_TEXT[39]), pcharrepphrase(DLG_TEXT[40], DLG_TEXT[41]), pcharrepphrase(DLG_TEXT[42], DLG_TEXT[43]));
					Link.l2.go = "colony";
				}
			}
			Link.l3 = pcharrepphrase(DLG_TEXT[44], DLG_TEXT[45]);
			Link.l3.go = "exit";
			Diag.TempNode = "First Time";
		break;

		case "Meeting":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[46] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[47], DLG_TEXT[48], DLG_TEXT[49], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[50], DLG_TEXT[51], DLG_TEXT[52]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[53], DLG_TEXT[54], DLG_TEXT[55]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[56], DLG_TEXT[57], DLG_TEXT[58]);
					Link.l2.go = "info";
				}
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[59], DLG_TEXT[60], DLG_TEXT[61]);
					Link.l2.go = "colony";
				}
				Link.l3 = DLG_TEXT[62];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
				Link.l1 = DLG_TEXT[63];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[64];
				Link.l2.go = "exit";
		break;

		case "new question":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[65] + GetMyName(Pchar) + DLG_TEXT[66], DLG_TEXT[67] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[68], DLG_TEXT[69] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[70], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[71], DLG_TEXT[72], DLG_TEXT[73]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[74], DLG_TEXT[75], DLG_TEXT[76]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[77], DLG_TEXT[78], DLG_TEXT[79]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[80], DLG_TEXT[81], DLG_TEXT[82]);
					Link.l2.go = "colony";
				}
				Link.l3 = DLG_TEXT[83];
				Link.l3.go = "exit";
		break;

		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[84] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[85], DLG_TEXT[86], DLG_TEXT[87], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				if(Rand(1)==0)
				{	
					Link.l1 = DLG_TEXT[88];
					Link.l1.go = "governor";
				}
				else
				{
					Link.l1 = DLG_TEXT[89];
					Link.l1.go = "tavernkeeper";
				}
				if(Rand(1)==0)  //  Cat FBQ
				
				{
					if(characters[GetCharacterIndex("Fred Bob")].quest.help == "agreed")
					{
					Link.l2 = DLG_TEXT[147];
					Link.l2.go = "fredbob";
					}
				}
				else
				{
					Link.l2 = DLG_TEXT[148];
					Link.l2.go = "harbormaster";
				}  //  Cat FBQ
				if(Rand(1)==0)	
				{
					Link.l3 = DLG_TEXT[90];
					Link.l3.go = "shipwright";
				}
				else 
				{
					Link.l3 = DLG_TEXT[91];
					Link.l3.go = "localtrader";
				}
				if(Rand(1)==0)	
				{
					Link.l4 = DLG_TEXT[157];
					Link.l4.go = "info";
				}
				else 
				{
					// RobC/Alan_Smithee Blacksmiths -->
					if (ENABLE_WEAPONSMOD)
					{
						Link.l4 = DLG_TEXT[158];
						Link.l4.go = "smithy";
					}
					// RobC/Alan_Smithee Blacksmiths <--
				}
				Link.l5 = DLG_TEXT[92];
				Link.l5.go = "new question";
		break;

		case "smithy":
				d.Text = DLG_TEXT[159];
				Link.l1 = DLG_TEXT[160];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[161];
				Link.l2.go = "exit";
		break;
//<-- RobC/A_S 'smiths

		case "governor":
				d.Text = DLG_TEXT[93];
				Link.l1 = DLG_TEXT[94];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[95];
				Link.l2.go = "exit";
		break;

		case "fredbob":   //  Cat FBQ
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[149], DLG_TEXT[155], DLG_TEXT[156], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
				Link.l1 = DLG_TEXT[150];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[151];
				Link.l2.go = "exit";
		break;
		
		case "harbormaster":
				d.Text = DLG_TEXT[152];
				Link.l1 = DLG_TEXT[153];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[154];
				Link.l2.go = "exit";
		break;  //  Cat FBQ

		case "tavernkeeper":				
				d.Text = DLG_TEXT[96];
				Link.l1 = DLG_TEXT[97];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[98];
				Link.l2.go = "exit";
		break;

		case "shipwright":				
				d.Text = DLG_TEXT[99];
				Link.l1 = DLG_TEXT[100];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[101];
				Link.l2.go = "exit";
		break;

		case "localtrader":				
				d.Text = DLG_TEXT[102];
				Link.l1 = DLG_TEXT[103];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[104];
				Link.l2.go = "exit";
		break;

		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[105] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[106], DLG_TEXT[107], DLG_TEXT[108] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[109], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			Link.l1 = DLG_TEXT[110];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[111];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[112];
			Link.l3.go = "town_store";
			// RobC/Alan_Smithee Blacksmiths -->
			if (ENABLE_WEAPONSMOD)
			{
				Link.l4 = DLG_TEXT[162];
				Link.l4.go = "town_smithy";
			}
			// RobC/Alan_Smithee Blacksmiths <--
		break;

		case "town_smithy":
			d.Text = DLG_TEXT[163];
			Link.l1 = DLG_TEXT[164];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[165];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[166];
			Link.l3.go = "town_store";
            DeleteAttribute(&locations[FindLocation("Falaise_de_fleur_location_03")], "reload.l11.goto_disable"); // BOP: Unlock Fast Travel
		break;
//<-- RobC/A_S Smiths

		case "town_tavern":
			d.Text = DLG_TEXT[113];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[115];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[116];
			Link.l3.go = "town_store";
			if (ENABLE_WEAPONSMOD)
			{
				Link.l4 = DLG_TEXT[167];
				Link.l4.go = "town_smithy";
			}
            DeleteAttribute(&locations[FindLocation("Falaise_de_fleur_location_03")], "reload.l4.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[117];
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[119];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[120];
			Link.l3.go = "exit";
            DeleteAttribute(&locations[FindLocation("Falaise_de_fleur_location_03")], "reload.l5.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_store":
			d.Text = DLG_TEXT[121];
			Link.l1 = DLG_TEXT[122];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[123];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[124];
			Link.l3.go = "exit";
            DeleteAttribute(&locations[FindLocation("Falaise_de_fleur_location_04")], "reload.l3.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[125], DLG_TEXT[126] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[127], DLG_TEXT[128] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[129], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = pcharrepphrase(DLG_TEXT[130], DLG_TEXT[131]);
				Link.l1.go = "Fleur";
			}
			else
			{
				Link.l1 = DLG_TEXT[132];
				Link.l1.go = "island";
			}
			Link.l2 = DLG_TEXT[133];
			Link.l2.go = "new question";
		break;

		case "Fleur":
			d.Text = DLG_TEXT[134] + DLG_TEXT[168] + GetTownSize("Falaise de Fleur") + DLG_TEXT[169]; // NK
			Link.l1 = pcharrepphrase(DLG_TEXT[135], DLG_TEXT[136]);
			Link.l1.go = "new question";
			link.l2 = pcharrepphrase(DLG_TEXT[137], DLG_TEXT[138]);
			link.l2.go = "exit";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[139];
					Link.l1 = pcharrepphrase(DLG_TEXT[140], DLG_TEXT[141]);
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[142];
					Link.l1 = DLG_TEXT[143];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[144];
					Link.l1 = DLG_TEXT[145];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[146];
			Link.l2.go = "new question";
		break;
		
		case "exit":
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
