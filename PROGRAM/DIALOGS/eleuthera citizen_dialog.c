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
				d.Text = RandPhrase(TimeGreeting() + DLG_TEXT[0] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[1] + GetMyFullName(NPChar) + DLG_TEXT[2], DLG_TEXT[3] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[4] + GetMyFullName(NPChar) + DLG_TEXT[5], DLG_TEXT[6] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[7] + GetMyFullName(NPChar) + DLG_TEXT[8], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				Link.l1 = LinkRandPhrase(DLG_TEXT[9] + GetMyFullName(PChar) + DLG_TEXT[10] + GetMyShipNameShow(PChar) + DLG_TEXT[11], DLG_TEXT[12] + GetMyFullName(PChar) + DLG_TEXT[13], DLG_TEXT[14] + GetMyName(Pchar) + DLG_TEXT[15]);
				Link.l1.go = "Meeting";
			}
			else
			{
				if(NPChar.sex == "man")
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
				     d.Text = RandPhrase(DLG_TEXT[16] + GetMyName(Pchar) + DLG_TEXT[17], DLG_TEXT[18] + GetMyFullName(PChar) + DLG_TEXT[19], DLG_TEXT[20] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[21], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				    }
				else
				{
					dialog.snd1 = "";
					dialog.snd2 = "";
					dialog.snd3 = "";
                     d.Text = RandPhrase(DLG_TEXT[22] + GetMyName(Pchar) + DLG_TEXT[23], DLG_TEXT[24] + GetMyFullName(PChar) + DLG_TEXT[25], DLG_TEXT[26] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[27], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
                    }

				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[28], DLG_TEXT[29], DLG_TEXT[30]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[31], DLG_TEXT[32], DLG_TEXT[33]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[34], DLG_TEXT[35], DLG_TEXT[36]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[37], DLG_TEXT[38], DLG_TEXT[39]);
					Link.l2.go = "colony";
				}

				Link.l3 = DLG_TEXT[40];
				Link.l3.go = "exit";
			}
	    	break;

		case "Meeting":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[41], DLG_TEXT[42] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + GetMyName(PChar) + DLG_TEXT[43], DLG_TEXT[44], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[45], DLG_TEXT[46], DLG_TEXT[47]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[48], DLG_TEXT[49], DLG_TEXT[50]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[51], DLG_TEXT[52], DLG_TEXT[53]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[54], DLG_TEXT[55], DLG_TEXT[56]);
					Link.l2.go = "colony";
				}


				Link.l3 = DLG_TEXT[57];
				Link.l3.go = "exit";
		break;

		case "rumours":
				d.Text = SelectRumour(FindIslandByLocation(LoadedLocation.id), GetNationIDByType(GetCurrentLocationNation()) );
				Link.l1 = DLG_TEXT[58];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[59];
				Link.l2.go = "exit";
		break;

		case "new question":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[60] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[61], DLG_TEXT[62] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[63], DLG_TEXT[64] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[65], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				if(Rand(1)==0)
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[66], DLG_TEXT[67], DLG_TEXT[68]);
					Link.l1.go = "rumours";
				}
				else
				{
					Link.l1 = LinkRandPhrase(DLG_TEXT[69], DLG_TEXT[70], DLG_TEXT[71]);
					Link.l1.go = "town";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[72], DLG_TEXT[73], DLG_TEXT[74]);
					Link.l2.go = "info";
				}
				else
				{
					Link.l2 = LinkRandPhrase(DLG_TEXT[75], DLG_TEXT[76], DLG_TEXT[77]);
					Link.l2.go = "colony";
				}

				Link.l3 = DLG_TEXT[78];
				Link.l3.go = "exit";
		break;

		case "info":
				dialog.snd1 = "";
				dialog.snd2 = "";
				dialog.snd3 = "";
				d.Text = RandPhrase(DLG_TEXT[79] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[80], DLG_TEXT[81], DLG_TEXT[82] + GetMyName(Pchar) + DLG_TEXT[83], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
				if(Rand(1)==0)
				{	
					Link.l1 = DLG_TEXT[84] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[85])]) + DLG_TEXT[87];
					Link.l1.go = "governor";
				}
				else
				{
					Link.l1 = DLG_TEXT[88] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[89])]) + DLG_TEXT[91];
					Link.l1.go = "tavernkeeper";
				}
				if(Rand(1)==0)	
				{
					Link.l2 = DLG_TEXT[92] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[93])]) + DLG_TEXT[95];
					Link.l2.go = "shipwright";
				}
				else 
				{
					Link.l2 = DLG_TEXT[96] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[97])]) + DLG_TEXT[99];
					Link.l2.go = "localtrader";
				}
				// RobC/Alan_Smithee Blacksmiths -->
				if (ENABLE_WEAPONSMOD)
				{
				//	Link.l3 = DLG_TEXT[162];
				//	Link.l3.go = "smithy";
				}
				// RobC/Alan_Smithee Blacksmiths <--
				Link.l4 = DLG_TEXT[100];
				Link.l4.go = "new question";
		break;
		
		case "smithy":
				Preprocessor_Add("sir", GetMyAddressForm(NPChar, PChar, ADDR_POLITE, false, false)); // DeathDaisy
				Preprocessor_Add("sir2", GetCharacterAddressForm(NPChar, ADDR_POLITE, false, false));
				d.Text = DLG_TEXT[163];
				Link.l1 = DLG_TEXT[164];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[165];
				Link.l2.go = "exit";
		break;
// <-- RobC/A_S 'smiths

		case "governor":
				d.Text = DLG_TEXT[101];
				Link.l1 = DLG_TEXT[102];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[103];
				Link.l2.go = "exit";
		break;

		case "tavernkeeper":
				d.Text = DLG_TEXT[104];
				Link.l1 = DLG_TEXT[105];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[106];
				Link.l2.go = "exit";
		break;

		case "shipwright":
				d.Text = DLG_TEXT[107];
				Link.l1 = DLG_TEXT[108];
				Link.l1.go = "new question";
				Link.l2 = DLG_TEXT[109];
				Link.l2.go = "exit";
		break;

		case "town":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[110] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[111], DLG_TEXT[112] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[113], DLG_TEXT[114] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[115], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			Link.l1 = DLG_TEXT[117];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[118];
			Link.l2.go = "town_store";
			if(Rand(1) == 0)
			{
				Link.l3 = DLG_TEXT[116];
				Link.l3.go = "town_tavern";
			}
			// RobC/Alan_Smithee Blacksmiths -->
			if(Rand(1) == 0)
			{
				Link.l4 = DLG_TEXT[166];
				Link.l4.go = "town_smith";
			}
			else
			{
				link.l4 = DLG_TEXT[174];
				link.l4.go = "town_usurer";
			}
		break;

		case "town_smith":
			d.Text = DLG_TEXT[167];
			Link.l1 = DLG_TEXT[168];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[169];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[170];
			Link.l3.go = "town_store";
		break;
//<-- RobC/A_S 'smiths

		case "town_tavern":
			if (GetAttribute(NPChar, "location") != "Eleuthera_Tavern")
			{
				d.Text = DLG_TEXT[119];
				Link.l1 = DLG_TEXT[120];
				Link.l1.go = "exit";
				Link.l2 = DLG_TEXT[121];
				Link.l2.go = "town_shipyard";
				Link.l3 = DLG_TEXT[122];
				Link.l3.go = "town_store";
				Link.l4 = DLG_TEXT[166];
				Link.l4.go = "town_smith";
            			DeleteAttribute(&locations[FindLocation("Eleuthera_Port")], "reload.l4.goto_disable"); // BOP: Unlock Fast Travel
			}
			else
			{
				d.text = DLG_TEXT[177];
				Link.l1 = DLG_TEXT[178];
				Link.l1.go = "exit";
			}
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[123] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[124];
			if (GetAttribute(NPChar, "location") != "Eleuthera_Tavern")
			{
				Link.l1 = DLG_TEXT[125];
				Link.l1.go = "town_tavern";
			}
			Link.l2 = DLG_TEXT[126];
			Link.l2.go = "town_store";
			Link.l4 = DLG_TEXT[166];
			Link.l4.go = "town_smith";
			Link.l3 = DLG_TEXT[127];
			Link.l3.go = "exit";
            DeleteAttribute(&locations[FindLocation("Eleuthera_Port")], "reload.l5.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_store":
			d.Text = DLG_TEXT[128] + GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[129])]) + DLG_TEXT[131];
			Link.l1 = DLG_TEXT[132];
			Link.l1.go = "town_shipyard";
			if (GetAttribute(NPChar, "location") != "Eleuthera_Tavern")
			{
				Link.l2 = DLG_TEXT[133];
				Link.l2.go = "town_tavern";
			}
			Link.l4 = DLG_TEXT[166];
			Link.l4.go = "town_smith";
			Link.l3 = DLG_TEXT[134];
			Link.l3.go = "exit";
            DeleteAttribute(&locations[FindLocation("Eleuthera_Port")], "reload.l6.goto_disable"); // BOP: Unlock Fast Travel
		break;

		case "town_usurer":
			Preprocessor_Add("usurer", GetMyFullName(CharacterFromID("Eleuthera Usurer")));
			d.Text = DLG_TEXT[175];
			Link.l1 = DLG_TEXT[176];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[169];
			Link.l2.go = "town_shipyard";
			Link.l3 = DLG_TEXT[170];
			Link.l3.go = "town_store";
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[135], DLG_TEXT[136], DLG_TEXT[137] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + " " + PChar.lastname + DLG_TEXT[138], &Dialog, Dialog.snd1, Dialog.snd2, Dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[139];
				Link.l1.go = "Douwesen";
			}
			else
			{
				Link.l1 = DLG_TEXT[140];
				Link.l1.go = "island";
			}
			if(Rand(1)== 0)
			{
				Link.l1 = DLG_TEXT[141];
				Link.l1.go = "fort";
			}
	/*		else
			{
				Link.l1 = "С кем торгуют местные торговцы?";
				Link.l1.go = "trade";
			}*/

			Link.l2 = DLG_TEXT[142];
			Link.l2.go = "new question";
		break;

		case "Douwesen":
			d.Text = DLG_TEXT[143] + " " + DLG_TEXT[171] + " " + GetTownSize("Douwesen") + " " + DLG_TEXT[172]; // NK
			Link.l1 = DLG_TEXT[144];
			Link.l1.go = "Douwesen_1";
			Link.l2 = DLG_TEXT[145];
			Link.l2.go = "new question";
		break;

		case "Douwesen_1":
			d.Text = DLG_TEXT[146];
			//Link.l1 = "Дальше...";
			//Link.l1.go = "Redmond_2";
			Link.l2 = DLG_TEXT[147];
			Link.l2.go = "new question";
		break;

		case "island":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[148];
					Link.l1 = DLG_TEXT[149];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[150];
					Link.l1 = DLG_TEXT[151];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[152];
					Link.l1 = DLG_TEXT[153];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[154];
			Link.l2.go = "new question";
		break;

		case "fort":
			switch(Rand(2))
			{	
				case 0:
					d.Text = DLG_TEXT[155];
					Link.l1 = DLG_TEXT[156];
					Link.l1.go = "colony";
				break;

				case 1:
					d.Text = DLG_TEXT[157]
					Link.l1 = DLG_TEXT[158];
					Link.l1.go = "colony";
				break;

				case 2:
					d.Text = DLG_TEXT[159];
					Link.l1 = DLG_TEXT[160];
					Link.l1.go = "colony";
				break;
			}
			Link.l2 = DLG_TEXT[161];
			Link.l2.go = "new question";
		break;
		
		case "localtrader":
			// NK fix for missing dialog 04-08
			/*dialog.text = DLG_TEXT[162];
			link.l1 = DLG_TEXT[163];
			Link.l1.go = "new question";
			Link.l2 = DLG_TEXT[164];
			Link.l2.go = "exit";*/
			dialog.text = GetMyFullName(&Characters[GetCharacterIndex(DLG_TEXT[97])]) + DLG_TEXT[173];
			link.l1 = DLG_TEXT[102];
			Link.l1.go = "new question";
			Link.l2 = DLG_TEXT[103];
			Link.l2.go = "exit";
			// NK <--
			
		break;


			} // end of switch; 

}
