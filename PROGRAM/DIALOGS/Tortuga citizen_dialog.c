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
				if(Rand(1)==0)	
				{
					Link.l2 = DLG_TEXT[90];
					Link.l2.go = "shipwright";
				}
				else 
				{
					Link.l2 = DLG_TEXT[91];
					Link.l2.go = "localtrader";
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
					//	Link.l4 = DLG_TEXT[158];
					//	Link.l4.go = "smithy";
					}
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
			Link.l4 = DLG_TEXT[168];
			Link.l4.go = "town_tailor";
			// RobC/Alan_Smithee Blacksmiths -->
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l5 = DLG_TEXT[162];
			//	Link.l5.go = "town_smithy";
			}
			// RobC/Alan_Smithee Blacksmiths <--
			//JRH WoodesRogers -->
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l6 = DLG_TEXT[170];
				Link.l6.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l7 = DLG_TEXT[171];
				Link.l7.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l8 = DLG_TEXT[172];
				Link.l8.go = "town_sailmaker";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
			//<-- JRH WoodesRogers
		break;

//JRH WoodesRogers -->
		case "town_surgeon":
			d.Text = DLG_TEXT[173];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "exit_surgeon";
			Link.l2 = DLG_TEXT[110];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[165];
			Link.l3.go = "town_shipyard";
			Link.l4 = DLG_TEXT[166];
			Link.l4.go = "town_store";
			Link.l5 = DLG_TEXT[168];
			Link.l5.go = "town_tailor";
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l6 = DLG_TEXT[162];
			//	Link.l6.go = "town_smithy";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l7 = DLG_TEXT[171];
				Link.l7.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l8 = DLG_TEXT[172];
				Link.l8.go = "town_sailmaker";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
		break;

		case "town_gunsmith":
			d.Text = DLG_TEXT[174];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "exit_gunsmith";
			Link.l2 = DLG_TEXT[118];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[115];
			Link.l3.go = "town_shipyard";
			Link.l4 = DLG_TEXT[116];
			Link.l4.go = "town_store";
			Link.l5 = DLG_TEXT[168];
			Link.l5.go = "town_tailor";
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l6 = DLG_TEXT[162];
			//	Link.l6.go = "town_smithy";
			}
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l7 = DLG_TEXT[170];
				Link.l7.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l8 = DLG_TEXT[172];
				Link.l8.go = "town_sailmaker";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
		break;

		case "town_sailmaker":
			d.Text = DLG_TEXT[175];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "exit_sailmaker";
			Link.l2 = DLG_TEXT[118];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[122];
			Link.l3.go = "town_shipyard";
			Link.l4 = DLG_TEXT[119];
			Link.l4.go = "town_store";
			Link.l5 = DLG_TEXT[168];
			Link.l5.go = "town_tailor";
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l6 = DLG_TEXT[162];
			//	Link.l6.go = "town_smithy";
			}
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l7 = DLG_TEXT[170];
				Link.l7.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l8 = DLG_TEXT[171];
				Link.l8.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
		break;

		case "town_carriage":
			d.Text = DLG_TEXT[179];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "exit_carriage";
			Link.l2 = DLG_TEXT[110];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[165];
			Link.l3.go = "town_shipyard";
			Link.l4 = DLG_TEXT[166];
			Link.l4.go = "town_store";
			Link.l5 = DLG_TEXT[168];
			Link.l5.go = "town_tailor";
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l6 = DLG_TEXT[162];
			//	Link.l6.go = "town_smithy";
			}
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l7 = DLG_TEXT[170];
				Link.l7.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l8 = DLG_TEXT[171];
				Link.l8.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l9 = DLG_TEXT[172];
				Link.l9.go = "town_sailmaker";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
		break;

		case "town_tower":
			d.Text = DLG_TEXT[177];
			Link.l1 = DLG_TEXT[114];
			Link.l1.go = "exit_tower";
			Link.l2 = DLG_TEXT[110];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[165];
			Link.l3.go = "town_shipyard";
			Link.l4 = DLG_TEXT[166];
			Link.l4.go = "town_store";
			Link.l5 = DLG_TEXT[168];
			Link.l5.go = "town_tailor";
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l6 = DLG_TEXT[162];
			//	Link.l6.go = "town_smithy";
			}
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l7 = DLG_TEXT[170];
				Link.l7.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l8 = DLG_TEXT[171];
				Link.l8.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l10 = DLG_TEXT[172];
				Link.l10.go = "town_sailmaker";
			}
		break;
//<-- JRH WoodesRogers

// RobC/Alan_Smithee Blacksmiths -->
		case "town_smithy":
			d.Text = DLG_TEXT[163];
			Link.l1 = DLG_TEXT[164];
			Link.l1.go = "exit";
			Link.l2 = DLG_TEXT[110];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[165];
			Link.l3.go = "town_shipyard";
			Link.l4 = DLG_TEXT[166];
			Link.l4.go = "town_store";
			Link.l5 = DLG_TEXT[168];
			Link.l5.go = "town_tailor";
			//JRH WoodesRogers -->
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l6 = DLG_TEXT[170];
				Link.l6.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l7 = DLG_TEXT[171];
				Link.l7.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l8 = DLG_TEXT[172];
				Link.l8.go = "town_sailmaker";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
			//<-- JRH WoodesRogers
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
			Link.l4 = DLG_TEXT[168];
			Link.l4.go = "town_tailor";
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l5 = DLG_TEXT[162];
			//	Link.l5.go = "town_smithy";
			}
			//JRH WoodesRogers -->
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l6 = DLG_TEXT[170];
				Link.l6.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l7 = DLG_TEXT[171];
				Link.l7.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l8 = DLG_TEXT[172];
				Link.l8.go = "town_sailmaker";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
			//<-- JRH WoodesRogers
			DeleteAttribute(&locations[FindLocation("Tortuga_port")], "reload.l6.goto_disable"); // JRH: Unlock Fast Travel
		break;

		case "town_shipyard":
			d.Text = DLG_TEXT[117];
			Link.l1 = DLG_TEXT[118];
			Link.l1.go = "town_tavern";
			Link.l2 = DLG_TEXT[119];
			Link.l2.go = "town_store";
			Link.l3 = DLG_TEXT[168];
			Link.l3.go = "town_tailor";
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l4 = DLG_TEXT[162];
			//	Link.l4.go = "town_smithy";
			}
			Link.l5 = DLG_TEXT[120];
			Link.l5.go = "exit";
			//JRH WoodesRogers -->
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l6 = DLG_TEXT[170];
				Link.l6.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l7 = DLG_TEXT[171];
				Link.l7.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l8 = DLG_TEXT[172];
				Link.l8.go = "town_sailmaker";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
			//<-- JRH WoodesRogers
			DeleteAttribute(&locations[FindLocation("Tortuga_port")], "reload.l3.goto_disable"); // JRH: Unlock Fast Travel
		break;

		case "town_store":
			d.Text = DLG_TEXT[121];
			Link.l1 = DLG_TEXT[122];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[123];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[168];
			Link.l3.go = "town_tailor";
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l4 = DLG_TEXT[162];
			//	Link.l4.go = "town_smithy";
			}
			Link.l5 = DLG_TEXT[124];
			Link.l5.go = "exit";
			//JRH WoodesRogers -->
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l6 = DLG_TEXT[170];
				Link.l6.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l7 = DLG_TEXT[171];
				Link.l7.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l8 = DLG_TEXT[172];
				Link.l8.go = "town_sailmaker";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
			//<-- JRH WoodesRogers
			DeleteAttribute(&locations[FindLocation("Tortuga_port")], "reload.l4.goto_disable"); // JRH: Unlock Fast Travel
		break;

		case "town_tailor":
			d.Text = DLG_TEXT[169];
			Link.l1 = DLG_TEXT[122];
			Link.l1.go = "town_shipyard";
			Link.l2 = DLG_TEXT[123];
			Link.l2.go = "town_tavern";
			Link.l3 = DLG_TEXT[119];
			Link.l3.go = "town_store";
			if (ENABLE_WEAPONSMOD)
			{
			//	Link.l4 = DLG_TEXT[162];
			//	Link.l4.go = "town_smithy";
			}
			Link.l5 = DLG_TEXT[124];
			Link.l5.go = "exit";
			//JRH WoodesRogers -->
			if(CheckAttribute(Pchar, "Tsurgeon") && Pchar.Tsurgeon == "yes")
			{
				Link.l6 = DLG_TEXT[170];
				Link.l6.go = "town_surgeon";
			}
			if(CheckAttribute(Pchar, "Tgunsmith") && Pchar.Tgunsmith == "yes")
			{
				Link.l7 = DLG_TEXT[171];
				Link.l7.go = "town_gunsmith";
			}
			if(CheckAttribute(Pchar, "Tsailmaker") && Pchar.Tsailmaker == "yes")
			{
				Link.l8 = DLG_TEXT[172];
				Link.l8.go = "town_sailmaker";
			}
			if(CheckAttribute(Pchar, "Tassistent") && Pchar.Tassistent == "yes")
			{
				Link.l9 = DLG_TEXT[178];
				Link.l9.go = "town_carriage";
			}
			if(CheckAttribute(Pchar, "Ttower") && Pchar.Ttower == "yes")
			{
				Link.l10 = DLG_TEXT[176];
				Link.l10.go = "town_tower";
			}
			//<-- JRH WoodesRogers
			DeleteAttribute(&locations[FindLocation("Tortuga_port")], "reload.l20.goto_disable"); // JRH: Unlock Fast Travel
		break;

		case "colony":
			dialog.snd1 = "";
			dialog.snd2 = "";
			dialog.snd3 = "";
			d.Text = RandPhrase(DLG_TEXT[125], DLG_TEXT[126] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[127], DLG_TEXT[128] + GetMyAddressForm(NPChar, PChar, ADDR_CIVIL, false, false) + DLG_TEXT[129], &Dialog, dialog.snd1, dialog.snd2, dialog.snd3);
			if(Rand(1)== 0)
			{
				Link.l1 = pcharrepphrase(DLG_TEXT[130], DLG_TEXT[131]);
				Link.l1.go = "Tortuga";
			}
			else
			{
				Link.l1 = DLG_TEXT[132];
				Link.l1.go = "island";
			}
			Link.l2 = DLG_TEXT[133];
			Link.l2.go = "new question";
		break;

		case "Tortuga":
			d.Text = DLG_TEXT[134];
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

		case "exit_surgeon":
			if(!CheckAttribute(Pchar,"qbook.richards4") || Pchar.qbook.richards4 != "done")
			{
				AddQuestRecord("Richards","4");
				Pchar.qbook.richards4 = "done";
			}

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reloadQ4", 1.5);	
			Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ4 = 1.5;	
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_gunsmith":
			if(!CheckAttribute(Pchar,"qbook.richards6") || Pchar.qbook.richards6 != "done")
			{
				AddQuestRecord("Richards","6");
				Pchar.qbook.richards6 = "done";
			}

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "box", "box8", 1.0);	
			Locations[FindLocation("Tortuga_port")].locators_radius.box.box8 = 1.0;	
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_sailmaker":
			if(!CheckAttribute(Pchar,"qbook.richards8") || Pchar.qbook.richards8 != "done")
			{
				AddQuestRecord("Richards","8");
				Pchar.qbook.richards8 = "done";
			}

			SetLocatorRadius(locations[FindLocation(Pchar.location)], "reload", "reloadQ1", 0.9);	
			Locations[FindLocation("Tortuga_port")].locators_radius.reload.reloadQ1 = 0.9;	
			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_carriage":
			if(!CheckAttribute(Pchar,"qbook.richards10") || Pchar.qbook.richards10 != "done")
			{
				AddQuestRecord("Richards","10");
				Pchar.qbook.richards10 = "done";
			}

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;

		case "exit_tower":
			if(!CheckAttribute(Pchar,"qbook.richards12") || Pchar.qbook.richards12 != "done")
			{
				AddQuestRecord("Richards","12");
				Pchar.qbook.richards12 = "done";
			}

			Diag.CurrentNode = Diag.TempNode;
			NPChar.quest.meeting = NPC_Meeting;
			DialogExit();
		break;
	}
}
